#include <iostream>
#include <vector>

void solve() {
    int n, k;
    std::cin >> n >> k;

    // Condition for no solution:
    // If N < 2K, at least one residue class modulo K will contain only one element.
    // A derangement of a set of size 1 is impossible.
    //
    // Let N = qK + r, where 0 <= r < K.
    // The sizes of residue classes (j % K) are:
    // - q+1 for 'rem' classes (1 to rem)
    // - q for K-'rem' classes (rem+1 to K-1, and 0)
    //
    // If q = 0 (i.e., N < K): All classes 1 to N have size 1. No solution.
    // If q = 1 (i.e., K <= N < 2K):
    //   Classes 1 to N%K have size 2.
    //   Classes N%K+1 to K-1 (and 0) have size 1.
    //   Since there's at least one class of size 1, no solution.
    //
    // Thus, if N < 2K, no solution exists.
    if (n < 2 * k) {
        std::cout << -1 << "\n";
        return;
    }

    // If N >= 2K, then q = floor(N/K) >= 2.
    // This means all residue classes modulo K will have size at least 2.
    // For a set of size m >= 2, a cyclic shift is a valid derangement.
    // Example: for {x1, x2, ..., xm}, map x_i to x_{i+1} (with x_m mapping to x_1).
    
    // Store elements grouped by their remainder modulo K.
    // groups[r] will contain all numbers j such that 1 <= j <= N and j % K == r.
    // Note: i % k for i=1..N will produce remainders 1, 2, ..., k-1, 0.
    // So groups[0] will store multiples of K, groups[1] for 1, 1+K, etc.
    std::vector<std::vector<int>> groups(k);
    for (int i = 1; i <= n; ++i) {
        groups[i % k].push_back(i);
    }

    // P will store the resulting permutation. P[i] is the value at index i.
    std::vector<int> p(n + 1);

    // For each remainder group, apply a cyclic shift.
    for (int r = 0; r < k; ++r) {
        const auto& current_group = groups[r];
        int group_size = current_group.size();
        
        // As established, group_size >= 2 when N >= 2K, so a cyclic shift is always valid.
        for (int i = 0; i < group_size; ++i) {
            int current_val = current_group[i];
            int next_val = current_group[(i + 1) % group_size]; // Cyclic shift
            p[current_val] = next_val;
        }
    }

    // Print the permutation P_1, P_2, ..., P_N.
    for (int i = 1; i <= n; ++i) {
        std::cout << p[i] << (i == n ? "" : " ");
    }
    std::cout << "\n";
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}