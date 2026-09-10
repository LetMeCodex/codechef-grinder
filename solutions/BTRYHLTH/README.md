# [Battery Health (BTRYHLTH)](https://www.codechef.com/problems/BTRYHLTH)
- **Difficulty Rating**: 296
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem "Battery Health" asks us to determine if a given battery health percentage `X` is considered "good". According to the problem statement, a battery is in good health if its percentage is 80% or more. We need to output "YES" if the battery health is good, and "NO" otherwise. This check needs to be performed for multiple test cases.

## Intuition & Mathematical Observation

The core of this problem is a straightforward conditional check. We are given an integer `X` representing the battery health percentage. The problem defines "good health" as `X` being greater than or equal to 80.

Our intuition directly translates to:
1. Read the battery health percentage, `X`.
2. Compare `X` with 80.
3. If `X >= 80`, the condition for good health is met, so we print "YES".
4. Otherwise (if `X < 80`), the condition is not met, so we print "NO".

There are no complex mathematical operations or advanced algorithms required; it's a direct application of an `if-else` statement. The problem primarily tests basic input/output and conditional logic.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    *   The program performs a constant number of operations for each test case: reading an integer `X`, performing a comparison (`X >= 80`), and printing a short string ("YES" or "NO").
    *   Since these operations take constant time, let's denote it as $O(1)$ per test case.
    *   The loop runs `T` times (where `T` is the number of test cases).
    *   Therefore, the total time complexity is $T \times O(1) = O(T)$.

*   **Space Complexity**: $O(1)$
    *   The program uses a few integer variables (`T`, `X`) to store the number of test cases and the battery health percentage.
    *   These variables consume a constant amount of memory, regardless of the input values or the number of test cases.
    *   No dynamic data structures or arrays are used that would scale with input size.
    *   Hence, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

using namespace std; // Uses the standard namespace

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from the C standard streams and prevents flushing
    // of cout before cin operations, leading to faster I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases
    cin >> T; // Read the number of test cases from standard input

    // Loop T times, once for each test case
    while (T--) {
        int X; // Declare an integer variable X for the battery health percentage
        cin >> X; // Read the battery health percentage for the current test case

        // Check if the battery health X is 80% or above
        if (X >= 80) {
            cout << "YES\n"; // If X is 80 or greater, print "YES" followed by a newline
        } else {
            cout << "NO\n"; // Otherwise (if X is less than 80), print "NO" followed by a newline
        }
    }

    return 0; // Indicate successful program execution
}
```