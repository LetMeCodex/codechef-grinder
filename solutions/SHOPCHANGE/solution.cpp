#include <bits/stdc++.h> // Include all standard libraries

using namespace std; // Use standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cout from flushing before cin reads input.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Declare an integer variable 't' to store the number of test cases.
    cin >> t; // Read the number of test cases from standard input.

    // Loop 't' times, once for each test case.
    // The 't--' decrements 't' after each iteration until it becomes 0.
    while (t--) {
        int x; // Declare an integer variable 'x' to store the price of items.
        cin >> x; // Read the price of items for the current test case.

        // Calculate the change Chef should receive.
        // Chef pays with 100 rupees, and items cost 'x' rupees.
        // The change is simply 100 - x.
        int change = 100 - x;

        // Print the calculated change followed by a newline character.
        // The problem requires output for each test case on a new line.
        cout << change << "\n";
    }

    return 0; // Indicate successful program execution.
}