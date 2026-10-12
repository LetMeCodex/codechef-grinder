#include <bits/stdc++.h> // Includes iostream, vector, set, etc.

// Using namespace std; as requested
using namespace std;

void solve() {
    int N;
    cin >> N;
    
    // Using a boolean vector to mark seen colors.
    // C_i are 1-indexed, so the vector needs to be of size N + 1.
    // Initialize all elements to false.
    vector<bool> seen_colors(N + 1, false); 
    int distinct_count = 0;
    
    for (int i = 0; i < N; ++i) {
        int C_i;
        cin >> C_i;
        // If this color hasn't been seen before
        if (!seen_colors[C_i]) {
            seen_colors[C_i] = true; // Mark it as seen
            distinct_count++;       // Increment the count of distinct colors
        }
    }
    
    cout << distinct_count << "\n";
}

int main() {
    // Fast I/O as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}