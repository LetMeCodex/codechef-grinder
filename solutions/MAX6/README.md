# [Max Sixers (MAX6)](https://www.codechef.com/problems/MAX6)
- **Difficulty Rating**: 216
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the maximum possible number of sixers (balls scoring 6 runs) in a 100-ball cricket match, given the total runs `X` scored in the match. Each ball can score 0, 1, 2, 3, 4, or 6 runs.

## Intuition & Mathematical Observation

To maximize the number of sixers, we should try to make each sixer contribute 6 runs, and all other balls contribute as few runs as possible. The minimum runs a ball can score is 0.

Let `S` be the number of sixers.
1.  **Runs from Sixers**: Each sixer contributes 6 runs. So, `S` sixers contribute `6 * S` runs.
2.  **Remaining Runs**: The total runs `X` must be accounted for. After `S` sixers, the remaining runs are `X - 6 * S`.
3.  **Remaining Balls**: Since there are 100 balls in total, the number of balls that are *not* sixers is `100 - S`.
4.  **Constraints on Remaining Balls**: Each of these `100 - S` balls can score 0, 1, 2, 3, or 4 runs (since 6 runs would make them a sixer).
    *   The minimum runs these `100 - S` balls can contribute is `0 * (100 - S) = 0`.
    *   The maximum runs these `100 - S` balls can contribute is `4 * (100 - S)`.

Combining these observations, we get the following inequalities:

*   **Total runs from sixers cannot exceed X**:
    `6 * S <= X`
    This implies `S <= X / 6`. To maximize `S`, we would initially consider `S = floor(X / 6)`.

*   **Remaining runs must be achievable by remaining balls**:
    The `X - 6 * S` runs must be scored by `100 - S` balls, where each ball scores between 0 and 4 runs.
    So, `0 * (100 - S) <= X - 6 * S <= 4 * (100 - S)`.

Let's analyze these two parts of the inequality:

1.  **`X - 6 * S >= 0`**:
    This is equivalent to `6 * S <= X`, which is already covered by our first observation `S <= X / 6`. If we choose `S = floor(X / 6)`, this condition is always satisfied.

2.  **`X - 6 * S <= 4 * (100 - S)`**:
    Let's simplify this:
    `X - 6 * S <= 400 - 4 * S`
    `X - 400 <= 2 * S`
    `S >= (X - 400) / 2`

So, to maximize `S`, we need to find the largest integer `S` that satisfies both:
1.  `S <= X / 6`
2.  `S >= (X - 400) / 2`

Now, let's consider the given constraints on `X`: `100 <= X <= 200`.

*   **For `S <= X / 6`**:
    *   Minimum `X = 100`: `S <= 100 / 6 = 16.66...`, so `S <= 16`.
    *   Maximum `X = 200`: `S <= 200 / 6 = 33.33...`, so `S <= 33`.
    The smallest possible value for `floor(X / 6)` is `floor(100 / 6) = 16`.

*   **For `S >= (X - 400) / 2`**:
    *   Minimum `X = 100`: `S >= (100 - 400) / 2 = -300 / 2 = -150`.
    *   Maximum `X = 200`: `S >= (200 - 400) / 2 = -200 / 2 = -100`.
    The largest possible value for `(X - 400) / 2` is `-100`.

Since `S` must be a non-negative number (you can't have negative sixers), and the smallest possible value for `S` from `floor(X / 6)` is 16, the condition `S >= (X - 400) / 2` (which gives a lower bound of at most -100) is always satisfied. For example, if `S=16`, `16 >= -100` is true.

Therefore, the only effective constraint for maximizing `S` is `S <= X / 6`. The maximum integer value for `S` is simply `X / 6` using integer division (which automatically performs `floor`).

## Complexity Analysis

*   **Time Complexity**: The solution involves reading a single integer `X` and performing one integer division. These are constant time operations. Thus, the time complexity is $O(1)$.

*   **Space Complexity**: The solution uses a single integer variable `X` to store the input. This requires a constant amount of memory. Thus, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Required header for competitive programming

// Use the standard namespace for convenience
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read the total number of runs scored.
    // The problem statement indicates a single test case: "The first and only line of input contains X".
    int X;
    cin >> X;

    // To maximize the number of sixers, we assume that all other balls (non-sixers)
    // score the minimum possible runs (0 runs).
    // Let S be the number of sixers.
    // Each sixer contributes 6 runs.
    // The total runs from S sixers is 6 * S.
    // This value cannot exceed the total runs X.
    // So, 6 * S <= X.
    // To maximize S, we take the largest integer S that satisfies this:
    // S = floor(X / 6).
    //
    // We also need to ensure that the remaining runs (X - 6 * S) can be scored
    // from the remaining balls (100 - S), with each of those balls scoring
    // between 0 and 4 runs.
    //
    // The minimum runs from (100 - S) balls is 0.
    // The maximum runs from (100 - S) balls is 4 * (100 - S).
    // So, 0 <= X - 6 * S <= 4 * (100 - S).
    //
    // The left inequality (X - 6 * S >= 0) is satisfied because S = floor(X / 6).
    // The right inequality (X - 6 * S <= 4 * (100 - S)) simplifies to S >= (X - 400) / 2.
    //
    // Given the constraints 100 <= X <= 200:
    // - The maximum value for floor(X / 6) is floor(200 / 6) = 33.
    // - The minimum value for ceil((X - 400) / 2) is ceil((100 - 400) / 2) = ceil(-150) = -150.
    //
    // Since floor(X / 6) (which is at least 16 for X=100) is always greater than or equal
    // to ceil((X - 400) / 2) (which is always negative for the given X range),
    // the condition S >= (X - 400) / 2 is always met by S = floor(X / 6).
    //
    // Therefore, the maximum number of sixers is simply X / 6 (using integer division).
    cout << X / 6 << "\n";

    return 0;
}
```