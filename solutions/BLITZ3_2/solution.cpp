#include <bits/stdc++.h> // Includes most standard libraries, as requested.

// Using the standard namespace to avoid prefixing std:: to standard library elements.
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and disables synchronization with C's stdio,
    // which can significantly speed up I/O operations.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop through each test case.
    while (T--) {
        int N, A, B; // Declare integer variables N, A, B for each test case.
        // N: total number of turns in the game.
        // A: seconds remaining on white's clock at the end.
        // B: seconds remaining on black's clock at the end.
        cin >> N >> A >> B; // Read N, A, and B for the current test case.

        // Problem analysis:
        // 1. Initial time for each player: 3 minutes = 3 * 60 = 180 seconds.
        //    So, total initial time for both players = 180 + 180 = 360 seconds.
        //
        // 2. Increment per move: 2 seconds.
        //    The game lasts N turns. Each turn involves one move, which adds 2 seconds
        //    to the clock of the player who made that move.
        //    Therefore, across N turns, a total of N * 2 seconds are added to the clocks.
        //
        // 3. Total "potential" time on both clocks combined:
        //    This is the sum of all initial times and all increments received.
        //    Total potential time = (Total initial time) + (Total increments)
        //    Total potential time = 360 + (2 * N) seconds.
        //
        // 4. Total time remaining on both clocks at the end: A + B.
        //
        // 5. The duration of the game is the total time that was *spent* by both players.
        //    This is calculated by subtracting the total time remaining from the total potential time.
        int duration = (360 + 2 * N) - (A + B);

        // Print the calculated duration followed by a newline character.
        cout << duration << "\n";
    }

    return 0; // Indicate successful execution of the program.
}