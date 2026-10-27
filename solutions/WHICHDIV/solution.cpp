#include <bits/stdc++.h> // Includes most standard libraries

// Use the standard namespace to avoid typing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Declare an integer variable 't' to store the number of test cases.
    cin >> t; // Read the number of test cases from standard input.

    // Loop 't' times, once for each test case.
    // The 't--' decrements 't' after each iteration until it becomes 0.
    while (t--) {
        int R; // Declare an integer variable 'R' to store the person's rating.
        cin >> R; // Read the rating for the current test case.

        // Apply the division rules using if-else if-else statements.
        // Check for Division 1 first (highest rating range).
        if (R >= 2000) {
            cout << 1 << "\n"; // If R is 2000 or more, output 1 for Division 1.
        } 
        // If not Division 1, check for Division 2.
        // This 'else if' implicitly means R < 2000.
        else if (R >= 1600) { 
            cout << 2 << "\n"; // If R is between 1600 and 1999 (inclusive), output 2 for Division 2.
        } 
        // If neither of the above conditions is met, it must be Division 3.
        // This 'else' implicitly means R < 1600.
        else {
            cout << 3 << "\n"; // If R is less than 1600, output 3 for Division 3.
        }
    }

    return 0; // Indicate successful program execution.
}