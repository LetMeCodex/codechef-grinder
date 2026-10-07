#include <bits/stdc++.h> // Includes common headers like iostream

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

// Function to solve a single test case
void solve() {
    int X, Y, Z;
    // Read the three integers for the current test case
    cin >> X >> Y >> Z;

    // An arithmetic progression (X, Y, Z) satisfies the condition Y - X = Z - Y.
    // This can be algebraically rearranged to 2 * Y = X + Z.
    // We check if this condition is already met.
    if (2 * Y == X + Z) {
        // If the condition is met, the sequence is already an AP.
        // No operations are required.
        cout << 0 << "\n";
    } else {
        // If the condition is not met, 0 operations are not enough.
        // We need to determine if 1 operation is sufficient.
        // As discussed in the thought process, we can always make it an AP
        // in one operation by changing either X or Z to a suitable integer.
        // For example, to change X: set X' = 2*Y - Z. This will always be an integer.
        // So, 1 operation is always sufficient if 0 operations are not.
        cout << 1 << "\n";
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

    return 0; // Indicate successful program execution
}