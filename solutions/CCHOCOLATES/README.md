# [Chef and Chocolates (CCHOCOLATES)](https://www.codechef.com/problems/CCHOCOLATES)
- **Difficulty Rating**: 405
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the maximum number of chocolates Chef can buy. Chef has `X` 5-rupee coins and `Y` 10-rupee coins. Each chocolate costs `Z` rupees. We need to find out how many chocolates Chef can afford in total.

## Intuition & Mathematical Observation

The core idea is to first determine the total amount of money Chef possesses and then divide that total by the cost of a single chocolate.

1.  **Calculate total money from 5-rupee coins**: If Chef has `X` 5-rupee coins, the total money from these coins will be `X * 5`.
2.  **Calculate total money from 10-rupee coins**: Similarly, if Chef has `Y` 10-rupee coins, the total money from these coins will be `Y * 10`.
3.  **Calculate overall total money**: The sum of money from both types of coins gives the `total_rupees` Chef has: `total_rupees = (X * 5) + (Y * 10)`.
4.  **Calculate maximum chocolates**: Since each chocolate costs `Z` rupees, the maximum number of chocolates Chef can buy is `total_rupees / Z`. We use integer division here because Chef cannot buy fractions of a chocolate.

The solution directly implements these steps.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    *   For each test case, the solution performs a few constant-time arithmetic operations (multiplications, additions, division) and input/output operations. These operations take $O(1)$ time.
    *   Since there are $T$ test cases, the total time complexity is $O(T)$.
-   **Space Complexity**: $O(1)$
    *   The solution only uses a fixed number of variables (`t`, `x`, `y`, `z`, `total_rupees`, `max_chocolates`) to store input and intermediate results. The memory usage does not depend on the input size.

## Solution Code

```cpp
#include <iostream>
#include <algorithm> // Not strictly necessary for this problem, but often included by default.

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from being flushed before each std::cin operation.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases

    while (t--) { // Loop through each test case
        long long x, y, z; // Declare variables for 5-rupee coins, 10-rupee coins, and chocolate cost.
                           // Using long long to prevent potential overflow for total_rupees,
                           // though for given constraints (X, Y, Z <= 1000), int would also suffice.
        std::cin >> x >> y >> z; // Read the values for the current test case

        // Calculate the total money Chef has
        long long total_rupees = x * 5 + y * 10;

        // Calculate the maximum number of chocolates Chef can buy using integer division
        long long max_chocolates = total_rupees / z;

        // Print the result followed by a newline character
        std::cout << max_chocolates << "\n";
    }

    return 0; // Indicate successful execution
}

```