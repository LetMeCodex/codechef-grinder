# [Product Exceed (PRDEXC)](https://www.codechef.com/problems/PRDEXC)
- **Difficulty Rating**: 981
- **Solved in**: 2 attempt(s)

## Problem Summary

The problem asks us to find the minimum number of moves required to make the product of two integers, `x` and `y`, at least `p`. A move consists of incrementing either `x` by 1 or `y` by 1. We need to find the minimum value of `moves_x + moves_y` such that `(x + moves_x) * (y + moves_y) >= p`, where `moves_x` and `moves_y` are non-negative integers.

## Intuition & Mathematical Observation

1.  **Base Case:** If the initial product `x * y` is already greater than or equal to `p`, then no moves are needed. The answer is `0`.

2.  **Objective Function:** We want to minimize `moves_x + moves_y`. Let `X' = x + moves_x` and `Y' = y + moves_y`. Our goal is to satisfy `X' * Y' >= p`.
    For a fixed value of `moves_x` (and thus a fixed `X'`), we need to find the minimum `moves_y` such that `X' * (y + moves_y) >= p`.
    This implies `y + moves_y >= p / X'`. Since `y + moves_y` must be an integer, the smallest integer value it can take is `ceil(p / X')`.
    Let `target_Y_prime = ceil(p / X')`.
    Then, the required `moves_y` would be `max(0LL, target_Y_prime - y)`. We use `max(0LL, ...)` because `moves_y` cannot be negative.

    So, for a given `moves_x`, the total number of moves is `f(moves_x) = moves_x + max(0LL, ceil(p / (x + moves_x)) - y)`.

3.  **Function Behavior and Search Space:**
    *   The term `moves_x` increases linearly with `moves_x`.
    *   The term `ceil(p / (x + moves_x))` decreases as `moves_x` increases (since `x + moves_x` is in the denominator).
    *   Functions of the form `A + C/A` (where `A` is `x + moves_x` and `C` is `p`) typically have their minimum value when `A` is approximately `sqrt(C)`.
    *   This suggests that the optimal `moves_x` will be relatively small, roughly around `sqrt(p) - x`.
    *   Given that `p` can be up to `10^4`, `sqrt(p)` is at most `sqrt(10^4) = 100`.
    *   Therefore, we only need to check `moves_x` values in a limited range. A safe upper bound for `moves_x` to check would be `2 * sqrt(p)` plus a small constant (e.g., 2 or 3) to account for integer rounding and the `max(0LL, ...)` term.
    *   For `p = 10^4`, `2 * sqrt(p) + 2 = 2 * 100 + 2 = 202`. This means we iterate at most about 200-300 times for each test case, which is very efficient.

4.  **Integer Ceiling Calculation:** For positive integers `a` and `b`, `ceil(a / b)` can be calculated using integer division as `(a + b - 1) / b`.

By iterating `moves_x` from `0` up to this calculated limit and finding the minimum `f(moves_x)`, we can find the overall minimum number of moves.

## Complexity Analysis

*   **Time Complexity**:
    The core of the solution is a loop that iterates `moves_x` from `0` up to a limit. This limit is approximately `2 * sqrt(p)`. Inside the loop, all operations (arithmetic, `max`) are constant time.
    Since there are `t` test cases, the total time complexity is $O(t \cdot \sqrt{P_{max}})$, where $P_{max}$ is the maximum possible value of `p`.
    Given $P_{max} = 10^4$, $\sqrt{P_{max}} = 100$. With $t = 100$, the total operations are roughly $100 \cdot 200 = 2 \cdot 10^4$, which is very fast and well within typical time limits.

*   **Space Complexity**:
    The solution uses a few variables to store `x, y, p`, loop counters, and the minimum moves found. This requires a constant amount of memory.
    Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <iostream>
#include <algorithm> // For std::max
#include <cmath>     // For sqrt

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        long long x, y, p;
        std::cin >> x >> y >> p; // Read x, y, p for each test case

        // If the initial product is already >= p, no moves are needed.
        if (x * y >= p) {
            std::cout << 0 << "\n";
            continue;
        }

        long long min_moves = -1; // Initialize min_moves to an invalid value

        // The function to minimize is f(moves_x) = moves_x + max(0LL, ceil(P / (X + moves_x)) - Y)
        // This function has a minimum typically when (X + moves_x) is around sqrt(P).
        // A safe upper bound for moves_x to check is around 2 * sqrt(P).
        // For P_max = 10^4, sqrt(P_max) = 100. So, 2*100 + 2 = 202 iterations.
        // This is a small and efficient search space.
        long long limit = 2 * static_cast<long long>(sqrt(p)) + 2;

        // Iterate through possible values of moves_x
        for (long long moves_x = 0; moves_x <= limit; ++moves_x) {
            long long current_x = x + moves_x;

            // Calculate target_y_prime = ceil(p / current_x) using integer division.
            // For positive integers a, b, ceil(a/b) is (a + b - 1) / b.
            long long target_y_prime = (p + current_x - 1) / current_x;
            
            // Calculate moves_y required. It cannot be negative.
            long long moves_y = std::max(0LL, target_y_prime - y);
            
            long long total_moves = moves_x + moves_y;
            
            // Update min_moves if a smaller total_moves is found
            if (min_moves == -1 || total_moves < min_moves) {
                min_moves = total_moves;
            }
        }
        
        std::cout << min_moves << "\n"; // Output the minimum moves
    }
    return 0;
}

```