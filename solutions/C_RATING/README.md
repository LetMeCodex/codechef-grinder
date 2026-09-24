# [Chess Ratings (C_RATING)](https://www.codechef.com/problems/C_RATING)
- **Difficulty Rating**: 651
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the minimum number of games a player must win to reach a target chess rating. We are given the player's current rating `X` and a target rating `Y`. We are guaranteed that `X <= Y`. Each game won increases the player's rating by 8 points. Losses and draws do not change the rating. We need to find the minimum number of wins required to achieve a rating of at least `Y`.

## Intuition & Mathematical Observation

1.  **Calculate the Rating Difference Needed**: The first step is to determine how many rating points the player needs to gain. This is simply the difference between the target rating `Y` and the current rating `X`. Let `diff = Y - X`. Since `X <= Y`, `diff` will always be non-negative.

2.  **Points per Win**: Each win contributes exactly 8 points to the rating.

3.  **Minimum Wins**: We need to find the minimum number of wins, let's call it `W`, such that `W * 8 >= diff`.
    To find `W`, we can divide the total `diff` by the points gained per win (8): `W = diff / 8`.
    However, since `W` must be an integer and we need to reach *at least* `Y`, we must use the ceiling function. That is, `W = ceil(diff / 8)`.

4.  **Ceiling Division for Integers**: For non-negative integer `A` and positive integer `B`, `ceil(A / B)` can be calculated using integer division as `(A + B - 1) / B`.
    In our case, `A = diff` and `B = 8`. So, the number of games needed is `(diff + 8 - 1) / 8`, which simplifies to `(diff + 7) / 8`.

    Let's test this formula:
    *   If `diff = 0` (X = Y), `(0 + 7) / 8 = 0`. Correct, 0 games needed.
    *   If `diff = 1` (e.g., X=1000, Y=1001), `(1 + 7) / 8 = 8 / 8 = 1`. Correct, 1 win gives 8 points, which is enough.
    *   If `diff = 8` (e.g., X=1000, Y=1008), `(8 + 7) / 8 = 15 / 8 = 1`. Correct, 1 win is exactly enough.
    *   If `diff = 9` (e.g., X=1000, Y=1009), `(9 + 7) / 8 = 16 / 8 = 2`. Correct, 1 win (8 points) is not enough, 2 wins (16 points) are needed.

This formula correctly handles all cases.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    For each test case, the solution performs a constant number of arithmetic operations (subtraction, addition, division) and input/output operations. These operations take constant time regardless of the magnitude of `X` and `Y` (within integer limits). If there are `T` test cases, the total time complexity will be $O(T)$.

-   **Space Complexity**: $O(1)$
    The solution uses a fixed number of integer variables (`X`, `Y`, `diff`, `games_needed`, `T`). The memory usage does not depend on the input values or the number of test cases, making the space complexity constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries, as requested

using namespace std; // Uses the standard namespace, as requested

void solve() {
    int X, Y;
    cin >> X >> Y; // Read current rating X and target rating Y

    // Calculate the difference needed in rating.
    // Since X <= Y, diff will always be non-negative.
    int diff = Y - X;

    // The number of games needed is ceil(diff / 8).
    // For non-negative integer 'diff' and positive integer 'divisor' (8 in this case),
    // ceil(diff / divisor) can be calculated using integer division as:
    // (diff + divisor - 1) / divisor
    int games_needed = (diff + 8 - 1) / 8; // This simplifies to (diff + 7) / 8

    cout << games_needed << "\n"; // Output the result followed by a newline
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}
```