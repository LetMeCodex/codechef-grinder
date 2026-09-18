#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice has A chocolates and Bob has B chocolates.
 * Total chocolates = A + B.
 * To distribute them equally between two people, the total number of chocolates
 * must be divisible by 2.
 * If (A + B) % 2 == 0, then each person gets (A + B) / 2 chocolates.
 * Since we cannot break chocolates, this is the only condition required.
 * 
 * Constraints:
 * 1 <= T <= 1000
 * 1 <= A, B <= 10^5
 * A + B will be at most 2 * 10^5, which fits comfortably in a standard 32-bit integer.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long a, b;
        cin >> a >> b;
        
        // Check if the sum is even
        if ((a + b) % 2 == 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}