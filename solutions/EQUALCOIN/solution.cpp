#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

// Function to solve a single test case
void solve() {
    int X, Y;
    cin >> X >> Y; // Read X (1-rupee coins) and Y (2-rupee coins)

    // The condition for a "YES" answer is:
    // (X is even) AND (Y is even OR X > 0)
    //
    // Explanation:
    // 1. Total value (X + 2Y) must be even for equal distribution.
    //    Since 2Y is always even, (X + 2Y) is even if and only if X is even.
    //    If X is odd, the total value is odd, so it's impossible. Output "NO".
    //
    // 2. If X is even:
    //    Each son needs (X + 2Y) / 2 = X/2 + Y rupees.
    //    a. If X = 0:
    //       Chef only has 2-rupee coins. Each son needs Y rupees.
    //       To form Y rupees using only 2-rupee coins, Y must be even.
    //       If Y is odd (e.g., X=0, Y=1), it's impossible. Output "NO".
    //       If Y is even (e.g., X=0, Y=2), it's possible. Output "YES".
    //    b. If X > 0 (and X is even, so X >= 2):
    //       Chef has at least two 1-rupee coins. This provides enough flexibility
    //       to adjust the parity of the sum for each son. It can be shown that
    //       it's always possible to distribute the coins equally in this scenario.
    //       Output "YES".
    //
    // Combining these:
    // Output "NO" if (X is odd) OR (X is 0 AND Y is odd).
    // Otherwise, output "YES".
    // This is equivalent to:
    // Output "YES" if (X is even) AND (Y is even OR X > 0).

    if (X % 2 == 0) { // X is even
        if (Y % 2 == 0 || X > 0) { // Y is even OR X > 0
            cout << "YES\n";
        } else { // This specific case is X=0 and Y is odd
            cout << "NO\n";
        }
    } else { // X is odd
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}