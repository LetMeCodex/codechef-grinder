# [The One with Russ (S02E10)](https://www.codechef.com/problems/S02E10)
- **Difficulty Rating**: 1230
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to determine if there are at least `X` indices `j` such that the absolute difference between the `j`-th element of array `A` and the `j`-th element of array `B` is less than or equal to `K`. We are given the sizes of the arrays `N`, the threshold `X`, the difference limit `K`, and the elements of array `A`. The elements of array `B` are provided sequentially.

## Intuition & Mathematical Observation
The core of the problem lies in checking a condition for each pair of elements at the same index from arrays `A` and `B`. For each index `j` from `0` to `N-1`, we need to calculate `abs(A[j] - B[j])` and see if it's less than or equal to `K`.

We are interested in the *count* of such indices. If this count reaches or exceeds `X`, the answer is "YES". Otherwise, it's "NO".

The problem statement implies that we can read the elements of array `B` one by one as we iterate through the indices. This is a crucial observation for optimizing space. We don't need to store the entire array `B` in memory. We can read `A[j]` (which is already stored in a vector) and then read `B[j]` and immediately perform the comparison.

The condition `abs(A[j] - B[j]) <= K` can be rewritten as:
`-K <= A[j] - B[j] <= K`

This is equivalent to:
`A[j] - K <= B[j] <= A[j] + K`

However, directly calculating the absolute difference `abs(A[j] - B[j])` is simpler and more direct for implementation.

## Complexity Analysis
- **Time Complexity**: $O(T \cdot N)$
    - The outer loop iterates `T` times, where `T` is the number of test cases.
    - Inside each test case, we first read `N` elements into vector `A`, which takes $O(N)$ time.
    - Then, we iterate `N` times to read elements of `B` and perform the comparison. This also takes $O(N)$ time.
    - Therefore, for each test case, the time complexity is $O(N) + O(N) = O(N)$.
    - The total time complexity across all test cases is $O(T \cdot N)$.
    - Given the constraints ($T \le 10$, $N \le 1000$), the maximum operations would be around $10 \times 1000 = 10000$, which is well within typical time limits.

- **Space Complexity**: $O(N)$
    - We store the elements of array `A` in a `std::vector<int>`, which requires $O(N)$ space.
    - We do not need to store array `B` entirely. We read its elements one by one.
    - The variables `N`, `X`, `K`, `count`, and `b_val` take constant space, $O(1)$.
    - Thus, the dominant space requirement is for storing array `A`, resulting in $O(N)$ space complexity.
    - With $N \le 1000$, this is very efficient in terms of memory.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <cmath> // For abs()

using namespace std;

/**
 * Problem Analysis:
 * We need to count indices j such that |A[j] - B[j]| <= K.
 * If the count >= X, output "YES", else "NO".
 *
 * The input format allows us to read elements of B one by one
 * as we iterate through the indices, avoiding the need to store B.
 *
 * Complexity:
 * Time: O(T * N) = 10 * 1000 = 10^4 operations.
 * Space: O(N) = 1000 integers for storing array A.
 * This is highly efficient and should pass well within the time limits.
 */

void solve() {
    int N, X, K;
    // Read N, X, K for the current test case.
    if (!(cin >> N >> X >> K)) return; // Error handling for input failure

    vector<int> A(N);
    // Read all elements of array A.
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    int count = 0; // Initialize counter for valid indices.
    // Iterate through the indices to read elements of B and perform checks.
    for (int i = 0; i < N; ++i) {
        int b_val;
        cin >> b_val; // Read the j-th element of B on the fly.
        
        // Calculate absolute difference and check if it's within the limit K.
        if (abs(A[i] - b_val) <= K) {
            count++; // Increment count if the condition is met.
        }
    }

    // Check if the total count of valid indices meets the threshold X.
    if (count >= X) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Optimization for faster I/O operations.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    // Read the number of test cases.
    if (!(cin >> t)) return 0; // Error handling for input failure
    
    // Process each test case.
    while (t--) {
        solve();
    }
    
    return 0;
}
```