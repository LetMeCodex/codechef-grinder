# Exun Leaderboard (BETWEEN)
- **Difficulty Rating**: 213
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to find the number of distinct integer ranks that lie strictly between two given ranks, $X$ and $Y$. We are given that $1 \le X, Y \le 10$ and $X \neq Y$.

## Intuition & Mathematical Observation
Let the two given ranks be $X$ and $Y$. We are interested in the number of integers $k$ such that $\min(X, Y) < k < \max(X, Y)$.

Consider two cases:

1.  **$X < Y$**: The ranks strictly between $X$ and $Y$ are $X+1, X+2, \dots, Y-1$.
    The number of integers in this sequence is $(Y-1) - (X+1) + 1$.
    Simplifying this, we get $Y - 1 - X - 1 + 1 = Y - X - 1$.

2.  **$Y < X$**: The ranks strictly between $Y$ and $X$ are $Y+1, Y+2, \dots, X-1$.
    The number of integers in this sequence is $(X-1) - (Y+1) + 1$.
    Simplifying this, we get $X - 1 - Y - 1 + 1 = X - Y - 1$.

In both cases, the number of ranks strictly between $X$ and $Y$ is the absolute difference between $X$ and $Y$, minus 1. That is, $|\text{X} - \text{Y}| - 1$.

Let's verify with the constraints:
-   The minimum possible difference between $X$ and $Y$ is $|1 - 2| = 1$. In this case, $|\text{X} - \text{Y}| - 1 = 1 - 1 = 0$. This is correct, as there are no integers strictly between two consecutive integers.
-   The maximum possible difference between $X$ and $Y$ is $|1 - 10| = 9$. In this case, $|\text{X} - \text{Y}| - 1 = 9 - 1 = 8$. If $X=1$ and $Y=10$, the ranks strictly between them are $2, 3, 4, 5, 6, 7, 8, 9$, which are indeed 8 ranks.

The constraints on $X$ and $Y$ are very small ($1 \le X, Y \le 10$), so standard integer types are sufficient.

## Complexity Analysis
-   **Time Complexity**: $O(1)$
    The solution involves a single subtraction and an absolute value operation, which are constant time operations.
-   **Space Complexity**: $O(1)$
    The solution uses a fixed amount of memory to store the input variables and the result, regardless of the input values.

## Solution Code
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C stdio.
    // cin.tie(NULL) unties cin from cout, so cin operations don't flush cout.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    // Read the two ranks from standard input.
    cin >> x >> y;

    // The problem asks for the number of teams strictly between rank X and rank Y.
    // This means we need to count the integers k such that min(X, Y) < k < max(X, Y).
    //
    // The number of integers strictly between two distinct integers A and B is |A - B| - 1.
    // For example, if A=3 and B=7, the integers strictly between them are 4, 5, 6.
    // The count is 3. Using the formula: |3 - 7| - 1 = |-4| - 1 = 4 - 1 = 3.
    // If A=7 and B=3, the integers strictly between them are 4, 5, 6.
    // The count is 3. Using the formula: |7 - 3| - 1 = |4| - 1 = 4 - 1 = 3.
    //
    // The constraints are 1 <= X, Y <= 10 and X != Y.
    // The maximum difference |X - Y| is |1 - 10| = 9.
    // The minimum difference |X - Y| is |1 - 2| = 1.
    //
    // If |X - Y| = 1, the result is 1 - 1 = 0, which is correct as there are no ranks strictly between consecutive ranks.
    // If |X - Y| = 9, the result is 9 - 1 = 8, which is correct for ranks 1 and 10 (ranks 2 through 9).
    //
    // The `abs()` function from `<cmath>` or `<cstdlib>` (included by `<bits/stdc++.h>`)
    // computes the absolute value of an integer.
    cout << abs(x - y) - 1 << "\n";

    return 0;
}
```