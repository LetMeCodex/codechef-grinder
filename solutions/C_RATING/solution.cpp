#include <bits/stdc++.h> // Includes all standard libraries, as requested

using namespace std; // Uses the standard namespace, as requested

void solve() {
    int X, Y;
    cin >> X >> Y; // Read current rating X and target rating Y

    // Calculate the difference needed in rating.
    // Since X <= Y, diff will always be non-negative.
    int diff = Y - X;

    // The number of games needed is ceil(diff / 8).
    // For non-negative integer 'diff' and positive integer 'divisor' (8 in this case),
    // ceil(diff / divisor) can be calculated using integer division as:
    // (diff + divisor - 1) / divisor
    int games_needed = (diff + 8 - 1) / 8; // This simplifies to (diff + 7) / 8

    cout << games_needed << "\n"; // Output the result followed by a newline
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}