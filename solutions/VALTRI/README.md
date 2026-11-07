# [Raju and His Trip (VALTRI)](https://www.codechef.com/problems/VALTRI)
- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary

Raju is planning a trip and needs to choose a bus. A bus is considered "lucky" for Raju if its bus number `N` is either divisible by 5 or divisible by 6. Given a bus number `N`, the task is to determine if it's a lucky bus for Raju. If it is, print "YES"; otherwise, print "NO".

## Intuition & Mathematical Observation

The problem statement directly translates into a simple mathematical condition. We are given an integer `N` and need to check if it satisfies one of two conditions:
1. `N` is divisible by 5.
2. `N` is divisible by 6.

If *either* of these conditions is true, the bus is lucky. In programming terms, "divisible by X" means that the remainder when `N` is divided by `X` is 0. This is checked using the modulo operator (`%`).

So, the condition can be written as:
`(N % 5 == 0) OR (N % 6 == 0)`

In C++ and many other programming languages, the logical OR operator is `||`. Therefore, we simply need to read `N` and then evaluate the expression `N % 5 == 0 || N % 6 == 0`. Based on the result, we print "YES" or "NO".

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The program performs a fixed number of operations:
    1. Reading an integer `N`.
    2. Two modulo operations (`N % 5`, `N % 6`).
    3. One logical OR operation.
    4. Printing a short string ("YES" or "NO").
    All these operations take constant time, regardless of the magnitude of `N` (within standard integer limits). Thus, the time complexity is constant.

-   **Space Complexity**: $O(1)$
    The program uses a single integer variable `N` to store the input. No other data structures are used that would scale with the input size. Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Required header for standard library utilities

using namespace std; // Use the standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; // Declare an integer variable N to store the bus number.

    // Read the bus number N from standard input.
    cin >> N;

    // Check if N is divisible by 5 OR if N is divisible by 6.
    // The modulo operator (%) returns the remainder of a division.
    // If N % 5 == 0, N is divisible by 5.
    // If N % 6 == 0, N is divisible by 6.
    // The '||' (logical OR) operator means the condition is true if at least one of the sub-conditions is true.
    if (N % 5 == 0 || N % 6 == 0) {
        // If N satisfies the condition, print "YES" followed by a newline.
        cout << "YES\n";
    } else {
        // If N does not satisfy the condition, print "NO" followed by a newline.
        cout << "NO\n";
    }

    return 0; // Indicate successful program execution.
}
```