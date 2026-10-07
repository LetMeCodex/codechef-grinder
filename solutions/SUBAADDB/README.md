# [Sub A Add B (SUBAADDB)](https://www.codechef.com/problems/SUBAADDB)
- **Difficulty Rating**: 817
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to start with a string of length $N$. We are allowed to perform an operation: choose a substring of length $A$ and replace it with a substring of length $B$. This operation can be performed as long as there exists a substring of length $A$ in the current string. We need to find the minimum possible length of the string after performing any number of these operations.

## Intuition & Mathematical Observation

The core of the problem lies in understanding how the string length changes with each operation. When we replace a substring of length $A$ with a substring of length $B$, the net change in the string's length is $B - A$.

The problem states that we can perform this operation as long as there's a substring of length $A$. This means we can perform the operation as long as the current string length is greater than or equal to $A$.

Since we want to find the *minimum* possible length, and each operation reduces the length by $A - B$ (assuming $A > B$, which is implied by the goal of minimizing length and the nature of the operation), we should perform this operation as many times as possible.

Let the initial length be $N$.
If $N < A$, we cannot perform any operations, so the final length is $N$.

If $N \ge A$, we can perform the operation. Each operation reduces the length by $A - B$. We can continue performing this operation as long as the current length is at least $A$.

Consider the length $N$. If we perform the operation, the new length becomes $N - (A - B)$. We can repeat this as long as the current length is $\ge A$. This is equivalent to repeatedly subtracting $(A - B)$ from $N$ until $N$ becomes less than $A$.

This process can be modeled as:
Start with $N$.
While $N \ge A$:
  $N = N - (A - B)$

This is precisely what the provided solution code does. It iteratively subtracts $(A - B)$ from $N$ as long as $N$ remains greater than or equal to $A$. The final value of $N$ after this loop is the minimum possible length.

Let's consider an example: $N=10, A=5, B=2$.
The length reduction per operation is $A - B = 5 - 2 = 3$.
1. Initial length $N = 10$. Since $10 \ge 5$, we can operate.
   New length $N = 10 - 3 = 7$.
2. Current length $N = 7$. Since $7 \ge 5$, we can operate.
   New length $N = 7 - 3 = 4$.
3. Current length $N = 4$. Since $4 < 5$, we cannot operate anymore.
The minimum length is 4.

The code implements this logic directly.

## Complexity Analysis

- **Time Complexity**: $O(\frac{N}{A-B})$ in the worst case.
  In each iteration of the `while (N >= A)` loop, the value of `N` is reduced by `A - B`. The loop continues as long as `N` is greater than or equal to `A`. The number of times we can subtract `A - B` from `N` before it becomes less than `A` is roughly proportional to `N / (A - B)`. Since `A` and `B` are constants for a given test case, and `N` is the initial length, the time complexity is dominated by this loop.

- **Space Complexity**: $O(1)$.
  The solution uses a fixed number of integer variables (`T`, `N`, `A`, `B`, `length_reduction_per_op`) regardless of the input size. Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries for competitive programming

using namespace std; // Allows using standard library components without the std:: prefix

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, processing each test case.
    while (T--) {
        int N, A, B; // Declare integer variables N, A, B for the current test case.
        cin >> N >> A >> B; // Read the initial string length N, and parameters A and B.

        // Calculate the amount by which the string length is reduced in each operation.
        // An operation replaces a substring of length A with one of length B.
        // Since B < A, the net change in length is A - B (a reduction).
        int length_reduction_per_op = A - B;

        // Continue performing operations as long as the string's current length (N)
        // is greater than or equal to A.
        while (N >= A) {
            // Reduce the string's length by 'length_reduction_per_op'.
            N -= length_reduction_per_op;
        }

        // Once the loop terminates, N is the final length of the string,
        // because it's no longer possible to find a substring of length A to modify.
        cout << N << "\n"; // Output the final length followed by a newline character.
    }

    return 0; // Indicate successful program execution.
}
```