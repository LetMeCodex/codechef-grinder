#include <bits/stdc++.h> // Includes iostream, vector, algorithm, etc.

// Using namespace std; as requested by problem statement
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Calculate cost for pattern 1: Odd, Even, Odd, Even, ...
    // Target parities: 1, 0, 1, 0, ...
    // For index i:
    // If i is even (i % 2 == 0), A[i] should be Odd (parity 1).
    // If i is odd (i % 2 == 1), A[i] should be Even (parity 0).
    int cost1 = 0;
    for (int i = 0; i < N; ++i) {
        int current_parity = A[i] % 2;
        int required_parity_for_pattern1 = (i % 2 == 0) ? 1 : 0; 
        
        if (current_parity != required_parity_for_pattern1) {
            cost1++;
        }
    }

    // Calculate cost for pattern 2: Even, Odd, Even, Odd, ...
    // Target parities: 0, 1, 0, 1, ...
    // For index i:
    // If i is even (i % 2 == 0), A[i] should be Even (parity 0).
    // If i is odd (i % 2 == 1), A[i] should be Odd (parity 1).
    int cost2 = 0;
    for (int i = 0; i < N; ++i) {
        int current_parity = A[i] % 2;
        int required_parity_for_pattern2 = (i % 2 == 0) ? 0 : 1; 
        
        if (current_parity != required_parity_for_pattern2) {
            cost2++;
        }
    }

    // The minimum changes needed is the minimum of the two costs
    cout << min(cost1, cost2) << "\n";
}

int main() {
    // Fast I/O as requested by problem statement
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}