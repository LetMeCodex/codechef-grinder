#include <bits/stdc++.h> // Includes all standard libraries

// Using the standard namespace to avoid writing std:: repeatedly
using namespace std;

// Function to solve a single test case
void solve() {
    int X, Y; // Declare variables for the prices of the two cab services
    cin >> X >> Y; // Read the prices X and Y from input

    // Compare the prices to determine which cab service is cheaper
    if (X < Y) {
        // If the first cab service (X) is cheaper than the second (Y)
        cout << "FIRST\n"; 
    } else if (Y < X) {
        // If the second cab service (Y) is cheaper than the first (X)
        cout << "SECOND\n";
    } else { // X == Y
        // If both cab services have the same price
        cout << "ANY\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can speed up I/O operations.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // further speeding up I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare variable for the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function to handle the current test case
    }

    return 0; // Indicate successful execution of the program
}