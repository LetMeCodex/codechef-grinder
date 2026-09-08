#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef needs 30 minutes to reach the office.
 * Chef leaves X minutes before the deadline.
 * If X >= 30, Chef reaches on time or early (YES).
 * If X < 30, Chef reaches late (NO).
 * 
 * Constraints: 1 <= T <= 60, 1 <= X <= 60.
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
        int x;
        cin >> x;
        
        // Check if the time taken (30 minutes) is less than or equal to 
        // the time available (X minutes).
        if (x >= 30) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}