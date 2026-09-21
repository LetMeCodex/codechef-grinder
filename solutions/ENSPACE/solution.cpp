#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n, x, y;
        std::cin >> n >> x >> y;
        long long total_size = (long long)x * 1 + (long long)y * 2;
        if (total_size <= n) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}