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
        std::vector<int> a(n);
        int max_degree = -1;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            if (a[i] != 0) {
                max_degree = i;
            }
        }
        std::cout << max_degree << "\n";
    }
    return 0;
}