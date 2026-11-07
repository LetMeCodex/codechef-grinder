#include <bits/stdc++.h> // Required header for standard library utilities

using namespace std; // Use the standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; // Declare an integer variable N to store the bus number.

    // Read the bus number N from standard input.
    cin >> N;

    // Check if N is divisible by 5 OR if N is divisible by 6.
    // The modulo operator (%) returns the remainder of a division.
    // If N % 5 == 0, N is divisible by 5.
    // If N % 6 == 0, N is divisible by 6.
    // The '||' (logical OR) operator means the condition is true if at least one of the sub-conditions is true.
    if (N % 5 == 0 || N % 6 == 0) {
        // If N satisfies the condition, print "YES" followed by a newline.
        cout << "YES\n";
    } else {
        // If N does not satisfy the condition, print "NO" followed by a newline.
        cout << "NO\n";
    }

    return 0; // Indicate successful program execution.
}