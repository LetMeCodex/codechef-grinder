# [Little Chef and Sums (CHEFSUM)](https://www.codechef.com/problems/CHEFSUM)
- **Difficulty Rating**: 1252
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find an index `p` (1-based) in a given array `A` of `N` integers such such that the sum `(A[1] + A[2] + ... + A[p]) + (A[p] + A[p+1] + ... + A[N])` is minimized. If there are multiple such indices `p` that yield the minimum sum, we should output the smallest among them.

## Intuition & Mathematical Observation

Let's analyze the sum we need to minimize:
`S_p = (A[1] + A[2] + ... + A[p]) + (A[p] + A[p+1] + ... + A[N])`

We can rewrite this sum by observing that `A[p]` is included twice.
Let `TotalSum = A[1] + A[2] + ... + A[N]`.
Then, the expression `(A[1] + A[2] + ... + A[p]) + (A[p] + A[p+1] + ... + A[N])` can be seen as:
`(A[1] + A[2] + ... + A[N]) + A[p]`

So, `S_p = TotalSum + A[p]`.

Since `TotalSum` is a constant value for a given array `A`, minimizing `S_p` is equivalent to minimizing `A[p]`.
Therefore, the problem reduces to finding the index `p` where `A[p]` is the minimum element in the array `A`.

The problem also states that if there are multiple indices `p` that result in the minimum sum (i.e., multiple occurrences of the minimum value in the array), we should output the *smallest* such `p`. This means if `A[i]` and `A[j]` are both minimum values and `i < j`, we should choose `i`.

This leads to a simple algorithm:
1. Initialize a variable `min_val` to a very large number (e.g., `numeric_limits<int>::max()`).
2. Initialize a variable `min_idx` to store the 1-based index of the minimum element found so far.
3. Iterate through the array `A` from index `i = 1` to `N`.
4. For each element `A[i]`:
   - If `A[i]` is strictly less than `min_val`, update `min_val = A[i]` and `min_idx = i`.
   - By using a *strictly less than* comparison (`<` instead of `<=`), we ensure that if we encounter an element equal to the current `min_val`, we do not update `min_idx`. This correctly preserves the smallest index among multiple occurrences of the minimum value.
5. After iterating through the entire array, `min_idx` will hold the 1-based index of the first occurrence of the minimum element. Output `min_idx`.

## Complexity Analysis

-   **Time Complexity**: $O(N)$ per test case. We iterate through the array `A` once to find the minimum element. If there are $T$ test cases, the total time complexity will be $O(T \cdot N)$.
-   **Space Complexity**: $O(1)$. We only use a few constant extra variables (`N`, `min_val`, `min_idx`, `current_A_val`) regardless of the input size `N`.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, vector, algorithm, limits, etc.
using namespace std; // Use standard namespace for brevity

void solve() {
    int N;
    cin >> N;

    // Initialize min_val with the maximum possible integer value
    // to ensure any A[i] will be smaller.
    int min_val = numeric_limits<int>::max(); 
    int min_idx = -1; // To store the 1-based index of the minimum element

    for (int i = 1; i <= N; ++i) {
        int current_A_val;
        cin >> current_A_val;

        // If the current element is strictly less than the current minimum,
        // update min_val and min_idx. This correctly finds the
        // smallest index if there are multiple occurrences of the minimum value.
        if (current_A_val < min_val) {
            min_val = current_A_val;
            min_idx = i;
        }
    }
    cout << min_idx << "\n"; // Output the 1-based index
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T;
    while (T--) { // Loop through each test case
        solve();
    }

    return 0;
}
```