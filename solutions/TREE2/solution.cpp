#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::set<int> distinct_heights;
        for (int i = 0; i < n; ++i) {
            int a;
            std::cin >> a;
            if (a > 0) {
                distinct_heights.insert(a);
            }
        }
        std::cout << distinct_heights.size() << "\n";
    }
    return 0;
}