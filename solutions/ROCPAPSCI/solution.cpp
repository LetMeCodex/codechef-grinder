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