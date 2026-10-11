# [N Queens Puzzle Solved ! (EUREKA)](https://www.codechef.com/problems/EUREKA)
- **Difficulty Rating**: 1109
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to calculate a specific value based on an input integer `n`. The formula provided is:

$$ \text{Result} = \lfloor (0.143 \times n)^n + 0.5 \rfloor $$

This means we need to compute $(0.143 \times n)$ raised to the power of `n`, and then round the result to the nearest integer.

## Intuition & Mathematical Observation
The problem statement directly provides the formula to compute the result. There isn't a complex algorithmic intuition required here, but rather a careful implementation of the given mathematical formula.

The core of the problem lies in accurately computing $(0.143 \times n)^n$ and then rounding it.

1.  **Floating-Point Precision**: The base `0.143` is a floating-point number. When multiplied by `n` and then raised to the power of `n`, the result can be a large or small floating-point number. Standard `double` precision in C++ is usually sufficient for this range of calculations, especially given the constraints on `n` (which are typically within reasonable limits for competitive programming problems, though not explicitly stated here, we can infer from the difficulty rating and the nature of the formula).

2.  **Rounding**: The formula specifies rounding to the nearest integer. The common way to achieve this with floating-point numbers is to add `0.5` and then take the floor (or cast to an integer type).
    *   If the fractional part is less than `0.5`, adding `0.5` will not change the integer part. For example, `3.4 + 0.5 = 3.9`, and `floor(3.9)` is `3`.
    *   If the fractional part is `0.5` or greater, adding `0.5` will increase the integer part by one. For example, `3.5 + 0.5 = 4.0`, and `floor(4.0)` is `4`. Similarly, `3.6 + 0.5 = 4.1`, and `floor(4.1)` is `4`.

    The C++ code uses `static_cast<long long>(result + 0.5)` which effectively performs this rounding. `long long` is used to accommodate potentially large integer results.

The problem is essentially a direct implementation of a mathematical formula, testing the ability to handle floating-point arithmetic and rounding correctly.

## Complexity Analysis
- **Time Complexity**: $O(\log n)$
    The dominant operation is `std::pow(base, n)`. The `pow` function for floating-point numbers typically uses an algorithm like exponentiation by squaring, which has a time complexity logarithmic to the exponent `n`. The multiplication and addition operations are $O(1)$. Therefore, the overall time complexity is $O(\log n)$.

- **Space Complexity**: $O(1)$
    The solution uses a fixed number of variables (`t`, `n`, `base`, `result`, `rounded_result`) regardless of the input size `n`. Thus, the space complexity is constant.

## Solution Code
```cpp
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int n; // Input integer
        std::cin >> n;

        // Calculate the base for the exponentiation
        double base = 0.143 * n;

        // Calculate (0.143 * n)^n
        double result = std::pow(base, n);

        // Round the result to the nearest integer.
        // Adding 0.5 and casting to a long long effectively rounds to the nearest integer.
        // For example:
        // 3.4 + 0.5 = 3.9 -> static_cast<long long>(3.9) = 3
        // 3.5 + 0.5 = 4.0 -> static_cast<long long>(4.0) = 4
        // 3.6 + 0.5 = 4.1 -> static_cast<long long>(4.1) = 4
        long long rounded_result = static_cast<long long>(result + 0.5);

        // Output the rounded result followed by a newline
        std::cout << rounded_result << "\n";
    }
    return 0;
}
```