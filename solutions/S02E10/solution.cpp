#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/**
 * Problem Analysis:
 * We need to count indices j such that |A[j] - B[j]| <= K.
 * If the count >= X, output "YES", else "NO".
 * 
 * Complexity:
 * Time: O(T * N) = 10 * 1000 = 10^4 operations.
 * Space: O(N) = 1000 integers.
 * This is highly efficient and should pass well within the time limits.
 */

void solve() {
    int N, X, K;
    if (!(cin >> N >> X >> K)) return;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    int count = 0;
    for (int i = 0; i < N; ++i) {
        int b_val;
        cin >> b_val;
        // Calculate absolute difference on the fly to save memory/time
        if (abs(A[i] - b_val) <= K) {
            count++;
        }
    }

    if (count >= X) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Optimization for faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}