#include <bits/stdc++.h> // Includes most standard libraries

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases
    cin >> T; // Read the number of test cases

    // Loop T times, once for each test case
    while (T--) {
        int X, Y; // Declare integer variables X and Y for total money and daily expenditure
        cin >> X >> Y; // Read X and Y for the current test case

        // Calculate the total money required for 30 days.
        // The problem states the month has 30 days.
        // Daily expenditure is Y, so total expenditure = Y * 30.
        int total_expenditure_required = Y * 30;

        // Check if Akshat has enough money (X) to cover the total expenditure.
        // If X is greater than or equal to total_expenditure_required, he has enough.
        if (X >= total_expenditure_required) {
            cout << "YES\n"; // Output "YES" followed by a newline
        } else {
            cout << "NO\n"; // Output "NO" followed by a newline
        }
    }

    return 0; // Indicate successful execution of the program
}