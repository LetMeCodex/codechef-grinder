# [Small Factorial (FLOW018)](https://www.codechef.com/problems/FLOW018)
- **Difficulty Rating**: 760
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to calculate the factorial of a given non-negative integer `N`. We are provided with `T` test cases. For each test case, we need to read an integer `N` and print its factorial, `N!`. The constraints specify that `N` will be between 1 and 20 (inclusive).

## Intuition & Mathematical Observation
The factorial of a non-negative integer `N`, denoted as `N!`, is the product of all positive integers less than or equal to `N`. Mathematically, it's defined as:
$N! = N \times (N-1) \times (N-2) \times \dots \times 1$
with the special case $0! = 1$.

Given the constraints, `N` will be between 1 and 20. Let's consider the maximum value:
$20! = 2,432,902,008,176,640,000$

A standard 32-bit integer type (like `int` in C++) can typically store values up to approximately $2 \times 10^9$. As $20!$ is significantly larger than this, a `long long` data type in C++ (which is a 64-bit integer) is required. A `long long` can store values up to approximately $9 \times 10^{18}$, which is sufficient to hold the value of $20!$.

The most straightforward way to calculate the factorial is to iterate from 1 up to `N`, multiplying a running product (initialized to 1) by each number in the sequence.

For example, to calculate $3!$:
1. Initialize a variable `factorial = 1`.
2. Loop `i` from 1 to 3:
   - When `i = 1`: `factorial = 1 * 1 = 1`.
   - When `i = 2`: `factorial = 1 * 2 = 2`.
   - When `i = 3`: `factorial = 2 * 3 = 6`.
The final result is 6.

This iterative approach is simple and efficient enough given the small constraint on `N`.

## Complexity Analysis
-   **Time Complexity**: For each test case, we run a loop that iterates `N` times to calculate the factorial. Since there are `T` test cases, the total time complexity will be $O(T \times N)$. Given that $N \le 20$, $N$ is effectively a small constant. Thus, the operations per test case are constant, making the overall time complexity very efficient.
-   **Space Complexity**: We only use a few variables to store the number of test cases (`t`), the input number (`n`), the calculated factorial (`factorial`), and a loop counter (`i`). These variables consume a constant amount of memory regardless of the input `N`. Therefore, the space complexity is $O(1)$.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes common headers like iostream, vector, algorithm, etc.

using namespace std; // Allows using standard library components without std:: prefix

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // potentially speeding up I/O operations.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // further speeding up I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Declare an integer variable 't' to store the number of test cases.
    cin >> t; // Read the number of test cases from standard input.

    // Loop 't' times, once for each test case.
    // The 't--' decrements 't' after each iteration until it becomes 0.
    while (t--) {
        int n; // Declare an integer variable 'n' to store the input number for which factorial is to be calculated.
        cin >> n; // Read the number 'n' for the current test case.

        // Declare a long long variable 'factorial' and initialize it to 1.
        // long long is used because factorial values can grow very large quickly.
        // For N=20, 20! is 2,432,902,008,176,640,000, which exceeds the capacity of a 32-bit integer
        // (max ~2*10^9) but fits within a 64-bit long long (max ~9*10^18).
        // Initializing to 1 correctly handles 0! = 1 and serves as the base for multiplication.
        long long factorial = 1;

        // Calculate the factorial of 'n'.
        // The loop iterates from 1 up to 'n' (inclusive).
        // In each iteration, 'factorial' is multiplied by the current loop variable 'i'.
        // Example: if n=3, factorial will be:
        // i=1: factorial = 1 * 1 = 1
        // i=2: factorial = 1 * 2 = 2
        // i=3: factorial = 2 * 3 = 6
        for (int i = 1; i <= n; ++i) {
            factorial *= i;
        }

        // Print the calculated factorial value to standard output,
        // followed by a newline character to ensure each output is on a new line
        // as per the problem's output format requirement.
        cout << factorial << "\n";
    }

    return 0; // Indicate that the program executed successfully.
}
```