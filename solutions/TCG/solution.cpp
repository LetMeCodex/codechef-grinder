#include <bits/stdc++.h> // Includes all standard libraries

using namespace std; // Allows using standard library elements without std:: prefix

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from C's stdio and prevents flushing cout before cin.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem statement's "Input Format" section specifies:
    // "The first and only line of input consists of two space-separated integers X and Y"
    // This indicates that there is a single test case, not multiple test cases
    // introduced by a 't' variable.

    int X, Y; // Declare two integer variables for the previous and new tax values
    cin >> X >> Y; // Read the two integers from standard input

    // Compare X and Y to determine the change in capital gain tax.
    // The constraints 10 <= X, Y <= 30 mean that 'int' is sufficient
    // to store these values without any risk of overflow.

    if (Y > X) {
        // If the new tax value (Y) is strictly greater than the previous tax value (X),
        // the capital gain tax has increased.
        cout << "INCREASED\n";
    } else if (Y < X) {
        // If the new tax value (Y) is strictly less than the previous tax value (X),
        // the capital gain tax has decreased.
        cout << "DECREASED\n";
    } else {
        // If the new tax value (Y) is equal to the previous tax value (X),
        // the capital gain tax has remained the same.
        cout << "SAME\n";
    }

    return 0; // Indicate successful execution of the program
}