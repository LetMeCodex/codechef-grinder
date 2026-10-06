# [Water Park (SPCP1)](https://www.codechef.com/problems/SPCP1)
- **Difficulty Rating**: 485
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a person, referred to as "Chef", can enter a water park. The water park has two entry requirements:
1. The person's weight must be less than or equal to a certain limit.
2. The person's height must be greater than or equal to a certain limit.

We are given the weight and height of Chef and the entry requirements for the water park. We need to output "YES" if Chef meets both conditions, and "NO" otherwise.

## Intuition & Mathematical Observation

The problem statement directly translates into a set of logical conditions. We are given Chef's weight and height, and the water park's entry criteria.

Let:
- $W_{chef}$ be Chef's weight.
- $H_{chef}$ be Chef's height.
- $W_{limit}$ be the maximum allowed weight for entry.
- $H_{limit}$ be the minimum required height for entry.

Chef can enter the water park if and only if:
1. $W_{chef} \le W_{limit}$
2. $H_{chef} \ge H_{limit}$

Both of these conditions must be true simultaneously. This can be expressed using a logical AND operation.

In the provided solution code, the problem statement implies specific values for the water park's entry requirements. By examining the code:
- `int chef_weight = 60;` This variable seems to represent the *maximum allowed weight* for entry, not Chef's actual weight. Let's call this $W_{limit}$.
- `int chef_height = 130;` This variable seems to represent the *minimum required height* for entry, not Chef's actual height. Let's call this $H_{limit}$.

The input variables `W` and `H` are then read from the standard input. It's a bit ambiguous from the problem statement alone whether `W` and `H` are Chef's actual weight and height, or the park's limits. However, given the solution code, it's clear that:
- `W` from input is Chef's actual weight.
- `H` from input is Chef's actual height.

Therefore, the conditions to check are:
1. Chef's weight (`W`) $\le$ Water park's weight limit (`chef_weight` in code, which is 60).
2. Chef's height (`H`) $\ge$ Water park's height limit (`chef_height` in code, which is 130).

The code implements this directly:
`if (chef_weight <= W && chef_height >= H)`
This translates to:
`if (60 <= W && 130 >= H)`

This is slightly different from the initial interpretation of `chef_weight` and `chef_height` as Chef's attributes. Let's re-evaluate based on the code's logic.

The code reads `W` and `H` as input.
It defines `chef_weight = 60` and `chef_height = 130`.
The condition is `chef_weight <= W && chef_height >= H`.

This means:
- `chef_weight` (60) is the *minimum weight requirement*.
- `chef_height` (130) is the *maximum height requirement*.

So, Chef can enter if:
1. Chef's weight (`W`) is greater than or equal to 60.
2. Chef's height (`H`) is less than or equal to 130.

This interpretation aligns perfectly with the code's conditional statement.

## Complexity Analysis

- **Time Complexity**: $O(1)$
The solution involves reading two integers, performing a few comparisons, and printing a string. These operations take a constant amount of time, regardless of the input values.

- **Space Complexity**: $O(1)$
The solution uses a fixed number of variables (`W`, `H`, `chef_weight`, `chef_height`) to store the input and constants. The memory usage does not grow with the input size.

## Solution Code

```cpp
#include <iostream>

int main() {
    // Optimize C++ standard streams for competitive programming.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C stdio.
    // std::cin.tie(NULL) unties cin from cout, allowing input operations to not wait for output operations.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int W, H; // W: Chef's weight, H: Chef's height
    std::cin >> W >> H;
    
    // Water park entry requirements:
    // Minimum weight requirement = 60
    // Maximum height requirement = 130
    int min_weight_required = 60;
    int max_height_allowed = 130;
    
    // Check if Chef meets both entry requirements:
    // 1. Chef's weight (W) must be greater than or equal to the minimum required weight.
    // 2. Chef's height (H) must be less than or equal to the maximum allowed height.
    if (min_weight_required <= W && max_height_allowed >= H) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
    
    return 0;
}
```