#include <bits/stdc++.h>

using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // allowing them to operate independently and often faster.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // which can further speed up I/O in interactive problems or those with mixed I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare an integer variable 'X' to store the measured AQI.
    int X;

    // Read the AQI value from standard input.
    cin >> X;

    // The government's goal is to keep the average AQI strictly below 100.
    // This means if X is less than 100, the limit is met.
    // If X is 100 or greater, the limit is not met.
    if (X < 100) {
        // If X is strictly less than 100, print "YES".
        cout << "YES\n";
    } else {
        // Otherwise (if X is 100 or greater), print "NO".
        cout << "NO\n";
    }

    // Return 0 to indicate successful program execution.
    return 0;
}