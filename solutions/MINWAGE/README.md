# [Minimum Wage (MINWAGE)](https://www.codechef.com/problems/MINWAGE)
- **Difficulty Rating**: 247
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if Chef's income per hour is strictly greater than the minimum wage in Chefland. The minimum wage is fixed at 11 dollars per hour. We are given Chef's income per hour, `X`, and we need to output "YES" if `X` is strictly greater than 11, and "NO" otherwise.

## Intuition & Mathematical Observation

This is a very straightforward problem that requires a direct comparison. The core of the problem lies in understanding the phrase "strictly above the minimum wage".

1.  **Minimum Wage**: The problem explicitly states that the minimum wage in Chefland is 11 dollars per hour.
2.  **Chef's Income**: We are given Chef's income per hour as `X`.
3.  **Condition**: We need to check if Chef's income `X` is "strictly above" the minimum wage (11).
    *   "Strictly above" means `X` must be greater than 11, not equal to or less than 11.
    *   Mathematically, this translates to the condition `X > 11`.

Based on this, our logic will be:
*   If `X > 11`, then Chef's income is strictly above the minimum wage, so we output "YES".
*   Otherwise (if `X <= 11`), Chef's income is not strictly above the minimum wage, so we output "NO".

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    The program performs a fixed number of operations regardless of the input value `X`. It involves reading one integer, performing a single comparison, and printing a string. All these operations take constant time.
*   **Space Complexity**: $O(1)$
    The program uses a constant amount of memory to store a single integer variable `X`. No data structures are used that scale with input size.

## Solution Code

```cpp
#include <bits/stdc++.h> // Include all standard libraries

using namespace std; // Use standard namespace

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from the C standard streams and prevents flushing
    // of cout before cin, leading to faster input/output operations.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare an integer variable X to store Chef's income per hour.
    int X;

    // Read the input value for X from standard input.
    // According to the problem statement, X is on the first and only line.
    cin >> X;

    // The minimum wage in Chefland is 11 dollars per hour.
    // We need to check if Chef's income X is strictly above the minimum wage.
    // This translates to the condition X > 11.
    if (X > 11) {
        // If X is strictly greater than 11, output "YES".
        // Use "\n" for a newline character as required.
        cout << "YES\n";
    } else {
        // Otherwise (if X is 11 or less), output "NO".
        cout << "NO\n";
    }

    // Return 0 to indicate successful program execution.
    return 0;
}
```