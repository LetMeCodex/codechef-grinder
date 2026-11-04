# [Chef and Serves (CHSERVE)](https://www.codechef.com/problems/CHSERVE)
- **Difficulty Rating**: 1101
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef and Cook are playing a game. Chef serves the first $K$ points. After every $K$ points are scored, the server changes. If Chef served the last $K$ points, Cook will serve the next $K$ points, and vice versa. Given the total points scored by Chef ($P_1$) and Cook ($P_2$), and the value of $K$, determine who is serving the current point.

## Intuition & Mathematical Observation
The core of the problem lies in determining who is serving based on the total number of points scored and the interval $K$.

Let $P_1$ be the points scored by Chef and $P_2$ be the points scored by Cook. The total points scored in the game is $TotalPoints = P_1 + P_2$.

The server changes after every $K$ points. This means:
- Points $0$ to $K-1$: Chef serves.
- Points $K$ to $2K-1$: Cook serves.
- Points $2K$ to $3K-1$: Chef serves.
- Points $3K$ to $4K-1$: Cook serves.
And so on.

We can observe a pattern here. The server for a given point depends on which block of $K$ points the total score falls into. The blocks can be indexed starting from 0.
- Block 0: Points $0$ to $K-1$. Chef serves.
- Block 1: Points $K$ to $2K-1$. Cook serves.
- Block 2: Points $2K$ to $3K-1$. Chef serves.
- Block 3: Points $3K$ to $4K-1$. Cook serves.

The block index can be determined by integer division of the total points by $K$: $BlockIndex = TotalPoints / K$.

Now, we can relate the `BlockIndex` to the server:
- If `BlockIndex` is even (0, 2, 4, ...), Chef serves.
- If `BlockIndex` is odd (1, 3, 5, ...), Cook serves.

This can be concisely expressed using the modulo operator:
- If $(TotalPoints / K) \pmod 2 == 0$, Chef serves.
- If $(TotalPoints / K) \pmod 2 == 1$, Cook serves.

The problem statement implies that the current point being considered is the $(P_1 + P_2)$-th point. The server for this point is determined by the total points scored up to and including this point.

For example, if $K=3$ and $TotalPoints = 5$:
- $TotalPoints / K = 5 / 3 = 1$ (integer division).
- $1 \pmod 2 = 1$.
- Since the result is 1 (odd), Cook serves.
Let's trace:
- Points 0, 1, 2: Chef serves.
- Points 3, 4, 5: Cook serves.
The 5th point (0-indexed) is indeed served by Cook.

If $K=3$ and $TotalPoints = 6$:
- $TotalPoints / K = 6 / 3 = 2$.
- $2 \pmod 2 = 0$.
- Since the result is 0 (even), Chef serves.
Let's trace:
- Points 0, 1, 2: Chef serves.
- Points 3, 4, 5: Cook serves.
- Points 6, 7, 8: Chef serves.
The 6th point (0-indexed) is served by Chef.

The logic holds.

## Complexity Analysis
- **Time Complexity**: $O(1)$
  The solution involves a few arithmetic operations (addition, division, modulo) and a conditional check. These operations take constant time, regardless of the input values of $P_1$, $P_2$, and $K$. The loop runs $T$ times, where $T$ is the number of test cases. Thus, for each test case, the time complexity is $O(1)$.

- **Space Complexity**: $O(1)$
  The solution uses a fixed number of variables to store the input values and intermediate results. The memory usage does not grow with the input size. Therefore, the space complexity is $O(1)$.

## Solution Code
```cpp
#include <iostream>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        long long p1, p2, k; // Points scored by Chef, Cook, and the interval K
        std::cin >> p1 >> p2 >> k;

        // Calculate the total points scored
        long long total_points = p1 + p2;

        // Determine the block index based on total points and K.
        // The server changes after every K points.
        // Block 0: points 0 to K-1 (Chef)
        // Block 1: points K to 2K-1 (Cook)
        // Block 2: points 2K to 3K-1 (Chef)
        // ...
        // The block index is total_points / K (integer division).
        // If the block index is even, Chef serves.
        // If the block index is odd, Cook serves.
        // This can be checked by (total_points / k) % 2.

        if ((total_points / k) % 2 == 0) {
            // If the result of (total_points / k) % 2 is 0, it means an even number of K-point intervals have been completed,
            // so Chef is serving the current point.
            std::cout << "CHEF\n";
        } else {
            // If the result is 1, it means an odd number of K-point intervals have been completed,
            // so Cook is serving the current point.
            std::cout << "COOK\n";
        }
    }
    return 0;
}
```