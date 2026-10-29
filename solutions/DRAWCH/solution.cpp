#include <bits/stdc++.h> // Includes iostream, string, cmath, etc.

// Using namespace std; is requested by the problem statement.
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;

    int alice_wins_M = 0;
    // Count Alice's wins from the already played matches
    for (char c : S) {
        if (c == '1') {
            alice_wins_M++;
        }
    }

    // Bob's wins from the already played matches can be derived
    int bob_wins_M = M - alice_wins_M;

    // Condition 1: Total number of matches N must be even for a tie to be possible.
    // If N is odd, it's impossible to have equal wins for Alice and Bob.
    if (N % 2 != 0) {
        cout << "No\n";
        return;
    }

    // Condition 2: The absolute difference in current wins must be less than or equal to
    // the number of remaining matches.
    // Let R be the number of remaining matches.
    // To achieve a tie, the current difference in scores must be bridgeable within R matches.
    // The maximum difference that can be made up is R (if one player wins all R matches).
    int remaining_matches = N - M;
    int current_diff = abs(alice_wins_M - bob_wins_M);

    if (current_diff <= remaining_matches) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    // Fast I/O setup as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve();
    }

    return 0;
}