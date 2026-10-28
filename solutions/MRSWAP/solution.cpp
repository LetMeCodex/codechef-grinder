#include <bits/stdc++.h> // Includes iostream, vector, algorithm, etc.

using namespace std; // Using namespace std as requested

void solve() {
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> a[i];
    }

    long long max_first_half_sum = 0;
    // Iterate through the first N elements (0-indexed: from 0 to N-1)
    for (int i = 0; i < n; ++i) {
        // For each element a[i] in the first half, its mirror element is a[2*n - 1 - i].
        // To maximize the sum of the first half, we choose the larger of these two values
        // to be at position i.
        max_first_half_sum += max(a[i], a[2 * n - 1 - i]);
    }

    cout << max_first_half_sum << "\n";
}

int main() {
    // Fast I/O as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}