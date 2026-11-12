# [Cooling Conundrum (COOLCON)](https://www.codechef.com/problems/COOLCON)
- **Difficulty Rating**: 608
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the total time required to cool a substance from an initial temperature `X` to a final temperature `Y`. The cooling process follows a specific rule: to reduce the temperature by 1 degree Celsius, it takes `ceil(current_temperature / 10)` seconds. We need to find the sum of seconds required for each 1-degree reduction until the temperature reaches `Y`.

## Intuition & Mathematical Observation

The core of the problem lies in simulating the cooling process step-by-step. Since the time taken to reduce the temperature by 1 degree depends on the *current* temperature, we cannot simply use a direct formula for the total time. Instead, we must iterate through each degree reduction.

1.  **Iterative Approach**: We start with the `current_temp` equal to `X`. We then repeatedly perform the following steps until `current_temp` becomes `Y`:
    *   Calculate the time needed to reduce the temperature by 1 degree from the `current_temp`.
    *   Add this time to a running total.
    *   Decrement `current_temp` by 1.

2.  **Ceiling Function Implementation**: The problem states that the time taken is `ceil(current_temperature / 10)`. In integer arithmetic, for positive integers `A` and `B`, `ceil(A / B)` can be computed as `(A + B - 1) / B`.
    *   In our case, `A = current_temp` and `B = 10`.
    *   So, `ceil(current_temp / 10)` becomes `(current_temp + 10 - 1) / 10`, which simplifies to `(current_temp + 9) / 10`. This is an efficient way to calculate the ceiling without using floating-point numbers.

3.  **Data Type for Total Seconds**: The maximum initial temperature `X` is 1000. If `X=1000` and `Y=0`, we perform 1000 steps. The maximum time for a single step (when `current_temp = 1000`) is `ceil(1000/10) = 100` seconds. The minimum time for a single step (when `current_temp = 1` to `10`) is `ceil(1/10)` to `ceil(10/10)`, which is 1 second.
    *   The total time would be roughly `1000 * (average time per step)`.
    *   A loose upper bound: `1000 * 100 = 100,000`.
    *   An `int` data type (which typically holds values up to 2 * 10^9) is sufficient for `total_seconds`. However, using `long long` (as in the provided solution) is a safe practice in competitive programming to prevent potential overflows, even if not strictly necessary for these constraints.

By combining these observations, we arrive at the straightforward simulation loop presented in the solution code.

## Complexity Analysis

-   **Time Complexity**:
    *   The program has an outer loop that runs `T` times for the number of test cases.
    *   Inside each test case, there's a `while` loop that iterates as long as `current_temp > Y`. This loop runs `X - Y` times.
    *   Within this inner loop, all operations (arithmetic, assignment) are constant time, $O(1)$.
    *   Therefore, the time complexity for a single test case is $O(X - Y)$.
    *   The total time complexity across all test cases is $O(T \cdot (X - Y))$.
    *   Given `T <= 100` and `X, Y <= 1000`, the maximum number of operations would be approximately `100 * (1000 - 0) = 100,000`. This is well within typical time limits for competitive programming (usually around $10^8$ operations per second).

-   **Space Complexity**:
    *   The solution uses a fixed number of variables (`T`, `X`, `Y`, `total_seconds`, `current_temp`, `time_needed_for_decrement`).
    *   The memory used by these variables does not depend on the input values `X` or `Y`.
    *   Therefore, the space complexity is $O(1)$ (constant space).

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries as per problem instructions

using namespace std; // Brings all names from the std namespace into the current scope

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from C's stdio and prevents flushing cout before cin.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int X, Y; // Variables to store initial and final temperatures
        cin >> X >> Y; // Read X and Y for the current test case

        long long total_seconds = 0; // Accumulator for total time, initialized to 0.
                                     // Using long long to be safe, though int would suffice for given constraints.
        int current_temp = X;        // Start cooling from the initial temperature X

        // Loop as long as the current temperature is above the target temperature Y
        while (current_temp > Y) {
            // Calculate the time needed to reduce the temperature by 1 degree.
            // The formula is ceil(current_temp / 10).
            // In integer arithmetic, ceil(A / B) for positive A, B is (A + B - 1) / B.
            // For A = current_temp and B = 10, this becomes (current_temp + 10 - 1) / 10,
            // which simplifies to (current_temp + 9) / 10.
            int time_needed_for_decrement = (current_temp + 9) / 10;

            // Add the calculated time for this 1-degree reduction to the total
            total_seconds += time_needed_for_decrement;

            // Decrease the temperature by 1 degree for the next iteration
            current_temp--;
        }

        // Output the total time calculated for the current test case, followed by a newline
        cout << total_seconds << "\n";
    }

    return 0; // Indicate successful program execution
}
```