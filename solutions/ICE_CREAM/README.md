# [ICE CREAM (ICE_CREAM)](https://www.codechef.com/problems/ICE_CREAM)
- **Difficulty Rating**: 354
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if Chef can buy two ice creams given his current money and the cost of a single ice cream. We are provided with two integers: `X`, which is the cost of one ice cream, and `Y`, which is the total amount of money Chef has. We need to output "YES" if Chef has enough money to buy two ice creams, and "NO" otherwise.

## Intuition & Mathematical Observation

The core of this problem lies in a simple comparison.
1.  **Calculate the total cost**: If one ice cream costs `X` rupees, then two ice creams will cost `X + X`, which simplifies to `2 * X` rupees.
2.  **Compare with Chef's money**: Chef can buy two ice creams if and only if the money he has (`Y`) is greater than or equal to the total cost required (`2 * X`).

So, the condition to check is `Y >= 2 * X`.

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    The program performs a fixed number of operations regardless of the input values (within the given constraints): reading two integers, performing one multiplication, one comparison, and one print operation. All these operations take constant time.
*   **Space Complexity**: $O(1)$
    The program uses a fixed amount of memory to store a few integer variables (`X`, `Y`, `total_cost_for_two`). This memory usage does not grow with the input values, hence it is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Using the standard namespace to avoid writing std::
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare two integer variables X and Y to store the input values.
    // X: cost of one ice cream
    // Y: money Chef has
    int X, Y;

    // Read the two space-separated integers from standard input.
    // According to the problem statement, this is the only line of input.
    cin >> X >> Y;

    // Calculate the total cost required to buy two ice creams.
    // Each ice cream costs X, so two ice creams will cost 2 * X.
    // Given constraints (1 <= X <= 100), 2 * X will be at most 200,
    // which fits comfortably within an 'int' type, so no overflow issues.
    int total_cost_for_two = 2 * X;

    // Check if Chef has enough money (Y) to cover the total cost.
    // If Y is greater than or equal to total_cost_for_two, Chef can buy them.
    if (Y >= total_cost_for_two) {
        // If Chef can buy, print "YES".
        // Using "\n" for a newline character is generally preferred over std::endl
        // in competitive programming for performance reasons, as std::endl also flushes the buffer.
        cout << "YES\n";
    } else {
        // Otherwise, Chef does not have enough money, so print "NO".
        cout << "NO\n";
    }

    // Return 0 to indicate successful execution of the program.
    return 0;
}
```