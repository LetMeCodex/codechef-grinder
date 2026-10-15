# [Imperfect Numbers (NO25PLS)](https://www.codechef.com/problems/NO25PLS)
- **Difficulty Rating**: 697
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem defines a "positive integer `M`" as **imperfect** if it is divisible by 2 or 5, but not both.
Given a positive integer `N`, we need to find the minimum non-negative integer `K` such that either `N-K` or `N+K` is an imperfect number.

## Intuition & Mathematical Observation

Let's first understand the definition of an "imperfect number" more deeply.
A positive integer `M` is imperfect if:
1. `M % 2 == 0` AND `M % 5 != 0` (divisible by 2, not 5)
   Examples: 2, 4, 6, 8, 12, 14, 16, 18, ...
2. `M % 2 != 0` AND `M % 5 == 0` (divisible by 5, not 2)
   Examples: 5, 15, 25, 35, ...

This condition is equivalent to `(M % 2 == 0) XOR (M % 5 == 0)`.

Now, let's consider numbers that are *not* imperfect:
1. `M % 2 != 0` AND `M % 5 != 0` (not divisible by 2 and not by 5)
   These are numbers whose last digit is 1, 3, 7, 9.
   Examples: 1, 3, 7, 9, 11, 13, 17, 19, ...
2. `M % 2 == 0` AND `M % 5 == 0` (divisible by both 2 and 5)
   These are numbers divisible by 10, i.e., whose last digit is 0.
   Examples: 10, 20, 30, 40, ...

So, a positive integer `M` is imperfect if its last digit is 2, 4, 5, 6, or 8.
A positive integer `M` is *not* imperfect if its last digit is 0, 1, 3, 7, or 9.

We are looking for the minimum non-negative `K` such that `N-K` or `N+K` is imperfect. We can check values of `K` in increasing order:

1.  **Case K = 0**:
    Check if `N` itself is an imperfect number.
    If `N % 10` is 2, 4, 5, 6, or 8, then `N` is imperfect. The minimum `K` is 0.
    Example: `N=6` (imperfect), `K=0`. `N=15` (imperfect), `K=0`.

2.  **Case K = 1**:
    If `N` is not imperfect, we check `N-1` and `N+1`.
    `N` is not imperfect if its last digit is 0, 1, 3, 7, or 9.
    Let's analyze these possibilities for `N % 10`:
    *   If `N % 10 == 1`:
        `N-1` ends in 0 (e.g., 10, 20) - Not imperfect.
        `N+1` ends in 2 (e.g., 12, 22) - **Imperfect!**
        So, if `N % 10 == 1`, `K=1` is the answer (via `N+1`).
    *   If `N % 10 == 3`:
        `N-1` ends in 2 (e.g., 12, 22) - **Imperfect!**
        `N+1` ends in 4 (e.g., 14, 24) - **Imperfect!**
        So, if `N % 10 == 3`, `K=1` is the answer (via `N-1` or `N+1`).
    *   If `N % 10 == 7`:
        `N-1` ends in 6 (e.g., 16, 26) - **Imperfect!**
        `N+1` ends in 8 (e.g., 18, 28) - **Imperfect!**
        So, if `N % 10 == 7`, `K=1` is the answer (via `N-1` or `N+1`).
    *   If `N % 10 == 9`:
        `N-1` ends in 8 (e.g., 18, 28) - **Imperfect!**
        `N+1` ends in 0 (e.g., 10, 20) - Not imperfect.
        So, if `N % 10 == 9`, `K=1` is the answer (via `N-1`).

    In summary, if `N` is not imperfect and its last digit is 1, 3, 7, or 9, then `K=1` is the answer.

3.  **Case K = 2**:
    The only remaining scenario is when `N` is not imperfect, and `N % 10` is not 1, 3, 7, or 9. This implies `N % 10 == 0`.
    If `N % 10 == 0`:
    *   `N` ends in 0 (e.g., 10, 20) - Not imperfect.
    *   `N-1` ends in 9 (e.g., 9, 19) - Not imperfect.
    *   `N+1` ends in 1 (e.g., 11, 21) - Not imperfect.
    In this specific case, we check `K=2`:
    *   `N-2` ends in 8 (e.g., 8, 18) - **Imperfect!**
    *   `N+2` ends in 2 (e.g., 12, 22) - **Imperfect!**
    So, if `N % 10 == 0`, then `K=2` is the answer.
    Example: `N=10`. `N-2=8` (imperfect), `N+2=12` (imperfect). Minimum `K=2`.

**Consolidated Logic:**
1. If `N` is imperfect (last digit 2, 4, 5, 6, 8), output `0`.
2. Else if `N % 10` is 1, 3, 7, or 9, output `1`.
3. Else (`N % 10` must be 0), output `2`.

The provided solution code implements this exact logic by first checking `K=0`, then `K=1`, and if neither yields an imperfect number, it defaults to `K=2`. The `is_imperfect` function correctly handles `N-K` potentially being non-positive (e.g., `N=1, K=1 \implies N-K=0`) by returning `false` for `num <= 0`, as imperfect numbers must be positive.

## Complexity Analysis

*   **Time Complexity**: The `is_imperfect` function performs a few constant-time arithmetic operations (modulo, comparison). The `solve` function calls `is_imperfect` at most 3 times. Input/output operations for integers are also constant time. Since there are `T` test cases, the total time complexity is $O(T)$. Given $T \le 1000$, this is extremely efficient.

*   **Space Complexity**: The solution uses a few integer variables to store `N`, `T`, and boolean flags. No data structures that scale with the input size `N` are used. Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, cmath, etc.

// Using the standard namespace as requested by the problem statement.
using namespace std;

// Function to check if a number is imperfect
// A positive integer M is imperfect if it's divisible by either 2 or 5, but not both.
bool is_imperfect(int num) {
    // Imperfect numbers must be positive.
    if (num <= 0) {
        return false;
    }

    bool div_by_2 = (num % 2 == 0);
    bool div_by_5 = (num % 5 == 0);

    // An imperfect number satisfies (div_by_2 OR div_by_5) AND NOT (div_by_2 AND div_by_5).
    // This is equivalent to (div_by_2 XOR div_by_5).
    return div_by_2 != div_by_5;
}

void solve() {
    int N;
    cin >> N; // Read N using cin

    // Case 0: N itself is an imperfect number.
    if (is_imperfect(N)) {
        cout << 0 << "\n"; // Output 0
    } else {
        // Case 1: Check if N-1 or N+1 is an imperfect number.
        // The is_imperfect function correctly handles N-1 being 0 (e.g., for N=1).
        bool found_at_diff_1 = false;
        if (is_imperfect(N - 1)) {
            found_at_diff_1 = true;
        }
        if (is_imperfect(N + 1)) {
            found_at_diff_1 = true;
        }

        if (found_at_diff_1) {
            cout << 1 << "\n"; // Output 1
        } else {
            // Case 2: If N, N-1, N+1 are not imperfect, the minimum difference must be 2.
            // As analyzed, this scenario only occurs when N is a multiple of 10.
            // For such N, N-2 and N+2 are always imperfect.
            cout << 2 << "\n"; // Output 2
        }
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T;
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}
```