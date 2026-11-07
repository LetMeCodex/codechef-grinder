#include <bits/stdc++.h> // Includes iostream, vector, algorithm, etc.

// Using namespace std; is common in competitive programming for brevity.
using namespace std;

void solve() {
    int n;
    cin >> n;
    // Initialize min_val with a value greater than the maximum possible Ai (10^5).
    // This ensures the first element read will correctly set min_val.
    int min_val = 100001; 

    for (int i = 0; i < n; ++i) {
        int a_i;
        cin >> a_i;
        // Update min_val with the smaller of current min_val and a_i
        min_val = min(min_val, a_i); 
    }

    // The total cost will be (N-1) * min_val.
    // N can be up to 50000, min_val up to 10^5.
    // (N-1) * min_val can be ~50000 * 10^5 = 5 * 10^9, which exceeds int max.
    // Use long long for the result to prevent overflow.
    long long total_cost = static_cast<long long>(min_val) * (n - 1);

    cout << total_cost << "\n";
}

int main() {
    // Fast I/O to speed up input and output operations.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}