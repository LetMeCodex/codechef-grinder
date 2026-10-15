# [Chef Drinks Tea (TEA)](https://www.codechef.com/problems/TEA)
- **Difficulty Rating**: 591
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef needs a total of `X` liters of tea. He has a jar with a capacity of `Y` liters. Each time Chef refills his jar, it costs `Z` rupees. The problem asks us to calculate the minimum total cost Chef will incur to obtain `X` liters of tea.

## Intuition & Mathematical Observation

The core of this problem is to determine the minimum number of times Chef needs to refill his jar to get `X` liters of tea.

1.  **Refills Calculation**:
    *   Each refill provides `Y` liters of tea.
    *   Chef needs `X` liters in total.
    *   If `X` is perfectly divisible by `Y`, Chef will need `X / Y` refills. For example, if he needs 10 liters and the jar holds 5 liters, he needs `10 / 5 = 2` refills.
    *   If `X` is not perfectly divisible by `Y`, he will need `X / Y` (integer division) refills, plus one additional refill to cover the remaining amount. For example, if he needs 12 liters and the jar holds 5 liters, `12 / 5 = 2` (integer division). This means 2 refills give him 10 liters, but he still needs 2 more. So, a third refill is necessary.
    *   This scenario is a classic application of **ceiling division**. We need `ceil(X / Y)` refills.
    *   In integer arithmetic, for positive integers `A` and `B`, `ceil(A / B)` can be calculated efficiently as `(A + B - 1) / B`.
        *   Let's test this formula:
            *   If `X = 10, Y = 5`: `(10 + 5 - 1) / 5 = 14 / 5 = 2` (integer division). Correct.
            *   If `X = 12, Y = 5`: `(12 + 5 - 1) / 5 = 16 / 5 = 3` (integer division). Correct.

2.  **Total Cost Calculation**:
    *   Once we have the `num_refills`, the total cost is simply `num_refills * Z`, where `Z` is the cost per refill.

3.  **Data Types**:
    *   The constraints state that `X, Y, Z` are up to 100.
    *   The maximum number of refills would be when `X=100` and `Y=1`, resulting in `(100 + 1 - 1) / 1 = 100` refills.
    *   The maximum total cost would be `100` refills * `100` rupees/refill = `10000` rupees.
    *   An `int` type in C++ is typically sufficient to store values up to `2 * 10^9`, so `10000` fits comfortably. However, using `long long` for `total_cost` is a good defensive programming practice in competitive programming to prevent potential overflow issues if constraints were slightly larger, or if intermediate calculations could exceed `int` limits.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    *   The program iterates `T` times, once for each test case.
    *   Inside each test case, it performs a fixed number of arithmetic operations (reading inputs, addition, subtraction, division, multiplication) and prints an output. These operations take constant time, $O(1)$.
    *   Therefore, the total time complexity is directly proportional to the number of test cases, $O(T)$.

*   **Space Complexity**: $O(1)$
    *   The solution uses a constant number of variables (`T`, `X`, `Y`, `Z`, `num_refills`, `total_cost`) to store input values and intermediate results.
    *   The memory usage does not depend on the magnitude of the input values (beyond the fixed size of integer types) or the number of test cases.
    *   Hence, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries for competitive programming

// Using the standard namespace to avoid prefixing std::
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int X, Y, Z; // X: total tea Chef needs, Y: jar capacity, Z: cost per refill
        cin >> X >> Y >> Z; // Read X, Y, and Z for the current test case

        // Calculate the minimum number of refills needed.
        // Chef needs X liters of tea. Each refill provides Y liters.
        // The number of refills must be sufficient to cover X liters.
        // This is a classic ceiling division problem: ceil(X / Y).
        // In integer arithmetic, for positive integers A and B, ceil(A / B) can be
        // calculated as (A + B - 1) / B.
        int num_refills = (X + Y - 1) / Y;

        // The total cost is the number of refills multiplied by the cost per refill (Z).
        // X, Y, Z are up to 100.
        // Maximum num_refills would be (100 + 1 - 1) / 1 = 100 (if X=100, Y=1).
        // Maximum total_cost would be 100 * 100 = 10000.
        // An 'int' type is sufficient for this range, but using 'long long'
        // is a good practice in competitive programming to prevent potential
        // integer overflow in similar problems with larger constraints,
        // as advised by the critical instructions.
        long long total_cost = (long long)num_refills * Z;

        // Output the calculated minimum total cost for the current test case,
        // followed by a newline character.
        cout << total_cost << "\n";
    }

    return 0; // Indicate successful program execution
}
```