# [Cashback (CASHBACK)](https://www.codechef.com/problems/CASHBACK)
- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the final amount a customer pays for a cake, given its original price `X`. The shop has a cashback policy: if the total purchase amount `X` is 200 rupees or more, the customer receives a 50 rupee cashback (effectively a discount). If the purchase amount `X` is less than 200 rupees, no cashback is applied, and the customer pays the full price. We need to output the effective amount paid by the customer.

## Intuition & Mathematical Observation

The problem describes a classic conditional scenario. We are given a single input `X`, which represents the original price of the cake. The core of the problem is to apply a discount based on whether `X` meets a specific threshold.

The logic can be broken down as follows:
1.  **Check the condition**: Is the purchase amount `X` greater than or equal to 200?
2.  **Apply discount if condition met**: If `X >= 200`, the customer gets a 50 rupee discount. So, the effective amount paid will be `X - 50`.
3.  **No discount otherwise**: If `X < 200`, no discount is applied. The effective amount paid will simply be `X`.

This is a direct application of an `if-else` statement. No complex mathematical formulas, data structures, or advanced algorithms are required. The solution involves basic arithmetic (subtraction) and a conditional check.

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    *   The program performs a fixed number of operations regardless of the input value `X`:
        *   Reading an integer (`cin >> X`).
        *   A single comparison (`X >= 200`).
        *   A potential subtraction (`X - 50`).
        *   Printing an integer (`cout << effective_amount`).
    *   Each of these operations takes constant time. Therefore, the total time complexity is constant.

*   **Space Complexity**: $O(1)$
    *   The program uses a few integer variables (`X`, `effective_amount`) to store the input and the calculated result. The memory required for these variables is constant and does not depend on the magnitude of `X` or any other input size.

## Solution Code

```cpp
#include <bits/stdc++.h> // Required header

// Required namespace
using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem statement specifies: "The first and only line contains a single integer X".
    // This indicates a single test case, not multiple test cases.
    // Therefore, no loop for 't' test cases is needed.

    int X; // Declare an integer variable to store the price of the cake
    cin >> X; // Read the price X from standard input

    int effective_amount; // Declare an integer variable to store the calculated effective amount

    // Apply Chef's cashback policy:
    // If the purchase amount (X) is at least 200 rupees, a 50 rupee discount is applied.
    if (X >= 200) {
        effective_amount = X - 50; // Calculate the amount after discount
    } else {
        // If the purchase amount is less than 200 rupees, no discount is applied.
        effective_amount = X; // The effective amount is the original price
    }

    // Output the effective amount paid by the customer, followed by a newline character.
    cout << effective_amount << "\n";

    return 0; // Indicate successful program execution
}
```