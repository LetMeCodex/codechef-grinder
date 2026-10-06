# [No Time to Wait (NOTIME)](https://www.codechef.com/problems/NOTIME)
- **Difficulty Rating**: 932
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef has `x` hours remaining to solve a problem that requires `H` hours. He can travel to any of `N` different time zones. Each time zone `i` is `T_i` hours behind the current time. If Chef travels to a time zone `T_i` hours behind, he effectively gains `T_i` hours, making his total available time `x + T_i`. The task is to determine if there exists *any* time zone `T_i` such that Chef's total available time (`x + T_i`) is sufficient to solve the problem (i.e., `x + T_i >= H`). Output "YES" if such a time zone exists, otherwise "NO".

## Intuition & Mathematical Observation

The problem asks if there's *at least one* time zone that allows Chef to solve the problem. This means we don't need to find the "best" time zone or maximize anything; we just need to find if the condition `x + T_i >= H` holds true for *any* `T_i` among the given `N` time zones.

Our approach will be straightforward:
1.  Read the initial values `N`, `H`, and `x`.
2.  Iterate through each of the `N` time zones.
3.  For each time zone `T_i`, calculate the total time Chef would have: `current_time = x + T_i`.
4.  Check if `current_time` is greater than or equal to `H`.
5.  If this condition is met for *any* `T_i`, we know Chef can solve the problem. We can immediately stop checking further time zones and output "YES".
6.  If we iterate through all `N` time zones and none of them satisfy the condition, then Chef cannot solve the problem, and we output "NO".

This is a simple search problem where we are looking for the existence of an element that satisfies a specific condition.

## Complexity Analysis

*   **Time Complexity**: $O(N)$
    We iterate through the `N` time zones at most once. In the best case, if the very first time zone allows Chef to solve the problem, we perform only one check. In the worst case, we might have to check all `N` time zones (either because none work, or the last one works). Each check and arithmetic operation inside the loop is constant time. Therefore, the overall time complexity is directly proportional to the number of time zones, $N$.

*   **Space Complexity**: $O(1)$
    We only use a few variables to store `N`, `H`, `x`, the current `T_i`, and a boolean flag `can_solve`. The amount of memory used does not depend on the input size `N`. Hence, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // potentially speeding up I/O operations.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // which can also speed up I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare variables N, H, and x as per problem statement.
    // N: number of time zones
    // H: hours needed to solve the problem
    // x: hours currently remaining
    int N, H, x;

    // Read the values of N, H, and x from standard input.
    cin >> N >> H >> x;

    // Initialize a boolean flag to track if Chef can solve the problem.
    // It's initially false, assuming he cannot solve it until a suitable time zone is found.
    bool can_solve = false;

    // Loop N times to read each time zone value T_i.
    for (int i = 0; i < N; ++i) {
        int T_i; // Declare variable for the current time zone's hours behind.
        cin >> T_i; // Read T_i from standard input.

        // Calculate the total time Chef would have if he uses this time zone.
        // This is his current remaining time (x) plus the time gained from traveling back (T_i).
        // Check if this total time is sufficient to solve the problem (i.e., >= H).
        if (x + T_i >= H) {
            can_solve = true; // If sufficient, set the flag to true.
            // Since we only need to find *one* suitable time zone,
            // we can break out of the loop as soon as we find one.
            break;
        }
    }

    // After checking all time zones (or breaking early),
    // print "YES" if can_solve is true, otherwise print "NO".
    if (can_solve) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    // Return 0 to indicate successful execution.
    return 0;
}
```