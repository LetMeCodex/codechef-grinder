# Rock Paper Scissors (ROCPAPSCI)
- **Difficulty Rating**: 1220
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to find the maximum number of wins Chef can achieve in a sequence of $N$ Rock Paper Scissors games against Roku. Roku's moves are given as a string $A$. The constraint is that Chef cannot play the same move in two consecutive games. For example, if Chef plays 'R' in game $i$, Chef cannot play 'R' in game $i+1$.

## Intuition & Mathematical Observation
This problem can be modeled as finding the optimal strategy over a sequence of decisions, which suggests dynamic programming.

Let's define our DP state. We need to keep track of the maximum wins achieved up to a certain game, considering the move Chef made in that game. Since Chef's move in the current game affects the possible moves in the next game, we need to include Chef's last move in our state.

Let $dp[i][move]$ be the maximum number of wins Chef can achieve up to game $i$, where Chef's move in game $i$ was $move$. Here, $move$ can be 'R', 'P', or 'S'.

However, the constraint is that Chef cannot play the same move in two *consecutive* games. This means that to calculate the maximum wins for game $i$ with Chef playing $move_C$, we need to know the maximum wins up to game $i-1$ where Chef played a move *different* from $move_C$.

This leads to a more efficient DP approach. Instead of storing the DP state for each game index $i$, we can observe that the decision for game $i$ only depends on the results of game $i-1$. This allows us to optimize space by only keeping track of the DP states for the previous game.

Let $dp_{prev}[move]$ be the maximum number of wins Chef can achieve up to the *previous* game, ending with Chef playing $move$.
Let $dp_{curr}[move]$ be the maximum number of wins Chef can achieve up to the *current* game, ending with Chef playing $move$.

When considering game $i$ (with Roku's move $A[i]$):
For each possible move Chef can make in the current game (let's say $chef\_curr\_move$):
1. Calculate the win score for this specific game: $win\_score = 1$ if $chef\_curr\_move$ beats $A[i]$, otherwise $0$.
2. To achieve $dp_{curr}[chef\_curr\_move]$, Chef must have played a move *different* from $chef\_curr\_move$ in the previous game. So, we need to find the maximum wins from the previous game where Chef played a move other than $chef\_curr\_move$.
   If $chef\_curr\_move$ is 'R', the previous move could have been 'P' or 'S'. So, we take $\max(dp_{prev}[P], dp_{prev}[S])$.
   If $chef\_curr\_move$ is 'P', the previous move could have been 'R' or 'S'. So, we take $\max(dp_{prev}[R], dp_{prev}[S])$.
   If $chef\_curr\_move$ is 'S', the previous move could have been 'R' or 'P'. So, we take $\max(dp_{prev}[R], dp_{prev}[P])$.
3. $dp_{curr}[chef\_curr\_move] = win\_score + \max(\text{wins from previous game with different move})$.

After iterating through all possible $chef\_curr\_move$ for the current game, we update $dp_{prev} = dp_{curr}$ for the next iteration.

The base case is before the first game, where the maximum wins are 0 for any hypothetical previous move.

Let's represent 'R', 'P', 'S' with indices 0, 1, 2 respectively.
- 'R' -> 0
- 'P' -> 1
- 'S' -> 2

The winning conditions are:
- 'R' (0) beats 'S' (2)
- 'P' (1) beats 'R' (0)
- 'S' (2) beats 'P' (1)

If Chef's current move index is $c$, and Roku's move index is $r$:
`get_win_score(c, r)` returns 1 if $(c=0, r=2)$ or $(c=1, r=0)$ or $(c=2, r=1)$.

The DP transition becomes:
For game $i$ with Roku's move $A[i]$:
For each $chef\_curr\_idx$ from 0 to 2:
  $chef\_curr\_move = get\_idx\_char(chef\_curr\_idx)$
  $current\_game\_win\_score = get\_win\_score(chef\_curr\_move, A[i])$
  
  // The previous move must be different from chef_curr_idx.
  // The indices of other moves are (chef_curr_idx + 1) % 3 and (chef_curr_idx + 2) % 3.
  $max\_prev\_wins\_for\_this\_path = \max(dp\_prev[(chef\_curr\_idx + 1) \% 3], dp\_prev[(chef\_curr\_idx + 2) \% 3])$
  
  $dp\_curr[chef\_curr\_idx] = current\_game\_win\_score + max\_prev\_wins\_for\_this\_path$

After processing all $chef\_curr\_idx$ for game $i$, set $dp\_prev = dp\_curr$.

The final answer is the maximum value in $dp\_prev$ after all $N$ games.

## Complexity Analysis
- **Time Complexity**: $O(N \cdot M)$, where $N$ is the number of games and $M$ is the number of possible moves (which is 3 for Rock Paper Scissors). For each game, we iterate through the 3 possible moves Chef can make. Thus, the time complexity is $O(N \cdot 3) = O(N)$.

- **Space Complexity**: $O(M)$, where $M$ is the number of possible moves. We use two vectors, `dp_prev` and `dp_curr`, each of size 3, to store the DP states. Thus, the space complexity is $O(3) = O(1)$.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Using namespace std; as requested
using namespace std;

// Function to determine if chef_move wins against roku_move
// Returns 1 if Chef wins, 0 otherwise (draw or loss)
int get_win_score(char chef_move, char roku_move) {
    if (chef_move == 'R' && roku_move == 'S') return 1;
    if (chef_move == 'P' && roku_move == 'R') return 1;
    if (chef_move == 'S' && roku_move == 'P') return 1;
    return 0;
}

// Helper function to get the move character for a given index
// 0 -> 'R', 1 -> 'P', 2 -> 'S'
char get_idx_char(int idx) {
    if (idx == 0) return 'R';
    if (idx == 1) return 'P';
    return 'S'; // idx == 2
}

void solve() {
    int N;
    cin >> N;
    string A;
    cin >> A;

    // dp_prev[0] stores max wins ending with 'R' in the previous game.
    // dp_prev[1] stores max wins ending with 'P' in the previous game.
    // dp_prev[2] stores max wins ending with 'S' in the previous game.
    // Initialize with 0 wins for the "game before the first game".
    vector<int> dp_prev(3, 0); 
    
    // dp_curr will store max wins for the current game.
    vector<int> dp_curr(3, 0);

    for (int i = 0; i < N; ++i) {
        char roku_move = A[i];

        // Iterate through all possible moves Chef can make in the current game
        for (int chef_curr_idx = 0; chef_curr_idx < 3; ++chef_curr_idx) {
            char chef_curr_move = get_idx_char(chef_curr_idx);
            int current_game_win_score = get_win_score(chef_curr_move, roku_move);
            
            int max_prev_wins_for_this_path = 0;
            // Chef's current move must be different from the previous game's move.
            // So, we consider max wins from previous states where the last move was NOT chef_curr_move.
            // The two other possible previous moves are (chef_curr_idx + 1) % 3 and (chef_curr_idx + 2) % 3.
            max_prev_wins_for_this_path = max(dp_prev[(chef_curr_idx + 1) % 3], dp_prev[(chef_curr_idx + 2) % 3]);
            
            // Update dp_curr for the current move
            dp_curr[chef_curr_idx] = current_game_win_score + max_prev_wins_for_this_path;
        }
        
        // After calculating dp_curr for all possible moves in the current game,
        // update dp_prev to be dp_curr for the next iteration.
        dp_prev = dp_curr;
    }

    // The maximum wins will be the maximum value among the final dp_prev states.
    int max_total_wins = 0;
    for (int wins : dp_prev) {
        max_total_wins = max(max_total_wins, wins);
    }
    cout << max_total_wins << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```