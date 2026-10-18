#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::map<int, int> counts;
        for (int i = 0; i < n; ++i) {
            int a;
            std::cin >> a;
            counts[a]++;
        }

        std::vector<int> sides;
        for (auto const& [length, count] : counts) {
            if (count >= 2) {
                sides.push_back(length);
                if (count >= 4) {
                    sides.push_back(length);
                }
            }
        }

        std::sort(sides.rbegin(), sides.rend());

        if (sides.size() < 2) {
            std::cout << -1 << "\n";
        } else {
            long long max_area = (long long)sides[0] * sides[1];
            std::cout << max_area << "\n";
        }
    }
    return 0;
}