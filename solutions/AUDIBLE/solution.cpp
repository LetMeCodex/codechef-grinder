#include <bits/stdc++.h> // Required header for competitive programming

// Required namespace
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int X; // Declare an integer variable X to store the frequency of Chef's commands.
        cin >> X; // Read the frequency X for the current test case.

        // Check if the frequency X falls within the audible range for binary.
        // The range is from 67 Hertz to 45000 Hertz, inclusive.
        if (X >= 67 && X <= 45000) {
            // If X is within the range, binary can hear it.
            cout << "YES\n"; // Print "YES" followed by a newline.
        } else {
            // Otherwise, X is outside the audible range.
            cout << "NO\n"; // Print "NO" followed by a newline.
        }
    }

    return 0; // Indicate successful program execution.
}