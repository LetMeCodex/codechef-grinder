#include <bits/stdc++.h> // Includes most standard library headers

// Using the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases
    cin >> T; // Read the number of test cases from standard input

    // Loop T times, once for each test case
    while (T--) {
        int X, Y; // Declare integer variables X and Y for the current test case
        cin >> X >> Y; // Read X (Ezio's manipulation capacity) and Y (total guards)

        // Ezio can manipulate at most X guards.
        // To manipulate all Y guards, his capacity X must be
        // greater than or equal to the number of guards Y.
        if (X >= Y) {
            // If X is greater than or equal to Y, Ezio can manipulate all guards.
            cout << "YES\n"; // Print "YES" followed by a newline
        } else {
            // Otherwise, Ezio cannot manipulate all guards.
            cout << "NO\n"; // Print "NO" followed by a newline
        }
    }

    return 0; // Indicate successful program execution
}