#include <bits/stdc++.h> // Includes iostream, algorithm, etc.
using namespace std;

void solve() {
    int N, X, K, P;
    cin >> N >> X >> K >> P;

    long long current_mana = P; // Initialize with initial mana level

    // Calculate mana from bells that provide +10.
    // These are the first X bells, but we only count up to K bells rung.
    // So, the number of such bells is the minimum of K (bells rung so far) and X (bells that give +10).
    int bells_10_count = min(K, X);
    current_mana += (long long)bells_10_count * 10;

    // Calculate mana from bells that provide +5.
    // These are bells rung after the first X bells, up to K bells.
    // The number of such bells is the total bells rung (K) minus the bells that already provided +10.
    // If K <= X, then bells_10_count will be K, and bells_5_count will be K - K = 0, which is correct.
    int bells_5_count = K - bells_10_count;
    current_mana += (long long)bells_5_count * 5;

    // Add the bonus mana if all N bells have been rung.
    if (K == N) {
        current_mana += 20;
    }

    cout << current_mana << "\n"; // Output the final current mana level
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times to solve each test case
        solve();
    }

    return 0;
}