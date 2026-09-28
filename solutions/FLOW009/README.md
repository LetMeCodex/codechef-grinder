# [Total Expenses (FLOW009)](https://www.codechef.com/problems/FLOW009)
- **Difficulty Rating**: 861
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the total expenses for purchasing a certain quantity of items, given their individual price. A special condition applies: if the total quantity of items purchased is strictly greater than 1000, a 10% discount is applied to the total cost. Otherwise, no discount is given. We need to output the final expenses, formatted to exactly 6 decimal places. This process needs to be repeated for multiple test cases.

## Intuition & Mathematical Observation

1.  **Input Reading**: We first read the number of test cases, `T`. Then, for each test case, we read the `quantity` and `price` of the items.

2.  **Data Type Considerations**:
    *   The `quantity` and `price` can each be up to 100,000.
    *   The product `quantity * price` (the total cost before discount) can be as large as `100,000 * 100,000 = 10,000,000,000` (10 billion).
    *   A standard 32-bit integer (`int` in C++) typically has a maximum value of approximately `2 * 10^9`. This means `quantity * price` will overflow a standard `int`.
    *   To correctly store the product, we must use `long long` for `quantity`, `price`, and their product. `long long` can hold values up to approximately `9 * 10^18`, which is sufficient.

3.  **Discount Logic**:
    *   We check if `quantity > 1000`.
    *   If true, a 10% discount is applied. This means the customer pays 90% of the original total cost. Mathematically, `final_expenses = (quantity * price) * 0.90`.
    *   If false (`quantity <= 1000`), no discount is applied. The `final_expenses` are simply `quantity * price`.

4.  **Floating-Point Arithmetic and Output Formatting**:
    *   Since the discount involves multiplication by `0.90`, the result can be a decimal number. Therefore, the `final_expenses` should be stored in a floating-point data type, such as `double`.
    *   The problem requires the output to be formatted to exactly 6 decimal places. This can be achieved using `std::fixed` and `std::setprecision(6)` from the `<iomanip>` library when printing to `std::cout`.

5.  **Fast I/O**: For competitive programming problems with multiple test cases or large inputs, it's good practice to use fast I/O by including `ios_base::sync_with_stdio(false);` and `cin.tie(NULL);` at the beginning of the `main` function.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    *   The program iterates `T` times, once for each test case.
    *   Inside each test case, we perform a constant number of operations: reading two `long long` integers, one multiplication, one comparison, one conditional multiplication (or assignment), and printing a `double` with specific formatting. All these operations take constant time.
    *   Therefore, the total time complexity is directly proportional to the number of test cases, $O(T)$.

*   **Space Complexity**: $O(1)$
    *   The program uses a fixed number of variables (`T`, `quantity`, `price`, `total_cost_before_discount_ll`, `final_expenses`) regardless of the input values or the number of test cases.
    *   These variables occupy a constant amount of memory.
    *   Thus, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, iomanip, etc.

// Using namespace std; as requested by the problem instructions.
using namespace std;

int main() {
    // Include fast I/O inside main() as requested.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the total number of test cases.

    // Loop through each test case.
    while (T--) {
        long long quantity; // Use long long for quantity to handle values up to 100000.
        long long price;    // Use long long for price to handle values up to 100000.
        cin >> quantity >> price; // Read quantity and price for the current test case.

        // Calculate the total cost before any discount.
        // The product (quantity * price) can be up to 100000 * 100000 = 10^10.
        // This value exceeds the maximum capacity of a 32-bit integer (approx 2*10^9),
        // so `long long` is necessary to prevent integer overflow.
        long long total_cost_before_discount_ll = quantity * price;
        
        double final_expenses; // Variable to store the final calculated expenses, which can be a decimal.

        // Check if the quantity purchased is more than 1000 to apply the discount.
        if (quantity > 1000) {
            // If quantity is more than 1000, a 10% discount is offered.
            // This means the customer pays 90% of the original price.
            // We cast `total_cost_before_discount_ll` to `double` before multiplying by 0.90
            // to ensure floating-point arithmetic for the discount calculation.
            final_expenses = static_cast<double>(total_cost_before_discount_ll) * 0.90;
        } else {
            // If quantity is 1000 or less, no discount is applied.
            // The final expenses are simply the total cost before discount.
            final_expenses = static_cast<double>(total_cost_before_discount_ll);
        }

        // Output the total expenses.
        // `fixed` ensures that the output is in fixed-point notation (not scientific).
        // `setprecision(6)` sets the number of digits to be displayed after the decimal point to 6,
        // as required by the sample output format.
        cout << fixed << setprecision(6) << final_expenses << "\n";
    }

    return 0; // Indicate successful execution.
}
```