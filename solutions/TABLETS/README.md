# [Multivitamin Tablets (TABLETS)](https://www.codechef.com/problems/TABLETS)
- **Difficulty Rating**: 376
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if Chef has enough multivitamin tablets for a specified number of days. Chef needs to take 3 tablets every day. We are given two integers for each test case:
1.  `X`: The number of days Chef needs to take tablets.
2.  `Y`: The number of tablets Chef currently has.

We need to output "YES" if Chef has enough tablets for `X` days, and "NO" otherwise.

## Intuition & Mathematical Observation

The core of this problem lies in a simple calculation and comparison.

1.  **Daily Requirement**: Chef takes 3 tablets per day.
2.  **Total Requirement**: If Chef needs to take tablets for `X` days, the total number of tablets required over these `X` days will be `3 * X`.
3.  **Comparison**: We then compare the total tablets Chef needs (`3 * X`) with the tablets Chef already has (`Y`).
    *   If `Y` is greater than or equal to `3 * X` (i.e., `Y >= 3 * X`), Chef has enough tablets. In this case, the answer is "YES".
    *   If `Y` is less than `3 * X` (i.e., `Y < 3 * X`), Chef does not have enough tablets. In this case, the answer is "NO".

This logic is applied independently for each test case.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    *   The program reads `T` test cases.
    *   For each test case, it performs a constant number of operations: reading two integers (`X`, `Y`), one multiplication (`3 * X`), one comparison (`Y >= tablets_needed`), and one print operation.
    *   Since each test case takes $O(1)$ time, and there are `T` test cases, the total time complexity is $O(T \times 1) = O(T)$.

*   **Space Complexity**: $O(1)$
    *   The program uses a fixed number of integer variables (`T`, `X`, `Y`, `tablets_needed`) regardless of the input values or the number of test cases.
    *   No dynamic data structures (like arrays or vectors) are used that would scale with input size.
    *   Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries, as requested
using namespace std;       // Uses the standard namespace, as requested

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from the C standard streams and disables synchronization
    // with C's stdio, making input/output operations faster.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int X, Y; // Declare integer variables X and Y for each test case.
                  // X: number of days Chef needs to take tablets.
                  // Y: number of tablets Chef already has.
        cin >> X >> Y; // Read X and Y for the current test case.

        // Calculate the total number of tablets Chef needs.
        // Chef takes 3 tablets a day for X days.
        int tablets_needed = 3 * X;

        // Compare the tablets Chef has (Y) with the tablets Chef needs (tablets_needed).
        // If Chef has enough or more tablets, output "YES".
        // Otherwise, output "NO".
        if (Y >= tablets_needed) {
            cout << "YES\n"; // Output "YES" followed by a newline.
        } else {
            cout << "NO\n"; // Output "NO" followed by a newline.
        }
    }

    return 0; // Indicate successful program execution.
}
```