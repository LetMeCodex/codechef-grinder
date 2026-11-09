# [Maximum Sum (MAXSUM77)](https://www.codechef.com/problems/MAXSUM77)
- **Difficulty Rating**: 990
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the maximum possible sum of elements in an array `A` after removing exactly `K` elements. The crucial constraint is that the remaining elements must form a *contiguous subarray*. All elements `A_i` are positive integers (greater than or equal to 1).

## Intuition & Mathematical Observation

1.  **Contiguous Subarray Constraint**: The core of the problem lies in the requirement that the remaining elements must form a contiguous subarray. This implies that we cannot remove elements from the middle of the array. If we remove an element `A[j]` where `A[j-1]` and `A[j+1]` remain, then `A[j-1]` and `A[j+1]` are no longer contiguous. Therefore, all `K` removed elements must be taken from either the beginning of the array, the end of the array, or a combination of both.

2.  **Strategy for Removal**: Let's say we remove `i` elements from the beginning of the array. Since we need to remove a total of `K` elements, we must then remove `K - i` elements from the end of the array.
    *   The number of elements removed from the beginning, `i`, can range from `0` (remove all `K` elements from the end) to `K` (remove all `K` elements from the beginning).
    *   For each possible value of `i` (from `0` to `K`), we can determine the contiguous subarray that remains.

3.  **Identifying the Remaining Subarray**:
    *   If `i` elements are removed from the beginning, the first remaining element is `A[i]`.
    *   If `K - i` elements are removed from the end, and the original array has `N` elements (indexed `0` to `N-1`), then the last `K-i` elements are `A[N - (K-i)]` through `A[N-1]`. Thus, the last *remaining* element is `A[N - (K-i) - 1]`.
    *   So, for a given `i`, the remaining contiguous subarray is `A[i], A[i+1], ..., A[N - (K-i) - 1]`.

4.  **Efficient Sum Calculation**: To find the sum of elements in a contiguous subarray `A[L...R]` efficiently, we can use **prefix sums**.
    *   Let `pref[j]` be the sum of the first `j` elements of `A` (i.e., `A[0] + ... + A[j-1]`). We define `pref[0] = 0`.
    *   Then, the sum of `A[L...R]` is `pref[R+1] - pref[L]`.
    *   In our case, `L = i` and `R = N - (K-i) - 1`.
    *   The sum of the remaining subarray is `pref[(N - (K-i) - 1) + 1] - pref[i]`, which simplifies to `pref[N - (K-i)] - pref[i]`.

5.  **Finding the Maximum**: We iterate `i` from `0` to `K`, calculate the sum for each configuration using prefix sums, and keep track of the maximum sum found. Since all `A_i \ge 1`, all sums will be positive, so initializing `max_sum = 0` is safe.

6.  **Data Type Consideration**: The problem constraints state `N` up to `10^5` and `A_i` up to `10^9`. The sum of `N` such elements can be up to `10^5 * 10^9 = 10^{14}`, which exceeds the capacity of a 32-bit integer (`int`). Therefore, `long long` must be used for prefix sums and the `max_sum` variable.

## Complexity Analysis

*   **Time Complexity**:
    *   Reading the input array `A`: $O(N)$
    *   Calculating the prefix sums array `pref`: $O(N)$
    *   Iterating through all possible `i` values (from `0` to `K`): This loop runs `K+1` times. Inside the loop, calculating `current_sum` using prefix sums and updating `max_sum` takes $O(1)$ time. So, this part is $O(K)$.
    *   Total time complexity for one test case: $O(N) + O(N) + O(K) = O(N+K)$. Since $K \le N$, this simplifies to $O(N)$.
    *   For `T` test cases, the total time complexity is $O(T \cdot N)$. Given `T` up to `10` and `N` up to `10^5`, this is approximately $10 \cdot 10^5 = 10^6$ operations, which is well within typical time limits.

*   **Space Complexity**:
    *   Storing the input array `A`: $O(N)$
    *   Storing the prefix sums array `pref`: $O(N)$
    *   Total space complexity: $O(N)$. Given `N` up to `10^5`, this is approximately $10^5 \cdot 4$ bytes (for `int`) or $10^5 \cdot 8$ bytes (for `long long`), which is well within typical memory limits.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, vector, algorithm, numeric etc.

// It's common in competitive programming to use `using namespace std;`
// for brevity, though in larger projects, explicit `std::` prefix is preferred.
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Calculate prefix sums.
    // pref[j] will store the sum of elements A[0]...A[j-1].
    // pref[0] = 0 (sum of an empty prefix).
    // This allows calculating sum of A[L...R] as pref[R+1] - pref[L].
    vector<long long> pref(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        pref[i + 1] = pref[i] + A[i];
    }

    long long max_sum = 0; // Initialize with 0, as A_i >= 1, sums will be positive.

    // We need to remove K elements in total.
    // Let 'i' be the number of elements removed from the beginning.
    // Then, 'K - i' elements must be removed from the end.
    // 'i' can range from 0 (remove all K from end) to K (remove all K from beginning).
    for (int i = 0; i <= K; ++i) {
        // 'start_idx' is the 0-indexed position of the first remaining element.
        // If 'i' elements are removed from the beginning, the first remaining element is A[i].
        int start_idx = i;
        
        // 'end_idx' is the 0-indexed position of the last remaining element.
        // If 'K - i' elements are removed from the end,
        // the original array has N elements (0 to N-1).
        // The last (K-i) elements are A[N-(K-i)], ..., A[N-1].
        // So, the last remaining element is A[N - (K - i) - 1].
        int end_idx = N - (K - i) - 1;

        // The sum of elements from A[start_idx] to A[end_idx] (inclusive)
        // using prefix sums is pref[end_idx + 1] - pref[start_idx].
        long long current_sum = pref[end_idx + 1] - pref[start_idx];
        
        // Update the maximum sum found so far.
        max_sum = max(max_sum, current_sum);
    }

    cout << max_sum << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T;
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}
```