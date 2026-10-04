# [Payment Scheme (PAYSC)](https://www.codechef.com/problems/PAYSC)
- **Difficulty Rating**: 213
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to choose the cheaper of two payment schemes for a product.
Scheme 1: Pay 100 coins immediately and then pay $X$ coins every week for 4 weeks.
Scheme 2: Pay 300 coins immediately.

We are given the value of $X$ and need to output the minimum total cost.

## Intuition & Mathematical Observation
The problem is a straightforward comparison of two costs. We need to calculate the total cost for each scheme and then select the minimum.

**Scheme 1 Cost Calculation:**
The cost for Scheme 1 consists of an initial payment and a recurring weekly payment.
- Initial payment: 100 coins
- Weekly payment: $X$ coins per week for 4 weeks. The total for weekly payments is $4 \times X$ coins.
Therefore, the total cost for Scheme 1 is $100 + 4 \times X$.

**Scheme 2 Cost Calculation:**
The cost for Scheme 2 is a single upfront payment.
- Immediate payment: 300 coins
Therefore, the total cost for Scheme 2 is 300.

**Choosing the Minimum:**
We need to compare the total cost of Scheme 1 ($100 + 4 \times X$) with the total cost of Scheme 2 (300) and output the smaller value.

The problem statement implies that $X$ will be a non-negative integer. The costs can potentially exceed the capacity of a 32-bit integer if $X$ is large, so using `long long` for cost calculations is a good practice to avoid overflow.

## Complexity Analysis
- **Time Complexity**: $O(1)$
The solution involves a fixed number of arithmetic operations (addition, multiplication, and comparison) and input/output operations. These operations take constant time, regardless of the input value of $X$.

- **Space Complexity**: $O(1)$
The solution uses a few variables to store the input and the calculated costs. The amount of memory used is constant and does not depend on the input size.

## Solution Code

```cpp
#include <iostream>
#include <algorithm>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int x; // The weekly payment amount for Scheme 1
    std::cin >> x;
    
    // Calculate the total cost for the first payment scheme
    // Scheme 1: 100 coins immediate + X coins/week for 4 weeks
    // Using long long to prevent potential integer overflow for large X
    long long cost_scheme1 = 100LL + 4LL * x;
    
    // Cost for the second payment scheme
    // Scheme 2: 300 coins immediate
    long long cost_scheme2 = 300LL;
    
    // Output the minimum of the two costs
    std::cout << std::min(cost_scheme1, cost_scheme2) << "\n";
    
    return 0;
}
```