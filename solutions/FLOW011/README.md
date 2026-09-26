# [Gross Salary (FLOW011)](https://www.codechef.com/problems/FLOW011)
- **Difficulty Rating**: 823
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the gross salary of an employee based on their basic salary. The calculation rules for House Rent Allowance (HRA) and Dearness Allowance (DA) depend on the basic salary:

1.  **If basic salary is less than Rs. 1500**:
    *   HRA = 10% of basic salary
    *   DA = 90% of basic salary
2.  **If basic salary is greater than or equal to Rs. 1500**:
    *   HRA = Rs. 500
    *   DA = 98% of basic salary

The gross salary is the sum of basic salary, HRA, and DA. We need to output the gross salary with exactly two decimal places. The program should handle multiple test cases.

## Intuition & Mathematical Observation

The core of this problem lies in applying conditional logic to determine the HRA and DA components. Once these components are calculated based on the given rules, the gross salary is a straightforward sum.

1.  **Conditional Logic**: We need an `if-else` statement to check the `basic_salary`.
    *   The `if` condition will be `basic_salary < 1500`.
    *   The `else` block will handle `basic_salary >= 1500`.

2.  **Calculations**:
    *   Inside the `if` block: `HRA = 0.10 * basic_salary` and `DA = 0.90 * basic_salary`.
    *   Inside the `else` block: `HRA = 500` and `DA = 0.98 * basic_salary`.

3.  **Final Gross Salary**: In both cases, `Gross Salary = Basic Salary + HRA + DA`.

4.  **Data Types and Output Formatting**: Since salaries can involve decimal values (e.g., 10% of 1000 is 100.00, but 98% of 1500 is 1470.00, and HRA can be 500.00), it's best to use floating-point data types (like `double` in C++). The output requires exactly two decimal places, which can be achieved using `std::fixed` and `std::setprecision(2)` from the `<iomanip>` library.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    For each test case, the program performs a constant number of operations: reading input, one conditional check, a few arithmetic calculations (multiplications and additions), and printing the result. If there are $T$ test cases, the total time complexity will be proportional to $T$, hence $O(T)$.

-   **Space Complexity**: $O(1)$
    The program uses a fixed amount of memory to store variables like `t`, `basic_salary`, `hra`, `da`, and `gross_salary`. The memory usage does not depend on the input values or the number of test cases. Therefore, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, iomanip, etc. for input/output and formatting
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) { // Loop through each test case
        double basic_salary;
        cin >> basic_salary; // Read the basic salary for the current test case

        double hra, da; // Declare variables for House Rent Allowance (HRA) and Dearness Allowance (DA)

        // Apply the conditional rules for HRA and DA calculation
        if (basic_salary < 1500) {
            // Rule 1: Basic salary less than 1500
            hra = 0.10 * basic_salary; // HRA is 10% of basic salary
            da = 0.90 * basic_salary;  // DA is 90% of basic salary
        } else {
            // Rule 2: Basic salary greater than or equal to 1500
            hra = 500;                 // HRA is a fixed 500
            da = 0.98 * basic_salary;  // DA is 98% of basic salary
        }

        // Calculate the gross salary
        double gross_salary = basic_salary + hra + da;

        // Output the gross salary formatted to two decimal places
        // fixed: ensures that the decimal point is always printed and trailing zeros are shown.
        // setprecision(2): sets the number of digits after the decimal point to 2.
        cout << fixed << setprecision(2) << gross_salary << "\n";
    }

    return 0; // Indicate successful execution
}

```