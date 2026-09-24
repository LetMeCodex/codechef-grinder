# [Puppy and Sum (PPSUM)](https://www.codechef.com/problems/PPSUM)
- **Difficulty Rating**: 961
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate a final value based on two given integers, `D` and `N`. We start with the initial value `N`. We then perform an operation `D` times. In each operation, if the current value is `X`, we replace `X` with the sum of all integers from 1 to `X`. Our task is to output the final value after `D` such operations.

For example:
- If `D=1, N=4`: The sum of integers from 1 to 4 is `1+2+3+4 = 10`. The result is 10.
- If `D=2, N=3`:
    1. Start with `N=3`.
    2. First operation: Sum of 1 to 3 is `1+2+3 = 6`. Current value becomes 6.
    3. Second operation: Sum of 1 to 6 is `1+2+3+4+5+6 = 21`. Current value becomes 21.
    The final result is 21.

The constraints are small: `1 <= T <= 1000`, `1 <= D <= 4`, `1 <= N <= 4`.

## Intuition & Mathematical Observation

The core of this problem lies in repeatedly calculating the sum of integers from 1 up to a given number. This is a classic arithmetic series sum, for which a well-known formula exists: the sum of integers from 1 to `X` is `X * (X + 1) / 2`.

The problem simply requires us to apply this formula `D` times. We start with `N`, and in each of the `D` iterations, we update our current value `current_N` using the formula:
`current_N = current_N * (current_N + 1) / 2`

Let's trace the maximum possible value to ensure it fits within standard integer types. The maximum `N` is 4, and maximum `D` is 4.
- Initial `N = 4`
- After 1 operation: `4 * (4 + 1) / 2 = 4 * 5 / 2 = 10`
- After 2 operations: `10 * (10 + 1) / 2 = 10 * 11 / 2 = 55`
- After 3 operations: `55 * (55 + 1) / 2 = 55 * 56 / 2 = 55 * 28 = 1540`
- After 4 operations: `1540 * (1540 + 1) / 2 = 1540 * 1541 / 2 = 770 * 1541 = 1,186,570`

The maximum value `1,186,570` fits comfortably within a 32-bit signed integer (which typically holds values up to `2 * 10^9`). However, using `long long` for `current_N` is a good defensive programming practice in competitive programming to prevent potential overflows, especially if constraints were slightly larger or if intermediate calculations could exceed `int` limits. For this specific problem, `int` would technically suffice, but `long long` causes no harm and adds robustness.

The solution strategy is thus a straightforward simulation:
1. Read the number of test cases `T`.
2. For each test case:
   a. Read `D` and `N`.
   b. Initialize a variable, say `current_N`, with the value of `N`.
   c. Loop `D` times:
      i. Update `current_N` using the formula: `current_N = current_N * (current_N + 1) / 2`.
   d. Print the final `current_N`.

## Complexity Analysis

-   **Time Complexity**: $O(T \cdot D)$
    For each of the `T` test cases, we perform a loop that runs `D` times. Inside this loop, we execute a constant number of arithmetic operations (multiplication, addition, division). Since `D` is very small (at most 4), the operations per test case are effectively constant. Therefore, the total time complexity is directly proportional to the number of test cases `T` multiplied by `D`. Given `T <= 1000` and `D <= 4`, the maximum number of operations is `1000 * 4 = 4000`, which is extremely fast and well within typical time limits. We can also express this as $O(T)$ because $D$ is a small constant.

-   **Space Complexity**: $O(1)$
    The solution uses a fixed number of variables (`T`, `D`, `N`, `current_N`, and a loop counter `i`). The memory usage does not depend on the input values `D` or `N` (beyond the fixed size of their data types). Thus, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Using the standard namespace to avoid prefixing std::
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from the C standard streams and
    // prevents synchronization with stdio, making I/O operations faster.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare variable for the number of test cases
    cin >> T; // Read the number of test cases from standard input

    // Loop through each test case
    while (T--) {
        int D, N; // Declare variables for D and N for the current test case
        cin >> D >> N; // Read D and N

        // Initialize current_N with the input N.
        // Using long long to store current_N to prevent potential integer overflow,
        // especially during the calculation of current_N * (current_N + 1),
        // although for the given constraints (D, N <= 4), int would technically suffice.
        long long current_N = N;

        // Apply the sum operation D times
        for (int i = 0; i < D; ++i) {
            // The sum of integers from 1 to X is given by the formula X * (X + 1) / 2.
            // We update current_N by applying this formula to its current value.
            current_N = current_N * (current_N + 1) / 2;
        }

        // Output the final calculated value for the current test case,
        // followed by a newline character as required.
        cout << current_N << "\n";
    }

    return 0; // Indicate successful program execution
}
```