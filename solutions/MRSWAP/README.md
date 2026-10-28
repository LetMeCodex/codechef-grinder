# [Mirror Swap (MRSWAP)](https://www.codechef.com/problems/MRSWAP)
- **Difficulty Rating**: 667
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to consider an array `A` of `2*N` integers. We need to divide this array into two new arrays, `H1` (first half) and `H2` (second half), each of size `N`. The crucial constraint is that for each index `i` (0-indexed) from `0` to `N-1`, the element `H1[i]` and the element `H2[i]` must come from a *mirror pair* in the original array `A`. A mirror pair is defined as `(A[j], A[2*N - 1 - j])` for some `j`. Our goal is to maximize the sum of elements in the first half (`H1`).

Essentially, we need to assign each of the `N` mirror pairs from the original array to one of the `N` positions in the new halves. For each assigned mirror pair `(X, Y)` at a specific position `i`, we must decide whether `H1[i] = X, H2[i] = Y` or `H1[i] = Y, H2[i] = X`. We want to make these choices to maximize the sum of `H1`.

## Intuition & Mathematical Observation

Let the original array be `A` of size `2*N`. The distinct mirror pairs in `A` are formed by `(A[k], A[2*N - 1 - k])` for `k` ranging from `0` to `N-1`. There are exactly `N` such distinct mirror pairs.

The problem states that for each index `i` (from `0` to `N-1`), the pair `(H1[i], H2[i])` must be one of these `N` mirror pairs. Since there are `N` positions `i` in the new halves and `N` distinct mirror pairs in the original array, it implies that each of the `N` original mirror pairs `(A[k], A[2*N - 1 - k])` must be used exactly once to form the `N` pairs `(H1[i], H2[i])`. The specific mapping of which original mirror pair goes to which index `i` in the new halves does not affect the total sum, only the sum of `H1` and `H2` combined.

To maximize the sum of `H1`, we can consider each mirror pair `(A[k], A[2*N - 1 - k])` independently. For each such pair, we have two choices for its contribution to `H1` and `H2`:
1.  Put `A[k]` into `H1` and `A[2*N - 1 - k]` into `H2`.
2.  Put `A[2*N - 1 - k]` into `H1` and `A[k]` into `H2`.

To maximize the sum of `H1`, for each mirror pair `(A[k], A[2*N - 1 - k])`, we should always choose the larger of the two values to be placed in `H1`. The smaller value will then automatically go into `H2`.

Therefore, the maximum sum of the first half `H1` will be the sum of `max(A[k], A[2*N - 1 - k])` for all `k` from `0` to `N-1`.

The solution iterates `i` from `0` to `N-1`, and for each `i`, it adds `max(a[i], a[2*N - 1 - i])` to a running total. This correctly implements the described strategy.

## Complexity Analysis

-   **Time Complexity**:
    -   Reading `N`: $O(1)$
    -   Reading `2*N` elements into the vector `a`: $O(N)$
    -   The loop `for (int i = 0; i < n; ++i)` runs `N` times. Inside the loop, `max()` and addition operations are $O(1)$.
    -   Total time for one test case: $O(N)$.
    -   Since there are `T` test cases, the overall time complexity is $O(T \cdot N)$.

-   **Space Complexity**:
    -   The `vector<int> a(2 * n)` stores `2*N` integers. This requires $O(N)$ space.
    -   Other variables (`n`, `max_first_half_sum`, loop counter `i`) use $O(1)$ space.
    -   Therefore, the total space complexity is $O(N)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, vector, algorithm, etc.

using namespace std; // Using namespace std as requested

void solve() {
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> a[i];
    }

    long long max_first_half_sum = 0;
    // Iterate through the first N elements (0-indexed: from 0 to N-1)
    for (int i = 0; i < n; ++i) {
        // For each element a[i] in the first half, its mirror element is a[2*n - 1 - i].
        // To maximize the sum of the first half, we choose the larger of these two values
        // to be at position i.
        max_first_half_sum += max(a[i], a[2 * n - 1 - i]);
    }

    cout << max_first_half_sum << "\n";
}

int main() {
    // Fast I/O as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
```