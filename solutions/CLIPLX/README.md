Here's a clean, high-quality solution writeup in GitHub-Flavored Markdown for the CodeChef problem CLIPLX:

# [IPL and RCB (CLIPLX)](https://www.codechef.com/problems/CLIPLX)
- **Difficulty Rating**: 1167
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the minimum number of matches Royal Challengers Bangalore (RCB) must win to achieve a target score of at least `X` points. RCB has `Y` matches remaining. The scoring system is:
- Win: 2 points
- Tie: 1 point
- Loss: 0 points

We need to find the smallest integer `W` such that if RCB wins `W` matches, they can achieve at least `X` points from their `Y` remaining matches.

## Intuition & Mathematical Observation

Our goal is to minimize the number of wins (`W`). To do this, we should maximize the points obtained from the matches that are *not* won.

Let's consider the `Y` remaining matches:
- If RCB wins `W` matches, they get `2 * W` points.
- The remaining `Y - W` matches can either be ties or losses.

To maximize points from these `Y - W` matches without winning them, RCB should aim for ties, as a tie gives 1 point, while a loss gives 0 points. Therefore, to minimize the required wins, we assume that all `Y - W` non-winning matches result in a tie.

So, if RCB wins `W` matches and ties the remaining `Y - W` matches:
- Points from wins: `2 * W`
- Points from ties: `1 * (Y - W)`
- Total points `P = (2 * W) + (Y - W) = W + Y`

We need the total points `P` to be at least `X`.
So, `W + Y >= X`.

Rearranging this inequality to find the minimum `W`:
`W >= X - Y`

Since the number of matches won cannot be negative, `W` must also be at least `0`.
Combining these two conditions, the minimum number of wins `W_min` is `max(0, X - Y)`.

For example:
- If `X = 10` and `Y = 5`: `W >= 10 - 5 = 5`. So, `W_min = max(0, 5) = 5`. RCB must win all 5 matches to get 10 points (5 wins * 2 points/win = 10 points).
- If `X = 5` and `Y = 10`: `W >= 5 - 10 = -5`. So, `W_min = max(0, -5) = 0`. RCB can tie all 10 matches to get 10 points (10 ties * 1 point/tie = 10 points), which is already more than 5 points, so 0 wins are sufficient.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    The program reads `T` test cases. For each test case, it performs a constant number of operations (reading two integers, one subtraction, one `max` operation, and printing an integer). Therefore, the total time complexity is directly proportional to the number of test cases, $O(T)$.

-   **Space Complexity**: $O(1)$
    The program uses a fixed amount of memory to store a few integer variables (`T`, `X`, `Y`, `min_wins`). This memory usage does not depend on the input values or the number of test cases, making the space complexity constant, $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, algorithm, etc.

using namespace std; // Use standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of testcases

    // Loop through each testcase
    while (T--) {
        int X, Y;
        cin >> X >> Y; // Read the required points (X) and remaining matches (Y)

        // Calculate the minimum number of matches RCB must win.
        // To minimize wins, we assume all non-winning matches are ties (1 point each).
        // If RCB wins W matches, they get 2*W points.
        // The remaining (Y - W) matches can be tied, giving (Y - W) points.
        // Total points = 2*W + (Y - W) = W + Y.
        // We need W + Y >= X.
        // This implies W >= X - Y.
        // Since the number of wins cannot be negative, the minimum wins is max(0, X - Y).
        int min_wins = max(0, X - Y);
        
        // Output the result for the current testcase, followed by a newline.
        cout << min_wins << "\n";
    }

    return 0; // Indicate successful execution
}
```