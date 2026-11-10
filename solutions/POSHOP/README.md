# [Posh Shopping (POSHOP)](https://www.codechef.com/problems/POSHOP)
- **Difficulty Rating**: 773
- **Solved in**: 2 attempt(s)

## Problem Summary

Chef wants to buy items from a shop. There are $N$ items, and the $i$-th item has a cost $C_i$. Chef has two options for buying:
1. Buy exactly one item.
2. Buy exactly two items, say item $k$ and item $i$. This option is only valid if $k < i$ (item $k$ appears before item $i$ in the input list) AND $C_k \le C_i$ (the cost of item $k$ is less than or equal to the cost of item $i$).

Chef wants to maximize the total amount of money spent. The task is to find this maximum possible amount.

## Intuition & Mathematical Observation

The problem asks us to find the maximum possible sum, which can be either a single item's cost or the sum of two items' costs under specific conditions. Let's analyze the conditions:

1.  **Buying one item**: The maximum amount spent would simply be the maximum $C_i$ among all items. This is a straightforward case.

2.  **Buying two items**: If Chef buys item $k$ and item $i$, two conditions must be met:
    *   $k < i$: Item $k$ must appear before item $i$ in the input sequence.
    *   $C_k \le C_i$: The cost of item $k$ must be less than or equal to the cost of item $i$.

    To maximize the sum $C_k + C_i$, for a fixed item $i$ (which is the second item bought), we need to find the largest possible $C_k$ that satisfies both conditions from all items $k$ that appeared *before* $i$.

This suggests an iterative approach: we can process the items one by one from left to right (from $i=0$ to $N-1$). As we iterate through item $i$:

*   **Update maximum for single item purchase**: We immediately consider $C_i$ as a potential maximum amount spent (if Chef buys only this item).
*   **Update maximum for two item purchase**: We need to look back at all items $k$ that we have already processed (i.e., $k < i$). Among these, we want to find the one with the largest cost $C_k$ such that $C_k \le C_i$. If such a $C_k$ exists, then $C_k + C_i$ is a candidate for the maximum amount spent.

To efficiently find the largest $C_k$ (where $k < i$ and $C_k \le C_i$), we can use a data structure that stores the costs of items encountered so far in a sorted manner and allows for quick searching. A `std::set` in C++ is ideal for this.

**Algorithm using `std::set`:**

1.  Initialize `max_spent = 0`.
2.  Create an empty `std::set<int> seen_costs`. This set will store the costs $C_k$ of all items $k$ processed so far (where $k < i$).
3.  Iterate through the items from $i = 0$ to $N-1$:
    a.  **Consider buying only item $i$**: Update `max_spent = std::max(max_spent, C[i])`.
    b.  **Consider buying two items (item $k$ and item $i$)**:
        *   Use `seen_costs.upper_bound(C[i])` to find an iterator to the first element in `seen_costs` that is *strictly greater* than $C_i$.
        *   If this iterator is not `seen_costs.begin()`, it means there are elements in `seen_costs` that are less than or equal to $C_i$.
        *   Decrementing the iterator (`--it`) will make it point to the largest element in `seen_costs` that is less than or equal to $C_i$. Let this element be `*it`. This `*it` is our desired $C_k$.
        *   Update `max_spent = std::max(max_spent, C[i] + *it)`.
    c.  **Add current item's cost to `seen_costs`**: Insert $C_i$ into `seen_costs` so it can be considered as $C_k$ for future items $j > i$.

After iterating through all items, `max_spent` will hold the maximum amount Chef can spend.

## Complexity Analysis

*   **Time Complexity**:
    *   Reading $N$ and the $N$ item costs: $O(N)$.
    *   The main loop runs $N$ times (for each item $i$).
    *   Inside the loop:
        *   `std::max` operations take $O(1)$.
        *   `seen_costs.upper_bound(C[i])`: In a `std::set` of size up to $i$, this operation takes $O(\log i)$ time.
        *   `seen_costs.insert(C[i])`: In a `std::set` of size up to $i$, this operation also takes $O(\log i)$ time.
    *   Therefore, the total time complexity for one test case is $\sum_{i=0}^{N-1} O(\log i) = O(N \log N)$.
    *   Given $T$ test cases, the total time complexity is $O(T \cdot N \log N)$.

*   **Space Complexity**:
    *   `std::vector<int> C(N)`: Stores the costs of $N$ items, requiring $O(N)$ space.
    *   `std::set<int> seen_costs`: In the worst case, all $N$ item costs are distinct and are inserted into the set. This requires $O(N)$ space.
    *   The total space complexity is $O(N)$.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <set> // Required for std::set

void solve() {
    int N;
    std::cin >> N; // Read N, the number of items
    std::vector<int> C(N); // Declare a vector to store item costs
    for (int i = 0; i < N; ++i) {
        std::cin >> C[i]; // Read item costs into the vector
    }

    int max_spent = 0; // Initialize max_spent to 0, as costs are non-negative

    // We use a std::set to store costs of items encountered so far (C[k] for k < i).
    // A set keeps elements sorted and allows efficient searching (upper_bound) and insertion.
    std::set<int> seen_costs;

    // Iterate through each item, considering it as the potential 'second' item (item i)
    // or a single item purchase.
    for (int i = 0; i < N; ++i) {
        // Case 1: Chef buys only one item (item i).
        // Update max_spent if the current item's cost is higher than previously found maximum.
        max_spent = std::max(max_spent, C[i]);

        // Case 2: Chef buys two items, with item i being the second item.
        // We need to find a previous item k (k < i) such that C[k] <= C[i].
        // To maximize C[k] + C[i], we need the largest C[k] that satisfies C[k] <= C[i].
        // `seen_costs` contains all C[k] for k < i.
        
        // `upper_bound(C[i])` returns an iterator to the first element in `seen_costs`
        // that is strictly greater than C[i].
        auto it = seen_costs.upper_bound(C[i]);

        // If `it` is not `seen_costs.begin()`, it means there is at least one element
        // in `seen_costs` that is less than or equal to C[i].
        if (it != seen_costs.begin()) {
            // Move `it` back one position. It now points to the largest element
            // in `seen_costs` that is less than or equal to C[i]. This is our C[k].
            --it;
            // Update max_spent with the sum of C[i] and the found C[k].
            max_spent = std::max(max_spent, C[i] + *it);
        }

        // Add the current item's cost to the set for future iterations.
        // This C[i] can now be a C[k] for any item j > i.
        seen_costs.insert(C[i]);
    }

    std::cout << max_spent << "\n"; // Output the maximum amount Chef can spend
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Solve the current test case
    }

    return 0; // Indicate successful execution
}
```