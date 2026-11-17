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
        std::vector<long long> w(n);
        bool possible = true;
        for (int i = 0; i < n; ++i) {
            std::cin >> w[i];
            if (w[i] > k) {
                possible = false;
            }
        }

        if (!possible) {
            std::cout << -1 << "\n";
            continue;
        }

        int trips = 0;
        long long current_weight = 0;
        for (int i = 0; i < n; ++i) {
            if (current_weight + w[i] <= k) {
                current_weight += w[i];
            } else {
                trips++;
                current_weight = w[i];
            }
        }
        
        // If there are any boxes left to carry, they need one more trip.
        if (current_weight > 0) {
            trips++;
        }

        std::cout << trips << "\n";
    }
    return 0;
}