#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Initial balance = W
 * Monthly deposit = X
 * Monthly deduction = Y
 * Net change per month = (X - Y)
 * Total change after Z months = (X - Y) * Z
 * Final balance = W + (X - Y) * Z
 * 
 * Constraints:
 * W, X, Y, Z <= 10^4
 * Max possible value: 10^4 + (10^4 * 10^4) = 100,010,000
 * Min possible value: 10^4 - (10^4 * 10^4) = -99,990,000
 * Both fit within a standard 32-bit signed integer, but long long is safe.
 */

void solve() {
    long long w, x, y, z;
    if (!(cin >> w >> x >> y >> z)) return;
    
    // Calculate final balance: Initial + (Net Monthly Change * Months)
    long long final_balance = w + (x - y) * z;
    
    cout << final_balance << "\n";
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        solve();
    }

    return 0;
}