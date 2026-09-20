#include <bits/stdc++.h> // Includes iostream, etc.

using namespace std; // Use standard namespace

void solve() {
    int n; // N up to 10^9 fits in a standard 32-bit integer
    cin >> n;

    long long low = 0; // Minimum possible height
    // A safe upper bound for h. For N=10^9, h is approx 45000.
    // 200000 is a generous upper bound that ensures mid * (mid+1) fits in long long.
    long long high = 200000; 
    long long ans = 0; // Stores the maximum valid height found

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        
        // Calculate coins needed for a triangle of height 'mid'.
        // mid * (mid + 1) can be up to 200000 * 200001 approx 4 * 10^10,
        // which requires a long long to prevent overflow.
        long long coins_needed = mid * (mid + 1) / 2;

        if (coins_needed <= n) {
            // If 'mid' height is possible with 'n' coins,
            // it's a candidate for the answer. Try to find a higher height.
            ans = mid;
            low = mid + 1;
        } else {
            // If 'mid' height requires too many coins,
            // we need to try a smaller height.
            high = mid - 1;
        }
    }
    cout << ans << "\n"; // Output the maximum possible height
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Number of test cases
    cin >> t;
    while (t--) {
        solve(); // Solve each test case
    }

    return 0;
}