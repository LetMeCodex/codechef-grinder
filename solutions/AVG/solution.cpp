#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n, k, v;
        std::cin >> n >> k >> v;
        std::vector<int> a(n);
        long long sum_a = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            sum_a += a[i];
        }

        // The original sequence had N + K elements.
        // The sum of the original sequence is (N + K) * V.
        // Let X be the value of the K deleted elements.
        // The sum of the remaining N elements is sum_a.
        // So, sum_a + K * X = (N + K) * V
        // K * X = (N + K) * V - sum_a
        // X = ((N + K) * V - sum_a) / K

        long long original_total_sum = (long long)(n + k) * v;
        long long sum_of_deleted_elements = original_total_sum - sum_a;

        // For the scenario to be possible, two conditions must be met:
        // 1. The sum of the deleted elements must be non-negative.
        // 2. The sum of the deleted elements must be perfectly divisible by K.
        // 3. The resulting value X must be a positive integer.

        if (sum_of_deleted_elements <= 0) {
            std::cout << -1 << "\n";
        } else {
            if (sum_of_deleted_elements % k == 0) {
                long long x = sum_of_deleted_elements / k;
                if (x > 0) {
                    std::cout << x << "\n";
                } else {
                    std::cout << -1 << "\n";
                }
            } else {
                std::cout << -1 << "\n";
            }
        }
    }
    return 0;
}