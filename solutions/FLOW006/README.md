# Sum of Digits (FLOW006)

## Problem Summary

The problem asks us to read a number of test cases, $T$. For each test case, we are given an integer $N$ and we need to calculate and print the sum of its digits. The input constraints specify that $N$ will be between 1 and $10^9$ (inclusive).

## Intuition & Mathematical Observation

To find the sum of digits of a number, we can repeatedly extract the last digit and add it to a running sum, then remove the last digit from the number until the number becomes zero.

The last digit of any integer $N$ can be obtained using the modulo operator: $N \pmod{10}$.
After extracting the last digit, we can remove it from the number by performing integer division by 10: $N / 10$.

For example, if $N = 123$:
1. Last digit: $123 \pmod{10} = 3$. Sum = 3. New $N = 123 / 10 = 12$.
2. Last digit: $12 \pmod{10} = 2$. Sum = $3 + 2 = 5$. New $N = 12 / 10 = 1$.
3. Last digit: $1 \pmod{10} = 1$. Sum = $5 + 1 = 6$. New $N = 1 / 10 = 0$.
The number is now 0, so we stop. The sum of digits is 6.

This process can be implemented using a `while` loop that continues as long as the number $N$ is greater than 0.

## Complexity Analysis

- **Time Complexity**: $O(\log_{10} N)$
    - For each test case, we iterate through the digits of the number $N$. The number of digits in $N$ is approximately $\log_{10} N$. In each iteration of the inner `while` loop, we perform constant time operations (modulo, addition, division). Therefore, the time complexity for processing a single number $N$ is logarithmic with respect to the value of $N$. Since there are $T$ test cases, the total time complexity is $O(T \log_{10} N_{max})$, where $N_{max}$ is the maximum possible value of $N$.

- **Space Complexity**: $O(1)$
    - We only use a few variables to store the number of test cases ($T$), the current number ($N$), and the sum of digits. The amount of memory used does not depend on the input size $N$ or the number of test cases $T$. Thus, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from the C standard streams and prevents flushing
    // of cout before cin, leading to faster input/output operations.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int N; // Declare an integer N to store the input number for the current test case.
        cin >> N; // Read the number N from standard input.

        int sum_of_digits = 0; // Initialize a variable to store the sum of digits.

        // Loop while N is greater than 0 to process each digit.
        // For N=0, the sum of digits is 0. The problem constraints state 1 <= N,
        // so N will always be positive initially.
        while (N > 0) {
            // Get the last digit of N using the modulo operator (N % 10).
            // Add this digit to sum_of_digits.
            sum_of_digits += N % 10;

            // Remove the last digit from N using integer division (N / 10).
            // This effectively shifts the number one place to the right.
            N /= 10;
        }

        // Print the calculated sum of digits for the current test case,
        // followed by a newline character as required.
        cout << sum_of_digits << "\n";
    }

    return 0; // Indicate successful execution of the program.
}
```