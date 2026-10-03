# Count the ACs (ACS)

- **Difficulty Rating**: 739
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the total number of problems solved by a participant given their total score. We are told that there are 10 problems in total. Each problem is worth either 1 point or 100 points. The participant's score `P` is given, and we need to find the total count of problems they solved. If the score `P` is impossible to achieve under the given rules, we should output -1.

The score `P` can range from 0 to 1000.

## Intuition & Mathematical Observation

Let `x` be the number of problems solved that are worth 100 points, and `y` be the number of problems solved that are worth 1 point.

We are given the following constraints:
1.  The total number of problems solved cannot exceed 10: `x + y <= 10`
2.  The number of 100-point problems (`x`) must be non-negative: `x >= 0`
3.  The number of 1-point problems (`y`) must be non-negative: `y >= 0`
4.  The total score `P` is formed by these problems: `100 * x + 1 * y = P`

Our goal is to find the value of `x + y`.

From constraint 4, we can express `y` in terms of `P` and `x`:
`y = P - 100 * x`

Now, we can substitute this into the other constraints:

*   **Constraint 1**: `x + (P - 100 * x) <= 10`
    This simplifies to: `P - 99 * x <= 10`

*   **Constraint 3**: `y >= 0`
    Substituting `y`: `P - 100 * x >= 0`
    This implies `P >= 100 * x`, or `x <= P / 100`.

Combining these, for a given score `P`, we are looking for non-negative integers `x` and `y` such that:
1.  `x <= 10` (since there are only 10 problems in total, `x` cannot exceed 10)
2.  `x <= P / 100` (to ensure `y` is non-negative)
3.  `P - 99 * x <= 10` (to ensure `x + y <= 10`)

The problem statement implies that for a valid score `P`, there is a unique number of problems solved. This means there should be a unique pair `(x, y)` that satisfies the conditions for a given `P`.

We can iterate through all possible values of `x` (from 0 to 10) and check if a valid `y` can be formed.

For each `x` from 0 to 10:
1.  Calculate the score from 100-point problems: `score_100 = x * 100`.
2.  Check if this score is achievable within the total score `P`: `score_100 <= P`. If not, this `x` is too high, and we can stop checking higher `x` values (or continue if we are iterating from 0).
3.  If `score_100 <= P`, calculate the remaining score needed from 1-point problems: `y = P - score_100`.
4.  Check if the total number of problems solved (`x + y`) is within the limit: `x + y <= 10`.
5.  If both conditions (`score_100 <= P` and `x + y <= 10`) are met, then we have found a valid combination. The number of problems solved is `x + y`. Since the problem implies a unique answer, the first valid combination we find will give us the correct total number of solved problems.

The initial check `if (p < 0 || p > 1000)` handles invalid score ranges. The maximum possible score is 10 problems * 100 points/problem = 1000 points. The minimum is 0.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The outer loop iterates at most 11 times (for `x` from 0 to 10). Inside the loop, operations are constant time. The initial check for `p` is also constant time. Therefore, the overall time complexity is constant.

-   **Space Complexity**: $O(1)$
    The solution uses a few integer variables to store the score, loop counters, and the answer. The space used does not depend on the input size, making it constant.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Number of test cases
    cin >> t;
    while (t--) {
        int p; // The participant's score
        cin >> p;

        // Check for impossible score ranges.
        // The minimum score is 0 (0 problems solved).
        // The maximum score is 10 problems * 100 points/problem = 1000 points.
        if (p < 0 || p > 1000) {
            cout << -1 << "\n";
        } else {
            int ans = -1; // Initialize answer to -1 (indicating no solution found yet)

            // Iterate through all possible numbers of 100-point problems (x).
            // x can range from 0 to 10, as there are at most 10 problems.
            for (int x = 0; x <= 10; ++x) {
                int score_from_100_point_problems = x * 100;

                // Check if the score from 100-point problems does not exceed the total score P.
                // This also implicitly checks if the number of 1-point problems (y) would be non-negative.
                if (score_from_100_point_problems <= p) {
                    // Calculate the remaining score that must come from 1-point problems.
                    int y = p - score_from_100_point_problems;

                    // Check if the total number of problems solved (x + y) does not exceed 10.
                    if (x + y <= 10) {
                        // We found a valid combination of x and y that sums up to P
                        // and satisfies the total number of problems constraint.
                        // Since the problem implies a unique number of solved problems for a valid score,
                        // the first valid combination found is the answer.
                        ans = x + y;
                        break; // Exit the loop as we've found the solution.
                    }
                }
            }
            // Output the calculated number of solved problems, or -1 if no valid combination was found.
            cout << ans << "\n";
        }
    }
    return 0;
}
```