#include <bits/stdc++.h> 
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from the C standard I/O library and
    // prevents flushing cout before cin, speeding up I/O operations.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times, once for each test case
        int X, Y;
        cin >> X >> Y; // Read Chef's daily goal (X) and chocolates sold (Y)

        int total_amount;

        // Case 1: Chef sells Y chocolates, which is less than or equal to the goal X.
        // In this scenario, Chef gets 1 rupee for each chocolate sold.
        if (Y <= X) {
            total_amount = Y * 1; // Total amount is simply Y rupees.
        } 
        // Case 2: Chef sells Y chocolates, which is more than the goal X.
        // In this scenario, Chef gets 1 rupee for the first X chocolates (meeting the goal)
        // and 2 rupees for each extra chocolate sold beyond X.
        else {
            // Amount for the first X chocolates (goal achieved): X * 1 rupees
            // Amount for the extra (Y - X) chocolates: (Y - X) * 2 rupees
            total_amount = X * 1 + (Y - X) * 2;
        }

        // Output the calculated total amount for the current test case, followed by a newline.
        cout << total_amount << "\n";
    }

    return 0; // Indicate successful execution
}