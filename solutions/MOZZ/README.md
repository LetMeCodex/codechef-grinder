# [Endless Appetizers (MOZZ)](https://www.codechef.com/problems/MOZZ)
- **Difficulty Rating**: 752
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the minimum number of appetizer plates Chef needs to order. Chef initially has `X` sticks. He also has `R` rupees, and for every 30 rupees, he receives one additional stick. Each plate of appetizers contains `Y` sticks. We need to determine the total number of sticks Chef will consume and then find the smallest integer number of plates required to obtain at least that many sticks.

## Intuition & Mathematical Observation

The problem can be broken down into two main steps:

1.  **Calculate the total number of sticks Chef will consume:**
    *   Chef starts with `X` sticks.
    *   He gets additional sticks based on his rupees. For every 30 rupees, he gets 1 extra stick. Since `R` is guaranteed to be a multiple of 30, the number of extra sticks he receives is simply `R / 30`.
    *   Therefore, the `total_sticks_eaten = X + (R / 30)`.

2.  **Calculate the minimum number of plates needed:**
    *   Once we have the `total_sticks_eaten`, we need to determine how many plates Chef must order. Each plate provides `Y` sticks. Chef needs to obtain *at least* `total_sticks_eaten` sticks.
    *   This is a classic ceiling division problem. If Chef needs `A` sticks and each plate provides `B` sticks, the number of plates required is `ceil(A / B)`.
    *   For positive integers `A` and `B`, the ceiling division `ceil(A / B)` can be efficiently calculated using integer arithmetic as `(A + B - 1) / B`.
    *   Let's verify this formula:
        *   If `A = 10` sticks are needed, and `B = 3` sticks per plate: `ceil(10 / 3) = 4`. Using the formula: `(10 + 3 - 1) / 3 = 12 / 3 = 4`. Correct.
        *   If `A = 9` sticks are needed, and `B = 3` sticks per plate: `ceil(9 / 3) = 3`. Using the formula: `(9 + 3 - 1) / 3 = 11 / 3 = 3` (integer division). Correct.

By combining these two steps, we can directly compute the final answer for each test case.

## Complexity Analysis

*   **Time Complexity**: For each test case, the solution performs a fixed number of arithmetic operations (division, addition, subtraction). These operations take constant time. Since there are `T` test cases, the total time complexity is $O(T)$.
*   **Space Complexity**: The solution uses a few integer variables to store input values and intermediate results (`T`, `X`, `Y`, `R`, `extra_sticks`, `total_sticks_eaten`, `plates_ordered`). The amount of memory used does not depend on the magnitude of the input values or the number of test cases (beyond the loop iteration). Therefore, the space complexity is $O(1)$ (constant space).

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries as requested by the problem

// Use the standard namespace as requested
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int X, Y, R;
        cin >> X >> Y >> R; // Read the values for X, Y, and R

        // Step 1: Calculate the number of extra sticks Chef ate.
        // R is guaranteed to be a multiple of 30.
        int extra_sticks = R / 30;

        // Step 2: Calculate the total number of sticks Chef ate.
        // This includes the initial X sticks plus the extra sticks.
        int total_sticks_eaten = X + extra_sticks;

        // Step 3: Calculate the maximum number of plates Chef could have ordered.
        // We need to find the smallest integer number of plates that can provide
        // at least 'total_sticks_eaten' sticks. This is a ceiling division.
        // For positive integers A and B, ceil(A/B) can be calculated as (A + B - 1) / B.
        int plates_ordered = (total_sticks_eaten + Y - 1) / Y;

        // Output the result for the current test case, followed by a newline.
        cout << plates_ordered << "\n";
    }

    return 0; // Indicate successful execution
}
```