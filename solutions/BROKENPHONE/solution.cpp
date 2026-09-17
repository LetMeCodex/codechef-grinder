#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int x, y;
        std::cin >> x >> y;
        if (x < y) {
            std::cout << "REPAIR\n";
        } else if (x > y) {
            std::cout << "NEW PHONE\n";
        } else {
            std::cout << "ANY\n";
        }
    }
    return 0;
}