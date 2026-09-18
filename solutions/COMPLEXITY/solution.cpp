#include <bits/stdc++.h> // Required include for competitive programming, includes iostream, string, etc.

using namespace std; // Required to avoid writing std:: prefix

// Function to solve a single test case
void solve() {
    int X, Y; // Declare two integers X and Y
    cin >> X >> Y; // Read the number of comparisons for algorithm A (X) and algorithm B (Y)

    // According to the problem definition, algorithm A has more time complexity
    // than algorithm B if it uses MORE number of comparisons.
    // So, we check if X is strictly greater than Y.
    if (X > Y) {
        cout << "YES\n"; // If X is greater than Y, print YES
    } else {
        cout << "NO\n"; // Otherwise (if X is less than or equal to Y), print NO
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer T for the number of test cases
    cin >> T; // Read the number of test cases

    // Loop T times, once for each test case
    while (T--) {
        solve(); // Call the solve function to handle the current test case
    }

    return 0; // Indicate successful execution
}