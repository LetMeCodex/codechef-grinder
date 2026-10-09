#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int m, h;
        std::cin >> m >> h;
        int bmi = m / (h * h);
        if (bmi <= 18) {
            std::cout << 1 << "\n";
        } else if (bmi >= 19 && bmi <= 24) {
            std::cout << 2 << "\n";
        } else if (bmi >= 25 && bmi <= 29) {
            std::cout << 3 << "\n";
        } else {
            std::cout << 4 << "\n";
        }
    }
    return 0;
}