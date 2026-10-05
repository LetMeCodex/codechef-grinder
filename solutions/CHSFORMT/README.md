# [Chess Format (CHSFORMT)](https://www.codechef.com/problems/CHSFORMT)
- **Difficulty Rating**: 844
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the format of a chess game based on the sum of two given integers, `a` and `b`. The rules for determining the format are as follows:
1. If `a + b < 3`, it's a Bullet game (output `1`).
2. If `3 <= a + b <= 10`, it's a Blitz game (output `2`).
3. If `11 <= a + b <= 60`, it's a Rapid game (output `3`).
4. If `60 < a + b`, it's a Classical game (output `4`).

We need to process `T` test cases, and for each test case, read `a` and `b`, calculate their sum, and print the corresponding format number.

## Intuition & Mathematical Observation

The problem is a direct application of conditional logic. We are given clear, mutually exclusive ranges for the sum `a + b`, each corresponding to a specific chess format. The task boils down to:
1. Reading the two input integers, `a` and `b`.
2. Calculating their sum, `a + b`.
3. Using a series of `if-else if-else` statements to check which range the calculated sum falls into.
4. Printing the integer (1, 2, 3, or 4) that corresponds to the identified format.

There are no complex algorithms, data structures, or mathematical insights required beyond basic arithmetic and conditional branching. The conditions are exhaustive, covering all possible positive integer sums.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    For each test case, we perform a constant number of operations: reading two integers, one addition, a few comparisons, and one print operation. Each of these operations takes constant time, $O(1)$. Since there are $T$ test cases, the total time complexity is $T \times O(1) = O(T)$.

-   **Space Complexity**: $O(1)$
    We only use a few integer variables (`T`, `a`, `b`, `sum`) to store the number of test cases, input values, and their sum. The amount of memory used is constant and does not depend on the magnitude of `a` or `b`, or the number of test cases (as they are processed iteratively). Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin/cout from C's stdio and prevents flushing cout before cin.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare variable for the number of testcases
    cin >> T; // Read the number of testcases

    // Loop through each testcase
    while (T--) {
        int a, b; // Declare variables for a and b
        cin >> a >> b; // Read a and b for the current testcase

        int sum = a + b; // Calculate the sum a + b

        // Apply the given conditions to determine the format
        if (sum < 3) {
            cout << 1 << "\n"; // Bullet format: a + b < 3
        } else if (sum <= 10) { // Blitz format: 3 <= a + b <= 10
            // This condition is reached if sum >= 3 (from previous if failing)
            // and sum <= 10.
            cout << 2 << "\n";
        } else if (sum <= 60) { // Rapid format: 11 <= a + b <= 60
            // This condition is reached if sum > 10 (from previous if failing)
            // and sum <= 60.
            cout << 3 << "\n";
        } else { // Classical format: 60 < a + b
            // This condition is reached if sum > 60 (from previous if failing).
            cout << 4 << "\n";
        }
    }

    return 0; // Indicate successful execution
}
```