#include <bits/stdc++.h> // Includes common standard libraries like iostream

// Use the standard namespace to avoid prefixing std::
using namespace std;

// Function to solve a single test case
void solve() {
    int A, B, C, D, E;
    // Read the five space-separated integers for the current test case
    cin >> A >> B >> C >> D >> E;

    // A boolean variable to track if any valid combination is found
    bool possible = false;

    // Scenario 1: Check-in bags A and B, carry bag C
    // Check if sum of A and B is within D AND C is within E
    if ((A + B <= D) && (C <= E)) {
        possible = true;
    }
    // Scenario 2: Check-in bags A and C, carry bag B
    // Only check this if a solution hasn't been found yet
    else if ((A + C <= D) && (B <= E)) {
        possible = true;
    }
    // Scenario 3: Check-in bags B and C, carry bag A
    // Only check this if a solution hasn't been found yet
    else if ((B + C <= D) && (A <= E)) {
        possible = true;
    }

    // Output "YES" if any scenario was possible, otherwise "NO"
    if (possible) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    // Read the number of test cases
    cin >> t;
    // Loop through each test case
    while (t--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful program termination
}