# [Knockout tournament (KNOCKOUT)](https://www.codechef.com/problems/KNOCKOUT)
- **Difficulty Rating**: 1279
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a knockout tournament with 16 players. Each player has a distinct skill level. In any match, the player with the higher skill level always wins. We need to determine, for each of the 16 players, the maximum number of matches they *could* win if the tournament bracket were arranged optimally for them.

## Intuition & Mathematical Observation

The core idea revolves around understanding how many weaker opponents a player needs to defeat to win a certain number of matches in a knockout format.

1.  **Winning a match**: A player can only win a match if their skill is strictly greater than their opponent's skill.
2.  **Optimal Bracket**: To maximize a player's wins, we must assume the tournament bracket is arranged such that this player only ever faces opponents weaker than themselves, until they reach the final match (or win the tournament).
3.  **Required Weaker Opponents**:
    *   To win 1 match, a player needs to defeat 1 opponent. This requires at least 1 player weaker than them.
    *   To win 2 matches, a player needs to defeat 2 opponents. To do this, they must be the strongest in a sub-bracket of 4 players. This means there must be 3 players weaker than them (the 2 opponents they defeat, plus the opponent their first opponent defeated). This is $2^2 - 1 = 3$ weaker players.
    *   Generalizing, to win `k` matches, a player must be the strongest in a sub-bracket of $2^k$ players. This implies there must be $2^k - 1$ players strictly weaker than them available to fill that sub-bracket.
4.  **Maximum Wins in a 16-player tournament**:
    *   A 16-player tournament has 4 rounds. So, the maximum possible wins for any player is 4.
    *   To win 4 matches (i.e., win the tournament), a player needs to be stronger than all 15 other players. This requires $2^4 - 1 = 15$ weaker players.
    *   To win 3 matches, a player needs to be stronger than at least 7 other players ($2^3 - 1 = 7$).
    *   To win 2 matches, a player needs to be stronger than at least 3 other players ($2^2 - 1 = 3$).
    *   To win 1 match, a player needs to be stronger than at least 1 other player ($2^1 - 1 = 1$).
    *   If a player is the weakest (0 weaker players), they can win 0 matches.

**Solution Strategy**:
1.  Store each player's skill along with their original 0-indexed position. This is crucial because we need to output results in the original player order.
2.  Sort all players based on their skill levels in ascending order.
3.  Iterate through the sorted list of players. For a player at sorted index `i` (0-indexed), there are exactly `i` players with strictly lower skill levels. Let's call this `weaker_count = i`.
4.  For each player, use their `weaker_count` to determine their maximum possible wins based on the observations above:
    *   If `weaker_count >= 15`, `max_wins = 4`.
    *   Else if `weaker_count >= 7`, `max_wins = 3`.
    *   Else if `weaker_count >= 3`, `max_wins = 2`.
    *   Else if `weaker_count >= 1`, `max_wins = 1`.
    *   Else (`weaker_count == 0`), `max_wins = 0`.
5.  Store these `max_wins` in a result array, indexed by the player's original position.
6.  Finally, print the results for all players in their original order.

## Complexity Analysis

Let $N$ be the number of players, which is fixed at 16 in this problem.

-   **Time Complexity**:
    *   Reading input for $N$ players: $O(N)$.
    *   Sorting $N$ players: $O(N \log N)$.
    *   Iterating through the sorted players and calculating `max_wins` for each: $O(N)$ operations, each taking constant time.
    *   Outputting results: $O(N)$.
    *   Since $N=16$ is a small constant, $N \log N$ is also a constant. Therefore, the overall time complexity per test case is $O(N \log N)$, which effectively simplifies to $O(1)$ for competitive programming purposes when $N$ is fixed and small.
    *   For $T$ test cases, the total time complexity is $T \times O(N \log N)$.

-   **Space Complexity**:
    *   Storing player skills and original indices in a `vector<pair<int, int>>`: $O(N)$ space.
    *   Storing results in a `vector<int>`: $O(N)$ space.
    *   Since $N=16$ is a small constant, the overall space complexity is $O(N)$, which effectively simplifies to $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, vector, algorithm, utility etc.

// Use standard namespace for convenience in competitive programming
using namespace std;

void solve() {
    // Store players as pairs of (skill, original_index)
    // original_index is 0-indexed, so player 1 is index 0, player 16 is index 15.
    vector<pair<int, int>> players(16);
    for (int i = 0; i < 16; ++i) {
        cin >> players[i].first; // Read skill level
        players[i].second = i;   // Store original 0-indexed position
    }

    // Sort players based on their skill levels.
    // std::pair sorts by first element, then by second if first elements are equal.
    // Since skills are distinct, only the first element (skill) matters for sorting.
    sort(players.begin(), players.end());

    // This vector will store the maximum number of wins for each player,
    // indexed by their original 0-indexed position.
    vector<int> results(16);

    // Iterate through the sorted players
    for (int i = 0; i < 16; ++i) {
        // For the player at sorted position 'i' (0-indexed),
        // there are 'i' players with strictly lower skill levels.
        // This is our 'weaker_count'.
        int weaker_count = i;
        int max_wins = 0;

        // Determine the maximum number of matches this player can win.
        // A player can win 'k' matches if there are at least (2^k - 1) players weaker than them.
        // We check from highest possible wins (4) down to 0.
        if (weaker_count >= 15) { // 2^4 - 1 = 15
            max_wins = 4;
        } else if (weaker_count >= 7) { // 2^3 - 1 = 7
            max_wins = 3;
        } else if (weaker_count >= 3) { // 2^2 - 1 = 3
            max_wins = 2;
        } else if (weaker_count >= 1) { // 2^1 - 1 = 1
            max_wins = 1;
        } else { // weaker_count == 0 (i.e., this is the weakest player)
            max_wins = 0;
        }
        
        // Store the calculated max_wins in the results vector at the player's original index.
        results[players[i].second] = max_wins;
    }

    // Output the results for all 16 players, space-separated.
    for (int i = 0; i < 16; ++i) {
        cout << results[i] << (i == 15 ? "" : " ");
    }
    cout << "\n"; // Newline after each test case output
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Number of test cases
    cin >> t;
    while (t--) {
        solve(); // Solve each test case
    }

    return 0;
}
```