#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        // We have X cards face-up and N-X cards face-down.
        // To make all cards face-up, we need to flip the N-X face-down cards.
        // To make all cards face-down, we need to flip the X face-up cards.
        // We want the minimum number of operations, so we choose the smaller of these two options.
        cout << min(x, n - x) << "\n";
    }
    return 0;
}