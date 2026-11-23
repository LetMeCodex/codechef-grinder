# [My First Geometry Problem (FIRSTGEO)](https://www.codechef.com/problems/FIRSTGEO)
- **Difficulty Rating**: 1171
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the total number of distinct integer coordinate points $(x, y)$ that can be reached from the origin $(0,0)$, subject to the constraints $-10 \le x \le 10$ and $-10 \le y \le 10$.

We are given a binary string $S$ of length 4, where each character indicates whether movement in a specific direction is allowed:
- $S_1$ (first character, `s[0]` in 0-indexed string): '1' means we can move left (decrease x-coordinate), '0' means we cannot.
- $S_2$ (second character, `s[1]`): '1' means we can move right (increase x-coordinate), '0' means we cannot.
- $S_3$ (third character, `s[2]`): '1' means we can move up (increase y-coordinate), '0' means we cannot.
- $S_4$ (fourth character, `s[3]`): '1' means we can move down (decrease y-coordinate), '0' means we cannot.

We can make any number of moves.

## Intuition & Mathematical Observation

The core idea behind solving this problem is to recognize that movement along the x-axis is completely independent of movement along the y-axis. This means we can determine the set of reachable x-coordinates and the set of reachable y-coordinates separately. The total number of reachable points will then be the product of the number of distinct reachable x-coordinates and the number of distinct reachable y-coordinates.

Let's analyze the reachability for each axis:

### X-axis Reachability (from $x=0$, within $[-10, 10]$):

1.  **Can move left ($S_1 = '1'$) and can move right ($S_2 = '1'$):**
    If we can move both left and right, we can reach any integer x-coordinate from $-\infty$ to $+\infty$. Within the given range $[-10, 10]$, all 21 integer values (from -10 to 10, inclusive) are reachable.
    Number of values = $10 - (-10) + 1 = 21$.

2.  **Can move left ($S_1 = '1'$) but cannot move right ($S_2 = '0'$):**
    We can only move to $x \le 0$. Starting from $x=0$, we can reach any integer $x \le 0$. Within the range $[-10, 10]$, this means $x \in [-10, 0]$.
    Number of values = $0 - (-10) + 1 = 11$.

3.  **Cannot move left ($S_1 = '0'$) but can move right ($S_2 = '1'$):**
    We can only move to $x \ge 0$. Starting from $x=0$, we can reach any integer $x \ge 0$. Within the range $[-10, 10]$, this means $x \in [0, 10]$.
    Number of values = $10 - 0 + 1 = 11$.

4.  **Cannot move left ($S_1 = '0'$) and cannot move right ($S_2 = '0'$):**
    We cannot move horizontally at all. Only $x=0$ is reachable.
    Number of values = $1$.

### Y-axis Reachability (from $y=0$, within $[-10, 10]$):

This is symmetric to the x-axis analysis, using $S_3$ for up and $S_4$ for down.

1.  **Can move up ($S_3 = '1'$) and can move down ($S_4 = '1'$):**
    All 21 integer values from -10 to 10 are reachable.
    Number of values = $21$.

2.  **Can move up ($S_3 = '1'$) but cannot move down ($S_4 = '0'$):**
    We can only move to $y \ge 0$. Within $[-10, 10]$, this means $y \in [0, 10]$.
    Number of values = $11$.

3.  **Cannot move up ($S_3 = '0'$) but can move down ($S_4 = '1'$):**
    We can only move to $y \le 0$. Within $[-10, 10]$, this means $y \in [-10, 0]$.
    Number of values = $11$.

4.  **Cannot move up ($S_3 = '0'$) and cannot move down ($S_4 = '0'$):**
    Only $y=0$ is reachable.
    Number of values = $1$.

Finally, the total number of reachable cells is the product of the number of reachable x-coordinates and the number of reachable y-coordinates.

## Complexity Analysis

-   **Time Complexity**: For each test case, we read a string of fixed length 4, perform a few constant-time comparisons and arithmetic operations, and print the result. All these operations take constant time, $O(1)$. If there are $T$ test cases, the total time complexity is $O(T)$.

-   **Space Complexity**: We store the input string $S$ (which has a fixed length of 4) and a few integer variables. This requires a constant amount of memory, $O(1)$, per test case.

## Solution Code

```cpp
#include <iostream> // Required for cin, cout
#include <string>   // Required for std::string

// As requested by the problem statement.
using namespace std;

// Function to solve a single test case
void solve() {
    string s;
    cin >> s; // Read the binary string S

    long long count_x = 0; // Number of reachable x-coordinates
    long long count_y = 0; // Number of reachable y-coordinates

    // Determine reachability along the x-axis
    // S_1 (s[0]) refers to left, S_2 (s[1]) refers to right
    bool can_move_left = (s[0] == '1');
    bool can_move_right = (s[1] == '1');

    if (can_move_left && can_move_right) {
        // Can move both left and right, so all x-coordinates from -10 to 10 are reachable.
        // Number of values from -10 to 10 inclusive is 10 - (-10) + 1 = 21.
        count_x = 21;
    } else if (can_move_left) {
        // Can only move left. From (0,0), can reach x <= 0.
        // Within [-10, 10], this means x-coordinates from -10 to 0 inclusive.
        // Number of values is 0 - (-10) + 1 = 11.
        count_x = 11;
    } else if (can_move_right) {
        // Can only move right. From (0,0), can reach x >= 0.
        // Within [-10, 10], this means x-coordinates from 0 to 10 inclusive.
        // Number of values is 10 - 0 + 1 = 11.
        count_x = 11;
    } else {
        // Cannot move left or right. Only x=0 is reachable.
        count_x = 1;
    }

    // Determine reachability along the y-axis
    // S_3 (s[2]) refers to up, S_4 (s[3]) refers to down
    bool can_move_up = (s[2] == '1');
    bool can_move_down = (s[3] == '1');

    if (can_move_up && can_move_down) {
        // Can move both up and down, so all y-coordinates from -10 to 10 are reachable.
        // Number of values from -10 to 10 inclusive is 10 - (-10) + 1 = 21.
        count_y = 21;
    } else if (can_move_up) {
        // Can only move up. From (0,0), can reach y >= 0.
        // Within [-10, 10], this means y-coordinates from 0 to 10 inclusive.
        // Number of values is 10 - 0 + 1 = 11.
        count_y = 11;
    } else if (can_move_down) {
        // Can only move down. From (0,0), can reach y <= 0.
        // Within [-10, 10], this means y-coordinates from -10 to 0 inclusive.
        // Number of values is 0 - (-10) + 1 = 11.
        count_y = 11;
    } else {
        // Cannot move up or down. Only y=0 is reachable.
        count_y = 1;
    }

    // The total number of reachable cells is the product of reachable x and y coordinates,
    // because movements along x and y axes are independent.
    cout << count_x * count_y << "\n";
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful execution
}
```