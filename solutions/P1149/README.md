# [Approximate Answer (P1149)](https://www.codechef.com/problems/P1149)
- **Difficulty Rating**: 291
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if it's possible to transform an integer `X` into another integer `Y` by performing at most `K` operations. Each operation allows us to either increment the current number by 1 (change `N` to `N+1`) or decrement it by 1 (change `N` to `N-1`).

## Intuition & Mathematical Observation

The core of this problem lies in understanding the minimum number of operations required to change one integer into another using only unit increments or decrements.

Consider starting at `X` and wanting to reach `Y`. Each operation moves us one step closer to `Y` if we always choose the correct direction (increment if `Y > X`, decrement if `Y < X`).
The total number of steps required to go from `X` to `Y` is simply the absolute difference between them, `|X - Y|`.

For example:
- If `X = 5` and `Y = 8`, we need `|5 - 8| = 3` operations (`5 -> 6 -> 7 -> 8`).
- If `X = 10` and `Y = 7`, we need `|10 - 7| = 3` operations (`10 -> 9 -> 8 -> 7`).

The problem states that we can perform *at most* `K` operations. This means if the minimum number of operations required (`|X - Y|`) is less than or equal to `K`, then it's possible to reach `Y` from `X`. Otherwise, it's not possible.

Therefore, the condition to check is `abs(X - Y) <= K`. If this condition is true, the answer is "Yes"; otherwise, it's "No".

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The solution involves reading three integers, performing a single absolute difference calculation, a comparison, and printing a string. All these operations take constant time, regardless of the magnitude of `X`, `Y`, or `K`.

-   **Space Complexity**: $O(1)$
    The program uses a fixed number of integer variables (`X`, `Y`, `K`) to store input and perform calculations. The memory usage does not scale with the input values, making it constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes cmath for abs()
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin/cout from C's stdio and prevents flushing cout before cin.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X, Y, K;
    // Read the three integer inputs: starting number X, target number Y, and max operations K.
    cin >> X >> Y >> K;

    // Calculate the minimum number of operations required to change X to Y,
    // which is the absolute difference |X - Y|.
    // Then, check if this required number of operations is less than or equal to K.
    if (abs(X - Y) <= K) {
        // If it is, then Y can be reached from X within K operations.
        cout << "Yes\n";
    } else {
        // Otherwise, it's not possible.
        cout << "No\n";
    }

    return 0;
}

```