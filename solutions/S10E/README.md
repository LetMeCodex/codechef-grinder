# [Phone Prices (S10E)](https://www.codechef.com/problems/S10E)
- **Difficulty Rating**: 1269
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to count the number of "good days" based on phone prices over `N` days. A day `i` is considered "good" if its price `P[i]` is strictly less than the prices of all the previous 1 to 5 days. Specifically, `P[i]` must be strictly less than `P[i-1]`, `P[i-2]`, `P[i-3]`, `P[i-4]`, and `P[i-5]`. If any of these previous days do not exist (e.g., for day 0, 1, 2, 3, or 4), we only compare with the existing previous days.

## Intuition & Mathematical Observation

The problem statement provides a very direct definition of a "good day". The most straightforward approach is to simulate this definition for each day.

1.  **Iterate through each day**: We can use an outer loop to go through each day `i` from `0` to `N-1`.
2.  **Check the "good day" condition**: For each day `i`, we need to determine if its price `P[i]` is strictly less than the prices of the previous 1 to 5 days.
    *   We can use an inner loop that iterates for `j` from `1` to `5`. This `j` represents how many days back we are looking (1 day back, 2 days back, ..., 5 days back).
    *   For each `j`, the index of the previous day to compare with is `prev_day_idx = i - j`.
    *   **Boundary Check**: Before comparing, we must ensure that `prev_day_idx` is a valid index (i.e., `prev_day_idx >= 0`). If `prev_day_idx < 0`, it means that particular previous day does not exist. Since `j` is increasing, all subsequent `i - (j+1)` will also be negative, so we can stop checking further back for the current day `i`.
    *   **Condition for "Not Good"**: If `prev_day_idx` is valid and `P[i] >= P[prev_day_idx]` (i.e., `P[i]` is *not strictly less* than `P[prev_day_idx]`), then day `i` is immediately determined to be *not* a good day. We can stop checking further previous days for the current `i` and move to the next day `i+1`.
3.  **Count Good Days**: We maintain a counter, `good_days_count`. If, after checking all relevant previous days (up to 5 days back), day `i` still satisfies the condition (i.e., `P[i]` was strictly less than all of them), we increment `good_days_count`.
4.  **Output**: After iterating through all `N` days, print the final `good_days_count`.

This approach directly translates the problem's rules into an algorithm without requiring complex mathematical insights, focusing instead on careful index handling and loop conditions.

## Complexity Analysis

-   **Time Complexity**: $O(N)$
    -   The outer loop iterates `N` times (for each day from `0` to `N-1`).
    -   The inner loop, which checks previous days, iterates at most `5` times (for `j` from `1` to `5`). In the worst case, it performs 5 comparisons and index calculations.
    -   Since the inner loop runs a constant number of times (maximum 5), the total time complexity is proportional to `N * 5`, which simplifies to $O(N)$.
    -   Given `N` can be up to $10^5$, $O(N)$ is efficient enough. For $N=10^5$, this is roughly $5 \times 10^5$ operations per test case, well within typical time limits.

-   **Space Complexity**: $O(N)$
    -   We store the `N` prices in a `std::vector<int> P`. This requires $O(N)$ space.
    -   All other variables (like `N`, `good_days_count`, loop counters `i`, `j`, boolean `is_good`, `prev_day_idx`) use a constant amount of memory, $O(1)$.
    -   Therefore, the dominant factor for space complexity is the storage of prices, resulting in $O(N)$ space.
    -   For $N=10^5$ integers, this is approximately $10^5 \times 4$ bytes = $400$ KB, which is well within typical memory limits.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries, as requested

// Use the standard namespace, as requested
using namespace std;

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the number of days
    vector<int> P(N); // Create a vector to store prices
    for (int i = 0; i < N; ++i) {
        cin >> P[i]; // Read prices for each day
    }

    int good_days_count = 0; // Initialize counter for good days

    // Iterate through each day from 0 to N-1
    for (int i = 0; i < N; ++i) {
        bool is_good = true; // Assume current day's price is good initially

        // Check prices from day i-1 down to max(0, i-5)
        // The inner loop iterates for j = 1, 2, 3, 4, 5, representing 1 to 5 days back
        for (int j = 1; j <= 5; ++j) {
            // Calculate the index of the previous day to compare with
            int prev_day_idx = i - j;

            if (prev_day_idx >= 0) { // Check if the previous day exists (index is valid)
                // If current price is not strictly smaller than a previous price, it's not good
                if (P[i] >= P[prev_day_idx]) {
                    is_good = false; // Mark as not good
                    break;           // No need to check further previous days for current 'i'
                }
            } else {
                // If prev_day_idx < 0, it means we've gone past the beginning of the array.
                // The problem states to ignore non-existent previous days.
                // Since 'j' is increasing, all subsequent 'i-j' will also be negative.
                // So, there are no more valid previous days to check in this direction.
                break;
            }
        }

        // If after all checks, the price is still considered good, increment the counter
        if (is_good) {
            good_days_count++;
        }
    }

    // Print the total count of good days for this test case
    cout << good_days_count << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output, as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful execution
}
```