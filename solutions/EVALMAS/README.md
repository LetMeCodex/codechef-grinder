# [Valid Expression (EVALMAS)](https://www.codechef.com/problems/EVALMAS)
- **Difficulty Rating**: 1354
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to construct a string `S` of `N` operators (`+`, `-`, `*`) such that when these operators are placed between `N+1` ones, the resulting arithmetic expression evaluates to a target value `X`. For example, if `N=2` and `S="*+"`, the expression is `1 * 1 + 1`. Standard operator precedence applies (multiplication before addition/subtraction). If multiple solutions exist, any one is acceptable. If no solution exists, we should output `-1`.

**Constraints**:
*   `1 <= N <= 10^5`
*   `-10^9 <= X <= 10^9`

## Intuition & Mathematical Observation

Let's analyze how each operator affects the expression `1 _ 1 _ 1 ... _ 1` (with `N+1` ones and `N` operator slots).

1.  **Multiplication (`*`)**: The key observation is that `1 * 1` evaluates to `1`. When we place a `*` operator between two `1`s, it effectively "collapses" them into a single `1`. For example, `1 + 1 * 1 + 1` becomes `1 + (1*1) + 1`, which simplifies to `1 + 1 + 1`.
    *   Each `*` operator reduces the *effective number of `1`s* in the expression by one.
    *   If we use `k` multiplication operators, the initial `N+1` ones effectively become `(N+1) - k` ones. Let `M = (N+1) - k` be this effective count of ones.
    *   The remaining `N-k` operators must then be `+` or `-`, operating on these `M` effective `1`s.

2.  **Addition (`+`) and Subtraction (`-`)**: After all multiplications are resolved, we are left with an expression of `M` ones combined by `M-1` operators, all of which are `+` or `-`. This expression will look like `1 op_1 1 op_2 1 ... op_{M-1} 1`.
    *   Let `P` be the number of `+` operators and `Q` be the number of `-` operators among these `M-1` operators.
    *   We know that `P + Q = M - 1`.
    *   The value of such an expression is `1 + P - Q`. (The first `1` is positive, then `P` more `1`s are added, and `Q` `1`s are subtracted).
    *   We need this value to be `X`. So, `1 + P - Q = X`.

Now we have a system of two linear equations for `P` and `Q` for a fixed `M` (which depends on `k`):
1.  `P + Q = M - 1`
2.  `P - Q = X - 1`

Adding the two equations: `2P = (M - 1) + (X - 1) = M + X - 2`
So, `P = (M + X - 2) / 2`

Subtracting the second equation from the first: `2Q = (M - 1) - (X - 1) = M - X`
So, `Q = (M - X) / 2`

**Conditions for a valid solution for a given `k` (and thus `M`):**

1.  **Number of operators**: `k` must be between `0` and `N` inclusive.
2.  **`P` and `Q` must be non-negative integers**:
    *   `P >= 0`: `M + X - 2 >= 0  =>  M + X >= 2`
    *   `Q >= 0`: `M - X >= 0  =>  M >= X`
    *   For `P` and `Q` to be integers, `M + X - 2` and `M - X` must both be even. This implies that `M + X` must be even, and `M - X` must be even. Both conditions are satisfied if and only if `M` and `X` have the same parity.
        *   This can be checked as `(M % 2 + 2) % 2 == (X % 2 + 2) % 2` (the `+2)%2` handles negative numbers correctly in C++).

Combining the `P >= 0` and `Q >= 0` conditions with the parity check, we can define the valid range for `X` for a given `M`:
*   The minimum possible value for `1 + P - Q` is when `P=0` and `Q=M-1`, which gives `1 - (M-1) = 2 - M`.
*   The maximum possible value for `1 + P - Q` is when `P=M-1` and `Q=0`, which gives `1 + (M-1) = M`.
*   So, `X` must be in the range `[2 - M, M]`.

**Algorithm:**

