#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare two integer variables to store the temperatures.
    // X will store the highest recorded temperature.
    // Y will store the temperature on the given day.
    int X, Y;

    // Read the two temperatures from standard input.
    cin >> X >> Y;

    // Check if the temperature on the given day (Y) is strictly greater
    // than the highest recorded temperature (X).
    // If Y is greater than X, it means a new record high was created.
    if (Y > X) {
        // If a new record high was created, print "YES".
        cout << "YES\n";
    } else {
        // Otherwise (if Y is less than or equal to X), it means a new record high
        // was NOT created.
        // In this case, print "NO".
        cout << "NO\n";
    }

    // The program finishes successfully.
    return 0;
}