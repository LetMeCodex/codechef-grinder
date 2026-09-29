# [Get Lowest Free (SALE)](https://www.codechef.com/problems/SALE)

- **Difficulty Rating**: 778
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the total amount Chef needs to pay for three items, given their individual prices `A`, `B`, and `C`. The catch is that Chef gets the lowest-priced item for free. We need to output the sum of the prices of the two most expensive items, effectively. This needs to be done for `T` test cases.

## Intuition & Mathematical Observation

The core idea is straightforward: if one item is free, Chef only pays for the other two. To maximize the benefit of the "lowest free" offer, Chef should naturally choose the item with the minimum price to be the free one.

So, the steps to solve this problem are:
1.  Read the three prices: `A`, `B`, and `C`.
2.  Calculate the sum of all three prices: `total_sum = A + B + C`.
3.  Find the minimum price among `A`, `B`, and `C`: `min_price = min(A, B, C)`.
4.  The amount Chef needs to pay is the `total_sum` minus the `min_price`. This effectively means Chef pays for the two items that are not the cheapest.

For example, if prices are 10, 20, 5:
*   `total_sum = 10 + 20 + 5 = 35`
*   `min_price = 5`
*   `amount_to_pay = 35 - 5 = 30` (which is 10 + 20, the sum of the two higher prices).

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    *   For each test case, we perform a constant number of operations: three integer reads, a few additions, a few comparisons (to find the minimum), one subtraction, and one integer print. All these operations take constant time.
    *   Since there are `T` test cases, the total time complexity is $T$ multiplied by a constant, which simplifies to $O(T)$.

-   **Space Complexity**: $O(1)$
    *   We only use a few integer variables (`A`, `B`, `C`, `total_sum`, `min_price`, `amount_to_pay`, `T`). The memory used by these variables is constant and does not depend on the input values or the number of test cases. Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, algorithm, etc.

// Using namespace std; as requested
using namespace std;

void solve() {
    int A, B, C;
    cin >> A >> B >> C;

    // Calculate the sum of all prices
    int total_sum = A + B + C;

    // Find the minimum price among A, B, C.
    // std::min can take an initializer list in C++11 and later,
    // which is convenient for finding the minimum of multiple values.
    int min_price = min({A, B, C});
    
    // The amount Chef needs to pay is the total sum of prices
    // minus the price of the lowest-cost item (which is free).
    int amount_to_pay = total_sum - min_price;

    cout << amount_to_pay << "\n";
}

int main() {
    // Fast I/O setup as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times, decrementing T in each iteration
        solve(); // Call the solve function for each test case
    }

    return 0;
}
```