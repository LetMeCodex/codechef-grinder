# [Janmansh and Coins (JCOINS)](https://www.codechef.com/problems/JCOINS)
- **Difficulty Rating**: 527
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the total amount of money Janmansh has, given the number of 10-rupee coins and 5-rupee coins he possesses. We are provided with `X` (the count of 10-rupee coins) and `Y` (the count of 5-rupee coins) for multiple test cases. For each test case, we need to output the total sum.

## Intuition & Mathematical Observation

This is a very straightforward problem that tests basic arithmetic.
The core idea is to calculate the value contributed by each type of coin and then sum them up.

1.  **Value from 10-rupee coins**: If Janmansh has `X` coins of 10 rupees each, the total value from these coins will be `X * 10`.
2.  **Value from 5-rupee coins**: Similarly, if he has `Y` coins of 5 rupees each, the total value from these coins will be `Y * 5`.
3.  **Total Money**: The total money Janmansh has is simply the sum of the values from both types of coins.
    `Total Money = (X * 10) + (Y * 5)`

This formula can be directly applied for each test case. No complex algorithms, data structures, or advanced mathematical concepts are required.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    For each test case, we perform a constant number of operations: reading two integers, two multiplications, one addition, and printing one integer. These operations take constant time, $O(1)$. Since there are $T$ test cases, the total time complexity will be $T \times O(1)$, which simplifies to $O(T)$.

*   **Space Complexity**: $O(1)$
    We only use a few integer variables (`t`, `x`, `y`, `total_money`) to store the number of test cases, input coin counts, and the calculated total. The memory used by these variables is constant and does not depend on the input values or the number of test cases. Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Required header for competitive programming

using namespace std; // Required namespace

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Declare an integer variable 't' to store the number of test cases.
    cin >> t; // Read the number of test cases from standard input.

    // Loop 't' times, once for each test case.
    while (t--) {
        int x, y; // Declare integer variables 'x' and 'y' for the number of coins.
        // 'x' will store the count of 10-rupee coins.
        // 'y' will store the count of 5-rupee coins.
        cin >> x >> y; // Read 'x' and 'y' for the current test case.

        // Calculate the total money Janmansh has.
        // Each 10-rupee coin contributes 10 * x rupees.
        // Each 5-rupee coin contributes 5 * y rupees.
        // The sum of these two amounts is the total money.
        int total_money = (x * 10) + (y * 5);

        // Print the calculated total money to standard output, followed by a newline character.
        // The newline character ensures that each test case's output is on a separate line.
        cout << total_money << "\n";
    }

    return 0; // Indicate successful program execution.
}
```