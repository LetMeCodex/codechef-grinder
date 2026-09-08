# [Masterchef finals (TOP10)](https://www.codechef.com/problems/TOP10)
- **Difficulty Rating**: 255
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if Chef has made it to the "top 10" in the Masterchef finals. We are given Chef's rank, `X`, for a specific test case. We need to output "YES" if Chef's rank is among the top 10 (i.e., 1st, 2nd, ..., up to 10th), and "NO" otherwise. This process needs to be repeated for `T` independent test cases.

## Intuition & Mathematical Observation

The core of this problem lies in understanding what "top 10" means in terms of rank. In competitive scenarios, a lower rank number indicates a better position. For Chef to be in the "top 10", their rank `X` must be one of the following: 1, 2, 3, 4, 5, 6, 7, 8, 9, or 10.

Mathematically, this condition can be expressed as:
`X <= 10`

If Chef's rank `X` satisfies this inequality, then Chef is in the top 10, and we should output "YES". Otherwise, if `X` is greater than 10 (e.g., 11, 12, etc.), Chef is not in the top 10, and we should output "NO".

The problem is a straightforward conditional check based on this simple observation.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    -   The program reads the number of test cases, `T`.
    -   Inside the `while (T--)` loop, for each test case:
        -   It reads an integer `X` ($O(1)$ operation).
        -   It performs a single comparison `X <= 10` ($O(1)$ operation).
        -   It prints a short string ("YES" or "NO") ($O(1)$ operation).
    -   Since these constant-time operations are performed `T` times, the total time complexity is directly proportional to the number of test cases, $O(T)$. The `ios_base::sync_with_stdio(false); cin.tie(NULL);` lines contribute $O(1)$ to the overall time.

-   **Space Complexity**: $O(1)$
    -   The program uses a few integer variables (`T`, `X`) to store input and loop counters. The memory required for these variables is constant and does not depend on the input values or the number of test cases.
    -   Therefore, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Using the standard namespace to avoid typing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can speed up I/O operations significantly.
    // cin.tie(NULL) prevents cout from flushing before cin reads input,
    // further optimizing I/O, especially in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable 'T' to store the number of test cases.
    cin >> T; // Read the value of 'T' from standard input.

    // Loop 'T' times, once for each test case.
    // The 'T--' decrements T after each iteration, and the loop continues as long as T is greater than 0.
    while (T--) {
        int X; // Declare an integer variable 'X' to store Chef's rank for the current test case.
        cin >> X; // Read the value of 'X' from standard input.

        // Check if Chef's rank 'X' is less than or equal to 10.
        // If the rank is 10 or less, Chef made it to the top 10.
        if (X <= 10) {
            cout << "YES\n"; // Output "YES" followed by a newline character.
        } else {
            // If Chef's rank is greater than 10, Chef did not make it to the top 10.
            cout << "NO\n"; // Output "NO" followed by a newline character.
        }
    }

    return 0; // Indicate that the program executed successfully.
}
```