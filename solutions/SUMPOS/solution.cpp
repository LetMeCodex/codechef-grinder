#include <bits/stdc++.h> // Includes common headers like iostream

using namespace std; // Use the standard namespace as requested

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Declare an integer variable 't' to store the number of testcases.
    cin >> t; // Read the number of testcases from standard input.

    // Loop through each testcase. The 't--' decrements 't' after each iteration
    // until 't' becomes 0, effectively running the loop 't' times.
    while (t--) {
        int x, y, z; // Declare three integer variables to store the input numbers.
        cin >> x >> y >> z; // Read the three space-separated integers for the current testcase.

        // Check if any of the three conditions are true:
        // 1. x is the sum of y and z
        // 2. y is the sum of x and z
        // 3. z is the sum of x and y
        if (x == y + z || y == x + z || z == x + y) {
            cout << "YES\n"; // If any condition is true, print "YES" followed by a newline.
        } else {
            cout << "NO\n"; // Otherwise (if none of the conditions are true), print "NO" followed by a newline.
        }
    }

    return 0; // Indicate successful program execution.
}