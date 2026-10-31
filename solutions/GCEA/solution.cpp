#include <bits/stdc++.h> // Includes iostream, algorithm, etc.

// Using namespace std; as requested by problem instructions.
using namespace std;

void solve() {
    int N;
    // X and Y can be int based on constraints (max 100), but using long long for consistency with total_cost
    // and general competitive programming practice to avoid potential overflow issues, especially with products.
    long long X, Y; 
    cin >> N >> X >> Y;

    long long total_cost = 0; // Use long long for total_cost to prevent overflow.
                              // Max total_cost is 100 * 100 = 10000, which fits in int.
                              // But following the general instruction "use long long in C++" for sums.

    for (int i = 0; i < N; ++i) {
        int A_i; // A_i is max 100, fits in int.
        cin >> A_i;

        // Calculate cost using Normal Pekóballs.
        // Cast A_i to long long before multiplication to ensure the product is long long,
        // even though A_i * X (100 * 100 = 10000) fits in int. This is a safe practice.
        long long cost_normal = (long long)A_i * X; 
        
        // Cost using a Master Pekóball is simply Y.
        long long cost_master = Y;

        // Add the minimum of the two options to the total cost.
        total_cost += min(cost_normal, cost_master);
    }

    cout << total_cost << "\n";
}

int main() {
    // Fast I/O setup as requested.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases.
    while (T--) { // Loop through each test case.
        solve();
    }

    return 0;
}