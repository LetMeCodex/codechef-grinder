# [Dividing Stamps (DIVIDING)](https://www.codechef.com/problems/DIVIDING)
- **Difficulty Rating**: 1109
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if it's possible to redistribute stamps among `N` members such that the `i`-th member (1-indexed) receives exactly `i` stamps. We are given the initial number of stamps each of the `N` members possesses. The key constraint is that redistribution means stamps can only be moved between members; no stamps can be added or removed from the system.

## Intuition & Mathematical Observation

The core idea behind solving this problem lies in the principle of conservation of stamps. If we can redistribute stamps to meet the desired condition, it implies that the *total* number of stamps available must be exactly equal to the *total* number of stamps required.

Let's break this down:
1.  **Required Total Stamps**: If the `i`-th member receives `i` stamps, then the total number of stamps required across all `N` members would be the sum `1 + 2 + 3 + ... + N`. This is a classic arithmetic series sum, which can be calculated using the formula: `N * (N + 1) / 2`.
2.  **Current Total Stamps**: The problem provides the initial number of stamps `C_i` for each member. The current total number of stamps available in the system is simply the sum of all `C_i` values: `C_1 + C_2 + ... + C_N`.

Therefore, the problem simplifies to checking if the `current_total_stamps` is equal to the `required_total_stamps`. If they are equal, then it's theoretically possible to redistribute the stamps, and we output "YES". Otherwise, if the totals don't match (either we have too few or too many stamps), redistribution is impossible, and we output "NO".

**Important Data Type Consideration**:
*   `N` can be up to `10^5`.
*   `C_i` can be up to `10^9`.
*   The `current_total_stamps` can be as large as `N * max(C_i) = 10^5 * 10^9 = 10^14`. A standard 32-bit integer (`int`) can only hold values up to approximately `2 * 10^9`, which would lead to an overflow. Thus, a `long long` (which can hold values up to approximately `9 * 10^18`) is necessary for `current_total_stamps`.
*   Similarly, for `required_total_stamps`, `N * (N + 1)` can be up to `10^5 * (10^5 + 1) \approx 10^{10}`. This also exceeds the capacity of a 32-bit `int`. Therefore, the calculation `(long long)N * (N + 1) / 2` must use `long long` to prevent overflow before division.

## Complexity Analysis

*   **Time Complexity**: $O(N)$
    *   Reading `N` takes $O(1)$ time.
    *   The loop iterates `N` times to read each `C_i` and add it to the running sum. This takes $O(N)$ time.
    *   Calculating `N * (N + 1) / 2` involves a constant number of arithmetic operations, taking $O(1)$ time.
    *   The final comparison and output take $O(1)$ time.
    *   Combining these, the dominant factor is the loop, resulting in an overall time complexity of $O(N)$.

*   **Space Complexity**: $O(1)$
    *   We use a few variables (`N`, `current_total_stamps`, `C_i`, `required_total_stamps`) to store input and intermediate calculations. The number of these variables is constant, regardless of the input size `N`.
    *   Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries, as requested.

using namespace std; // Uses the standard namespace, as requested.

int main() {
    // Enable fast I/O operations, as requested.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; // Declare N to store the number of members.
    cin >> N; // Read the number of members.

    long long current_total_stamps = 0; // Use long long to prevent integer overflow.
                                        // N can be up to 10^5, and Ci up to 10^9.
                                        // The sum can be up to 10^5 * 10^9 = 10^14,
                                        // which exceeds the capacity of a 32-bit int.
                                        // A long long can hold values up to ~9 * 10^18.

    // Loop N times to read each member's stamp count and sum them up.
    for (int i = 0; i < N; ++i) {
        int C_i; // Declare C_i to store the stamp count for the current member.
        cin >> C_i; // Read the stamp count.
        current_total_stamps += C_i; // Add it to the running total.
    }

    // Calculate the required total number of stamps if each i-th member gets i stamps.
    // This is the sum of an arithmetic series: 1 + 2 + ... + N.
    // The formula for this sum is N * (N + 1) / 2.
    // N can be up to 10^5. So, N * (N + 1) can be approximately 10^5 * 10^5 = 10^10.
    // This intermediate product also requires a long long to prevent overflow before division.
    long long required_total_stamps = (long long)N * (N + 1) / 2;

    // Compare the actual total stamps with the required total stamps.
    // If they are equal, redistribution is possible.
    if (current_total_stamps == required_total_stamps) {
        cout << "YES\n"; // Output YES if possible.
    } else {
        cout << "NO\n"; // Output NO if not possible.
    }

    return 0; // Indicate successful execution.
}
```