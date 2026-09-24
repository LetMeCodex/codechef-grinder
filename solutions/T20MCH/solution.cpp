#include <bits/stdc++.h> // Includes iostream and many other standard libraries

// Using the standard namespace as requested
using namespace std;

int main() {
    // Enable fast I/O operations as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare three integer variables to store the input values:
    // R: Team A's total score
    // O: Number of overs Team B has already played
    // C: Team B's current score
    int R, O, C;

    // Read the three integers from standard input
    cin >> R >> O >> C;

    // Calculate the number of overs remaining for Team B to play.
    // A T20 match has 20 overs per team.
    int remaining_overs = 20 - O;

    // Calculate the maximum runs Team B can score in the remaining overs.
    // In each over, there are 6 balls.
    // On each ball, a maximum of 6 runs can be scored.
    // So, maximum runs per over = 6 balls * 6 runs/ball = 36 runs.
    // Maximum runs in remaining overs = remaining_overs * 36.
    int max_runs_in_remaining_overs = remaining_overs * 36;

    // Calculate the maximum total score Team B can achieve.
    // This is their current score plus the maximum runs they can score in the remaining overs.
    int max_team_b_score = C + max_runs_in_remaining_overs;

    // Check if Team B's maximum possible score is strictly greater than Team A's score (R).
    // If it is, Team B can win.
    if (max_team_b_score > R) {
        // Output "YES" if Team B can win
        cout << "YES\n";
    } else {
        // Otherwise, output "NO"
        cout << "NO\n";
    }

    // Return 0 to indicate successful execution
    return 0;
}