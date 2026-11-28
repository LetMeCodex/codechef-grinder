#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let c be the number of correct answers and w be the number of wrong answers.
 * We are given:
 * 1. 0 <= c + w <= N
 * 2. 4*c - 1*w = S
 * 
 * We want to minimize (c + w) subject to these constraints.
 * From (2), w = 4*c - S.
 * Substituting into (1):
 * 0 <= c + (4*c - S) <= N
 * 0 <= 5*c - S <= N
 * S <= 5*c <= N + S
 * 
 * So, c must satisfy:
 * 1. c >= 0
 * 2. w = 4*c - S >= 0 => c >= S/4
 * 3. 5*c >= S => c >= ceil(S/5)
 * 4. 5*c <= N + S => c <= (N + S) / 5
 * 
 * We need to find the smallest c + w = c + (4*c - S) = 5*c - S
 * such that there exists an integer c satisfying:
 * max(0, ceil(S/4), ceil(S/5)) <= c <= floor((N + S) / 5)
 * 
 * Since 5*c - S is strictly increasing with c, we just need to check if there
 * exists any c in the range [max(0, ceil(S/4), ceil(S/5)), floor((N + S) / 5)].
 * If such a c exists, the minimum attempts will be at the smallest valid c.
 */

void solve() {
    int N, S;
    cin >> N >> S;

    int min_c = 0;
    // c must be at least ceil(S/4.0) because w = 4c - S >= 0
    min_c = max(min_c, (S + 3) / 4);
    // c must be at least ceil(S/5.0) because 5c - S >= 0 (Wait, 5c - S is the total attempts, 
    // which is >= 0, so c >= S/5 is covered by c >= S/4)
    
    int max_c = (N + S) / 5;

    if (min_c > max_c) {
        cout << -1 << "\n";
    } else {
        // Smallest attempts = 5 * min_c - S
        cout << (5 * min_c - S) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}