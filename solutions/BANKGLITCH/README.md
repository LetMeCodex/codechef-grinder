# Bank Glitch (BANKGLITCH)
- **Difficulty Rating**: 649
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has two types of currency. Initially, he has $A$ units of currency 1 and $B$ units of currency 2. Normally, 1 unit of currency 1 is equivalent to 1 unit of currency 2. However, there's a glitch: Chef can trade $X$ units of currency 1 for $Y$ units of currency 2, where $X < Y$. This trade can be performed multiple times as long as Chef has enough currency 1. The goal is to maximize the total value of Chef's money, where the value is the sum of currency 1 and currency 2.

## Intuition & Mathematical Observation
The core of the problem lies in understanding the benefit of the glitch. When Chef trades $X$ units of currency 1, he receives $Y$ units of currency 2. Since $X < Y$, this means for every $X$ units of currency 1 he spends, he effectively gains $Y - X$ units of value (because the $X$ units of currency 1 are replaced by $Y$ units of currency 2, and their values are equivalent in the normal exchange rate). This is a strictly profitable transaction.

Since the trade is always beneficial ($Y > X$), Chef should perform this trade as many times as possible to maximize his total money. The limiting factor for the number of trades is the amount of currency 1 Chef possesses.

If Chef has $A$ units of currency 1 and each trade requires $X$ units of currency 1, the maximum number of trades he can perform is the integer division of $A$ by $X$. Let this be `num_trades = A / X`.

After performing `num_trades` trades:
1.  **Currency 1 remaining**: Chef starts with $A$ units and spends `num_trades * X` units. So, the remaining currency 1 is $A - (\text{num\_trades} \times X)$.
2.  **Currency 2 gained**: For each trade, Chef gains $Y$ units of currency 2. So, he gains `num_trades * Y` units of currency 2.
3.  **Total currency 2**: Chef initially had $B$ units of currency 2 and gained `num_trades * Y` units. So, the total currency 2 becomes $B + (\text{num\_trades} \times Y)$.

The total money Chef has is the sum of his remaining currency 1 and his total currency 2:
Total Money = (Currency 1 remaining) + (Total currency 2)
Total Money = $(A - (\text{num\_trades} \times X)) + (B + (\text{num\_trades} \times Y))$
Total Money = $A + B + (\text{num\_trades} \times Y) - (\text{num\_trades} \times X)$
Total Money = $A + B + \text{num\_trades} \times (Y - X)$

This formula directly calculates the maximum possible money Chef can have by utilizing the glitch to its fullest extent.

## Complexity Analysis
- **Time Complexity**: $O(1)$
    The solution involves a fixed number of arithmetic operations (division, multiplication, addition, subtraction) for each test case. The number of test cases is read from input, but the computation per test case is constant.
- **Space Complexity**: $O(1)$
    The solution uses a fixed number of variables to store the input values and the result, regardless of the input size.

## Solution Code
```cpp
#include <iostream>
#include <algorithm>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        long long a, b, x, y; // Initial amounts of currency 1 and 2, trade parameters
        std::cin >> a >> b >> x >> y;

        // The problem states that 1 unit of currency 1 is worth 1 unit of currency 2 normally.
        // The glitch allows trading X units of currency 1 for Y units of currency 2, where X < Y.
        // This means for every X units of currency 1 spent, Chef gains Y units of currency 2.
        // The net gain in total value is Y - X.
        // Chef wants to maximize his total money, which is the sum of currency 1 and currency 2.
        // Since the trade is always beneficial (Y > X), Chef should make as many trades as possible.
        // The number of trades is limited by the amount of currency 1 he has.
        // He can make at most floor(A / X) trades.

        // Calculate the maximum number of trades Chef can perform.
        // Integer division automatically handles the floor operation.
        long long num_trades = a / x;
        
        // After making num_trades:
        // Currency 1 remaining = A - (num_trades * X)
        // Currency 2 gained = num_trades * Y
        // Total currency 2 = B + (num_trades * Y)
        
        // Total money = (Currency 1 remaining) + (Total currency 2)
        // Total money = (A - num_trades * X) + (B + num_trades * Y)
        // Rearranging terms:
        // Total money = A + B + num_trades * Y - num_trades * X
        // Total money = A + B + num_trades * (Y - X)

        long long max_money = a + b + num_trades * (y - x);
        
        std::cout << max_money << "\n";
    }
    return 0;
}
```