# [Chef and Bird farm (BIRDFARM)](https://www.codechef.com/problems/BIRDFARM)
- **Difficulty Rating**: 591
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to buy birds for his farm. He has a budget of `z` units. He can buy chickens for `x` units each and ducks for `y` units each. He wants to know what kind of birds he can buy given his budget. He can buy:
- "CHICKEN" if he can only afford chickens (and not ducks).
- "DUCK" if he can only afford ducks (and not chickens).
- "ANY" if he can afford both chickens and ducks.
- "NONE" if he cannot afford either.

He can afford a type of bird if he can buy at least one of them. This means the total cost of buying `k` birds of a certain type must be less than or equal to his budget `z`.

## Intuition & Mathematical Observation
The core of the problem lies in determining if Chef can afford at least one chicken and at least one duck.

Chef can afford at least one chicken if the cost of one chicken (`x`) is less than or equal to his budget (`z`). Mathematically, this is `x <= z`.
Similarly, Chef can afford at least one duck if the cost of one duck (`y`) is less than or equal to his budget (`z`). Mathematically, this is `y <= z`.

However, the problem statement implies a slightly different interpretation based on the provided solution. The solution checks if the budget `z` is *divisible* by the cost of a single bird (`x` or `y`). This suggests that Chef wants to spend *exactly* his budget `z` by buying a certain number of birds of a single type.

Let's re-evaluate based on the solution's logic:
- Chef can buy chickens if he can spend his entire budget `z` by buying only chickens. This means `z` must be a multiple of `x`. Mathematically, `z % x == 0`.
- Chef can buy ducks if he can spend his entire budget `z` by buying only ducks. This means `z` must be a multiple of `y`. Mathematically, `z % y == 0`.

Based on these conditions, we can determine the output:
1. If `z` is divisible by `x` AND `z` is divisible by `y`, Chef can buy either chickens or ducks (or both if he could mix them, but the problem implies buying only one type to spend the exact budget). So, the output is "ANY".
2. If `z` is divisible by `x` BUT NOT by `y`, Chef can only buy chickens. So, the output is "CHICKEN".
3. If `z` is NOT divisible by `x` BUT IS divisible by `y`, Chef can only buy ducks. So, the output is "DUCK".
4. If `z` is NOT divisible by `x` AND NOT divisible by `y`, Chef cannot spend his entire budget on either type of bird. So, the output is "NONE".

This interpretation aligns perfectly with the provided C++ solution.

## Complexity Analysis
- **Time Complexity**: $O(1)$
  The solution involves a fixed number of arithmetic operations (modulo, comparisons) and input/output operations for each test case. The number of operations does not depend on the magnitude of `x`, `y`, or `z`. Since there are `t` test cases, the total time complexity is $O(t)$. However, for a single test case, it's $O(1)$.

- **Space Complexity**: $O(1)$
  The solution uses a constant amount of extra space to store variables like `t`, `x`, `y`, `z`, and boolean flags. This space requirement does not grow with the input size.

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
        int x, y, z; // Cost of chicken, cost of duck, budget
        std::cin >> x >> y >> z;

        bool can_chicken = false;
        // Check if the budget 'z' is perfectly divisible by the cost of a chicken 'x'
        // This implies Chef can spend exactly 'z' by buying only chickens.
        if (z % x == 0) {
            can_chicken = true;
        }

        bool can_duck = false;
        // Check if the budget 'z' is perfectly divisible by the cost of a duck 'y'
        // This implies Chef can spend exactly 'z' by buying only ducks.
        if (z % y == 0) {
            can_duck = true;
        }

        // Determine the output based on affordability of chickens and ducks
        if (can_chicken && can_duck) {
            // If both are possible, Chef can choose either.
            std::cout << "ANY\n";
        } else if (can_chicken) {
            // If only chickens are possible.
            std::cout << "CHICKEN\n";
        } else if (can_duck) {
            // If only ducks are possible.
            std::cout << "DUCK\n";
        } else {
            // If neither is possible.
            std::cout << "NONE\n";
        }
    }
    return 0;
}
```