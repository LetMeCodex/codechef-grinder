#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int x, y, z;
        std::cin >> x >> y >> z;
        if (x > y && x > z) {
            std::cout << "Setter\n";
        } else if (y > x && y > z) {
            std::cout << "Tester\n";
        } else {
            std::cout << "Editorialist\n";
        }
    }
    return 0;
}