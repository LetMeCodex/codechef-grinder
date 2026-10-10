# [Maximum Production (EITA)](https://www.codechef.com/problems/EITA)
- **Difficulty Rating**: 833
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the maximum possible total production over a 7-day week, given two different production strategies.

1.  **Strategy 1**: Produce `x` units of work every day for all 7 days.
2.  **Strategy 2**: Produce `y` units of work for the first `d` days, and then `z` units of work for the remaining `7 - d` days.

We need to calculate the total production for both strategies and output the higher of the two values.

## Intuition & Mathematical Observation

The problem is a straightforward comparison between two distinct methods of calculating total production. We simply need to apply the given formulas for each strategy and then find the maximum of the two results.

Let's break down the calculation for each strategy:

1.  **Strategy 1 Total Production**:
    If `x` units are produced each day for 7 days, the total production is simply `x * 7`.

2.  **Strategy 2 Total Production**:
    This strategy involves two phases:
    *   For the first `d` days, `y` units are produced per day. Total production in this phase: `y * d`.
    *   For the remaining days, `z` units are produced per day. The number of remaining days is `7 - d`. Total production in this phase: `z * (7 - d)`.
    *   Combining these, the total production for Strategy 2 is `(y * d) + (z * (7 - d))`.

Once we have calculated the total production for both strategies, we simply take the maximum of these two values.

`Maximum Production = max( (x * 7), (y * d + z * (7 - d)) )`

The constraints on `x, y, z` are up to 100, and `d` is between 1 and 7. The maximum possible production would be `100 * 7 = 700`. This value fits comfortably within a standard `int` data type. However, using `long long` for calculations is a good practice in competitive programming to prevent potential overflow issues, even if not strictly necessary for these specific constraints.

## Complexity Analysis

*   **Time Complexity**: $O(1)$ per test case.
    For each test case, we perform a fixed number of arithmetic operations (multiplications, additions) and a comparison. These operations take constant time. If there are `T` test cases, the total time complexity will be $O(T)$.
*   **Space Complexity**: $O(1)$.
    We only use a few variables to store the input values (`d, x, y, z`) and the calculated production for each strategy. The amount of memory used does not depend on the input values (other than the number of test cases), making it constant space.

## Solution Code

```cpp
#include <iostream> // Required for input/output operations (std::cin, std::cout)
#include <algorithm> // Required for std::max

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Variable to store the number of test cases
    std::cin >> t; // Read the number of test cases

    // Loop through each test case
    while (t--) {
        int d, x, y, z; // Variables to store input for the current test case
        std::cin >> d >> x >> y >> z; // Read d, x, y, z

        // Strategy 1: x units of work every day for 7 days
        // Calculate total work for strategy 1. Using long long to be safe,
        // though int would suffice for these constraints.
        long long strategy1_work = (long long)x * 7;

        // Strategy 2: y units of work for the first d days, then z units for the remaining days
        // Number of remaining days = 7 - d
        // Calculate total work for strategy 2.
        long long strategy2_work = (long long)y * d + (long long)z * (7 - d);

        // The maximum work is the maximum of the two strategies
        long long max_work = std::max(strategy1_work, strategy2_work);

        // Print the maximum work followed by a newline character
        std::cout << max_work << "\n";
    }

    return 0; // Indicate successful execution
}

```