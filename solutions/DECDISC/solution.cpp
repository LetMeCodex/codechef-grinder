#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T;
    std::cin >> T;
    while (T--) {
        int N;
        std::cin >> N;
        std::vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> A[i];
        }

        long long min_cost = -1; // Initialize with a value that will be overwritten

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == j) {
                    continue; // Must buy two DIFFERENT vases
                }

                long long current_cost;
                if (j == i + 1) {
                    // If vase i is bought, price of vase i+1 is halved.
                    // We are buying vase i and vase j=i+1.
                    // The cost is A[i] + A[j]/2.
                    current_cost = (long long)A[i] + ((long long)A[j] / 2);
                } else if (i == j + 1) {
                    // If vase j is bought, price of vase j+1 (which is i) is halved.
                    // We are buying vase j and vase i=j+1.
                    // The cost is A[j] + A[i]/2.
                    current_cost = (long long)A[j] + ((long long)A[i] / 2);
                }
                else {
                    // No adjacent discount applies between i and j.
                    current_cost = (long long)A[i] + (long long)A[j];
                }

                if (min_cost == -1 || current_cost < min_cost) {
                    min_cost = current_cost;
                }
            }
        }
        std::cout << min_cost << std::endl;
    }
    return 0;
}