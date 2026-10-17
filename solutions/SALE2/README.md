# [Buy 2 Get 1 Free (SALE2)](https://www.codechef.com/problems/SALE2)
- **Difficulty Rating**: 821
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the minimum money Chef needs to spend to buy at least `N` items. Each item costs `X` rupees. There's a special offer: "Buy 2 items and get 1 item free". This means if Chef pays for 2 items, they receive a total of 3 items.

## Intuition & Mathematical Observation

The core idea to minimize cost is to maximize the use of the "buy 2 get 1 free" offer, as it's the most cost-effective way to acquire items. This offer allows Chef to get 3 items for the price of 2.

1.  **Maximize Full Cycles**: We should try to form as many complete "buy 2 get 1 free" cycles as possible. Each cycle provides 3 items for the cost of `2 * X`.
    *   The number of full cycles that can be formed from `N` items is `N / 3` (integer division).
    *   For each such cycle, Chef pays for 2 items. So, the total number of items paid for in these full cycles is `(N / 3) * 2`.
    *   The cost for these full cycles will be `(N / 3) * 2 * X`.

2.  **Handle Remaining Items**: After forming `N / 3` full cycles, there might be some items remaining that don't form a complete cycle of 3. The number of remaining items is `N % 3`.
    *   If `N % 3 == 0`: All items are covered by full cycles. No additional cost.
    *   If `N % 3 == 1`: Chef needs 1 more item. They must buy this item individually, costing `1 * X`.
    *   If `N % 3 == 2`: Chef needs 2 more items. They must buy these 2 items individually, costing `2 * X`. (Note: While buying 2 items could also trigger the "get 1 free" offer, giving 3 items for `2*X`, we only *need* 2 items. Paying `2*X` for 2 items is the minimum cost to acquire exactly 2 items, and it's not more expensive than getting 3 items for `2*X` if we only needed 2).

Combining these observations, the total minimum cost is:
`Total Cost = ( (N / 3) * 2 * X ) + ( (N % 3) * X )`

Let's take an example: `N = 5`, `X = 10`
*   `num_full_cycles = 5 / 3 = 1`.
*   Cost for full cycles: `1 * 2 * X = 1 * 2 * 10 = 20`. (Chef gets 3 items for 20 rupees).
*   `remaining_items = 5 % 3 = 2`.
*   Cost for remaining items: `2 * X = 2 * 10 = 20`. (Chef buys 2 items for 20 rupees).
*   Total cost = `20 + 20 = 40`.

The solution directly implements this formula. Using `long long` for `total_cost` is a good practice to prevent potential integer overflow, although for the given constraints (`N, X <= 1000`), `int` would technically suffice.

## Complexity Analysis

*   **Time Complexity**: The solution performs a fixed number of arithmetic operations (division, modulo, multiplication, addition) for each test case. These operations take constant time. Therefore, for `T` test cases, the total time complexity is $O(T)$.
*   **Space Complexity**: The solution uses a few integer variables to store `N`, `X`, intermediate calculations, and the final `total_cost`. The amount of memory used is constant and does not depend on the input size. Thus, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <iostream> // Required for cin, cout
// For competitive programming, it's common to include <bits/stdc++.h>
// which includes most standard libraries.
#include <bits/stdc++.h> 

// Using the standard namespace to avoid writing std:: prefix
using namespace std;

// Function to solve a single test case
void solve() {
    int N, X;
    cin >> N >> X; // Read N (number of items) and X (cost per item)

    // Calculate the number of full "buy 2 get 1 free" cycles.
    // Each cycle gives 3 items for the price of 2.
    int num_full_cycles = N / 3;

    // Calculate the cost for these full cycles.
    // For each cycle, Chef pays for 2 items.
    // So, num_full_cycles * 2 items are paid for.
    // The total cost for these items is (num_full_cycles * 2) * X.
    // Using long long for total_cost to prevent potential overflow,
    // though for the given constraints (N, X <= 1000), int would suffice.
    long long total_cost = (long long)num_full_cycles * 2 * X;

    // Calculate the number of remaining items after full cycles.
    int remaining_items = N % 3;

    // For the remaining items, Chef has to pay for them individually.
    // If remaining_items is 1, Chef pays for 1 item.
    // If remaining_items is 2, Chef pays for 2 items.
    // This logic correctly finds the minimum cost for exactly 'remaining_items'.
    // If remaining_items is 2, paying for 2 items gives 2 items for 2*X.
    // Using the offer (pay for 2, get 1 free) would give 3 items for 2*X.
    // Both cost 2*X, but the latter gives more items. Since we need "at least N items",
    // both options are valid for the cost, and 2*X is the minimum.
    total_cost += (long long)remaining_items * X;

    // Output the minimum money required
    cout << total_cost << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
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