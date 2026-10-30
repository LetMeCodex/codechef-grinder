# [Max Triangle (MAXTRI)](https://www.codechef.com/problems/MAXTRI)
- **Difficulty Rating**: 664
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, you have a set of sticks with lengths $1, 2, 3, \dots, N$. The task is to find the maximum possible perimeter of a non-degenerate triangle that can be formed using three distinct sticks from this set. If no non-degenerate triangle can be formed, output -1.

## Intuition & Mathematical Observation

To maximize the perimeter of a triangle, we should intuitively choose the three longest available sticks. Let the lengths of the three chosen sticks be $a, b, c$, where $c$ is the longest side. For these three sticks to form a non-degenerate triangle, they must satisfy the triangle inequality:
1. $a + b > c$
2. $a + c > b$
3. $b + c > a$

Since we are picking the three longest sticks, let their lengths be $c = N$, $b = N-1$, and $a = N-2$. We need to check if these lengths satisfy the triangle inequality.

The inequalities $a + c > b$ and $b + c > a$ will always be satisfied because $c$ is the largest side and $a, b$ are positive. For example, $a + c = (N-2) + N = 2N - 2$. Since $b = N-1$, and for $N \ge 2$, $2N - 2 > N-1$ (which simplifies to $N > 1$), this inequality holds. Similarly for $b+c > a$.

The critical inequality to check is $a + b > c$. Substituting our chosen stick lengths:
$(N-2) + (N-1) > N$
$2N - 3 > N$
$N > 3$

This means that if $N > 3$, the three longest sticks ($N, N-1, N-2$) will always form a non-degenerate triangle. The perimeter in this case would be $N + (N-1) + (N-2) = 3N - 3$.

Now, let's consider the edge cases:

*   **$N < 3$**: If $N$ is 1 or 2, we don't even have three sticks to form a triangle. So, no triangle can be formed. The output should be -1.

*   **$N = 3$**: The available sticks are 1, 2, and 3.
    *   If we pick 1, 2, 3: The longest side is 3. The sum of the other two sides is $1 + 2 = 3$. Since $3 \ngtr 3$, this forms a degenerate triangle.
    *   Any other combination of three sticks is not possible as there are only three sticks.
    Therefore, for $N=3$, no non-degenerate triangle can be formed. The output should be -1.

*   **$N = 4$**: The available sticks are 1, 2, 3, 4.
    *   The three longest sticks are 4, 3, 2.
    *   Longest side $c = 4$.
    *   Sum of other two sides $a + b = 2 + 3 = 5$.
    *   Since $5 > 4$, a non-degenerate triangle can be formed.
    *   The perimeter is $4 + 3 + 2 = 9$.
    *   This aligns with our condition $N > 3$.

So, the logic is:
- If $N < 3$, output -1.
- If $N = 3$, output -1.
- If $N \ge 4$, output $3N - 3$.

This can be simplified to:
- If $N < 4$, output -1.
- If $N \ge 4$, output $3N - 3$.

## Complexity Analysis

- **Time Complexity**: $O(1)$
    The solution involves a few constant-time comparisons and arithmetic operations for each test case. The number of test cases is read once, and then the loop runs a fixed number of times based on the input $t$.

- **Space Complexity**: $O(1)$
    The solution uses a fixed amount of memory to store variables like $t$, $n$, and the perimeter, regardless of the input size $N$.

## Solution Code

```cpp
#include <iostream>
#include <algorithm>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        long long n; // The maximum length of a stick available
        std::cin >> n;

        // A non-degenerate triangle requires at least 3 sticks.
        // If n < 3, we don't have enough sticks.
        // For n = 3, the sticks are 1, 2, 3. The longest side is 3.
        // The sum of the other two sides is 1 + 2 = 3.
        // Since 3 is not strictly greater than 3, a degenerate triangle is formed.
        // Thus, for n < 4, no non-degenerate triangle can be formed.
        if (n < 4) {
            std::cout << -1 << "\n";
        } else {
            // To maximize the perimeter, we pick the three largest sticks: n, n-1, and n-2.
            // For n >= 4, these sticks form a valid non-degenerate triangle because:
            // (n-2) + (n-1) > n  => 2n - 3 > n => n > 3.
            // The perimeter is the sum of these three lengths.
            long long perimeter = n + (n - 1) + (n - 2);
            std::cout << perimeter << "\n";
        }
    }
    return 0;
}
```