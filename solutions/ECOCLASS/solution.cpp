#include <bits/stdc++.h> // Includes most standard libraries like iostream, vector, etc.

// Use the standard namespace to avoid prefixing standard library elements with std::
using namespace std;

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the number of time points for this test case

    // Declare two vectors to store supply and demand data.
    // Vectors are dynamic arrays, suitable when size N is known at runtime.
    vector<int> S(N); // Supply array
    vector<int> D(N); // Demand array

    // Read the supply values into the S vector
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }

    // Read the demand values into the D vector
    for (int i = 0; i < N; ++i) {
        cin >> D[i];
    }

    int equilibrium_count = 0; // Initialize a counter for time points in equilibrium

    // Iterate through each time point from 0 to N-1
    for (int i = 0; i < N; ++i) {
        // Check if supply equals demand at the current time point
        if (S[i] == D[i]) {
            equilibrium_count++; // If they are equal, increment the counter
        }
    }

    // Output the total number of equilibrium points for the current test case
    cout << equilibrium_count << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function to handle the current test case
    }

    return 0; // Indicate successful program execution
}