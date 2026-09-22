#include <bits/stdc++.h> // Includes common standard libraries like iostream

using namespace std; // Allows using standard library elements without the std:: prefix

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int A, B; // Variables to store the first two numbers drawn
        cin >> A >> B; // Read the two numbers for the current test case

        // Calculate the required third number (C) to make the sum 21
        int C = 21 - A - B;

        // Check if the calculated C is a valid number (between 1 and 10 inclusive)
        if (C >= 1 && C <= 10) {
            // If C is valid, print C
            cout << C << "\n";
        } else {
            // If C is not valid (either too low or too high), Chef cannot win.
            // Print -1 as per problem statement.
            cout << -1 << "\n";
        }
    }

    return 0; // Indicate successful program execution
}