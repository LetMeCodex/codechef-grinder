#include <bits/stdc++.h> // Required header for competitive programming

using namespace std; // Required namespace

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Declare an integer variable 't' to store the number of test cases.
    cin >> t; // Read the number of test cases from standard input.

    // Loop 't' times, once for each test case.
    while (t--) {
        int x, y; // Declare integer variables 'x' and 'y' for the number of coins.
        // 'x' will store the count of 10-rupee coins.
        // 'y' will store the count of 5-rupee coins.
        cin >> x >> y; // Read 'x' and 'y' for the current test case.

        // Calculate the total money Janmansh has.
        // Each 10-rupee coin contributes 10 * x rupees.
        // Each 5-rupee coin contributes 5 * y rupees.
        // The sum of these two amounts is the total money.
        int total_money = (x * 10) + (y * 5);

        // Print the calculated total money to standard output, followed by a newline character.
        // The newline character ensures that each test case's output is on a separate line.
        cout << total_money << "\n";
    }

    return 0; // Indicate successful program execution.
}