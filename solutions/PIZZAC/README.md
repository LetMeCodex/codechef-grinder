# Pizza Cutting (PIZZAC)
- **Difficulty Rating**: 566
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if it's possible to cut a circular pizza into $N$ equal pieces using straight cuts that pass through the center of the pizza.

## Intuition & Mathematical Observation

Let's consider how cuts through the center of a pizza work. Each cut that passes through the center divides the pizza into two new pieces.

*   **1 cut:** A single cut through the center divides the pizza into 2 pieces.
*   **2 cuts:** Two cuts through the center (which can be at any angle relative to each other) will divide the pizza into 4 pieces.
*   **3 cuts:** Three cuts through the center will divide the pizza into 6 pieces.

We can observe a pattern here: if we make $k$ cuts through the center of the pizza, we will always end up with $2 \times k$ pieces. This is because each new cut, by definition, passes through the center and intersects all previous cuts at the center, effectively doubling the number of existing pieces.

Therefore, the total number of pieces we can obtain by making straight cuts through the center is always an **even number**.

The problem states that we need to cut the pizza into exactly $N$ equal pieces. Based on our observation, this is only possible if $N$ is an even number.

However, there's a special case: if $N=1$, it means we don't need to make any cuts. A single pizza is already 1 piece. So, $N=1$ is also achievable.

Combining these observations:
*   If $N=1$, we can achieve 1 piece (no cuts needed). So, "YES".
*   If $N$ is an even number greater than 1, we can achieve $N$ pieces by making $N/2$ cuts through the center. So, "YES".
*   If $N$ is an odd number greater than 1, it's impossible to obtain an odd number of pieces using only cuts through the center. So, "NO".

This leads to a simple condition: the pizza can be cut into $N$ equal pieces if $N=1$ or if $N$ is even.

## Complexity Analysis

- **Time Complexity**: $O(1)$
    The solution involves a few simple arithmetic operations and comparisons for each test case. The number of operations does not depend on the input value of $N$.

- **Space Complexity**: $O(1)$
    The solution uses a constant amount of extra space to store variables like `t`, `n`, and loop counters.

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
        int n; // Number of pieces required
        std::cin >> n;

        // If n is 1, we already have 1 piece (no cuts needed).
        // If n is even, we can achieve n pieces by making n/2 cuts through the center.
        // If n is odd and greater than 1, it's impossible to get an odd number of pieces
        // using only cuts through the center.
        if (n == 1 || n % 2 == 0) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}
```