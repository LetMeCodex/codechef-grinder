# [Lucky Four (LUCKYFR)](https://www.codechef.com/problems/LUCKYFR)
- **Difficulty Rating**: 998
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to count the number of occurrences of the digit '4' in a given integer $N$. We are given $T$ test cases, and for each test case, we need to read an integer $N$ and output the count of '4's in it.

## Intuition & Mathematical Observation
The core of this problem is to extract individual digits from a given integer. A common and efficient way to do this is by using the modulo operator (`%`) and integer division (`/`).

1.  **Extracting the last digit**: The modulo operator, when applied with 10 (`N % 10`), gives us the last digit of the number $N$. For example, `123 % 10` is `3`.
2.  **Removing the last digit**: Integer division by 10 (`N / 10`) effectively removes the last digit from the number $N$. For example, `123 / 10` is `12`.

By repeatedly applying these two operations, we can iterate through all the digits of the number. We start with the given number $N$. We extract its last digit, check if it's a '4', and then remove it. We continue this process until the number becomes 0, meaning all digits have been processed.

For each extracted digit, we simply check if it is equal to 4. If it is, we increment a counter. After processing all digits, the value of the counter will be the total number of '4's in the original integer.

The problem statement implies that the input integers will be non-negative. If the input is 0, the `while (N > 0)` loop condition will be false immediately, and the `count` will remain 0, which is the correct output for the number 0.

## Complexity Analysis
- **Time Complexity**: $O(\log_{10} N)$
    The number of operations to extract digits from an integer $N$ is proportional to the number of digits in $N$. The number of digits in base 10 is approximately $\log_{10} N$. For each digit, we perform a constant number of operations (modulo, comparison, division). Therefore, the time complexity for processing a single test case is logarithmic with respect to the value of $N$. Since there are $T$ test cases, the total time complexity is $O(T \log_{10} N_{max})$, where $N_{max}$ is the maximum possible value of $N$.

- **Space Complexity**: $O(1)$
    We only use a few variables to store the number of test cases ($T$), the current number ($N$), the extracted digit, and the count of '4's. The amount of memory used does not depend on the input size $N$ or the number of test cases $T$. Hence, the space complexity is constant.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes all standard libraries

using namespace std; // Use standard namespace for convenience

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times, decrementing T in each iteration
        int N;
        cin >> N; // Read the integer for the current test case

        int count = 0; // Initialize a counter for occurrences of the digit '4'

        // Loop to extract digits from N and count '4's.
        // The loop continues as long as N has digits remaining (N > 0).
        // This also correctly handles the case where N is 0:
        // If N is 0, the loop condition (N > 0) is false, so the loop is skipped.
        // 'count' remains 0, which is the correct answer for N=0.
        while (N > 0) {
            int digit = N % 10; // Get the last digit of N
            if (digit == 4) {   // Check if the extracted digit is '4'
                count++;        // If it is, increment the counter
            }
            N /= 10;            // Remove the last digit from N using integer division
        }

        // Output the total count of '4's for the current number, followed by a newline.
        cout << count << "\n";
    }

    return 0; // Indicate successful program execution
}
```