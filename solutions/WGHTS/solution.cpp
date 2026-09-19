#include <bits/stdc++.h> // Includes most standard libraries

using namespace std; // Allows using standard library elements without the std:: prefix

// Function to solve a single test case
void solve() {
    int W, X, Y, Z;
    cin >> W >> X >> Y >> Z; // Read the four weights

    bool possible = false; // Flag to track if W can be measured

    // Check if W can be measured using a single weight
    if (W == X || W == Y || W == Z) {
        possible = true;
    }

    // If not found yet, check combinations of two weights
    // The `!possible` check ensures we only proceed if a solution hasn't been found
    if (!possible && (W == X + Y || W == X + Z || W == Y + Z)) {
        possible = true;
    }

    // If not found yet, check the combination of all three weights
    if (!possible && (W == X + Y + Z)) {
        possible = true;
    }

    // Output the result based on the 'possible' flag
    if (possible) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}