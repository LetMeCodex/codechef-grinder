# [Christmas Trees (XMASTREE)](https://www.codechef.com/problems/XMASTREE)
- **Difficulty Rating**: 300
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the total profit made from buying and selling Christmas trees. We are given four integers:
1. `N`: The number of Christmas trees to buy.
2. `A`: The cost of one Christmas tree.
3. `M`: The number of Christmas trees to sell.
4. `B`: The selling price of one Christmas tree.

The goal is to compute the total profit, which is defined as `(Total Revenue) - (Total Cost)`.

## Intuition & Mathematical Observation

This problem is a straightforward application of basic arithmetic.
1. **Total Cost**: If we buy `N` trees and each tree costs `A`, the total cost incurred will be `N * A`.
2. **Total Revenue**: If we sell `M` trees and each tree sells for `B`, the total revenue generated will be `M * B`.
3. **Total Profit**: As per the problem definition, profit is `Total Revenue - Total Cost`.

Combining these, the formula for profit becomes:
`Profit = (M * B) - (N * A)`

The only potential pitfall in such problems is integer overflow if the intermediate products (`N * A` or `M * B`) or the final profit exceed the maximum value an `int` can hold. Given that competitive programming problems often involve large numbers, it's a good practice to use `long long` for calculations involving products that might exceed $2 \times 10^9$. The provided solution correctly uses `long long` to prevent this.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The solution involves a fixed number of arithmetic operations (two multiplications and one subtraction) and constant time input/output operations. The number of operations does not depend on the magnitude of the input values `N, A, M, B`. Therefore, the time complexity is constant.

-   **Space Complexity**: $O(1)$
    The solution uses a fixed number of variables (`n, a, m, b, cost, revenue, profit`) to store input and intermediate/final results. The memory usage does not scale with the input values. Thus, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, m, b;
    // Read the number of trees to buy (N), cost per tree (A),
    // number of trees to sell (M), and selling price per tree (B).
    cin >> n >> a >> m >> b;

    // Calculate the total cost of buying N trees.
    // Use long long to prevent potential integer overflow,
    // as N * A could be large.
    long long cost = (long long)n * a;

    // Calculate the total revenue from selling M trees.
    // Use long long to prevent potential integer overflow,
    // as M * B could be large.
    long long revenue = (long long)m * b;

    // Calculate the profit, which is revenue minus cost.
    long long profit = revenue - cost;

    // Print the calculated profit followed by a newline.
    cout << profit << "\n";

    return 0;
}
```