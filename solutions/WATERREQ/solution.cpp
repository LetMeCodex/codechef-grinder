#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        // The water cooler requires 2 liters of water per hour.
        // For N hours, the total water required is 2 * N liters.
        // Constraints: 1 <= N <= 1000.
        // The maximum result will be 2 * 1000 = 2000, which fits within an int.
        cout << 2 * n << "\n";
    }
    return 0;
}