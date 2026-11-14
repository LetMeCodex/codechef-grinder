#include <bits/stdc++.h> // Required header

using namespace std; // Required

void solve() {
    int N, M;
    cin >> N >> M; // Read N and M for the current test case

    // Iterate through rows (0-indexed)
    for (int i = 0; i < N; ++i) {
        // Iterate through columns (0-indexed)
        for (int j = 0; j < M; ++j) {
            // Calculate the element A_ij using the formula: i + j + M + 2
            // This formula ensures:
            // 1. All elements are >= 2 (min value is M+2, which is >= 4 since M >= 2).
            // 2. All elements are <= 10^9 (max value is N+2M, which is approx 9*10^5).
            // 3. Each row contains M consecutive integers, so its GCD is 1.
            //    (e.g., for row i: (i+M+2), (i+M+3), ..., (i+M+2+M-1))
            // 4. Each column contains N consecutive integers, so its GCD is 1.
            //    (e.g., for col j: (j+M+2), (j+M+3), ..., (j+M+2+N-1))
            cout << (i + j + M + 2);

            // Print a space after the element if it's not the last one in the row
            if (j < M - 1) {
                cout << " ";
            }
        }
        // Print a newline character after each row
        cout << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    // Process each test case
    while (T--) {
        solve();
    }

    return 0;
}