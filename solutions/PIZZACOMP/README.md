# [Pizza Comparision (PIZZACOMP)](https://www.codechef.com/problems/PIZZACOMP)
- **Difficulty Rating**: 599
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to compare the "value" of two types of square pizzas:
1.  **Small Pizza**: Has a side length of 10 inches and costs `A` rupees.
2.  **Large Pizza**: Has a side length of 15 inches and costs `B` rupees.

We need to determine which pizza offers more area per rupee. If the small pizza offers more value, output "Small". If the large pizza offers more value, output "Large". If both offer equal value, output "Equal".

## Intuition & Mathematical Observation

To determine which pizza offers more "value," we need to calculate the area per unit cost for each pizza and then compare these values.

1.  **Calculate Area:**
    *   For a square pizza with side length `S`, its area is `S * S`.
    *   **Small Pizza:** Side length = 10 inches. Area = `10 * 10 = 100` square inches.
    *   **Large Pizza:** Side length = 15 inches. Area = `15 * 15 = 225` square inches.

2.  **Calculate Area per Cost:**
    *   **Small Pizza Value:** `Area_Small / Cost_Small = 100 / A`
    *   **Large Pizza Value:** `Area_Large / Cost_Large = 225 / B`

3.  **Compare Ratios without Floating-Point Arithmetic:**
    Comparing `100 / A` and `225 / B` directly using floating-point numbers (like `double` or `float`) can sometimes lead to precision errors, especially in competitive programming. A safer and more accurate approach is to compare them by cross-multiplication.
    To compare `X/Y` with `P/Q` (where Y and Q are positive), we can compare `X * Q` with `P * Y`.
    Applying this to our problem:
    *   Compare `(100 / A)` with `(225 / B)`
    *   This is equivalent to comparing `(100 * B)` with `(225 * A)`.

4.  **Simplify the Comparison:**
    Notice that both 100 and 225 are divisible by 25:
    *   `100 = 4 * 25`
    *   `225 = 9 * 25`
    So, the comparison `(100 * B)` vs `(225 * A)` can be simplified by dividing both sides by 25:
    *   Compare `( (100 / 25) * B )` with `( (225 / 25) * A )`
    *   This simplifies to comparing `(4 * B)` with `(9 * A)`.

    This simplification reduces the magnitude of the numbers involved, making it even safer against potential integer overflows, although for the given constraints (A, B <= 400), `int` would suffice. Using `long long` for the products `4LL * B` and `9LL * A` is a good defensive programming practice.

5.  **Final Decision:**
    *   If `(4 * B) > (9 * A)`, the small pizza offers more value. Output "Small".
    *   If `(9 * A) > (4 * B)`, the large pizza offers more value. Output "Large".
    *   If `(4 * B) == (9 * A)`, both offer equal value. Output "Equal".

## Complexity Analysis

*   **Time Complexity**: For each test case, the solution performs a fixed number of arithmetic operations (multiplications, comparisons) and a print operation. These are all constant-time operations. If there are `T` test cases, the total time complexity will be **$O(T)$**.

*   **Space Complexity**: The solution uses a few integer variables (`A`, `B`, `small_pizza_metric`, `large_pizza_metric`, `T`) to store input and intermediate results. The amount of memory used does not depend on the input values. Therefore, the space complexity is **$O(1)$**.

## Solution Code

```cpp
#include <bits/stdc++.h> // Required include for competitive programming

// Required using directive
using namespace std;

void solve() {
    int A, B;
    cin >> A >> B; // Read costs A and B

    // Small pizza: length 10 inches, area = 10*10 = 100
    // Large pizza: length 15 inches, area = 15*15 = 225

    // We want to maximize Area / Cost.
    // For small pizza: 100 / A
    // For large pizza: 225 / B

    // To compare these fractions (100/A vs 225/B) without using floating-point numbers,
    // we can cross-multiply:
    // Compare (100 * B) with (225 * A)

    // Further simplification: Both 100 and 225 are divisible by 25.
    // 100 / 25 = 4
    // 225 / 25 = 9
    // So, the comparison simplifies to:
    // Compare (4 * B) with (9 * A)

    // Use long long for the products to prevent potential overflow,
    // although for the given constraints (A, B <= 400), int would suffice.
    long long small_pizza_metric = 4LL * B;
    long long large_pizza_metric = 9LL * A;

    if (small_pizza_metric > large_pizza_metric) {
        cout << "Small\n"; // Small pizza offers more area per rupee
    } else if (large_pizza_metric > small_pizza_metric) {
        cout << "Large\n"; // Large pizza offers more area per rupee
    } else {
        cout << "Equal\n"; // Both offer the same area per rupee
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve();
    }

    return 0;
}
```