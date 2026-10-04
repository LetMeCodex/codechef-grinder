#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int X, Y;
    std::cin >> X >> Y;
    if (X - Y >= 18) {
        std::cout << "RCB\n";
    } else {
        std::cout << "CSK\n";
    }
    return 0;
}