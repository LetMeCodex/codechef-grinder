# [Cricket World Cup Qualifier (CWC23QUALIF)](https://www.codechef.com/problems/CWC23QUALIF)
- **Difficulty Rating**: 203
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a cricket team qualifies for the Cricket World Cup. A team qualifies if and only if their total score is 12 points or more. We are given a single integer `X`, representing the total points scored by the team. Our task is to print "Yes" if the team qualifies, and "No" otherwise.

## Intuition & Mathematical Observation

This problem is a direct application of a simple conditional check. The core requirement for qualification is that the team's total points `X` must be greater than or equal to 12.

Therefore, the intuition is:
1. Read the input value `X`.
2. Compare `X` with 12.
3. If `X >= 12`, the team qualifies, so print "Yes".
4. Otherwise (if `X < 12`), the team does not qualify, so print "No".

There are no complex algorithms, data structures, or mathematical observations beyond this basic comparison.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The program performs a constant number of operations: reading an integer, performing a single comparison, and printing a string. These operations take a fixed amount of time regardless of the input value `X` (within the typical integer limits).

-   **Space Complexity**: $O(1)$
    The program uses a constant amount of memory to store the input integer `X` and a few other variables for input/output operations. The memory usage does not grow with the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare an integer variable X to store the total points scored by the team.
    int X;

    // Read the total points X from standard input.
    cin >> X;

    // Check if the team has scored 12 or more points.
    // According to the problem statement, a team qualifies if they score 12 or more points.
    if (X >= 12) {
        // If the team has scored 12 or more points, print "Yes".
        // The output format requires "Yes" or "No", case-insensitive, so "Yes" is fine.
        cout << "Yes\n";
    } else {
        // Otherwise (if X is less than 12), the team does not qualify. Print "No".
        cout << "No\n";
    }

    // Return 0 to indicate successful execution of the program.
    return 0;
}
```