#include <bits/stdc++.h> // Includes iostream and other standard libraries

// Use the standard namespace as requested
using namespace std;

void solve() {
    int N;
    cin >> N; // Read initial position N

    // Apply the derived formulas based on N's parity
    if (N == 1) {
        // Special case for N=1: The person is at position 1 initially
        // and gets tickets in the first second.
        cout << 1 << "\n";
    } else if (N % 2 == 1) { // N is odd and N >= 3
        // For odd N (N >= 3), the person's position effectively decreases by 2 each second
        // until it reaches position 3.
        // Example: N=5 -> pos 5 (sec 0) -> pos 3 (sec 1). Gets ticket at sec 2. Total 2 seconds.
        // The number of seconds is (N-1)/2.
        // Integer division N/2 correctly computes (N-1)/2 for odd N.
        cout << N / 2 << "\n";
    } else { // N is even
        // For even N, the person's position effectively decreases by 2 each second
        // until it reaches position 2. Then it moves to position 1, then gets ticket.
        // Example: N=4 -> pos 4 (sec 0) -> pos 2 (sec 1) -> pos 1 (sec 2). Gets ticket at sec 3. Total 3 seconds.
        // The number of seconds is N/2 + 1.
        cout << N / 2 + 1 << "\n";
    }
}

int main() {
    // Enable fast I/O as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}