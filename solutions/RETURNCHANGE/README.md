# Return the Change (RETURNCHANGE)
- **Difficulty Rating**: 763
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to calculate the change a customer should receive from a 100 unit payment, given a cost `x`. The rule for calculating the amount charged is as follows:
1. If the cost `x` is a multiple of 10, the customer is charged `x`.
2. If the cost `x` is not a multiple of 10, the customer is charged the nearest multiple of 10 to `x`.
3. If the cost `x` is equally distant from two nearest multiples of 10 (i.e., ends in 5), it is rounded up to the higher multiple of 10.

We need to output the change, which is `100 - charged_amount`.

## Intuition & Mathematical Observation

The core of the problem lies in determining the "charged amount" based on the given rounding rules. We are essentially asked to round the cost `x` to the nearest multiple of 10, with a tie-breaking rule of rounding up.

Let's consider the cost `x`. We can express `x` in terms of its remainder when divided by 10.
`x = 10 * q + r`, where `q` is the quotient and `r` is the remainder (0 <= r <= 9).

- **Case 1: `r == 0`**
  If the remainder is 0, `x` is already a multiple of 10. According to the problem, the charged amount is `x`.

- **Case 2: `r != 0`**
  If the remainder is not 0, we need to find the nearest multiple of 10. The two nearest multiples of 10 to `x` are `10 * q` (the lower multiple) and `10 * q + 10` (the upper multiple).

  - The distance to the lower multiple (`10 * q`) is `x - (10 * q) = r`.
  - The distance to the upper multiple (`10 * q + 10`) is `(10 * q + 10) - x = (10 * q + 10) - (10 * q + r) = 10 - r`.

  Now, we apply the rounding rules:
  - If `r < 5` (i.e., `r` is 1, 2, 3, or 4), the distance to the lower multiple (`r`) is less than the distance to the upper multiple (`10 - r`). So, we round down to `10 * q`.
  - If `r > 5` (i.e., `r` is 6, 7, 8, or 9), the distance to the lower multiple (`r`) is greater than the distance to the upper multiple (`10 - r`). So, we round up to `10 * q + 10`.
  - If `r == 5`, the cost is equally distant from `10 * q` and `10 * q + 10` (distance is 5 in both cases). The problem states that in this case, we round up. So, we round up to `10 * q + 10`.

Combining the cases for `r != 0`:
- If `r < 5`, charged amount is `10 * q`.
- If `r >= 5`, charged amount is `10 * q + 10`.

This logic can be concisely implemented by checking the remainder.
- If `x % 10 == 0`, charged amount is `x`.
- If `x % 10 < 5`, charged amount is `x - (x % 10)`.
- If `x % 10 >= 5`, charged amount is `x - (x % 10) + 10`.

The problem statement also mentions that if the cost is already a multiple of 10, it's charged as is. Our logic handles this correctly: if `x % 10 == 0`, the remainder is 0, and the charged amount is `x`.

The final step is to calculate the change: `100 - charged_amount`.

## Complexity Analysis

- **Time Complexity**: $O(1)$
  For each test case, we perform a constant number of arithmetic operations (modulo, subtraction, addition, comparison). The number of test cases is read from input, but the computation per test case is independent of the input size `x` (within integer limits).

- **Space Complexity**: $O(1)$
  We only use a few integer variables to store the input `x`, the remainder, the rounded cost, and the number of test cases. The memory usage is constant and does not grow with the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Number of test cases
    cin >> t;
    while (t--) {
        int x; // The cost
        cin >> x;

        int rounded_cost;
        int remainder = x % 10; // Get the last digit

        // Determine the charged amount based on the remainder
        if (remainder == 0) {
            // If x is already a multiple of 10, it's charged as is.
            rounded_cost = x;
        } else {
            // Calculate the lower multiple of 10
            int lower_multiple = x - remainder;
            // Calculate the upper multiple of 10
            int upper_multiple = lower_multiple + 10;

            // Apply rounding rules:
            // If remainder is less than 5, round down.
            // If remainder is 5 or greater, round up (tie-breaking rule).
            if (remainder < 5) {
                rounded_cost = lower_multiple;
            } else { // remainder >= 5, round up
                rounded_cost = upper_multiple;
            }
        }
        
        // The problem states:
        // - If x is a multiple of 10, charged_amount = x.
        //   Our logic: if remainder is 0, rounded_cost = x. Correct.
        // - If x is not a multiple of 10, charged_amount = nearest multiple of 10.
        //   - If remainder < 5, nearest is lower_multiple. Correct.
        //   - If remainder > 5, nearest is upper_multiple. Correct.
        // - If equally distant (remainder == 5), round up.
        //   Our logic: if remainder >= 5, rounds up. Correct.

        // Calculate and print the change from 100
        cout << 100 - rounded_cost << "\n";
    }
    return 0;
}
```