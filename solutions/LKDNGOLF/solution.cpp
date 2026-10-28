#include <bits/stdc++.h> // Includes common standard libraries like iostream

// Using the standard namespace to avoid prefixing std::
using namespace std; 

int main() {
    // Optimize C++ standard streams for faster input/output.
    // Unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        long long N, x, k; // Declare N, x, k as long long to handle values up to 10^9 safely
        cin >> N >> x >> k; // Read N, x, and k for the current test case

        bool found = false; // Flag to track if the hole is found

        // Check for the forward journey:
        // The ball starts at tile 0 and lands on tiles 0, k, 2k, ...
        // If x is a multiple of k, the ball lands on tile x.
        if (x % k == 0) {
            found = true;
        }

        // If the hole was not found in the forward journey, check the backward journey.
        // The ball starts at tile N+1 and lands on tiles (N+1), (N+1-k), (N+1-2k), ...
        // If (N+1 - x) is a multiple of k, the ball lands on tile x.
        // (N+1 - x) represents the distance from N+1 to x, which must be a multiple of k.
        if (!found) { 
            if ((N + 1 - x) % k == 0) {
                found = true;
            }
        }

        // Output "YES" if the hole was found in either journey, otherwise "NO".
        if (found) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0; // Indicate successful execution
}