#include <bits/stdc++.h> // Includes all standard libraries

using namespace std; // Uses the standard namespace

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from the C standard streams and prevents flushing
    // of cout before cin operations, leading to faster I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases
    cin >> T; // Read the number of test cases from standard input

    // Loop T times, once for each test case
    while (T--) {
        int X; // Declare an integer variable X for the battery health percentage
        cin >> X; // Read the battery health percentage for the current test case

        // Check if the battery health X is 80% or above
        if (X >= 80) {
            cout << "YES\n"; // If X is 80 or greater, print "YES" followed by a newline
        } else {
            cout << "NO\n"; // Otherwise (if X is less than 80), print "NO" followed by a newline
        }
    }

    return 0; // Indicate successful program execution
}