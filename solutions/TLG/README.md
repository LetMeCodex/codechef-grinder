# [The Lead Game (TLG)](https://www.codechef.com/problems/TLG)
- **Difficulty Rating**: 790
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a game played between two players, Player 1 and Player 2, over `N` rounds. In each round `i`, Player 1 scores `S_i` points and Player 2 scores `T_i` points. The scores are cumulative, meaning a player's total score is the sum of points they scored in all rounds up to the current one.

The objective is to determine the maximum lead achieved by any player at the end of any round. A "lead" is defined as the absolute difference between the cumulative scores of the two players. We need to output two things:
1. The player (1 or 2) who achieved this maximum lead.
2. The value of the maximum lead itself.

It's guaranteed that the maximum lead will always be non-zero.

## Intuition & Mathematical Observation

The core idea behind solving this problem is to simulate the game round by round and keep track of the cumulative scores for both players.

1.  **Cumulative Scores**: We need two variables, say `cumulative_score_P1` and `cumulative_score_P2`, initialized to zero. In each round `i`, we read `S_i` and `T_i`, and then update these variables:
    `cumulative_score_P1 += S_i`
    `cumulative_score_P2 += T_i`

2.  **Current Lead**: After updating the cumulative scores for a round, the current lead is simply the absolute difference between them:
    `current_lead = abs(cumulative_score_P1 - cumulative_score_P2)`

3.  **Maximum Lead Tracking**: We need another variable, `max_lead`, initialized to zero, to store the largest lead encountered so far. We also need a `winner` variable (initialized to 0 or any placeholder) to store which player achieved this `max_lead`.
    In each round, after calculating `current_lead`, we compare it with `max_lead`.
    If `current_lead > max_lead`:
    *   Update `max_lead = current_lead`.
    *   Determine which player is currently ahead:
        *   If `cumulative_score_P1 > cumulative_score_P2`, then Player 1 is leading, so `winner = 1`.
        *   Else (meaning `cumulative_score_P2 > cumulative_score_P1`, since ties in lead are not the maximum lead as per problem statement), Player 2 is leading, so `winner = 2`.

By iterating through all `N` rounds and performing these steps, we will correctly identify the maximum lead and the player who achieved it by the end of the game.

## Complexity Analysis

*   **Time Complexity**: $O(N)$
    The solution involves a single loop that iterates `N` times, once for each round. Inside the loop, all operations (reading input, additions, `abs()` function, comparisons, assignments) are constant time operations, $O(1)$. Therefore, the total time complexity is directly proportional to the number of rounds, `N`.

*   **Space Complexity**: $O(1)$
    The solution uses a fixed number of integer variables (`N`, `cumulative_score_P1`, `cumulative_score_P2`, `max_lead`, `winner`, `S_i`, `T_i`, `current_lead`) regardless of the input size `N`. No data structures that grow with `N` are used. Hence, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, cmath, algorithm, etc.

// It's common practice in competitive programming to use the entire std namespace for brevity.
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; // Number of rounds in the game
    cin >> N;

    int cumulative_score_P1 = 0; // Total score for Player 1
    int cumulative_score_P2 = 0; // Total score for Player 2
    int max_lead = 0;            // Stores the maximum lead achieved
    int winner = 0;              // Stores the player (1 or 2) who achieved max_lead

    // Loop through each round of the game
    for (int i = 0; i < N; ++i) {
        int S_i, T_i; // Scores for Player 1 and Player 2 in the current round
        cin >> S_i >> T_i;

        // Update cumulative scores
        cumulative_score_P1 += S_i;
        cumulative_score_P2 += T_i;

        // Calculate the current lead
        int current_lead = abs(cumulative_score_P1 - cumulative_score_P2);

        // Check if this current lead is greater than the maximum lead found so far
        if (current_lead > max_lead) {
            max_lead = current_lead; // Update max_lead
            
            // Determine who is currently leading and update the winner
            if (cumulative_score_P1 > cumulative_score_P2) {
                winner = 1; // Player 1 is leading
            } else { 
                // Player 2 is leading. The problem guarantees no ties for max lead,
                // so we don't need to explicitly handle cumulative_score_P1 == cumulative_score_P2
                // when updating max_lead.
                winner = 2; 
            }
        }
    }

    // Output the winner and the maximum lead achieved
    // Using "\n" instead of endl for potentially faster output, as endl also flushes the buffer.
    cout << winner << " " << max_lead << "\n";

    return 0; // Indicate successful execution
}
```