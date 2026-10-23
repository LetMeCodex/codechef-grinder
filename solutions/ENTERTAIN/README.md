# [Entertainments (ENTERTAIN)](https://www.codechef.com/problems/ENTERTAIN)
- **Difficulty Rating**: 200
- **Solved in**: 3 attempt(s)

## Problem Summary
The problem asks us to calculate the minimum cost to entertain a child for a day. We are given two options:
1. Buy a TV for a fixed cost of 1000.
2. Buy toys, where each toy costs 200, and we need to buy `n` toys, where `n` is the input to the problem.

We need to choose the option that results in a lower cost.

## Intuition & Mathematical Observation
The problem presents a straightforward choice between two distinct options with calculable costs.

Let's define the costs:
- Cost of buying a TV: $C_{TV} = 1000$
- Cost of buying `n` toys: $C_{Toys} = n \times 200$

The goal is to find the minimum of these two costs. Therefore, the minimum cost will be:
$Minimum Cost = \min(C_{TV}, C_{Toys})$
$Minimum Cost = \min(1000, n \times 200)$

This means if the cost of buying `n` toys ($n \times 200$) is less than the cost of the TV (1000), we should choose to buy toys. Otherwise, we should choose to buy the TV.

The condition $n \times 200 < 1000$ simplifies to $n < \frac{1000}{200}$, which is $n < 5$.
So, if $n < 5$, the cost of toys is cheaper. If $n \ge 5$, the cost of the TV is cheaper or equal.

## Complexity Analysis
- **Time Complexity**: $O(1)$
The solution involves a fixed number of arithmetic operations (multiplication, comparison) and input/output operations, regardless of the input value `n`. Thus, the time complexity is constant.

- **Space Complexity**: $O(1)$
The solution uses a fixed amount of memory to store variables like `n`, `cost_tv`, and `cost_toys`. This amount does not grow with the input size. Thus, the space complexity is constant.

## Solution Code
```cpp
#include <iostream>

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C stdio.
    // std::cin.tie(NULL) unties cin from cout.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n; // Number of toys to buy
    std::cin >> n;

    int cost_tv = 1000; // Fixed cost of the TV
    int cost_toys = n * 200; // Cost of buying n toys

    // Compare the cost of toys with the cost of the TV.
    // Output the minimum of the two costs.
    if (cost_toys < cost_tv) {
        std::cout << cost_toys << "\n";
    } else {
        std::cout << cost_tv << "\n";
    }

    return 0;
}
```