#include <bits/stdc++.h> // Includes iostream, vector, etc.

// Using namespace std; is common in competitive programming
using namespace std;

void solve() {
    int n;
    cin >> n;

    // Strategy: Output n distinct integers starting from 251.
    // Let S be the set {251, 252, ..., 250 + n}.
    //
    // 1. Distinctness: All elements 251, 252, ..., 250+n are clearly distinct.
    //
    // 2. Range constraint (1 to 500):
    //    The smallest element is 251, which is >= 1.
    //    The largest element is 250 + n. Since n <= 100, the maximum value is 250 + 100 = 350.
    //    350 is <= 500.
    //    Thus, all elements are distinct and lie between 1 and 500.
    //
    // 3. "Good set" condition (no distinct a, b, c in S such that a + b = c):
    //    Let a, b be two distinct elements from S.
    //    The smallest possible sum a + b occurs when a and b are the two smallest elements in S,
    //    which are 251 and 252.
    //    So, a + b >= 251 + 252 = 503.
    //
    //    Now, consider any element c in S.
    //    The largest possible element c in S is 250 + n.
    //    Since n <= 100, the maximum value for c is 250 + 100 = 350.
    //    So, c <= 350.
    //
    //    Since a + b >= 503 and c <= 350, it is impossible for a + b = c.
    //    Therefore, the set S is a good set.
    for (int i = 0; i < n; ++i) {
        cout << 251 + i << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}