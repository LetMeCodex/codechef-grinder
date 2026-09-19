#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n, x, y;
        std::cin >> n >> x >> y;
        // Chef can achieve exactly Y marks if Y is a multiple of X,
        // and the number of problems contributing to Y (i.e., Y/X)
        // is less than or equal to the total number of problems N.
        // If Y is 0, it's always possible by scoring 0 in all problems.
        if (y == 0) {
            std::cout << "YES\n";
        } else if (y % x == 0) {
            int problems_needed = y / x;
            if (problems_needed <= n) {
                std::cout << "YES\n";
            } else {
                std::cout << "NO\n";
            }
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}