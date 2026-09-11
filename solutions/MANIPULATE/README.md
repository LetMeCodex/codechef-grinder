# [Ezio and Guards (MANIPULATE)](https://www.codechef.com/problems/MANIPULATE)
- **Difficulty Rating**: 427
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if Ezio can manipulate all guards given his manipulation capacity. Ezio has a manipulation capacity of `X`, meaning he can manipulate at most `X` guards. There are a total of `Y` guards. We need to output "YES" if Ezio can manipulate all `Y` guards, and "NO" otherwise. This needs to be done for `T` test cases.

## Intuition & Mathematical Observation

Ezio's manipulation capacity `X` represents the maximum number of guards he can control. If there are `Y` guards in total, Ezio can successfully manipulate *all* of them only if his capacity `X` is sufficient to cover all `Y` guards.

This leads to a direct comparison:
*   If Ezio's capacity `X` is greater than or equal to the total number of guards `Y` (i.e., `X >= Y`), then he has enough capacity to manipulate all `Y` guards. In this case, the answer is "YES".
*   If Ezio's capacity `X` is less than the total number of guards `Y` (i.e., `X < Y`), then he does not have enough capacity to manipulate all `Y` guards. In this case, the answer is "NO".

This is a straightforward conditional check.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    *   The program reads the number of test cases `T` once.
    *   It then enters a `while` loop that iterates `T` times.
    *   Inside the loop, for each test case, it performs a constant number of operations: reading two integers (`X` and `Y`), one comparison (`X >= Y`), and printing a string ("YES" or "NO").
    *   Since the operations inside the loop take constant time, the total time complexity is directly proportional to the number of test cases, `T`.
*   **Space Complexity**: $O(1)$
    *   The program uses a fixed number of integer variables (`T`, `X`, `Y`) to store input and loop counters.
    *   The memory used by these variables does not depend on the input values `T`, `X`, or `Y` (beyond the fixed size of an integer).
    *   No dynamic data structures or arrays are used that would scale with input size.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard library headers

// Using the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases
    cin >> T; // Read the number of test cases from standard input

    // Loop T times, once for each test case
    while (T--) {
        int X, Y; // Declare integer variables X and Y for the current test case
        cin >> X >> Y; // Read X (Ezio's manipulation capacity) and Y (total guards)

        // Ezio can manipulate at most X guards.
        // To manipulate all Y guards, his capacity X must be
        // greater than or equal to the number of guards Y.
        if (X >= Y) {
            // If X is greater than or equal to Y, Ezio can manipulate all guards.
            cout << "YES\n"; // Print "YES" followed by a newline
        } else {
            // Otherwise, Ezio cannot manipulate all guards.
            cout << "NO\n"; // Print "NO" followed by a newline
        }
    }

    return 0; // Indicate successful program execution
}
```