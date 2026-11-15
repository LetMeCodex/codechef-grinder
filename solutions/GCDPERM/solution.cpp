#include <bits/stdc++.h> // Includes common C++ libraries, as requested

// Use the standard namespace, as requested
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    // Calculate the maximum possible GCD.
    // As derived, this is floor(N/K). Integer division in C++
    // automatically computes the floor for positive numbers.
    int max_gcd = n / k;

    // Print the K-sized subset. The simplest subset with GCD 'max_gcd'
    // is {max_gcd, 2*max_gcd, ..., K*max_gcd}.
    // All these numbers are <= N because K * max_gcd <= K * (N/K) = N.
    for (int i = 1; i <= k; ++i) {
        cout << i * max_gcd << (i == k ? "" : " ");
    }
    cout << "\n"; // Newline after each test case output
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Number of test cases
    cin >> t;
    while (t--) {
        solve(); // Solve each test case
    }

    return 0;
}