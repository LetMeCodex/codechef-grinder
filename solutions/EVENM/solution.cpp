#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T;
    std::cin >> T;
    while (T--) {
        int N;
        std::cin >> N;
        std::vector<std::vector<int>> matrix(N, std::vector<int>(N));
        int odd_val = 1;
        int even_val = 2;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                // Using 0-based indexing for matrix access, but problem uses 1-based for logic.
                // The sum of indices (i+1) + (j+1) = i + j + 2.
                // Parity of (i+1) + (j+1) is the same as parity of i + j.
                if ((i + j) % 2 == 0) { // Corresponds to (row_idx + col_idx) being even
                    matrix[i][j] = odd_val;
                    odd_val += 2;
                } else { // Corresponds to (row_idx + col_idx) being odd
                    matrix[i][j] = even_val;
                    even_val += 2;
                }
            }
        }

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                std::cout << matrix[i][j] << (j == N - 1 ? "" : " ");
            }
            std::cout << "\n";
        }
    }
    return 0;
}