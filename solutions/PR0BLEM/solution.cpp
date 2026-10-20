#include <bits/stdc++.h> // Includes common libraries like iostream

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

// Function to solve a single test case
void solve() {
    int N, M;
    cin >> N >> M; // Read initial problems for Alice (N) and Bob (M)

    // The core logic: check if N and M have the same parity.
    // If N % 2 == M % 2, they have the same parity (both even or both odd).
    // If they have the same parity, it's possible to reach a state where they have
    // the same number of problems. Otherwise, it's impossible.
    if ((N % 2) == (M % 2)) {
        cout << "YES\n"; // Output YES if parities are the same
    } else {
        cout << "NO\n";  // Output NO if parities are different
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before reading input.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}