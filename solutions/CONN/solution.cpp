#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        bool possible = false;
        // We want to find non-negative integers X and Y such that 2*X + 7*Y = N.
        // This is equivalent to checking if N - 7*Y is a non-negative even number
        // for some non-negative integer Y.
        // We can iterate through possible values of Y.
        // Since 7*Y must be less than or equal to N, the maximum value of Y is N/7.
        for (int y = 0; y * 7 <= n; ++y) {
            int remaining = n - y * 7;
            // If the remaining part is non-negative and even, then it can be represented as 2*X.
            if (remaining >= 0 && remaining % 2 == 0) {
                possible = true;
                break;
            }
        }
        if (possible) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}