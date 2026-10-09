# Chefland Visa (VISA)

- **Difficulty Rating**: 857
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef wants to travel to Chefland. To get a visa, he needs to satisfy three conditions:
1. His current savings ($x_1$) must be less than or equal to the required savings ($x_2$).
2. His current spending per month ($y_1$) must be less than or equal to the required spending per month ($y_2$).
3. His current balance in his bank account ($z_1$) must be greater than or equal to the required balance ($z_2$).

If all three conditions are met, Chef can get a visa. Otherwise, he cannot.

## Intuition & Mathematical Observation

The problem statement directly translates the visa requirements into three distinct conditions that must all be true for Chef to obtain a visa. Let's represent the given values:

- $x_1$: Chef's current savings.
- $x_2$: Required savings for the visa.
- $y_1$: Chef's current spending per month.
- $y_2$: Required spending per month for the visa.
- $z_1$: Chef's current balance in his bank account.
- $z_2$: Required balance in his bank account for the visa.

The conditions for getting a visa are:
1. Chef's current savings must be at least the required savings: $x_1 \le x_2$.
2. Chef's current spending per month must be at most the required spending per month: $y_1 \le y_2$.
3. Chef's current bank balance must be at least the required balance: $z_1 \ge z_2$.

If and only if all three of these inequalities hold true, Chef can get a visa. This is a straightforward logical AND operation.

Therefore, the core of the solution is to read the six input values and check if `x2 >= x1` AND `y2 >= y1` AND `z2 <= z1`.

## Complexity Analysis

- **Time Complexity**: $O(1)$
    The solution involves reading a fixed number of input variables and performing a few constant-time comparisons and logical operations for each test case. The number of test cases is also handled within a loop, but the operations inside the loop are constant.

- **Space Complexity**: $O(1)$
    The solution uses a fixed number of integer variables to store the input values and perform calculations. The memory usage does not grow with the input size.

## Solution Code

```cpp
#include <iostream>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int x1, x2, y1, y2, z1, z2;
        // Read the input values for each test case
        std::cin >> x1 >> x2 >> y1 >> y2 >> z1 >> z2;

        // Check if all three visa conditions are met
        // Condition 1: x2 >= x1 (Required savings >= Current savings)
        // Condition 2: y2 >= y1 (Required spending <= Current spending)
        // Condition 3: z2 <= z1 (Required balance <= Current balance)
        if (x2 >= x1 && y2 >= y1 && z2 <= z1) {
            std::cout << "YES\n"; // All conditions met, Chef gets a visa
        } else {
            std::cout << "NO\n";  // At least one condition not met, Chef does not get a visa
        }
    }
    return 0;
}
```