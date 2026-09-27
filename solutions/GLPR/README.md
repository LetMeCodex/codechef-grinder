# [Glass Prices (GLPR)](https://www.codechef.com/problems/GLPR)
- **Difficulty Rating**: 219
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to help Chef decide which type of frame to buy for his new glasses. There are two options: a plastic frame and a metal frame. The plastic frame costs `X` rupees, and the metal frame costs `Y` rupees.

Chef has a specific decision rule:
- He will buy the metal frame if its cost (`Y`) is at most twice the cost of the plastic frame (`X`).
- Otherwise (if the metal frame's cost is more than twice the plastic frame's cost), he will buy the plastic frame.

We need to read the costs `X` and `Y` and output "METAL" if Chef buys the metal frame, or "PLASTIC" if he buys the plastic frame.

## Intuition & Mathematical Observation

The problem statement directly provides the decision rule as a simple condition. We just need to translate this condition into code.

The core rule is: "Chef buys the metal frame if its cost (`Y`) is at most twice the cost of the plastic frame (`X`)."

"At most twice the cost of the plastic frame" can be expressed mathematically as `2 * X`.
So, the condition becomes `Y <= 2 * X`.

- If this condition (`Y <= 2 * X`) is true, Chef buys the metal frame.
- If this condition is false (meaning `Y > 2 * X`), Chef buys the plastic frame.

This leads to a straightforward `if-else` statement.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The program performs a fixed number of operations: reading two integers, one comparison, and printing one string. These operations take constant time, regardless of the values of `X` and `Y` (within typical integer limits). Therefore, the time complexity is constant.

-   **Space Complexity**: $O(1)$
    The program uses a constant amount of memory to store two integer variables (`X` and `Y`) and for input/output buffers. The memory usage does not grow with the input values. Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common headers like iostream

// Use the standard namespace as requested
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare two integer variables to store the prices of the plastic and metal frames.
    int X, Y;

    // Read the two prices from the standard input.
    // As per the problem description, there is only one line of input with X and Y.
    cin >> X >> Y;

    // Apply Chef's decision rule:
    // Chef buys the metal frame if its cost (Y) is at most twice the plastic frame's cost (X).
    // This translates to the condition: Y <= 2 * X.
    if (Y <= 2 * X) {
        // If the condition is true, Chef buys the metal frame.
        // Output "METAL" followed by a newline character.
        cout << "METAL\n";
    } else {
        // If the condition is false (i.e., Y > 2 * X), Chef buys the plastic frame.
        // Output "PLASTIC" followed by a newline character.
        cout << "PLASTIC\n";
    }

    // Indicate successful program execution.
    return 0;
}
```