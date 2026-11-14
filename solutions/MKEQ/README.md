# [Make Equal (MKEQ)](https://www.codechef.com/problems/MKEQ)
- **Difficulty Rating**: 1373
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks whether it's possible to make all elements of an array `A` of length `N` equal by repeatedly applying a specific operation. The operation allows choosing an index `i` such that `1 < i < N` (using 1-based indexing for the problem statement, which translates to `0 < i < N-1` in 0-based indexing) and replacing `A[i]` with `min(A[i-1], A[i+1])`.

## Intuition & Mathematical Observation

The core of this problem lies in understanding the constraints and effects of the given operation: `A[i] = min(A[i-1], A[i+1])` for `0 < i < N-1`.

1.  **Fixed Elements**: The most crucial observation is the range of `i`. The operation can only be applied to elements `A[1]` through `A[N-2]` (0-indexed). This means the first element `A[0]` and the last element `A[N-1]` can *never* be changed. They are fixed throughout the entire process.

2.  **Monotonicity of Operation**: The operation `A[i] = min(A[i-1], A[i+1])` can only ever decrease the value of `A[i]` or keep it the same. It can never increase `A[i]`. This implies that if all elements are to become equal to some value `X`, then `X` must be less than or equal to *all* initial elements of the array. Therefore, the target value `X` must be the minimum value present in the *initial* array. Let's call this `min_val`.

3.  **Necessary Condition**: Combining the above two points:
    *   `A[0]` and `A[N-1]` are fixed.
    *   All elements must eventually become `min_val` (the overall minimum of the initial array).
    *   For this to be possible, it is absolutely necessary that `A[0]` must already be equal to `min_val`, AND `A[N-1]` must already be equal to `min_val`. If either of these fixed elements is greater than `min_val`, it's impossible to make them equal to `min_val`, and thus impossible to make all elements equal to `min_val`.

4.  **Sufficient Condition**: Is this condition also sufficient? If `A[0] == min_val` and `A[N-1] == min_val`, can we always make all other elements `min_val`?
    Yes. Consider any element `A[i]` where `0 < i < N-1`. If `A[i]` is already `min_val`, we don't need to do anything. If `A[i]` is greater than `min_val`, we can apply the operation `A[i] = min(A[i-1], A[i+1])`. Since `A[0]` and `A[N-1]` are `min_val`, this `min_val` will "propagate" inwards from both ends. For example, `A[1]` can become `min(A[0], A[2])`. Since `A[0]` is `min_val`, `A[1]` can become `min_val` (if `A[2]` is also `min_val` or greater). Similarly, `A[N-2]` can become `min(A[N-3], A[N-1])`, and since `A[N-1]` is `min_val`, `A[N-2]` can become `min_val`. By repeatedly applying the operation, the `min_val` will spread from both ends, eventually reducing all intermediate elements to `min_val`.

5.  **Edge Case N=1**: If `N=1`, the array already has all elements equal (just one element). The operation `0 < i < N-1` is impossible to apply. So, for `N=1`, the answer is always "Yes".

Therefore, the strategy is:
1.  Handle `N=1` as a special case: print "Yes".
2.  For `N > 1`, find the minimum value (`min_val`) in the entire array.
3.  Check if `A[0]` and `A[N-1]` are both equal to `min_val`. If they are, print "Yes"; otherwise, print "No".

## Complexity Analysis

-   **Time Complexity**: $O(N)$
    *   Reading `N`: $O(1)$
    *   Handling `N=1` edge case: $O(1)$
    *   Reading `first_val`: $O(1)$
    *   Loop to read `N-2` intermediate elements and update `min_val`: $O(N)$ operations.
    *   Reading `last_val` and final `min_val` update: $O(1)$
    *   Final comparison and print: $O(1)$
    *   Since there are `T` test cases, the total time complexity is $O(T \cdot N)$.

-   **Space Complexity**: $O(1)$
    *   The solution only stores a few integer variables (`n`, `first_val`, `min_val`, `current_val`, `last_val`). The input array itself is not stored. This requires constant extra space.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, algorithm, etc.

// Use the standard namespace to avoid prefixing std::
using namespace std;

// Function to solve a single test case
void solve() {
    int n;
    cin >> n; // Read the length of the array
    
    // Edge case: If N is 1, the array already has all elements equal.
    // The operation 1 < i < N (0 < i < N-1) cannot be applied.
    if (n == 1) {
        int val;
        cin >> val; // Read the single element (and discard, as it doesn't affect the answer)
        cout << "Yes\n";
        return; // Move to the next test case
    }
    
    // For N > 1, the first and last elements (A_1 and A_N in 1-based indexing,
    // or A[0] and A[N-1] in 0-based indexing) cannot be changed
    // because the operation requires 0 < i < N-1.
    // All elements must eventually become equal to the minimum value in the initial array.
    // If A[0] or A[N-1] is not equal to this minimum value, it's impossible.
    
    int first_val;
    cin >> first_val; // Read A[0]
    
    int min_val = first_val; // Initialize minimum value found so far
    
    // Read elements from A[1] to A[N-2] (inclusive, 0-indexed)
    // and update min_val.
    // This loop runs N-2 times. If N=2, this loop does not run (i=1 to 0).
    for (int i = 1; i < n - 1; ++i) {
        int current_val;
        cin >> current_val;
        min_val = min(min_val, current_val);
    }
    
    int last_val;
    cin >> last_val; // Read A[N-1]
    min_val = min(min_val, last_val); // Update min_val with the last element
    
    // Check if the first and last elements are equal to the overall minimum.
    if (first_val == min_val && last_val == min_val) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is crucial for competitive programming problems with large I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }
    
    return 0; // Indicate successful execution
}
```