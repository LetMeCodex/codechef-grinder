#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace to avoid prefixing std::
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from the C standard streams and disables synchronization,
    // making I/O operations faster.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare two integer variables to store the convincing powers.
    // X for prosecution, Y for defense.
    int X, Y;

    // Read the two integers from standard input.
    cin >> X >> Y;

    // According to the problem statement, the accused will be convicted if
    // the convincing power of the prosecution (X) is greater than or equal to
    // the convincing power of the defense (Y).
    if (X >= Y) {
        // If the condition is met, print "YES".
        // Use "\n" for a newline character, which is generally faster than endl.
        cout << "YES\n";
    } else {
        // Otherwise (if X < Y), print "NO".
        cout << "NO\n";
    }

    // The main function should return 0 to indicate successful execution.
    return 0;
}