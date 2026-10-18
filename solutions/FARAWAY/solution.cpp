#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>

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
        long long total_distance = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            // To maximize |A_i - B_i|, B_i should be either 1 or M.
            // We want to choose B_i such that it's as far as possible from A_i.
            // If A_i is closer to 1, we choose B_i = M.
            // If A_i is closer to M, we choose B_i = 1.
            // The distance will be max(|A_i - 1|, |A_i - M|).
            // This is equivalent to choosing B_i = 1 if A_i > M/2, and B_i = M if A_i <= M/2.
            // However, a simpler way to think about it is that for each A_i,
            // the maximum possible distance is achieved by picking B_i to be either 1 or M.
            // The distance is then max(A_i - 1, M - A_i).
            // Summing these maximum possible distances for each element will give the overall maximum distance.
            total_distance += std::max(a[i] - 1, m - a[i]);
        }
        std::cout << total_distance << "\n";
    }
    return 0;
}