#include <bits/stdc++.h> // Includes common headers like iostream

// Use the standard namespace as requested
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare two integer variables to store the prices of the plastic and metal frames.
    int X, Y;

    // Read the two prices from the standard input.
    // As per the problem description, there is only one line of input with X and Y.
    cin >> X >> Y;

    // Apply Chef's decision rule:
    // Chef buys the metal frame if its cost (Y) is at most twice the plastic frame's cost (X).
    // This translates to the condition: Y <= 2 * X.
    if (Y <= 2 * X) {
        // If the condition is true, Chef buys the metal frame.
        // Output "METAL" followed by a newline character.
        cout << "METAL\n";
    } else {
        // If the condition is false (i.e., Y > 2 * X), Chef buys the plastic frame.
        // Output "PLASTIC" followed by a newline character.
        cout << "PLASTIC\n";
    }

    // Indicate successful program execution.
    return 0;
}