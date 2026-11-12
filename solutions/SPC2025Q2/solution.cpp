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
        long long k, p;
        std::cin >> n >> k >> p;
        std::vector<int> a(n);
        int max_chair_height = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            if (a[i] > max_chair_height) {
                max_chair_height = a[i];
            }
        }

        long long ved_total_height = k;
        long long varun_total_height = p;

        bool ved_got_max = false;
        for (int i = 0; i < n; ++i) {
            if (a[i] == max_chair_height) {
                if (!ved_got_max) {
                    ved_total_height += a[i];
                    ved_got_max = true;
                } else {
                    varun_total_height += a[i];
                }
            } else {
                varun_total_height += a[i];
            }
        }

        if (ved_total_height > varun_total_height) {
            std::cout << "Ved\n";
        } else if (varun_total_height > ved_total_height) {
            std::cout << "Varun\n";
        } else {
            std::cout << "Equal\n";
        }
    }
    return 0;
}