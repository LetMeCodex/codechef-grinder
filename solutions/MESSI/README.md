# [Football Training (MESSI)](https://www.codechef.com/problems/MESSI)
- **Difficulty Rating**: 329
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a scenario where two types of football training sessions are proposed: a free kick session and a penalty session. There are `X` fans who want a free kick session and `Y` fans who want a penalty session. The rule is that the training session with more interested players will be held. We are guaranteed that the number of fans for each session will never be equal (i.e., `X != Y`). Our task is to determine and print which session will be held: "FREEKICK" or "PENALTY".

## Intuition & Mathematical Observation

This problem is a direct comparison task. We are given two integer values, `X` and `Y`, representing the number of fans for two different types of sessions. The problem statement clearly defines the decision rule: the session with more fans is chosen. Since it's guaranteed that `X` will never be equal to `Y`, there are only two possible scenarios:

1.  **`X > Y`**: If the number of fans for the free kick session (`X`) is strictly greater than the number of fans for the penalty session (`Y`), then the free kick session will be held.
2.  **`Y > X`**: If the number of fans for the penalty session (`Y`) is strictly greater than the number of fans for the free kick session (`X`), then the penalty session will be held.

This logic can be implemented using a simple `if-else` conditional statement. We read `X` and `Y`, then check `if (X > Y)`. If true, we print "FREEKICK"; otherwise (meaning `Y > X`), we print "PENALTY".

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    *   The program performs a constant number of operations: reading two integers, comparing them, and printing a fixed-length string. These operations do not depend on the magnitude of `X` or `Y` (within standard integer limits), making the time complexity constant.
*   **Space Complexity**: $O(1)$
    *   The program uses a constant amount of memory to store the two input integers (`X` and `Y`) and a few other variables for standard I/O operations. No dynamic data structures or arrays are used, so the space complexity remains constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries

using namespace std; // Use the standard namespace

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from C's stdio and prevents flushing cout before cin.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare two integer variables X and Y.
    // X: number of Leo's fans, who want a free kick session.
    // Y: number of Ronald's fans, who want a penalty session.
    int X, Y;

    // Read the two space-separated integers from the first and only line of input.
    // The problem statement implies a single test case by describing the input
    // as "The first and only line of input contains two space-separated integers X and Y".
    cin >> X >> Y;

    // The problem states that the training session with more interested players will be held.
    // It is guaranteed that X != Y, so there will be no tie in the number of fans.

    // If X (number of Leo's fans) is greater than Y (number of Ronald's fans),
    // then more players want a free kick session.
    if (X > Y) {
        cout << "FREEKICK\n";
    }
    // Otherwise (since X != Y, this implies Y > X),
    // more players want a penalty session.
    else { // Y > X
        cout << "PENALTY\n";
    }

    // The program successfully executed.
    return 0;
}
```