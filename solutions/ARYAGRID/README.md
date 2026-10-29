# [Arya In Grid (ARYAGRID)](https://www.codechef.com/problems/ARYAGRID)
- **Difficulty Rating**: 1341
- **Solved in**: 2 attempt(s)

## Problem Summary

The problem asks us to find the total number of distinct cells `(X, Y)` that can be reached from a starting cell `(X0, Y0)` within a grid of size `N x M`. A cell `(X, Y)` is considered reachable if its row coordinate `X` satisfies `X % L == X0 % L` and its column coordinate `Y` satisfies `Y % L == Y0 % L`. The grid is 1-indexed, meaning `1 <= X <= N` and `1 <= Y <= M`. We are given `N, M, X0, Y0, L` for each test case.

## Intuition & Mathematical Observation

The core of the problem lies in the condition `X % L == X0 % L` and `Y % L == Y0 % L`. This means that the row coordinate `X` must have the same remainder as `X0` when divided by `L`, and similarly for `Y` and `Y0`. Since the conditions for `X` and `Y` are independent, we can calculate the number of reachable rows and the number of reachable columns separately, and then multiply these two counts to get the total number of distinct reachable cells.

Let's focus on finding the number of reachable rows. We need to find all `X` such that `1 <= X <= N` and `X % L == X0 % L`.
A common way to handle remainders when dealing with 1-based indexing and positive numbers is to consider `(X - 1) % L`. If `X % L == X0 % L`, it implies that `X` and `X0` are congruent modulo `L`. This also means `X - 1` and `X0 - 1` are congruent modulo `L`.
So, we are looking for `X` such that `1 <= X <= N` and `(X - 1) % L == (X0 - 1) % L`.

Let `remainder_val = (X0 - 1) % L`. This `remainder_val` will be an integer in the range `[0, L-1]`.
Any reachable `X` must satisfy `(X - 1) % L == remainder_val`. This means `X - 1` must be of the form `k * L + remainder_val` for some non-negative integer `k`.
Therefore, `X = k * L + remainder_val + 1`.

To find the number of such `X` values within `[1, N]`:
1.  **Find the smallest reachable row coordinate (`X_start`):** This occurs when `k = 0`.
    `X_start = remainder_val + 1`.
    Since `remainder_val` is in `[0, L-1]`, `X_start` will be in `[1, L]`. This `X_start` is guaranteed to be within the grid boundaries (at least `1`).

2.  **Count the number of reachable rows:** The reachable rows form an arithmetic progression: `X_start, X_start + L, X_start + 2L, ..., X_start + k_max * L`.
    We need `X_start + k * L <= N`.
    Rearranging for `k`: `k * L <= N - X_start`
    `k <= (N - X_start) / L` (using integer division).
    The maximum value for `k` is `k_max = (N - X_start) / L`.
    Since `k` can range from `0` to `k_max`, the total number of terms (reachable rows) is `k_max + 1`.
    So, `count_rows = (N - X_start) / L + 1`.
    (Note: If `X_start > N`, then `N - X_start` would be negative. Integer division of a negative number by a positive number typically truncates towards zero. For example, `(-5)/3` might be `-1`. In C++, `(-5)/3` is `-1`. So `(-5)/3 + 1` would be `0`, which correctly indicates no reachable rows. This formula works even if `X_start` is greater than `N`, though `X_start` is always `1 <= X_start <= L`, so `X_start > N` only happens if `L > N` and `X_start` happens to be greater than `N`.)

The exact same logic applies to the column coordinates `Y`:
1.  `Y_start = (Y0 - 1) % L + 1`.
2.  `count_cols = (M - Y_start) / L + 1`.

Finally, the total number of distinct reachable cells is `count_rows * count_cols`.
Given that `N, M, L` can be up to `10^9`, the counts can also be large, and their product can exceed `2^31 - 1`. Therefore, `long long` data type must be used for all calculations and the final result.

## Complexity Analysis

*   **Time Complexity**: For each test case, the solution performs a fixed number of arithmetic operations (subtractions, modulo, additions, divisions, and one multiplication). These operations take constant time. Reading input and printing output also take constant time per test case. If there are `T` test cases, the total time complexity is $O(T)$.
*   **Space Complexity**: The solution uses a constant amount of memory to store variables (`N, M, X0, Y0, L`, `X_start`, `count_rows`, etc.) for each test case. This memory usage does not depend on the input size. Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <cstdio> // Required for standard input/output operations (scanf/printf)

void solve() {
    long long N, M, X0, Y0, L;
    // Read the five space-separated integers for the current test case using scanf
    scanf("%lld %lld %lld %lld %lld", &N, &M, &X0, &Y0, &L);

    // Calculate the smallest reachable row coordinate (X_start)
    // This is the smallest number >= 1 that has the same remainder as X0 when divided by L.
    // (X0 - 1) % L gives a remainder in [0, L-1]. Adding 1 shifts it to [1, L].
    long long X_start = (X0 - 1) % L + 1;
    
    // Calculate the number of reachable rows.
    // The reachable rows form an arithmetic progression: X_start, X_start + L, X_start + 2L, ...
    // The largest term is X_start + k*L <= N.
    // The number of terms is k_max + 1, where k_max = (N - X_start) / L (integer division).
    long long count_rows = (N - X_start) / L + 1;

    // Perform the same calculation for column coordinates
    long long Y_start = (Y0 - 1) % L + 1;
    long long count_cols = (M - Y_start) / L + 1;

    // The total number of distinct reachable cells is the product of the number of reachable rows
    // and the number of reachable columns. This is because any combination of a reachable row
    // and a reachable column forms a reachable cell.
    long long total_reachable_cells = count_rows * count_cols;

    // Print the result for the current test case using printf, followed by a newline
    printf("%lld\n", total_reachable_cells);
}

int main() {
    // When using scanf/printf, std::ios_base::sync_with_stdio(false) and std::cin.tie(NULL) are not needed.
    
    int T;
    // Read the number of test cases
    scanf("%d", &T);
    // Loop through each test case
    while (T--) {
        solve();
    }

    return 0;
}
```