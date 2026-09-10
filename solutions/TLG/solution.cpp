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