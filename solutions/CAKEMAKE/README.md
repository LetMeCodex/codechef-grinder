# [Cake Making (CAKEMAKE)](https://www.codechef.com/problems/CAKEMAKE)
- **Difficulty Rating**: 279
- **Solved in**: 1 attempt(s)

## Problem Summary
We are asked to find the number of ways to make a two-layer cake. The first layer can be any color from 1 to $A$, and the second layer can be any color from 1 to $B$. However, there's a constraint: the two layers cannot have the same color.

## Intuition & Mathematical Observation
Let $A$ be the number of available colors for the first layer, and $B$ be the number of available colors for the second layer.

If there were no restrictions, the number of ways to choose a color for the first layer is $A$, and the number of ways to choose a color for the second layer is $B$. The total number of combinations would simply be the product of the choices for each layer: $A \times B$.

However, the problem states that the first and second layers cannot have the same color. We need to subtract the cases where the colors are identical.

Consider a case where the color of the first layer is $c_1$ and the color of the second layer is $c_2$.
The first layer can be any color from $\{1, 2, \dots, A\}$.
The second layer can be any color from $\{1, 2, \dots, B\}$.

We are looking for pairs $(c_1, c_2)$ such that $1 \le c_1 \le A$ and $1 \le c_2 \le B$, with the additional condition that $c_1 \ne c_2$.

The total number of possible pairs $(c_1, c_2)$ without any restriction is $A \times B$.

Now, let's identify the "forbidden" pairs, which are those where $c_1 = c_2$.
For a pair $(c, c)$ to be forbidden, the color $c$ must be a valid choice for *both* the first layer and the second layer.
This means $c$ must satisfy:
1. $1 \le c \le A$ (valid for the first layer)
2. $1 \le c \le B$ (valid for the second layer)

Both conditions are met if and only if $c$ is in the range $[1, \min(A, B)]$.
The number of such common colors is $\min(A, B)$.
For each of these $\min(A, B)$ common colors, there is exactly one forbidden combination: $(c, c)$.

Therefore, the total number of valid cake combinations is the total number of combinations minus the number of forbidden combinations:
Total valid cakes = (Total combinations) - (Combinations where colors are the same)
Total valid cakes = $(A \times B) - \min(A, B)$

The problem statement uses `int a, b;` for input, and the calculation `(long long)a * b - common_colors;` correctly handles potential overflow for the product `a * b` by casting `a` to `long long` before multiplication.

## Complexity Analysis
- **Time Complexity**: $O(1)$
The solution involves a few arithmetic operations and a call to `std::min`. These operations take constant time, regardless of the input values of $A$ and $B$.

- **Space Complexity**: $O(1)$
The solution uses a fixed amount of memory to store variables (`a`, `b`, `common_colors`, `total_cakes`). This amount does not depend on the input size.