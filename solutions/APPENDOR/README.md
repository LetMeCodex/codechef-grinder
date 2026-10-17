# [Append for OR (APPENDOR)](https://www.codechef.com/problems/APPENDOR)
- **Difficulty Rating**: 1201
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the smallest non-negative integer `X` such that the bitwise OR of all elements in a given array `A` (of size `N`) *and* `X` equals a target value `Y`. If no such `X` exists, we should output -1.

Let `or_A` be the bitwise OR of all elements `a_i` in the input array `A`. The problem then simplifies to finding the smallest non-negative `X` such that `(or_A | X) = Y`.

## Intuition & Mathematical Observation

The core of this problem lies in understanding how the bitwise OR operation works at the individual bit level. Let's denote the $k$-th bit of a number $Z$ as $Z_k$. The equation `(or_A | X) = Y` must hold true for every bit position $k$, meaning `(or_A_k | X_k) = Y_k`.

We need to determine `X_k` for each bit position $k$ to satisfy this equation, while also ensuring `X` is the smallest non-negative integer possible.

Let's analyze the possibilities for each bit $k$:

**1. Pre-condition for a solution to exist:**

Consider the case where `Y_k = 0`. For `(or_A_k | X_k)` to be 0, both `or_A_k` and `X_k` must be 0. If `or_A_k` were 1 while `Y_k` is 0, then `(1 | X_k)` would always be 1, which contradicts `Y_k = 0`. Therefore, a fundamental requirement for a solution to exist is: **if `Y_k = 0`, then `or_A_k` must also be 0.**

This condition can be compactly checked by `(or_A | Y) == Y`.
*   If `(or_A | Y) == Y` is true, it means that for every bit `k`, if `or_A_k` is 1, then `Y_k` must also be 1. (Because if `or_A_k=1` and `Y_k=0`, then `(or_A_k | Y_k)` would be `(1 | 0) = 1`, which is not equal to `Y_k=0`).
*   If `(or_A | Y) != Y` is true, it implies there's at least one bit `k` where `or_A_k = 1` and `Y_k = 0`. In this scenario, no `X` can satisfy the equation, so we output -1.

**2. Constructing the smallest `X`:**

Assuming the pre-condition `(or_A | Y) == Y` is met, we now determine the bits of `X` to make `X` as small as possible. To minimize `X`, we want to set `X_k = 0` whenever possible.

*   **If `Y_k = 0`:**
    As established, `or_A_k` must be 0. To satisfy `(0 | X_k) = 0`, `X_k` *must* be 0.

*   **If `Y_k = 1`:**
    We need `(or_A_k | X_k) = 1`.
    *   If `or_A_k = 1`: Then `(1 | X_k)` is always 1, regardless of `X_k` being 0 or 1. To minimize `X`, we choose `X_k = 0`.
    *   If `or_A_k = 0`: Then `(0 | X_k)` must be 1. This implies `X_k` *must* be 1.

**Summary for `X_k`:**
`X_k` is 1 if and only if (`Y_k = 1` AND `or_A_k = 0`).
Otherwise, `X_k` is 0.

This logic can be compactly expressed using bitwise operations: `X = Y & (~or_A)`.
Let's verify this formula:
*   If `Y_k = 0`: `X_k = 0 & (~or_A_k)` which is `0`. (Correct, as `or_A_k` must be 0).
*   If `Y_k = 1` and `or_A_k = 1`: `X_k = 1 & (~1)` which is `1 & 0 = 0`. (Correct).
*   If `Y_k = 1` and `or_A_k = 0`: `X_k = 1 & (~0)` which is `1 & 1 = 1`. (Correct).

**Note on `~or_A`:** The bitwise NOT operator `~` in C++ operates on all bits of the integer type. However, since `Y` is less than $2^{20}$, `Y` will have 0s for all bits from position 20 upwards. Therefore, `Y & (~or_A)` effectively masks `~or_A` to the relevant bit range (0-19), ensuring `X` is non-negative and has 0s for higher bits, which is consistent with the problem constraints and the goal of finding the smallest `X`.

**Algorithm:**
1.  Initialize `or_A = 0`.
2.  Read `N` integers `a_i` and compute `or_A = or_A | a_i` for each `a_i`.
3.  Check if `(or_A | Y) == Y`.
    *   If false, print -1.
    *   If true, calculate `X = Y & (~or_A)` and print `X`.

## Complexity Analysis

*   **Time Complexity**:
    *   Calculating `or_A`: We iterate through `N` elements, performing a constant number of operations (read, bitwise OR) for each. This takes $O(N)$ time.
    *   The pre-condition check and calculation of `X` are constant time operations ($O(1)$).
    *   The `solve()` function is called `T` times.
    *   Therefore, the total time complexity is $O(T \cdot N)$. Given $N \le 2 \cdot 10^5$ and $T \le 10$, the maximum operations are around $10 \cdot 2 \cdot 10^5 = 2 \cdot 10^6$, which is efficient enough for the given time limits.

*   **Space Complexity**:
    *   We only store a few integer variables (`N`, `Y`, `or_A`, `a_i`, `X`). No data structures whose size depends on `N` are used.
    *   Thus, the space complexity is $O(1)$ (excluding input/output buffers).

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, vector, numeric, etc.
using namespace std;     // Use standard namespace

void solve() {
    int N, Y;
    cin >> N >> Y;

    int or_A = 0;
    for (int i = 0; i < N; ++i) {
        int a_i;
        cin >> a_i;
        or_A |= a_i; // Compute bitwise OR of all elements in A
    }

    // Condition 1: Every bit set in or_A must also be set in Y.
    // This is equivalent to (or_A | Y) == Y.
    // If this condition is not met, no solution exists.
    if ((or_A | Y) != Y) {
        cout << -1 << "\n";
        return;
    }

    // Condition 2: Find the minimum non-negative X such that (or_A | X) = Y.
    //
    // For each bit position k:
    // We need (or_A_k | X_k) = Y_k.
    //
    // If Y_k = 0:
    //   (or_A_k | X_k) must be 0. This implies or_A_k = 0 AND X_k = 0.
    //   (If or_A_k was 1 and Y_k was 0, Condition 1 would have failed).
    //   So, if Y_k = 0, we must set X_k = 0.
    //
    // If Y_k = 1:
    //   (or_A_k | X_k) must be 1.
    //   To minimize X, we want to set X_k = 0 if possible.
    //   - If or_A_k = 1: (1 | X_k) = 1 is true for both X_k = 0 and X_k = 1.
    //     To minimize X, we choose X_k = 0.
    //   - If or_A_k = 0: (0 | X_k) = 1 implies X_k MUST be 1.
    //
    // Summary for minimum X:
    // X_k is 1 if and only if Y_k is 1 AND or_A_k is 0.
    // This logic is compactly expressed as X = Y & (~or_A).
    // The bitwise NOT operator (~) in C++ operates on all bits of the integer type.
    // However, since Y values are less than 2^20, Y will have 0s for bits 20 and higher.
    // Therefore, Y & (~or_A) will correctly produce 0s for bits 20 and higher in X,
    // effectively masking ~or_A to the relevant bit range (0-19).
    int X = Y & (~or_A);

    cout << X << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
```