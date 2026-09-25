# [Pass the Exam (PASSTHEEXAM)](https://www.codechef.com/problems/PASSTHEEXAM)
- **Difficulty Rating**: 424
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if Chef passes an exam based on his scores in three sections: A, B, and C. To pass the exam, Chef must satisfy two conditions simultaneously:

1.  **Total Score Condition**: The sum of his scores in all three sections (A + B + C) must be greater than or equal to 100.
2.  **Minimum Section Score Condition**: His score in each individual section (A, B, and C) must be greater than or equal to 10.

If both of these conditions are met, Chef passes the exam. Otherwise, Chef fails. We need to output "PASS" or "FAIL" accordingly for each test case.

## Intuition & Mathematical Observation

This problem is a direct application of conditional logic. We are given two distinct conditions that must both be true for Chef to pass.

1.  **Condition 1 (Total Score)**: We need to calculate the sum of the three scores, `A + B + C`. Then, we check if this sum is `>= 100`. This can be represented as a boolean expression: `(A + B + C >= 100)`.
2.  **Condition 2 (Minimum Section Score)**: We need to check each score individually. `A` must be `>= 10`, `B` must be `>= 10`, and `C` must be `>= 10`. All three of these sub-conditions must be true. This can be represented as a boolean expression: `(A >= 10 && B >= 10 && C >= 10)`.

Chef passes if and only if **both** Condition 1 AND Condition 2 are true. Therefore, the final logic is `(Condition 1) && (Condition 2)`. If this combined expression evaluates to true, we print "PASS"; otherwise, we print "FAIL".

No complex algorithms, data structures, or mathematical observations beyond basic arithmetic and logical operations are required.

## Complexity Analysis

*   **Time Complexity**: For each test case, we perform a few constant-time operations: reading three integers, summing them, and performing a few comparisons. These operations take $O(1)$ time. Since there are $T$ test cases, the total time complexity will be $O(T)$.
*   **Space Complexity**: We only use a few integer variables to store the scores and the total sum. This amount of memory is constant and does not depend on the input values or the number of test cases (beyond the loop counter). Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries like iostream

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

// Function to solve a single test case
void solve() {
    int A, B, C;
    // Read Chef's scores for the three sections
    cin >> A >> B >> C;

    // Condition 1: Total score of Chef is >= 100
    // Calculate the sum of scores
    int total_score = A + B + C;
    bool total_score_condition_met = (total_score >= 100);

    // Condition 2: Score of each section >= 10
    bool section_scores_condition_met = (A >= 10 && B >= 10 && C >= 10);

    // Chef passes if BOTH conditions are satisfied
    if (total_score_condition_met && section_scores_condition_met) {
        cout << "PASS\n"; // Output PASS if both conditions are true
    } else {
        cout << "FAIL\n"; // Output FAIL otherwise
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    // Read the number of test cases
    cin >> T;
    // Loop T times, calling the solve function for each test case
    while (T--) {
        solve();
    }

    return 0; // Indicate successful program execution
}
```