#include <bits/stdc++.h> // Includes all standard libraries for convenience

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

// Function to solve a single test case
void solve() {
    int N; // Declare an integer variable N to store the number of bits
    cin >> N; // Read the value of N from standard input

    // Check if N is perfectly divisible by 4
    // If N % 4 == 0, it means N bits is an exact integer number of nibbles.
    // Since N >= 1, this integer number of nibbles will also be positive.
    if (N % 4 == 0) {
        cout << "Good\n"; // If divisible, the program is "Good"
    } else {
        cout << "Not Good\n"; // Otherwise, the program is "Not Good"
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

    int T; // Declare an integer variable T to store the number of test cases
    cin >> T; // Read the value of T from standard input

    // Loop T times, calling the solve() function for each test case
    while (T--) {
        solve();
    }

    return 0; // Indicate successful program execution
}