# [Expense List (EXPENSES)](https://www.codechef.com/problems/EXPENSES)
- **Difficulty Rating**: 719
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem states that you start with an initial income of $2^X$. You then make $N$ expenses. Each time an expense is made, your current income is halved. The task is to calculate the final amount of money remaining after all $N$ expenses have been made.

## Intuition & Mathematical Observation

Let's trace the income transformation:
1.  **Initial Income**: $2^X$
2.  **After 1st Expense**: The income is halved. So, $2^X / 2 = 2^{X-1}$.
3.  **After 2nd Expense**: The current income ($2^{X-1}$) is halved again. So, $2^{X-1} / 2 = 2^{X-2}$.
4.  **After 3rd Expense**: The current income ($2^{X-2}$) is halved. So, $2^{X-2} / 2 = 2^{X-3}$.

We can observe a clear pattern here: each expense reduces the exponent of 2 by 1. If this operation is performed $N$ times, the exponent will be reduced by $N$ in total.

Therefore, after $N$ expenses, the final amount of money remaining will be $2^{X-N}$.

To implement $2^K$ efficiently in C++, we can use the left bit shift operator `1LL << K`. This operation calculates $2^K$ and `1LL` ensures that the result is treated as a `long long` to prevent potential overflow for larger exponents, although for the given constraints (maximum $X-N$ is 19, so $2^{19}$ fits in an `int`), `int` would also suffice. Using `long long` is a good practice for powers of 2.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    The program iterates $T$ times, once for each test case. Inside the loop, it performs a constant number of operations: reading two integers (`N`, `X`), performing a single bit shift calculation (`1LL << (X - N)`), and printing the result. Each of these operations takes constant time. Therefore, the total time complexity is directly proportional to the number of test cases, $T$.

-   **Space Complexity**: $O(1)$
    The program uses a fixed number of variables (`T`, `N`, `X`, `savings`) regardless of the input values or the number of test cases. These variables occupy a constant amount of memory. Hence, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> 
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin/cout from the C standard I/O library and
    // prevents flushing cout before cin reads input.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times for each test case
        int N, X;
        cin >> N >> X; // Read N (number of expenses) and X (exponent for income 2^X)

        // Calculate the amount saved using the derived formula: 2^(X-N)
        // The expression (X - N) gives the exponent.
        // 1LL << (X - N) performs a left bit shift.
        // For example, 1LL << 3 results in 1 * 2^3 = 8.
        // 1LL ensures that the operation is performed using a long long integer type,
        // which prevents potential overflow if the result were larger, though for X-N <= 19,
        // a standard 'int' would suffice. It's good practice for powers of 2.
        long long savings = 1LL << (X - N); 
        
        cout << savings << "\n"; // Output the calculated savings followed by a newline
    }

    return 0; // Indicate successful program execution
}
```