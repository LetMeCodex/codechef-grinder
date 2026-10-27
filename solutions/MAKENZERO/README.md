# [Make N Zero (MAKENZERO)](https://www.codechef.com/problems/MAKENZERO)
- **Difficulty Rating**: 846
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a given positive integer `N` can be reduced to `0` by repeatedly subtracting either `3` or `4`. We can perform these operations any number of times.

## Intuition & Mathematical Observation
The core of this problem lies in understanding what it means to reduce `N` to `0` by repeatedly subtracting `3` or `4`. If we can reduce `N` to `0`, it means `N` must be expressible as a sum of `3`s and `4`s. That is, `N` can be written in the form `3x + 4y`, where `x` and `y` are non-negative integers representing the number of times we subtract `3` and `4` respectively.

This is a classic problem in number theory known as the **Frobenius Coin Problem** (also known as the coin problem or the McNugget problem). For two relatively prime positive integers `a` and `b`, the largest integer that cannot be expressed in the form `ax + by` for non-negative integers `x, y` is given by the **Frobenius number** `g(a, b) = ab - a - b`.

In our case, `a = 3` and `b = 4`.
1.  **Check for relative primality**: `gcd(3, 4) = 1`, so they are relatively prime. This means the Frobenius number formula is applicable.
2.  **Calculate the Frobenius number**:
    `g(3, 4) = (3 * 4) - 3 - 4`
    `g(3, 4) = 12 - 7`
    `g(3, 4) = 5`

This result tells us that any integer `N > 5` can *always* be expressed in the form `3x + 4y` with non-negative integers `x` and `y`. Therefore, for any `N > 5`, the answer is "YES".

Now, we need to manually check the smaller values of `N` (from `1` to `5`):
*   **N = 1**: Cannot be formed by `3x + 4y`. (NO)
*   **N = 2**: Cannot be formed by `3x + 4y`. (NO)
*   **N = 3**: `3 = 3 * 1 + 4 * 0`. (YES)
*   **N = 4**: `4 = 3 * 0 + 4 * 1`. (YES)
*   **N = 5**: Cannot be formed by `3x + 4y`. This is the Frobenius number itself, meaning it's the largest number that *cannot* be formed. (NO)

Combining these observations:
*   `N = 1`, `N = 2`, `N = 5` result in "NO".
*   All other positive integers `N` (i.e., `N = 3, 4` and all `N > 5`) result in "YES".

This leads to a simple conditional check: if `N` is `1`, `2`, or `5`, print "NO"; otherwise, print "YES".

## Complexity Analysis
-   **Time Complexity**: $O(T)$
    For each test case, the solution performs a constant number of operations: reading an integer, comparing it with a few fixed values, and printing a string. This takes constant time per test case. If there are $T$ test cases, the total time complexity is $O(T)$.
-   **Space Complexity**: $O(1)$
    The solution uses a fixed amount of memory for variables like `T` and `N`, regardless of the input values. No dynamic data structures or arrays are used. Thus, the space complexity is constant.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes all standard libraries, as requested.

// Using the standard namespace to avoid prefixing std::
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can be a bottleneck for large I/O.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // further speeding up I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases.

    // Loop through each test case.
    while (T--) {
        int N;
        cin >> N; // Read the integer N for the current test case.

        // Based on the analysis using the Frobenius Coin Problem for (3, 4),
        // the largest number that cannot be formed by 3x + 4y (where x, y >= 0) is 5.
        // This means any N > 5 can be made zero.
        // We manually check N = 1, 2, 3, 4, 5:
        // N = 1: NO
        // N = 2: NO
        // N = 3: YES (3 = 3*1)
        // N = 4: YES (4 = 4*1)
        // N = 5: NO (Frobenius number g(3,4) = 5)
        //
        // Therefore, N can be made zero if it's not 1, 2, or 5.
        if (N == 1 || N == 2 || N == 5) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }

    return 0; // Indicate successful execution.
}
```