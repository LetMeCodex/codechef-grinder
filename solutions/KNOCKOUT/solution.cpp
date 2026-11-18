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