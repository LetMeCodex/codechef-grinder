#include <bits/stdc++.h> // Includes iostream, vector, numeric, algorithm, etc.

// Using namespace std; is requested
using namespace std;

void solve() {
    int n;
    cin >> n; // Read N

    // Permutation A: [1, 2, ..., N]
    for (int i = 1; i <= n; ++i) {
        cout << i << (i == n ? "" : " "); // Print space-separated, no trailing space for last element
    }
    cout << "\n"; // Newline after permutation A

    // Permutation B: [k+1, k+2, ..., N, 1, 2, ..., k] where k = floor(N/2)
    // This construction achieves the maximum possible distance floor(N/2).
    int k = n / 2; // Integer division correctly computes floor(N/2)

    // Print elements from k+1 to N
    for (int i = k + 1; i <= n; ++i) {
        cout << i << " ";
    }
    // Print elements from 1 to k
    // This loop handles the last element printing without a trailing space
    for (int i = 1; i <= k; ++i) {
        cout << i << (i == k ? "" : " "); // Print space-separated, no trailing space for last element
    }
    cout << "\n"; // Newline after permutation B
}

int main() {
    // Fast I/O inside main() as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) { // Loop through each test case
        solve();
    }

    return 0;
}