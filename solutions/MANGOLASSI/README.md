# [Summer Time (MANGOLASSI)](https://www.codechef.com/problems/MANGOLASSI)
- **Difficulty Rating**: 242
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine whether Mamalesh will drink mango lassi today. We are given today's temperature, `X` degrees Celsius. Mamalesh drinks mango lassi only if the temperature is *strictly greater than* 35 degrees Celsius. We need to output "YES" if he drinks it, and "NO" otherwise.

## Intuition & Mathematical Observation

This is a very basic conditional problem. The core logic revolves around a single comparison. We are given an integer `X` representing the temperature. The problem statement explicitly defines the condition for drinking mango lassi: `X > 35`.

Therefore, the intuition is straightforward:
1. Read the input temperature `X`.
2. Check if `X` is strictly greater than 35.
3. If the condition `X > 35` is true, print "YES".
4. Otherwise (if `X` is 35 or less), print "NO".

There are no complex algorithms, data structures, or advanced mathematical concepts required. It's a direct implementation of the given condition.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The program performs a fixed number of operations regardless of the input value `X`: one input operation, one comparison, and one output operation. All these operations take constant time. Hence, the time complexity is constant.

-   **Space Complexity**: $O(1)$
    The program uses a single integer variable `X` to store the input temperature. This variable occupies a constant amount of memory. No other data structures are used that would scale with input size. Hence, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare an integer variable X to store today's temperature.
    int X;

    // Read the temperature X from standard input.
    cin >> X;

    // Check the condition: Mamalesh drinks mango lassi if the temperature
    // is strictly greater than 35 degrees Celsius.
    if (X > 35) {
        // If the condition is true, print "YES" followed by a newline.
        cout << "YES\n";
    } else {
        // Otherwise (if X is 35 or less), print "NO" followed by a newline.
        cout << "NO\n";
    }

    // Return 0 to indicate successful execution of the program.
    return 0;
}
```