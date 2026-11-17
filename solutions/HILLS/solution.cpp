#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, U, D;
    cin >> N >> U >> D;
    vector<int> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    int rightmost_reachable_hill = 1;
    bool parachute_used = false;

    for (int i = 0; i < N - 1; ++i) {
        int h_current = H[i];
        int h_next = H[i+1];

        if (h_next == h_current) {
            rightmost_reachable_hill = i + 2;
        } else if (h_next > h_current) { // Taller hill
            if (h_next - h_current <= U) {
                rightmost_reachable_hill = i + 2;
            } else {
                break; // Cannot jump, too high
            }
        } else { // h_next < h_current, Lower hill
            if (h_current - h_next <= D) {
                rightmost_reachable_hill = i + 2;
            } else { // Too low for normal jump
                if (!parachute_used) {
                    parachute_used = true;
                    rightmost_reachable_hill = i + 2;
                } else {
                    break; // Cannot jump, parachute already used
                }
            }
        }
    }
    
    cout << rightmost_reachable_hill << "\n";
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