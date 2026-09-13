# [Water Requirement (WATERREQ)](https://www.codechef.com/problems/WATERREQ)
- **Difficulty Rating**: 351
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the total amount of water required for a water cooler. We are given that the water cooler needs 2 liters of water per hour. We need to find out how much water is required if the cooler runs for `N` hours. This calculation needs to be performed for multiple test cases.

## Intuition & Mathematical Observation

The problem statement provides a very direct relationship: the water cooler consumes 2 liters of water for every hour it operates.
If the cooler operates for `N` hours, the total water required will simply be `N` times the hourly requirement.

Mathematically, this can be expressed as:
`Total Water Required = N * 2`

Given the constraints on `N` (1 <= N <= 1000), the maximum water required would be `1000 * 2 = 2000` liters. This value easily fits within a standard integer data type, so there's no concern about overflow. The solution simply involves reading `N` and printing `2 * N`.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    *   The program reads `T` test cases.
    *   For each test case, it performs a constant number of operations: reading an integer `N`, performing a multiplication (`2 * N`), and printing the result. Each of these operations takes constant time, $O(1)$.
    *   Therefore, the total time complexity is proportional to the number of test cases, $T$, resulting in $O(T)$.

-   **Space Complexity**: $O(1)$
    *   The program uses a few variables (`t`, `n`) to store input and intermediate results. The memory usage for these variables is constant and does not depend on the input size `N` or the number of test cases `T`.
    *   Thus, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common C++ headers

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Declare an integer variable 't' for the number of test cases
    cin >> t; // Read the number of test cases

    // Loop through each test case
    while (t--) {
        int n; // Declare an integer variable 'n' for the number of hours
        cin >> n; // Read the number of hours for the current test case

        // The problem states the water cooler requires 2 liters of water per hour.
        // For N hours, the total water required is 2 * N liters.
        // Constraints: 1 <= N <= 1000.
        // The maximum result will be 2 * 1000 = 2000, which fits within an int.
        cout << 2 * n << "\n"; // Calculate and print the total water required, followed by a newline
    }

    return 0; // Indicate successful program execution
}

```