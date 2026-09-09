#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N friends and each subscription covers 6 people.
 * To cover N people, we need ceil(N / 6.0) subscriptions.
 * Using integer arithmetic, ceil(N / 6) can be calculated as (N + 5) / 6.
 * The total cost is then (number of subscriptions) * X.
 * 
 * Constraints:
 * N <= 100, X <= 1000.
 * The maximum cost would be roughly (100/6 + 1) * 1000 = 17 * 1000 = 17000.
 * This fits well within a standard 32-bit integer, but using long long is safe practice.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, x;
        cin >> n >> x;

        // Calculate number of subscriptions needed
        // Using integer division: (n + 6 - 1) / 6 is the standard way to perform ceiling division
        long long subscriptions = (n + 5) / 6;

        // Calculate total cost
        long long total_cost = subscriptions * x;

        cout << total_cost << "\n";
    }

    return 0;
}