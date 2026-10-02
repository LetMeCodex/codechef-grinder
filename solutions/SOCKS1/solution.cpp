#include <bits/stdc++.h> // Includes common C++ headers like iostream, vector, algorithm, etc.

using namespace std; // Allows using standard library components without the std:: prefix

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // potentially speeding up I/O operations.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // further speeding up I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B, C; // Declare three integer variables to store the colors of the socks
    
    // Read the three space-separated integers A, B, and C from standard input
    cin >> A >> B >> C;

    // Check if any two socks have the same color.
    // This can be done by comparing A with B, A with C, and B with C.
    // If any of these comparisons are true, it means Chef can form a pair.
    if (A == B || A == C || B == C) {
        // If a pair can be formed, print "YES" followed by a newline character.
        cout << "YES\n";
    } else {
        // If no two socks have the same color, print "NO" followed by a newline character.
        cout << "NO\n";
    }

    return 0; // Indicate successful program execution
}