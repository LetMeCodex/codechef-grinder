# [Change Please (CHANGE_PLZ)](https://www.codechef.com/problems/CHANGE_PLZ)
- **Difficulty Rating**: 760
- **Solved in**: 3 attempt(s)

## Problem Summary

You are given an integer $X$, representing the amount you owe to a driver. You initially paid the driver $100. The driver can only give you change in $10 dollar bills. Your task is to determine the maximum amount of change the driver can give you back, given that the change must be in multiples of $10 and cannot exceed the amount you are owed.

## Intuition & Mathematical Observation

The core of the problem lies in calculating the total change you are supposed to receive and then determining how much of that change can be given back in $10 dollar bills.

1.  **Total Change Owed:** You paid $100 and owe $X$. Therefore, the total amount the driver should return to you is $100 - X$. Let's call this `amount_driver_owes_back`.

2.  **Constraint on Change:** The driver can only provide change in $10 dollar bills. This means the change given must be a multiple of $10$.

3.  **Maximum Change:** We need to find the largest multiple of $10$ that is less than or equal to `amount_driver_owes_back`.

    Consider an example: If `amount_driver_owes_back` is $37$.
    The multiples of $10$ are $0, 10, 20, 30, 40, \dots$.
    The largest multiple of $10$ that is less than or equal to $37$ is $30$.

    This can be achieved mathematically using integer division.
    If we divide `amount_driver_owes_back` by $10$ using integer division, we get the number of full $10 dollar bills that can be given.
    For example, $37 / 10 = 3$ (integer division).
    Then, to get the total amount represented by these bills, we multiply this result by $10$.
    $3 * 10 = 30$.

    So, the formula for the maximum change is: `(amount_driver_owes_back / 10) * 10`.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The solution involves a fixed number of arithmetic operations (subtraction, division, multiplication) and input/output operations for each test case. The number of operations does not depend on the input value $X$ or the number of test cases $T$ in a way that would increase linearly. Therefore, the time complexity is constant.

-   **Space Complexity**: $O(1)$
    The solution uses a few integer variables to store the input and intermediate calculations. The amount of memory used is constant and does not grow with the input size.

## Solution Code

```cpp
#include <cstdio> // For standard input/output operations using printf and scanf

int main() {
    int T; // Declare variable for the number of test cases
    scanf("%d", &T); // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int X; // Declare variable for the amount owed to the driver
        scanf("%d", &X); // Read the amount owed

        // Calculate the total amount the driver owes back to you.
        // You paid 100 dollars, and you owe X dollars.
        int amount_driver_owes_back = 100 - X;

        // The driver can only give back change in 10 dollar bills.
        // To find the maximum amount the driver can give back without exceeding
        // 'amount_driver_owes_back', we find the largest multiple of 10
        // that is less than or equal to 'amount_driver_owes_back'.
        // This is done by integer division by 10 (to get the number of 10-dollar bills)
        // and then multiplying by 10 again (to get the total amount).
        int max_change = (amount_driver_owes_back / 10) * 10;

        // Output the calculated maximum change, followed by a newline character.
        printf("%d\n", max_change);
    }

    return 0; // Indicate successful program execution
}
```