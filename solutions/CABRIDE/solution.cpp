#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * Problem: CABRIDE
 * The cost for a cab with X people is max(200, 100 * X).
 * We need to transport N people with cabs of capacity 4.
 * The minimum number of cabs is ceil(N / 4.0).
 * The total cost is the sum of costs of these cabs.
 * The formula max(200 * ceil(N/4.0), 100 * N) works because:
 * - If N is small, the 200 floor dominates.
 * - If N is large, the 100 * N dominates.
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        int num_cabs = (n + 3) / 4;
        long long cost = max((long long)200 * num_cabs, (long long)100 * n);
        cout << cost << "\n";
    }
    return 0;
}