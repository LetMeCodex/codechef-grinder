# [Hattrick (HATTRICK)](https://www.codechef.com/problems/HATTRICK)
- **Difficulty Rating**: 853
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a bowler has achieved a "hattrick" in a single over of cricket. An over consists of 6 balls. A hattrick is defined as taking three wickets in three consecutive balls. The outcome of each ball is given as input, which can be either an integer (representing runs scored) or 'W' (representing a wicket). We need to output "YES" if a hattrick is achieved and "NO" otherwise.

## Intuition & Mathematical Observation

The core of the problem lies in identifying three consecutive 'W's within the sequence of 6 ball outcomes. Since an over has exactly 6 balls, we can represent the outcomes as an array or list of 6 elements.

Let the outcomes of the 6 balls be $s_0, s_1, s_2, s_3, s_4, s_5$.
A hattrick occurs if any of the following conditions are met:
1.  $s_0 = 'W'$ AND $s_1 = 'W'$ AND $s_2 = 'W'$ (Balls 1, 2, 3)
2.  $s_1 = 'W'$ AND $s_2 = 'W'$ AND $s_3 = 'W'$ (Balls 2, 3, 4)
3.  $s_2 = 'W'$ AND $s_3 = 'W'$ AND $s_4 = 'W'$ (Balls 3, 4, 5)
4.  $s_3 = 'W'$ AND $s_4 = 'W'$ AND $s_5 = 'W'$ (Balls 4, 5, 6)

If any of these four conditions are true, then a hattrick has occurred. Otherwise, it has not. The problem involves multiple test cases, so we need to read the number of test cases and process each one independently.

The input for each test case consists of 6 strings, each representing the outcome of a ball. We can store these in an array of strings.

## Complexity Analysis

-   **Time Complexity**: $O(1)$ per test case.
    For each test case, we read 6 strings and perform a fixed number of comparisons (at most 4 sets of 3 comparisons). This is a constant number of operations, independent of the input size (beyond the fixed 6 balls). If there are $T$ test cases, the total time complexity is $O(T)$.

-   **Space Complexity**: $O(1)$ per test case.
    We use a fixed-size array of 6 strings to store the ball outcomes. This requires a constant amount of memory, regardless of the input values.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries, as requested by the problem statement.

// Using the standard namespace as requested by the problem statement.
using namespace std;

// Function to solve a single test case.
void solve() {
    // Declare an array of 6 strings to store the outcomes of the 6 balls.
    // Each outcome can be an integer (e.g., "1", "2") or "W".
    string s[6];
    // Read the outcomes for the 6 balls from standard input.
    for (int i = 0; i < 6; ++i) {
        cin >> s[i];
    }

    // Check for a hattrick. A hattrick occurs if three consecutive balls result in a 'W' (wicket).
    // There are four possible sequences of three consecutive balls in a 6-ball over:
    // 1. Balls at indices 0, 1, 2 (corresponding to A, B, C)
    // 2. Balls at indices 1, 2, 3 (corresponding to B, C, D)
    // 3. Balls at indices 2, 3, 4 (corresponding to C, D, E)
    // 4. Balls at indices 3, 4, 5 (corresponding to D, E, F)
    // We use logical OR (||) to check if any of these conditions are true.
    if ((s[0] == "W" && s[1] == "W" && s[2] == "W") || // Check for hattrick with balls A, B, C
        (s[1] == "W" && s[2] == "W" && s[3] == "W") || // Check for hattrick with balls B, C, D
        (s[2] == "W" && s[3] == "W" && s[4] == "W") || // Check for hattrick with balls C, D, E
        (s[3] == "W" && s[4] == "W" && s[5] == "W")) { // Check for hattrick with balls D, E, F
        // If any of the hattrick conditions are met, print "YES".
        cout << "YES\n";
    } else {
        // Otherwise, no hattrick was found in this over, so print "NO".
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // This is a common practice in competitive programming to prevent TLE (Time Limit Exceeded)
    // on problems with large input/output.
    ios_base::sync_with_stdio(false); // Unties C++ standard streams from C standard streams.
    cin.tie(NULL);                    // Prevents cin from flushing cout before each input operation.

    int t; // Variable to store the number of test cases.
    cin >> t; // Read the number of test cases from standard input.
    // Loop through each test case.
    while (t--) {
        solve(); // Call the solve function to process each test case.
    }

    return 0; // Indicate successful program execution.
}
```