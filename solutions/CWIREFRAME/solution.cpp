#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The perimeter of a rectangle with length N and width M is 2 * (N + M).
 * The cost per cm is X.
 * Total cost = Perimeter * X = 2 * (N + M) * X.
 * 
 * Constraints:
 * N, M, X <= 1000.
 * Max perimeter = 2 * (1000 + 1000) = 4000.
 * Max cost = 4000 * 1000 = 4,000,000.
 * This fits within a standard 32-bit integer, but using long long is 
 * safer practice in competitive programming to prevent overflow in 
 * similar problems with larger constraints.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, m, x;
        cin >> n >> m >> x;
        
        // Calculate perimeter: 2 * (N + M)
        // Calculate total cost: Perimeter * X
        long long perimeter = 2 * (n + m);
        long long total_cost = perimeter * x;
        
        cout << total_cost << "\n";
    }

    return 0;
}