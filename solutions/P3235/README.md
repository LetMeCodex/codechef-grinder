# [Balanced Positions in a Permutation (P3235)](https://www.codechef.com/problems/P3235)
- **Difficulty Rating**: 930
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to count the number of "balanced positions" in a given permutation `P` of length `N`. A position `i` (0-indexed) is defined as balanced if two conditions are met:
1.  Let `L_i` be the count of elements `P[j]` such that `j < i` (to the left of `P[i]`) and `P[j] < P[i]`.
2.  Let `R_i` be the count of elements `P[k]` such that `k > i` (to the right of `P[i]`) and `P[k] > P[i]`.

A position `i` is balanced if `L_i` is equal to `R_i`. We need to output the total number of such balanced positions in the permutation.

## Intuition & Mathematical Observation

The problem statement provides a clear and direct definition for a "balanced position". For each position `i` in the permutation, we need to calculate two specific counts (`L_i` and `R_i`) and then compare them.

The most straightforward approach is to iterate through each possible position `i` from `0` to `N-1`. For each `P[i]`:
1.  **Calculate `L_i`**: We can do this by iterating through all elements `P[j]` where `j` ranges from `0` to `i-1`. If `P[j] < P[i]`, we increment a counter for `L_i`.
2.  **Calculate `R_i`**: Similarly, we iterate through all elements `P[k]` where `k` ranges from `i+1` to `N-1`. If `P[k] > P[i]`, we increment a counter for `R_i`.
3.  **Check Balance**: After calculating both `L_i` and `R_i`, we compare them. If `L_i == R_i`, then the current position `i` is balanced, and we increment our total count of balanced positions.

Since `N` is up to `1000`, an `O(N^2)` approach (N positions, and for each position, two `O(N)` scans) should be efficient enough to pass within typical time limits (1-2 seconds). There doesn't appear to be a need for more complex data structures or algorithms like segment trees or Fenwick trees for this constraint.

## Complexity Analysis

*   **Time Complexity**: $O(N^2)$
    *   The outer loop iterates `N` times (for `i` from `0` to `N-1`).
    *   Inside the outer loop, we have two inner loops:
        *   The loop to calculate `L_i` iterates `i` times. In the worst case (when `i = N-1`), this is `O(N)`.
        *   The loop to calculate `R_i` iterates `N - 1 - i` times. In the worst case (when `i = 0`), this is `O(N)`.
    *   Therefore, for each `i`, the work done is proportional to `O(N)`.
    *   Total time complexity: `N * O(N) = O(N^2)`.
    *   Given `N <= 1000`, `N^2` is `10^6`, which is well within typical time limits for competitive programming problems.

*   **Space Complexity**: $O(N)$
    *   We use a `std::vector<int> P` of size `N` to store the input permutation. This requires `O(N)` space.
    *   All other variables (`N`, `balanced_positions_count`, loop counters, `L_i`, `R_i`, `current_val`) use a constant amount of space, `O(1)`.
    *   Thus, the dominant factor is the storage of the permutation, leading to an overall space complexity of `O(N)`.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries

// It's common practice in competitive programming to use the entire std namespace
// to avoid repeatedly typing std::.
using namespace std;

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the length of the permutation
    
    // Declare a vector to store the permutation P
    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i]; // Read elements of the permutation
    }

    int balanced_positions_count = 0; // Initialize counter for balanced positions

    // Iterate through each position i from 0 to N-1
    for (int i = 0; i < N; ++i) {
        int current_val = P[i]; // The value at the current position
        
        // Calculate L_i: number of elements smaller than P_i to its left
        int L_i = 0;
        // Iterate through elements to the left of P[i] (indices 0 to i-1)
        for (int j = 0; j < i; ++j) {
            if (P[j] < current_val) {
                L_i++; // Increment if P[j] is smaller
            }
        }
        
        // Calculate R_i: number of elements greater than P_i to its right
        int R_i = 0;
        // Iterate through elements to the right of P[i] (indices i+1 to N-1)
        for (int j = i + 1; j < N; ++j) {
            if (P[j] > current_val) {
                R_i++; // Increment if P[j] is greater
            }
        }
        
        // Check if L_i equals R_i
        if (L_i == R_i) {
            balanced_positions_count++; // If equal, increment the count
        }
    }
    
    // Print the total count of balanced positions for this test case
    cout << balanced_positions_count << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```