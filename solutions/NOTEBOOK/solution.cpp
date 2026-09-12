#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        // 1 kg of pulp makes 1000 pages.
        // 1 notebook consists of 100 pages.
        // So, 1 kg of pulp makes 1000 / 100 = 10 notebooks.
        // For N kgs of pulp, the number of notebooks is N * 10.
        long long notebooks = static_cast<long long>(n) * 10;
        std::cout << notebooks << "\n";
    }
    return 0;
}