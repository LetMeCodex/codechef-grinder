# [Expensive Buying (BUYING7)](https://www.codechef.com/problems/BUYING7)
- **Difficulty Rating**: 635
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to select exactly `K` items out of `N` available items. Each item `i` has a specific cost `c_i`. Our goal is to maximize the total cost of the `K` selected items. We need to output this maximum possible total cost.

## Intuition & Mathematical Observation

To maximize the sum of `K` items chosen from a larger set of `N` items, the most straightforward and optimal strategy is to always pick the `K` items that have the highest individual costs.

Consider any set of `K` items. If this set does not include one of the top `K` most expensive items, it must include an item that is *not* among the top `K` most expensive. In this scenario, we could replace that less expensive item with one of the top `K` most expensive items (which we initially didn't pick). This replacement would either increase the total sum or keep it the same (if the replaced item had the same cost as the one we picked). By repeatedly applying this logic, we can always arrive at a state where we have picked the `K` most expensive items, and this configuration will yield the maximum possible total cost.

Therefore, the approach is:
1. Read all `N` item costs.
2. Sort these costs in descending order.
3. Sum the first `K` costs from the sorted list. This sum will be our maximum total cost.

## Complexity Analysis

-   **Time Complexity**:
    *   Reading `N` integers: $O(N)$
    *   Sorting the `N` integers: `std::sort` typically uses an IntroSort-like algorithm, which has an average and worst-case time complexity of $O(N \log N)$. Sorting in reverse order doesn't change this complexity.
    *   Summing the top `K` integers: $O(K)$
    *   The dominant operation among these is sorting.
    *   Thus, the overall time complexity is $\mathbf{O(N \log N)}$.

-   **Space Complexity**:
    *   Storing `N` integers in a `std::vector`: $O(N)$
    *   No other significant auxiliary data structures are used that depend on `N` or `K`.
    *   Thus, the overall space complexity is $\mathbf{O(N)}$.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // For std::sort
#include <numeric>   // Not strictly needed for this solution, but often useful for sums

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        int n, k;
        std::cin >> n >> k; // Read N (number of items) and K (items to select)

        std::vector<int> c(n); // Create a vector to store the costs of N items
        for (int i = 0; i < n; ++i) {
            std::cin >> c[i]; // Read each item's cost
        }

        // Sort the prices in descending order.
        // c.rbegin() and c.rend() provide reverse iterators,
        // so std::sort sorts the elements from largest to smallest.
        std::sort(c.rbegin(), c.rend());

        // Sum the top K prices.
        // Use long long for total_cost to prevent potential overflow,
        // as N and individual costs can be large (e.g., N=10^5, cost=10^9, K=N, total_cost could be 10^14).
        long long total_cost = 0;
        for (int i = 0; i < k; ++i) {
            total_cost += c[i]; // Add the i-th most expensive item's cost
        }
        std::cout << total_cost << "\n"; // Print the maximum total cost
    }
    return 0; // Indicate successful execution
}

```