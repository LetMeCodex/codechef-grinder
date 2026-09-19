#include <bits/stdc++.h> // Includes all standard libraries, as requested.

// Using the standard namespace, as requested.
using namespace std;

// Function to solve a single test case.
void solve() {
    int X; // Declare an integer variable X for the spice level.
    cin >> X; // Read the spice level X from standard input.

    // Apply the categorization rules using if-else if-else statements.
    // The conditions are checked in order.
    if (X < 4) {
        // If the spice level is strictly less than 4, it's MILD.
        cout << "MILD\n";
    } else if (X < 7) {
        // If the previous condition (X < 4) was false, it means X >= 4.
        // So, if X is also strictly less than 7, it falls into the MEDIUM category.
        // This covers the range 4 <= X < 7.
        cout << "MEDIUM\n";
    } else {
        // If neither of the above conditions were met, it means X is not less than 4
        // AND X is not less than 7. This implies X must be greater than or equal to 7.
        // Thus, it's in the HOT category.
        cout << "HOT\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases.
    cin >> T; // Read the number of test cases.

    // Loop T times, calling the solve function for each test case.
    while (T--) {
        solve();
    }

    return 0; // Indicate successful execution of the program.
}