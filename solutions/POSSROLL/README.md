# [Possible Roll (POSSROLL)](https://www.codechef.com/problems/POSSROLL)
- **Difficulty Rating**: 289
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a special die with `X` faces. The numbers displayed on these faces are `K*1, K*2, ..., K*X`, where `K` is a given positive integer. We are also given a target number `Y`. The task is to determine if `Y` can be shown on this die. In other words, we need to check if `Y` is one of the numbers `K*1, K*2, ..., K*X`.

## Intuition & Mathematical Observation

For a number `Y` to be a possible roll on the die, it must satisfy two conditions based on the die's face values `K*1, K*2, ..., K*X`:

1.  **`Y` must be a multiple of `K`**: If `Y` is to be expressed as `K * i` for some integer `i`, then `Y` must be perfectly divisible by `K`. We can check this using the modulo operator: `Y % K == 0`. If `Y` is not a multiple of `K`, it cannot be a face value.

2.  **The multiplier `i` must be within the valid range**: If `Y` is a multiple of `K` (i.e., `Y = K * i`), then `i` represents which face of the die `Y` corresponds to. The problem states the faces are `K*1, K*2, ..., K*X`. This means the multiplier `i` must be an integer such that `1 <= i <= X`.
    Since `Y` and `K` are positive integers, if `Y % K == 0`, then `Y / K` will always be an integer greater than or equal to 1. So, we only need to check the upper bound: `(Y / K) <= X`.

Combining these two conditions, `Y` can be shown on the die if and only if `Y % K == 0` AND `(Y / K) <= X`.

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    The solution involves a few basic arithmetic operations (modulo, division, comparison) and input/output operations. All these operations take constant time, irrespective of the magnitude of `X`, `K`, or `Y`. Therefore, the overall time complexity is constant.

*   **Space Complexity**: $O(1)$
    The solution uses a fixed number of integer variables (`X`, `K`, `Y`) to store the input and perform calculations. The memory usage does not scale with the input values. Hence, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries, including iostream
using namespace std;     // Brings all names from std namespace into global scope

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X, K, Y;
    // Read the three space-separated integers X, K, and Y.
    cin >> X >> K >> Y;

    // A number Y can be shown by the die if two conditions are met:
    // 1. Y must be a multiple of the base multiplier K.
    //    This is checked by Y % K == 0.
    // 2. If Y is a multiple of K, let Y = K * i. Then 'i' must be
    //    between 1 and X (inclusive), because the faces are K*1, K*2, ..., K*X.
    //    Since Y, K >= 1, if Y % K == 0, then Y/K will be at least 1.
    //    So we only need to check if Y/K is less than or equal to X.
    if (Y % K == 0 && (Y / K) <= X) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
```