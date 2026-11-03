# OR Permutation (PERMOR)

- **Difficulty Rating**: 1196
- **Solved in**: 1 attempt(s)

## Problem Summary

We are asked to find a permutation $A$ of numbers from $1$ to $N$ such that for all $3 \le i \le N$, the condition $A_i \neq A_{i-1} | A_{i-2}$ holds. Here, $|$ denotes the bitwise OR operation. The problem guarantees that at least one such permutation always exists.

## Intuition & Mathematical Observation

The core of the problem lies in satisfying the condition $A_i \neq A_{i-1} | A_{i-2}$. We need to construct a permutation where no element is the bitwise OR of the two preceding elements.

Let's consider a simple construction: printing the numbers in decreasing order, i.e., $A = [N, N-1, N-2, \dots, 1]$.
So, $A_i = N - i + 1$.

We need to verify if $A_i \neq A_{i-1} | A_{i-2}$ for $3 \le i \le N$.
Substituting our construction:
$A_i = N - i + 1$
$A_{i-1} = N - (i-1) + 1 = N - i + 2$
$A_{i-2} = N - (i-2) + 1 = N - i + 3$

The condition becomes:
$N - i + 1 \neq (N - i + 2) | (N - i + 3)$

Let $x = N - i + 1$. Then the condition is $x \neq (x+1) | (x+2)$.
We need to show that for any integer $x \ge 1$ (since $N \ge 3$ and $i \le N$, the minimum value of $x$ is when $i=N$, giving $x=1$), $x$ is never equal to the bitwise OR of $x+1$ and $x+2$.

Let's analyze the binary representations of $x$, $x+1$, and $x+2$.
Consider the least significant bit (LSB) where $x$ and $x+1$ differ. This bit must be a $0$ in $x$ and a $1$ in $x+1$. Let this position be $k$.
So, $x$ has a $0$ at bit $k$, and $x+1$ has a $1$ at bit $k$.

Now consider $x+2$.
If $x+1$ ends in $\dots 01$, then $x+2$ ends in $\dots 10$.
If $x+1$ ends in $\dots 10$, then $x+2$ ends in $\dots 11$.
If $x+1$ ends in $\dots 11$, then $x+2$ ends in $\dots 00$ (with a carry).

Crucially, for any non-negative integer $y$, $y$ and $y+1$ differ at the position of the LSB of $y+1$.
Let $y = x+1$. The LSB of $y+1 = x+2$ is at some position $m$.
This means $x+2$ has a $1$ at bit $m$, and $x+1$ has a $0$ at bit $m$.

Let's focus on the bitwise OR: $(x+1) | (x+2)$.
If there is any bit position $p$ where $x+1$ has a $1$ or $x+2$ has a $1$, then $(x+1) | (x+2)$ will have a $1$ at that position.

Consider the most significant bit (MSB) of $x$. Let it be at position $M$.
If $x+1$ and $x+2$ are both strictly less than $2^M$, then their OR would also be less than $2^M$. However, $x$ itself has a $1$ at bit $M$. This scenario is impossible.
At least one of $x+1$ or $x+2$ must have a bit set at position $M$ or higher.

More formally, let $k$ be the position of the least significant bit of $x+1$. This means $x+1$ has a $1$ at bit $k$, and all bits less significant than $k$ are $0$.
Then $x$ must have a $0$ at bit $k$ (and potentially other bits).
Since $x+1$ has a $1$ at bit $k$, the bitwise OR $(x+1) | (x+2)$ will also have a $1$ at bit $k$.
Since $x$ has a $0$ at bit $k$, it implies $x \neq (x+1) | (x+2)$.

This logic holds as long as $x+1 \ge 1$, which is true since $N \ge 3$ and $x = N-i+1 \ge 1$.

Therefore, the permutation $N, N-1, N-2, \dots, 1$ is a valid solution. The problem statement allows printing any valid permutation, so this simple construction is sufficient.

## Complexity Analysis

- **Time Complexity**: $O(N)$ for each test case, as we iterate from $N$ down to $1$ to print the numbers. Since the sum of $N$ over all test cases is limited, the total time complexity is efficient.
- **Space Complexity**: $O(1)$ if we print the numbers directly as we generate them, without storing the entire permutation in an array.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int n; // The size of the permutation
        std::cin >> n;

        // Construct the permutation by printing numbers in decreasing order: N, N-1, ..., 1.
        // As proven in the intuition section, this construction satisfies the condition
        // A_i != A_{i-1} | A_{i-2} for all 3 <= i <= N.
        for (int i = n; i >= 1; --i) {
            std::cout << i << (i == 1 ? "" : " "); // Print number, followed by space unless it's the last number
        }
        std::cout << "\n"; // Newline after each test case output
    }
    return 0;
}
```