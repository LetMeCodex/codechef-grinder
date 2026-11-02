# [Reselling Items (RESELL)](https://www.codechef.com/problems/RESELL)
- **Difficulty Rating**: 903
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef has `N` items, and the resell price for each item `i` is `A_i`. Chef wants to buy and resell some of these items to maximize profit. Chef has a special offer: the first `K` items he buys will cost 5 coins each. Any subsequent items (beyond the first `K`) will cost 10 coins each. Chef will only buy an item if reselling it yields a positive profit. We need to find the maximum total profit Chef can make.

## Intuition & Mathematical Observation

The core idea to maximize profit is to apply the cheaper buying price (5 coins) to the items that have the highest potential resell value, and thus the highest potential profit.

Let's break down the strategy:

1.  **Prioritize High Resell Prices**: To maximize `(Resell Price - Cost)`, we should always aim for items with higher `Resell Price`.
2.  **Discounted Items (Cost 5)**: Chef can buy `K` items at 5 coins each. To get the most out of this discount, these `K` items should be the ones with the absolute highest resell prices among all `N` items. This is because `A_i - 5` will be maximized when `A_i` is largest.
3.  **Regular Items (Cost 10)**: After selecting the `K` most expensive items for the discount, the remaining `N-K` items will be considered for purchase at 10 coins each. Again, to maximize profit, Chef should consider the items with the highest resell prices among these remaining `N-K` items.
4.  **Profit Condition**: Chef only buys an item if it yields a positive profit.
    *   For a discounted item (cost 5): `A_i - 5 > 0`, which means `A_i > 5`.
    *   For a regular item (cost 10): `A_i - 10 > 0`, which means `A_i > 10`.

Based on these observations, a greedy approach works perfectly:

*   First, sort all item resell prices `A_i` in **descending order**. This places the most valuable items at the beginning of the list.
*   Then, iterate through the first `K` items in this sorted list. For each item `A[i]`, calculate its profit as `A[i] - 5`. If this profit is positive, add it to the total.
*   Next, iterate through the remaining `N-K` items (from index `K` to `N-1`) in the sorted list. For each item `A[i]`, calculate its profit as `A[i] - 10`. If this profit is positive, add it to the total.

This strategy ensures that the cheapest buying price is always applied to the items that can generate the most profit, leading to the maximum possible total profit.

## Complexity Analysis

*   **Time Complexity**:
    *   Reading `N` and `K`: $O(1)$
    *   Reading `N` item prices into a vector: $O(N)$
    *   Sorting the vector `A` in descending order: $O(N \log N)$ (using `std::sort`)
    *   Iterating through the first `K` items: $O(K)$
    *   Iterating through the remaining `N-K` items: $O(N-K)$
    *   The dominant operation is sorting. Therefore, the total time complexity is $O(N \log N)$.

*   **Space Complexity**:
    *   Storing the `N` item prices in a vector `A`: $O(N)$
    *   Other variables (`N`, `K`, `total_profit`, loop counters): $O(1)$
    *   The total space complexity is $O(N)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, vector, algorithm, functional etc.

// It's generally good practice to avoid 'using namespace std;' in headers or large projects
// but for competitive programming, it's standard and accepted.
using namespace std; 

void solve() {
    int N, K;
    cin >> N >> K; // Read N (total items) and K (discounted items count)

    vector<int> A(N); // Declare a vector of size N to store item resell prices
    for (int i = 0; i < N; ++i) {
        cin >> A[i]; // Read each item's resell price
    }

    // Sort the array A in descending order.
    // This ensures that items with higher resell prices (A_i) are considered first.
    // std::greater<int>() is a comparator that makes std::sort sort in descending order.
    sort(A.begin(), A.end(), greater<int>());

    long long total_profit = 0; // Initialize total profit. Use long long to be safe, though int is sufficient here.

    // Chef can buy the first K items at a cost of 5 coins each.
    // These are the K items with the highest resell prices due to sorting.
    for (int i = 0; i < K; ++i) {
        // An item is bought only if it yields a positive profit.
        // Profit for these items is A[i] - 5.
        // If A[i] - 5 > 0 (i.e., A[i] > 5), Chef makes a profit.
        if (A[i] > 5) {
            total_profit += (A[i] - 5);
        }
    }

    // After the first K items, any subsequent items Chef buys will cost 10 coins each.
    // These are the remaining N-K items in the sorted array.
    for (int i = K; i < N; ++i) {
        // An item is bought only if it yields a positive profit.
        // Profit for these items is A[i] - 10.
        // If A[i] - 10 > 0 (i.e., A[i] > 10), Chef makes a profit.
        if (A[i] > 10) {
            total_profit += (A[i] - 10);
        }
    }

    // Output the maximum total profit for the current test case.
    cout << total_profit << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```