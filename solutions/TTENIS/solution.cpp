#include <bits/stdc++.h> // Includes all standard libraries

// Using namespace std; is requested by the problem statement.
using namespace std;

void solve() {
    string s;
    cin >> s; // Read the binary string representing the match points

    int chef_score = 0;
    int opp_score = 0;

    // Iterate through each character (point) in the string
    for (char c : s) {
        if (c == '1') {
            chef_score++; // Chef won the point
        } else { // c == '0'
            opp_score++; // Chef lost the point (opponent won)
        }

        // Check for winner after each point according to table tennis rules
        // A player wins if they have at least 11 points AND a lead of at least 2 points.
        // This single condition covers both the "first to 11" rule and the "deuce" rule (win by 2 points).

        // Check if Chef won
        if (chef_score >= 11 && (chef_score - opp_score >= 2)) {
            cout << "WIN\n"; // Chef wins
            return; // Game finished, exit function for this test case
        }

        // Check if Opponent won
        if (opp_score >= 11 && (opp_score - chef_score >= 2)) {
            cout << "LOSE\n"; // Opponent wins
            return; // Game finished, exit function for this test case
        }
    }
    // The problem guarantees that statistics represent a valid, finished match.
    // Therefore, one of the 'return' statements inside the loop will always be executed.
    // This part of the code should theoretically be unreachable if the problem statement's
    // guarantee holds true and the logic is correct.
}

int main() {
    // Fast I/O setup as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Call the solve function for each test case
    }

    return 0;
}