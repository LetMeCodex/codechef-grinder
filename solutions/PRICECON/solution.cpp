#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        long long k;
        std::cin >> n >> k;
        long long lost_revenue = 0;
        for (int i = 0; i < n; ++i) {
            long long p;
            std::cin >> p;
            if (p > k) {
                lost_revenue += (p - k);
            }
        }
        std::cout << lost_revenue << "\n";
    }
    return 0;
}