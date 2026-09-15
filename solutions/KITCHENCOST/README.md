# [Cost of Groceries (KITCHENCOST)](https://www.codechef.com/problems/KITCHENCOST)
- **Difficulty Rating**: 799
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to calculate the total cost of groceries that a chef will buy. The chef has a list of `n` items. For each item, we are given its `freshness` value and its `cost`. The chef will only buy an item if its `freshness` value is greater than or equal to a given threshold `x`. We need to sum up the costs of all such items.

## Intuition & Mathematical Observation
The problem statement is quite direct. We are given a set of items, each with a property (freshness) and a value (cost). We have a condition based on the property, and we need to sum the values of items that satisfy the condition.

The core logic is to iterate through each item. For each item, we check if its freshness value meets the minimum requirement `x`. If it does, we add its cost to a running total. After checking all items, this running total will be our final answer.

Mathematically, if we have `n` items, where the `i`-th item has freshness `a[i]` and cost `b[i]`, and the freshness threshold is `x`, the total cost `C` can be expressed as:

$C = \sum_{i=0}^{n-1} b[i] \quad \text{if } a[i] \ge x$

This translates directly into a simple loop and conditional check.

## Complexity Analysis
- **Time Complexity**: $O(N)$
  The solution involves iterating through the `n` items once. For each item, we perform a constant number of operations (a comparison and potentially an addition). Therefore, the time complexity is directly proportional to the number of items, `n`.

- **Space Complexity**: $O(1)$ (excluding input storage)
  The solution uses a single variable `total_cost` to accumulate the sum. This variable's space requirement is constant, regardless of the input size `n`. The input arrays `a` and `b` take $O(N)$ space, but this is considered input storage and not auxiliary space used by the algorithm itself. If we consider the space for input, it would be $O(N)$.

## Solution Code

```cpp
#include <iostream>
#include <vector>
// The <numeric> header is not strictly necessary for this problem's logic.

class Solution {
public:
    /**
     * @brief Computes the total cost of groceries based on freshness threshold.
     *
     * @param n The number of grocery items.
     * @param x The minimum freshness value required to purchase an item.
     * @param a A vector containing the freshness values of the items.
     * @param b A vector containing the costs of the items.
     * @return The total cost of items whose freshness is greater than or equal to x.
     */
    long long compute(int n, int x, const std::vector<int>& a, const std::vector<int>& b) {
        long long total_cost = 0; // Use long long to prevent potential overflow for large sums.
        for (int i = 0; i < n; ++i) {
            // Chef purchases items with freshness value greater than or equal to X.
            if (a[i] >= x) {
                total_cost += b[i];
            }
        }
        return total_cost;
    }
};

// The platform will provide its own main function, similar to this (hypothetical example):
/*
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n, x;
        std::cin >> n >> x;
        std::vector<int> a(n);
        std::vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            std::cin >> b[i];
        }

        Solution s;
        std::cout << s.compute(n, x, a, b) << "\n";
    }
    return 0;
}
*/
```