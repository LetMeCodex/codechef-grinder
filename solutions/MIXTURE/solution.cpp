#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int a, b;
        std::cin >> a >> b;
        if (a > 0 && b > 0) {
            std::cout << "Solution\n";
        } else if (b == 0) {
            std::cout << "Solid\n";
        } else if (a == 0) {
            std::cout << "Liquid\n";
        }
    }
    return 0;
}