#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int x1, x2, y1, y2, z1, z2;
        std::cin >> x1 >> x2 >> y1 >> y2 >> z1 >> z2;
        if (x2 >= x1 && y2 >= y1 && z2 <= z1) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}