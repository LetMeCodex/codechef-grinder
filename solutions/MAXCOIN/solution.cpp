#include <bits/stdc++.h> // Required by problem statement

// Required by problem statement
using namespace std;

void solve() {
    int N, X;
    cin >> N >> X;

    // The strategy to maximize coins is to win the X games with the highest coin values
    // and lose the (N-X) games with the lowest coin values.
    //
    // The coin values are 2^1, 2^2, ..., 2^N.
    //
    // Chef wins games N, N-1, ..., N-X+1.
    // Sum of coins from wins: S_win = 2^N + 2^(N-1) + ... + 2^(N-X+1)
    //
    // Chef loses games 1, 2, ..., N-X.
    // Sum of coins paid for losses: S_loss = 2^1 + 2^2 + ... + 2^(N-X)
    //
    // Total coins = S_win - S_loss.
    //
    // We use the formula for the sum of a geometric series: 2^1 + ... + 2^k = 2^(k+1) - 2.
    //
    // S_win can be written as (2^1 + ... + 2^N) - (2^1 + ... + 2^(N-X)).
    // S_win = (2^(N+1) - 2) - (2^(N-X+1) - 2)
    // S_win = 2^(N+1) - 2^(N-X+1)
    // (This formula holds even if N-X = 0, as 2^1 - 2 = 0.)
    //
    // S_loss = 2^(N-X+1) - 2.
    // (This formula also holds if N-X = 0, as 2^1 - 2 = 0.)
    //
    // Total coins = S_win - S_loss
    // Total coins = (2^(N+1) - 2^(N-X+1)) - (2^(N-X+1) - 2)
    // Total coins = 2^(N+1) - 2 * 2^(N-X+1) + 2
    // Total coins = 2^(N+1) - 2^(N-X+1+1) + 2
    // Total coins = 2^(N+1) - 2^(N-X+2) + 2

    long long total_coins = (1LL << (N + 1)) - (1LL << (N - X + 2)) + 2;
    
    cout << total_coins << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}