#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> r(n);
    std::set<int> reported_to;

    for (int i = 0; i < n; ++i) {
        std::cin >> r[i];
        if (r[i] != 0) {
            reported_to.insert(r[i]);
        }
    }

    std::vector<int> potential_killers;
    for (int i = 1; i <= n; ++i) {
        if (reported_to.find(i) == reported_to.end()) {
            potential_killers.push_back(i);
        }
    }

    std::sort(potential_killers.begin(), potential_killers.end());

    for (size_t i = 0; i < potential_killers.size(); ++i) {
        std::cout << potential_killers[i] << (i == potential_killers.size() - 1 ? "" : " ");
    }
    std::cout << "\n";

    return 0;
}