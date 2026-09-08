#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace to avoid prefixing std::
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can be slow.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // further speeding up I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases
    cin >> T; // Read the number of test cases from input

    // Loop T times, once for each test case
    while (T--) {
        int X, Y; // Declare integer variables X for Alice's height and Y for Bob's height
        cin >> X >> Y; // Read Alice's and Bob's heights for the current test case

        // Compare their heights to determine who is taller
        if (X > Y) {
            // If Alice's height (X) is greater than Bob's height (Y), Alice is taller
            cout << "A\n"; // Output 'A' followed by a newline character
        } else {
            // Since it's guaranteed that X != Y, if X is not greater than Y,
            // then Y must be greater than X. So, Bob is taller.
            cout << "B\n"; // Output 'B' followed by a newline character
        }
    }

    return 0; // Indicate successful program execution
}