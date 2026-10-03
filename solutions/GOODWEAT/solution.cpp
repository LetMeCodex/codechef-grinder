#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int sunny_days = 0;
        int rainy_days = 0;
        for (int i = 0; i < 7; ++i) {
            int day_type;
            std::cin >> day_type;
            if (day_type == 1) {
                sunny_days++;
            } else {
                rainy_days++;
            }
        }
        if (sunny_days > rainy_days) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}