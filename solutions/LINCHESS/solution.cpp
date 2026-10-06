#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        long long k;
        std::cin >> n >> k;
        std::vector<long long> p(n);
        int min_moves = -1;
        long long best_player_pos = -1;

        for (int i = 0; i < n; ++i) {
            std::cin >> p[i];
            // A player starting at P_i can capture Chef's pawn at K
            // if K is reachable from P_i by repeatedly adding P_i.
            // This means K must be of the form P_i + m * P_i for some non-negative integer m.
            // This simplifies to K = P_i * (1 + m).
            // So, K must be a multiple of P_i, and K >= P_i.
            // If K is a multiple of P_i, then K = q * P_i for some integer q.
            // The number of moves would be q - 1.
            // We are looking for the minimum number of moves, which means we want to maximize q.
            // This is equivalent to finding P_i such that K is a multiple of P_i,
            // and K/P_i is minimized (but K/P_i >= 1).
            // The number of moves is (K/P_i) - 1.
            // We need K >= P_i for the pawn to be able to reach K.
            // If K is a multiple of P_i, then K = q * P_i.
            // The pawn starts at P_i.
            // Move 1: P_i + P_i = 2*P_i
            // Move 2: 2*P_i + P_i = 3*P_i
            // ...
            // Move m: (m+1)*P_i
            // To reach K, we need (m+1)*P_i = K.
            // So, m+1 = K/P_i.
            // The number of moves is m = (K/P_i) - 1.
            // This requires K to be divisible by P_i, and K/P_i >= 1.
            // Since K and P_i are positive, K/P_i >= 1 is always true if K is divisible by P_i.
            // The condition is K % P_i == 0.

            if (k % p[i] == 0) {
                long long moves = (k / p[i]) - 1;
                if (best_player_pos == -1 || moves < min_moves) {
                    min_moves = moves;
                    best_player_pos = p[i];
                }
            }
        }
        std::cout << best_player_pos << "\n";
    }
    return 0;
}