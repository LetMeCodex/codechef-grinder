# [Cup Finals (CRICUP)](https://www.codechef.com/problems/CRICUP)
- **Difficulty Rating**: 716
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a cricket match between two teams will be interesting to Chef. We are given the skill level of the first team, `X`, the skill level of the second team, `Y`, and a maximum allowed skill difference, `D`. Chef finds a match interesting if the absolute difference between the skill levels of the two teams is less than or equal to `D`. For each test case, we need to output "YES" if the match is interesting, and "NO" otherwise.

## Intuition & Mathematical Observation

The core of this problem lies in a simple comparison. We need to quantify the "difference" in skill levels between the two teams and then check if this difference meets Chef's criteria.

1.  **Calculate the Skill Difference**: The difference between two quantities, regardless of which is larger, is typically represented by their absolute difference. So, if the skill levels are `X` and `Y`, the skill difference is `|X - Y|`. For example, if `X=10` and `Y=7`, the difference is `|10 - 7| = 3`. If `X=7` and `Y=10`, the difference is `|7 - 10| = |-3| = 3`.

2.  **Apply Chef's Criteria**: Chef finds the match interesting if this calculated skill difference is less than or equal to `D`.
    *   If `|X - Y| <= D`, then the match is interesting. We should output "YES".
    *   If `|X - Y| > D`, then the match is not interesting. We should output "NO".

This is a direct application of the absolute value function and a conditional check.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    For each test case, the solution performs a constant number of operations: reading three integers, calculating an absolute difference, and a single comparison, followed by printing a string. These operations take constant time, $O(1)$. Since there are $T$ test cases, the total time complexity is $T \times O(1) = O(T)$.

*   **Space Complexity**: $O(1)$
    The solution uses a fixed number of integer variables (`T`, `X`, `Y`, `D`, `skill_difference`) to store input and intermediate results. The memory usage does not depend on the magnitude of the input values or the number of test cases (beyond storing `T` itself). Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <iostream> // Required for cin, cout
#include <cmath>    // Required for abs()
#include <algorithm> // Not strictly needed if using cmath's abs, but good for general utility

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and prevents synchronization with C's stdio.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Number of testcases
    std::cin >> T; // Read the number of testcases

    while (T--) { // Loop T times for each testcase
        int X, Y, D; // Skill levels of teams X, Y, and maximum allowed difference D
        std::cin >> X >> Y >> D; // Read X, Y, and D for the current testcase

        // Calculate the absolute difference between the skill levels of the two teams.
        // std::abs() is used to ensure the difference is non-negative.
        int skill_difference = std::abs(X - Y);

        // Check if the calculated skill difference is less than or equal to D.
        if (skill_difference <= D) {
            std::cout << "YES\n"; // If it is, Chef finds the game interesting
        } else {
            std::cout << "NO\n"; // Otherwise, Chef does not find the game interesting
        }
    }

    return 0; // Indicate successful execution
}
```