# [Car Trip (CARTRIP)](https://www.codechef.com/problems/CARTRIP)

- **Difficulty Rating**: 374
- **Solved in**: 1 attempt(s)

## Problem Summary
A car rental company charges ₹10 per kilometer. However, there is a minimum charge equivalent to traveling 300 kilometers. Given the distance $X$ traveled by a user, calculate the total cost the user must pay. If $X \leq 300$, the user pays for 300 km; otherwise, they pay for $X$ km.

## Intuition & Mathematical Observation
The problem defines a conditional pricing structure. Let $C$ be the total cost and $X$ be the distance traveled:
1. If $X \leq 300$, the cost is $300 \times 10 = 3000$.
2. If $X > 300$, the cost is $X \times 10$.

This can be simplified using the `max` function. We determine the number of kilometers to be billed as $\max(X, 300)$. Multiplying this value by 10 gives the final cost. Since the input $X$ can be small, but the output could potentially exceed the range of a 32-bit integer in larger variations of this problem, using `long long` for the calculation is a good practice.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case performs a constant number of operations ($O(1)$).
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <iostream>
#include <algorithm>

int main() {
    // Optimize standard I/O operations for speed
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        int x;
        std::cin >> x;
        
        // The cost is 10 per km, but at least 300 km must be paid for.
        // We take the maximum of the actual distance and the minimum threshold (300).
        long long kilometers_to_charge = std::max(x, 300);
        long long cost = kilometers_to_charge * 10LL;
        
        std::cout << cost << "\n";
    }
    return 0;
}
```