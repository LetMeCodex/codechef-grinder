#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Anna (A), Bob (B), and Claudio (C) fight in pairs.
 * Each fight reduces both players' health by min(X, Y).
 * Effectively, the player with lower health becomes 0, and the player with
 * higher health reduces by the amount of the lower health.
 * 
 * To maximize Anna's final health, we want her to fight the opponents 
 * after they have potentially weakened each other.
 * 
 * Optimal Strategy:
 * 1. Let Bob and Claudio fight first. The winner (the one with more health) 
 *    will have health = abs(B - C).
 * 2. Anna then fights the winner of the first match.
 * 3. Anna's final health will be A - abs(B - C).
 * 4. If A - abs(B - C) > 0, then Anna has positive health.
 * 
 * This is equivalent to checking if A > abs(B - C).
 */

void solve() {
    long long A, B, C;
    if (!(cin >> A >> B >> C)) return;

    // The health of the opponent Anna faces after they fight each other
    // is the absolute difference between B and C.
    long long opponent_health = abs(B - C);

    // Anna wins if her initial health is strictly greater than the 
    // remaining health of the opponent she faces last.
    if (A > opponent_health) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}