# Chef On Date (CHEFONDATE)
- **Difficulty Rating**: 294
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to go on a date. He has `x` rupees and the date costs `y` rupees. Chef can only go on the date if he has enough money, i.e., if his money is greater than or equal to the cost of the date. The problem asks us to determine if Chef can go on the date given his money `x` and the date cost `y`.

## Intuition & Mathematical Observation
The problem is a straightforward comparison. Chef can afford the date if and only if the amount of money he has (`x`) is greater than or equal to the cost of the date (`y`). This can be expressed as a simple mathematical inequality: $x \ge y$.

If this condition holds true, Chef can go on the date, and the answer is "YES". Otherwise, if $x < y$, Chef does not have enough money, and the answer is "NO".

The core of the solution lies in implementing this direct comparison.

## Complexity Analysis
- **Time Complexity**: $O(1)$
  The solution involves a single comparison and printing an output for each test case. The number of operations is constant regardless of the input values of `x` and `y`. Since there are `t` test cases, the total time complexity is $O(t)$, but for each test case, it's $O(1)$.

- **Space Complexity**: $O(1)$
  The solution uses a few integer variables (`t`, `x`, `y`) to store input and perform calculations. The memory usage is constant and does not depend on the input size.

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
        int x, y; // x: Chef's money, y: Date cost
        std::cin >> x >> y;

        // Check if Chef has enough money for the date
        if (x >= y) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}
```