#include <bits/stdc++.h> // Includes most standard libraries

using namespace std; // Allows using standard library elements without the std:: prefix

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int X, Y; // Declare two integer variables X and Y for Chef's and Chefina's income.
        cin >> X >> Y; // Read X and Y for the current test case.

        // The problem states that Chefina earns Y rupees and Chef earns X rupees, with Y > X.
        // To end up with exactly the same amount, they donate the difference between their income.
        // The difference is Y - X. If Chefina donates this amount, she will have Y - (Y - X) = X rupees,
        // which is the same as Chef's income.
        int donation_amount = Y - X;

        // Output the calculated donation amount, followed by a newline character.
        cout << donation_amount << "\n";
    }

    return 0; // Indicate successful program execution.
}