# [Binary Parity (BINPARITY)](https://www.codechef.com/problems/BINPARITY)
- **Difficulty Rating**: 771
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the parity (even or odd) of the sum of binary digits for a given integer `N`. In other words, we need to count the number of set bits (1s) in the binary representation of `N`, and then check if this count is even or odd. We must output "EVEN" or "ODD" accordingly for each test case.

## Intuition & Mathematical Observation

The core of the problem lies in efficiently calculating the "sum of binary digits," which is also known as the "population count" or "Hamming weight" of an integer.

For example:
- If `N = 4` (decimal), its binary representation is `100`. The sum of binary digits is `1 + 0 + 0 = 1`. Since `1` is odd, the output should be "ODD".
- If `N = 6` (decimal), its binary representation is `110`. The sum of binary digits is `1 + 1 + 0 = 2`. Since `2` is even, the output should be "EVEN".

Modern compilers and processors often provide highly optimized ways to calculate the population count. In C++, the GCC compiler provides a built-in function `__builtin_popcount(n)` which efficiently computes the number of set bits in an integer `n`. This function leverages hardware instructions (like `POPCNT` on x86-64 architectures) when available, making it extremely fast.

Once we have the population count, we simply perform a modulo 2 operation on it. If the result is 0, the count is even; otherwise, it's odd.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    For each test case, we perform the following operations:
    1.  Reading an integer `N`: $O(1)$.
    2.  Calculating the sum of binary digits using `__builtin_popcount(N)`: This operation is highly optimized. On most modern processors, there's a dedicated instruction for population count, making it an $O(1)$ operation. Even without dedicated hardware support, a software implementation would typically take $O(\log N)$ time (proportional to the number of bits in `N`), which is still very fast for standard integer sizes (e.g., 32 or 64 bits). For competitive programming, `__builtin_popcount` is generally considered $O(1)$.
    3.  Checking parity and printing: $O(1)$.
    Therefore, each test case takes effectively $O(1)$ time. Since there are `T` test cases, the total time complexity is $O(T)$.

-   **Space Complexity**: $O(1)$
    The solution uses a constant amount of extra space to store variables like `n`, `sum_binary_digits`, and `t`. No data structures that grow with the input size are used.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes everything, including iostream and built-in functions

// Using the standard namespace as requested
using namespace std;

// Function to solve a single test case
void solve() {
    int n;
    cin >> n; // Read the integer N

    // Calculate the sum of binary digits (population count) using __builtin_popcount.
    // This function efficiently counts the number of set bits (1s) in the binary representation of n.
    int sum_binary_digits = __builtin_popcount(n);

    // Check the parity of the sum of binary digits
    if (sum_binary_digits % 2 == 0) {
        // If the sum is even, output "EVEN"
        cout << "EVEN\n";
    } else {
        // If the sum is odd, output "ODD"
        cout << "ODD\n";
    }
}

int main() {
    // Enable fast I/O operations.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases

    // Loop through each test case
    while (t--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```