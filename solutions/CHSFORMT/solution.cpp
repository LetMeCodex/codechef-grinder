#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin/cout from C's stdio and prevents flushing cout before cin.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare variable for the number of testcases
    cin >> T; // Read the number of testcases

    // Loop through each testcase
    while (T--) {
        int a, b; // Declare variables for a and b
        cin >> a >> b; // Read a and b for the current testcase

        int sum = a + b; // Calculate the sum a + b

        // Apply the given conditions to determine the format
        if (sum < 3) {
            cout << 1 << "\n"; // Bullet format: a + b < 3
        } else if (sum <= 10) { // Blitz format: 3 <= a + b <= 10
            // This condition is reached if sum >= 3 (from previous if failing)
            // and sum <= 10.
            cout << 2 << "\n";
        } else if (sum <= 60) { // Rapid format: 11 <= a + b <= 60
            // This condition is reached if sum > 10 (from previous if failing)
            // and sum <= 60.
            cout << 3 << "\n";
        } else { // Classical format: 60 < a + b
            // This condition is reached if sum > 60 (from previous if failing).
            cout << 4 << "\n";
        }
    }

    return 0; // Indicate successful execution
}