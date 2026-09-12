#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int N; // Declare an integer variable N to store the hours of free time.
        cin >> N; // Read the number of hours for the current test case.

        // Calculate the maximum number of complete chess games.
        // One hour has 60 minutes. So, N hours have N * 60 minutes.
        // Each game takes at least 20 minutes. To maximize games, assume each takes exactly 20 minutes.
        // Total minutes / minutes per game = (N * 60) / 20.
        // This simplifies to N * (60 / 20) = N * 3.
        int max_games = N * 3;

        // Output the result for the current test case, followed by a newline character.
        cout << max_games << "\n";
    }

    return 0; // Indicate successful program execution.
}