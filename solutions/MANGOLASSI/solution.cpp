#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare an integer variable X to store today's temperature.
    int X;

    // Read the temperature X from standard input.
    cin >> X;

    // Check the condition: Mamalesh drinks mango lassi if the temperature
    // is strictly greater than 35 degrees Celsius.
    if (X > 35) {
        // If the condition is true, print "YES" followed by a newline.
        cout << "YES\n";
    } else {
        // Otherwise (if X is 35 or less), print "NO" followed by a newline.
        cout << "NO\n";
    }

    // Return 0 to indicate successful execution of the program.
    return 0;
}