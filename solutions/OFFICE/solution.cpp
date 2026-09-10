#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The employee works for X hours from Monday to Thursday (4 days).
 * The employee works for Y hours on Friday (1 day).
 * Total hours = (4 * X) + Y.
 * 
 * Constraints:
 * T <= 100
 * 2 <= X <= 12
 * 1 <= Y < X
 * 
 * Since X and Y are small, the result will fit in a standard integer.
 * Time Complexity: O(T)
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y;
        if (cin >> x >> y) {
            // Calculate total hours: 4 days of X hours + 1 day of Y hours
            long long total_hours = (4 * x) + y;
            cout << total_hours << "\n";
        }
    }

    return 0;
}