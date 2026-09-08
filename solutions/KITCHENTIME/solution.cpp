#include <bits/stdc++.h> // Includes all standard C++ libraries

// Use the standard namespace to avoid prefixing standard library elements with std::
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and prevents synchronization with C's stdio,
    // leading to faster input/output operations.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable to store the number of test cases
    cin >> T; // Read the number of test cases from standard input

    // Loop T times, once for each test case
    while (T--) {
        int X, Y; // Declare two integer variables for the start and end times
        cin >> X >> Y; // Read the start time X and end time Y for the current test case

        // Calculate the duration Chef works.
        // Since X is the start time and Y is the end time, and Y > X,
        // the duration is simply their difference.
        int duration = Y - X;

        // Print the calculated duration followed by a newline character.
        // Using "\n" is generally faster than endl in competitive programming
        // because endl also flushes the output buffer.
        cout << duration << "\n";
    }

    return 0; // Indicate successful program execution
}