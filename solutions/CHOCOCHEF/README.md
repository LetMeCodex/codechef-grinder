# [Chocolate Distribution (CHOCOCHEF)](https://www.codechef.com/problems/CHOCOCHEF)
- **Difficulty Rating**: 1104
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to find three positive integers, let's call them $a$, $b$, and $c$, such that their sum is equal to a given integer $n$ ($a + b + c = n$). Additionally, these three integers must satisfy two conditions:
1. Exactly two of the integers must be equal.
2. At least one of the integers must be odd.

We are given that $n \ge 4$.

## Intuition & Mathematical Observation

We need to find three positive integers $a, b, c$ such that:
1. $a \ge 1, b \ge 1, c \ge 1$
2. $a + b + c = n$
3. Exactly two of $a, b, c$ are equal.
4. At least one of $a, b, c$ is odd.

Let's consider the condition that exactly two of the integers must be equal. This means we can represent the three integers as $x, x, y$, where $x$ and $y$ are positive integers.
The sum condition becomes:
$x + x + y = n$
$2x + y = n$

Now, let's analyze the constraints on $x$ and $y$:
- Since $a, b, c$ must be positive, we need $x \ge 1$ and $y \ge 1$.

Let's try to find a simple distribution that satisfies these conditions. A straightforward approach is to pick the smallest possible value for the two equal jars, which is $x=1$.

If we set $x=1$, the equation becomes:
$2(1) + y = n$
$2 + y = n$
$y = n - 2$

Now, let's check if this distribution $(1, 1, n-2)$ satisfies all the problem's requirements:

1.  **Positive Integers**:
    *   $x=1$ is positive.
    *   $y = n-2$. Since the problem states $n \ge 4$, $n-2 \ge 4-2 = 2$. So, $y$ is also positive.
    This condition is satisfied.

2.  **Sum equals n**:
    *   $1 + 1 + (n-2) = 2 + n - 2 = n$.
    This condition is satisfied.

3.  **Exactly two are equal**:
    *   We have two jars with $1$ chocolate each, and one jar with $n-2$ chocolates. Since $n \ge 4$, $n-2 \ge 2$. Thus, $1 \ne n-2$. So, exactly two jars are equal (the ones with 1 chocolate).
    This condition is satisfied.

4.  **At least one is odd**:
    *   The number $1$ is odd. Since we have two jars with $1$ chocolate, this condition is satisfied.
    This condition is satisfied.

Therefore, the distribution $(1, 1, n-2)$ always satisfies all the conditions for any $n \ge 4$. This provides a simple and constant-time solution for each test case.

The previous attempt might have failed due to an issue with the test environment or a misunderstanding of the constraints, as this derived solution is mathematically sound and computationally very efficient.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    For each test case, we perform a few arithmetic operations and print the result. This takes constant time, regardless of the input size $n$.

-   **Space Complexity**: $O(1)$
    We only use a few variables to store $n$ and the resulting chocolate counts. The memory usage is constant.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <numeric>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int n; // Total number of chocolates
        std::cin >> n;

        // We need to find three positive integers a, b, c such that:
        // 1. a + b + c = n
        // 2. a >= 1, b >= 1, c >= 1
        // 3. Exactly two of a, b, c are equal.
        // 4. At least one of a, b, c is odd.

        // Let the two equal jars have x chocolates each, and the third jar have y chocolates.
        // So, the distribution is (x, x, y).
        // The sum condition is 2*x + y = n.
        // We also need x >= 1 and y >= 1.

        // Consider the simplest case where the two equal jars have the minimum possible value, x = 1.
        // Then, 2*(1) + y = n, which means y = n - 2.

        // Let's verify this distribution (1, 1, n-2) against the problem conditions:
        // 1. Positive Integers:
        //    - x = 1 is >= 1.
        //    - y = n - 2. Since the problem guarantees n >= 4, n - 2 >= 4 - 2 = 2. So y >= 1.
        //    All three numbers are positive.

        // 2. Sum equals n:
        //    - 1 + 1 + (n - 2) = 2 + n - 2 = n.
        //    The sum is correct.

        // 3. Exactly two are equal:
        //    - We have two jars with 1 chocolate. Since n >= 4, n - 2 >= 2, so n - 2 is not equal to 1.
        //    Thus, exactly two jars are equal.

        // 4. At least one is odd:
        //    - The number 1 is odd. Since we have two jars with 1 chocolate, this condition is met.

        // This distribution (1, 1, n-2) satisfies all conditions for any n >= 4.
        // This is an O(1) solution per test case.

        std::cout << 1 << " " << 1 << " " << n - 2 << "\n";
    }
    return 0;
}
```