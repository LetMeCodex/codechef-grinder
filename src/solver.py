import logging
import re
import time
from typing import Any, Dict, List, Optional
from google import genai
from google.genai import types

from src.config import config

logger = logging.getLogger("CodeChefSolver")


class CodeChefSolver:
    CANDIDATE_MODELS = [
        "gemini-2.5-flash",
        "gemini-2.5-flash-lite",
        "gemini-3.1-flash-lite",
    ]

    def __init__(self, api_key: str = "", model_name: str = ""):
        self.api_key = api_key or config.gemini_api_key
        primary = model_name or config.gemini_model
        models = [primary] if primary else []
        for m in self.CANDIDATE_MODELS:
            if m not in models:
                models.append(m)
        self.candidate_models = models

        if not self.api_key:
            self.client = None
        else:
            self.client = genai.Client(api_key=self.api_key)

    def _ensure_client(self):
        if not self.client:
            raise ValueError("GEMINI_API_KEY is not set. Please provide a valid key.")

    def _generate_with_resilience(self, prompt: str) -> str:
        """Call Gemini models with fallback across multiple models and backoff retry."""
        self._ensure_client()
        last_err = None

        for model in self.candidate_models:
            for try_idx in range(2):
                try:
                    logger.info(f"Generating solution via model '{model}' (try {try_idx + 1}/2)...")
                    response = self.client.models.generate_content(
                        model=model,
                        contents=prompt,
                        config=types.GenerateContentConfig(temperature=0.2)
                    )
                    if response and response.text:
                        return response.text
                except Exception as e:
                    last_err = e
                    err_str = str(e)
                    logger.warning(f"Model '{model}' try {try_idx + 1} failed: {err_str[:120]}")
                    if "503" in err_str or "429" in err_str or "UNAVAILABLE" in err_str:
                        time.sleep(3 * (try_idx + 1))
                    else:
                        break

        raise RuntimeError(f"All Gemini candidate models failed. Last error: {last_err}")

    def extract_clean_code(self, raw_text: str) -> str:
        """Extract clean, compileable source code from markdown fences."""
        text = raw_text.strip()
        match = re.search(r"```(?:[a-zA-Z0-9_\+\-]+)?\n(.*?)```", text, re.DOTALL)
        if match:
            return match.group(1).strip()
        return text

    def generate_initial_solution(
        self, problem_details: Dict[str, Any], language: str = "cpp"
    ) -> str:
        """Generate optimal C++ / Python solution for a CodeChef problem."""
        code = problem_details.get("problem_code", "")
        name = problem_details.get("problem_name", "")
        difficulty = problem_details.get("difficulty_rating", "Unrated")
        content = problem_details.get("cleanContent", "")
        time_limit = problem_details.get("max_timelimit", 1.0)

        lang_instructions = ""
        if "cpp" in language.lower() or "c++" in language.lower():
            lang_instructions = """Language: C++17
- Use `#include <bits/stdc++.h>` and `using namespace std;`
- Include fast I/O inside main(): `ios_base::sync_with_stdio(false); cin.tie(NULL);`
- Read standard input using `cin` and output using `cout << ... << "\\n";`
- Handle multiple test cases (e.g. `int t; cin >> t; while(t--)`) properly as requested by the problem statement.
"""
        else:
            lang_instructions = """Language: Python 3
- Read input from standard input using `sys.stdin.read` or `input()`.
- Output answers using `print()`.
- Fast I/O: `import sys; input = sys.stdin.readline`.
"""

        prompt = f"""You are an International Grandmaster Competitive Programmer.
Solve the following CodeChef problem with optimal time and space complexity.

Problem Code: {code}
Problem Title: {name}
Difficulty Rating: {difficulty}
Time Limit: {time_limit}s

Problem Description & Constraints:
{content}

{lang_instructions}

Critical Instructions:
1. Handle all edge cases: minimum/maximum constraints, negative numbers, single element, empty strings, integer overflow (use `long long` in C++).
2. Adhere strictly to the required input and output formats. Do not print extra prompts like "Enter number:".
3. Return ONLY the complete, executable source code inside a ```{language} ... ``` code block. No conversational markdown outside the code.
"""
        raw_output = self._generate_with_resilience(prompt)
        return self.extract_clean_code(raw_output)

    def generate_self_healing_solution(
        self,
        problem_details: Dict[str, Any],
        previous_code: str,
        diagnostic: str,
        attempt: int,
        language: str = "cpp"
    ) -> str:
        """Self-healing reflection prompt to debug and refactor failed CodeChef submission."""
        code = problem_details.get("problem_code", "")
        content = problem_details.get("cleanContent", "")

        prompt = f"""You are a World-Class Competitive Programmer debugging a failed CodeChef submission.

Problem Code: {code}
Problem Description:
{content}

--------------------------------------------------
YOUR PREVIOUS ATTEMPT (Attempt #{attempt}):
```{language}
{previous_code}
```

CODECHEF VERDICT / ERROR DIAGNOSTIC:
{diagnostic}
--------------------------------------------------

DEBUGGING & REFLECTION INSTRUCTIONS:
1. If WRONG ANSWER (WA):
   - Check if you missed an edge case (N=1, N=0, all elements equal, large numbers requiring 64-bit integers / long long).
   - Check if problem uses 1-based indexing vs 0-based indexing.
   - Check off-by-one errors or tie-breaking rules.
2. If TIME LIMIT EXCEEDED (TLE):
   - Asymptotic complexity is too slow. Switch to a faster algorithm (e.g. prefix sums, hash maps, two pointers, binary search, sorting).
3. If RUNTIME ERROR (SIGSEGV / NZEC):
   - Fix array out of bounds, division by zero, null pointer, or stack overflow.
4. Output ONLY the complete revised executable code enclosed in a ```{language} ... ``` code block.
"""
        raw_output = self._generate_with_resilience(prompt)
        return self.extract_clean_code(raw_output)

    def generate_explanation_doc(
        self, problem_details: Dict[str, Any], code_solution: str, attempts: int, language: str = "cpp"
    ) -> str:
        """Generate markdown documentation for the solved CodeChef problem."""
        code = problem_details.get("problem_code", "")
        name = problem_details.get("problem_name", "")
        difficulty = problem_details.get("difficulty_rating", "Unrated")

        prompt = f"""Generate a clean, high-quality solution writeup in GitHub-Flavored Markdown for:
CodeChef Problem: [{name} ({code})](https://www.codechef.com/problems/{code})
Difficulty Rating: {difficulty}
Solved in: {attempts} attempt(s)

Solution Code:
```{language}
{code_solution}
```

Include:
# [{name} ({code})](https://www.codechef.com/problems/{code})
- **Difficulty Rating**: {difficulty}
- **Solved in**: {attempts} attempt(s)
## Problem Summary
## Intuition & Mathematical Observation
## Complexity Analysis
- **Time Complexity**: $O(...)$
- **Space Complexity**: $O(...)$
## Solution Code
"""
        return self._generate_with_resilience(prompt).strip()
