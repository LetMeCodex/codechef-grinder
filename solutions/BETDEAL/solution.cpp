#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int a, b;
        std::cin >> a >> b;

        // Calculate the price after discount for the first store
        // Original price = 100
        // Discount = A%
        // Price after discount = 100 * (100 - A) / 100 = 100 - A
        double price1 = 100.0 * (100.0 - a) / 100.0;

        // Calculate the price after discount for the second store
        // Original price = 200
        // Discount = B%
        // Price after discount = 200 * (100 - B) / 100 = 2 * (100 - B) = 200 - 2*B
        double price2 = 200.0 * (100.0 - b) / 100.0;

        if (price1 < price2) {
            std::cout << "FIRST\n";
        } else if (price2 < price1) {
            std::cout << "SECOND\n";
        } else {
            std::cout << "BOTH\n";
        }
    }
    return 0;
}