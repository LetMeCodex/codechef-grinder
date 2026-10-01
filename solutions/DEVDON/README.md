# [Devouring Donuts (DEVDON)](https://www.codechef.com/problems/DEVDON)
- **Difficulty Rating**: 241
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to calculate the total calories consumed by eating a certain number of donuts. We are given two inputs: the number of donuts eaten ($x$) and the number of calories in each donut ($y$). We need to output the total calories.

## Intuition & Mathematical Observation
The problem is a straightforward multiplication problem. If we eat $x$ donuts, and each donut has $y$ calories, then the total calories consumed is simply the product of the number of donuts and the calories per donut.

Mathematically, this can be expressed as:
Total Calories = Number of Donuts $\times$ Calories per Donut
Total Calories = $x \times y$

The problem statement implies a single test case based on the input format. If there were multiple test cases, the input would typically start with an integer `t` representing the number of test cases. Since this is not the case, we can assume a single calculation is required.

We should consider potential integer overflow. Given the constraints $x \le 10$ and $y \le 300$, the maximum possible product is $10 \times 300 = 3000$. This value fits comfortably within a standard 32-bit integer type. However, in competitive programming, it's a good practice to use `long long` for calculations involving products, especially when constraints might be larger or if intermediate calculations could potentially exceed the limits of `int`. This makes the code more robust against potential future changes in constraints.

## Complexity Analysis
- **Time Complexity**: $O(1)$
The solution involves a single multiplication operation and a single output operation. These operations take constant time, regardless of the input values.

- **Space Complexity**: $O(1)$
The solution uses a fixed amount of memory to store the input variables ($x$ and $y$) and the result. This memory usage does not grow with the input size, hence it's constant.

## Solution Code
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C stdio,
    // potentially speeding up I/O operations.
    // cin.tie(NULL) unties cin from cout, meaning cin operations
    // won't force a flush of cout, further speeding up I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare variables to store the number of donuts (x) and calories per donut (y).
    // Using long long to ensure that the product does not overflow,
    // even though for the given constraints (x <= 10, y <= 300),
    // a standard int would suffice. It's a good practice for robustness.
    long long x, y;

    // Read the input values for x and y from standard input.
    cin >> x >> y;

    // Calculate the total calories consumed.
    // This is simply the product of the number of donuts and the calories per donut.
    long long total_calories = x * y;

    // Output the calculated total calories to standard output, followed by a newline character.
    cout << total_calories << "\n";

    // Return 0 to indicate successful execution of the program.
    return 0;
}
```