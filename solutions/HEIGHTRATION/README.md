# Height of Rationals (HEIGHTRATION)
- **Difficulty Rating**: 405
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem defines the "height" of a rational number (fraction) $a/b$ as the maximum of its numerator $a$ and its denominator $b$. We are given two integers, $a$ and $b$, and need to output their height. The constraints are $1 \le a, b \le 100$.

## Intuition & Mathematical Observation
The definition of the height of a rational number $a/b$ is explicitly given as $\max(a, b)$. This is a direct mathematical definition. There are no complex mathematical transformations or properties of fractions that need to be considered beyond this definition. The problem is essentially asking us to find the larger of two given numbers.

For example, if the fraction is $3/5$, its height is $\max(3, 5) = 5$. If the fraction is $7/2$, its height is $\max(7, 2) = 7$.

The constraints $1 \le a, b \le 100$ are very small, meaning that standard integer types will easily accommodate these values, and no overflow issues will arise.

## Complexity Analysis
- **Time Complexity**: $O(1)$
The solution involves reading two integers and then performing a single comparison using the `max` function. These operations take constant time, regardless of the input values (within the given constraints).

- **Space Complexity**: $O(1)$
The solution only uses a few variables to store the input numbers $a$ and $b$, and potentially a temporary variable within the `max` function. This requires a constant amount of memory.

## Solution Code
```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Height of Rationals
 * The height of a fraction a/b is defined as max(a, b).
 * Given constraints: 1 <= a, b <= 100.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b;
    // The problem description implies a single line of input for a and b.
    // If there were multiple test cases, we would wrap this in a while(t--) loop.
    if (cin >> a >> b) {
        cout << max(a, b) << "\n";
    }

    return 0;
}
```