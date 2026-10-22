# [Buy Lamps (BUYLAMP)](https://www.codechef.com/problems/BUYLAMP)
- **Difficulty Rating**: 775
- **Solved in**: 3 attempt(s)

## Problem Summary

You are given $N$ lamps to buy. You can buy red lamps at a cost of $X$ each, or blue lamps at a cost of $Y$ each. You are also given a constraint that you must buy at least $K$ red lamps. Your goal is to minimize the total cost of buying all $N$ lamps.

## Intuition & Mathematical Observation

The problem asks us to select $N$ lamps, with a minimum of $K$ being red, to minimize the total cost. We have two options for each lamp: buy it as red (cost $X$) or buy it as blue (cost $Y$).

Let's consider the costs $X$ and $Y$.

**Case 1: Red lamps are cheaper or equal in price to blue lamps ($X \le Y$)**

If buying a red lamp is cheaper or the same price as a blue lamp, to minimize the total cost, we should always prefer buying red lamps. Since we need to buy a total of $N$ lamps, and red lamps are not more expensive, the optimal strategy is to buy all $N$ lamps as red lamps. This automatically satisfies the condition of buying at least $K$ red lamps (since $N \ge K$ is implied by the problem constraints, or if $N < K$ it would be impossible to satisfy, but typical competitive programming problems ensure feasibility).

The total cost in this case would be $N \times X$.

**Case 2: Blue lamps are cheaper than red lamps ($X > Y$)**

If buying a blue lamp is cheaper than a red lamp, we want to maximize the number of blue lamps we buy, subject to the constraint of buying at least $K$ red lamps.

To satisfy the "at least $K$ red lamps" constraint with the minimum possible cost, we should buy exactly $K$ red lamps. Any additional red lamps beyond $K$ would only increase the cost unnecessarily, as we could have bought them as blue lamps for a lower price.

So, we buy $K$ red lamps at a cost of $K \times X$.
The remaining lamps we need to buy are $N - K$. Since blue lamps are cheaper, we should buy all these remaining $N - K$ lamps as blue lamps. The cost for these would be $(N - K) \times Y$.

The total cost in this case would be $K \times X + (N - K) \times Y$.

Combining these two cases, we can determine the minimum cost by comparing $X$ and $Y$.

## Complexity Analysis

- **Time Complexity**: $O(1)$
    - For each test case, we perform a fixed number of arithmetic operations and comparisons. The input reading also takes constant time per test case. Since the number of test cases $T$ is given, the total time complexity is $O(T)$, but for a single test case, it's $O(1)$.

- **Space Complexity**: $O(1)$
    - We only use a few variables to store the input values and the calculated total cost. The memory usage does not grow with the input size $N$, $K$, $X$, or $Y$.

## Solution Code

```cpp
#include <iostream>
#include <algorithm> // For std::min if needed, though not strictly here

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        long long N, K, X, Y; // Use long long for N, X, Y to handle large values and intermediate products
        std::cin >> N >> K >> X >> Y; // Read input for each test case

        long long total_cost;

        if (X <= Y) {
            // Red lamps are cheaper or equal.
            // To minimize cost and satisfy "at least K red",
            // we buy all N lamps as red.
            total_cost = N * X;
        } else {
            // Blue lamps are cheaper.
            // We must buy at least K red lamps.
            // To minimize cost, we buy exactly K red lamps
            // and the remaining N-K lamps as blue lamps.
            total_cost = K * X + (N - K) * Y;
        }
        std::cout << total_cost << "\n";
    }
    return 0;
}
```