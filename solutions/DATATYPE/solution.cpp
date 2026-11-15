#include <bits/stdc++.h> // Includes all standard libraries as requested

// Use the standard namespace as requested
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of testcases
    cin >> T; // Read the number of testcases

    // Loop through each testcase
    while (T--) {
        int N, X; // N: maximum value the data type can store, X: value Chef wants to store
        cin >> N >> X; // Read N and X for the current testcase

        // The data type can store values from 0 to N, inclusive.
        // This means there are N+1 distinct values in its range (0, 1, ..., N).
        // When a value X is greater than N, it is cyclically converted.
        // This cyclic conversion is precisely what the modulo operator (%) does.
        // The cycle length (or modulus) is N+1.
        //
        // For example:
        // If N=11, the range is 0-11. The cycle length is 11+1 = 12.
        // - If X=12, it becomes 12 % 12 = 0.
        // - If X=13, it becomes 13 % 12 = 1.
        //
        // If X is already within the range (0 to N), the modulo operation
        // will return X itself, which is correct.
        // For example:
        // If N=15, the range is 0-15. The cycle length is 15+1 = 16.
        // - If X=10, it becomes 10 % 16 = 10.
        // - If X=0, it becomes 0 % 16 = 0.
        //
        // Given the constraints (N, X <= 50), 'int' is sufficient to store
        // N, X, and the result of the modulo operation. No overflow issues.
        int stored_value = X % (N + 1);

        // Output the actual value stored in memory, followed by a newline
        cout << stored_value << "\n";
    }

    return 0; // Indicate successful program execution
}