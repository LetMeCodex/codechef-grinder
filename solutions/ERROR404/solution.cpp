#include <bits/stdc++.h>

using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare an integer variable X to store the response code.
    int X;

    // Read the response code from standard input.
    cin >> X;

    // Check if the response code is 404.
    if (X == 404) {
        // If X is 404, print "NOT FOUND" followed by a newline.
        cout << "NOT FOUND\n";
    } else {
        // For any other response code, print "FOUND" followed by a newline.
        cout << "FOUND\n";
    }

    // Return 0 to indicate successful execution of the program.
    return 0;
}