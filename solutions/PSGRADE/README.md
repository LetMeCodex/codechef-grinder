# Passing Marks (PSGRADE)
- **Difficulty Rating**: 904
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a student, Chef, passes a set of exams. To pass, Chef must satisfy four conditions:
1. The score in subject A must be greater than or equal to a minimum required score for subject A.
2. The score in subject B must be greater than or equal to a minimum required score for subject B.
3. The score in subject C must be greater than or equal to a minimum required score for subject C.
4. The sum of scores in subjects A, B, and C must be greater than or equal to a minimum total required score.

If all four conditions are met, Chef passes; otherwise, Chef fails. We are given the minimum required scores for each subject and the total, along with Chef's actual scores in each subject. The input consists of multiple test cases.

## Intuition & Mathematical Observation
The problem statement directly translates into a set of logical conditions. Chef passes if and only if *all* the specified criteria are met. This suggests a straightforward implementation using logical AND (`&&`) operators.

Let:
- $A_{min}$, $B_{min}$, $C_{min}$ be the minimum required scores for subjects A, B, and C respectively.
- $T_{min}$ be the minimum required total score.
- $A$, $B$, $C$ be Chef's actual scores in subjects A, B, and C respectively.

Chef passes if the following four conditions are simultaneously true:
1. $A \ge A_{min}$
2. $B \ge B_{min}$
3. $C \ge C_{min}$
4. $A + B + C \ge T_{min}$

The solution involves reading the input values for each test case and checking if all these conditions hold. If they do, we print "YES"; otherwise, we print "NO".

The use of `std::ios_base::sync_with_stdio(false);` and `std::cin.tie(NULL);` is a standard optimization in competitive programming to speed up input/output operations, which can be crucial for problems with a large number of test cases or large inputs.

## Complexity Analysis
- **Time Complexity**: $O(T)$
  For each test case, we perform a constant number of comparisons and arithmetic operations. Since there are $T$ test cases, the total time complexity is directly proportional to the number of test cases, $T$.

- **Space Complexity**: $O(1)$
  We only use a few integer variables to store the minimum scores, Chef's scores, and the number of test cases. The amount of memory used does not grow with the input size or the number of test cases, making the space complexity constant.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes most standard libraries, as requested by problem statement
using namespace std;       // Uses the standard namespace, as requested

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare variable for the number of testcases
    cin >> T; // Read the number of testcases

    // Loop through each testcase
    while (T--) {
        // Declare variables for minimum required scores and Chef's actual scores
        int A_min, B_min, C_min, T_min; // Minimum scores for subjects and total
        int A, B, C;                   // Chef's scores in subjects

        // Read the seven integers for the current testcase
        cin >> A_min >> B_min >> C_min >> T_min >> A >> B >> C;

        // Check all four conditions simultaneously using logical AND (&&) operator.
        // Chef passes only if ALL conditions are true.
        if (A >= A_min &&        // Condition 1: Score in subject A meets minimum
            B >= B_min &&        // Condition 2: Score in subject B meets minimum
            C >= C_min &&        // Condition 3: Score in subject C meets minimum
            (A + B + C >= T_min) // Condition 4: Total score meets minimum
        ) {
            // If all conditions are met, Chef passes
            cout << "YES\n";
        } else {
            // Otherwise, Chef does not pass
            cout << "NO\n";
        }
    }

    return 0; // Indicate successful program execution
}
```