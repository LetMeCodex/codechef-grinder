#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace to avoid prefixing standard library elements with std::
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can prevent synchronization overhead.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // further speeding up I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare an integer variable 'S' to store Alice's maximum speed.
    int S;

    // Read the maximum speed 'S' from standard input.
    cin >> S;

    // According to the problem rules, Alice is fined if her speed
    // "exceeds 40 km/hr". This means if S is strictly greater than 40.
    if (S > 40) {
        // If Alice's speed is greater than 40, she will be fined.
        // Print "YES" followed by a newline character.
        cout << "YES\n";
    } else {
        // If Alice's speed is not greater than 40 (i.e., S is 40 or less),
        // she will not be fined.
        // Print "NO" followed by a newline character.
        cout << "NO\n";
    }

    // Return 0 to indicate successful execution of the program.
    return 0;
}