#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        long long max_profit = 0;
        for (int i = 0; i < n; ++i) {
            long long s, p, v;
            std::cin >> s >> p >> v;
            // Chef's store is one additional store.
            // So, total stores for this food type will be s + 1.
            // Number of people buying from Chef is floor(p / (s + 1)).
            long long chef_customers = p / (s + 1);
            long long current_profit = chef_customers * v;
            if (current_profit > max_profit) {
                max_profit = current_profit;
            }
        }
        std::cout << max_profit << "\n";
    }
    return 0;
}