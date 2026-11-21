# [Strange Number (STRNO)](https://www.codechef.com/problems/STRNO)
- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if there exists an integer `A` that satisfies two conditions given two integers `X` and `K`:
1. `A` must have exactly `X` positive integer divisors.
2. `A` must have exactly `K` distinct prime numbers among its divisors (i.e., `K` distinct prime factors).

We need to output `1` if such an `A` exists, and `0` otherwise. This needs to be done for `T` test cases.

## Intuition & Mathematical Observation

Let's denote the prime factorization of an integer `A` as $A = p_1^{a_1} \cdot p_2^{a_2} \cdot \ldots \cdot p_m^{a_m}$, where $p_1, p_2, \ldots, p_m$ are distinct prime numbers and $a_1, a_2, \ldots, a_m$ are positive integer exponents ($a_i \ge 1$).

Now, let's translate the given conditions into mathematical terms:

**Condition 2: `A` has exactly `K` distinct prime factors.**
From our prime factorization definition, the number of distinct prime factors of `A` is $m$. Therefore, this condition implies $m = K$.
So, the prime factorization of `A` must look like $A = p_1^{a_1} \cdot p_2^{a_2} \cdot \ldots \cdot p_K^{a_K}$.

**Condition 1: `A` has exactly `X` positive integer divisors.**
The formula for the number of positive divisors of an integer $A = p_1^{a_1} \cdot p_2^{a_2} \cdot \ldots \cdot p_K^{a_K}$ is given by $\tau(A) = (a_1+1)(a_2+1)\ldots(a_K+1)$.
Therefore, this condition implies $X = (a_1+1)(a_2+1)\ldots(a_K+1)$.

Combining these, the problem reduces to: Can `X` be expressed as a product of `K` integers, say $T_1, T_2, \ldots, T_K$, such that each $T_i \ge 2$?
(Since $a_i \ge 1$, it follows that $a_i+1 \ge 2$. So, each $T_i = a_i+1$ must be at least 2.)

Let's consider the prime factorization of `X` itself. Suppose $X = q_1 \cdot q_2 \cdot \ldots \cdot q_P$, where $q_j$ are prime factors of `X` (counting multiplicity). The total number of prime factors of `X` (counting multiplicity) is $P$. This is often denoted as $\Omega(X)$.

- If we need to express `X` as a product of `K` terms, each $\ge 2$, and the total number of prime factors of `X` is $P$:
  - If $P < K$: It's impossible to form `K` terms, each of which is $\ge 2$, whose product is `X`. Each term $\ge 2$ must have at least one prime factor. If `X` has fewer than `K` prime factors in total, we cannot distribute them among `K` terms such that each term is $\ge 2$.
  - If $P \ge K$: It is always possible to construct such a product. We can assign the first $K-1$ prime factors of `X` to $T_1, \ldots, T_{K-1}$ (i.e., $T_j = q_j$ for $j=1, \ldots, K-1$). For the $K$-th term, we group the remaining prime factors: $T_K = q_K \cdot q_{K+1} \cdot \ldots \cdot q_P$.
    Since all $q_j$ are prime numbers, $q_j \ge 2$. Thus, each $T_j$ constructed this way will be $\ge 2$.
    For example, if $X = q_1 \cdot q_2 \cdot q_3 \cdot q_4$ and $K=3$:
    We can set $T_1 = q_1$, $T_2 = q_2$, and $T_3 = q_3 \cdot q_4$. All $T_i \ge 2$.
    Then we can find $a_i$ such that $a_i+1 = T_i$, which means $a_i \ge 1$.

Therefore, the condition simplifies to: the total number of prime factors of `X` (counting multiplicity), $\Omega(X)$, must be greater than or equal to `K`.

The `count_total_prime_factors` function in the provided code correctly calculates $\Omega(n)$.

## Complexity Analysis

-   **Time Complexity**:
    The `count_total_prime_factors(int n)` function iterates `i` from `2` up to `sqrt(n)`. Inside the loop, the `while` loop divides `n` by `i` repeatedly. The total number of divisions across all `i` values is at most $\log n$. The dominant part is the outer loop, which runs up to `sqrt(n)` iterations. Thus, one call to `count_total_prime_factors(n)` takes $O(\sqrt{n})$ time.
    There are `T` test cases. In each test case, we call `count_total_prime_factors(X)`.
    Given $T \le 1000$ and $X_{max} = 10^9$, the total time complexity is $O(T \cdot \sqrt{X_{max}})$.
    $1000 \cdot \sqrt{10^9} \approx 1000 \cdot 31622 \approx 3.16 \cdot 10^7$ operations, which is well within typical time limits (usually $10^8$ operations per second).

-   **Space Complexity**:
    The `count_total_prime_factors` function uses a few integer variables (`count`, `i`, `n`). This is $O(1)$ auxiliary space.
    The `main` function also uses a few integer variables (`T`, `X`, `K`, `omega_X`). This is also $O(1)$ auxiliary space.
    Therefore, the total space complexity is $O(1)$.

## Solution Code

```cpp
#include <iostream>

// Function to calculate the total number of prime factors of n (counting multiplicity)
// This is often denoted as Omega(n)
int count_total_prime_factors(int n) {
    int count = 0;
    // Iterate from 2 up to sqrt(n)
    for (int i = 2; i * i <= n; ++i) {
        // If i divides n, it's a prime factor
        while (n % i == 0) {
            count++;
            n /= i;
        }
    }
    // If n is still greater than 1 after the loop, it means the remaining n is a prime factor itself
    // (e.g., if n was initially a prime number, or if it's the largest prime factor)
    if (n > 1) {
        count++;
    }
    return count;
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;
    while (T--) {
        int X, K;
        std::cin >> X >> K;

        // The problem asks if there exists an integer A such that:
        // 1. A has exactly X positive integer divisors.
        // 2. A has exactly K prime numbers among its divisors (i.e., K distinct prime factors).
        //
        // Let A = p_1^a_1 * p_2^a_2 * ... * p_m^a_m be the prime factorization of A,
        // where p_i are distinct primes and a_i >= 1.
        //
        // From condition 2, m = K.
        // So, A = p_1^a_1 * p_2^a_2 * ... * p_K^a_K.
        //
        // From condition 1, the number of divisors of A is X.
        // The formula for the number of divisors is (a_1+1)(a_2+1)...(a_K+1).
        // So, X = (a_1+1)(a_2+1)...(a_K+1).
        //
        // Since a_i >= 1, it implies a_i+1 >= 2 for all i.
        // Thus, we need to determine if X can be expressed as a product of K integers,
        // each of which is greater than or equal to 2.
        //
        // This is equivalent to checking if X has at least K prime factors,
        // when counting multiplicity.
        //
        // If X has fewer than K prime factors (counting multiplicity), it's impossible.
        // If X has exactly P prime factors (counting multiplicity), and P >= K,
        // we can always construct such a product.
        // Let X = q_1 * q_2 * ... * q_P be the prime factors of X.
        // We can set a_1+1 = q_1, ..., a_{K-1}+1 = q_{K-1}, and
        // a_K+1 = q_K * q_{K+1} * ... * q_P.
        // Since all q_i >= 2, all a_i+1 >= 2, which means all a_i >= 1.
        // The product (a_1+1)...(a_K+1) will be X.
        //
        // So the condition is simply: count_total_prime_factors(X) >= K.

        int omega_X = count_total_prime_factors(X);

        if (omega_X >= K) {
            std::cout << 1 << "\n";
        } else {
            std::cout << 0 << "\n";
        }
    }

    return 0;
}
```