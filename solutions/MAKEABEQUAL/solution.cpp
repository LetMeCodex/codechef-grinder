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
        std::vector<long long> a(n), b(n);
        long long sum_a = 0, sum_b = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            sum_a += a[i];
        }
        for (int i = 0; i < n; ++i) {
            std::cin >> b[i];
            sum_b += b[i];
        }

        if (sum_a != sum_b) {
            std::cout << -1 << "\n";
        } else {
            long long diff_pos = 0;
            long long diff_neg = 0;
            for (int i = 0; i < n; ++i) {
                if (a[i] > b[i]) {
                    diff_pos += (a[i] - b[i]);
                } else if (b[i] > a[i]) {
                    diff_neg += (b[i] - a[i]);
                }
            }
            // Since sum_a == sum_b, the total difference where a[i] > b[i]
            // must be equal to the total difference where b[i] > a[i].
            // Each operation can reduce one positive difference and one negative difference by 1.
            // Therefore, the minimum operations is the total positive difference (or total negative difference).
            std::cout << diff_pos << "\n";
        }
    }
    return 0;
}