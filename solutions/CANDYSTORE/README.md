# [Candy Store (CANDYSTORE)](https://www.codechef.com/problems/CANDYSTORE)
- **Difficulty Rating**: 429
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a scenario where Chef sells chocolates and earns money based on the number of chocolates sold (`Y`) relative to a daily goal (`X`).

There are two earning rules:
1.  If Chef sells `Y` chocolates, and `Y` is less than or equal to the daily goal `X` (`Y <= X`), he earns 1 rupee for each chocolate sold.
2.  If Chef sells `Y` chocolates, and `Y` is greater than the daily goal `X` (`Y > X`), he earns 1 rupee for the first `X` chocolates (meeting the goal) and 2 rupees for each additional chocolate sold beyond `X`.

The task is to calculate the total amount Chef earns for given `X` and `Y` for multiple test cases.

## Intuition & Mathematical Observation

The problem statement clearly defines two distinct cases for calculating Chef's earnings, based on the comparison between the number of chocolates sold (`Y`) and the daily goal (`X`). Our intuition should immediately lead to an `if-else` conditional structure to handle these two scenarios.

Let's break down the logic for each case:

1.  **Case 1: `Y <= X` (Chocolates sold are less than or equal to the goal)**
    *   In this scenario, Chef hasn't exceeded his goal.
    *   According to the rules, he earns 1 rupee for *each* chocolate sold.
    *   Therefore, the total amount earned is simply `Y * 1`.

2.  **Case 2: `Y > X` (Chocolates sold exceed the goal)**
    *   Here, Chef has met his goal of `X` chocolates and sold `Y - X` additional chocolates.
    *   For the first `X` chocolates (which meet the goal), he earns 1 rupee each. The amount for these is `X * 1`.
    *   For the `Y - X` additional chocolates, he earns 2 rupees each. The amount for these is `(Y - X) * 2`.
    *   The total amount earned is the sum of earnings from both parts: `(X * 1) + ((Y - X) * 2)`.

By implementing these two cases with an `if-else` statement, we can correctly calculate the total earnings for any given `X` and `Y`.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    The program iterates `T` times, once for each test case. Inside the loop, it performs a constant number of operations: reading two integers, a comparison, and a few arithmetic operations (multiplication, subtraction, addition). Each test case is processed in $O(1)$ time. Therefore, the total time complexity is directly proportional to the number of test cases, $O(T)$.

-   **Space Complexity**: $O(1)$
    The program uses a fixed number of integer variables (`T`, `X`, `Y`, `total_amount`) regardless of the input values or the number of test cases. The memory usage does not grow with the input size. Hence, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> 
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from the C standard I/O library and
    // prevents flushing cout before cin, speeding up I/O operations.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times, once for each test case
        int X, Y;
        cin >> X >> Y; // Read Chef's daily goal (X) and chocolates sold (Y)

        int total_amount;

        // Case 1: Chef sells Y chocolates, which is less than or equal to the goal X.
        // In this scenario, Chef gets 1 rupee for each chocolate sold.
        if (Y <= X) {
            total_amount = Y * 1; // Total amount is simply Y rupees.
        } 
        // Case 2: Chef sells Y chocolates, which is more than the goal X.
        // In this scenario, Chef gets 1 rupee for the first X chocolates (meeting the goal)
        // and 2 rupees for each extra chocolate sold beyond X.
        else {
            // Amount for the first X chocolates (goal achieved): X * 1 rupees
            // Amount for the extra (Y - X) chocolates: (Y - X) * 2 rupees
            total_amount = X * 1 + (Y - X) * 2;
        }

        // Output the calculated total amount for the current test case, followed by a newline.
        cout << total_amount << "\n";
    }

    return 0; // Indicate successful execution
}
```