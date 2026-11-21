# [Final Sum (FINALSUM)](https://www.codechef.com/problems/FINALSUM)
- **Difficulty Rating**: 1145
- **Solved in**: 2 attempt(s)

## Problem Summary

The problem asks us to calculate the final sum of elements in an array `A` after a series of `Q` operations. Initially, the array `A` contains `N` integers. Each operation is defined by a range `[L, R]` (1-based indices). For every element `A[i]` within this range (`L <= i <= R`), its value is updated based on its position relative to `L`:
*   If `(i - L)` is even, `A[i]` is incremented by 1 (`A[i] = A[i] + 1`).
*   If `(i - L)` is odd, `A[i]` is decremented by 1 (`A[i] = A[i] - 1`).

After all `Q` queries are processed, we need to print the total sum of all elements in the array `A`.

## Intuition & Mathematical Observation

A naive approach of actually updating the array elements for each query would be too slow. With `N, Q` up to $10^5$, an $O(N)$ update per query would lead to an $O(N \cdot Q)$ total time complexity, which is $10^{10}$ operations in the worst case, far too slow. We need a more efficient way to determine the *change in the total sum* for each query.

Let's analyze the effect of a single query `(L, R)` on the total sum of the array. The elements `A[L], A[L+1], ..., A[R]` are affected.
The changes applied to these elements are:
*   `A[L]` changes by `+1` (since `L-L = 0`, which is even)
*   `A[L+1]` changes by `-1` (since `(L+1)-L = 1`, which is odd)
*   `A[L+2]` changes by `+1` (since `(L+2)-L = 2`, which is even)
*   `A[L+3]` changes by `-1` (since `(L+3)-L = 3`, which is odd)
*   ... and so on, alternating `+1, -1, +1, -1, ...`

We are interested in the sum of these changes for the segment `[L, R]`. Let `len = R - L + 1` be the length of the segment.

1.  **If `len` is even:**
    The sequence of changes will be `+1, -1, +1, -1, ..., +1, -1`.
    When we sum these changes, they cancel out in pairs: `(+1 -1) + (+1 -1) + ... + (+1 -1) = 0`.
    So, if the segment length `len` is even, the total sum of the array does not change.

2.  **If `len` is odd:**
    The sequence of changes will be `+1, -1, +1, -1, ..., +1, -1, +1`.
    When we sum these changes, all pairs cancel out, leaving only the final `+1`: `(+1 -1) + (+1 -1) + ... + (+1 -1) + 1 = 1`.
    So, if the segment length `len` is odd, the total sum of the array increases by `1`.

Now, we need to relate the parity of `len = R - L + 1` to the parities of `L` and `R`.
*   `len` is odd $\iff$ `R - L` is even.
*   `R - L` is even $\iff$ `R` and `L` have the same parity (e.g., `even - even = even`, `odd - odd = even`).
*   `len` is even $\iff$ `R - L` is odd.
*   `R - L` is odd $\iff$ `R` and `L` have different parities (e.g., `even - odd = odd`, `odd - even = odd`).

Therefore, the total sum of the array increases by `1` if and only if `L` and `R` have the same parity. Otherwise, the total sum remains unchanged.

This observation allows us to solve the problem efficiently:
1.  Calculate the initial sum of all elements in the array.
2.  For each query `(L, R)`:
    *   Check if `L % 2 == R % 2`.
    *   If true, increment the current total sum by `1`.
3.  After all queries, print the final total sum.

**Data Type Consideration:**
The initial array elements can be up to $10^9$, and `N` can be up to $10^5$. The initial sum can thus be up to $10^5 \times 10^9 = 10^{14}$. This requires a `long long` data type for the `current_sum`. Each query adds at most 1 to the sum, and `Q` can be up to $10^5$, so the final sum will still fit within `long long`.

## Complexity Analysis

*   **Time Complexity**:
    *   Reading `N` and `Q`: $O(1)$.
    *   Calculating the initial sum of `N` elements: $O(N)$.
    *   Processing `Q` queries: For each query, we read `L` and `R`, perform a constant number of arithmetic operations (modulo, comparison, increment). This is $O(1)$ per query. Total for `Q` queries: $O(Q)$.
    *   Overall time complexity: $O(N + Q)$. Given $N, Q \le 10^5$, this is approximately $2 \cdot 10^5$ operations, which is very efficient and well within typical time limits.

*   **Space Complexity**:
    *   We only store a few variables: `N`, `Q`, `current_sum`, `L`, `R`, and a temporary variable for reading array elements. We do not need to store the entire array `A`.
    *   Overall space complexity: $O(1)$.

## Solution Code

```cpp
#include <iostream> // For std::cin, std::cout

// No using namespace std; to be explicit.

void solve() {
    int N, Q;
    std::cin >> N >> Q;

    long long current_sum = 0; // Use long long for safety, as sum can exceed int max
    // Calculate the initial sum of the array elements
    for (int i = 0; i < N; ++i) {
        int val;
        std::cin >> val;
        current_sum += val;
    }

    // Process each query
    for (int i = 0; i < Q; ++i) {
        int L, R;
        std::cin >> L >> R;
        
        // The total sum changes by +1 if L and R have the same parity.
        // L and R are 1-based indices.
        // (L % 2) == (R % 2) correctly checks if L and R have the same parity.
        // This is equivalent to (R - L + 1) being odd, meaning the alternating sum is +1.
        if ((L % 2) == (R % 2)) {
            current_sum++;
        }
    }

    std::cout << current_sum << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}

```