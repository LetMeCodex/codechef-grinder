# [Chef and Icecream (CHFICRM)](https://www.codechef.com/problems/CHFICRM)
- **Difficulty Rating**: 1269
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a chef can successfully sell ice cream to `N` customers. Each ice cream costs 5 rupees. Customers pay with coins of 5, 10, or 15 rupees. The chef starts with no money and must always be able to give exact change to every customer. We need to output "YES" if the chef can serve all customers, and "NO" otherwise.

## Intuition & Mathematical Observation

The core of this problem lies in managing the change available to the chef. The ice cream costs 5 rupees, so the chef needs to provide change if a customer pays with a 10 or 15 rupee coin.

Let's analyze the transactions:

1.  **Customer pays 5 rupees**:
    *   No change is required.
    *   The chef gains a 5 rupee coin.
    *   This is always possible.

2.  **Customer pays 10 rupees**:
    *   The chef needs to give 5 rupees change.
    *   This requires the chef to have at least one 5 rupee coin.
    *   If the chef has a 5 rupee coin: Give one 5 rupee coin, gain one 10 rupee coin.
    *   If the chef does not have a 5 rupee coin: It's impossible to give change.

3.  **Customer pays 15 rupees**:
    *   The chef needs to give 10 rupees change.
    *   This can be done in two ways:
        *   **Option A**: Give one 10 rupee coin. This requires the chef to have at least one 10 rupee coin.
        *   **Option B**: Give two 5 rupee coins. This requires the chef to have at least two 5 rupee coins.
    *   **Greedy Strategy**: When both options are available, which one should the chef prioritize? Using a 10 rupee coin (Option A) is generally better because 5 rupee coins are more versatile. They can be used for 5 rupee change (for a 10 rupee payment) or as part of 10 rupee change (for a 15 rupee payment). A 10 rupee coin can only be used for 10 rupee change. By preserving 5 rupee coins, we maximize our flexibility for future transactions. Therefore, the chef should prioritize giving a 10 rupee coin if available. If not, then use two 5 rupee coins.
    *   If neither a 10 rupee coin nor two 5 rupee coins are available: It's impossible to give change.

Based on these observations, we only need to keep track of the number of 5 rupee coins (`count5`) and 10 rupee coins (`count10`) the chef possesses. 15 rupee coins received are not useful for giving change, so we don't need to count them.

We iterate through each customer's payment. If at any point the chef cannot provide the correct change, we immediately know it's impossible for the entire sequence, and we can output "NO". If all customers are served successfully, we output "YES".

The provided solution implements this exact greedy strategy. The `possible` boolean flag tracks the feasibility, and the inner loops to consume remaining input are an optimization to prevent Time Limit Exceeded (TLE) errors on large test cases once `possible` becomes false.

## Complexity Analysis

-   **Time Complexity**: $O(N)$ per test case.
    The solution iterates through `N` customers for each test case. Inside the loop, all operations (incrementing/decrementing counters, comparisons) are constant time. In the worst case, if `possible` becomes false, the code still iterates through the remaining `N-i-1` inputs to consume them, ensuring that the total operations for a single test case remain proportional to `N`. If there are `T` test cases, the total time complexity is $O(T \cdot N)$.

-   **Space Complexity**: $O(1)$.
    The solution uses a fixed number of integer variables (`t`, `n`, `count5`, `count10`, `possible`, `coin`, `i`, `j`, `dummy`) regardless of the input size `N`. These variables consume a constant amount of memory.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <numeric>

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) { // Loop through each test case
        int n; // Number of customers
        std::cin >> n;

        int count5 = 0;  // Number of 5 rupee coins the chef has
        int count10 = 0; // Number of 10 rupee coins the chef has
        bool possible = true; // Flag to track if it's possible to serve all customers

        for (int i = 0; i < n; ++i) {
            int coin; // Coin paid by the current customer
            std::cin >> coin;

            if (coin == 5) {
                // Customer pays 5, no change needed. Chef gains a 5 rupee coin.
                count5++;
            } else if (coin == 10) {
                // Customer pays 10, needs 5 rupees change.
                if (count5 > 0) {
                    // If chef has a 5 rupee coin, give it as change.
                    count5--;
                    count10++; // Chef gains a 10 rupee coin.
                } else {
                    // Chef doesn't have a 5 rupee coin, cannot give change.
                    possible = false;
                    // Consume remaining input for this test case to avoid TLE.
                    for (int j = i + 1; j < n; ++j) {
                        int dummy;
                        std::cin >> dummy;
                    }
                    break; // No need to process further customers for this test case.
                }
            } else if (coin == 15) { // coin == 15
                // Customer pays 15, needs 10 rupees change.
                // Prioritize using a 10 rupee coin if available.
                if (count10 > 0) {
                    count10--; // Give one 10 rupee coin.
                    // Chef gains a 15 rupee coin, which is not useful for change, so we don't track it.
                } else if (count5 >= 2) {
                    // If no 10 rupee coin, use two 5 rupee coins if available.
                    count5 -= 2; // Give two 5 rupee coins.
                } else {
                    // Chef doesn't have a 10 rupee coin or two 5 rupee coins, cannot give change.
                    possible = false;
                    // Consume remaining input for this test case to avoid TLE.
                    for (int j = i + 1; j < n; ++j) {
                        int dummy;
                        std::cin >> dummy;
                    }
                    break; // No need to process further customers for this test case.
                }
            }
        }

        // After processing all customers (or breaking early if impossible)
        if (possible) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0; // Indicate successful execution
}

```