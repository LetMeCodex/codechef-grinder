#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<long long> w(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> w[i];
        }

        long long min_initial_velocity = 0;
        for (int i = 0; i < n; ++i) {
            // For the i-th segment (0-indexed), the velocity must be at least w[i].
            // Also, the velocity on the i-th segment is at most the velocity on the (i-1)-th segment minus 1.
            // Let V_0 be the initial velocity.
            // Velocity on segment 0: V_0. Must satisfy V_0 >= w[0].
            // Velocity on segment 1: V_1. Must satisfy V_1 >= w[1] and V_1 <= V_0 - 1.
            // Velocity on segment i: V_i. Must satisfy V_i >= w[i] and V_i <= V_{i-1} - 1.
            // This implies V_i <= V_0 - i.
            // So, for each segment i, we must have V_0 - i >= w[i], which means V_0 >= w[i] + i.
            // To satisfy this for all segments, V_0 must be at least the maximum of (w[i] + i) over all i.
            min_initial_velocity = std::max(min_initial_velocity, w[i] + i);
        }
        std::cout << min_initial_velocity << "\n";
    }
    return 0;
}