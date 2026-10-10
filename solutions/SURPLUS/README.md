# [Trade Surplus (SURPLUS)](https://www.codechef.com/problems/SURPLUS)
- **Difficulty Rating**: 695
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a third country, Country C, will have a trade surplus given the export and import values of two other countries, Country A and Country B. We are given the exports of A ($a_1$), imports of A ($a_2$), exports of B ($b_1$), and imports of B ($b_2$). The total trade in the system must balance, meaning the sum of all exports must equal the sum of all imports across all countries involved.

## Intuition & Mathematical Observation

The core principle here is the **balance of trade**. In any closed economic system, the total value of goods and services exported by all participants must equal the total value of goods and services imported by all participants.

Let:
- $a_1$: Exports of Country A
- $a_2$: Imports of Country A
- $b_1$: Exports of Country B
- $b_2$: Imports of Country B
- $c_1$: Exports of Country C
- $c_2$: Imports of Country C

The condition for balanced trade is:
$a_1 + b_1 + c_1 = a_2 + b_2 + c_2$

We are interested in whether Country C has a trade surplus. A trade surplus for Country C means its exports are strictly greater than its imports, i.e., $c_1 > c_2$. This is equivalent to $c_1 - c_2 > 0$.

Let's rearrange the balance of trade equation to solve for $c_1 - c_2$:
$c_1 - c_2 = (a_2 - a_1) + (b_2 - b_1)$

We can also express this in terms of net exports. The net export of a country is its exports minus its imports.
- Net export of A: $net\_export\_a = a_1 - a_2$
- Net export of B: $net\_export\_b = b_1 - b_2$
- Net export of C: $net\_export\_c = c_1 - c_2$

Substituting these into the rearranged equation:
$net\_export\_c = -(a_1 - a_2) - (b_1 - b_2)$
$net\_export\_c = -(net\_export\_a) - (net\_export\_b)$
$net\_export\_c = -(net\_export\_a + net\_export\_b)$

This equation tells us that the net export of Country C is the negative sum of the net exports of Country A and Country B. In other words, if Country A and Country B together have a net export, Country C must have a net import of the same magnitude to balance the system. Conversely, if Country A and Country B together have a net import, Country C must have a net export of the same magnitude.

Therefore, Country C has a trade surplus ($net\_export\_c > 0$) if and only if the sum of the net exports of Country A and Country B is negative ($net\_export\_a + net\_export\_b < 0$).

The problem statement implies that $a_1, a_2, b_1, b_2$ are non-negative integers. The values can be large, so `long long` is appropriate for calculations.

The logic is straightforward:
1. Calculate the net export for Country A: $a_1 - a_2$.
2. Calculate the net export for Country B: $b_1 - b_2$.
3. Calculate the net export for Country C: $-( (a_1 - a_2) + (b_1 - b_2) )$.
4. If the net export of Country C is strictly greater than 0, output "YES". Otherwise, output "NO".

## Complexity Analysis

- **Time Complexity**: $O(1)$
  The solution involves a fixed number of arithmetic operations and comparisons for each test case. The input size does not affect the number of operations performed per test case.

- **Space Complexity**: $O(1)$
  The solution uses a constant amount of extra space to store variables like `t`, `a1`, `a2`, `b1`, `b2`, `net_export_a`, `net_export_b`, and `net_export_c`. This space requirement does not grow with the input size.

## Solution Code

```cpp
#include <iostream>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        long long a1, a2, b1, b2; // Exports and imports for countries A and B
        std::cin >> a1 >> a2 >> b1 >> b2;
        
        // Calculate the net export for Country A.
        // Net export = Exports - Imports
        long long net_export_a = a1 - a2;
        
        // Calculate the net export for Country B.
        long long net_export_b = b1 - b2;
        
        // The total trade in the system must balance.
        // Let c1 be exports of C and c2 be imports of C.
        // Total exports = a1 + b1 + c1
        // Total imports = a2 + b2 + c2
        // For balance: a1 + b1 + c1 = a2 + b2 + c2
        // Rearranging for C's net export (c1 - c2):
        // c1 - c2 = (a2 - a1) + (b2 - b1)
        // c1 - c2 = -(a1 - a2) - (b1 - b2)
        // c1 - c2 = -(net_export_a) - (net_export_b)
        // c1 - c2 = -(net_export_a + net_export_b)
        
        // Calculate the net export for Country C.
        long long net_export_c = -(net_export_a + net_export_b);
        
        // A trade surplus occurs when a country exports strictly more than it imports.
        // This means net export > 0.
        if (net_export_c > 0) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}
```