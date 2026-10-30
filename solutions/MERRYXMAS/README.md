# [Merry Christmas! (MERRYXMAS)](https://www.codechef.com/problems/MERRYXMAS)
- **Difficulty Rating**: 454
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef has `X` hours available and wants to complete as many Christmas activities as possible. There are three activities with fixed durations:
1. Decorating a Christmas tree: 1 hour
2. Baking cookies: 2 hours
3. Making a gingerbread house: 4 hours

The goal is to determine the maximum number of activities Chef can complete within the given `X` hours.

## Intuition & Mathematical Observation

This problem is a classic example of a greedy approach. To maximize the number of activities completed, Chef should always prioritize the activities that take the *least* amount of time. This strategy ensures that more time is left available for subsequent activities, thus increasing the chances of completing more tasks overall.

The activity durations are 1 hour, 2 hours, and 4 hours. Following the greedy strategy, Chef should attempt to complete them in increasing order of their duration:

1.  **1-hour activity (Decorating a Christmas tree):** If Chef has at least 1 hour remaining, he should complete this activity.
2.  **2-hour activity (Baking cookies):** After potentially completing the 1-hour activity, if Chef has at least 2 hours remaining, he should complete this activity.
3.  **4-hour activity (Making a gingerbread house):** After potentially completing the 1-hour and 2-hour activities, if Chef has at least 4 hours remaining, he should complete this activity.

We simply iterate through these activities in this specific order, checking if enough time is available. If an activity can be completed, we decrement the available time `X` and increment a counter for completed activities.

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    The solution involves a fixed number of operations (a few `if` conditions, subtractions, and increments). These operations do not depend on the magnitude of the input `X`. Therefore, the time taken is constant.

*   **Space Complexity**: $O(1)$
    The solution uses a constant amount of extra space for variables like `X` and `activities_completed`. The memory usage does not scale with the input `X`.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries
using namespace std; // Uses the standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X; // Declare an integer variable X to store the available hours.
    cin >> X; // Read the value of X from standard input.

    int activities_completed = 0; // Initialize a counter for completed activities.

    // To maximize the number of activities, Chef should always choose the activities
    // that take the least amount of time first. This greedy approach ensures that
    // more time is left for subsequent activities.
    // The activity durations are: 1 hour, 2 hours, and 4 hours.
    // We process them in increasing order of duration: 1, then 2, then 4.

    // Try to complete the 1-hour activity (Decorating a Christmas tree).
    // If Chef has at least 1 hour remaining, he can do this activity.
    if (X >= 1) {
        X -= 1; // Deduct the time taken for this activity from the available hours.
        activities_completed++; // Increment the count of completed activities.
    }

    // Try to complete the 2-hour activity (Baking cookies).
    // If Chef has at least 2 hours remaining after potentially completing the 1-hour activity,
    // he can do this activity.
    if (X >= 2) {
        X -= 2; // Deduct the time taken for this activity.
        activities_completed++; // Increment the count of completed activities.
    }

    // Try to complete the 4-hour activity (Making a gingerbread house).
    // If Chef has at least 4 hours remaining after potentially completing the 1-hour and 2-hour activities,
    // he can do this activity.
    if (X >= 4) {
        X -= 4; // Deduct the time taken for this activity.
        activities_completed++; // Increment the count of completed activities.
    }

    // Output the maximum number of activities Chef can complete.
    cout << activities_completed << "\n";

    return 0; // Indicate successful execution.
}
```