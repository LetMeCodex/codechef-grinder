# [Avoid Squares Please (AVDSQUARPLZ)](https://www.codechef.com/problems/AVDSQUARPLZ)
- **Difficulty Rating**: 960
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to construct a permutation $P = [p_1, p_2, \ldots, p_N]$ of integers from $1$ to $N$ such that for any adjacent elements $p_i$ and $p_{i+1}$ (where $1 \le i < N$), their product $p_i \cdot p_{i+1}$ is *not* a perfect square. We need to output any such valid permutation.

## Intuition & Mathematical Observation

The core of the problem lies in understanding when a product of two integers $A \cdot B$ is a perfect square. A number is a perfect square if and only if all exponents in its prime factorization are even. For $A \cdot B$ to be a perfect square, for every prime $p$, the exponent of $p$ in $A$ must have the same parity as the exponent of $p$ in $B$. This means $A$ and $B$ must have the same "square-free part". For example, if $A = k \cdot x^2$ and $B = k \cdot y^2$ where $k$ is square-free, then $A \cdot B = k^2 \cdot (xy)^2 = (kxy)^2$, which is a perfect square.

We need to find a permutation $P$ such that $p_i \cdot p_{i+1}$ is *never* a perfect square. Let's consider the simplest possible permutation: the identity permutation, where $p_i = i$ for all $i$. That is, $P = [1, 2, 3, \ldots, N]$.

For this permutation, we need to check if $i \cdot (i+1)$ is a perfect square for any $i$ from $1$ to $N-1$.

A crucial mathematical property is that any two consecutive positive integers are coprime. That is, for any integer $k \ge 1$, $\gcd(k, k+1) = 1$.
**Proof**: Assume $d$ is a common divisor of $k$ and $k+1$. Then $d$ must divide their difference, $(k+1) - k = 1$. The only positive integer that divides 1 is 1. Thus, $\gcd(k, k+1) = 1$.

Now, if $k \cdot (k+1)$ is a perfect square, and we know $\gcd(k, k+1) = 1$, then it must be that both $k$ and $k+1$ are individually perfect squares.
**Proof**: Let $k \cdot (k+1) = S^2$ for some integer $S$. Since $k$ and $k+1$ share no common prime factors (because they are coprime), for their product to be a perfect square, all prime factors in $k$ must have even exponents, and all prime factors in $k+1$ must also have even exponents. This directly implies that $k$ itself must be a perfect square, and $k+1$ itself must be a perfect square.

So, the problem boils down to: are there any consecutive positive integers $k$ and $k+1$ that are both perfect squares?
Let $k = x^2$ and $k+1 = y^2$ for some non-negative integers $x, y$.
Then we have $y^2 - x^2 = 1$.
Factoring the left side, we get $(y-x)(y+x) = 1$.
Since $k \ge 1$, $x$ and $y$ must be non-negative integers. Specifically, $y > x \ge 0$.
The only way for the product of two integers to be 1 is if both integers are 1 or both are -1.
Since $y > x \ge 0$, $y+x$ must be a positive integer. Therefore, $y+x=1$.
Also, $y-x$ must be a positive integer, so $y-x=1$.
We have a system of equations:
1. $y-x = 1$
2. $y+x = 1$
Adding the two equations: $(y-x) + (y+x) = 1+1 \implies 2y = 2 \implies y = 1$.
Substituting $y=1$ into $y-x=1$: $1-x=1 \implies x=0$.
This gives us $k = x^2 = 0^2 = 0$ and $k+1 = y^2 = 1^2 = 1$.
So, the only consecutive non-negative integers that are both perfect squares are 0 and 1.

However, the problem specifies that the permutation consists of integers from $1$ to $N$. This means $p_i \ge 1$ for all $i$. Consequently, $k$ must be at least 1. Since $k \ge 1$, $k$ cannot be 0.
Therefore, there are no consecutive positive integers $k, k+1$ such that both are perfect squares.

This implies that for any $i \ge 1$, the product $i \cdot (i+1)$ is never a perfect square.
Thus, the simple permutation $[1, 2, \ldots, N]$ always satisfies the condition.

## Complexity Analysis

*   **Time Complexity**: For each test case, the solution iterates from $1$ to $N$ once to print the numbers. Printing each number is a constant time operation (or logarithmic in $N$ for very large $N$, but practically constant for typical integer sizes). Thus, for a single test case, the time complexity is $O(N)$. Given $T$ test cases, the total time complexity will be $O(\sum N)$ where $\sum N$ is the sum of $N$ over all test cases. With typical competitive programming constraints (e.g., $\sum N \le 2 \cdot 10^5$ or $10^6$), this is highly efficient.
*   **Space Complexity**: The solution uses a few integer variables ($n, i, t$) and prints directly to standard output without storing the permutation in an array or any other data structure. Therefore, the space complexity is $O(1)$ (constant space), excluding the space required for input/output buffers.

## Solution Code

```cpp
#include <iostream> // Required for std::cin, std::cout

// Function to solve a single test case
void solve() {
    int n;
    std::cin >> n; // Read the integer N for the current test case

    // The permutation [1, 2, ..., N] always satisfies the condition.
    // This is because for any i (1 <= i < N), i and i+1 are coprime.
    // For their product i * (i+1) to be a perfect square, both i and i+1 must be perfect squares.
    // The only consecutive non-negative integers that are both perfect squares are 0 and 1.
    // Since i >= 1, i cannot be 0. Thus, i and i+1 can never both be perfect squares.
    // Therefore, i * (i+1) is never a perfect square for i >= 1.
    // So, simply printing numbers from 1 to N in increasing order is a valid solution.
    for (int i = 1; i <= n; ++i) {
        std::cout << i << (i == n ? "" : " "); // Print number, followed by a space unless it's the last number
    }
    std::cout << "\n"; // Newline after each test case's output
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {  // Loop through each test case
        solve();   // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}
```