# [Reach the Target (REACHTARGET)](https://www.codechef.com/problems/REACHTARGET)
- **Difficulty Rating**: 281
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the number of additional runs Team B needs to score to reach a specific target score. We are given the target score `X` and Team B's current score `Y`. This calculation needs to be performed for `T` independent test cases.

## Intuition & Mathematical Observation

This problem is a very basic arithmetic task. If Team B's goal is to achieve `X` runs and they have already scored `Y` runs, the number of runs they still need to score is simply the difference between the target score and their current score.

Mathematically, the runs needed can be expressed as:
`runs_needed = X - Y`

There are no complex algorithms, data structures, or advanced mathematical concepts required. It's a direct application of subtraction.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    *   The program performs a constant number of operations (reading two integers, one subtraction, and printing one integer) for each of the `T` test cases.
    *   The `ios_base::sync_with_stdio(false); cin.tie(NULL);` lines optimize I/O but take constant time.
    *   Therefore, the total time taken is directly proportional to the number of test cases, `T`.

*   **Space Complexity**: $O(1)$
    *   The program uses a fixed number of integer variables (`T`, `X`, `Y`, `runs_needed`) regardless of the input values or the number of test cases.
    *   No arrays, vectors, or other data structures whose size depends on the input are used.
    *   Thus, the memory usage remains constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries, as requested
using namespace std;       // Uses the standard namespace, as requested

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from C's stdio and prevents synchronization with cout.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    // T-- decrements T after each iteration, and the loop continues as long as T is positive.
    while (T--) {
        int X, Y; // Declare integer variables X (target score) and Y (current score).
        cin >> X >> Y; // Read X and Y for the current test case.

        // Calculate the number of runs Team B needs to score to win.
        // To win, Team B must reach X runs. They currently have Y runs.
        // So, they need X - Y more runs.
        int runs_needed = X - Y;

        // Print the calculated runs_needed to standard output, followed by a newline character.
        cout << runs_needed << "\n";
    }

    return 0; // Indicate successful program execution.
}
```