#include <bits/stdc++.h> // Include all standard libraries

using namespace std; // Use the standard namespace

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X; // Declare an integer variable X to store Chef's current IQ.
    cin >> X; // Read Chef's current IQ from standard input.

    // Calculate Chef's IQ after learning a musical instrument.
    // The problem states that playing an instrument increases IQ by 7 points.
    int final_iq = X + 7;

    // Determine if Chef's final IQ is strictly greater than Einstein's IQ (170).
    if (final_iq > 170) {
        // If Chef's final IQ is strictly greater than 170, print "Yes".
        cout << "Yes\n";
    } else {
        // Otherwise, print "No".
        cout << "No\n";
    }

    return 0; // Indicate successful execution of the program.
}