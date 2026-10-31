#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace for convenience in competitive programming
using namespace std;

void solve() {
    int N, X;
    cin >> N >> X; // Read N and X for the current test case

    // Total players = 2N
    // Rated players = X
    // Unrated players = 2N - X

    // We want to minimize the number of rated players whose opponents are also rated.
    // This is achieved by maximizing the number of Rated-Unrated (R-U) pairs.

    // Case 1: If the number of rated players (X) is less than or equal to
    // the number of unrated players (2N - X).
    // This simplifies to X <= N.
    // In this scenario, we can pair every rated player with an unrated player.
    // No rated player will have a rated opponent.
    if (X <= N) {
        cout << 0 << "\n";
    }
    // Case 2: If the number of rated players (X) is greater than
    // the number of unrated players (2N - X).
    // This simplifies to X > N.
    // In this scenario, we use all (2N - X) unrated players to form R-U pairs.
    // This leaves X - (2N - X) = 2X - 2N rated players without an unrated opponent.
    // These remaining (2X - 2N) rated players must be paired among themselves.
    // They will form (2X - 2N) / 2 = X - N pairs of Rated-Rated (R-R).
    // Each R-R pair consists of two rated players, both of whom have rated opponents.
    // So, each R-R pair contributes 2 to our count.
    // The total count is 2 * (number of R-R pairs) = 2 * (X - N).
    else { // X > N
        cout << 2 * (X - N) << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times, solving each test case
        solve();
    }

    return 0; // Indicate successful execution
}