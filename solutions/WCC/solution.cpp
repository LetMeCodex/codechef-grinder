#include <bits/stdc++.h> // Includes all standard libraries like iostream, string, etc.

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

// Function to solve a single test case
void solve() {
    long long X; // X can be up to 10^6. Prize money (e.g., 60*X) can be 6*10^7.
                 // Using long long for X and prize money is a good practice
                 // to ensure no overflow, even though int might suffice for 6*10^7.
    cin >> X;
    string S; // String to store the results of the 14 games
    cin >> S;

    int carlsen_points = 0; // Carlsen's total points
    int chef_points = 0;    // Chef's total points

    // Iterate through each game result in the string S
    for (char outcome : S) {
        if (outcome == 'C') {
            // Carlsen wins: Carlsen gets 2 points
            carlsen_points += 2;
        } else if (outcome == 'N') {
            // Chef wins: Chef gets 2 points
            chef_points += 2;
        } else { // outcome == 'D'
            // Draw: Both players get 1 point
            carlsen_points += 1;
            chef_points += 1;
        }
    }

    long long carlsen_prize; // Variable to store Carlsen's prize money

    // Determine Carlsen's prize based on the final points
    if (carlsen_points > chef_points) {
        // Carlsen has strictly more points, he is the champion
        carlsen_prize = 60 * X;
    } else if (chef_points > carlsen_points) {
        // Chef has strictly more points, Carlsen is the loser
        carlsen_prize = 40 * X;
    } else { // carlsen_points == chef_points
        // Points are tied. Carlsen is declared the winner as defending champion.
        carlsen_prize = 55 * X;
    }

    // Output Carlsen's prize money followed by a newline
    cout << carlsen_prize << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful program execution
}