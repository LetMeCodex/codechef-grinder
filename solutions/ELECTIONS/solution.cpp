#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int xa, xb, xc;
        std::cin >> xa >> xb >> xc;
        if (xa > 50) {
            std::cout << "A\n";
        } else if (xb > 50) {
            std::cout << "B\n";
        } else if (xc > 50) {
            std::cout << "C\n";
        } else {
            std::cout << "NOTA\n";
        }
    }
    return 0;
}