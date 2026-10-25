#include <bits/stdc++.h> // Include all standard libraries

using namespace std; // Use the standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Declare an integer variable 't' to store the number of test cases.
    cin >> t; // Read the number of test cases from standard input.

    // Loop 't' times, once for each test case.
    // The 't--' decrements 't' after each iteration until it becomes 0.
    while (t--) {
        int x; // Declare an integer variable 'x' to store the value on the top face.
        cin >> x; // Read the value on the top face for the current test case.

        // According to the problem statement, in a regular dice,
        // the sum of opposite faces is 7.
        // If 'x' is the value on the top face, and 'bottom_face' is the value
        // on the bottom face, then x + bottom_face = 7.
        // Therefore, bottom_face = 7 - x.
        int bottom_face = 7 - x;

        // Print the calculated value of the bottom face, followed by a newline character.
        // Using "\n" is generally faster than endl because endl also flushes the buffer.
        cout << bottom_face << "\n";
    }

    return 0; // Indicate that the program executed successfully.
}