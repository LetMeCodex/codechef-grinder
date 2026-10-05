#include <bits/stdc++.h> // Includes iostream and many other standard libraries

// Using the entire std namespace as requested
using namespace std;

int main() {
    // Enable fast I/O operations.
    // This unties C++ standard streams from C standard streams
    // and prevents flushing cout before cin, speeding up input/output.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int N, M; // Declare integer variables N (runs required) and M (overs remaining).
        cin >> N >> M; // Read N and M for the current test case.

        // Calculate the maximum possible runs Chef's team can score.
        // 1 over consists of 6 balls.
        // A player can score a maximum of 6 runs in a ball.
        // So, maximum runs per over = 6 balls * 6 runs/ball = 36 runs.
        // Maximum total runs in M overs = M * 36 runs.
        int max_possible_runs = M * 36;

        // Check if the runs required (N) are less than or equal to the
        // maximum runs Chef's team can possibly score.
        if (N <= max_possible_runs) {
            // If yes, Chef's team can win. Print "YES" followed by a newline.
            cout << "YES\n";
        } else {
            // If no, Chef's team cannot win. Print "NO" followed by a newline.
            cout << "NO\n";
        }
    }

    return 0; // Indicate successful program execution.
}