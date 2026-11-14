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
        std::cin >> n;
        std::vector<long long> a(n);
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            sum += a[i];
        }

        int best_coin_index = -1;

        // The condition for the mean to remain the same after removing coin i is:
        // (Sum - A_i) / (N - 1) = Sum / N
        // N * (Sum - A_i) = Sum * (N - 1)
        // N * Sum - N * A_i = N * Sum - Sum
        // -N * A_i = -Sum
        // N * A_i = Sum
        // A_i = Sum / N
        // This means the value of the coin to be removed must be equal to the original mean.
        // Since the mean can be a fraction, we need to be careful.
        // The equation N * A_i = Sum implies that Sum must be divisible by N,
        // and A_i must be equal to Sum / N.

        // We are looking for the smallest index i such that A_i = Sum / N.
        // This implies Sum must be divisible by N.
        // If Sum is not divisible by N, then no integer A_i can be equal to Sum / N.
        // So, we first check if Sum is divisible by N.
        if (sum % n == 0) {
            long long required_value = sum / n;
            for (int i = 0; i < n; ++i) {
                if (a[i] == required_value) {
                    best_coin_index = i + 1; // 1-based indexing
                    break; // Found the smallest index
                }
            }
        }

        if (best_coin_index != -1) {
            std::cout << best_coin_index << "\n";
        } else {
            std::cout << "Impossible\n";
        }
    }
    return 0;
}