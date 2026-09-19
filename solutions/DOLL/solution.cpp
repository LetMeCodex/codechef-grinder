#include <bits/stdc++.h> // Includes all standard libraries, as requested

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

// Function to solve a single test case
void solve() {
    int N, K;
    // Read the number of players (N) and the height of Gi-Hun/Ali (K)
    cin >> N >> K;

    int shot_players_count = 0; // Initialize a counter for players who need to be shot

    // Loop through each of the N players between Gi-Hun and Ali
    for (int i = 0; i < N; ++i) {
        int H_i;
        // Read the height of the current player
        cin >> H_i;

        // According to the problem statement, a player blocks the line of sight
        // if their height H_i is strictly greater than K.
        // Players with height H_i <= K do not block the line of sight.
        if (H_i > K) {
            shot_players_count++; // Increment the counter if the player blocks the view
        }
    }

    // Output the minimum number of players who need to be shot for this test case
    cout << shot_players_count << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming to prevent TLE (Time Limit Exceeded)
    // on problems with large inputs.
    ios_base::sync_with_stdio(false); // Unties C++ streams from C standard streams
    cin.tie(NULL);                   // Prevents cin from flushing cout before each input operation

    int T;
    // Read the total number of test cases
    cin >> T;

    // Loop T times, calling the solve function for each test case
    while (T--) {
        solve();
    }

    return 0; // Indicate successful program execution
}