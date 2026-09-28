# [Better Deal (BETDEAL)](https://www.codechef.com/problems/BETDEAL)
- **Difficulty Rating**: 584
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to compare two deals for purchasing an item.
Deal 1: An item is sold at a 100% discount. This means the price is $100 - A$, where $A$ is the percentage discount.
Deal 2: An item is sold at a 200% discount. This means the price is $200 - 2B$, where $B$ is the percentage discount.

We need to determine which deal is better (cheaper) or if they are both the same price.

## Intuition & Mathematical Observation

The core of the problem is to calculate the final price for each deal and then compare them.

**Deal 1:**
The original price is implicitly 100 units.
The discount is $A\%$.
The discount amount is $100 \times \frac{A}{100} = A$.
The final price for Deal 1 is $100 - A$.

**Deal 2:**
The original price is implicitly 200 units.
The discount is $B\%$.
The discount amount is $200 \times \frac{B}{100} = 2B$.
The final price for Deal 2 is $200 - 2B$.

Now, we need to compare these two final prices:
- If $100 - A < 200 - 2B$, then Deal 1 is better.
- If $200 - 2B < 100 - A$, then Deal 2 is better.
- If $100 - A = 200 - 2B$, then both deals are equally good.

We can rearrange the inequality $100 - A < 200 - 2B$ to understand the condition for Deal 1 being better:
$2B - A < 200 - 100$
$2B - A < 100$

Similarly, for Deal 2 being better:
$200 - 2B < 100 - A$
$2B - A > 100$

And for both being equal:
$100 - A = 200 - 2B$
$2B - A = 100$

The provided solution directly calculates the final prices using floating-point numbers for clarity and then compares them. This is a straightforward and correct approach.

Let's verify the calculation in the code:
`double price1 = 100.0 * (100.0 - a) / 100.0;`
This simplifies to `100.0 - a`, which matches our derived price for Deal 1.

`double price2 = 200.0 * (100.0 - b) / 100.0;`
This simplifies to `2.0 * (100.0 - b)`, which is `200.0 - 2.0 * b`. This matches our derived price for Deal 2.

The comparison `price1 < price2`, `price2 < price1`, and the `else` case correctly implement the logic.

## Complexity Analysis

- **Time Complexity**: $O(1)$
The program performs a fixed number of arithmetic operations and comparisons for each test case. The number of test cases is read from input, but the operations per test case are constant. Therefore, the time complexity is constant.

- **Space Complexity**: $O(1)$
The program uses a fixed amount of memory to store variables like `t`, `a`, `b`, `price1`, and `price2`, regardless of the input size. Thus, the space complexity is constant.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int a, b; // Percentage discounts for Deal 1 and Deal 2 respectively
        std::cin >> a >> b;

        // Calculate the final price for Deal 1.
        // Original price is 100. Discount is A%.
        // Final price = 100 * (100 - A) / 100 = 100 - A
        double price1 = 100.0 - static_cast<double>(a);

        // Calculate the final price for Deal 2.
        // Original price is 200. Discount is B%.
        // Final price = 200 * (100 - B) / 100 = 2 * (100 - B) = 200 - 2*B
        double price2 = 200.0 - 2.0 * static_cast<double>(b);

        // Compare the prices and print the result
        if (price1 < price2) {
            std::cout << "FIRST\n"; // Deal 1 is cheaper
        } else if (price2 < price1) {
            std::cout << "SECOND\n"; // Deal 2 is cheaper
        } else {
            std::cout << "BOTH\n"; // Both deals have the same price
        }
    }
    return 0;
}
```