# [RCB vs CSK  (RCBCSK)](https://www.codechef.com/problems/RCBCSK)
- **Difficulty Rating**: 282
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the winner between two teams, RCB and CSK, based on a simple condition involving two given integers, `X` and `Y`. If the difference `X - Y` is greater than or equal to 18, then RCB wins. Otherwise, CSK wins. We need to print "RCB" or "CSK" accordingly.

## Intuition & Mathematical Observation

This problem is a direct application of a conditional statement. The core logic is explicitly stated in the problem description:
1. Calculate the difference between `X` and `Y`.
2. Compare this difference with the value 18.
3. If `(X - Y) >= 18`, RCB is the winner.
4. Otherwise (if `(X - Y) < 18`), CSK is the winner.

There are no complex algorithms, data structures, or mathematical insights required beyond this simple comparison. It's a straightforward "if-else" scenario.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The program performs a fixed number of operations regardless of the input values `X` and `Y`. These operations include reading two integers, one subtraction, one comparison, and one print statement. All these operations take constant time. Therefore, the time complexity is constant.

-   **Space Complexity**: $O(1)$
    The program uses a constant amount of memory to store a few integer variables (`X`, `Y`). The memory usage does not scale with the input values. Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <iostream> // Required for input/output operations (std::cin, std::cout)

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    // While not strictly necessary for such a small problem, it's good practice in competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int X, Y; // Declare two integer variables to store the input values
    std::cin >> X >> Y; // Read the values of X and Y from standard input

    // Check the condition specified in the problem:
    // If the difference (X - Y) is 18 or more, RCB wins.
    if (X - Y >= 18) {
        std::cout << "RCB\n"; // Print "RCB" followed by a newline
    } else {
        // Otherwise (if X - Y is less than 18), CSK wins.
        std::cout << "CSK\n"; // Print "CSK" followed by a newline
    }

    return 0; // Indicate successful program execution
}

```