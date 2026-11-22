#include <bits/stdc++.h> // Includes all standard libraries

// Using namespace std; is requested by the problem statement.
using namespace std;

void solve() {
    long long x, y; // Using long long for x, y to safely handle inputs up to 10^9.
    cin >> x >> y;

    // A point (x, y) is reachable from (0, 0) if and only if
    // x and y have the same parity.
    // This condition is equivalent to (x + y) being an even number.
    // For example:
    // If x is even, y is even -> x+y is even.
    // If x is odd, y is odd -> x+y is even.
    // If x is even, y is odd -> x+y is odd.
    // If x is odd, y is even -> x+y is odd.
    // The modulo operator (%) works correctly with negative numbers in C++ for parity checks.
    // E.g., (-4) % 2 == 0, (-3) % 2 == -1.
    if ((x + y) % 2 == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Fast I/O setup as requested for competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of testcases
    while (t--) { // Loop through each testcase
        solve(); // Call the solve function for each testcase
    }

    return 0;
}