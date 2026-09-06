import html
import json
import logging
import re
import time
from typing import Any, Dict, List, Optional
import requests

from src.config import config

logger = logging.getLogger("CodeChefClient")


class CodeChefClient:
    BASE_URL = "https://www.codechef.com"
    API_LIST_PROBLEMS = f"{BASE_URL}/api/list/problems"
    API_PROBLEM_DETAILS = f"{BASE_URL}/api/contests/PRACTICE/problems"
    API_SUBMIT = f"{BASE_URL}/api/ide/submit"

    # Language mapping for CodeChef IDE
    LANG_MAP = {
        "cpp": "42",        # C++ (gcc 9.2.1)
        "c++": "42",
        "cpp17": "42",
        "python3": "116",   # Python 3.8
        "py": "116",
        "java": "10",       # Java
    }

    def __init__(self, session_cookie: str = ""):
        raw_session = session_cookie or config.codechef_session
        self.session_cookie = raw_session.strip().strip('"').strip("'") if raw_session else ""
        self.http = requests.Session()
        self._setup_headers()

    def _setup_headers(self):
        headers = {
            "User-Agent": (
                "Mozilla/5.0 (Windows NT 10.0; Win64; x64) "
                "AppleWebKit/537.36 (KHTML, like Gecko) "
                "Chrome/124.0.0.0 Safari/537.36"
            ),
            "Accept": "application/json, text/plain, */*",
            "Accept-Language": "en-US,en;q=0.9",
            "Referer": self.BASE_URL,
            "Origin": self.BASE_URL,
            "Connection": "keep-alive",
        }
        if self.session_cookie:
            # CodeChef session cookies typically look like 'SESS...=value' or just the value
            if "=" in self.session_cookie:
                headers["Cookie"] = self.session_cookie
            else:
                # If only raw value provided, fallback or set common Drupal key
                headers["Cookie"] = f"SESS93b6022d778ee317bf48f7dbffe03173={self.session_cookie}"

        self.http.headers.update(headers)

    def fetch_practice_problems(
        self,
        page: int = 0,
        limit: int = 25,
        sort_by: str = "successful_submissions",
        sort_order: str = "desc",
    ) -> List[Dict[str, Any]]:
        """Fetch popular / graded practice problems from CodeChef."""
        params = {
            "page": page,
            "limit": limit,
            "sort_by": sort_by,
            "sort_order": sort_order,
        }
        response = self.http.get(self.API_LIST_PROBLEMS, params=params, timeout=15)
        response.raise_for_status()
        data = response.json()
        return data.get("data", [])

    def fetch_problem_details(self, problem_code: str) -> Dict[str, Any]:
        """Fetch full description, constraints, and sample inputs for a problem."""
        url = f"{self.API_PROBLEM_DETAILS}/{problem_code}"
        response = self.http.get(url, timeout=15)
        response.raise_for_status()
        data = response.json()
        if data.get("status") != "success":
            raise ValueError(f"Could not retrieve details for {problem_code}: {data}")

        # Check if modern structured problemComponents exist
        comps = data.get("problemComponents")
        if comps and isinstance(comps, dict) and comps.get("statement"):
            parts = []
            if comps.get("statement"):
                parts.append(f"### Problem Statement:\n{self._clean_html(comps['statement'])}")
            if comps.get("inputFormat"):
                parts.append(f"### Input Format:\n{self._clean_html(comps['inputFormat'])}")
            if comps.get("outputFormat"):
                parts.append(f"### Output Format:\n{self._clean_html(comps['outputFormat'])}")
            if comps.get("constraints"):
                parts.append(f"### Constraints:\n{self._clean_html(comps['constraints'])}")
            if comps.get("sampleTestCases"):
                parts.append("### Sample Test Cases:")
                for stc in comps["sampleTestCases"]:
                    inp = stc.get("input", "").strip()
                    outp = stc.get("output", "").strip()
                    expl = stc.get("explanation", "").strip()
                    parts.append(f"Input:\n```\n{inp}\n```\nOutput:\n```\n{outp}\n```\nExplanation: {expl}")
            clean_content = "\n\n".join(parts)
        else:
            raw_body = data.get("body", "")
            raw_body = re.sub(
                r"^This is an example statement in markdown\..*?email us at help@codechef\.com\.\s*",
                "",
                raw_body,
                flags=re.DOTALL | re.IGNORECASE
            )
            clean_content = self._clean_html(raw_body)

        data["cleanContent"] = clean_content
        return data

    def get_csrf_token(self, problem_code: str) -> str:
        """Extract the dynamic window.csrfToken from CodeChef problem page."""
        url = f"{self.BASE_URL}/problems/{problem_code}"
        response = self.http.get(url, timeout=15)
        response.raise_for_status()

        match = re.search(r'window\.csrfToken\s*=\s*"([a-f0-9]+)"', response.text)
        if match:
            return match.group(1)
        raise ValueError(f"Could not find window.csrfToken on problem page {url}")

    def submit_solution(
        self,
        problem_code: str,
        code: str,
        language: str = "cpp",
    ) -> str:
        """Submit code to CodeChef IDE and return solution_id (upid)."""
        if not self.session_cookie:
            raise PermissionError("CODECHEF_SESSION is required to submit code to CodeChef.")

        csrf_token = self.get_csrf_token(problem_code)
        lang_id = self.LANG_MAP.get(language.lower(), "42")

        headers = {
            "Referer": f"{self.BASE_URL}/problems/{problem_code}",
            "x-csrf-token": csrf_token,
            "Content-Type": "application/x-www-form-urlencoded; charset=UTF-8",
        }

        payload = {
            "sourceCode": code,
            "language": lang_id,
            "problemCode": problem_code,
            "contestCode": "PRACTICE",
        }

        response = self.http.post(self.API_SUBMIT, data=payload, headers=headers, timeout=20)
        if response.status_code != 200:
            raise RuntimeError(f"Submission failed [HTTP {response.status_code}]: {response.text}")

        res_data = response.json()
        solution_id = str(res_data.get("upid") or res_data.get("solution_id") or "")
        if not solution_id:
            raise RuntimeError(f"Unexpected submit response: {res_data}")

        return solution_id

    def poll_verdict(self, solution_id: str, max_wait_seconds: int = 45) -> Dict[str, Any]:
        """Poll CodeChef IDE submit status until judging completes."""
        url = f"{self.API_SUBMIT}?solution_id={solution_id}"
        start_time = time.time()

        while time.time() - start_time < max_wait_seconds:
            response = self.http.get(url, timeout=15)
            if response.status_code == 200:
                data = response.json()
                # Status: wait, running, or done
                result_code = data.get("result_code")
                # When evaluation finishes, result_code is not 'wait' or empty
                if result_code and result_code not in ("wait", "running"):
                    return self.parse_verdict(data)

            time.sleep(2.5)

        raise TimeoutError(f"Submission {solution_id} timed out after {max_wait_seconds}s")

    def parse_verdict(self, raw_result: Dict[str, Any]) -> Dict[str, Any]:
        """Normalize CodeChef judging result into a structured feedback object."""
        result_code = str(raw_result.get("result_code", "unknown")).lower()
        status = str(raw_result.get("status", "")).lower()
        score = raw_result.get("score")
        
        # 'accepted' or 'correct' or 100 score means Accepted / AC on CodeChef
        passed = (
            result_code in ("correct", "accepted", "ac")
            or status in ("correct", "accepted")
            or score == 100
        )

        time_taken = raw_result.get("time", "N/A")
        memory_taken = raw_result.get("memory", "N/A")

        diagnostic = ""
        if not passed:
            if result_code == "wrong":
                diagnostic = (
                    f"Verdict: WRONG ANSWER (WA)\n"
                    f"Score: {raw_result.get('score', 0)}\n"
                    f"Message: {raw_result.get('custom__message', 'Incorrect output on testcases.')}"
                )
            elif result_code == "time":
                diagnostic = (
                    f"Verdict: TIME LIMIT EXCEEDED (TLE)\n"
                    f"Time Taken: {time_taken}s\n"
                    f"Action: Algorithm time complexity too high. Optimize loops / use fast I/O."
                )
            elif result_code == "compilation_error":
                diagnostic = (
                    f"Verdict: COMPILATION ERROR\n"
                    f"Compiler Log:\n{raw_result.get('cmp_info', 'Compilation failed.')}"
                )
            elif result_code == "runtime":
                diagnostic = (
                    f"Verdict: RUNTIME ERROR (SIGSEGV / NZEC)\n"
                    f"Signal: {raw_result.get('signal', 'Non-zero exit code')}\n"
                    f"Memory Limit / Bounds Exception."
                )
            else:
                diagnostic = f"Verdict: {result_code}\nDetails: {json.dumps(raw_result, indent=2)}"

        return {
            "passed": passed,
            "result_code": result_code,
            "time": time_taken,
            "memory": memory_taken,
            "diagnostic": diagnostic,
            "raw": raw_result,
        }

    @staticmethod
    def _clean_html(raw_html: str) -> str:
        """Convert HTML problem body into clean, legible text."""
        if not raw_html:
            return ""
        text = html.unescape(raw_html)
        text = re.sub(r"<pre>(.*?)</pre>", r"\n```\n\1\n```\n", text, flags=re.DOTALL)
        text = re.sub(r"<code>(.*?)</code>", r"`\1`", text)
        text = re.sub(r"<strong>(.*?)</strong>", r"**\1**", text)
        text = re.sub(r"<em>(.*?)</em>", r"*\1*", text)
        text = re.sub(r"<li>(.*?)</li>", r"- \1\n", text)
        text = re.sub(r"<p>", r"\n", text)
        text = re.sub(r"<br\s*/?>", r"\n", text)
        text = re.sub(r"<[^>]+>", "", text)
        text = re.sub(r"\n{3,}", "\n\n", text)
        return text.strip()
