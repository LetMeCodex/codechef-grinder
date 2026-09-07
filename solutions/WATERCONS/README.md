# [Water Consumption (WATERCONS)](https://www.codechef.com/problems/WATERCONS)
- **Difficulty Rating**: 254
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if Chef has consumed a sufficient amount of water according to a doctor's advice. The doctor advised Chef to drink **at least 2000 ml** of water daily. We are given the actual amount of water, `X` ml, that Chef drank on a particular day. Our task is to output "YES" if Chef drank 2000 ml or more, and "NO" otherwise. This needs to be done for multiple test cases.

## Intuition & Mathematical Observation

The problem statement directly provides the condition for sufficient water consumption: "at least 2000 ml". In mathematical terms, "at least" translates to "greater than or equal to". Therefore, if Chef drank `X` ml of water, we simply need to check if `X >= 2000`.

*   If `X` is 2000 or greater, Chef followed the advice, and the answer is "YES".
*   If `X` is less than 2000, Chef did not follow the advice, and the answer is "NO".

This is a straightforward conditional check without any complex mathematical operations or data structures required.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    *   The program first reads the number of test cases, `T`.
    *   It then enters a loop that iterates `T` times.
    *   Inside the loop, for each test case, it performs a constant number of operations: reading an integer `X`, performing a single comparison (`X >= 2000`), and printing a string ("YES" or "NO").
    *   Since each operation inside the loop takes constant time, the total time complexity is directly proportional to the number of test cases, `T`.

*   **Space Complexity**: $O(1)$
    *   The program uses a few integer variables (`T`, `X`) to store input and loop counters. These variables occupy a fixed amount of memory regardless of the input values or the number of test cases.
    *   No dynamic data structures or arrays whose size depends on the input are used.
    *   Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

using namespace std; // Use standard namespace

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from C's stdio and prevents flushing cout before cin.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare variable for the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int X; // Declare variable for the amount of water Chef drank
        cin >> X; // Read the amount of water X

        // The doctor advised Chef to drink at least 2000 ml of water.
        // We check if the amount X Chef drank is greater than or equal to 2000.
        if (X >= 2000) {
            cout << "YES\n"; // If Chef drank 2000 ml or more, print YES
        } else {
            cout << "NO\n"; // Otherwise (if Chef drank less than 2000 ml), print NO
        }
    }

    return 0; // Indicate successful execution
}
```