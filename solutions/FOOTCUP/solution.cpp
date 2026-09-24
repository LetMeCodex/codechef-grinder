#include <bits/stdc++.h> // Required include for competitive programming

// Required namespace
using namespace std;

// Function to solve a single test case
void solve() {
    int X, Y;
    cin >> X >> Y; // Read the goals scored by both teams

    // Chef likes a match if:
    // 1. The match ends in a draw (X == Y)
    // 2. At least one goal has been scored by either team (X + Y > 0)
    //
    // If X == Y, then X + Y > 0 simplifies to 2*X > 0, which means X > 0.
    // So, the combined condition is X == Y AND X > 0.
    if (X == Y && X > 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0;
}