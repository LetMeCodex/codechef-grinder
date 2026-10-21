# [No Winner (NOWINNER)](https://www.codechef.com/problems/NOWINNER)
- **Difficulty Rating**: 931
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem involves three players: Alice, Bob, and Cameron, with initial scores $A, B, C$ respectively. There are $M$ additional matches to be played. In each match, one point is awarded to the winner. We need to determine if it's possible, after these $M$ matches, for at least two players to end up with the same final score.

## Intuition & Mathematical Observation

Let the initial scores of Alice, Bob, and Cameron be $A, B, C$.
Let $x_A, x_B, x_C$ be the number of points Alice, Bob, and Cameron win from the $M$ additional matches, respectively.
Since points are awarded in matches, $x_A, x_B, x_C$ must be non-negative integers ($x_A \ge 0, x_B \ge 0, x_C \ge 0$).
The total number of points awarded across all $M$ matches must sum up to $M$, so $x_A + x_B + x_C = M$.

The final scores of the players will be:
$A' = A + x_A$
$B' = B + x_B$
$C' = C + x_C$

We need to check if it's possible for any pair of players to have the same final score. This means we need to check if any of the following conditions can be satisfied:
1. $A' = B'$ (Alice and Bob have the same final score)
2. $B' = C'$ (Bob and Cameron have the same final score)
3. $A' = C'$ (Alice and Cameron have the same final score)

Let's analyze the condition for $A' = B'$:
$A + x_A = B + x_B$
Rearranging this equation, we get:
$x_B - x_A = A - B$

We need to determine if there exist non-negative integers $x_A, x_B, x_C$ such that $x_A + x_B + x_C = M$ and $x_B - x_A = A - B$.

Consider the possible range of values for $x_B - x_A$:
- The maximum value of $x_B - x_A$ occurs when $x_B$ is maximized and $x_A$ is minimized. The maximum $x_B$ can be is $M$ (if Bob wins all $M$ matches), and the minimum $x_A$ can be is $0$. In this scenario, $x_B - x_A = M - 0 = M$.
- The minimum value of $x_B - x_A$ occurs when $x_B$ is minimized and $x_A$ is maximized. The minimum $x_B$ can be is $0$, and the maximum $x_A$ can be is $M$. In this scenario, $x_B - x_A = 0 - M = -M$.

Any integer value between $-M$ and $M$ (inclusive) can be achieved for $x_B - x_A$ while ensuring $x_A, x_B \ge 0$ and $x_A + x_B \le M$. The remaining points $M - (x_A + x_B)$ can then be assigned to $x_C$.
For example, if we want $x_B - x_A = K$ where $-M \le K \le M$:
- If $K \ge 0$: We can set $x_A = 0$, $x_B = K$. Then $x_C = M - (x_A + x_B) = M - K$. Since $K \le M$, $x_C \ge 0$ is guaranteed.
- If $K < 0$: We can set $x_B = 0$, $x_A = -K$. Then $x_C = M - (x_A + x_B) = M - (-K) = M + K$. Since $K \ge -M$, $M+K \ge 0$ is guaranteed.

Therefore, it is possible for Alice and Bob to have the same final score ($A' = B'$) if and only if the initial score difference $A - B$ falls within the range $[-M, M]$. This condition can be concisely expressed as $|A - B| \le M$.

The same logic applies to any other pair of players:
- It is possible for Bob and Cameron to have the same final score ($B' = C'$) if and only if $|B - C| \le M$.
- It is possible for Alice and Cameron to have the same final score ($A' = C'$) if and only if $|A - C| \le M$.

The problem asks if it's possible for *at least two* players to have the same score. This means we need to check if *any* of these three conditions are true. If at least one of them is true, the answer is "YES"; otherwise, the answer is "NO".

## Complexity Analysis

-   **Time Complexity**: For each test case, the solution reads four integers ($A, B, C, M$) and performs a few constant-time arithmetic operations (subtractions, absolute values, comparisons) and logical OR operations. These operations take constant time. Given $T$ test cases, the total time complexity is $O(T)$.
-   **Space Complexity**: The solution uses a fixed number of integer variables to store $A, B, C, M$, and $t$. This amount of memory does not depend on the input values or the number of test cases (beyond the loop counter). Thus, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <iostream> // Required for standard input/output operations (cin, cout)
#include <cmath>    // Required for std::abs

void solve() {
    int A, B, C, M;
    std::cin >> A >> B >> C >> M;

    // The problem asks if it's possible for at least two players to end up with the same score.
    // Let the initial scores be A, B, C and M be the number of additional matches.
    // In each match, one point is awarded to a winner.
    // Let xA, xB, xC be the points won by Alice, Bob, and Cameron respectively.
    // We must have xA, xB, xC >= 0 and xA + xB + xC = M.
    // The final scores will be A' = A + xA, B' = B + xB, C' = C + xC.

    // Consider if it's possible for Alice and Bob to have the same final score (A' = B').
    // A + xA = B + xB  =>  xB - xA = A - B.
    // The maximum value xB - xA can take is M (if Bob wins all M matches, Alice wins 0).
    // The minimum value xB - xA can take is -M (if Alice wins all M matches, Bob wins 0).
    // So, for A' = B' to be possible, the difference A - B must be within the range [-M, M].
    // This is equivalent to |A - B| <= M.
    // If |A - B| <= M, we can always find non-negative xA, xB, xC that sum to M and make A' = B'.
    // (e.g., if A >= B, set xA=0, xB=A-B, xC=M-(A-B); if B > A, set xA=B-A, xB=0, xC=M-(B-A)).

    // The same logic applies to any pair of players:
    // - A' = B' is possible if and only if |A - B| <= M.
    // - B' = C' is possible if and only if |B - C| <= M.
    // - A' = C' is possible if and only if |A - C| <= M.

    // We need to output "YES" if any of these conditions are met, and "NO" otherwise.
    if (std::abs(A - B) <= M || std::abs(B - C) <= M || std::abs(A - C) <= M) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        solve(); // Call the solve function for each test case
    }

    return 0;
}
```