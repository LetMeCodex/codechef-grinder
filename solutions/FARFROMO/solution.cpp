#include <bits/stdc++.h> 

// Use the standard namespace to avoid prefixing standard library elements with std::
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times, decrementing T in each iteration
        int X1, Y1, X2, Y2;
        // Read the coordinates for Alex (X1, Y1) and Bob (X2, Y2)
        cin >> X1 >> Y1 >> X2 >> Y2; 

        // Calculate Alex's squared distance from the origin (0,0).
        // Using (long long) for type casting before multiplication to ensure
        // the product is computed as a long long, preventing potential overflow
        // if intermediate squares were larger than int max.
        // For this problem's constraints (-1000 to 1000), int would be sufficient,
        // but long long is a safer general practice.
        long long dist_sq_alex = (long long)X1 * X1 + (long long)Y1 * Y1;

        // Calculate Bob's squared distance from the origin (0,0).
        long long dist_sq_bob = (long long)X2 * X2 + (long long)Y2 * Y2;

        // Compare the squared distances to determine who is farther or if they are equal.
        if (dist_sq_alex > dist_sq_bob) {
            cout << "ALEX\n"; // Alex is farther
        } else if (dist_sq_bob > dist_sq_alex) {
            cout << "BOB\n";  // Bob is farther
        } else {
            cout << "EQUAL\n"; // Both are at the same distance
        }
    }

    return 0; // Indicate successful program execution
}