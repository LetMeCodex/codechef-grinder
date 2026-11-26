# [Starved for Seating (STRSEAT)](https://www.codechef.com/problems/STRSEAT)
- **Difficulty Rating**: 983
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the number of unique pairs of teams whose match would attract more fans than a given stadium capacity `K`. We are provided with `N` teams, and for each team `i`, its individual fan count `A[i]`. The number of fans attending a match between any two distinct teams `i` and `j` is defined by a specific formula: `(sum of A[k]/2 for all k from 0 to N-1) + (A[i]/2) + (A[j]/2)`. Our task is to count how many such matches would result in a fan count strictly greater than `K`.

## Intuition & Mathematical Observation

The key to solving this problem efficiently lies in carefully analyzing the given formula for calculating the number of fans for a match between team `i` and team `j`:

`Fans(i, j) = (sum of A[k]/2 for all k) + (A[i]/2) + (A[j]/2)`

Let's break down this formula:
1.  The term `(sum of A[k]/2 for all k)` represents the sum of half the fan counts of *all* `N` teams. Let's call this `S_total_half`.
    `S_total_half = A[0]/2 + A[1]/2 + ... + A[N-1]/2`.
2.  Notice that `S_total_half` is a constant value, independent of which specific pair of teams `(i, j)` is playing. It's the same for every possible match.

With this observation, the formula simplifies significantly:
`Fans(i, j) = S_total_half + A[i]/2 + A[j]/2`

This leads to a straightforward approach:
1.  **Pre-calculate `S_total_half`**: Iterate through all `N` teams once, divide each `A[k]` by 2, and accumulate their sum. This takes $O(N)$ time.
2.  **Iterate through all unique pairs `(i, j)`**: Since the order of teams in a match doesn't matter (team `i` vs `j` is the same as `j` vs `i`), we only need to consider pairs where `i < j`. For each such pair:
    *   Calculate `current_match_fans = S_total_half + A[i]/2 + A[j]/2`. This is an $O(1)$ operation.
    *   Compare `current_match_fans` with `K`. If `current_match_fans > K`, increment a counter.

The constraints `N <= 100` and `A[i] <= 100` are quite small:
*   `S_total_half` will be at most `100 * (100/2) = 5000`.
*   `current_match_fans` will be at most `5000 + (100/2) + (100/2) = 5100`.
*   `K` can be up to `10000`.
All these values fit comfortably within a standard `int` data type. Using `long long` for sums (like `sum_A_half` and `current_match_fans`) as in the provided solution is a safe practice, especially in competitive programming, as it prevents potential overflow issues if constraints were slightly larger, though not strictly necessary here.

The number of unique pairs `(i, j)` where `i < j` is `N * (N-1) / 2`. For `N=100`, this is `100 * 99 / 2 = 4950` pairs, which is a very small number, making the nested loop approach highly efficient.

## Complexity Analysis

*   **Time Complexity**:
    *   Reading `N` and `K`: $O(1)$.
    *   Reading the `N` elements of array `A` and calculating `sum_A_half`: This involves a single loop that iterates `N` times. Thus, $O(N)$.
    *   Iterating through all unique pairs `(i, j)`: This is achieved using nested loops. The outer loop runs `N` times (for `i` from `0` to `N-1`), and the inner loop runs `N-1`, `N-2`, ..., `1` times (for `j` from `i+1` to `N-1`). The total number of pairs considered is `N * (N-1) / 2`, which is approximately $O(N^2)$. Inside the inner loop, the fan calculation and comparison are constant time $O(1)$ operations.
    *   Therefore, the dominant part of the algorithm is the nested loop for pairs.
    *   Total Time Complexity: $O(N) + O(N^2) = \boxed{O(N^2)}$.
    *   Given `N <= 100`, $N^2 = 100^2 = 10000$, which is extremely fast and well within typical time limits (usually $10^8$ operations per second).

*   **Space Complexity**:
    *   Storing the input array `A`: This requires a `vector` of size `N`, contributing $O(N)$ space.
    *   Other variables (`N`, `K`, `sum_A_half`, `count_over_K`, loop counters): These use a constant amount of memory, contributing $O(1)$ space.
    *   Total Space Complexity: $O(N) + O(1) = \boxed{O(N)}$.
    *   Given `N <= 100`, this is a very small memory footprint (e.g., `100 * sizeof(int)`).

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, vector, numeric, etc.

// Using namespace std; is requested by the problem statement.
using namespace std;

void solve() {
    int N;
    long long K; // K can be up to 10000. Max fans is 5100. int is sufficient for K, but long long is safer for sums.
    cin >> N >> K;

    vector<int> A(N);
    long long sum_A_half = 0; // Stores sum of A_i / 2 for all i. Max 100 * (100/2) = 5000. int is sufficient.
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        sum_A_half += A[i] / 2;
    }

    int count_over_K = 0; // Counts matches with strictly more than K fans. Max N*(N-1)/2 = 4950. int is sufficient.
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) { // Iterate through unique pairs (i, j) where i < j
            // Calculate fans attending for a match between team i and team j
            // Formula: sum_A_half + A[i]/2 + A[j]/2
            long long current_match_fans = sum_A_half + (A[i] / 2) + (A[j] / 2); // Max 5000 + 50 + 50 = 5100. int is sufficient.
            
            // Check if the number of fans exceeds stadium capacity K
            if (current_match_fans > K) {
                count_over_K++;
            }
        }
    }
    cout << count_over_K << "\n";
}

int main() {
    // Fast I/O setup as requested by the problem statement.
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