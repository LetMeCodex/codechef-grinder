# [Chef and Street Food (STFOOD)](https://www.codechef.com/problems/STFOOD)
- **Difficulty Rating**: 1268
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef wants to open a street food stall. There are `N` different types of street food available. For each food type, Chef is given three pieces of information:
1.  `S`: The number of other existing stores that sell this particular food type.
2.  `P`: The total number of people who want to buy this food type.
3.  `V`: The profit Chef makes per person if they buy this food type from Chef.

When Chef opens a stall for a specific food type, the `P` people who want to buy that food type are divided equally among all stores selling it. This includes Chef's new store and the `S` existing stores. Chef wants to choose the food type that will yield the maximum possible profit. We need to output this maximum profit.

## Intuition & Mathematical Observation

The core of this problem lies in calculating the profit for each food type and then finding the maximum among them. Let's break down the calculation for a single food type:

1.  **Total Stores for a Food Type**: If there are `S` other stores selling a particular food type, and Chef decides to open one store for that same food type, the total number of stores selling that food type will be `S + 1`.

2.  **Customers for Chef's Store**: The `P` people who want to buy this food type are divided equally among all `S + 1` stores. Since customers must be whole numbers, Chef will get `P / (S + 1)` customers. In integer division (as in C++), this automatically performs a floor operation, which is appropriate here (e.g., if 10 people are divided among 3 stores, each store gets `floor(10/3) = 3` customers).

3.  **Profit for a Food Type**: Chef's profit for this specific food type is the number of customers Chef gets multiplied by the profit per person (`V`). So, the profit will be `(P / (S + 1)) * V`.

To solve the problem, we simply need to iterate through all `N` food types, calculate the profit for each using the formula derived above, and keep track of the maximum profit encountered.

## Complexity Analysis

-   **Time Complexity**: $O(N)$ per test case.
    -   For each test case, we iterate `N` times (once for each food type).
    -   Inside the loop, we perform a few constant-time operations: reading three integers, one addition, one division, one multiplication, and one comparison.
    -   Therefore, if there are `T` test cases, the total time complexity will be $O(T \cdot N)$. Given the constraints ($T \le 100$, $N \le 1000$), $100 \times 1000 = 10^5$ operations per test case, which is well within typical time limits.

-   **Space Complexity**: $O(1)$
    -   We only use a few variables to store `t`, `n`, `max_profit`, `s`, `p`, `v`, `chef_customers`, and `current_profit`. The amount of memory used does not depend on the input size `N`.

## Solution Code

```cpp
#include <iostream>
#include <algorithm> // Required for std::max, though a simple if condition works too

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin/cout from C's stdio and prevents synchronization.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) { // Loop through each test case
        int n; // Number of food types
        std::cin >> n;

        long long max_profit = 0; // Initialize maximum profit found so far to 0

        // Iterate through each of the N food types
        for (int i = 0; i < n; ++i) {
            long long s, p, v; // s: other stores, p: total people, v: profit per person
            std::cin >> s >> p >> v;

            // Chef's store is one additional store.
            // So, total stores for this food type will be s + 1.
            // Number of people buying from Chef is floor(p / (s + 1)).
            // Integer division in C++ automatically performs floor for positive numbers.
            long long chef_customers = p / (s + 1);

            // Calculate the current profit for this food type
            long long current_profit = chef_customers * v;

            // Update max_profit if the current food type yields a higher profit
            if (current_profit > max_profit) {
                max_profit = current_profit;
            }
            // Alternatively, using std::max: max_profit = std::max(max_profit, current_profit);
        }
        // Output the maximum profit for the current test case
        std::cout << max_profit << "\n";
    }
    return 0; // Indicate successful execution
}

```