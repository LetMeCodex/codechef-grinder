#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int x;
        std::cin >> x;
        while (x > 3) {
            if (x % 2 == 0) {
                x /= 2;
            } else {
                x -= 3;
            }
        }
        // After the loop, x will be 1, 2, or 3.
        // If x is 1, it's already minimum.
        // If x is 2, it can be divided by 2 to become 1.
        // If x is 3, it cannot be reduced further.
        if (x == 2) {
            std::cout << 1 << "\n";
        } else {
            std::cout << x << "\n";
        }
    }
    return 0;
}