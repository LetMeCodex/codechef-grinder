#include <bits/stdc++.h> // Includes iostream and many other standard libraries

// Use the standard namespace as requested
using namespace std;

int main() {
    // Enable fast I/O operations as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare variable for the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int A, B, C, D; // Declare variables for the four angles
        cin >> A >> B >> C >> D; // Read the four angles for the current test case

        // A quadrilateral is cyclic if the sum of opposite angles is 180 degrees.
        // Given A, B, C, D in order along its perimeter, A and C are opposite angles.
        // The problem also guarantees A + B + C + D = 360.
        // If A + C = 180, then B + D must also be 180 (since 360 - 180 = 180).
        // Therefore, checking only one pair of opposite angles (e.g., A + C) is sufficient.
        if (A + C == 180) {
            cout << "YES\n"; // If the condition is met, print "YES"
        } else {
            cout << "NO\n"; // Otherwise, print "NO"
        }
    }

    return 0; // Indicate successful program execution
}