# [Sweets Shop (SWEETSHOP)](https://www.codechef.com/problems/SWEETSHOP)
- **Difficulty Rating**: 262
- **Solved in**: 1 attempt(s)

## Problem Summary

Sushil has `X` rupees. He wants to buy `N` laddus. Each laddu costs 10 rupees, and each jalebi costs 20 rupees. The task is to determine the maximum number of jalebis Sushil can buy *after* purchasing `N` laddus.

## Intuition & Mathematical Observation

The problem is a straightforward arithmetic calculation. We need to follow these steps:

1.  **Calculate the cost of laddus**: Sushil wants to buy `N` laddus, and each laddu costs 10 rupees. So, the total money spent on laddus will be `N * 10`.
2.  **Calculate remaining money**: After buying the laddus, the money left with Sushil will be his initial money `X` minus the money spent on laddus. That is, `X - (N * 10)`.
3.  **Calculate number of jalebis**: With the remaining money, Sushil wants to buy jalebis. Each jalebi costs 20 rupees. To find the maximum number of jalebis he can buy, we divide the remaining money by the cost of one jalebi. Since he can only buy whole jalebis, integer division will correctly give us the floor of this value, which is the maximum whole number of jalebis. If the remaining money is not enough to buy even one jalebi (i.e., less than 20), integer division will correctly result in 0.

The problem statement implies that Sushil *will* buy `N` laddus. Therefore, we assume `X` is sufficient for this purchase, or at least that the calculation should proceed as described.

## Complexity Analysis

*   **Time Complexity**: The solution involves a fixed number of arithmetic operations (multiplication, subtraction, division) and input/output operations. These operations take constant time regardless of the input values `X` and `N` (within typical integer limits). Therefore, the time complexity is $O(1)$.

*   **Space Complexity**: The solution uses a few integer variables (`X`, `N`, `money_spent_on_laddus`, `remaining_money`, `num_jalebis`) to store the input and intermediate results. The amount of memory used is constant and does not depend on the magnitude of `X` or `N`. Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X, N;
    cin >> X >> N;

    // Cost of one laddu is Rs. 10
    // Cost of one jalebi is Rs. 20

    // Step 1: Calculate money spent on laddus
    int money_spent_on_laddus = N * 10;

    // Step 2: Calculate remaining money after buying laddus
    int remaining_money = X - money_spent_on_laddus;

    // Step 3: Calculate number of jalebis Sushil can buy with the remaining money.
    // Integer division automatically handles the floor, which is what we need
    // for buying whole items. If remaining_money is negative or less than 20,
    // this will correctly yield 0 or a negative number (which implies 0 jalebis
    // in a practical sense, though problem constraints usually ensure non-negative
    // remaining money for jalebi purchase).
    int num_jalebis = remaining_money / 20;

    // Output the result
    cout << num_jalebis << "\n";

    return 0;
}
```