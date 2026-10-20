# [Morning Run (MORNINGRUN)](https://www.codechef.com/problems/MORNINGRUN)
- **Difficulty Rating**: 306
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if Chef can achieve a fitness goal by running along the perimeter of a rectangular park. Chef's fitness goal is to run at least 1000 meters. We are given the length ($X$) and width ($Y$) of the rectangular park. We need to output "YES" if the perimeter of the park is 1000 meters or more, and "NO" otherwise.

## Intuition & Mathematical Observation

The core of this problem lies in calculating the perimeter of a rectangle and then comparing it against a target value.

1.  **Perimeter of a Rectangle**: For a rectangle with length $X$ and width $Y$, the perimeter is given by the formula:
    $$ \text{Perimeter} = 2 \times (X + Y) $$

2.  **Fitness Goal Check**: Chef's goal is to run at least 1000 meters. This means if the calculated perimeter is greater than or equal to 1000, Chef can achieve the goal. Otherwise, Chef cannot.

So, the steps are:
*   Read the length $X$ and width $Y$.
*   Calculate the perimeter using the formula $2 \times (X + Y)$.
*   If `perimeter >= 1000`, print "YES".
*   Else, print "NO".

This is a straightforward application of a basic geometric formula and a conditional check.

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    The solution involves reading two integers, performing a constant number of arithmetic operations (one addition, one multiplication), one comparison, and printing a string. All these operations take a fixed amount of time, irrespective of the input values (within the standard integer limits). Therefore, the time complexity is constant.

*   **Space Complexity**: $O(1)$
    The solution uses a few integer variables (`X`, `Y`, `perimeter`) to store input and intermediate results. These variables occupy a constant amount of memory, which does not depend on the magnitude of the input values. No dynamic data structures or arrays are used. Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common standard libraries like iostream

using namespace std; // Allows using standard library elements without the std:: prefix

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X, Y; // Declare variables for length and width
    cin >> X >> Y; // Read the length (X) and width (Y) from standard input

    // Calculate the perimeter of the rectangular park.
    // The perimeter is 2 * (length + width).
    int perimeter = 2 * (X + Y);

    // Check if the calculated perimeter is at least 1000 meters.
    // If it is, Chef can achieve the fitness goal.
    if (perimeter >= 1000) {
        cout << "YES\n"; // Print "YES" followed by a newline
    } else {
        // If the perimeter is less than 1000 meters, Chef cannot achieve the goal.
        cout << "NO\n"; // Print "NO" followed by a newline
    }

    return 0; // Indicate successful execution
}
```