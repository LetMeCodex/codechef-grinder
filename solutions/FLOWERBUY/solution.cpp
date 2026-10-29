#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        // We want to find the minimum cost to buy exactly N flowers.
        // We have two options:
        // 1. Buy 2 flowers for 4 coins. Cost per flower: 4/2 = 2.
        // 2. Buy 3 flowers for 5 coins. Cost per flower: 5/3 ≈ 1.67.
        // The second option is generally cheaper per flower.

        // Let x be the number of times we use the (2 flowers, 4 coins) option.
        // Let y be the number of times we use the (3 flowers, 5 coins) option.
        // We need to find non-negative integers x and y such that:
        // 2*x + 3*y = N
        // and we want to minimize the total cost: 4*x + 5*y.

        // Since N is small (up to 100), we can iterate through possible values of y.
        // The maximum number of times we can use the (3 flowers, 5 coins) option
        // is when 3*y <= N. So, y can range from 0 to N/3.

        int min_cost = -1; // Initialize with an invalid value

        for (int y = 0; y * 3 <= n; ++y) {
            int remaining_flowers = n - (y * 3);
            // If the remaining flowers can be formed by buying 2 flowers at a time
            if (remaining_flowers >= 0 && remaining_flowers % 2 == 0) {
                int x = remaining_flowers / 2;
                int current_cost = (x * 4) + (y * 5);
                if (min_cost == -1 || current_cost < min_cost) {
                    min_cost = current_cost;
                }
            }
        }
        std::cout << min_cost << "\n";
    }
    return 0;
}