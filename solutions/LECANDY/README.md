# [Little Elephant and Candies (LECANDY)](https://www.codechef.com/problems/LECANDY)
- **Difficulty Rating**: 1141
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if it's possible to satisfy all elephants with candies given a limited supply. We are given `N` elephants and a total of `C` candies available. For each of the `N` elephants, we are told how many candies (`A_K`) they need. We need to output "Yes" if it's possible to give each elephant the exact number of candies they need, and "No" otherwise. This must be done for `T` test cases.

**Constraints:**
- `1 <= T <= 1000` (Number of test cases)
- `1 <= N <= 100` (Number of elephants)
- `1 <= C <= 10^9` (Total candies available)
- `1 <= A_K <= 10000` (Candies needed by Kth elephant)

## Intuition & Mathematical Observation

The core idea behind this problem is quite simple: to determine if we can satisfy all elephants, we just need to figure out the *total* number of candies required by *all* elephants combined.

1.  **Calculate Total Required Candies**: Iterate through all `N` elephants and sum up the candies `A_K` that each elephant needs. Let this sum be `total_required_candies`.
2.  **Compare with Available Candies**: Once we have `total_required_candies`, we compare it with the `C` candies we have available.
    *   If `total_required_candies <= C`, it means we have enough (or more than enough) candies to satisfy everyone. In this case, the answer is "Yes".
    *   If `total_required_candies > C`, it means we don't have enough candies to satisfy everyone. In this case, the answer is "No".

This approach directly addresses the problem's requirement without needing any complex data structures or algorithms. The maximum possible value for `total_required_candies` would be `N_max * A_K_max = 100 * 10000 = 1,000,000`, which easily fits within a standard 32-bit integer type (like `int` in C++). The total available candies `C` can be up to `10^9`, which also fits within an `int`.

## Complexity Analysis

*   **Time Complexity**:
    For each test case:
    *   Reading `N` and `C` takes $O(1)$ time.
    *   The loop iterates `N` times to read each `A_K` and add it to the sum. This takes $O(N)$ time.
    *   The final comparison and printing take $O(1)$ time.
    Therefore, for a single test case, the time complexity is $O(N)$.
    Since there are `T` test cases, the total time complexity is $O(T \cdot N)$.
    Given `T <= 1000` and `N <= 100`, the maximum number of operations would be approximately `1000 * 100 = 10^5`, which is very efficient and well within typical time limits for competitive programming problems.

*   **Space Complexity**:
    For each test case, we use a few integer variables to store `N`, `C`, `AK`, and `required_candies_sum`. These variables occupy a constant amount of memory regardless of the input size `N` or `C`.
    Therefore, the space complexity is $O(1)$ (constant space).

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common headers like iostream, vector, etc.
using namespace std; // Allows using cin, cout, etc. without std:: prefix

void solve() {
    int N; // Number of elephants
    int C; // Total candies available. Max 10^9, fits in a 32-bit signed int.
    cin >> N >> C;

    int required_candies_sum = 0; // Sum of AK. Max 100 * 10000 = 10^6, fits in a 32-bit signed int.
    for (int i = 0; i < N; ++i) {
        int AK; // Candies needed by Kth elephant. Max 10000, fits in a 32-bit signed int.
        cin >> AK;
        required_candies_sum += AK;
    }

    // If the total candies required to make all elephants happy
    // is less than or equal to the total candies available,
    // then it's possible.
    if (required_candies_sum <= C) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false); // Unties C++ streams from C standard streams.
    cin.tie(NULL); // Unties cin from cout, meaning cin will not flush cout before reading.

    int T; // Number of test cases
    cin >> T;
    while (T--) { // Loop T times, decrementing T each time
        solve(); // Call the function to solve each test case
    }

    return 0; // Indicate successful execution
}
```