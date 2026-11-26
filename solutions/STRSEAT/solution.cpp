#include <bits/stdc++.h> // Includes iostream, vector, numeric, etc.

// Using namespace std; is requested by the problem statement.
using namespace std;

void solve() {
    int N;
    long long K; // K can be up to 10000. Max fans is 5100. int is sufficient for K, but long long is safer for sums.
    cin >> N >> K;

    vector<int> A(N);
    long long sum_A_half = 0; // Stores sum of A_i / 2 for all i. Max 100 * (100/2) = 5000. int is sufficient.
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        sum_A_half += A[i] / 2;
    }

    int count_over_K = 0; // Counts matches with strictly more than K fans. Max N*(N-1)/2 = 4950. int is sufficient.
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) { // Iterate through unique pairs (i, j) where i < j
            // Calculate fans attending for a match between team i and team j
            // Formula: sum_A_half + A[i]/2 + A[j]/2
            long long current_match_fans = sum_A_half + (A[i] / 2) + (A[j] / 2); // Max 5000 + 50 + 50 = 5100. int is sufficient.
            
            // Check if the number of fans exceeds stadium capacity K
            if (current_match_fans > K) {
                count_over_K++;
            }
        }
    }
    cout << count_over_K << "\n";
}

int main() {
    // Fast I/O setup as requested by the problem statement.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve();
    }
    return 0;
}