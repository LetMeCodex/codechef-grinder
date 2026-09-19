# Test Score (CHEFSCORE)
- **Difficulty Rating**: 610
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to achieve a total score of $Y$. There are $N$ problems, and each problem is worth $X$ marks. Chef can choose to solve any subset of these $N$ problems. If Chef solves $k$ problems, their total score will be $k \times X$. We need to determine if it's possible for Chef to achieve a total score of exactly $Y$.

## Intuition & Mathematical Observation
The core of this problem lies in understanding how Chef's score is calculated. Chef can only achieve scores that are multiples of $X$, because each solved problem adds $X$ marks to the total. If Chef solves $k$ problems, the total score will be $k \times X$.

Therefore, to achieve a total score of $Y$, two conditions must be met:

1.  **$Y$ must be a multiple of $X$**: This means that $Y$ divided by $X$ must result in an integer. Mathematically, this can be checked using the modulo operator: $Y \pmod X == 0$.
2.  **The number of problems required to achieve $Y$ must not exceed the total number of available problems $N$**: If $Y$ is a multiple of $X$, the number of problems Chef needs to solve is $k = Y / X$. This value of $k$ must be less than or equal to $N$. So, $Y / X \le N$.

There's a special case to consider: if the target score $Y$ is 0. Chef can always achieve a score of 0 by simply not solving any problems. This is always possible, regardless of $N$ and $X$.

Combining these observations:
- If $Y = 0$, the answer is always "YES".
- If $Y > 0$:
    - If $Y$ is not divisible by $X$ (i.e., $Y \pmod X \neq 0$), then it's impossible to achieve $Y$. The answer is "NO".
    - If $Y$ is divisible by $X$ (i.e., $Y \pmod X == 0$), we then check if the number of problems required, $Y/X$, is less than or equal to $N$.
        - If $Y/X \le N$, the answer is "YES".
        - If $Y/X > N$, the answer is "NO".

## Complexity Analysis
- **Time Complexity**: $O(1)$
    The solution involves a few arithmetic operations (modulo, division) and comparisons. These operations take constant time. Since the operations are independent of the input size $N$, $X$, and $Y$ (within their integer limits), the time complexity is constant.

- **Space Complexity**: $O(1)$
    The solution uses a fixed number of variables to store input values and intermediate results ($t, n, x, y$, and `problems_needed`). The memory usage does not grow with the input size, hence the space complexity is constant.

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
        int n; // Total number of problems
        int x; // Marks per problem
        int y; // Target score
        std::cin >> n >> x >> y;

        // Chef can achieve exactly Y marks if Y is a multiple of X,
        // and the number of problems contributing to Y (i.e., Y/X)
        // is less than or equal to the total number of problems N.

        // Case 1: Target score is 0. Always possible by solving 0 problems.
        if (y == 0) {
            std::cout << "YES\n";
        }
        // Case 2: Target score is positive.
        else if (y % x == 0) { // Check if Y is a multiple of X
            int problems_needed = y / x; // Calculate the number of problems required
            // Check if the required number of problems is within the available limit
            if (problems_needed <= n) {
                std::cout << "YES\n";
            } else {
                std::cout << "NO\n"; // Not enough problems available
            }
        }
        // Case 3: Target score is positive but not a multiple of X. Impossible.
        else {
            std::cout << "NO\n";
        }
    }
    return 0;
}
```