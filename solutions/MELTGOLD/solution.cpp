#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int x, y;
        std::cin >> x >> y;
        int current_temp = y;
        int minutes = 0;
        while (current_temp < x) {
            minutes++;
            current_temp += minutes;
        }
        std::cout << minutes << "\n";
    }
    return 0;
}