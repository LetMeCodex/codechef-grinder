# [Lunchtime (LTIME)](https://www.codechef.com/problems/LTIME)
- **Difficulty Rating**: 352
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a given integer `x` represents a valid "lunchtime" slot. Based on the problem's context and the provided solution, a valid lunchtime slot is defined as any integer `x` that falls within the range of 1 to 4, inclusive. We need to process multiple test cases. For each test case, we read an integer `x` and output "YES" if `x` is between 1 and 4 (inclusive), and "NO" otherwise.

## Intuition & Mathematical Observation

The problem is a straightforward conditional check. There isn't any complex mathematical theory or advanced algorithm required. The core idea is to simply verify if the input number `x` satisfies the given range condition.

The condition for a valid lunchtime slot is:
$1 \le x \le 4$

This can be broken down into two simultaneous conditions:
1. $x \ge 1$
2. $x \le 4$

If both of these conditions are true, then `x` is a valid lunchtime slot, and we print "YES". Otherwise, if either condition is false (i.e., `x` is less than 1, or `x` is greater than 4), then `x` is not a valid slot, and we print "NO".

The solution directly implements this logical check using an `if-else` statement.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    -   The program reads an integer `T` representing the number of test cases.
    -   Inside the `while (T--)` loop, for each test case, it performs the following operations:
        -   Reads an integer `x`: This is an $O(1)$ operation.
        -   Performs a constant number of comparisons (`x >= 1` and `x <= 4`): This is an $O(1)$ operation.
        -   Prints "YES" or "NO": This is an $O(1)$ operation.
    -   Since these constant-time operations are repeated `T` times, the total time complexity is $O(T)$.

-   **Space Complexity**: $O(1)$
    -   The program uses a few integer variables (`t`, `x`) to store input and loop counters.
    -   The amount of memory used does not depend on the input values or the number of test cases `T`. It remains constant regardless of the input size.
    -   Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common C++ headers

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from C's stdio and prevents synchronization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); // Unties cin from cout

    int t; // Declare an integer variable 't' for the number of test cases
    cin >> t; // Read the number of test cases

    // Loop 't' times, processing each test case
    while (t--) {
        int x; // Declare an integer variable 'x' for the current input number
        cin >> x; // Read the integer 'x' for the current test case

        // Check if 'x' is within the valid range [1, 4]
        if (x >= 1 && x <= 4) {
            cout << "YES\n"; // If valid, print "YES" followed by a newline
        } else {
            cout << "NO\n"; // Otherwise, print "NO" followed by a newline
        }
    }

    return 0; // Indicate successful program execution
}

```