# [Chef and Price Control (PRICECON)](https://www.codechef.com/problems/PRICECON)
- **Difficulty Rating**: 931
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the total "lost revenue" for a shop owner due to a price control policy. The owner has `N` items, each with an original price `P_i`. A price control threshold `K` is imposed. If an item's original price `P_i` is greater than `K`, it must be sold at `K`. This means the shop owner loses `P_i - K` dollars for that specific item. If `P_i` is less than or equal to `K`, no revenue is lost for that item. We need to find the sum of all such lost revenues across all `N` items. This process needs to be repeated for `T` test cases.

## Intuition & Mathematical Observation

The problem statement directly defines how to calculate the lost revenue for each item:
*   If `P_i > K`, the lost revenue for this item is `P_i - K`.
*   If `P_i <= K`, the lost revenue for this item is `0`.

Our goal is to find the *total* lost revenue. This means we need to iterate through all `N` items, apply the rule above for each item's price `P_i`, and accumulate the individual lost revenues into a running total.

The approach is straightforward:
1. Initialize a variable, say `total_lost_revenue`, to `0`.
2. For each of the `N` items:
    a. Read its price `P`.
    b. Check if `P` is greater than `K`.
    c. If `P > K`, add `(P - K)` to `total_lost_revenue`.
    d. If `P <= K`, do nothing (effectively adding `0`).
3. After iterating through all `N` items, `total_lost_revenue` will hold the final answer for the current test case.

The maximum possible price `P` is $10^9$, and `K` can also be up to $10^9$. The difference `P - K` can be up to $10^9$. With `N` up to $10^5$, the total lost revenue can be up to $10^5 \times 10^9 = 10^{14}$. This value exceeds the capacity of a standard `int` (which typically goes up to $2 \times 10^9$), so we must use a `long long` data type for `total_lost_revenue` and potentially for `P` and `K` to avoid overflow.

## Complexity Analysis

-   **Time Complexity**: $O(N)$ per test case.
    *   For each test case, we read `N` and `K` (constant time).
    *   We then loop `N` times. Inside the loop, we read an integer `P`, perform a comparison, a subtraction, and an addition. All these operations are constant time.
    *   Therefore, the total time complexity for one test case is directly proportional to `N`.
    *   Given `T` test cases, the overall time complexity would be $O(\sum N)$ across all test cases. With `N` up to $10^5$ and `T` up to $100$, and the sum of `N` over all test cases up to $10^5$, this approach is very efficient.

-   **Space Complexity**: $O(1)$.
    *   The solution uses a fixed number of variables (`t`, `n`, `k`, `lost_revenue`, `p`) regardless of the input size `N`.
    *   No arrays or dynamic data structures are used to store the prices; they are processed one by one.
    *   Thus, the memory usage remains constant.

## Solution Code

```cpp
#include <iostream> // Required for input/output operations (std::cin, std::cout)
#include <vector>   // Not strictly needed for this solution, but often included
#include <numeric>  // Not strictly needed for this solution, but often included

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Variable to store the number of test cases
    std::cin >> t; // Read the number of test cases

    while (t--) { // Loop through each test case
        int n;       // Variable to store the number of items
        long long k; // Variable to store the price control threshold (use long long for safety)
        std::cin >> n >> k; // Read N and K for the current test case

        long long lost_revenue = 0; // Initialize total lost revenue for this test case (use long long)

        // Loop N times to process each item's price
        for (int i = 0; i < n; ++i) {
            long long p; // Variable to store the current item's price (use long long for safety)
            std::cin >> p; // Read the item's price

            // Check if the item's price exceeds the threshold K
            if (p > k) {
                // If it does, calculate the lost revenue for this item and add it to the total
                lost_revenue += (p - k);
            }
        }
        // Output the total lost revenue for the current test case, followed by a newline
        std::cout << lost_revenue << "\n";
    }

    return 0; // Indicate successful program execution
}

```