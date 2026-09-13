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
        int x; // Declare an integer variable x to store the discount percentage.
        cin >> x; // Read the discount percentage for the current test case.

        // The original price of the toy is 100 rupees.
        // A discount of x percent means a discount of x rupees (since 100 * x/100 = x).
        // The amount Alice needs to pay is the original price minus the discount amount.
        int amount_to_pay = 100 - x;

        // Output the calculated amount Alice needs to pay, followed by a newline character.
        cout << amount_to_pay << "\n";
    }

    return 0; // Indicate successful program execution.
}