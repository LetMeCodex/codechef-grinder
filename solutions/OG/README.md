# [Origin (OG)](https://www.codechef.com/problems/OG)
- **Difficulty Rating**: 1309
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to calculate the sum of the "origins" of all integers from 1 to a given number $N$. The origin of a positive integer is defined as the single-digit number obtained by repeatedly summing its digits until a single digit is reached. For example, the origin of 123 is $1+2+3=6$. The origin of 99 is $9+9=18$, and then $1+8=9$.

## Intuition & Mathematical Observation

The core of this problem lies in understanding the property of the "origin" of a number. The process of repeatedly summing digits until a single digit is obtained is equivalent to finding the number modulo 9, with a special case for multiples of 9.

Let $S(x)$ be the sum of the digits of a positive integer $x$. It is a well-known property that $x \equiv S(x) \pmod{9}$. This is because any number $x$ can be written as $x = d_k 10^k + d_{k-1} 10^{k-1} + \dots + d_1 10^1 + d_0 10^0$. Since $10 \equiv 1 \pmod{9}$, we have $10^i \equiv 1^i \equiv 1 \pmod{9}$ for any non-negative integer $i$. Therefore,
$x \equiv d_k (1) + d_{k-1} (1) + \dots + d_1 (1) + d_0 (1) \pmod{9}$
$x \equiv d_k + d_{k-1} + \dots + d_1 + d_0 \pmod{9}$
$x \equiv S(x) \pmod{9}$.

By repeatedly applying this property, the final single-digit origin of $x$ will be congruent to $x \pmod{9}$.

Now, let's consider the possible values of the origin:
- If $x$ is not a multiple of 9, then $x \pmod{9}$ will be a value from 1 to 8. The repeated digit sum will eventually yield this value.
- If $x$ is a multiple of 9 (i.e., $x \equiv 0 \pmod{9}$), the repeated digit sum will eventually be 9. For example, $18 \to 1+8=9$, $27 \to 2+7=9$, $99 \to 9+9=18 \to 1+8=9$.

So, the origin of a positive integer $x$ can be expressed as:
- $x \pmod{9}$, if $x \pmod{9} \neq 0$
- $9$, if $x \pmod{9} = 0$

This can be more compactly written as:
Origin$(x) = (x - 1) \pmod{9} + 1$.

Let's verify this formula:
- If $x \pmod{9} = 1$, then $(x-1) \pmod{9} = 0$, so $(x-1) \pmod{9} + 1 = 0 + 1 = 1$. Correct.
- If $x \pmod{9} = 8$, then $(x-1) \pmod{9} = 7$, so $(x-1) \pmod{9} + 1 = 7 + 1 = 8$. Correct.
- If $x \pmod{9} = 0$ (i.e., $x$ is a multiple of 9), then $x-1 \equiv -1 \equiv 8 \pmod{9}$. So $(x-1) \pmod{9} = 8$, and $(x-1) \pmod{9} + 1 = 8 + 1 = 9$. Correct.

The problem asks for the sum of origins from 1 to $N$:
$$ \sum_{i=1}^{N} \text{Origin}(i) = \sum_{i=1}^{N} ((i-1) \pmod{9} + 1) $$
We can split this sum into two parts:
$$ \sum_{i=1}^{N} ((i-1) \pmod{9} + 1) = \sum_{i=1}^{N} (i-1) \pmod{9} + \sum_{i=1}^{N} 1 $$
The second part is simply $N$.
The first part is $\sum_{i=1}^{N} (i-1) \pmod{9}$. Let $j = i-1$. When $i=1$, $j=0$. When $i=N$, $j=N-1$. So the sum becomes:
$$ \sum_{j=0}^{N-1} (j \pmod{9}) $$

Now we need to efficiently calculate the sum of $j \pmod{9}$ for $j$ from 0 to $N-1$.
The sequence $j \pmod{9}$ is $0, 1, 2, 3, 4, 5, 6, 7, 8, 0, 1, 2, \dots$.
The sum of one full cycle of 9 terms ($0$ to $8$) is $0+1+2+3+4+5+6+7+8 = \frac{8 \times 9}{2} = 36$.

Let's consider $N-1$.
Let $M = N-1$. We want to calculate $\sum_{j=0}^{M} (j \pmod{9})$.
The number of full blocks of 9 in the range $[0, M]$ is $\lfloor \frac{M+1}{9} \rfloor$.
The number of terms is $M+1$.
Number of full blocks of 9 is $(M+1) / 9$.
The sum from these full blocks is $\lfloor \frac{M+1}{9} \rfloor \times 36$.

The remaining terms are from $j = \lfloor \frac{M+1}{9} \rfloor \times 9$ up to $M$.
The number of remaining terms is $(M+1) \pmod{9}$.
Let $R = (M+1) \pmod{9}$. The remaining terms are $0, 1, \dots, R-1$.
The sum of these remaining terms is $\sum_{k=0}^{R-1} k = \frac{(R-1)R}{2}$.

So, $\sum_{j=0}^{N-1} (j \pmod{9})$ can be calculated as follows:
Let $K = N$. We need to sum $j \pmod{9}$ for $j$ from $0$ to $K-1$.
Number of full cycles of 9 in $K$ terms: $K / 9$.
Sum from full cycles: $(K / 9) \times 36$.
Number of remaining terms: $K \pmod{9}$.
Sum of remaining terms: $\sum_{i=0}^{(K \pmod{9}) - 1} i$.

