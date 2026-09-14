#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * An expert is defined as someone who has at least 50% of their problems approved.
 * Given X total problems and Y approved problems:
 * The condition is (Y / X) >= 0.5
 * To avoid floating point precision issues, we can multiply both sides by 2X:
 * 2 * Y >= X
 * 
 * Constraints:
 * 1 <= T <= 1000
 * 1 <= Y <= X <= 10^6
 * Since X and Y fit within standard integer types, long long is safe but int is sufficient.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y;
        cin >> x >> y;
        
        // Check if at least 50% of problems are approved
        // 2 * Y >= X is equivalent to Y/X >= 0.5
        if (2 * y >= x) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}