#include <bits/stdc++.h> // Includes all standard libraries

using namespace std; // Use standard namespace

// Function to solve a single test case
void solve() {
    int X;
    cin >> X; // Read the seat number X

    // Determine the nearest exit based on the seat number X.
    // The midpoint between seat 1 and seat 100 is 50.5.
    // Seats 1 through 50 are closer to seat 1 (LEFT exit).
    // Seats 51 through 100 are closer to seat 100 (RIGHT exit).
    if (X <= 50) {
        cout << "LEFT\n"; // Passenger chooses the exit beside seat 1
    } else {
        cout << "RIGHT\n"; // Passenger chooses the exit beside seat 100
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin/cout from the C standard I/O library and
    // prevents flushing cout before each cin.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times for each test case
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}