1.  Iterate `k` (number of `*` operators) from `0` to `N`.
2.  For each `k`:
    *   Calculate `M = N + 1 - k` (the effective number of `1`s).
    *   Check if `X` is within the valid range `[2 - M, M]`. If `X < 2 - M` or `X > M`, this `k` cannot lead to a solution; continue to the next `k`.
    *   Check if `X` and `M` have the same parity. If `(X % 2 + 2) % 2 != (M % 2 + 2) % 2`, this `k` cannot lead to a solution; continue to the next `k`.
    *   If both range and parity conditions are met, a solution exists for this `k`.
        *   Calculate `P = (M + X - 2) / 2` (number of `+` operators).
        *   Calculate `Q = (M - X) / 2` (number of `-` operators).
        *   Construct the solution string `S`: append `k` asterisks, then `P` plus signs, then `Q` minus signs. The order of `+` and `-` relative to each other doesn't matter, as long as they appear after all `*` operators.
        *   Print `S` and terminate for this test case (since any valid solution is fine).
3.  If the loop completes without finding any `k` that satisfies the conditions, no solution exists. Print `-1`.

## Complexity Analysis

*   **Time Complexity**: The algorithm iterates `k` from `0` to `N`. In each iteration, it performs constant-time arithmetic operations and potentially constructs a string of length `N`. Using `std::string::reserve` and `+=` operations, building a string of length `N` takes $O(N)$ time. In the worst case, we might iterate through all `N+1` values of `k` before finding a solution or determining none exists. Thus, the overall time complexity is $O(N)$.

*   **Space Complexity**: The primary space usage is for storing the resulting operator string `S`, which has a length of `N`. All other variables use constant space. Therefore, the space complexity is $O(N)$.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <numeric> // Not strictly needed, but often included in competitive programming

void solve() {
    int N;
    long long X; // X can be negative, using long long for safety, though int is sufficient for given constraints.
    std::cin >> N >> X;

    bool found = false;
    // Iterate through possible number of '*' operators (k)
    for (int k = 0; k <= N; ++k) {
        // M is the effective number of '1's remaining after all multiplications.
        // Each '*' operator reduces the count of '1's by one.
        long long M = (long long)N + 1 - k;

        // Check if X is within the possible range for M '1's using only '+' and '-' operators.
        // Minimum value achievable: 1 - (M-1) = 2-M (e.g., 1-1-1...-1)
        // Maximum value achievable: 1 + (M-1) = M (e.g., 1+1+1...+1)
        if (X < 2 - M || X > M) {
            continue; // X is out of range for this M
        }

        // Check parity: The sum of M terms (1 +/- 1 +/- ... +/- 1) must have the same parity as M.
        // (val % 2 + 2) % 2 is a common way to get a positive remainder for negative numbers in C++.
        if ((X % 2 + 2) % 2 != (M % 2 + 2) % 2) {
            continue; // Parity mismatch
        }

        // If both range and parity conditions are met, a solution exists for this k.
        // Calculate P (number of '+' operators) and Q (number of '-' operators).
        // We need to achieve X-1 using M-1 operators on the remaining M-1 '1's.
        // P + Q = M-1
        // P - Q = X-1
        // Solving these equations:
        long long P = (M + X - 2) / 2; // Number of '+' operators
        long long Q = (M - X) / 2;     // Number of '-' operators

        // P and Q are guaranteed to be non-negative integers by the range and parity checks.

        // Construct the string S.
        // A simple construction is to place all '*' first, then all '+'s, then all '-'s.
        // The problem allows any valid string.
        std::string S = "";
        S.reserve(N); // Pre-allocate memory for efficiency

        for (int i = 0; i < k; ++i) {
            S += '*';
        }
        for (int i = 0; i < P; ++i) {
            S += '+';
        }
        for (int i = 0; i < Q; ++i) {
            S += '-';
        }

        std::cout << S << "\n";
        found = true;
        break; // Found a solution, print it and exit the loop for this test case.
    }

    if (!found) {
        std::cout << -1 << "\n"; // No solution found after checking all possible k values.
    }
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