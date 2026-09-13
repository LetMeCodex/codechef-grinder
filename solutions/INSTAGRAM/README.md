# Instagram (INSTAGRAM)
- **Difficulty Rating**: 408
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a user can achieve a certain goal on Instagram based on two given values, `x` and `y`. The condition for achieving the goal is that `x` must be strictly greater than 10 times `y`.

## Intuition & Mathematical Observation
The problem statement directly provides the condition for success: "if `x` is strictly greater than 10 times `y`". This translates directly into a mathematical inequality.

Let:
- `x` be the first given integer.
- `y` be the second given integer.

The condition for printing "YES" is:
$x > 10 \times y$

If this condition is not met, meaning $x \le 10 \times y$, then we should print "NO".

The problem involves a simple comparison, and there are no complex algorithms or data structures required. The core of the solution is to implement this direct comparison.

## Complexity Analysis
- **Time Complexity**: $O(1)$
The solution involves reading two integers and performing a single comparison. This operation takes constant time, regardless of the input values. Since the loop runs `t` times, and each iteration is $O(1)$, the total time complexity for `t` test cases is $O(t)$. However, for a single test case, it's $O(1)$.

- **Space Complexity**: $O(1)$
The solution uses a few integer variables (`t`, `x`, `y`) to store input and loop counters. The amount of memory used is constant and does not depend on the input size.

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
        int x, y; // The two given integers
        std::cin >> x >> y;

        // Check if x is strictly greater than 10 times y
        if (x > 10 * y) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}
```