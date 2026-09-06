# [Reverse The Number (FLOW007)](https://www.codechef.com/problems/FLOW007)
- **Difficulty Rating**: 588
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to reverse a given integer. For example, if the input is `123`, the output should be `321`. If the input is `100`, the output should be `1`. The problem specifies that we need to handle multiple test cases.

## Intuition & Mathematical Observation

To reverse a number, we can extract its digits one by one, starting from the least significant digit (the rightmost digit), and then construct a new number using these extracted digits in reverse order.

Here's the step-by-step process:

1.  **Initialize a variable** `reversed_n` to `0`. This variable will store the reversed number.
2.  **Loop while the original number `n` is greater than `0`**:
    *   **Extract the last digit**: Use the modulo operator (`% 10`). `digit = n % 10`.
    *   **Append the digit to `reversed_n`**: To do this, we first shift the existing `reversed_n` one decimal place to the left (by multiplying by `10`) and then add the extracted `digit`. So, `reversed_n = reversed_n * 10 + digit`.
    *   **Remove the last digit from `n`**: Use integer division (`/ 10`). `n = n / 10`.
3.  Once `n` becomes `0`, the loop terminates, and `reversed_n` will hold the completely reversed number.

**Example Walkthrough (n = 123):**

*   Initially: `n = 123`, `reversed_n = 0`
*   **Iteration 1**:
    *   `digit = 123 % 10 = 3`
    *   `reversed_n = 0 * 10 + 3 = 3`
    *   `n = 123 / 10 = 12`
*   **Iteration 2**:
    *   `digit = 12 % 10 = 2`
    *   `reversed_n = 3 * 10 + 2 = 32`
    *   `n = 12 / 10 = 1`
*   **Iteration 3**:
    *   `digit = 1 % 10 = 1`
    *   `reversed_n = 32 * 10 + 1 = 321`
    *   `n = 1 / 10 = 0`
*   `n` is now `0`, loop terminates.
*   Result: `321`

This approach correctly handles numbers with trailing zeros (e.g., `100` becomes `1`) because the leading zeros in the reversed number are naturally omitted by integer arithmetic.

## Complexity Analysis

-   **Time Complexity**: $O(\log_{10} N)$ per test case.
    The `while` loop iterates once for each digit in the number `N`. The number of digits in `N` is proportional to $\log_{10} N$. Since there are `T` test cases, the total time complexity will be $O(T \cdot \log_{10} N_{max})$, where $N_{max}$ is the maximum possible value of `N`.

-   **Space Complexity**: $O(1)$.
    We use a fixed number of integer variables (`n`, `reversed_n`, `digit`, `t`) regardless of the input number's magnitude. This constant amount of memory usage leads to $O(1)$ space complexity.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common C++ headers like iostream

// Using the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Variable to store the number of test cases
    cin >> t; // Read the number of test cases

    // Loop through each test case
    while (t--) {
        int n; // Variable to store the input number
        cin >> n; // Read the input number for the current test case

        int reversed_n = 0; // Initialize a variable to store the reversed number

        // Loop to extract digits and build the reversed number
        while (n > 0) {
            int digit = n % 10; // Get the last digit of n
            reversed_n = reversed_n * 10 + digit; // Append the digit to reversed_n
            n /= 10; // Remove the last digit from n
        }

        // Print the reversed number followed by a newline character
        cout << reversed_n << "\n";
    }

    return 0; // Indicate successful execution
}

```