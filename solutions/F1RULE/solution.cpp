#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int x, y;
        std::cin >> x >> y;
        // The 107% rule means Chef's time (Y) must be less than or equal to 107% of the fastest time (X).
        // Mathematically, this is Y <= X * 1.07
        // To avoid floating-point precision issues, we can rewrite this as:
        // Y * 100 <= X * 107
        if (y * 100 <= x * 107) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}