#include <bits/stdc++.h> // Includes most standard libraries

// It's common practice in competitive programming to use the entire std namespace
// to avoid repeatedly typing std::
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin/cout from the C standard streams and disables synchronization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int N, X;
        cin >> N >> X; // Read N (number of people) and X (number of tiles)

        // A Jenga game is considered "valid" if two conditions are met:
        // 1. All players have a tile in each round.
        //    This implies that the total number of tiles X must be at least N.
        //    If X < N, there aren't enough tiles for even one round for all N players.
        // 2. All tiles are used at the end.
        //    Since N tiles are used per round (1 tile per player), the total number of tiles X
        //    must be perfectly divisible by N. That is, X % N must be equal to 0.

        // Let's analyze the combined condition:
        // Given the constraints 1 <= N, X <= 1000:
        // Both N and X are positive integers.
        // If X % N == 0, it means X is a positive multiple of N.
        // The smallest positive multiple of N is N itself (when X = 1 * N).
        // Any other positive multiple of N (e.g., 2*N, 3*N, ...) will be greater than N.
        // Therefore, if X % N == 0 and N, X are positive, it automatically implies that X >= N.
        // So, checking only if X is perfectly divisible by N (X % N == 0) is sufficient
        // to satisfy both conditions for a valid game.

        if (X % N == 0) {
            cout << "YES\n"; // If X is a multiple of N, the game is valid
        } else {
            cout << "NO\n";  // Otherwise, the game is not valid
        }
    }

    return 0; // Indicate successful execution
}