#include <bits/stdc++.h> // Includes all standard libraries, as requested by the problem statement.

// Using the standard namespace as requested by the problem statement.
using namespace std;

// Function to solve a single test case.
void solve() {
    // Declare an array of 6 strings to store the outcomes of the 6 balls.
    // Each outcome can be an integer (e.g., "1", "2") or "W".
    string s[6];
    // Read the outcomes for the 6 balls from standard input.
    for (int i = 0; i < 6; ++i) {
        cin >> s[i];
    }

    // Check for a hattrick. A hattrick occurs if three consecutive balls result in a 'W' (wicket).
    // There are four possible sequences of three consecutive balls in a 6-ball over:
    // 1. Balls at indices 0, 1, 2 (corresponding to A, B, C)
    // 2. Balls at indices 1, 2, 3 (corresponding to B, C, D)
    // 3. Balls at indices 2, 3, 4 (corresponding to C, D, E)
    // 4. Balls at indices 3, 4, 5 (corresponding to D, E, F)
    // We use logical OR (||) to check if any of these conditions are true.
    if ((s[0] == "W" && s[1] == "W" && s[2] == "W") || // Check for hattrick with balls A, B, C
        (s[1] == "W" && s[2] == "W" && s[3] == "W") || // Check for hattrick with balls B, C, D
        (s[2] == "W" && s[3] == "W" && s[4] == "W") || // Check for hattrick with balls C, D, E
        (s[3] == "W" && s[4] == "W" && s[5] == "W")) { // Check for hattrick with balls D, E, F
        // If any of the hattrick conditions are met, print "YES".
        cout << "YES\n";
    } else {
        // Otherwise, no hattrick was found in this over, so print "NO".
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // This is a common practice in competitive programming to prevent TLE (Time Limit Exceeded)
    // on problems with large input/output.
    ios_base::sync_with_stdio(false); // Unties C++ standard streams from C standard streams.
    cin.tie(NULL);                    // Prevents cin from flushing cout before each input operation.

    int t; // Variable to store the number of test cases.
    cin >> t; // Read the number of test cases from standard input.
    // Loop through each test case.
    while (t--) {
        solve(); // Call the solve function to process each test case.
    }

    return 0; // Indicate successful program execution.
}