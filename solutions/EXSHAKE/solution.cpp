#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

long long calculate_handshakes(long long people) {
    if (people < 2) {
        return 0;
    }
    return people * (people - 1) / 2;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        long long m;
        std::cin >> n >> m;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        std::sort(a.begin(), a.end());

        int max_groups = 0;
        for (int k = 0; k <= n; ++k) { // k is the number of groups to invite
            if (k == 0) {
                max_groups = std::max(max_groups, 0);
                continue;
            }

            // To minimize handshakes for k groups, we should pick the k smallest groups.
            // This is because the number of handshakes is a convex function of the total number of people.
            // For a fixed number of groups, minimizing the total number of people minimizes handshakes.
            // The smallest groups have the fewest people.
            
            long long current_people = 0;
            for (int i = 0; i < k; ++i) {
                current_people += a[i];
            }

            if (calculate_handshakes(current_people) <= m) {
                max_groups = std::max(max_groups, k);
            }
        }
        std::cout << max_groups << "\n";
    }
    return 0;
}