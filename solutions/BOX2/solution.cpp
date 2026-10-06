#include <bits/stdc++.h> // Includes iostream, cmath (for abs), algorithm (for min), etc.

// Using namespace std; is requested by the problem statement.
using namespace std;

void solve() {
    int X, Y, K;
    cin >> X >> Y >> K;

    int S = X + Y; // Total number of stones, which remains constant.

    // Condition for impossibility:
    // For the difference |X1' - X2'| = K to be achievable,
    // where X1' + X2' = S, we have |2*X1' - S| = K.
    // This implies 2*X1' - S = K or 2*X1' - S = -K.
    // So, 2*X1' = S + K or 2*X1' = S - K.
    // For X1' to be an integer, (S + K) and (S - K) must both be even.
    // This means S and K must have the same parity (both even or both odd).
    // If (S + K) is odd, then S and K have different parities, and X1' cannot be an integer.
    if ((S + K) % 2 != 0) {
        cout << -1 << "\n";
        return;
    }

    // If S and K have the same parity, a solution is possible.
    // There are two target configurations for the number of stones in the first box (X1'):
    // 1. X1' such that X1' - (S - X1') = K  => 2*X1' - S = K  => X1' = (S + K) / 2
    // 2. X1' such that (S - X1') - X1' = K  => S - 2*X1' = K  => 2*X1' = S - K => X1' = (S - K) / 2

    int target_X1_A = (S + K) / 2;
    int target_X1_B = (S - K) / 2;

    // The number of moves (and thus time) required to change the count of stones
    // in the first box from its current value X to a target value X1' is |X - X1'|.
    // We need the minimum time, so we take the minimum of the two possibilities.
    int moves_A = abs(X - target_X1_A);
    int moves_B = abs(X - target_X1_B);

    cout << min(moves_A, moves_B) << "\n";
}

int main() {
    // Fast I/O setup as requested.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases.
    while (T--) {
        solve(); // Solve each test case.
    }

    return 0;
}