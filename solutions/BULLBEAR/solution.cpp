#include <bits/stdc++.h> // Includes most standard libraries

// Use the standard namespace to avoid prefixing std::
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // potentially speeding up I/O operations.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // which can further speed up I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int X, Y; // Declare two integer variables X and Y for buying and selling prices.
        cin >> X >> Y; // Read X and Y for the current test case.

        // Compare X and Y to determine profit, loss, or neutral deal.
        if (Y > X) {
            // If selling price (Y) is greater than buying price (X), it's a profit.
            cout << "PROFIT\n";
        } else if (Y < X) {
            // If selling price (Y) is less than buying price (X), it's a loss.
            cout << "LOSS\n";
        } else {
            // If selling price (Y) is equal to buying price (X), it's a neutral deal.
            cout << "NEUTRAL\n";
        }
    }

    return 0; // Indicate successful execution of the program.
}