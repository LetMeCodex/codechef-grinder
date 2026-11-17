#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // Not strictly needed, but useful for other sum operations

void solve() {
    int N, M;
    std::cin >> N >> M;

    std::vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    std::vector<long long> B(M);
    for (int i = 0; i < M; ++i) {
        std::cin >> B[i];
    }

    // Sort skills in descending order to easily pick the top players
    std::sort(A.begin(), A.end(), std::greater<long long>());
    std::sort(B.begin(), B.end(), std::greater<long long>());

    // Calculate prefix sums for top skills.
    // pref_A[k] will store the sum of the top k skills (1-indexed).
    // pref_A[0] will be 0.
    std::vector<long long> pref_A(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        pref_A[i + 1] = pref_A[i] + A[i];
    }

    std::vector<long long> pref_B(M + 1, 0);
    for (int i = 0; i < M; ++i) {
        pref_B[i + 1] = pref_B[i] + B[i];
    }

    long long max_total_skill = -1; // Initialize with -1 to indicate no valid team found yet

    // Iterate through possible combinations of (batsmen_count, bowlers_count)
    // A team must have exactly 11 players, with at least 4 batsmen and 4 bowlers.
    // This means batsmen_count can range from 4 to 7.
    // Corresponding bowlers_count will be 11 - batsmen_count.
    for (int num_batsmen = 4; num_batsmen <= 7; ++num_batsmen) {
        int num_bowlers = 11 - num_batsmen;

        // Check if we have enough players of each type available
        if (N >= num_batsmen && M >= num_bowlers) {
            long long current_skill = pref_A[num_batsmen] + pref_B[num_bowlers];
            if (current_skill > max_total_skill) {
                max_total_skill = current_skill;
            }
        }
    }

    std::cout << max_total_skill << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}