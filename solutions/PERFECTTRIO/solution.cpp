#include <bits/stdc++.h> // Includes all standard libraries, as per competitive programming common practice

// Use the standard namespace to avoid typing std:: repeatedly
using namespace std;

// Function to solve a single test case
void solve() {
    int A, B, C;
    // Read the three ages for the current test case
    cin >> A >> B >> C;

    // Check if any of the three conditions for a perfect group are met:
    // 1. Age of A is the sum of B and C (A = B + C)
    // 2. Age of B is the sum of A and C (B = A + C)
    // 3. Age of C is the sum of A and B (C = A + B)
    if (A == B + C || B == A + C || C == A + B) {
        // If any condition is true, the group is perfect
        cout << "YES\n";
    } else {
        // Otherwise, the group is not perfect
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    // Read the number of test cases
    cin >> T;
    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}