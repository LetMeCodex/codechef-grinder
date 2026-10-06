# [HOW MANY DIGITS DO I HAVE (HOWMANY)](https://www.codechef.com/problems/HOWMANY)
- **Difficulty Rating**: 908
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the number of digits in a given non-negative integer `N`. Based on the number of digits, we need to print specific outputs:
- If `N` has 1 digit (i.e., `0 <= N <= 9`), print "1".
- If `N` has 2 digits (i.e., `10 <= N <= 99`), print "2".
- If `N` has 3 digits (i.e., `100 <= N <= 999`), print "3".
- If `N` has more than 3 digits (i.e., `N >= 1000`), print "More than 3 digits".

The input `N` is guaranteed to be between 0 and 1,000,000 (inclusive).

## Intuition & Mathematical Observation

The core idea is to categorize the input number `N` into different ranges based on its magnitude. Each range corresponds to a specific number of digits.

We can observe the following ranges for the number of digits:
1.  **1-digit numbers**: These are integers from 0 to 9. Mathematically, `0 <= N <= 9`.
2.  **2-digit numbers**: These are integers from 10 to 99. Mathematically, `10 <= N <= 99`.
3.  **3-digit numbers**: These are integers from 100 to 999. Mathematically, `100 <= N <= 999`.
4.  **More than 3 digits**: These are integers from 1000 upwards. Given the problem constraints, this range extends up to 1,000,000. Mathematically, `N >= 1000`.

A straightforward approach is to use a series of `if-else if-else` statements. We can check the conditions in increasing order of magnitude:
- First, check if `N` is small enough to be a 1-digit number (`N <= 9`).
- If not, `N` must be `10` or greater. Then, check if it's small enough to be a 2-digit number (`N <= 99`).
- If not, `N` must be `100` or greater. Then, check if it's small enough to be a 3-digit number (`N <= 999`).
- If none of the above conditions are met, `N` must be `1000` or greater, falling into the "More than 3 digits" category.

This conditional logic directly maps to the problem's requirements and efficiently determines the correct output.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The solution involves reading a single integer and then performing a fixed number of comparisons (at most three `if` conditions) and a single print operation. The number of operations does not depend on the magnitude of `N` (within its constraints). Thus, the time taken is constant.

-   **Space Complexity**: $O(1)$
    The solution uses a single integer variable `N` to store the input. This requires a constant amount of memory, irrespective of the value of `N`. Thus, the space used is constant.

## Solution Code

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare an integer variable N to store the input number.
    // The problem constraints state 0 <= N <= 1000000, which fits within a standard 'int'.
    int N;

    // Read the number N from standard input.
    cin >> N;

    // Use a series of if-else if statements to determine the number of digits.
    // The conditions are ordered from smallest to largest number of digits.

    // If N is between 0 and 9 (inclusive), it's a 1-digit number.
    // The condition N <= 9 covers this, as N is guaranteed to be non-negative by constraints.
    if (N <= 9) {
        cout << "1\n";
    }
    // If N is not <= 9, it means N >= 10.
    // If N is also <= 99, then it's a 2-digit number (10 to 99).
    else if (N <= 99) {
        cout << "2\n";
    }
    // If N is not <= 99, it means N >= 100.
    // If N is also <= 999, then it's a 3-digit number (100 to 999).
    else if (N <= 999) {
        cout << "3\n";
    }
    // If none of the above conditions are met, it means N is greater than 999.
    // According to the problem, such numbers have "More than 3 digits".
    // This covers numbers from 1000 up to the maximum constraint of 1000000.
    else {
        cout << "More than 3 digits\n";
    }

    return 0; // Indicate successful program execution.
}
```