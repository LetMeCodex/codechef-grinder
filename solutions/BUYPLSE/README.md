# [Buy Please (BUYPLSE)](https://www.codechef.com/problems/BUYPLSE)
- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the total cost of buying a certain number of pens and pencils, given the quantity of each item and their respective prices. Specifically, we are given:
- `a`: the number of pens to buy.
- `b`: the number of pencils to buy.
- `x`: the cost of one pen.
- `y`: the cost of one pencil.

We need to output the total cost.

## Intuition & Mathematical Observation

The problem is a straightforward application of basic arithmetic. To find the total cost, we need to calculate the cost of all the pens and the cost of all the pencils separately, and then sum them up.

The cost of `a` pens, each costing `x`, is simply `a * x`.
The cost of `b` pencils, each costing `y`, is simply `b * y`.

Therefore, the total cost is the sum of these two amounts: `(a * x) + (b * y)`.

The constraints on the input values are `1 <= a, b, x, y <= 10^3`.
The maximum possible value for `a * x` would be `10^3 * 10^3 = 10^6`.
Similarly, the maximum possible value for `b * y` would be `10^3 * 10^3 = 10^6`.
The maximum total cost would therefore be `10^6 + 10^6 = 2 * 10^6`.
A standard `int` data type in C++ can typically hold values up to `2 * 10^9`, which is more than sufficient to store this maximum total cost. Thus, `long long` is not required.

## Complexity Analysis

- **Time Complexity**: $O(1)$
The solution involves a fixed number of arithmetic operations (two multiplications and one addition) and input/output operations. The time taken does not depend on the magnitude of the input values, only on the number of operations, which is constant.

- **Space Complexity**: $O(1)$
The solution uses a fixed number of variables (`a`, `b`, `x`, `y`, `total_cost`) to store the input and the result. The memory usage is constant and does not grow with the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare four integer variables to store the input values:
    // a: number of pens
    // b: number of pencils
    // x: cost per pen
    // y: cost per pencil
    int a, b, x, y;

    // Read the four space-separated integers from the first line of input.
    cin >> a >> b >> x >> y;

    // Calculate the total cost.
    // The cost of 'a' pens is 'a * x'.
    // The cost of 'b' pencils is 'b * y'.
    // The total amount spent is the sum of these two costs.
    // Given constraints (1 <= a, b, x, y <= 10^3), the maximum possible
    // value for (a * x) is 10^3 * 10^3 = 10^6.
    // Similarly, (b * y) is at most 10^6.
    // The total cost will be at most 10^6 + 10^6 = 2 * 10^6.
    // A standard 'int' type in C++ is sufficient to store this value
    // (typically up to 2 * 10^9), so no 'long long' is needed here.
    int total_cost = (a * x) + (b * y);

    // Print the calculated total cost to standard output, followed by a newline character.
    cout << total_cost << "\n";

    return 0; // Indicate successful execution of the program.
}
```