#include <iostream>
#include <algorithm> // Required for std::min and std::max

void solve() {
    // Changed N, X, Y to long long to handle potentially large values and prevent overflow.
    long long N, X, Y;
    std::cin >> N >> X >> Y;

    // Let L1 be the number of leaves decorated with (1 large, 3 small) ornaments.
    // Let L2 be the number of leaves decorated with (2 large) ornaments.
    // Total leaves: L1 + L2 = N

    // Constraint 1: Total small ornaments used must not exceed Y.
    // Each L1 leaf uses 3 small ornaments. L2 leaves use 0 small ornaments.
    // So, 3 * L1 <= Y
    // This implies L1 <= Y / 3 (integer division)
    // Also, L1 cannot be more than N (total leaves) and must be non-negative.
    // So, 0 <= L1 <= std::min(N, Y / 3)
    // L1_max_possible also changed to long long.
    long long L1_max_possible = std::min(N, Y / 3);

    // Constraint 2: Total large ornaments used must not exceed X.
    // Each L1 leaf uses 1 large ornament. Each L2 leaf uses 2 large ornaments.
    // So, 1 * L1 + 2 * L2 <= X
    // Substitute L2 = N - L1:
    // L1 + 2 * (N - L1) <= X
    // L1 + 2N - 2L1 <= X
    // 2N - L1 <= X
    // Rearranging for L1:
    // L1 >= 2N - X
    // Also, L1 must be non-negative.
    // So, L1 >= std::max(0LL, 2 * N - X)
    // L1_min_required also changed to long long.
    // Used 0LL to ensure the literal 0 is treated as a long long.
    long long L1_min_required = std::max(0LL, 2 * N - X);

    // A solution exists if there is any integer L1 that satisfies both bounds.
    // This means L1_min_required <= L1_max_possible.
    if (L1_min_required <= L1_max_possible) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // Unties cin from cout and disables synchronization with C stdio.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // T can remain int as it's up to 10^4
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}