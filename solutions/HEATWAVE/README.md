# [Heat Wave (HEATWAVE)](https://www.codechef.com/problems/HEATWAVE)
- **Difficulty Rating**: 284
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a new record high temperature was set on a particular day. We are given two integer values: $X$, which represents the highest recorded temperature in a city, and $Y$, which represents the temperature on a specific day. We need to output "YES" if the temperature on this day ($Y$) is strictly greater than the highest recorded temperature ($X$), indicating a new record. Otherwise, if $Y$ is less than or equal to $X$, we should output "NO".

## Intuition & Mathematical Observation

The problem boils down to a straightforward comparison between two given temperatures.
A new record high is created only if the current day's temperature ($Y$) strictly exceeds the previously highest recorded temperature ($X$).

Mathematically, this can be expressed as:
- If $Y > X$, then a new record high has been set.
- If $Y \le X$, then a new record high has not been set.

There are no complex algorithms, data structures, or advanced mathematical concepts required. It's a direct conditional check.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The program performs a fixed number of operations regardless of the input values: two integer reads, one comparison, and one print operation. All these operations take constant time. Therefore, the time complexity is constant.

-   **Space Complexity**: $O(1)$
    The program uses a constant amount of memory to store two integer variables ($X$ and $Y$) and perform the comparison. The memory usage does not scale with any input size, as there is no variable-sized input. Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare two integer variables to store the temperatures.
    // X will store the highest recorded temperature.
    // Y will store the temperature on the given day.
    int X, Y;

    // Read the two temperatures from standard input.
    cin >> X >> Y;

    // Check if the temperature on the given day (Y) is strictly greater
    // than the highest recorded temperature (X).
    // If Y is greater than X, it means a new record high was created.
    if (Y > X) {
        // If a new record high was created, print "YES".
        cout << "YES\n";
    } else {
        // Otherwise (if Y is less than or equal to X), it means a new record high
        // was NOT created.
        // In this case, print "NO".
        cout << "NO\n";
    }

    // The program finishes successfully.
    return 0;
}
```