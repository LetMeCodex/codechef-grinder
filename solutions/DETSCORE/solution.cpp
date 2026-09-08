#include <bits/stdc++.h> // Include all standard libraries

// Use the standard namespace
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare variable for number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int X, N; // Declare variables for total points and passed test cases
        cin >> X >> N; // Read X (total points) and N (passed test cases) for the current test case

        // The problem states there are exactly 10 test cases, and each is worth the same number of points.
        // Also, X is guaranteed to be a multiple of 10.
        // So, points per test case = X / 10.
        // Chef's total score is (points per test case) * (number of passed test cases).
        int score = (X / 10) * N;

        // Output the calculated score followed by a newline
        cout << score << "\n";
    }

    return 0; // Indicate successful execution
}