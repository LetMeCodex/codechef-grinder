# [Buying Flowers (FLOWERBUY)](https://www.codechef.com/problems/FLOWERBUY)
- **Difficulty Rating**: 931
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum cost to buy exactly `N` flowers. We are given two options for purchasing flowers:
1.  Buy 2 flowers for 4 coins.
2.  Buy 3 flowers for 5 coins.

We need to determine the combination of these two options that yields exactly `N` flowers at the lowest possible total cost.

## Intuition & Mathematical Observation

Let's analyze the cost per flower for each option:
*   **Option 1**: 2 flowers for 4 coins. Cost per flower = $4 / 2 = 2$ coins.
*   **Option 2**: 3 flowers for 5 coins. Cost per flower = $5 / 3 \approx 1.67$ coins.

From this, we observe that Option 2 (buying 3 flowers for 5 coins) is generally more cost-effective per flower. This suggests that we should try to use Option 2 as much as possible to minimize the total cost.

Let's formalize this:
*   Let `x` be the number of times we use Option 1 (buy 2 flowers).
*   Let `y` be the number of times we use Option 2 (buy 3 flowers).

We need to satisfy the following conditions:
1.  **Total flowers**: `2 * x + 3 * y = N` (where `x` and `y` must be non-negative integers).
2.  **Minimize total cost**: `4 * x + 5 * y`.

This is a variation of a linear Diophantine equation with an optimization objective. Since `N` is relatively small (up to 100), we can iterate through possible values for one of the variables (`x` or `y`) and check if a valid integer solution exists for the other.

Given that Option 2 is cheaper per flower, it makes sense to iterate through the number of times we use Option 2 (`y`).
*   The maximum number of times we can use Option 2 is when `3 * y <= N`. So, `y` can range from `0` up to `N / 3`.
*   For each possible value of `y`:
    *   Calculate the `remaining_flowers = N - (3 * y)`.
    *   If `remaining_flowers` is non-negative and can be formed by buying flowers in pairs (i.e., `remaining_flowers % 2 == 0`), then we can find a valid `x`:
        *   `x = remaining_flowers / 2`.
    *   With valid `x` and `y`, calculate the `current_cost = (x * 4) + (y * 5)`.
    *   Keep track of the `minimum_cost` found so far.
*   If `remaining_flowers` is negative or odd, then this `y` value does not lead to a valid combination, and we skip it.

We initialize `min_cost` to a value like `-1` or `INT_MAX` to correctly capture the first valid cost or the smallest subsequent cost.

## Complexity Analysis

*   **Time Complexity**:
    The solution iterates through `T` test cases. For each test case, it runs a `for` loop where `y` goes from `0` up to `N/3`. Since `N` is at most 100, `N/3` is at most `33`. Inside the loop, all operations (arithmetic, comparisons) are constant time. Therefore, for each test case, the complexity is $O(N)$.
    The total time complexity is $O(T \cdot N)$. Given $T \le 1000$ and $N \le 100$, the maximum operations would be around $1000 \cdot 100 = 10^5$, which is very efficient and well within typical time limits.

*   **Space Complexity**:
    The solution uses a few integer variables (`t`, `n`, `min_cost`, `y`, `remaining_flowers`, `x`, `current_cost`) to store intermediate values. These variables occupy a constant amount of memory regardless of the input `N`.
    Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <iostream>
#include <algorithm> // Not strictly needed for this solution, but often useful
#include <vector>    // Not strictly needed for this solution, but often useful

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {  // Loop through each test case
        int n;
        std::cin >> n; // Read the target number of flowers for the current test case

        // We want to find the minimum cost to buy exactly N flowers.
        // We have two options:
        // 1. Buy 2 flowers for 4 coins. Cost per flower: 4/2 = 2.
        // 2. Buy 3 flowers for 5 coins. Cost per flower: 5/3 ≈ 1.67.
        // The second option is generally cheaper per flower.

        // Let x be the number of times we use the (2 flowers, 4 coins) option.
        // Let y be the number of times we use the (3 flowers, 5 coins) option.
        // We need to find non-negative integers x and y such that:
        // 2*x + 3*y = N
        // and we want to minimize the total cost: 4*x + 5*y.

        // Since N is small (up to 100), we can iterate through possible values of y.
        // The maximum number of times we can use the (3 flowers, 5 coins) option
        // is when 3*y <= N. So, y can range from 0 to N/3.

        int min_cost = -1; // Initialize with an invalid value.
                           // This will be updated with the first valid cost,
                           // then with any smaller valid costs found.

        // Iterate through all possible counts of 'y' (3-flower packs)
        for (int y = 0; y * 3 <= n; ++y) {
            int remaining_flowers = n - (y * 3); // Flowers still needed after buying 'y' packs of 3

            // If remaining_flowers is non-negative and can be bought in pairs (even number)
            if (remaining_flowers >= 0 && remaining_flowers % 2 == 0) {
                int x = remaining_flowers / 2; // Number of 2-flower packs needed
                int current_cost = (x * 4) + (y * 5); // Calculate total cost for this (x, y) combination

                // Update min_cost if this is the first valid cost or a cheaper one
                if (min_cost == -1 || current_cost < min_cost) {
                    min_cost = current_cost;
                }
            }
        }
        std::cout << min_cost << "\n"; // Output the minimum cost found
    }
    return 0;
}

```