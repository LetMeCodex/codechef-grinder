# [Chef and Profits (CHFPROFIT)](https://www.codechef.com/problems/CHFPROFIT)
- **Difficulty Rating**: 889
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the total profit Chef makes from selling stocks. For each test case, we are given three integers:
1.  `X`: The number of stocks Chef owns.
2.  `Y`: The price at which Chef bought each stock.
3.  `Z`: The price at which Chef can sell each stock.

We need to output the total profit Chef makes for each given set of `X`, `Y`, and `Z`. The problem specifies that `Y <= Z`, which means Chef will always make a non-negative profit (or break even).

## Intuition & Mathematical Observation

The core of this problem is to correctly calculate the profit. Profit is generally defined as the total revenue minus the total cost.

1.  **Total Cost**: Chef buys `X` stocks, and each stock costs `Y`. So, the total amount Chef spent is `X * Y`.
2.  **Total Revenue**: Chef sells `X` stocks, and each stock is sold for `Z`. So, the total amount Chef receives is `X * Z`.
3.  **Total Profit**: Using the definition, Profit = Total Revenue - Total Cost.
    Substituting the expressions from steps 1 and 2:
    `Profit = (X * Z) - (X * Y)`

We can simplify this expression by factoring out `X`:
`Profit = X * (Z - Y)`

This simplified formula is more efficient as it involves one subtraction and one multiplication, compared to two multiplications and one subtraction in the original form.

**Constraints Check**:
The problem constraints are `1 <= X, Y <= 10^4` and `Y <= Z <= 10^4`.
*   The maximum value for `Z - Y` would be `10^4 - 1` (if `Y=1, Z=10^4`), which is `9999`.
*   The maximum value for `X` is `10^4`.
*   Therefore, the maximum possible profit would be `10^4 * (10^4 - 1)` which is approximately `10^8`.
*   A standard `int` data type in C++ typically handles values up to `2 * 10^9`, so it is perfectly sufficient to store the calculated profit without any risk of overflow.

The solution involves reading the number of test cases `T`, and then iterating `T` times, performing this simple calculation and printing the result for each test case.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    *   The `std::ios_base::sync_with_stdio(false);` and `std::cin.tie(NULL);` lines execute once at the beginning, taking constant time.
    *   Reading the number of test cases `T` takes constant time.
    *   The `while (T--)` loop runs `T` times.
    *   Inside the loop, for each test case:
        *   Reading `X`, `Y`, and `Z` takes constant time.
        *   Calculating `profit = X * (Z - Y)` involves a few arithmetic operations (subtraction and multiplication), which take constant time.
        *   Printing the `profit` takes constant time.
    *   Since each test case is processed in constant time, the total time complexity is directly proportional to the number of test cases, hence $O(T)$.

*   **Space Complexity**: $O(1)$
    *   The solution uses a fixed number of variables (`T`, `X`, `Y`, `Z`, `profit`) to store input and intermediate results. The memory required for these variables does not depend on the input values or the number of test cases. Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <iostream> // Required for input/output operations (cin, cout)

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from the C standard I/O library and
    // prevents synchronization overhead, making I/O faster.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    std::cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int X, Y, Z; // Declare integer variables X, Y, Z for each test case.
        // X: number of stocks
        // Y: price each stock was bought at
        // Z: price each stock can be sold at
        std::cin >> X >> Y >> Z; // Read X, Y, and Z for the current test case.

        // Calculate the total amount spent: X stocks * Y price/stock
        // Calculate the total amount received: X stocks * Z price/stock
        // Profit = Total amount received - Total amount spent
        // Profit = (X * Z) - (X * Y)
        // This can be simplified to: Profit = X * (Z - Y)
        // Given constraints: 1 <= X, Y <= 10^4, Y <= Z <= 10^4
        // Maximum possible value for X * Z or X * Y is 10^4 * 10^4 = 10^8.
        // An 'int' type in C++ typically handles values up to 2 * 10^9,
        // so 'int' is sufficient to store the profit without overflow.
        int profit = X * (Z - Y);

        // Print the calculated profit for the current test case,
        // followed by a newline character as required.
        std::cout << profit << "\n";
    }

    return 0; // Indicate successful program execution.
}
```