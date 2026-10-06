#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // potentially speeding up I/O operations.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // which can also speed up I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare variables N, H, and x as per problem statement.
    // N: number of time zones
    // H: hours needed to solve the problem
    // x: hours currently remaining
    int N, H, x;

    // Read the values of N, H, and x from standard input.
    cin >> N >> H >> x;

    // Initialize a boolean flag to track if Chef can solve the problem.
    // It's initially false, assuming he cannot solve it until a suitable time zone is found.
    bool can_solve = false;

    // Loop N times to read each time zone value T_i.
    for (int i = 0; i < N; ++i) {
        int T_i; // Declare variable for the current time zone's hours behind.
        cin >> T_i; // Read T_i from standard input.

        // Calculate the total time Chef would have if he uses this time zone.
        // This is his current remaining time (x) plus the time gained from traveling back (T_i).
        // Check if this total time is sufficient to solve the problem (i.e., >= H).
        if (x + T_i >= H) {
            can_solve = true; // If sufficient, set the flag to true.
            // Since we only need to find *one* suitable time zone,
            // we can break out of the loop as soon as we find one.
            break;
        }
    }

    // After checking all time zones (or breaking early),
    // print "YES" if can_solve is true, otherwise print "NO".
    if (can_solve) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    // Return 0 to indicate successful execution.
    return 0;
}