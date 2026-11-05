# [Can_Reach (CAN_REACH)](https://www.codechef.com/problems/CAN_REACH)
- **Difficulty Rating**: 990
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks if it's possible to reach a target coordinate $(x, y)$ starting from $(0, 0)$ on a 2D plane. In each move, we can change either the x-coordinate or the y-coordinate by exactly $K$ (either $+K$ or $-K$).

## Intuition & Mathematical Observation
The student starts at the origin $(0, 0)$. Each move involves adding or subtracting $K$ to either the x-coordinate or the y-coordinate.

Let's consider the coordinates after a few moves:
- After 1 move: The possible positions are $(K, 0)$, $(-K, 0)$, $(0, K)$, or $(0, -K)$.
- After 2 moves:
    - From $(K, 0)$: $(2K, 0)$, $(0, 0)$, $(K, K)$, $(K, -K)$.
    - From $(-K, 0)$: $(-2K, 0)$, $(0, 0)$, $(-K, K)$, $(-K, -K)$.
    - And so on.

Notice a pattern: every reachable coordinate $(x', y')$ will have $x'$ as a multiple of $K$ and $y'$ as a multiple of $K$.
This is because the initial coordinates are $(0, 0)$, and each operation adds or subtracts $K$ to one of the coordinates. If we represent the number of times we add $K$ to the x-coordinate as $a_x$, subtract $K$ as $b_x$, add $K$ to the y-coordinate as $a_y$, and subtract $K$ as $b_y$, then the final coordinates $(x, y)$ will be:
$x = (a_x - b_x) \times K$
$y = (a_y - b_y) \times K$

Here, $(a_x - b_x)$ and $(a_y - b_y)$ are integers. This means that any reachable $x$ must be an integer multiple of $K$, and any reachable $y$ must also be an integer multiple of $K$.

Therefore, to reach the target coordinate $(x, y)$, both $x$ and $y$ must be divisible by $K$. If either $x$ or $y$ is not divisible by $K$, it's impossible to reach that coordinate. If both $x$ and $y$ are divisible by $K$, we can always reach $(x, y)$. For example, to reach $(x, y)$ where $x = mK$ and $y = nK$:
1. Perform $|m|$ moves of adding/subtracting $K$ to the x-coordinate to reach $(x, 0)$.
2. Perform $|n|$ moves of adding/subtracting $K$ to the y-coordinate to reach $(x, y)$.

The problem statement guarantees that $x, y, k$ are positive integers.

## Complexity Analysis
- **Time Complexity**: $O(1)$
    The solution involves a constant number of arithmetic operations (modulo and comparisons) for each test case. Since there are $t$ test cases, the total time complexity is $O(t)$. However, for a single test case, it's $O(1)$.

- **Space Complexity**: $O(1)$
    The solution uses a fixed amount of memory to store variables ($t, x, y, k$), regardless of the input size.