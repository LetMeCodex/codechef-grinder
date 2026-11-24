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
        int n, l, r;
        std::cin >> n >> l >> r;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        long long max_carrots = 0;

        // The bear patrols clearings L to R (1-indexed).
        // In 0-indexed array, this is indices L-1 to R-1.
        // The rabbit cannot visit indices from L-1 to R-1.

        // The rabbit can start in any clearing not patrolled by the bear.
        // These are clearings 1 to L-1 (indices 0 to L-2)
        // and clearings R+1 to N (indices R to N-1).

        // Case 1: Rabbit starts in the left safe zone (clearings 1 to L-1)
        // The rabbit can collect carrots from any contiguous subsegment of clearings
        // from 1 to L-1. Since the rabbit can move freely within this zone,
        // and cannot cross into the bear's zone, the maximum carrots will be
        // the sum of carrots in a contiguous subsegment.
        // However, the problem states the rabbit can move left/right as many times
        // as they like. This implies that if the rabbit starts in a safe zone,
        // they can reach *all* clearings in that safe zone.
        // So, the total carrots from the left safe zone is the sum of a[0]...a[L-2].
        if (l > 1) {
            long long current_carrots = 0;
            for (int i = 0; i < l - 1; ++i) {
                current_carrots += a[i];
            }
            max_carrots = std::max(max_carrots, current_carrots);
        }

        // Case 2: Rabbit starts in the right safe zone (clearings R+1 to N)
        // Similarly, the rabbit can reach all clearings in this zone.
        // The total carrots from the right safe zone is the sum of a[R]...a[N-1].
        if (r < n) {
            long long current_carrots = 0;
            for (int i = r; i < n; ++i) {
                current_carrots += a[i];
            }
            max_carrots = std::max(max_carrots, current_carrots);
        }
        
        // The problem statement guarantees that either L > 1 or R < N.
        // This means at least one of the safe zones is non-empty.
        // The rabbit can choose to start in *any* clearing not patrolled by the bear.
        // If the rabbit starts in clearing X, it can collect carrots from X.
        // Then it can move to X-1 or X+1.
        // The key insight is that the rabbit can reach *all* clearings in a connected
        // component of safe clearings.
        // The safe clearings form two disjoint segments: [0, L-2] and [R, N-1].
        // The rabbit can collect all carrots from the first segment if it starts there,
        // or all carrots from the second segment if it starts there.
        // The maximum is simply the sum of carrots in the larger of these two segments.

        std::cout << max_carrots << "\n";
    }
    return 0;
}