```cpp
#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int x, y;
        std::cin >> x >> y;
        // Let N be the total number of sets in the match. N is always odd.
        // The match stops when one player has won enough sets such that the other player
        // cannot possibly win, even if they win all remaining sets.
        //
        // Let the current score be (X, Y).
        // Let M = max(X, Y) and m = min(X, Y).
        // The number of sets played so far is X + Y.
        // The number of remaining sets is N - (X + Y).
        //
        // The match stops if the current leader has won enough sets that the opponent cannot reach the winning threshold.
        // The winning threshold is (N+1)/2 sets.
        //
        // Case 1: Sonu is leading (X > Y). So M = X, m = Y.
        // Titu's maximum possible score = Y + (N - (X + Y)) = N - X.
        // For Titu to have no chance of winning, Titu's maximum possible score must be strictly less than the number of sets needed to win.
        // N - X < (N+1)/2
        // 2 * (N - X) < N + 1
        // 2N - 2X < N + 1
        // N < 2X + 1
        // Since N must be odd, the maximum possible value for N is 2X - 1.
        //
        // Case 2: Titu is leading (Y > X). So M = Y, m = X.
        // Sonu's maximum possible score = X + (N - (X + Y)) = N - Y.
        // For Sonu to have no chance of winning, Sonu's maximum possible score must be strictly less than the number of sets needed to win.
        // N - Y < (N+1)/2
        // 2 * (N - Y) < N + 1
        // 2N - 2Y < N + 1
        // N < 2Y + 1
        // Since N must be odd, the maximum possible value for N is 2Y - 1.
        //
        // Combining both cases, the maximum possible odd N is 2 * max(X, Y) - 1.
        //
        // Additionally, the total number of sets N must be at least the number of sets already played.
        // So, N >= X + Y.
        //
        // We need to find the largest odd N that satisfies both conditions:
        // 1. N <= 2 * max(X, Y) - 1
        // 2. N >= X + Y
        //
        // Let's check if 2 * max(X, Y) - 1 is always greater than or equal to X + Y.
        // Let M = max(X, Y) and m = min(X, Y).
        // We need to check if 2*M - 1 >= M + m.
        // This simplifies to M - 1 >= m, or M - m >= 1.
        // Since the problem states X != Y, we know that M > m, so M - m is at least 1.
        // Thus, 2 * max(X, Y) - 1 is always greater than or equal to X + Y.
        //
        // Therefore, the largest possible odd N is simply 2 * max(X, Y) - 1.

        int max_sets = std::max(x, y);
        int n = 2 * max_sets - 1;
        std::cout << n << "\n";
    }
    return 0;
}
```

# Best of N Sets (BESTOFTENNIS)
- **Difficulty Rating**: 830
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine the total number of sets, $N$, in a best-of-$N$ tennis match, given the final score $(X, Y)$. The match stops as soon as one player has won enough sets such that the other player cannot possibly win, even if they win all remaining sets. $N$ is always an odd number.

## Intuition & Mathematical Observation
Let the current score be $(X, Y)$, where $X$ is the number of sets won by player 1 and $Y$ is the number of sets won by player 2. Let $N$ be the total number of sets in the match. $N$ is always odd.

The match stops if the current leader has won enough sets that the opponent cannot reach the winning threshold. The winning threshold is defined as winning strictly more than half of the total sets. Since $N$ is odd, a player needs to win at least $\frac{N+1}{2}$ sets to win the match.

Let $M = \max(X, Y)$ be the number of sets won by the current leader, and $m = \min(X, Y)$ be the number of sets won by the current loser.
The total number of sets played so far is $X + Y$.
The number of remaining sets is $N - (X + Y)$.

Consider the player who is currently losing (with $m$ sets). If this player wins all the remaining sets, their final score will be $m + (N - (X + Y))$.
For the match to have stopped at the score $(X, Y)$, the current loser must have had no chance of winning. This means their maximum possible final score must be strictly less than the number of sets required to win the match, which is $\frac{N+1}{2}$.

