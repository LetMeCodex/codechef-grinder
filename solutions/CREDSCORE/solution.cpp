#include <bits/stdc++.h> // Include all standard libraries

using namespace std; // Use the standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X; // Declare an integer variable X to store the credit score.
    
    // Read the credit score X from standard input.
    cin >> X;

    // Check if the credit score X is 750 or more.
    // According to the problem statement, a score of 750 or more is required
    // to access CRED programs.
    if (X >= 750) {
        // If the condition is met, print "YES" followed by a newline.
        cout << "YES\n";
    } else {
        // Otherwise (if X is less than 750), print "NO" followed by a newline.
        cout << "NO\n";
    }

    return 0; // Indicate successful program execution.
}