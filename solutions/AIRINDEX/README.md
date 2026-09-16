# Air Quality Index (AIRINDEX)

- **Difficulty Rating**: 347
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if the measured Air Quality Index (AQI) is within the government's acceptable limit. The government's goal is to keep the average AQI strictly below 100. We are given a single integer `X` representing the measured AQI. We need to output "YES" if the AQI is strictly less than 100, and "NO" otherwise.

## Intuition & Mathematical Observation

The core of the problem lies in understanding the condition "strictly below 100". This means that any AQI value that is less than 100 satisfies the condition. If the AQI is exactly 100 or greater than 100, it does not satisfy the condition.

Mathematically, this can be expressed as:
- If $X < 100$, the condition is met.
- If $X \ge 100$, the condition is not met.

This directly translates into a simple conditional check.

## Complexity Analysis

- **Time Complexity**: $O(1)$
The solution involves reading a single integer and performing a single comparison. These operations take constant time, regardless of the input value of `X`.

- **Space Complexity**: $O(1)$
The solution uses a fixed amount of memory to store the input variable `X` and a few other variables for program control. This amount of memory does not grow with the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // allowing them to operate independently and often faster.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // which can further speed up I/O in interactive problems or those with mixed I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare an integer variable 'X' to store the measured AQI.
    int X;

    // Read the AQI value from standard input.
    cin >> X;

    // The government's goal is to keep the average AQI strictly below 100.
    // This means if X is less than 100, the limit is met.
    // If X is 100 or greater, the limit is not met.
    if (X < 100) {
        // If X is strictly less than 100, print "YES".
        cout << "YES\n";
    } else {
        // Otherwise (if X is 100 or greater), print "NO".
        cout << "NO\n";
    }

    // Return 0 to indicate successful program execution.
    return 0;
}
```