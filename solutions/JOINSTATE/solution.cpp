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
        long long m;
        std::cin >> n >> m;
        std::vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        int count = 0;
        long long current_sum = 0;
        for (int i = 0; i < n; ++i) {
            current_sum += a[i];
            if (current_sum >= m) {
                count++;
                current_sum = 0;
            }
        }
        std::cout << count << "\n";
    }
    return 0;
}