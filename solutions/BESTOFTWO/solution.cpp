#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int x, y;
        std::cin >> x >> y;
        std::cout << std::max(x, y) << "\n";
    }
    return 0;
}