import json
import logging
import os
import sys
import time
from pathlib import Path

from src.config import config
from src.codechef_client import CodeChefClient
from src.solver import CodeChefSolver

logging.basicConfig(
    level=logging.INFO,
    format="%(asctime)s [%(levelname)s] %(name)s: %(message)s",
    handlers=[logging.StreamHandler(sys.stdout)],
)
logger = logging.getLogger("CodeChefAutoGrinder")


def load_solved_database(data_path: Path) -> dict:
    """Load or initialize database tracking solved problem codes."""
    if data_path.exists():
        try:
            with open(data_path, "r", encoding="utf-8") as f:
                return json.load(f)
        except Exception as e:
            logger.warning(f"Failed to read {data_path}, creating fresh state: {e}")

    return {"total_solved": 0, "solved_codes": [], "history": []}


def save_solved_database(data_path: Path, data: dict) -> None:
    """Persist solved problems tracking to JSON."""
    data_path.parent.mkdir(parents=True, exist_ok=True)
    with open(data_path, "w", encoding="utf-8") as f:
        json.dump(data, f, indent=2)


def save_solution_files(
    solutions_dir: Path,
    problem_code: str,
    code: str,
    doc: str,
    language: str
) -> None:
    """Save code and explanation markdown inside problem folder."""
    target_dir = solutions_dir / problem_code
    target_dir.mkdir(parents=True, exist_ok=True)

    ext = "cpp" if "cpp" in language.lower() or "c++" in language.lower() else "py"
    code_path = target_dir / f"solution.{ext}"
    with open(code_path, "w", encoding="utf-8") as f:
        f.write(code)

    readme_path = target_dir / "README.md"
    with open(readme_path, "w", encoding="utf-8") as f:
        f.write(doc)

    logger.info(f"Saved problem solution files at: {target_dir}")


def run():
    logger.info("=== Starting CodeChef Practice Archive Auto-Grinder ===")
    
    client = CodeChefClient()
    solver = CodeChefSolver()

    # Pre-flight Credentials Verification
    if not solver.api_key:
        logger.error(
            "CRITICAL: GEMINI_API_KEY is missing! Please configure it in your environment or GitHub Secrets."
        )
        sys.exit(1)

    if not config.dry_run and not client.session_cookie:
        logger.error(
            "CRITICAL: CODECHEF_SESSION is missing! Please add your CodeChef session cookie to GitHub Secrets."
        )
        sys.exit(1)

    # 1. Load Solved Database
    db = load_solved_database(config.data_file)
    solved_set = set(db.get("solved_codes", []))
    logger.info(f"Database loaded: {len(solved_set)} problems already solved.")

    # 2. Discover Unsolved Candidate Problems
    candidate_problems = []
    page = 0
    while len(candidate_problems) < config.problems_per_run and page < 5:
        logger.info(f"Fetching practice problems page {page} from CodeChef...")
        try:
            problems = client.fetch_practice_problems(
                page=page,
                limit=30,
                sort_by="successful_submissions",
                sort_order="desc"
            )
        except Exception as e:
            logger.error(f"Failed to fetch problems from CodeChef API: {e}")
            break

        if not problems:
            break

        for p in problems:
            code = p.get("code")
            if not code:
                continue

            # Check difficulty bounds if rated
            diff = int(p.get("difficulty_rating", -1))
            if diff > 0 and (diff < config.min_difficulty or diff > config.max_difficulty):
                continue

            if code not in solved_set and code not in [cp["code"] for cp in candidate_problems]:
                candidate_problems.append(p)
                if len(candidate_problems) >= config.problems_per_run:
                    break

        page += 1

    if not candidate_problems:
        logger.info("No new candidate problems found in targeted range. All caught up!")
        return

    logger.info(f"Selected {len(candidate_problems)} problems to solve in this session:")
    for i, p in enumerate(candidate_problems, 1):
        logger.info(f"  {i}. {p.get('code')} - {p.get('name')} (Rating: {p.get('difficulty_rating')})")

    # 3. Solve & Submit Each Problem
    solved_this_run = 0

    for idx, p_meta in enumerate(candidate_problems, 1):
        code = p_meta.get("code")
        name = p_meta.get("name")
        logger.info(f"\n[{idx}/{len(candidate_problems)}] Processing Problem: {code} ({name})...")

        try:
            details = client.fetch_problem_details(code)
        except Exception as e:
            logger.error(f"Failed to fetch details for {code}: {e}")
            continue

        attempt = 1
        previous_code = ""
        diagnostic = ""
        is_solved = False

        while attempt <= config.max_retries:
            logger.info(f"--- Problem {code} | Attempt {attempt} of {config.max_retries} ---")
            try:
                if attempt == 1:
                    logger.info("Generating initial solution using Gemini...")
                    sol_code = solver.generate_initial_solution(details, config.language)
                else:
                    logger.info("Triggering Self-Healing Reflection loop...")
                    sol_code = solver.generate_self_healing_solution(
                        problem_details=details,
                        previous_code=previous_code,
                        diagnostic=diagnostic,
                        attempt=attempt - 1,
                        language=config.language
                    )

                logger.info(f"Generated solution ({len(sol_code)} chars). Preview:\n{sol_code[:160]}...\n")

                if config.dry_run:
                    logger.info("[DRY RUN] Skipping live submission.")
                    doc = solver.generate_explanation_doc(details, sol_code, attempts=attempt, language=config.language)
                    save_solution_files(config.solutions_dir, code, sol_code, doc, config.language)
                    is_solved = True
                    break

                # Live Submission
                logger.info(f"Submitting to CodeChef IDE...")
                solution_id = client.submit_solution(code, sol_code, config.language)
                logger.info(f"Submitted. Solution ID: {solution_id}. Polling verdict...")

                verdict = client.poll_verdict(solution_id)
                logger.info(f"Verdict: {verdict.get('result_code')} (Passed: {verdict.get('passed')})")

                if verdict["passed"]:
                    logger.info(f"[ACCEPTED] Problem {code} solved successfully!")
                    is_solved = True

                    doc = solver.generate_explanation_doc(details, sol_code, attempts=attempt, language=config.language)
                    save_solution_files(config.solutions_dir, code, sol_code, doc, config.language)

                    # Update database
                    db["solved_codes"].append(code)
                    db["total_solved"] = len(db["solved_codes"])
                    db["history"].append({
                        "code": code,
                        "name": name,
                        "attempts": attempt,
                        "time": time.strftime("%Y-%m-%d %H:%M:%S")
                    })
                    save_solved_database(config.data_file, db)
                    solved_this_run += 1
                    break
                else:
                    logger.warning(f"Verdict failed: {verdict.get('result_code')}")
                    diagnostic = verdict.get("diagnostic", "Submission failed.")
                    previous_code = sol_code
                    if attempt < config.max_retries:
                        time.sleep(10)

            except Exception as loop_err:
                logger.error(f"Error during attempt {attempt} for {code}: {loop_err}")
                diagnostic = f"Execution error: {str(loop_err)}"
                previous_code = sol_code if 'sol_code' in locals() else ""
                time.sleep(10)

            attempt += 1

        # Human-like delay between different problems
        if is_solved and idx < len(candidate_problems) and not config.dry_run:
            pacing_delay = config.submission_delay_seconds
            logger.info(f"Waiting {pacing_delay}s before starting next problem (human pacing)...")
            time.sleep(pacing_delay)

    logger.info(f"\n=== Session Finished: Solved {solved_this_run}/{len(candidate_problems)} problems ===")
    logger.info(f"Total CodeChef problems solved to date: {db.get('total_solved', 0)}")


if __name__ == "__main__":
    run()
