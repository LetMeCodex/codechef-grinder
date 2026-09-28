# [CodeChef Streak (CS2023_STK)](https://www.codechef.com/problems/CS2023_STK)
- **Difficulty Rating**: 1009
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the winner between two players, Om and Addy, based on their "maximum streak" of solving problems. We are given the number of days, `N`. For each player, we then receive `N` integers, where each integer represents the number of problems solved on a particular day.

A "streak" is defined as a sequence of consecutive days where a player solves at least one problem. If a player solves `0` problems on a day, their current streak is broken. We need to find the maximum streak achieved by Om and Addy over `N` days.

Finally, we compare their maximum streaks:
- If Om's maximum streak is greater, print "OM".
- If Addy's maximum streak is greater, print "ADDY".
- If their maximum streaks are equal, print "DRAW".

## Intuition & Mathematical Observation

The core of this problem is to efficiently calculate the maximum streak for a given sequence of `N` daily problem counts. This can be done with a single pass through the scores.

Let's consider how to track a streak:
1.  **Current Streak**: We need a variable, say `current_streak`, to keep track of the length of the streak that is currently active (i.e., ending on the most recently processed day).
2.  **Maximum Streak**: We also need a variable, say `max_streak`, to store the longest streak encountered so far across all days.

We iterate through the `N` daily problem counts:
-   **If `problems_solved > 0`**: The player solved at least one problem, so the streak continues. We increment `current_streak`.
-   **If `problems_solved == 0`**: The player solved no problems, which breaks the current streak.
    -   Before resetting `current_streak`, the value it holds represents the length of the streak that just ended. We should compare this `current_streak` with `max_streak` and update `max_streak` if `current_streak` is larger: `max_streak = max(max_streak, current_streak)`.
    -   After updating `max_streak`, we reset `current_streak` to `0` because a new streak must begin from scratch.

**Edge Case**: After the loop finishes, it's possible that the last few days (or all days) contributed to an ongoing streak that never ended with a `0`. In this scenario, the `current_streak` variable would hold the length of this final streak, but it would not have been compared with `max_streak` because no `0` was encountered to trigger the update. Therefore, after the loop, we must perform one final comparison: `max_streak = max(max_streak, current_streak)` to ensure this potential final streak is considered.

This logic is applied independently for Om's scores and then for Addy's scores. Finally, a simple comparison of their `max_streak` values determines the output.

## Complexity Analysis

Let `N` be the number of days for which scores are provided for each player.
Let `T` be the number of test cases.

-   **Time Complexity**:
    -   For each test case:
        -   Reading `N`: $O(1)$.
        -   Calculating Om's maximum streak: This involves iterating through `N` scores. Each operation inside the loop (reading input, incrementing, comparing, assigning) takes constant time. Thus, it's $O(N)$.
        -   Calculating Addy's maximum streak: Similarly, this also takes $O(N)$.
        -   Comparing the two maximum streaks and printing the result: $O(1)$.
    -   Total time complexity per test case is $O(N) + O(N) = O(N)$.
    -   Since there are `T` test cases, the overall time complexity is $O(T \cdot N)$.

-   **Space Complexity**:
    -   For each test case, we only use a few integer variables (`N`, `current_streak`, `max_streak`, `problems_solved`, `om_max_streak`, `addy_max_streak`). These variables occupy a constant amount of memory regardless of the value of `N`. We do not store all `N` scores in an array; we process them one by one.
    -   Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace as requested
using namespace std;

// Function to calculate the maximum streak for a given sequence of N scores.
// It reads N integers from standard input.
int calculateMaxStreak(int N) {
    int current_streak = 0; // Stores the length of the current active streak
    int max_streak = 0;     // Stores the maximum streak found so far

    for (int i = 0; i < N; ++i) {
        int problems_solved;
        cin >> problems_solved; // Read the number of problems solved on the current day

        if (problems_solved > 0) {
            // If at least one problem is solved, the streak continues/increases
            current_streak++;
        } else {
            // If 0 problems are solved, the streak is broken.
            // First, update max_streak if the just-ended current_streak was longer.
            max_streak = max(max_streak, current_streak);
            // Then, reset current_streak to 0 as a new streak must start.
            current_streak = 0;
        }
    }
    // After the loop, there might be an ongoing streak that extends to the last day.
    // This streak would not have been compared with max_streak yet because it didn't end with a '0'.
    // So, perform one final comparison to ensure this last streak is considered.
    max_streak = max(max_streak, current_streak);
    return max_streak;
}

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the number of days

    // Calculate Om's maximum streak by calling calculateMaxStreak.
    // This call will read the N integers for Om's scores.
    int om_max_streak = calculateMaxStreak(N);

    // Calculate Addy's maximum streak.
    // This call will read the N integers for Addy's scores, immediately after Om's scores.
    int addy_max_streak = calculateMaxStreak(N);

    // Compare their maximum streaks and print the result as specified.
    if (om_max_streak > addy_max_streak) {
        cout << "OM\n";
    } else if (addy_max_streak > om_max_streak) {
        cout << "ADDY\n";
    } else {
        cout << "DRAW\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```