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
        std::vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        long long stored_protein = 0;
        bool possible = true;
        int first_day_fail = -1;

        for (int i = 0; i < n; ++i) {
            long long current_protein = stored_protein + a[i];
            if (current_protein < k) {
                possible = false;
                first_day_fail = i + 1;
                break;
            }
            stored_protein = current_protein - k;
        }

        if (possible) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO " << first_day_fail << "\n";
        }
    }
    return 0;
}