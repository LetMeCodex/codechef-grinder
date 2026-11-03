#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        std::vector<int> c(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> c[i];
        }

        // Sort the prices in descending order
        std::sort(c.rbegin(), c.rend());

        // Sum the top K prices
        long long total_cost = 0;
        for (int i = 0; i < k; ++i) {
            total_cost += c[i];
        }
        std::cout << total_cost << "\n";
    }
    return 0;
}