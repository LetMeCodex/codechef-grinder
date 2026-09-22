# [Valentine is Coming (VALENTINE)](https://www.codechef.com/problems/VALENTINE)
- **Difficulty Rating**: 691
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has a certain amount of money, `x`, and wants to buy chocolates that cost `y` each. The goal is to determine the maximum number of chocolates Chef can buy.

## Intuition & Mathematical Observation
The problem asks for the maximum number of items (chocolates) that can be purchased given a total budget and the cost per item. This is a classic division problem.

If Chef has `x` amount of money and each chocolate costs `y`, then the number of chocolates Chef can buy is simply the total money divided by the cost of one chocolate. Since Chef can only buy whole chocolates, we are interested in the integer part of this division.

Mathematically, if `N` is the number of chocolates, then:
`N * y <= x`

To find the maximum `N`, we can rearrange this inequality:
`N <= x / y`

Since `N` must be an integer, the maximum value of `N` is the floor of `x / y`. In most programming languages, integer division automatically performs this floor operation.

For example, if Chef has $10$ and chocolates cost $3$, Chef can buy $10 / 3 = 3$ chocolates. Chef will have $1$ dollar left over, but cannot buy another chocolate.

The constraints on `x` and `y` (up to 100) are small, so standard integer types are sufficient.

## Complexity Analysis
- **Time Complexity**: $O(1)$
The solution involves a single division operation for each test case. Since the number of operations is constant regardless of the input values (within their constraints), the time complexity is $O(1)$.

- **Space Complexity**: $O(1)$
The solution uses a few variables to store the input values (`x`, `y`, `t`) and the result. The amount of memory used does not grow with the input size, hence the space complexity is $O(1)$.

## Solution Code
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C stdio.
    // cin.tie(NULL) unties cin from cout, allowing input and output operations
    // to not block each other.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Variable to store the number of test cases.
    cin >> t; // Read the number of test cases.

    // Loop through each test case.
    while (t--) {
        int x, y; // x: total money, y: cost of one chocolate.
        cin >> x >> y; // Read the total money and the cost per chocolate.

        // The maximum number of chocolates Chef can buy is the total amount of money
        // divided by the cost of one chocolate. Integer division automatically
        // handles the "maximum" aspect by truncating any remainder.
        // Since X and Y are at most 100, int is sufficient.
        cout << x / y << "\n"; // Print the result followed by a newline.
    }

    return 0; // Indicate successful execution.
}
```