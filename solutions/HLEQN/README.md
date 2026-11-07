# [Hello Equation (HLEQN)](https://www.codechef.com/problems/HLEQN)
- **Difficulty Rating**: 1315
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a given positive integer $X$ can be represented in the form $2a + 2b + ab$, where $a$ and $b$ are positive integers ($a > 0, b > 0$).

## Intuition & Mathematical Observation

The core of the problem lies in transforming the given equation into a more manageable form. The equation is:
$2a + 2b + ab = X$

We can observe that this expression is close to a factored form if we add a constant to both sides. Let's try adding 4 to both sides:
$ab + 2a + 2b + 4 = X + 4$

Now, the left side can be factored by grouping:
$a(b + 2) + 2(b + 2) = X + 4$
$(a + 2)(b + 2) = X + 4$

Let $A = a + 2$ and $B = b + 2$.
Since $a$ and $b$ are positive integers, $a \ge 1$ and $b \ge 1$.
This implies:
$A = a + 2 \ge 1 + 2 = 3$
$B = b + 2 \ge 1 + 2 = 3$

So, the problem reduces to finding if there exist two integers $A$ and $B$, both greater than or equal to 3, such that their product $A \times B$ equals $X + 4$.

Let $Target = X + 4$. We need to check if $Target$ can be expressed as a product of two integers, both of which are at least 3.

This means we are looking for a divisor $A$ of $Target$ such that:
1. $A \ge 3$
2. $B = Target / A \ge 3$

If we find such a divisor $A$, then $a = A - 2$ and $b = B - 2$ will be positive integers.

To efficiently check for such a pair of factors $(A, B)$, we can iterate through possible values of $A$. We only need to check divisors up to the square root of $Target$. If we find a divisor $A$ such that $3 \le A \le \sqrt{Target}$, then the corresponding $B = Target / A$ will satisfy $B \ge \sqrt{Target}$.

Since $a$ and $b$ must be positive integers, $A$ and $B$ must be at least 3.
If $Target < 9$, it's impossible to find two factors $A, B \ge 3$ whose product is $Target$. For example, if $Target = 8$, the possible pairs of factors are $(1, 8), (2, 4), (4, 2), (8, 1)$. None of these pairs consist of two numbers $\ge 3$.
If $Target \ge 9$, and we find a divisor $A$ such that $3 \le A \le \sqrt{Target}$:
- $A \ge 3$ is satisfied.
- $B = Target / A$. Since $A \le \sqrt{Target}$, $B = Target / A \ge Target / \sqrt{Target} = \sqrt{Target}$.
- Since $Target \ge 9$, $\sqrt{Target} \ge 3$. Therefore, $B \ge 3$.

So, the condition simplifies to: check if $Target = X + 4$ has any divisor $A$ in the range $[3, \sqrt{Target}]$. If such a divisor exists, then $X$ can be represented in the required form.

The algorithm would be:
1. Calculate $Target = X + 4$.
2. If $Target < 9$, output "NO".
3. Iterate from $i = 3$ up to $\lfloor\sqrt{Target}\rfloor$.
4. If $Target$ is divisible by $i$, then we have found a valid pair of factors $(i, Target/i)$, both $\ge 3$. Output "YES" and break.
5. If the loop finishes without finding such a divisor, output "NO".

## Complexity Analysis

- **Time Complexity**: $O(\sqrt{X})$
  For each test case, we iterate up to the square root of $X+4$. The number of test cases is $T$. Therefore, the total time complexity is $O(T \sqrt{X_{max}})$, where $X_{max}$ is the maximum possible value of $X$.

- **Space Complexity**: $O(1)$
  We only use a few variables to store intermediate calculations, regardless of the input size.

## Solution Code

```cpp
#include <iostream>
#include <cmath>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        long long x; // The input integer X
        std::cin >> x;

        // The given equation is 2*a + 2*b + a*b = X
        // We can rewrite this equation by adding 4 to both sides:
        // a*b + 2*a + 2*b + 4 = X + 4
        // This can be factored as:
        // (a + 2)(b + 2) = X + 4
        // Let A = a + 2 and B = b + 2.
        // Since a and b are positive integers (a > 0, b > 0),
        // it implies a >= 1 and b >= 1.
        // Therefore, A = a + 2 >= 1 + 2 = 3, and B = b + 2 >= 1 + 2 = 3.
        // So, we need to find if there exist two integers A and B, both >= 3,
        // such that A * B = X + 4.

        long long target = x + 4;

        // We need to find if 'target' can be expressed as a product of two integers,
        // both of which are greater than or equal to 3.
        // This means we are looking for a divisor 'A' of 'target' such that:
        // 1. A >= 3
        // 2. B = target / A >= 3

        // If target < 9, it's impossible to have two factors >= 3.
        // For example, if target = 8, max product of two numbers >= 3 is 3*3=9.
        // So, if target < 9, we can immediately say NO.
        bool found = false;
        if (target >= 9) {
            // We only need to check for divisors up to the square root of 'target'.
            // If we find a divisor 'i' such that 3 <= i <= sqrt(target),
            // then target/i will be >= sqrt(target).
            // Since target >= 9, sqrt(target) >= 3.
            // Thus, if i >= 3, then target/i will also be >= 3.
            long long limit = sqrt(target);
            for (long long i = 3; i <= limit; ++i) {
                if (target % i == 0) {
                    // We found a divisor 'i'.
                    // Let A = i and B = target / i.
                    // Since i >= 3 and i <= sqrt(target),
                    // we have A >= 3.
                    // And B = target / i >= target / sqrt(target) = sqrt(target).
                    // Since target >= 9, sqrt(target) >= 3.
                    // So B >= 3.
                    // Thus, we found a pair (A, B) both >= 3.
                    found = true;
                    break; // No need to check further once a valid pair is found
                }
            }
        }

        if (found) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}
```