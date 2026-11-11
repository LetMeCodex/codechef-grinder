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
        std::vector<int> a(n);
        long long sum_odd_days = 0;
        long long sum_even_days = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            if ((i + 1) % 2 != 0) { // Day 1, 3, 5... (1-indexed)
                sum_odd_days += a[i];
            } else { // Day 2, 4, 6... (1-indexed)
                sum_even_days += a[i];
            }
        }
        std::cout << std::max(sum_odd_days, sum_even_days) << "\n";
    }
    return 0;
}