# [Discount (DISCNT)](https://www.codechef.com/problems/DISCNT)
- **Difficulty Rating**: 401
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to calculate the final price of a toy after a given discount percentage is applied. The original price of the toy is fixed at 100 rupees. We are given a discount percentage `x` and need to output the price Alice has to pay.

## Intuition & Mathematical Observation
The original price of the toy is 100 rupees.
A discount of `x` percent means that `x/100` of the original price is deducted.
So, the discount amount is `100 * (x / 100)` rupees.
This simplifies to `x` rupees.

The final price Alice has to pay is the original price minus the discount amount.
Final Price = Original Price - Discount Amount
Final Price = 100 - x

Therefore, for any given discount percentage `x`, the amount Alice needs to pay is simply `100 - x`.

## Complexity Analysis
- **Time Complexity**: $O(1)$
The solution involves a fixed number of arithmetic operations (subtraction) and input/output operations for each test case. The number of operations does not depend on the input values `x` or the number of test cases `T` in a way that scales linearly or logarithmically. Thus, for each test case, the time complexity is constant.

- **Space Complexity**: $O(1)$
The solution uses a few integer variables (`T`, `x`, `amount_to_pay`) to store input and intermediate results. The amount of memory used is constant and does not grow with the input size.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes most standard libraries

using namespace std; // Allows using standard library elements without the std:: prefix

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int x; // Declare an integer variable x to store the discount percentage.
        cin >> x; // Read the discount percentage for the current test case.

        // The original price of the toy is 100 rupees.
        // A discount of x percent means a discount of x rupees (since 100 * x/100 = x).
        // The amount Alice needs to pay is the original price minus the discount amount.
        int amount_to_pay = 100 - x;

        // Output the calculated amount Alice needs to pay, followed by a newline character.
        cout << amount_to_pay << "\n";
    }

    return 0; // Indicate successful program execution.
}
```