#include <bits/stdc++.h> // Includes most standard libraries

// Use the standard namespace to avoid prefixing std::
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare an integer variable X to store Alice's height.
    int X;

    // Read Alice's height from standard input.
    cin >> X;

    // Check if Alice's height is greater than or equal to the minimum required height (60 cm).
    if (X >= 60) {
        // If Alice's height is sufficient, print "Yes".
        cout << "Yes\n";
    } else {
        // Otherwise (if Alice's height is less than 60 cm), print "No".
        cout << "No\n";
    }

    // The program finishes successfully.
    return 0;
}