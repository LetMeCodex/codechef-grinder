#include <bits/stdc++.h> // Includes all standard libraries

// Using the standard namespace to avoid prefixing std::
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from the C standard streams and
    // prevents synchronization with stdio, making I/O operations faster.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare variable for the number of test cases
    cin >> T; // Read the number of test cases from standard input

    // Loop through each test case
    while (T--) {
        int D, N; // Declare variables for D and N for the current test case
        cin >> D >> N; // Read D and N

        // Initialize current_N with the input N.
        // Using long long to store current_N to prevent potential integer overflow,
        // especially during the calculation of current_N * (current_N + 1),
        // although for the given constraints (D, N <= 4), int would technically suffice.
        long long current_N = N;

        // Apply the sum operation D times
        for (int i = 0; i < D; ++i) {
            // The sum of integers from 1 to X is given by the formula X * (X + 1) / 2.
            // We update current_N by applying this formula to its current value.
            current_N = current_N * (current_N + 1) / 2;
        }

        // Output the final calculated value for the current test case,
        // followed by a newline character as required.
        cout << current_N << "\n";
    }

    return 0; // Indicate successful program execution
}