Let's refine the `sum_mod_9(n)` function. It should calculate $\sum_{j=0}^{n-1} (j \pmod{9})$.
If `n` is the upper bound for `j` (i.e., we sum up to `n-1`), then:
Number of full blocks of 9 in `n` terms (0 to n-1): `n / 9`.
Sum from full blocks: `(n / 9) * 36`.
Number of remaining terms: `n % 9`.
These remaining terms are $0, 1, \dots, (n \% 9) - 1$.
Sum of remaining terms: $\sum_{i=0}^{(n \% 9) - 1} i$.

Example: $N=10$. We need to sum origins from 1 to 10.
Origins: 1, 2, 3, 4, 5, 6, 7, 8, 9, 1.
Sum = $1+2+3+4+5+6+7+8+9+1 = 46$.

Using the formula:
Sum = $\sum_{j=0}^{9} (j \pmod{9}) + 10$
$\sum_{j=0}^{9} (j \pmod{9}) = (0 \pmod{9}) + (1 \pmod{9}) + \dots + (8 \pmod{9}) + (9 \pmod{9})$
$= 0 + 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 0 = 36$.
Sum = $36 + 10 = 46$. Correct.

Let's test the `sum_mod_9(n)` function with $n=10$.
`num_blocks = 10 / 9 = 1`.
`remainder = 10 % 9 = 1`.
`total_sum = 1 * 36 = 36`.
Loop for remainder: `i` from 0 to `remainder - 1` (i.e., `i=0`).
`total_sum += 0`.
`total_sum = 36`.
This function calculates $\sum_{j=0}^{n-1} (j \pmod{9})$.
So for $N=10$, we call `sum_mod_9(10)`. This calculates $\sum_{j=0}^{9} (j \pmod{9}) = 36$.
The final answer is `sum_mod_9(N) + N`.
For $N=10$, `sum_mod_9(10) + 10 = 36 + 10 = 46$.

The `sum_mod_9` function in the provided code:
```cpp
long long sum_mod_9(long long n) {
    if (n == 0) return 0;
    // We need to sum j % 9 for j from 0 to n-1.
    // Let's consider blocks of 9: 0..8, 9..17, etc.
    // In each block of 9, the sum of (j % 9) is 0+1+..+8 = 36.
    long long num_blocks = n / 9; // Number of full blocks of 9 in 'n' terms (0 to n-1)
    long long remainder = n % 9; // Number of remaining terms

    long long total_sum = num_blocks * 36; // Sum for full blocks of 9

    // Sum for the remaining part
    // The remaining terms are 0, 1, ..., remainder-1
    for (long long i = 0; i < remainder; ++i) {
        total_sum += i;
    }
    return total_sum;
}
```
This function correctly calculates $\sum_{j=0}^{n-1} (j \pmod{9})$.
The main logic `sum_of_origins = sum_mod_9(n) + n;` is also correct.

The `get_origin` function is not used in the final solution but is a direct implementation of the digit sum process. It's useful for understanding the concept but not for efficient calculation.

## Complexity Analysis

- **Time Complexity**: The `main` function reads the number of test cases $t$. For each test case, it reads $N$ and calls `sum_mod_9(n)`. The `sum_mod_9` function performs a constant number of arithmetic operations and a loop that runs at most 8 times (for `remainder < 9`). Therefore, the time complexity for each test case is $O(1)$. The total time complexity is $O(t)$.

- **Space Complexity**: The solution uses a few variables to store intermediate results. The space complexity is $O(1)$ per test case.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

// Function to calculate the sum of (i-1)%9 for i from 1 to n.
// This is equivalent to sum of j%9 for j from 0 to n-1.
long long sum_mod_9(long long n) {
    if (n == 0) return 0;
    // We need to sum j % 9 for j from 0 to n-1.
    // The sequence j % 9 is 0, 1, ..., 8, 0, 1, ...
    // The sum of one full block of 9 terms (0 to 8) is 36.

    // Number of full blocks of 9 in 'n' terms (from 0 to n-1).
    // For example, if n=10, we consider j=0 to 9. There is one full block (0-8).
    long long num_blocks = n / 9;

    // Number of remaining terms after the full blocks.
    // For n=10, remainder is 1 (term j=9).
    long long remainder = n % 9;

    // Sum from the full blocks. Each block sums to 36.
    long long total_sum = num_blocks * 36;

    // Sum for the remaining part.
    // The remaining terms are 0, 1, ..., remainder-1.
    // For n=10, remainder=1, so we sum for i=0.
    for (long long i = 0; i < remainder; ++i) {
        total_sum += i;
    }
    return total_sum;
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        long long n; // Input number
        std::cin >> n;

        // The origin of a positive integer x is (x-1) % 9 + 1.
        // We need to calculate sum_{i=1 to N} ((i-1) % 9 + 1)
        // This can be rewritten as:
        // sum_{i=1 to N} (i-1) % 9 + sum_{i=1 to N} 1
        // Let j = i-1. When i=1, j=0. When i=N, j=N-1.
        // So, the sum is sum_{j=0 to N-1} (j % 9) + N

        // Calculate sum_{j=0 to N-1} (j % 9) using the helper function.
        long long sum_of_mod_9_terms = sum_mod_9(n);

        // The total sum of origins is the sum of mod 9 terms plus N.
        long long sum_of_origins = sum_of_mod_9_terms + n;

        std::cout << sum_of_origins << "\n";
    }
    return 0;
}
```