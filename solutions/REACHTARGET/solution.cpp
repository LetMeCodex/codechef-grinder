#include <bits/stdc++.h> // Includes all standard libraries, as requested
using namespace std;       // Uses the standard namespace, as requested

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from C's stdio and prevents synchronization with cout.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    // T-- decrements T after each iteration, and the loop continues as long as T is positive.
    while (T--) {
        int X, Y; // Declare integer variables X (target score) and Y (current score).
        cin >> X >> Y; // Read X and Y for the current test case.

        // Calculate the number of runs Team B needs to score to win.
        // To win, Team B must reach X runs. They currently have Y runs.
        // So, they need X - Y more runs.
        int runs_needed = X - Y;

        // Print the calculated runs_needed to standard output, followed by a newline character.
        cout << runs_needed << "\n";
    }

    return 0; // Indicate successful program execution.
}