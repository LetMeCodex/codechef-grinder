#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        long long r1, r2, r3;
        std::cin >> r1 >> r2 >> r3;
        if (r1 > r2 + r3 || r2 > r1 + r3 || r3 > r1 + r2) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }
    return 0;
}