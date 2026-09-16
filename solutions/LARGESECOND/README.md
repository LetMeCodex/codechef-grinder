# [Largest and Second Largest (LARGESECOND)](https://www.codechef.com/problems/LARGESECOND)
- **Difficulty Rating**: 928
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the sum of the largest and the second largest *distinct* elements in a given array of `N` integers. We are provided with `T` test cases, and for each test case, we read `N` and then `N` integers. The constraints state that `N` is between 2 and 100, and each array element `A_i` is between 1 and 1000.

## Intuition & Mathematical Observation

The core of this problem is efficiently finding the largest and second largest distinct elements. A naive approach might involve sorting the array and then picking the top two distinct elements, but sorting takes $O(N \log N)$ time. Given the constraints ($N$ up to 100), this would pass, but we can do better.

A more efficient approach is to iterate through the array once, keeping track of the largest element found so far (`max1`) and the second largest distinct element found so far (`max2`).

Here's the step-by-step logic:

1.  **Initialization**:
    *   Initialize `max1 = 0` and `max2 = 0`. Since all array elements `A_i` are guaranteed to be at least 1, `0` is a safe initial value that will be correctly overwritten by the first few elements.

2.  **Iteration**:
    *   Iterate through each element `current_val` in the input array.
    *   **Case 1: `current_val` is greater than `max1`**:
        *   This means `current_val` is the new largest element.
        *   The previous `max1` (which was the largest) now becomes the second largest. So, set `max2 = max1`.
        *   Then, set `max1 = current_val`.
    *   **Case 2: `current_val` is not greater than `max1`, but is greater than `max2` AND less than `max1`**:
        *   This means `current_val` is not the absolute largest, but it's larger than our current second largest (`max2`).
        *   The condition `current_val < max1` is crucial to ensure that `current_val` is *distinct* from `max1`. If `current_val` were equal to `max1`, we wouldn't want to update `max2` with a duplicate of `max1`.
        *   In this case, set `max2 = current_val`.
    *   **Case 3: `current_val` is less than or equal to `max2`, or equal to `max1`**:
        *   In these scenarios, `current_val` does not affect `max1` or `max2`, so we do nothing.

3.  **Result**:
    *   After iterating through all `N` elements, `max1` will hold the largest distinct element and `max2` will hold the second largest distinct element.
    *   The final answer is `max1 + max2`.

This approach ensures that we find the largest and second largest *distinct* elements in a single pass through the array.

## Complexity Analysis

*   **Time Complexity**: $O(N)$
    *   For each test case, the algorithm iterates through the `N` elements of the array exactly once.
    *   Inside the loop, a constant number of comparisons and assignments are performed.
    *   Therefore, the time complexity for processing one test case is $O(N)$.
    *   Given `T` test cases, the total time complexity is $O(T \cdot N)$. With $T=100$ and $N=100$, this is $100 \times 100 = 10^4$ operations, which is very efficient and well within typical time limits.

*   **Space Complexity**: $O(1)$
    *   The algorithm uses a fixed number of integer variables (`N`, `max1`, `max2`, `current_val`, `T`) regardless of the input array size `N`.
    *   No auxiliary data structures (like arrays or vectors) are used that scale with `N`.
    *   Thus, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries
using namespace std;     // Uses the standard namespace

// Function to solve a single test case
void solve() {
    int N;
    cin >> N;
    
    // Initialize max1 and max2. Since A_i >= 1, 0 is a safe initial value.
    // max1 will store the largest element found so far.
    // max2 will store the second largest distinct element found so far.
    int max1 = 0; 
    int max2 = 0;
    
    for (int i = 0; i < N; ++i) {
        int current_val;
        cin >> current_val;
        
        if (current_val > max1) {
            // If current_val is strictly greater than max1, it becomes the new max1.
            // The old max1 (which was the largest) becomes the new max2.
            max2 = max1;
            max1 = current_val;
        } else if (current_val > max2 && current_val < max1) {
            // If current_val is not greater than max1, but is strictly greater than max2,
            // and also strictly less than max1 (to ensure distinctness from max1),
            // then it becomes the new max2.
            max2 = current_val;
        }
        // If current_val is equal to max1, or less than or equal to max2,
        // it does not affect max1 or max2.
    }
    
    cout << max1 + max2 << "\n";
}

int main() {
    // Fast I/O setup to speed up cin/cout operations.
    // This is crucial for competitive programming problems with large inputs.
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