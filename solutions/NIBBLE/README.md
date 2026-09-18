# Good Program (NIBBLE)

- **Difficulty Rating**: 593
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a program is "Good" or "Not Good" based on the number of bits it uses. A program is considered "Good" if the total number of bits it uses is a multiple of 4. Otherwise, it's "Not Good". We are given an integer $N$, representing the number of bits, and we need to output "Good" or "Not Good" accordingly.

## Intuition & Mathematical Observation

The core of the problem lies in understanding the condition for a program to be "Good". The problem statement explicitly defines this condition: the number of bits must be a multiple of 4.

A number is a multiple of 4 if and only if it is perfectly divisible by 4. In mathematical terms, this means that when the number is divided by 4, the remainder is 0.

Given an integer $N$ representing the number of bits, we can check if it's a multiple of 4 by using the modulo operator (`%`). If $N \pmod 4 == 0$, then $N$ is a multiple of 4, and the program is "Good". Otherwise, if $N \pmod 4 \neq 0$, the program is "Not Good".

The problem constraints state that $N \ge 1$. This is important because it ensures we are always dealing with a positive number of bits.

## Complexity Analysis

- **Time Complexity**: $O(1)$
    The solution involves a single modulo operation and a conditional check for each test case. These operations take constant time, regardless of the input value of $N$. Since there are $T$ test cases, the total time complexity is $O(T \times 1) = O(T)$. However, if we consider the complexity per test case, it's $O(1)$.

- **Space Complexity**: $O(1)$
    The solution uses a few integer variables ($N$, $T$) to store input and perform calculations. The amount of memory used does not grow with the input size $N$ or the number of test cases $T$. Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries for convenience

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

// Function to solve a single test case
void solve() {
    int N; // Declare an integer variable N to store the number of bits
    cin >> N; // Read the value of N from standard input

    // Check if N is perfectly divisible by 4
    // If N % 4 == 0, it means N bits is an exact integer number of nibbles.
    // Since N >= 1, this integer number of nibbles will also be positive.
    if (N % 4 == 0) {
        cout << "Good\n"; // If divisible, the program is "Good"
    } else {
        cout << "Not Good\n"; // Otherwise, the program is "Not Good"
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can speed up I/O operations.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // further speeding up I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases
    cin >> T; // Read the value of T from standard input

    // Loop T times, calling the solve() function for each test case
    while (T--) {
        solve();
    }

    return 0; // Indicate successful program execution
}
```