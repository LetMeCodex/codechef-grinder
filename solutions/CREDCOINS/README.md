# [CRED Coins (CREDCOINS)](https://www.codechef.com/problems/CREDCOINS)
- **Difficulty Rating**: 539
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the maximum number of bags of CRED coins that can be purchased given the number of bills paid and the number of CRED coins earned per bill. Each bag of CRED coins costs 100 coins.

## Intuition & Mathematical Observation

The core of the problem lies in understanding how to calculate the total number of CRED coins earned and then determining how many bags can be bought with those coins.

1.  **Total CRED Coins Earned**: The problem states that for each bill paid, a user earns `y` CRED coins. If a user pays `x` bills, the total number of CRED coins earned is simply the product of the number of bills and the coins earned per bill.
    $$ \text{Total CRED Coins} = x \times y $$

2.  **Maximum Number of Bags**: Each bag of CRED coins costs 100 coins. To find the maximum number of bags that can be purchased, we need to divide the total CRED coins earned by the cost of one bag (100 coins). Since we can only buy whole bags, we are interested in the integer part of this division (floor division).
    $$ \text{Maximum Bags} = \lfloor \frac{\text{Total CRED Coins}}{100} \rfloor $$
    Substituting the expression for total CRED coins:
    $$ \text{Maximum Bags} = \lfloor \frac{x \times y}{100} \rfloor $$

The problem involves a simple multiplication and division. The input values `x` and `y` can be up to $10^9$, so their product can be up to $10^{18}$. This necessitates the use of a 64-bit integer type (like `long long` in C++) to store the total coins to avoid overflow.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The solution involves a fixed number of arithmetic operations (multiplication and division) regardless of the input size. Therefore, the time complexity is constant.

-   **Space Complexity**: $O(1)$
    The solution uses a fixed amount of memory to store a few variables (`t`, `x`, `y`, `total_coins`, `max_bags`). The memory usage does not grow with the input size. Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C stdio,
    // potentially speeding up I/O.
    // cin.tie(NULL) unties cin from cout, meaning cin operations
    // won't flush cout automatically, further speeding up I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Variable to store the number of test cases.
    cin >> t; // Read the number of test cases.

    // Loop through each test case.
    while (t--) {
        long long x, y; // Variables to store the number of bills and coins per bill.
                        // Using long long to handle potential large values up to 10^9.
        cin >> x >> y; // Read the input values for x and y.

        // Calculate the total CRED coins earned.
        // x (number of bills) * y (coins per bill)
        // The result can be up to 10^9 * 10^9 = 10^18, which fits in a long long.
        long long total_coins = x * y;

        // Each bag costs 100 CRED coins.
        // To find the maximum number of bags, we divide the total coins by 100.
        // Integer division in C++ automatically performs floor division for positive numbers.
        // For example, 150 / 100 = 1, and 200 / 100 = 2.
        long long max_bags = total_coins / 100;

        // Print the maximum number of bags that can be purchased, followed by a newline.
        cout << max_bags << "\n";
    }

    return 0; // Indicate successful program execution.
}
```