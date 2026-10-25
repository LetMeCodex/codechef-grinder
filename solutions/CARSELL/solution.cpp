#include <iostream>
#include <vector>
#include <algorithm> // For std::sort

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        int n;
        std::cin >> n; // Read the number of cars

        // Use a vector to store initial prices
        std::vector<long long> p_values(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> p_values[i];
        }

        // Sort prices in descending order.
        // std::sort with reverse iterators (rbegin(), rend()) sorts in descending order.
        std::sort(p_values.rbegin(), p_values.rend()); 

        long long total_profit = 0;
        const long long MOD = 1000000007; // Modulo constant

        // Iterate through the sorted prices, selling one car per year.
        // 'year' represents the number of years passed since the start (0-indexed).
        // The car sold in 'year' k (0-indexed) depreciates by k units.
        for (int year = 0; year < n; ++year) {
            // The current car to sell is the one with the highest remaining initial price.
            // This is p_values[year] after sorting in descending order.
            long long current_initial_price = p_values[year];

            // Calculate the selling price after depreciation.
            // Price cannot drop below 0.
            long long current_price = current_initial_price - year;

            if (current_price > 0) {
                // Add positive profit to total_profit, applying modulo.
                total_profit = (total_profit + current_price) % MOD;
            } else {
                // Optimization: If the current car (which has the highest remaining initial price)
                // yields 0 or negative profit, all subsequent cars will also yield 0 or negative profit
                // because their initial prices are less than or equal, and the 'year' (depreciation)
                // value only increases. So, we can stop.
                break;
            }
        }
        std::cout << total_profit << "\n"; // Print the maximum profit for the test case
    }
    return 0;
}