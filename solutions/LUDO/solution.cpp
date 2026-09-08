#include <bits/stdc++.h> // Includes all standard libraries

// Using the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases
    cin >> T; // Read the number of test cases

    // Loop T times, once for each test case
    while (T--) {
        int X; // Declare an integer variable X for the number rolled on the die
        cin >> X; // Read the number rolled by Chef

        // Check if the rolled number X is 6
        if (X == 6) {
            // If X is 6, Chef can enter a new token
            cout << "YES\n"; // Print "YES" followed by a newline
        } else {
            // If X is not 6, Chef cannot enter a new token
            cout << "NO\n"; // Print "NO" followed by a newline
        }
    }

    return 0; // Indicate successful program execution
}