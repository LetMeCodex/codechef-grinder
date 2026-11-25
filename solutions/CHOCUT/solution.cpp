#include <bits/stdc++.h> // Includes iostream, algorithm, etc.

// Using namespace std; as requested
using namespace std;

void solve() {
    int N, M, K;
    cin >> N >> M >> K; // Read N, M, K for the current test case

    int max_alice_squares = 0; // Initialize maximum squares Alice can keep

    // Option 1: Alice makes no cut and keeps the entire bar.
    // This is only possible if Bob is happy receiving 0 squares (i.e., K <= 0).
    if (0 >= K) {
        max_alice_squares = max(max_alice_squares, N * M);
    }

    // Option 2: Alice makes a horizontal cut.
    // A horizontal cut divides the N rows into two parts: 'r' rows and 'N-r' rows.
    // 'r' must be between 1 and N-1 to create two distinct pieces.
    for (int r = 1; r < N; ++r) {
        int size1 = r * M;         // Squares in the first piece (r x M)
        int size2 = (N - r) * M;   // Squares in the second piece ((N-r) x M)

        // If the first piece (size1) is large enough for Bob, Alice can give it to Bob
        // and keep the second piece (size2).
        if (size1 >= K) {
            max_alice_squares = max(max_alice_squares, size2);
        }
        // If the second piece (size2) is large enough for Bob, Alice can give it to Bob
        // and keep the first piece (size1).
        if (size2 >= K) {
            max_alice_squares = max(max_alice_squares, size1);
        }
    }

    // Option 3: Alice makes a vertical cut.
    // A vertical cut divides the M columns into two parts: 'c' columns and 'M-c' columns.
    // 'c' must be between 1 and M-1 to create two distinct pieces.
    for (int c = 1; c < M; ++c) {
        int size1 = N * c;         // Squares in the first piece (N x c)
        int size2 = N * (M - c);   // Squares in the second piece (N x (M-c))

        // If the first piece (size1) is large enough for Bob, Alice can give it to Bob
        // and keep the second piece (size2).
        if (size1 >= K) {
            max_alice_squares = max(max_alice_squares, size2);
        }
        // If the second piece (size2) is large enough for Bob, Alice can give it to Bob
        // and keep the first piece (size1).
        if (size2 >= K) {
            max_alice_squares = max(max_alice_squares, size1);
        }
    }

    // Output the maximum number of squares Alice can keep.
    cout << max_alice_squares << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}