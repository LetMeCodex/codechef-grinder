# [Change One (CHANGEONE7)](https://www.codechef.com/problems/CHANGEONE7)
- **Difficulty Rating**: 738
- **Solved in**: 1 attempt(s)

## Problem Summary

You are given an array `A` of `N` integers. Your task is to change *exactly one* element of this array to *any* integer value. After making this change, you need to find the minimum possible value of `max(A) - min(A)`, where `max(A)` is the maximum element and `min(A)` is the minimum element of the modified array.

## Intuition & Mathematical Observation

Let the given array be `A`. We want to minimize the range `max(A') - min(A')` after changing one element.

1.  **Sorting is Key**: To easily identify the minimum and maximum elements, and their neighbors, it's always beneficial to sort the array first. Let's sort the array `A` in non-decreasing order. After sorting, `A[0]` is the smallest element, `A[1]` is the second smallest, `A[N-2]` is the second largest, and `A[N-1]` is the largest.

2.  **Which element to change?**
    Consider the effect of changing an element `A[k]`:
    *   If we change an element `A[k]` where `0 < k < N-1` (i.e., an element that is neither the smallest nor the largest), and we change it to a value within the range `[A[0], A[N-1]]`, then `A[0]` will still be the minimum and `A[N-1]` will still be the maximum. The difference would remain `A[N-1] - A[0]`. This is generally not optimal, as we want to *reduce* the range.
    *   To reduce the `max - min` difference, we must eliminate either the original minimum or the original maximum from being the extreme value. This means we should either change `A[0]` or `A[N-1]`.

3.  **Case 1: Change the smallest element `A[0]`**
    *   If we change `A[0]`, the new minimum element in the array will become `A[1]` (the second smallest original element).
    *   The maximum element will still be `A[N-1]` (the largest original element).
    *   To minimize the `max - min` difference, we should change `A[0]` to a value that falls within the range `[A[1], A[N-1]]`. For example, we could change `A[0]` to `A[1]`.
    *   The resulting `max - min` difference would be `A[N-1] - A[1]`.

4.  **Case 2: Change the largest element `A[N-1]`**
    *   If we change `A[N-1]`, the new maximum element in the array will become `A[N-2]` (the second largest original element).
    *   The minimum element will still be `A[0]` (the smallest original element).
    *   To minimize the `max - min` difference, we should change `A[N-1]` to a value that falls within the range `[A[0], A[N-2]]`. For example, we could change `A[N-1]` to `A[N-2]`.
    *   The resulting `max - min` difference would be `A[N-2] - A[0]`.

5.  **Final Answer**: The minimum possible `max - min` difference will be the smaller of the two possibilities derived above.
    Therefore, the answer is `min(A[N-1] - A[1], A[N-2] - A[0])`.

This logic holds for `N >= 2`. The problem constraints state `N >= 2`, so we don't need to worry about `N=1` edge cases.

## Complexity Analysis

-   **Time Complexity**:
    *   Reading `N` and `N` elements: $O(N)$
    *   Sorting the array `A`: $O(N \log N)$
    *   Calculating the two differences and finding their minimum: $O(1)$
    *   Since there are `T` test cases, the total time complexity is $O(T \cdot N \log N)$.

-   **Space Complexity**:
    *   Storing the array `A`: $O(N)$
    *   Other variables: $O(1)$
    *   The total space complexity is $O(N)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries
using namespace std; // Uses the standard namespace

void solve() {
    int N;
    cin >> N; // Read N

    vector<int> A(N); // Declare a vector of N integers
    for (int i = 0; i < N; ++i) {
        cin >> A[i]; // Read elements into the vector
    }

    sort(A.begin(), A.end()); // Sort the array in non-decreasing order

    // After sorting, A[0] is the smallest, A[N-1] is the largest.
    // A[1] is the second smallest, A[N-2] is the second largest.

    // Case 1: We choose to change the smallest element (A[0]).
    // The remaining N-1 elements are A[1], A[2], ..., A[N-1].
    // The minimum among these is A[1], and the maximum is A[N-1].
    // To minimize max-min, we change A[0] to be any value within [A[1], A[N-1]].
    // The resulting max-min difference will be A[N-1] - A[1].
    int diff1 = A[N-1] - A[1];

    // Case 2: We choose to change the largest element (A[N-1]).
    // The remaining N-1 elements are A[0], A[1], ..., A[N-2].
    // The minimum among these is A[0], and the maximum is A[N-2].
    // To minimize max-min, we change A[N-1] to be any value within [A[0], A[N-2]].
    // The resulting max-min difference will be A[N-2] - A[0];
    int diff2 = A[N-2] - A[0];

    // The overall minimum possible value of max(A) - min(A)
    // is the smaller of these two possibilities.
    // (Changing any other element A[k] where 0 < k < N-1 would result in a difference
    // of A[N-1] - A[0], which is always greater than or equal to diff1 and diff2).
    cout << min(diff1, diff2) << "\n";
}

int main() {
    // Fast I/O to speed up input and output operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}
```