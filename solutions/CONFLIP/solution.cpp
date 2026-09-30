#include <bits/stdc++.h> // Required by problem statement

// Using namespace std; as requested by problem statement
using namespace std;

void solve() {
    int G;
    cin >> G; // Read the number of games
    while (G--) {
        long long I, N, Q; // N can be up to 10^9, fits in int. Using long long for N, I, Q just to be absolutely safe, though int is sufficient for all.
        cin >> I >> N >> Q; // Read initial state, number of coins/rounds, and query type

        if (N % 2 == 0) {
            // If N is an even number:
            // There are N/2 coins that are flipped an odd number of times (ending in opposite state)
            // and N/2 coins that are flipped an even number of times (ending in initial state).
            // This means there will always be N/2 Heads and N/2 Tails, regardless of the initial state (I)
            // or the specific face being queried (Q).
            cout << N / 2 << "\n";
        } else {
            // If N is an odd number:
            // There are (N+1)/2 coins that are flipped an odd number of times (ending in opposite state)
            // and (N-1)/2 coins that are flipped an even number of times (ending in initial state).

            if (I == Q) {
                // If the initial state (I) is the same as the queried state (Q):
                // We want to count coins that end up in their initial state.
                // This count is (N-1)/2.
                cout << (N - 1) / 2 << "\n";
            } else {
                // If the initial state (I) is different from the queried state (Q):
                // We want to count coins that end up in the opposite state.
                // This count is (N+1)/2.
                cout << (N + 1) / 2 << "\n";
            }
        }
    }
}

int main() {
    // Fast I/O setup as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}