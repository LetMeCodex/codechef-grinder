# Spice Level (KITCHENSPICE)

- **Difficulty Rating**: 390
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to categorize a given spice level, represented by an integer `X`, into one of three categories: "MILD", "MEDIUM", or "HOT". The rules for categorization are as follows:
- If `X` is less than 4, it's "MILD".
- If `X` is greater than or equal to 4 but less than 7, it's "MEDIUM".
- If `X` is greater than or equal to 7, it's "HOT".

We are given `T` test cases, and for each test case, we need to read the spice level `X` and print the corresponding category.

## Intuition & Mathematical Observation

The problem is a straightforward application of conditional logic. We are given clear thresholds for each category. The core of the solution involves checking the value of `X` against these thresholds in a specific order.

The mathematical observation is that the conditions are mutually exclusive and cover all possible integer values of `X` (assuming `X` is non-negative, which is typical for spice levels).

1.  **MILD**: `X < 4`
2.  **MEDIUM**: `4 <= X < 7`
3.  **HOT**: `X >= 7`

We can implement this using a series of `if-else if-else` statements. The order of checks is important for efficiency and correctness.

- First, check if `X < 4`. If true, it's "MILD".
- If the first condition is false (meaning `X >= 4`), then check if `X < 7`. If true, it's "MEDIUM". This implicitly covers the range `4 <= X < 7`.
- If both the above conditions are false (meaning `X >= 4` and `X >= 7`), then `X` must be `X >= 7`, so it's "HOT".

This sequential checking ensures that each `X` falls into exactly one category.

## Complexity Analysis

- **Time Complexity**: $O(1)$
    For each test case, we perform a constant number of comparisons and input/output operations. Since the number of operations does not depend on the input value `X` (other than its magnitude, which is bounded by integer types), the time complexity per test case is constant. If there are `T` test cases, the total time complexity is $O(T)$.

- **Space Complexity**: $O(1)$
    We only use a few variables to store the input `X` and the number of test cases `T`. The memory usage is constant and does not grow with the input size.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries, as requested.

// Using the standard namespace, as requested.
using namespace std;

// Function to solve a single test case.
void solve() {
    int X; // Declare an integer variable X for the spice level.
    cin >> X; // Read the spice level X from standard input.

    // Apply the categorization rules using if-else if-else statements.
    // The conditions are checked in order.
    if (X < 4) {
        // If the spice level is strictly less than 4, it's MILD.
        cout << "MILD\n";
    } else if (X < 7) {
        // If the previous condition (X < 4) was false, it means X >= 4.
        // So, if X is also strictly less than 7, it falls into the MEDIUM category.
        // This covers the range 4 <= X < 7.
        cout << "MEDIUM\n";
    } else {
        // If neither of the above conditions were met, it means X is not less than 4
        // AND X is not less than 7. This implies X must be greater than or equal to 7.
        // Thus, it's in the HOT category.
        cout << "HOT\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases.
    cin >> T; // Read the number of test cases.

    // Loop T times, calling the solve function for each test case.
    while (T--) {
        solve();
    }

    return 0; // Indicate successful execution of the program.
}
```