import sys
from pathlib import Path

if sys.platform == "win32" and hasattr(sys.stdout, "reconfigure"):
    try:
        sys.stdout.reconfigure(encoding="utf-8")
    except Exception:
        pass

# Add project root to sys.path
sys.path.insert(0, str(Path(__file__).parent.parent))

from src.codechef_client import CodeChefClient
from src.solver import CodeChefSolver


def test_problem_discovery():
    print("[1/4] Testing Problem Discovery API...")
    client = CodeChefClient()
    problems = client.fetch_practice_problems(page=0, limit=5)
    assert len(problems) > 0, "Problems list should not be empty"
    first = problems[0]
    assert first.get("code"), "Problem code must exist"
    print(f"  [OK] Fetched {len(problems)} problems. Top: {first.get('code')} - {first.get('name')}")


def test_problem_details_and_csrf():
    print("[2/4] Testing Problem Details & Dynamic CSRF Extraction...")
    client = CodeChefClient()
    details = client.fetch_problem_details("START01")
    assert details.get("problem_code") == "START01"
    assert len(details.get("cleanContent", "")) > 10, "Clean content must exist"

    csrf_token = client.get_csrf_token("START01")
    assert csrf_token and len(csrf_token) == 64, "Dynamic window.csrfToken must be a 64-character hex hash"
    print(f"  [OK] Extracted Problem 'START01' details and CSRF Token: {csrf_token[:12]}...")


def test_verdict_parser():
    print("[3/4] Testing Verdict Parsing Logic...")
    client = CodeChefClient()
    # Correct AC
    ac = client.parse_verdict({"result_code": "correct", "time": "0.02", "memory": "3.5M"})
    assert ac["passed"] is True
    assert ac["result_code"] == "correct"

    # Wrong Answer
    wa = client.parse_verdict({"result_code": "wrong", "score": 0, "custom__message": "Wrong Answer on testcase 2"})
    assert wa["passed"] is False
    assert "WRONG ANSWER" in wa["diagnostic"]
    print("  [OK] Verdict parsing handles AC and WA correctly.")


def test_code_cleaner():
    print("[4/4] Testing Code Extractor...")
    solver = CodeChefSolver()
    raw = """Here is the solution:
```cpp
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    cout << n << "\\n";
    return 0;
}
```
Good luck!
"""
    clean = solver.extract_clean_code(raw)
    assert clean.startswith("#include <iostream>")
    assert not clean.endswith("```")
    assert "Good luck!" not in clean
    print("  [OK] Clean code extraction verified.")


if __name__ == "__main__":
    print("=== Running CodeChef Bot Component Tests ===")
    test_problem_discovery()
    test_problem_details_and_csrf()
    test_verdict_parser()
    test_code_cleaner()
    print("\n[SUCCESS] All 4 CodeChef test suites PASSED successfully!")
