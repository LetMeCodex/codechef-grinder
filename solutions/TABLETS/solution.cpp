#include <bits/stdc++.h> // Includes all standard libraries, as requested
using namespace std;       // Uses the standard namespace, as requested

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from the C standard streams and disables synchronization
    // with C's stdio, making input/output operations faster.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int X, Y; // Declare integer variables X and Y for each test case.
                  // X: number of days Chef needs to take tablets.
                  // Y: number of tablets Chef already has.
        cin >> X >> Y; // Read X and Y for the current test case.

        // Calculate the total number of tablets Chef needs.
        // Chef takes 3 tablets a day for X days.
        int tablets_needed = 3 * X;

        // Compare the tablets Chef has (Y) with the tablets Chef needs (tablets_needed).
        // If Chef has enough or more tablets, output "YES".
        // Otherwise, output "NO".
        if (Y >= tablets_needed) {
            cout << "YES\n"; // Output "YES" followed by a newline.
        } else {
            cout << "NO\n"; // Output "NO" followed by a newline.
        }
    }

    return 0; // Indicate successful program execution.
}