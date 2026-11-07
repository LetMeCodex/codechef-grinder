# [Penalty Shoot-out (PENALTYSHOOT)](https://www.codechef.com/problems/PENALTYSHOOT)
- **Difficulty Rating**: 869
- **Solved in**: 1 attempt(s)

## Problem Summary
In a penalty shootout, two teams, A and B, take turns shooting penalties. Team A takes 5 shots, and Team B takes 5 shots. The problem states that Team A has already taken 3 shots, and Team B has already taken 4 shots. We are given the current scores of Team A ($x$) and Team B ($y$) after these shots. We need to determine if it's possible for the match to end in a draw, considering the remaining shots.

Team A has $5 - 3 = 2$ shots remaining.
Team B has $5 - 4 = 1$ shot remaining.

A draw occurs if both teams end up with the same final score.

## Intuition & Mathematical Observation

Let $x$ be the current score of Team A and $y$ be the current score of Team B.

Team A has 2 shots remaining. For each of these shots, Team A can either score a goal or miss.
- If Team A scores in both remaining shots, their final score will be $x + 2$.
- If Team A scores in one of the remaining shots, their final score will be $x + 1$.
- If Team A misses both remaining shots, their final score will be $x$.
Therefore, the possible final scores for Team A are $x$, $x+1$, and $x+2$.

Team B has 1 shot remaining. For this shot, Team B can either score a goal or miss.
- If Team B scores in the remaining shot, their final score will be $y + 1$.
- If Team B misses the remaining shot, their final score will be $y$.
Therefore, the possible final scores for Team B are $y$ and $y+1$.

For the match to end in a draw, there must exist a score $S$ such that $S$ is a possible final score for Team A AND $S$ is a possible final score for Team B.
This means we need to check if there is any overlap between the set of possible final scores for Team A and the set of possible final scores for Team B.

Set of possible final scores for Team A: $\{x, x+1, x+2\}$
Set of possible final scores for Team B: $\{y, y+1\}$

A draw is possible if and only if the intersection of these two sets is non-empty.
This means we need to check if any of the following conditions are true:
1.  $x = y$
2.  $x = y+1$
3.  $x+1 = y$
4.  $x+1 = y+1$
5.  $x+2 = y$
6.  $x+2 = y+1$

If any of these equalities hold, it means there's a common score that both teams can achieve, and thus a draw is possible. Otherwise, a draw is not possible.

We can simplify this by considering the ranges of possible scores.
Team A's possible scores form the range $[x, x+2]$.
Team B's possible scores form the range $[y, y+1]$.

Two intervals $[a, b]$ and $[c, d]$ overlap if and only if $\max(a, c) \le \min(b, d)$.
In our case, $a=x$, $b=x+2$, $c=y$, $d=y+1$.
So, a draw is possible if $\max(x, y) \le \min(x+2, y+1)$.

Let's verify this condition with the individual checks:
- If $x = y$: $\max(x, x) = x$, $\min(x+2, x+1) = x+1$. $x \le x+1$ is true.
- If $x = y+1$: $\max(y+1, y) = y+1$, $\min((y+1)+2, y+1) = \min(y+3, y+1) = y+1$. $y+1 \le y+1$ is true.
- If $x+1 = y$: $\max(y, y-1) = y$, $\min((y-1)+2, y+1) = \min(y+1, y+1) = y+1$. $y \le y+1$ is true.
- If $x+1 = y+1$ (which means $x=y$): Covered by the first case.
- If $x+2 = y$: $\max(y-2, y) = y$, $\min((y-2)+2, y+1) = \min(y, y+1) = y$. $y \le y$ is true.
- If $x+2 = y+1$ (which means $x+1=y$): Covered by the third case.

The direct check of the six equality conditions is more straightforward and less prone to off-by-one errors in interval logic.

## Complexity Analysis

- **Time Complexity**: $O(1)$
    For each test case, we perform a fixed number of comparisons and arithmetic operations. The number of operations does not depend on the input values of $x$ and $y$ or the number of test cases $t$.

- **Space Complexity**: $O(1)$
    We only use a few variables to store the input values and the result. The memory usage is constant and does not grow with the input size.

## Solution Code

```cpp
#include <iostream>
#include <algorithm> // Required for std::max and std::min if using the interval overlap approach

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int x, y; // Current scores of Team A and Team B
        std::cin >> x >> y;

        // Team A has 2 shots remaining. Possible final scores: x, x+1, x+2.
        // Team B has 1 shot remaining. Possible final scores: y, y+1.

        // A draw is possible if there's a common score achievable by both teams.
        // We check if any of Team A's possible scores match any of Team B's possible scores.
        bool possible_draw = false;

        // Check if Team A's score 'x' can match Team B's scores
        if (x == y || x == y + 1) {
            possible_draw = true;
        }
        // Check if Team A's score 'x+1' can match Team B's scores
        if (x + 1 == y || x + 1 == y + 1) {
            possible_draw = true;
        }
        // Check if Team A's score 'x+2' can match Team B's scores
        if (x + 2 == y || x + 2 == y + 1) {
            possible_draw = true;
        }

        if (possible_draw) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}
```