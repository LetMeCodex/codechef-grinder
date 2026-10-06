# [Chef and Linear Chess (LINCHESS)](https://www.codechef.com/problems/LINCHESS)
- **Difficulty Rating**: 1200
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef has a pawn located at position $K$. There are $N$ other players, each with a pawn at an initial position $P_i$. A player's pawn at $P_i$ can move by repeatedly adding $P_i$ to its current position. For example, from $P_i$, it can move to $2P_i$, then $3P_i$, and so on. Chef wants to find out which player can capture his pawn at $K$ in the minimum number of moves. If multiple players can achieve this minimum, Chef prefers the player whose pawn started at the largest initial position $P_i$. If no player can capture Chef's pawn, the output should be -1.

## Intuition & Mathematical Observation

1.  **Condition for Capture**: A player starting at position $P_i$ can capture Chef's pawn at $K$ if and only if $K$ is a multiple of $P_i$. This means $K = m \cdot P_i$ for some positive integer $m$. If $K$ is not divisible by $P_i$, that player cannot reach $K$.

2.  **Number of Moves**: If a player at $P_i$ can reach $K = m \cdot P_i$:
    *   Initial position: $P_i$ (0 moves)
    *   After 1st move: $P_i + P_i = 2P_i$
    *   After 2nd move: $2P_i + P_i = 3P_i$
    *   ...
    *   After $(m-1)$ moves: $(m-1)P_i + P_i = mP_i = K$
    So, the number of moves required is $m-1$. Since $m = K/P_i$, the number of moves is $(K/P_i) - 1$.

3.  **Minimizing Moves**: To minimize the number of moves $(K/P_i) - 1$, we need to minimize the value of $K/P_i$. Since $K$ is a fixed positive integer, minimizing $K/P_i$ is equivalent to maximizing $P_i$ among all players who can capture Chef's pawn.

4.  **Tie-breaking**: The problem states: "If there are multiple such players, Chef wants to know the player whose pawn started at the largest initial position."
    Let's consider two distinct players, $P_A$ and $P_B$, both of whom can capture Chef's pawn (i.e., $K \% P_A == 0$ and $K \% P_B == 0$).
    Assume $P_A > P_B$.
    Then, $K/P_A < K/P_B$.
    Consequently, $(K/P_A) - 1 < (K/P_B) - 1$.
    This means that if two distinct players can capture Chef's pawn, the one with the larger initial position $P_i$ will always require *strictly fewer* moves.
    Therefore, there will always be a *unique* player who achieves the absolute minimum number of moves. This unique player will be the one with the largest $P_i$ that divides $K$. The tie-breaking condition in the problem statement is effectively redundant because there won't be multiple players achieving the same minimum number of moves.

Based on this, the strategy is:
Iterate through all players $P_i$.
If $K$ is divisible by $P_i$:
  Calculate the number of moves: `current_moves = (K / P_i) - 1`.
  Keep track of the minimum `min_moves` found so far and the corresponding `best_player_pos`.
  If `current_moves` is less than `min_moves` (or if this is the first valid player found), update `min_moves` and `best_player_pos`.
After checking all players, `best_player_pos` will hold the answer. If no player could capture Chef's pawn, `best_player_pos` will remain -1.

## Complexity Analysis

*   **Time Complexity**: $O(T \cdot N)$
    *   The solution involves an outer loop that runs `T` times for the number of test cases.
    *   Inside each test case, there's a loop that iterates `N` times, once for each player.
    *   Within this inner loop, operations like modulo (`%`), division (`/`), comparisons, and assignments are all constant time operations, $O(1)$.
    *   Thus, for each test case, the time complexity is $O(N)$.
    *   The total time complexity is $O(T \cdot N)$. Given $T \le 100$ and $N \le 10^5$, the maximum operations would be around $100 \cdot 10^5 = 10^7$, which is well within typical time limits (usually $10^8$ operations per second).

*   **Space Complexity**: $O(N)$
    *   A `std::vector<long long> p(n)` is used to store the initial positions of the $N$ players. This requires $O(N)$ space.
    *   All other variables (`t`, `n`, `k`, `min_moves`, `best_player_pos`, `moves`, `i`) use a constant amount of memory, $O(1)$.
    *   Therefore, the dominant space complexity is $O(N)$ per test case.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int n;         // Number of players
        long long k;   // Chef's pawn position
        std::cin >> n >> k;

        // Initialize variables to track the best player found so far.
        // min_moves stores the minimum number of moves required.
        // best_player_pos stores the initial position of the player who achieves min_moves.
        // Initialize min_moves to -1 or a very large value, and best_player_pos to -1
        // to indicate no valid player has been found yet.
        int min_moves = -1; 
        long long best_player_pos = -1;

        // Iterate through each player
        for (int i = 0; i < n; ++i) {
            long long current_player_pos;
            std::cin >> current_player_pos; // Read current player's initial position

            // Check if the current player can capture Chef's pawn.
            // A player at P_i can capture K if K is a multiple of P_i.
            if (k % current_player_pos == 0) {
                // If K is a multiple of P_i, say K = m * P_i,
                // then the number of moves required is m - 1.
                // m is K / P_i.
                long long moves = (k / current_player_pos) - 1;

                // Update best_player_pos if this player offers a better solution.
                // A better solution means either:
                // 1. This is the first valid player found (best_player_pos is -1).
                // 2. This player requires fewer moves than the current minimum (moves < min_moves).
                // As observed, a player with a larger P_i will always require fewer moves,
                // so there will be a unique player achieving the minimum moves.
                if (best_player_pos == -1 || moves < min_moves) {
                    min_moves = moves;
                    best_player_pos = current_player_pos;
                }
            }
        }
        // Output the initial position of the best player found, or -1 if no player can capture.
        std::cout << best_player_pos << "\n";
    }
    return 0;
}

```