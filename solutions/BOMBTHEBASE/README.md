# [Bomb the base (BOMBTHEBASE)](https://www.codechef.com/problems/BOMBTHEBASE)
- **Difficulty Rating**: 982
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a scenario where there are `N` houses, each with a certain defense strength `A_i`. A bomb with attack strength `X` is used. The rule for destruction is specific: if house `i` (1-indexed) has a defense strength `A_i` strictly less than the bomb's attack strength `X` (i.e., `A_i < X`), then house `i` and *all* houses with indices `j` such that `1 <= j < i` are destroyed. The task is to find the maximum number of houses that can be destroyed.

## Intuition & Mathematical Observation

The key to this problem lies in understanding the destruction rule: "if house `i` is destroyed, all houses `1` to `i` are destroyed." This implies a cumulative effect. If we find a house `i` that can be destroyed (i.e., `A_i < X`), then we can destroy `i` houses in total (houses 1, 2, ..., `i`).

Consider iterating through the houses from the first (index 1) to the last (index `N`).
1. If we encounter a house `i` such that its defense `A_i` is less than the bomb's attack `X`, it means we can destroy houses `1` through `i`. The total count of destroyed houses would be `i`.
2. If we later encounter a house `k` (where `k > i`) such that `A_k < X`, it means we can destroy houses `1` through `k`. The total count of destroyed houses would be `k`.

Since we are looking for the *maximum* number of houses that can be destroyed, we should always aim for the largest possible index `i` for which the condition `A_i < X` holds. As we iterate from `i=1` to `N`, if we find a house `i` that satisfies `A_i < X`, then `i` becomes a candidate for the maximum number of destroyed houses. We simply keep track of the largest such `i` encountered so far.

By iterating through all houses and updating a `max_destroyed_houses` variable whenever we find a destroyable house `i` (setting `max_destroyed_houses = i`), the final value of `max_destroyed_houses` will correctly represent the maximum possible count. If no house can be destroyed, `max_destroyed_houses` will remain 0, which is the correct answer.

## Complexity Analysis

-   **Time Complexity**: $O(N)$
    The solution involves a single loop that iterates through all `N` houses once for each test case. Inside the loop, operations like reading input, comparison, and assignment are all constant time. Therefore, for a single test case, the time complexity is $O(N)$. Since there are `T` test cases, the total time complexity is $O(T \cdot N)$. Given $T \le 100$ and $N \le 1000$, the maximum operations would be around $100 \times 1000 = 10^5$, which is very efficient and well within typical time limits.

-   **Space Complexity**: $O(1)$
    The solution uses a few integer variables (`N`, `X`, `max_destroyed_houses`, `A_i`, `i`) to store input and intermediate results. It does not use any data structures that grow with the input size `N` (e.g., it doesn't store the entire array `A`). Thus, the space used is constant, making the space complexity $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Standard header for competitive programming in C++. Includes iostream, vector, algorithm, etc.

// Using namespace std; is a common practice in competitive programming to avoid repeatedly typing std::
using namespace std;

// Function to solve a single test case
void solve() {
    int N; // Number of houses
    long long X; // Attack strength of the bomb. Using long long for safety, though int (32-bit) would suffice for 10^9.
    cin >> N >> X;

    int max_destroyed_houses = 0; // This variable will store the maximum number of houses that can be destroyed.
                                  // Initialized to 0, in case no house can be destroyed.

    // Iterate through each house from 1 to N (using 0-based indexing for array A, so i from 0 to N-1).
    for (int i = 0; i < N; ++i) {
        long long A_i; // Defence strength of the i-th house. Using long long for safety.
        cin >> A_i;

        // Check if the current house (i+1) can be destroyed by the bomb.
        // A house is destroyed if its defence A_i is strictly less than the bomb's attack strength X.
        if (A_i < X) {
            // If house (i+1) can be destroyed, then according to the problem statement,
            // all houses with indices j such that 1 <= j < (i+1) also get destroyed.
            // This means houses 1, 2, ..., (i+1) are all destroyed.
            // The total number of destroyed houses would be (i+1).
            // Since we want to find the MAXIMUM number of houses destroyed,
            // and we are iterating from the first house to the last,
            // any time we find a house (i+1) that can be destroyed,
            // it means we can potentially destroy (i+1) houses.
            // By continuously updating max_destroyed_houses with (i+1),
            // the final value will be the largest (i+1) for which A_i < X.
            max_destroyed_houses = i + 1;
        }
    }

    // Output the maximum number of houses that can be destroyed for this test case.
    cout << max_destroyed_houses << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```