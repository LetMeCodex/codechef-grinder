#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int x, y;
        std::cin >> x >> y;
        if (x < 50) {
            std::cout << "Z\n";
        } else {
            if (y < 50) {
                std::cout << "F\n";
            } else {
                std::cout << "A\n";
            }
        }
    }
    return 0;
}