#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int r1, r2, r3, r4, r5;
        std::cin >> r1 >> r2 >> r3 >> r4 >> r5;
        int liked_count = r1 + r2 + r3 + r4 + r5;
        if (liked_count >= 4) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}