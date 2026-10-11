# [Calorie Limit (CALLIM)](https://www.codechef.com/problems/CALLIM)
- **Difficulty Rating**: 719
- **Solved in**: 1 attempt(s)

## Problem Summary

Sushil wants to eat sweets. He has a daily calorie limit `K`. He is presented with `N` sweets, one by one, each having a specific calorie count `A_i`. Sushil eats the sweets *in the given order*. He continues eating as long as his total calorie intake does not exceed `K`. The moment eating the *next* sweet would cause his total calorie intake to exceed `K`, he stops eating immediately. He does not eat that sweet or any subsequent sweets. The task is to determine the maximum number of sweets Sushil can eat.

## Intuition & Mathematical Observation

The problem statement clearly specifies that Sushil eats sweets "in the given order". This is the most crucial piece of information. It means we don't have the freedom to pick and choose sweets or reorder them to maximize the count. We must process them exactly as they appear in the input.

Given this constraint, the approach becomes straightforward:
1.  We need to keep track of the `current_calories_consumed` and the `sweets_eaten_count`.
2.  We iterate through the sweets from the first one to the last.
3.  For each sweet, we check if adding its calories (`A_i`) to our `current_calories_consumed` would exceed the `K` limit.
    *   If `current_calories_consumed + A_i <= K`: Sushil can eat this sweet. We add `A_i` to `current_calories_consumed` and increment `sweets_eaten_count`.
    *   If `current_calories_consumed + A_i > K`: Sushil cannot eat this sweet. According to the problem, he stops immediately. This means he will not eat this sweet or any subsequent sweets. At this point, we can stop processing and output the `sweets_eaten_count` accumulated so far.
4.  A minor implementation detail for competitive programming: If Sushil stops early, there might be remaining `A_i` values for the current test case in the input buffer. To ensure the next test case reads correctly, these remaining values must be read and discarded.

This approach is greedy because at each step, we make the locally optimal choice (eat the sweet if possible) which also leads to the globally optimal solution given the fixed order constraint.

## Complexity Analysis

*   **Time Complexity**: $O(N)$ per test case.
    *   The solution iterates through the `N` sweets at most once. In the worst case, Sushil eats all `N` sweets, leading to `N` iterations.
    *   If Sushil stops early (e.g., after `i` sweets), the loop breaks. However, the code then proceeds to read and discard the remaining `N - (i+1)` sweet calorie values to clear the input buffer for the next test case.
    *   In total, for each test case, we perform a constant number of operations (read, add, compare, increment) for each of the `N` sweets.
    *   Since there are `T` test cases, the total time complexity is $O(T \cdot N)$.

*   **Space Complexity**: $O(1)$
    *   The solution uses a few integer variables (`N`, `K`, `current_calories_consumed`, `sweets_eaten_count`, `A_i`, `dummy`). These variables consume a constant amount of memory regardless of the input size `N`.
    *   Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries, as requested

using namespace std; // As requested, to avoid typing std:: repeatedly

void solve() {
    int N, K;
    cin >> N >> K; // Read N (number of sweets) and K (calorie limit)

    int current_calories_consumed = 0; // Tracks total calories eaten so far
    int sweets_eaten_count = 0;        // Tracks number of sweets eaten

    // Iterate through the sweets in order
    for (int i = 0; i < N; ++i) {
        int A_i;
        cin >> A_i; // Read the calorie count of the current sweet

        // Check if eating this sweet would exceed the daily calorie limit
        if (current_calories_consumed + A_i <= K) {
            // If it doesn't exceed, eat the sweet
            current_calories_consumed += A_i; // Add its calories to the total
            sweets_eaten_count++;             // Increment the count of sweets eaten
        } else {
            // If eating this sweet would exceed the limit, Sushil stops.
            // He will not eat this sweet or any further sweets.
            // We need to consume the remaining A_i values for this test case
            // from the input buffer to ensure the next test case reads correctly.
            for (int j = i + 1; j < N; ++j) {
                int dummy;
                cin >> dummy; // Read and discard remaining sweet calorie counts
            }
            break; // Exit the loop as Sushil stops eating
        }
    }
    
    // Output the maximum number of sweets Sushil could eat
    cout << sweets_eaten_count << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cout from being flushed before each cin operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {  // Loop T times, decrementing T each time
        solve();   // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```