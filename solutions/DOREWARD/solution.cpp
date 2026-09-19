#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int x;
        std::cin >> x;
        if (x <= 3) {
            std::cout << "BRONZE\n";
        } else if (x > 3 && x <= 6) {
            std::cout << "SILVER\n";
        } else { // x > 6
            std::cout << "GOLD\n";
        }
    }
    return 0;
}