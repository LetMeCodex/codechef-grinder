# [Pair Me (SUMPOS)](https://www.codechef.com/problems/SUMPOS)
- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if, given three integers `X`, `Y`, and `Z`, any one of them is equal to the sum of the other two. We need to output "YES" if such a condition is met, and "NO" otherwise. This check must be performed for multiple test cases.

**Input:**
- The first line contains an integer `T`, the number of test cases.
- Each of the following `T` lines contains three space-separated integers `X`, `Y`, and `Z`.

**Output:**
- For each test case, print "YES" or "NO" on a new line.

## Intuition & Mathematical Observation

The problem statement directly translates into a simple conditional check. We are given three numbers, say `x`, `y`, and `z`. We need to verify if any of the following three conditions hold true:

1.  Is `x` equal to the sum of `y` and `z`? (i.e., `x == y + z`)
2.  Is `y` equal to the sum of `x` and `z`? (i.e., `y == x + z`)
3.  Is `z` equal to the sum of `x` and `y`? (i.e., `z == x + y`)

If at least one of these conditions is true, then the answer is "YES". If none of them are true, then the answer is "NO". There are no complex mathematical properties or data structures required; it's a straightforward application of `if-else` statements.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    For each test case, we perform a constant number of operations: three integer reads, at most three additions, at most three comparisons, and one print operation. All these operations take constant time, $O(1)$. Since there are `T` test cases, the total time complexity will be $T \times O(1) = O(T)$. The input/output optimizations (`ios_base::sync_with_stdio(false); cin.tie(NULL);`) improve the constant factor but do not change the asymptotic complexity.

-   **Space Complexity**: $O(1)$
    We only use a few integer variables (`t`, `x`, `y`, `z`) to store the input and loop counter. The amount of memory used does not depend on the magnitude of the input numbers or the number of test cases (as we process them one by one). Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common headers like iostream

using namespace std; // Use the standard namespace as requested

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Declare an integer variable 't' to store the number of testcases.
    cin >> t; // Read the number of testcases from standard input.

    // Loop through each testcase. The 't--' decrements 't' after each iteration
    // until 't' becomes 0, effectively running the loop 't' times.
    while (t--) {
        int x, y, z; // Declare three integer variables to store the input numbers.
        cin >> x >> y >> z; // Read the three space-separated integers for the current testcase.

        // Check if any of the three conditions are true:
        // 1. x is the sum of y and z
        // 2. y is the sum of x and z
        // 3. z is the sum of x and y
        if (x == y + z || y == x + z || z == x + y) {
            cout << "YES\n"; // If any condition is true, print "YES" followed by a newline.
        } else {
            cout << "NO\n"; // Otherwise (if none of the conditions are true), print "NO" followed by a newline.
        }
    }

    return 0; // Indicate successful program execution.
}
```