So, we have the inequality:
$m + (N - (X + Y)) < \frac{N+1}{2}$

Let's substitute $X+Y = M+m$:
$m + (N - (M+m)) < \frac{N+1}{2}$
$m + N - M - m < \frac{N+1}{2}$
$N - M < \frac{N+1}{2}$

Multiply by 2:
$2(N - M) < N + 1$
$2N - 2M < N + 1$
$N < 2M + 1$

Since $N$ must be an odd integer, the maximum possible value for $N$ that satisfies $N < 2M + 1$ is $2M - 1$.

Additionally, the total number of sets $N$ must be at least the number of sets already played. Therefore, $N \ge X + Y$.

We need to find the largest odd integer $N$ such that:
1. $N \le 2 \times \max(X, Y) - 1$
2. $N \ge X + Y$

Let's verify if the upper bound is always greater than or equal to the lower bound.
We need to check if $2 \times \max(X, Y) - 1 \ge X + Y$.
Let $M = \max(X, Y)$ and $m = \min(X, Y)$. The inequality becomes $2M - 1 \ge M + m$.
Subtracting $M$ from both sides gives $M - 1 \ge m$, or $M - m \ge 1$.
Since the problem states that $X \ne Y$, we know that $\max(X, Y) > \min(X, Y)$, so $M - m \ge 1$.
Thus, the condition $N \ge X + Y$ is always satisfied by $N = 2 \times \max(X, Y) - 1$.

Therefore, the largest possible odd value for $N$ that allows the match to stop at score $(X, Y)$ is $2 \times \max(X, Y) - 1$. The problem implies a unique value for $N$, and this derivation provides it.

For example:
- If score is (2, 5), $\max(X, Y) = 5$. $N = 2 \times 5 - 1 = 9$.
  - Check: $N=9$. Winning threshold is $(9+1)/2 = 5$. Sets played = $2+5=7$. Remaining = $9-7=2$.
  - Titu leads with 5 sets. Sonu's max score = $2 + 2 = 4$. Since $4 < 5$, Sonu cannot win. Match stops.
  - If $N=11$, winning threshold is $(11+1)/2 = 6$. Sets played = 7. Remaining = $11-7=4$.
  - Titu leads with 5 sets. Sonu's max score = $2 + 4 = 6$. Since $6 \ge 6$, Sonu *could* win. Match would not stop. So $N$ cannot be 11 or more.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. The solution involves a constant number of arithmetic operations and a call to `std::max`.
- **Space Complexity**: $O(1)$ per test case. The solution uses a fixed amount of extra space for variables.

## Solution Code
```cpp
#include <iostream>
#include <algorithm>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int x, y; // Current score (sets won by player 1 and player 2)
        std::cin >> x >> y;

        // Let N be the total number of sets in the match. N is always odd.
        // The match stops when one player has won enough sets such that the other player
        // cannot possibly win, even if they win all remaining sets.
        //
        // Let M = max(X, Y) be the number of sets won by the current leader.
        // Let m = min(X, Y) be the number of sets won by the current loser.
        // The number of sets played is X + Y.
        // The number of remaining sets is N - (X + Y).
        //
        // The winning threshold is (N+1)/2 sets.
        //
        // For the match to stop, the loser's maximum possible final score must be less than the winning threshold.
        // Loser's max score = m + (N - (X + Y)) = N - M.
        // So, N - M < (N+1)/2
        // 2 * (N - M) < N + 1
        // 2N - 2M < N + 1
        // N < 2M + 1
        //
        // Since N must be odd, the maximum possible value for N is 2M - 1.
        //
        // Also, N must be at least the number of sets played: N >= X + Y.
        // We proved that 2 * max(X, Y) - 1 is always >= X + Y.
        //
        // Therefore, the largest possible odd N is 2 * max(X, Y) - 1.

        int max_sets = std::max(x, y); // Find the maximum sets won by either player
        int n = 2 * max_sets - 1;      // Calculate N based on the derived formula
        std::cout << n << "\n";        // Output the result for the current test case
    }
    return 0;
}
```