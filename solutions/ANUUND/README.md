This writeup provides a clean, high-quality solution for the CodeChef problem "Ups and Downs (ANUUND)" in GitHub-Flavored Markdown.

---

# [Ups and Downs (ANUUND)](https://www.codechef.com/problems/ANUUND)
- **Difficulty Rating**: 1198
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to rearrange a given array `A` of `N` integers such that it follows a specific "zig-zag" pattern. The pattern requires that:
1. For all even indices `i`, `A[i] <= A[i+1]`.
2. For all odd indices `i`, `A[i] >= A[i+1]`.

This means the desired arrangement should look like: `A[0] <= A[1] >= A[2] <= A[3] >= A[4] ...` and so on. We need to output any such valid rearrangement.

## Intuition & Mathematical Observation

The core idea is to iterate through the array and enforce the required condition for each adjacent pair `(A[i], A[i+1])` locally.

The target pattern can be broken down into two simple rules:
*   If `i` is an even index, we need `A[i] <= A[i+1]`.
*   If `i` is an odd index, we need `A[i] >= A[i+1]`.

We can iterate from `i = 0` up to `N-2` (since we are always considering `A[i]` and `A[i+1]`). For each `i`:
1.  If `i` is even: Check if `A[i] > A[i+1]`. If it is, swap `A[i]` and `A[i+1]` to satisfy `A[i] <= A[i+1]`.
2.  If `i` is odd: Check if `A[i] < A[i+1]`. If it is, swap `A[i]` and `A[i+1]` to satisfy `A[i] >= A[i+1]`.

This greedy approach works because each swap only affects the current pair `(A[i], A[i+1])` and potentially the *next* pair `(A[i+1], A[i+2])`. Crucially, it does *not* invalidate any conditions that were already satisfied for previous pairs `(A[j], A[j+1])` where `j < i`. When we fix `(A[i], A[i+1])`, the elements `A[0]` through `A[i-1]` remain untouched, preserving their relationships. The element `A[i+1]` (after potential swap) will then be correctly considered when the loop proceeds to `i+1`. By processing the array from left to right, we ensure that all conditions are met by the end of the single pass.

Consider an example: `A = [3, 1, 4, 2]`
*   `i = 0` (even): We need `A[0] <= A[1]`. Current `A[0]=3, A[1]=1`. Since `3 > 1`, we swap them. Array becomes `[1, 3, 4, 2]`.
*   `i = 1` (odd): We need `A[1] >= A[2]`. Current `A[1]=3, A[2]=4`. Since `3 < 4`, we swap them. Array becomes `[1, 4, 3, 2]`.
*   `i = 2` (even): We need `A[2] <= A[3]`. Current `A[2]=3, A[3]=2`. Since `3 > 2`, we swap them. Array becomes `[1, 4, 2, 3]`.

The loop finishes. The final array `[1, 4, 2, 3]` satisfies the conditions: `1 <= 4`, `4 >= 2`, `2 <= 3`.

This simple greedy strategy is sufficient because the problem asks for *any* valid rearrangement, not necessarily the lexicographically smallest or largest.

## Complexity Analysis

*   **Time Complexity**: $O(N)$
    *   Reading `N` integers into the vector takes $O(N)$ time.
    *   The main loop iterates `N-1` times. Inside the loop, checking conditions and performing a `swap` operation (if needed) both take $O(1)$ time. Thus, this loop contributes $O(N)$ to the total time.
    *   Printing the `N` elements of the modified array takes $O(N)$ time.
    *   Overall, for each test case, the time complexity is dominated by operations proportional to `N`, resulting in $O(N)$.
    *   Given `T` test cases, the total time complexity is $O(T \cdot N)$.

*   **Space Complexity**: $O(N)$
    *   We use a `std::vector<int> A` to store the `N` input integers, which requires $O(N)$ space.
    *   All other variables (like `N`, `i`, `T`) use a constant amount of space, $O(1)$.
    *   Therefore, the total space complexity is $O(N)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, vector, algorithm, etc.

using namespace std; // Use standard namespace

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Iterate through the array up to N-2 to check pairs (A[i], A[i+1])
    // The loop condition N-1 ensures we always access A[i] and A[i+1] safely.
    // For N=1, the loop (i < N-1) will not execute, which is correct as there are no pairs to check.
    for (int i = 0; i < N - 1; ++i) {
        if (i % 2 == 0) { // Even index: A[i] <= A[i+1]
            if (A[i] > A[i+1]) {
                swap(A[i], A[i+1]);
            }
        } else { // Odd index: A[i] >= A[i+1]
            if (A[i] < A[i+1]) {
                swap(A[i], A[i+1]);
            }
        }
    }

    // Output the rearranged array
    for (int i = 0; i < N; ++i) {
        cout << A[i] << (i == N - 1 ? "" : " "); // Print space between numbers, no space after last
    }
    cout << "\n"; // Newline after each test case output
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve();
    }

    return 0;
}
```