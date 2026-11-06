#include <bits/stdc++.h> // Includes iostream, vector, algorithm, limits, etc.

// Using namespace std as requested by problem statement
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;

    vector<int> F(N);
    for (int i = 0; i < N; ++i) {
        cin >> F[i];
    }

    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }

    // type_costs[k] will store the total cost for fruit type k
    // Using long long just to be safe, though int is sufficient given constraints (max sum 2500)
    vector<long long> type_costs(M + 1, 0);
    // appeared[k] will be true if at least one basket of type k exists
    vector<bool> appeared(M + 1, false);

    // Aggregate costs and mark appeared fruit types
    for (int i = 0; i < N; ++i) {
        type_costs[F[i]] += P[i];
        appeared[F[i]] = true;
    }

    long long min_total_cost = LLONG_MAX; // Initialize with maximum possible long long value

    // Iterate through all possible fruit types from 1 to M
    for (int k = 1; k <= M; ++k) {
        // Only consider fruit types that actually appear in at least one basket
        if (appeared[k]) {
            min_total_cost = min(min_total_cost, type_costs[k]);
        }
    }

    cout << min_total_cost << "\n";
}

int main() {
    // Fast I/O as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}