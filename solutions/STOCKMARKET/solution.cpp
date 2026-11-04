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
        long long total_sum = 0;
        long long min_val = 101; // Initialize with a value larger than any possible A_i

        for (int i = 0; i < n; ++i) {
            long long current_profit;
            std::cin >> current_profit;
            total_sum += current_profit;
            if (current_profit < min_val) {
                min_val = current_profit;
            }
        }

        if (n == 1) {
            std::cout << 0 << "\n"; // If only one day, skipping it results in 0 profit.
            continue;
        }

        // To maximize profit by skipping exactly one day, we should skip the day
        // with the minimum profit (or maximum loss).
        // The maximum profit will be the total sum minus the minimum profit.
        long long max_profit = total_sum - min_val;
        std::cout << max_profit << "\n";
    }
    return 0;
}