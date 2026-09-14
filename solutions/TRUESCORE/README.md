# [Is the Score Consistent (TRUESCORE)](https://www.codechef.com/problems/TRUESCORE)
- **Difficulty Rating**: 572
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a given final score `C:D` is "consistent" with an initial score `A:B`. A score is considered consistent if it's possible for the game to progress from `A:B` to `C:D`. The only rule governing this progression is that a team's score can never decrease; it can only increase or stay the same. For each test case, we need to output "POSSIBLE" if the final score is consistent, and "IMPOSSIBLE" otherwise.

## Intuition & Mathematical Observation

The core of this problem lies directly in the rule provided: "A team's score can never decrease." This simple rule translates into two independent conditions that must both be met for the final score `C:D` to be consistent with the initial score `A:B`:

1.  **For Team 1**: Its final score `C` must be greater than or equal to its initial score `A`. If `C < A`, it means Team 1's score would have decreased, which is not allowed. So, we must have `C >= A`.
2.  **For Team 2**: Similarly, its final score `D` must be greater than or equal to its initial score `B`. If `D < B`, it means Team 2's score would have decreased, which is not allowed. So, we must have `D >= B`.

If *both* these conditions (`C >= A` AND `D >= B`) are true, then it is possible for the score to transition from `A:B` to `C:D`. In this scenario, Team 1 would have scored `C - A` additional goals, and Team 2 would have scored `D - B` additional goals. Since `C - A >= 0` and `D - B >= 0`, this is a valid progression where scores only increase or stay the same.

If either `C < A` or `D < B` (or both), then at least one team's score would have decreased, violating the problem's rule. In such a case, the score `C:D` is "IMPOSSIBLE".

## Complexity Analysis

-   **Time Complexity**: The solution processes `T` test cases. For each test case, it performs a constant number of operations: reading four integers (`A`, `B`, `C`, `D`), two comparisons (`C >= A` and `D >= B`), and printing a string ("POSSIBLE" or "IMPOSSIBLE"). These operations take constant time. Therefore, the total time complexity is directly proportional to the number of test cases, $T$. This gives us $O(T)$.

-   **Space Complexity**: The solution uses a fixed number of integer variables (`T`, `A`, `B`, `C`, `D`) to store input and perform calculations. The memory usage does not scale with the magnitude of the input values or the number of test cases (beyond the fixed variables themselves). Thus, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> 

// It's common practice in competitive programming to use the entire standard namespace
// to avoid repeatedly typing `std::`. The problem statement also suggests this.
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // `ios_base::sync_with_stdio(false)` unties C++ streams from C standard streams.
    // `cin.tie(NULL)` prevents `cin` from flushing `cout` before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int A, B; // Declare integers A and B for the initial scores of team 1 and team 2.
        cin >> A >> B; // Read the initial scores.

        int C, D; // Declare integers C and D for the potential final scores of team 1 and team 2.
        cin >> C >> D; // Read the potential final scores.

        // To determine if a score C:D is possible from A:B, two conditions must be met:
        // 1. Team 1's score (C) must be greater than or equal to its initial score (A).
        //    A team's score cannot decrease.
        // 2. Team 2's score (D) must be greater than or equal to its initial score (B).
        //    Similarly, a team's score cannot decrease.
        if (C >= A && D >= B) {
            // If both conditions are true, then it is possible for the score to become C:D.
            // Team 1 scores (C - A) more goals and Team 2 scores (D - B) more goals.
            cout << "POSSIBLE\n"; 
        } else {
            // If either condition is false (i.e., C < A or D < B or both),
            // then it is impossible for the score to become C:D.
            cout << "IMPOSSIBLE\n";
        }
    }

    return 0; // Indicate successful program execution.
}
```