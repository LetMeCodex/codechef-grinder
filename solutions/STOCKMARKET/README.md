# Chef and Stocks (STOCKMARKET)
- **Difficulty Rating**: 948
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to calculate the maximum possible profit Chef can achieve by trading stocks over $N$ days. On each day, Chef can either buy a stock at a certain price and sell it on a future day for a higher price, or do nothing. The profit for each day is given. Chef must choose to *not* trade on exactly one day. The goal is to maximize the total profit from the days Chef *does* trade.

## Intuition & Mathematical Observation
Chef wants to maximize the total profit. The total profit is the sum of profits from all days Chef chooses to trade. Since Chef must skip exactly one day, the total profit will be the sum of profits from all days *minus* the profit from the day Chef skips.

To maximize the total profit, Chef should minimize the profit lost from the skipped day. This means Chef should skip the day that yields the *minimum* profit. If a day has a negative profit (a loss), skipping that day would be beneficial. If all days have positive profits, skipping the day with the smallest positive profit will maximize the remaining sum.

Therefore, the strategy is to:
1. Calculate the sum of profits from all $N$ days.
2. Find the minimum profit among all $N$ days.
3. The maximum achievable profit is the total sum of profits minus the minimum profit.

A special case is when $N=1$. If there's only one day, Chef *must* skip it. In this scenario, no trades are made, and the profit is 0.

## Complexity Analysis
- **Time Complexity**: $O(N)$
    The code iterates through the $N$ days once to read the profits, calculate the total sum, and find the minimum profit. This takes linear time with respect to the number of days.

- **Space Complexity**: $O(1)$
    The solution uses a few variables to store the total sum, the minimum profit, and loop counters. The amount of memory used does not depend on the input size $N$.

## Solution Code
```cpp
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int n; // Number of days
        std::cin >> n;

        long long total_sum = 0;
        // Initialize min_val with a value larger than any possible A_i.
        // The problem constraints usually specify the range of A_i.
        // Assuming A_i can be up to 100, 101 is a safe initial maximum.
        long long min_val = 101;

        for (int i = 0; i < n; ++i) {
            long long current_profit;
            std::cin >> current_profit;
            total_sum += current_profit; // Accumulate total profit
            if (current_profit < min_val) {
                min_val = current_profit; // Update minimum profit found so far
            }
        }

        // Special case: If there's only one day, Chef must skip it, resulting in 0 profit.
        if (n == 1) {
            std::cout << 0 << "\n";
            continue;
        }

        // To maximize profit by skipping exactly one day, we should skip the day
        // with the minimum profit (or maximum loss).
        // The maximum profit will be the total sum of all profits minus the minimum profit.
        long long max_profit = total_sum - min_val;
        std::cout << max_profit << "\n";
    }
    return 0;
}
```