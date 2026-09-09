#include <bits/stdc++.h> // Includes all standard libraries

// Using the standard namespace to avoid writing std::
using namespace std;

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
        int X, Y; // Declare integer variables X and Y to store the prize amounts.
        cin >> X >> Y; // Read X and Y for the current test case.

        // Calculate the total prize money.
        // Top 10 participants receive X rupees each. Total for this group: 10 * X.
        // Participants with rank 11 to 100 (which are 100 - 11 + 1 = 90 participants)
        // receive Y rupees each. Total for this group: 90 * Y.
        // The total prize money is the sum of these two amounts.
        // Since X and Y are at most 1000, the maximum total prize money is
        // (10 * 1000) + (90 * 1000) = 10000 + 90000 = 100000.
        // This value fits comfortably within a standard 'int' type.
        int total_prize_money = (10 * X) + (90 * Y);

        // Output the calculated total prize money for the current test case,
        // followed by a newline character as required.
        cout << total_prize_money << "\n";
    }

    return 0; // Indicate successful program execution.
}