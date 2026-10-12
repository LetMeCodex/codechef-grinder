#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

// Function to solve a single test case
void solve() {
    int india_wins = 0;    // Counter for matches won by India
    int england_wins = 0;  // Counter for matches won by England

    // Loop 5 times to read the results of all 5 matches
    for (int i = 0; i < 5; ++i) {
        int R_i; // Variable to store the result of the current match
        cin >> R_i; // Read the match result

        // Check the result and update the respective win counter
        if (R_i == 1) {
            // India won this match
            india_wins++;
        } else if (R_i == 2) {
            // England won this match
            england_wins++;
        }
        // If R_i == 0, it's a draw, so neither counter is incremented.
    }

    // Determine the winner of the series based on the total wins
    if (india_wins > england_wins) {
        // India won strictly more matches
        cout << "INDIA\n";
    } else if (england_wins > india_wins) {
        // England won strictly more matches
        cout << "ENGLAND\n";
    } else {
        // Both teams won the same number of matches, or neither won any
        cout << "DRAW\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases

    // Loop T times, calling the solve function for each test case
    while (T--) {
        solve();
    }

    return 0; // Indicate successful execution
}