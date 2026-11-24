#include <bits/stdc++.h> // Includes iostream and many other useful headers

using namespace std; // As requested by the problem statement

void solve() {
    long long A, B; // A, B can be up to 10^9, so long long is used for safety.
    cin >> A >> B; // Read A and B

    if (A == 0) {
        // Case 1: A = 0. Impossible, as any positive integer has at least one odd divisor (1).
        cout << "No\n";
    } else { // A > 0
        // Case 2: A > 0. An odd integer M with A divisors can always be constructed.
        if (B == 0) {
            // Subcase 2.1: B = 0. This means N must be an odd number (k=0).
            // All its divisors are odd, and it has no even divisors. This is possible.
            cout << "Yes\n";
        } else { // B > 0
            // Subcase 2.2: B > 0. We need B = k * A for some positive integer k.
            // This implies B must be perfectly divisible by A.
            if (B % A == 0) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T;
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}