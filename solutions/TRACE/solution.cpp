#include <bits/stdc++.h> // Includes all standard libraries

// Using namespace std; as requested by critical instructions
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A[i][j];
        }
    }

    long long max_trace = 0; // A_ij >= 1, so trace will be positive. Initialize to 0 is safe.
                             // Max trace for N=100, A_ij=100 is 100*100 = 10000, which fits in int.
                             // Using long long is a safe general practice, though not strictly necessary here.

    // Iterate over all possible top-left corners (r, c) of a submatrix
    // r and c are 0-indexed row and column.
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            // For each (r, c), consider all possible square submatrices
            // that start at (r, c).
            // A submatrix of size l x l starting at (r, c) has diagonal elements:
            // A[r][c], A[r+1][c+1], ..., A[r+l-1][c+l-1]
            
            long long current_sum = 0;
            // Iterate through possible lengths 'l' for submatrices starting at (r,c).
            // 'k' represents the offset from (r,c) along the diagonal.
            // So, l = k+1.
            // The diagonal elements are A[r+k][c+k].
            // The loop continues as long as r+k and c+k are within matrix bounds.
            for (int k = 0; r + k < N && c + k < N; ++k) {
                current_sum += A[r+k][c+k];
                // After adding A[r+k][c+k], current_sum is the trace of a (k+1)x(k+1) submatrix
                // starting at (r,c). Update max_trace if this is larger.
                max_trace = max(max_trace, current_sum);
            }
        }
    }
    
    cout << max_trace << "\n";
}

int main() {
    // Fast I/O as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}