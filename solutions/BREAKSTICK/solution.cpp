#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace to avoid std:: prefix
using namespace std;

void solve() {
    long long N, X;
    cin >> N >> X;

    // Apply the consolidated logic:
    // If X is odd, we can always obtain it.
    // If X is even, we can only obtain it if N is also even.
    if (X % 2 == 1) { // X is odd
        cout << "YES\n";
    } else { // X is even
        if (N % 2 == 1) { // N is odd
            cout << "NO\n";
        } else { // N is even
            cout << "YES\n";
        }
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the function to solve the current test case
    }

    return 0;
}