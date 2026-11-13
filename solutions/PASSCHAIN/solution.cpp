#include <bits/stdc++.h> // Includes all standard libraries, as suggested

// Using the standard namespace, as suggested
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int N, K; // Variables to store the number of players and passing power
        cin >> N >> K; // Read N and K for the current test case

        int current_player = 1; // The ball initially starts with player 1

        // Simulate the passing chain.
        // The loop continues as long as the current player can pass the ball
        // to a valid player (i.e., current_player + K is within the range [1, N]).
        while (current_player + K <= N) {
            current_player = current_player + K; // Pass the ball to the next player
        }

        // After the loop terminates, 'current_player' holds the ball and cannot
        // pass it further. This is the final player.
        cout << current_player << "\n"; // Output the number of the final player, followed by a newline
    }

    return 0; // Indicate successful execution
}