#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given X seats and Y interested students.
 * If Y > X, we need to add (Y - X) seats to accommodate all students.
 * If Y <= X, we already have enough seats, so we need to add 0 seats.
 * This can be represented as max(0, Y - X).
 * 
 * Constraints:
 * T <= 100
 * X, Y <= 10^5
 * The result will fit in a standard integer, but using long long is safe practice.
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y;
        cin >> x >> y;
        
        if (y > x) {
            cout << (y - x) << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
    
    return 0;
}