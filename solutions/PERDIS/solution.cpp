#include <iostream>
#include <vector>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> p(n);
        std::vector<bool> is_fixed(n, false);
        for (int i = 0; i < n; ++i) {
            std::cin >> p[i];
            if (p[i] == i + 1) {
                is_fixed[i] = true;
            }
        }

        long long total_swaps = 0;
        int i = 0;
        while (i < n) {
            if (is_fixed[i]) {
                int start = i;
                while (i < n && is_fixed[i]) {
                    i++;
                }
                int length = i - start;
                // A block of length L requires ceil(L/2) swaps
                total_swaps += (length + 1) / 2;
            } else {
                i++;
            }
        }
        std::cout << total_swaps << "\n";
    }
    return 0;
}