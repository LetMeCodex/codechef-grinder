#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int x, y, z;
        std::cin >> x >> y >> z;

        bool can_chicken = false;
        if (z % x == 0) {
            can_chicken = true;
        }

        bool can_duck = false;
        if (z % y == 0) {
            can_duck = true;
        }

        if (can_chicken && can_duck) {
            std::cout << "ANY\n";
        } else if (can_chicken) {
            std::cout << "CHICKEN\n";
        } else if (can_duck) {
            std::cout << "DUCK\n";
        } else {
            std::cout << "NONE\n";
        }
    }
    return 0;
}