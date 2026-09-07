# [First and Last Digit (FLOW004)](https://www.codechef.com/problems/FLOW004)
- **Difficulty Rating**: 461
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to process `T` test cases. For each test case, we are given a single integer `N`. Our task is to find the first digit of `N` and the last digit of `N`, and then print their sum.

For example, if `N = 12345`:
- The first digit is `1`.
- The last digit is `5`.
- The sum is `1 + 5 = 6`.

## Intuition & Mathematical Observation

To solve this problem, we need two distinct operations: one to extract the last digit and another to extract the first digit.

1.  **Finding the Last Digit**:
    The last digit of any positive integer `N` can be easily obtained using the modulo operator. `N % 10` gives the remainder when `N` is divided by 10, which is always its last digit.
    *Example*: `12345 % 10 = 5`

2.  **Finding the First Digit**:
    To find the first digit, we can repeatedly remove the last digit of `N` until `N` becomes a single-digit number. This is achieved by repeatedly dividing `N` by 10 using integer division.
    *Example*: For `N = 12345`
    *   `12345 / 10 = 1234`
    *   `1234 / 10 = 123`
    *   `123 / 10 = 12`
    *   `12 / 10 = 1`
    *   Now, `1` is a single-digit number (less than 10), so it is the first digit.
    This process continues as long as the number is greater than or equal to 10.

Once both the first and last digits are found, we simply add them together and print the result.

## Complexity Analysis

*   **Time Complexity**: $O(T \cdot \log_{10} N)$
    *   For each test case, finding the last digit takes constant time ($O(1)$) as it involves a single modulo operation.
    *   Finding the first digit involves a `while` loop that repeatedly divides `N` by 10. The number of divisions is proportional to the number of digits in `N`. The number of digits in `N` is $\lfloor \log_{10} N \rfloor + 1$. Thus, this operation takes $O(\log_{10} N)$ time.
    *   The sum and print operations are $O(1)$.
    *   Since there are `T` test cases, the total time complexity is $O(T \cdot \log_{10} N)$. Given that `N` fits within an `int` (up to $2 \cdot 10^9$), $\log_{10} N$ is at most around 10, making it a very small constant factor.

*   **Space Complexity**: $O(1)$
    *   The solution only uses a few integer variables (`t`, `n`, `last_digit`, `first_digit`) to store input and intermediate results. The amount of memory used does not depend on the magnitude of `N` or `T`. Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common headers like iostream

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
        int n; // Declare an integer variable 'n' for the input number
        cin >> n; // Read the input number for the current test case

        // The last digit is simply the remainder when n is divided by 10.
        int last_digit = n % 10;

        // To get the first digit, we repeatedly divide n by 10
        // until it becomes a single digit number (i.e., less than 10).
        int first_digit = n; // Initialize first_digit with n
        while (first_digit >= 10) { // Continue as long as first_digit has more than one digit
            first_digit /= 10; // Integer division by 10 removes the last digit
        }

        // Print the sum of the first and last digits, followed by a newline character.
        cout << first_digit + last_digit << "\n";
    }

    return 0; // Indicate successful execution of the program
}

```