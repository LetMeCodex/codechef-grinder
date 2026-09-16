# [Nearest Exit (NEARESTEXIT)](https://www.codechef.com/problems/NEARESTEXIT)
- **Difficulty Rating**: 585
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem describes a scenario with 100 seats, numbered from 1 to 100. There are two exits: one at seat 1 (LEFT exit) and another at seat 100 (RIGHT exit). A passenger is at seat `X` and needs to choose the nearest exit. We are required to output "LEFT" if the passenger chooses the exit at seat 1, and "RIGHT" if they choose the exit at seat 100.

## Intuition & Mathematical Observation
The core of the problem is to determine which of the two exits (seat 1 or seat 100) is closer to a given seat `X`.

1.  **Distance to LEFT exit**: The distance from seat `X` to seat 1 is `X - 1`.
2.  **Distance to RIGHT exit**: The distance from seat `X` to seat 100 is `100 - X`.

A passenger will choose the LEFT exit if `X - 1` is less than `100 - X`.
A passenger will choose the RIGHT exit if `100 - X` is less than `X - 1`.

Let's find the midpoint where the distances are equal:
`X - 1 = 100 - X`
`2X = 101`
`X = 50.5`

Since seat numbers are integers, there is no seat exactly at `50.5`. This means there will never be a tie in distance.
-   For any seat `X` where `X <= 50`:
    -   The distance `X - 1` will be less than or equal to `49`.
    -   The distance `100 - X` will be greater than or equal to `50`.
    -   For example, if `X = 50`: distance to LEFT is `50 - 1 = 49`, distance to RIGHT is `100 - 50 = 50`. `49 < 50`, so LEFT.
    -   Thus, seats `1` through `50` are closer to the LEFT exit.

-   For any seat `X` where `X >= 51`:
    -   The distance `X - 1` will be greater than or equal to `50`.
    -   The distance `100 - X` will be less than or equal to `49`.
    -   For example, if `X = 51`: distance to LEFT is `51 - 1 = 50`, distance to RIGHT is `100 - 51 = 49`. `50 > 49`, so RIGHT.
    -   Thus, seats `51` through `100` are closer to the RIGHT exit.

Based on this observation, the logic is straightforward: if `X` is less than or equal to `50`, output "LEFT"; otherwise, output "RIGHT".

## Complexity Analysis
-   **Time Complexity**: $O(1)$ per test case.
    For each test case, the program reads an integer, performs a single comparison, and prints a string. These operations take constant time, regardless of the value of `X`. If there are `T` test cases, the total time complexity will be $O(T)$.
-   **Space Complexity**: $O(1)$.
    The program uses a few integer variables (`X`, `T`) to store input and loop counters. The amount of memory used does not depend on the input values or the number of test cases (beyond the fixed number of variables).

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

using namespace std; // Use standard namespace

// Function to solve a single test case
void solve() {
    int X;
    cin >> X; // Read the seat number X

    // Determine the nearest exit based on the seat number X.
    // The midpoint between seat 1 and seat 100 is 50.5.
    // Seats 1 through 50 are closer to seat 1 (LEFT exit).
    // Seats 51 through 100 are closer to seat 100 (RIGHT exit).
    if (X <= 50) {
        cout << "LEFT\n"; // Passenger chooses the exit beside seat 1
    } else {
        cout << "RIGHT\n"; // Passenger chooses the exit beside seat 100
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin/cout from the C standard I/O library and
    // prevents flushing cout before each cin.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times for each test case
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```