#include <bits/stdc++.h> // Includes all standard libraries, as requested

using namespace std; // Uses the standard namespace, as requested

void solve() {
    // Initialize max_points to a value lower than any possible score.
    // The minimum possible score is 0 (0 runs, 0 wickets), so -1 is a safe initial value.
    int max_points = -1; 
    // Initialize man_of_the_match_index to an invalid value.
    // It will be updated with the 1-based index of the first player or any player with a higher score.
    int man_of_the_match_index = -1;

    // Iterate through all 22 players. Player indices are 1-based.
    for (int i = 1; i <= 22; ++i) {
        int runs, wickets;
        // Read the runs scored and wickets taken by the current player.
        cin >> runs >> wickets;

        // Calculate the total points for the current player.
        // Each run earns 1 point, and each wicket earns 20 points.
        int current_player_points = runs * 1 + wickets * 20;

        // Check if the current player's points are greater than the maximum points found so far.
        // The problem guarantees a unique "Man of the Match", so we don't need to handle ties.
        if (current_player_points > max_points) {
            max_points = current_player_points; // Update the maximum points.
            man_of_the_match_index = i;         // Update the index of the player with the maximum points.
        }
    }
    // Output the 1-based index of the player who has the highest total points.
    cout << man_of_the_match_index << "\n";
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // `ios_base::sync_with_stdio(false)` disables synchronization between C-style I/O (stdio)
    // and C++-style I/O (iostream), which can speed up I/O operations.
    // `cin.tie(NULL)` unties `cin` from `cout`, meaning `cin` will not flush `cout` before
    // reading input, further improving performance.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    // Read the number of test cases.
    cin >> t; 
    // Loop through each test case.
    while (t--) { 
        solve(); // Call the solve function to process the current test case.
    }

    return 0; // Indicate successful program execution.
}