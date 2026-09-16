# [Air Conditioner Temperature (ACTEMP)](https://www.codechef.com/problems/ACTEMP)
- **Difficulty Rating**: 584
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if there exists a temperature that can satisfy the preferences of Alice, Bob, and Charlie simultaneously. Alice wants the temperature to be at least $a$ degrees. Bob wants the temperature to be at most $b$ degrees. Charlie wants the temperature to be at least $c$ degrees. We are given $t$ test cases, and for each test case, we receive the values of $a$, $b$, and $c$.

## Intuition & Mathematical Observation
Let $T$ be the temperature. The conditions given by Alice, Bob, and Charlie can be translated into mathematical inequalities:

1.  **Alice's condition**: $T \ge a$
2.  **Bob's condition**: $T \le b$
3.  **Charlie's condition**: $T \ge c$

For a temperature $T$ to satisfy all three conditions, it must simultaneously meet all of them. We can combine these inequalities:

*   From Alice's and Charlie's conditions, we have two lower bounds for the temperature: $T \ge a$ and $T \ge c$. For $T$ to satisfy both, it must be greater than or equal to the larger of these two values. Therefore, $T \ge \max(a, c)$.
*   Bob's condition provides an upper bound: $T \le b$.

So, we are looking for a temperature $T$ such that:
$\max(a, c) \le T \le b$

Such a temperature $T$ exists if and only if the lower bound is less than or equal to the upper bound. In other words, a valid temperature exists if and only if:
$\max(a, c) \le b$

If this condition holds, we can output "Yes". Otherwise, if the required minimum temperature is greater than the maximum allowed temperature, no such temperature exists, and we should output "No".

The `std::max(a, c)` function in C++ directly computes the maximum of $a$ and $c$.

## Complexity Analysis
- **Time Complexity**: $O(1)$
    For each test case, we perform a constant number of operations: reading three integers, calculating the maximum of two integers, and performing a single comparison. Since the number of test cases is $t$, the total time complexity is $O(t \times 1) = O(t)$. However, if we consider the complexity per test case, it is $O(1)$.

- **Space Complexity**: $O(1)$
    We only use a few integer variables to store the input values and intermediate results. The memory usage does not depend on the input size, making the space complexity constant.

## Solution Code
```cpp
#include <iostream>
#include <algorithm> // Required for std::max

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int a, b, c; // Alice's minimum, Bob's maximum, Charlie's minimum
        std::cin >> a >> b >> c;

        // Alice wants temperature >= a
        // Bob wants temperature <= b
        // Charlie wants temperature >= c
        
        // For a temperature T to satisfy all conditions:
        // T >= a
        // T <= b
        // T >= c
        
        // Combining the lower bounds: T must be >= max(a, c)
        // So, we need a temperature T such that:
        // max(a, c) <= T <= b
        
        // Such a temperature T exists if and only if the lower bound is less than or equal to the upper bound.
        // That is, max(a, c) <= b
        
        if (std::max(a, c) <= b) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }
    return 0;
}
```