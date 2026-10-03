#include <bits/stdc++.h> // Includes common headers like iostream

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

// Function to solve a single test case
void solve() {
    int A, B, C;
    // Read the three problem scores
    cin >> A >> B >> C;

    // Check if any of the three conditions for a draw are met:
    // 1. Bob solves A, Alice solves B and C (A == B + C)
    // 2. Bob solves B, Alice solves A and C (B == A + C)
    // 3. Bob solves C, Alice solves A and B (C == A + B)
    if (A == B + C || B == A + C || C == A + B) {
        cout << "YES\n"; // If any condition is true, a draw is possible
    } else {
        cout << "NO\n";  // Otherwise, a draw is not possible
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    // Read the number of test cases
    cin >> T;
    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}