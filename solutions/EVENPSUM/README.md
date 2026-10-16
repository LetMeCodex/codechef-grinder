# [Even Pair Sum (EVENPSUM)](https://www.codechef.com/problems/EVENPSUM)
- **Difficulty Rating**: 1200
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two integers $A$ and $B$, we need to find the number of pairs $(X, Y)$ such that $1 \le X \le A$, $1 \le Y \le B$, and the sum $X + Y$ is even.

## Intuition & Mathematical Observation
The sum of two integers $X$ and $Y$ is even if and only if:
1. Both $X$ and $Y$ are even.
2. Both $X$ and $Y$ are odd.

This is because:
- Even + Even = Even
- Odd + Odd = Even
- Even + Odd = Odd
- Odd + Even = Odd

Therefore, to find the total number of pairs $(X, Y)$ where $X+Y$ is even, we need to calculate the number of pairs where both $X$ and $Y$ are even, and add it to the number of pairs where both $X$ and $Y$ are odd.

Let's consider the range of numbers for $X$ and $Y$:
- For $X$, the range is $[1, A]$.
- For $Y$, the range is $[1, B]$.

We need to count how many even and odd numbers are present in each range.

**Counting even and odd numbers in $[1, N]$:**
- The number of even integers in the range $[1, N]$ is $\lfloor N/2 \rfloor$.
- The number of odd integers in the range $[1, N]$ is $\lceil N/2 \rceil$.
  Alternatively, if $N$ is even, there are $N/2$ odd numbers. If $N$ is odd, there are $(N+1)/2$ odd numbers. This can be concisely written as $(N+1)/2$ using integer division.

So, for the range $[1, A]$:
- Number of even $X$ = `even_a = A / 2`
- Number of odd $X$ = `odd_a = (A + 1) / 2`

And for the range $[1, B]$:
- Number of even $Y$ = `even_b = B / 2`
- Number of odd $Y$ = `odd_b = (B + 1) / 2`

Now, we can calculate the number of valid pairs:

**Case 1: Both $X$ and $Y$ are even.**
The number of ways to choose an even $X$ is `even_a`.
The number of ways to choose an even $Y$ is `even_b`.
The total number of pairs where both are even is `even_a * even_b`.

**Case 2: Both $X$ and $Y$ are odd.**
The number of ways to choose an odd $X$ is `odd_a`.
The number of ways to choose an odd $Y$ is `odd_b`.
The total number of pairs where both are odd is `odd_a * odd_b`.

The total number of pairs $(X, Y)$ such that $X+Y$ is even is the sum of the counts from these two cases:
`total_pairs = (even_a * even_b) + (odd_a * odd_b)`

The problem involves multiple test cases, so we will read the number of test cases $t$ and then iterate $t$ times, performing the calculation for each pair of $A$ and $B$. Using `long long` for $A$, $B$, and the counts is important to avoid potential integer overflow, as $A$ and $B$ can be up to $10^9$.

## Complexity Analysis
- **Time Complexity**: $O(1)$
  For each test case, we perform a fixed number of arithmetic operations (division, addition, multiplication). The time taken does not depend on the magnitude of $A$ and $B$, only on the number of test cases $t$. Thus, the time complexity per test case is constant. If there are $t$ test cases, the total time complexity is $O(t)$.

- **Space Complexity**: $O(1)$
  We only use a few variables to store the input values and intermediate results. The amount of memory used is constant and does not grow with the input size.

## Solution Code
```cpp
#include <iostream>

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        long long a, b; // Input integers A and B
        std::cin >> a >> b;

        // For X + Y to be even, either both X and Y are even, or both are odd.

        // Count of even numbers in the range [1, A]
        // Integer division a / 2 gives floor(a / 2)
        long long even_a = a / 2;
        // Count of odd numbers in the range [1, A]
        // (a + 1) / 2 using integer division gives ceil(a / 2)
        long long odd_a = (a + 1) / 2;

        // Count of even numbers in the range [1, B]
        long long even_b = b / 2;
        // Count of odd numbers in the range [1, B]
        long long odd_b = (b + 1) / 2;

        // Case 1: X is even, Y is even
        // Number of pairs = (count of even X) * (count of even Y)
        long long even_even_pairs = even_a * even_b;

        // Case 2: X is odd, Y is odd
        // Number of pairs = (count of odd X) * (count of odd Y)
        long long odd_odd_pairs = odd_a * odd_b;

        // Total valid pairs = (even X, even Y) + (odd X, odd Y)
        long long total_pairs = even_even_pairs + odd_odd_pairs;

        std::cout << total_pairs << "\n";
    }
    return 0;
}
```