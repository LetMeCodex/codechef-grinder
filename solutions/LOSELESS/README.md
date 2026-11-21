# [Lose Less (LOSELESS)](https://www.codechef.com/problems/LOSELESS)
- **Difficulty Rating**: 900
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum possible number of losses given the total number of matches played (`M`) and the total points obtained (`N`). The scoring system is:
- Win: 3 points
- Tie: 1 point
- Loss: 0 points

We are guaranteed that a valid combination of wins, ties, and losses always exists for the given `M` and `N`.

## Intuition & Mathematical Observation

Let's define variables for the number of wins, ties, and losses:
- `W`: Number of wins
- `T`: Number of ties
- `L`: Number of losses

From the problem statement, we can form two equations:

1.  **Total Matches**: The sum of wins, ties, and losses must equal the total matches played:
    `W + T + L = M`

2.  **Total Points**: The sum of points from wins and ties must equal the total points obtained (losses contribute 0 points):
    `3W + T = N`

Our goal is to **minimize `L`**. To do this, we should try to express `L` in terms of `M`, `N`, and one of the other variables (`W` or `T`).

From the total points equation (`3W + T = N`), we can express `T` in terms of `W` and `N`:
`T = N - 3W`

Now, substitute this expression for `T` into the total matches equation (`W + T + L = M`):
`W + (N - 3W) + L = M`
`W + N - 3W + L = M`
`N - 2W + L = M`

Rearranging this equation to solve for `L`:
`L = M - N + 2W`

This is a crucial relationship: `L = M - N + 2W`. To minimize `L`, we need to minimize `W` (since `M` and `N` are constants for a given test case, and `2` is a positive coefficient).

Now, let's determine the minimum possible value for `W`. `W` must satisfy several constraints:

1.  **`W >= 0`**: The number of wins cannot be negative.
2.  **`T >= 0`**: The number of ties cannot be negative. Since `T = N - 3W`, we must have:
    `N - 3W >= 0`
    `N >= 3W`
    `W <= N/3`
3.  **`L >= 0`**: The number of losses cannot be negative. Since `L = M - N + 2W`, we must have:
    `M - N + 2W >= 0`
    `2W >= N - M`
    `W >= (N - M)/2`

Combining the constraints for `W`:
- `W >= 0`
- `W >= (N - M)/2`

Therefore, the minimum possible integer value for `W` must be the maximum of `0` and the ceiling of `(N - M)/2`.
`W_min = max(0, ceil((N - M)/2))`

The problem guarantees that a solution always exists, which implies that this `W_min` will also satisfy `W <= N/3`.

Once we find `W_min`, we can substitute it back into the equation for `L` to find the minimum number of losses:
`min_L = M - N + 2 * W_min`

**Ceiling Division for Integers**:
The expression `ceil((N - M)/2)` needs careful handling with integer division in C++.
- For positive `a` and `b`, `ceil(a/b)` can be computed as `(a + b - 1) / b`.
- For negative `a` and positive `b`, C++ integer division `a/b` truncates towards zero, which effectively computes `ceil(a/b)` if `a` is not a multiple of `b` (e.g., `-5/2` is `-2`, and `ceil(-2.5)` is `-2`). If `a` is a multiple of `b`, it's also correct (e.g., `-4/2` is `-2`, and `ceil(-2)` is `-2`).
The provided `ceil_div` function correctly handles both positive and negative numerators.

## Complexity Analysis

-   **Time Complexity**: The `solve` function performs a fixed number of arithmetic operations (subtraction, division, multiplication, comparison, `std::max`). These operations take constant time. The `main` function iterates `T` times, calling `solve` for each test case. Therefore, the total time complexity is $O(T)$.

-   **Space Complexity**: The solution uses a few variables (`M`, `N`, `W_lower_bound`, `min_W`, `min_L`) to store intermediate results. These variables occupy a constant amount of memory, regardless of the input values. Thus, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <iostream>
#include <algorithm> // For std::max

// Function to compute ceil(a/b) for integer a and positive integer b.
// C++ integer division truncates towards zero.
// If a is non-negative, ceil(a/b) is (a + b - 1) / b.
// If a is negative, ceil(a/b) is a / b (e.g., ceil(-5/2) = -2, and -5/2 in C++ is -2).
long long ceil_div(long long a, long long b) {
    if (a >= 0) {
        return (a + b - 1) / b;
    } else {
        return a / b;
    }
}

void solve() {
    long long M, N;
    std::cin >> M >> N;

    // Let W = number of wins, T = number of ties, L = number of losses.
    // Total matches: W + T + L = M
    // Total points: 3W + T = N (Losses contribute 0 points)

    // From total points equation, T = N - 3W.
    // Substitute T into total matches equation to find L:
    // L = M - W - T
    // L = M - W - (N - 3W)
    // L = M - N + 2W

    // To minimize L, we need to minimize W.
    // Constraints on W:
    // 1. W >= 0 (Number of wins cannot be negative)
    // 2. T >= 0  => N - 3W >= 0 => 3W <= N => W <= N/3
    // 3. L >= 0  => M - N + 2W >= 0 => 2W >= N - M => W >= (N - M)/2

    // The minimum W must satisfy W >= 0 and W >= ceil((N - M)/2).
    // So, the minimum W is max(0, ceil((N - M)/2)).
    // The problem guarantees that a solution exists, which implies that
    // this minimum W will also satisfy W <= N/3.

    long long W_lower_bound = ceil_div(N - M, 2);
    long long min_W = std::max(0LL, W_lower_bound);

    // Calculate the minimum number of losses using the derived formula and min_W.
    long long min_L = M - N + 2 * min_W;

    std::cout << min_L << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases.
    while (T--) {
        solve(); // Solve each test case.
    }

    return 0;
}
```