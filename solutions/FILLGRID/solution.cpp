#include <iostream>
#include <vector> // Not strictly needed for this solution, but often useful

void solve() {
    int N;
    std::cin >> N;

    if (N % 2 == 0) {
        // N is even. Fill all cells with -1.
        // For any row/column: k=N (even). S = N - 2N = -N. P = (-1)^N = 1. S*P = -N < 0.
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                std::cout << -1 << (j == N - 1 ? "" : " ");
            }
            std::cout << std::endl;
        }
    } else {
        // N is odd. Fill main diagonal with -1, others with 1.
        // For any row/column: k=1 (odd). S = N - 2*1 = N-2. P = (-1)^1 = -1. S*P = -(N-2) = 2-N.
        // For N >= 3, 2-N is negative. So S*P < 0.
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == j) {
                    std::cout << -1 << (j == N - 1 ? "" : " ");
                } else {
                    std::cout << 1 << (j == N - 1 ? "" : " ");
                }
            }
            std::cout << std::endl;
        }
    }
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