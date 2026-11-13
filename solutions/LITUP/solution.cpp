#include <iostream>
#include <vector>
#include <algorithm> // Required for std::min
#include <limits>    // Required for std::numeric_limits

void solve() {
    int N, K;
    std::cin >> N >> K;
    std::vector<int> C(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> C[i];
    }

    // Initialize min_total_cost to a value larger than any possible sum of costs.
    // Max C_i is 100, so max sum is 100 + 100 = 200.
    // Using long long and numeric_limits for robustness, though int would suffice for 200.
    long long min_total_cost = std::numeric_limits<long long>::max();

    // Iterate over all possible positions for the first floodlight (1-indexed: 1 to N)
    for (int i = 1; i <= N; ++i) {
        // Iterate over all possible positions for the second floodlight (1-indexed: i+1 to N)
        // This ensures j > i, so the two stalls are distinct and ordered.
        for (int j = i + 1; j <= N; ++j) {
            // Condition 1: Stall 1 must be covered.
            // Light at 'i' covers [max(1, i-K), min(N, i+K)].
            // For stall 1 to be covered, i-K <= 1 => i <= K+1.
            bool condition1 = (i <= K + 1);

            // Condition 2: Stall N must be covered.
            // Light at 'j' covers [max(1, j-K), min(N, j+K)].
            // For stall N to be covered, j+K >= N => j >= N-K.
            bool condition2 = (j >= N - K);

            // Condition 3: No gap between the coverage of light 'i' and light 'j'.
            // The rightmost point covered by light 'i' is min(N, i+K).
            // The leftmost point covered by light 'j' is max(1, j-K).
            // We need min(N, i+K) >= max(1, j-K) - 1.
            // This simplifies to j <= i + 2*K + 1 in the critical case.
            bool condition3 = (j <= i + 2 * K + 1);

            if (condition1 && condition2 && condition3) {
                // If all conditions are met, this is a valid pair.
                // Calculate the cost (using 0-indexed C array: C[i-1] and C[j-1]).
                long long current_cost = static_cast<long long>(C[i-1]) + C[j-1];
                min_total_cost = std::min(min_total_cost, current_cost);
            }
        }
    }

    // If min_total_cost is still its initial large value, no valid pair was found.
    if (min_total_cost == std::numeric_limits<long long>::max()) {
        std::cout << -1 << "\n";
    } else {
        std::cout << min_total_cost << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases.
    while (T--) {
        solve(); // Solve each test case.
    }

    return 0;
}