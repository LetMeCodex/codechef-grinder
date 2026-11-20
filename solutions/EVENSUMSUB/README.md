Here's a clean, high-quality solution writeup in GitHub-Flavored Markdown for the Even Sum Subarray problem:

# [Even Sum Subarray (EVENSUMSUB)](https://www.codechef.com/problems/EVENSUMSUB)
- **Difficulty Rating**: 1079
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the maximum possible length of a contiguous subarray within a given array `A` such that the sum of the elements in that subarray is an even number.

## Intuition & Mathematical Observation

The core of this problem lies in understanding the properties of sums with respect to parity (even or odd).
Recall the basic rules:
*   `Even + Even = Even`
*   `Even + Odd = Odd`
*   `Odd + Odd = Even`

We want to find the longest subarray whose sum is even. Let `total_sum` be the sum of all elements in the given array `A`.

**Case 1: The `total_sum` of the entire array `A` is even.**
If the sum of all elements `A[0...N-1]` is already even, then the entire array itself is a valid subarray with an even sum. Since we are looking for the *maximum* possible length, the entire array (of length `N`) is the optimal answer.

**Case 2: The `total_sum` of the entire array `A` is odd.**
If the `total_sum` is odd, we cannot take the entire array. We must remove some elements from either the beginning (a prefix) or the end (a suffix) of the array such that the sum of the *remaining* subarray becomes even.

To change an odd sum to an even sum, we must subtract an odd sum. This means we need to remove a prefix or a suffix whose sum is odd. To maximize the length of the remaining subarray, we must remove the *shortest possible* prefix or suffix that has an odd sum.

Let's analyze the two possibilities for removal:

1.  **Removing a prefix `A[0...k]`**:
    If we remove `A[0...k]`, the remaining subarray is `A[k+1...N-1]`. Its sum will be `total_sum - sum(A[0...k])`.
    Since `total_sum` is odd, for the remaining sum to be even, `sum(A[0...k])` must also be odd (`odd - odd = even`).
    To maximize the length of `A[k+1...N-1]` (which is `N - (k+1)`), we need to minimize `k+1`, which means minimizing `k`.
    The smallest `k` for which `sum(A[0...k])` is odd occurs when `A[k]` is the *first odd number* encountered from the left. If `A[0]` is odd, then `k=0`. If `A[0]` is even, `A[1]` is even, ..., `A[k-1]` is even, and `A[k]` is odd, then `sum(A[0...k])` will be odd.
    So, we find the index `first_odd_idx` of the first odd number from the left. Removing `A[0...first_odd_idx]` leaves a subarray of length `N - (first_odd_idx + 1)`.

2.  **Removing a suffix `A[k...N-1]`**:
    If we remove `A[k...N-1]`, the remaining subarray is `A[0...k-1]`. Its sum will be `total_sum - sum(A[k...N-1])`.
    Similarly, for the remaining sum to be even, `sum(A[k...N-1])` must be odd.
    To maximize the length of `A[0...k-1]` (which is `k`), we need to maximize `k`.
    The largest `k` for which `sum(A[k...N-1])` is odd occurs when `A[k]` is the *first odd number* encountered from the right (let's call its index `last_odd_idx`). If `A[N-1]` is odd, then `k=N-1`. If `A[N-1]` is even, `A[N-2]` is even, ..., `A[k+1]` is even, and `A[k]` is odd, then `sum(A[k...N-1])` will be odd.
    So, we find the index `last_odd_idx` of the first odd number from the right. Removing `A[last_odd_idx...N-1]` leaves a subarray of length `last_odd_idx`.

Since the `total_sum` is odd, there must be at least one odd number in the array. Therefore, `first_odd_idx` and `last_odd_idx` will always be valid indices (not -1).

The maximum length in Case 2 will be the maximum of these two candidate lengths:
*   `N - (first_odd_idx + 1)`
*   `last_odd_idx`

The solution implements this logic directly.

## Complexity Analysis

*   **Time Complexity**:
    *   Reading `N` and the array `A`, and calculating `total_sum`: This involves iterating through the array once, taking $O(N)$ time.
    *   Finding `first_odd_idx`: This involves iterating from the beginning of the array, taking at most $O(N)$ time.
    *   Finding `last_odd_idx`: This involves iterating from the end of the array, taking at most $O(N)$ time.
    *   The remaining operations (comparisons, `max`, printing) are $O(1)$.
    *   Since these steps are sequential, the total time complexity for one test case is $O(N) + O(N) + O(N) = O(N)$.
    *   Given `T` test cases, the overall time complexity is $O(T \cdot N)$.
    *   With $N \le 10^5$ and $T \le 10$, the total operations are roughly $10 \cdot 10^5 = 10^6$, which is well within typical time limits.

*   **Space Complexity**:
    *   Storing the input array `A` requires $O(N)$ space.
    *   All other variables (`N`, `total_sum`, `first_odd_idx`, `last_odd_idx`, etc.) use a constant amount of space, $O(1)$.
    *   Therefore, the total space complexity is $O(N)$.
    *   With $N \le 10^5$, storing $10^5$ integers (approx. 400 KB) is well within typical memory limits (usually 256 MB).

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, vector, numeric, algorithm etc.
using namespace std; // Use standard namespace

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    long long total_sum = 0; // Use long long for sum, though int would suffice for given constraints (max sum 50*10^4 = 5*10^5, fits in int)
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total_sum += A[i];
    }

    if (total_sum % 2 == 0) {
        // If the total sum of the array is even, the entire array is the largest subarray with an even sum.
        cout << N << "\n";
    } else {
        // If the total sum is odd, we cannot take the entire array.
        // We need to remove a prefix or a suffix such that the remaining sum is even.
        // To change an odd sum to an even sum, we must remove a part whose sum is odd.
        // To maximize the length of the remaining subarray, we must remove the shortest possible prefix/suffix whose sum is odd.
        
        // Find the index of the first odd number from the left.
        // If A[L] is the first odd number from the left, then sum(A[0...L]) is odd.
        // Removing A[0...L] leaves A[L+1...N-1], whose sum is (total_sum - sum(A[0...L])) = odd - odd = even.
        // Its length is N - (L+1).
        int first_odd_idx = -1;
        for (int i = 0; i < N; ++i) {
            if (A[i] % 2 != 0) {
                first_odd_idx = i;
                break;
            }
        }

        // Find the index of the first odd number from the right.
        // If A[R] is the first odd number from the right, then sum(A[R...N-1]) is odd.
        // Removing A[R...N-1] leaves A[0...R-1], whose sum is (total_sum - sum(A[R...N-1])) = odd - odd = even.
        // Its length is R.
        int last_odd_idx = -1;
        for (int i = N - 1; i >= 0; --i) {
            if (A[i] % 2 != 0) {
                last_odd_idx = i;
                break;
            }
        }
        
        // Since total_sum is odd, there must be at least one odd number in the array.
        // Thus, first_odd_idx and last_odd_idx will always be valid indices (not -1).

        // Candidate length 1: Remove prefix up to first_odd_idx.
        // The remaining subarray starts at first_odd_idx + 1 and ends at N-1.
        // Its length is N - (first_odd_idx + 1).
        int len_after_removing_prefix = N - (first_odd_idx + 1);

        // Candidate length 2: Remove suffix from last_odd_idx.
        // The remaining subarray starts at 0 and ends at last_odd_idx - 1.
        // Its length is last_odd_idx.
        int len_after_removing_suffix = last_odd_idx;
        
        cout << max(len_after_removing_prefix, len_after_removing_suffix) << "\n";
    }
}

int main() {
    // Fast I/O
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