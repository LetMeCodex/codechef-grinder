# [Largest K (LARGESTK343)](https://www.codechef.com/problems/LARGESTK343)
- **Difficulty Rating**: 990
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the largest possible integer `K` given `X` zeros and `Y` ones. We need to arrange these `X` zeros and `Y` ones into a binary string such that there are at least `K` ones between any two consecutive occurrences of zeros. We are guaranteed that `X` is always greater than or equal to 2.

## Intuition & Mathematical Observation

1.  **Understanding the Constraint**: The core condition is "at least `K` ones between any two occurrences of zeros". This implies that we need to focus on the segments *between* the zeros.

2.  **Arrangement of Zeros**: If we have `X` zeros, they will create `X-1` "internal" gaps or segments between them.
    *   For `X=2`: `0 [gap1] 0` (1 gap)
    *   For `X=3`: `0 [gap1] 0 [gap2] 0` (2 gaps)
    *   For `X=4`: `0 [gap1] 0 [gap2] 0 [gap3] 0` (3 gaps)
    In general, `X` zeros create `X-1` such internal gaps.

3.  **Minimum Ones Required for Gaps**: To satisfy the problem's condition, each of these `X-1` internal gaps *must* contain at least `K` ones.

4.  **Total Minimum Ones**: Therefore, the total number of ones required to fulfill this minimum condition across all `X-1` gaps is `(X-1) * K`.

5.  **Available Ones**: We are given a total of `Y` ones. These `Y` ones must be sufficient to cover the minimum requirements for all internal gaps. This leads to the inequality:
    `Y >= (X-1) * K`

6.  **Finding the Largest K**: We want to find the largest integer `K` that satisfies this inequality. We can rearrange the inequality to solve for `K`:
    `K <= Y / (X-1)`

7.  **Integer Division**: Since `K` must be an integer, the largest possible integer `K` is the floor of `Y / (X-1)`. In C++ (and many other programming languages), integer division `Y / (X-1)` automatically computes the floor for positive numbers.

8.  **Denominator Check**: The problem statement guarantees `X >= 2`. This means `X-1` will always be at least `1`, so we never have to worry about division by zero.

9.  **Remaining Ones**: Any ones beyond the `(X-1) * K` minimum can be distributed anywhere (e.g., before the first zero, after the last zero, or added to any of the internal gaps). These extra ones do not affect the calculation of the *largest possible minimum* `K`.

Thus, the formula for the largest `K` is simply `Y / (X-1)`.

## Complexity Analysis

*   **Time Complexity**: The solution involves reading two `long long` integers, performing one subtraction, and one division, followed by printing the result. These are all constant-time operations. The `solve()` function is called `T` times. Therefore, the total time complexity is $O(T)$.
*   **Space Complexity**: The solution uses a few variables (`X`, `Y`, `K`, `T`) to store input and intermediate results. These consume a constant amount of memory regardless of the input values. Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries
using namespace std; // Use standard namespace

void solve() {
    // X: count of 0s
    // Y: count of 1s
    // K: minimum 1s between any two 0s
    // Using long long for X, Y, and K to handle values up to 10^9,
    // ensuring no overflow, although int might suffice for these specific constraints.
    long long X, Y; 
    cin >> X >> Y;

    // The problem states X >= 2.
    // If there are X zeros, they create X-1 "internal" segments (gaps)
    // between consecutive zeros.
    // For example:
    // If X=2, string is 0 [ones] 0. There is 1 gap. (X-1 = 1)
    // If X=3, string is 0 [ones] 0 [ones] 0. There are 2 gaps. (X-1 = 2)
    //
    // The condition "atleast K 1s between any two occurrences of 0s"
    // applies to these X-1 internal gaps.
    //
    // To satisfy this condition, each of these X-1 gaps must contain
    // at least K ones.
    // Therefore, the total number of ones required for these minimums is (X-1) * K.
    //
    // The total number of ones available is Y.
    // So, we must have: Y >= (X-1) * K
    //
    // To find the largest integer K, we rearrange the inequality:
    // K <= Y / (X-1)
    //
    // Since K must be an integer, the largest possible K is the floor of Y / (X-1).
    // In C++, integer division automatically performs floor for positive numbers.
    //
    // X-1 will always be at least 1 (since X >= 2), so division by zero is not a concern.

    long long K = Y / (X - 1);
    
    cout << K << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
```