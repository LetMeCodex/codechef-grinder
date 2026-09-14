#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chefario has Y mana points and each special attack costs X mana points.
 * To find the maximum number of attacks, we need to find the largest integer k
 * such that k * X <= Y.
 * This is equivalent to the integer division of Y by X: floor(Y / X).
 * 
 * Constraints:
 * T <= 10^5
 * X <= 100
 * Y <= 1000
 * Since Y/X will not exceed 1000, standard 'int' is sufficient.
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
        int x, y;
        cin >> x >> y;
        
        // The maximum number of attacks is simply the quotient of Y divided by X.
        // If Y < X, the result is 0, which is correctly handled by integer division.
        int max_attacks = y / x;
        
        cout << max_attacks << "\n";
    }
    
    return 0;
}