#include <bits/stdc++.h> // Includes all standard libraries

// Using the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can speed up I/O operations.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // further speeding up I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases
    cin >> T; // Read the number of test cases from standard input

    // Loop T times, once for each test case
    while (T--) {
        int X; // Declare an integer variable X for the body temperature in °F
        cin >> X; // Read the body temperature for the current test case

        // Determine if Chef has fever based on the problem's condition:
        // A person has fever if their body temperature is strictly greater than 98 °F.
        if (X > 98) {
            // If X is strictly greater than 98, Chef has fever.
            cout << "YES\n"; // Print "YES" followed by a newline
        } else {
            // Otherwise (if X is 98 or less), Chef does not have fever.
            cout << "NO\n"; // Print "NO" followed by a newline
        }
    }

    return 0; // Indicate successful execution of the program
}