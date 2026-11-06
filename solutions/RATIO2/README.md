# [Ratio By 2 (RATIO2)](https://www.codechef.com/problems/RATIO2)
- **Difficulty Rating**: 1035
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum number of operations required to satisfy one of two conditions: $X \ge 2Y$ or $Y \ge 2X$. An operation consists of changing $X$ to $X+1$, $X-1$, $Y$ to $Y+1$, or $Y-1$. We are given initial values for $X$ and $Y$, where $1 \le X, Y \le 10$.

## Intuition & Mathematical Observation

1.  **Goal**: We want to transform the initial pair $(X, Y)$ into a new pair $(X', Y')$ such that either $X' \ge 2Y'$ or $Y' \ge 2X'$.
2.  **Cost of Transformation**: The number of operations to change $X$ to $X'$ and $Y$ to $Y'$ is $|X - X'| + |Y - Y'|$. Our objective is to minimize this sum.
3.  **Base Case**: If the initial values $X, Y$ already satisfy $X \ge 2Y$ or $Y \ge 2X$, then no operations are needed, and the answer is 0.
4.  **Minimizing Operations for a Condition**:
    *   **Condition 1: $X' \ge 2Y'$**: To minimize $|X - X'| + |Y - Y'|$ while ensuring $X' \ge 2Y'$, the most efficient choice for $X'$ for a given $Y'$ is $X' = 2Y'$. Any $X'' > 2Y'$ would only increase $|X - X''|$ without further benefit. So, we want to minimize $|X - 2Y'| + |Y - Y'|$.
    *   **Condition 2: $Y' \ge 2X'$**: Similarly, for a given $X'$, the most efficient choice for $Y'$ is $Y' = 2X'$. We want to minimize $|X - X'| + |Y - 2X'|$.
5.  **Small Constraints**: The crucial observation is that $X$ and $Y$ are very small ($1 \le X, Y \le 10$). This implies that the optimal target values $X'$ and $Y'$ will also be relatively small.
    *   Consider the function $f(k) = |A - Bk| + |C - k|$. This is a sum of absolute value functions, which is a convex function. Its minimum can be found by checking values around the "centers" $C$ and $A/B$.
    *   Since $X, Y \le 10$, the maximum possible operations to reach a state like $(20, 10)$ from $(1, 1)$ is $|1-20| + |1-10| = 19+9=28$.
    *   If we consider target values $Y'$ (or $X'$) much larger than 10, say $Y'=100$, then $X'=200$. The operations would be roughly $|X-200| + |Y-100|$, which is very large.
    *   Given the small initial values, iterating through a small range of possible target values for $X'$ and $Y'$ (e.g., from 1 up to 10 or 20) is sufficient to find the minimum operations. The provided solution iterates from 1 to 10, which is indeed sufficient for $X, Y \le 10$. For example, if $X=10, Y=10$, the optimal $Y'$ for $X' \ge 2Y'$ is $Y'=5$ (leading to $X'=10$), with 5 operations. If $X=1, Y=10$, the optimal $X'$ for $Y' \ge 2X'$ is $X'=5$ (leading to $Y'=10$), with 4 operations. These optimal $X', Y'$ values are within the $[1, 10]$ range.

6.  **Algorithm**:
    *   Initialize `min_ops` to a very large value (e.g., `INT_MAX`).
    *   Check the base case: if $X \ge 2Y$ or $Y \ge 2X$, print 0 and return.
    *   **For Condition 1 ($X' \ge 2Y'$):**
        *   Iterate `target_Y` from 1 to 10 (or a slightly larger small constant if unsure, but 10 is enough here).
        *   For each `target_Y`, calculate the required `target_X = 2 * target_Y`.
        *   Calculate `current_ops = abs(X - target_X) + abs(Y - target_Y)`.
        *   Update `min_ops = min(min_ops, current_ops)`.
    *   **For Condition 2 ($Y' \ge 2X'$):**
        *   Iterate `target_X` from 1 to 10.
        *   For each `target_X`, calculate the required `target_Y = 2 * target_X`.
        *   Calculate `current_ops = abs(X - target_X) + abs(Y - target_Y)`.
        *   Update `min_ops = min(min_ops, current_ops)`.
    *   Print the final `min_ops`.

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    *   The `solve()` function contains two independent loops. Each loop iterates a fixed number of times (10 iterations). Inside the loops, operations like `abs`, `+`, `-`, and `std::min` take constant time.
    *   Therefore, the time taken for one test case is constant, specifically $2 \times 10 = 20$ iterations, each with a few constant-time operations.
    *   Since there are $T$ test cases, the total time complexity is $O(T)$. Given $T \le 1000$, this is extremely efficient ($1000 \times 20 = 20000$ operations in total).

*   **Space Complexity**: $O(1)$
    *   The solution uses a fixed number of integer variables (`X`, `Y`, `min_ops`, `target_Y`, `target_X`, `current_ops`). These variables consume a constant amount of memory regardless of the input values.

## Solution Code

```cpp
#include <iostream> // Required for cin, cout
#include <algorithm> // Required for std::min, std::abs
#include <climits>   // Required for INT_MAX

// Using namespace std; as requested by problem instructions
using namespace std;

void solve() {
    int X, Y;
    cin >> X >> Y;

    // Check if the condition is already met
    if (X >= 2 * Y || Y >= 2 * X) {
        cout << 0 << "\n";
        return;
    }

    // Initialize minimum operations to a very large value
    int min_ops = INT_MAX;

    // Option 1: Achieve X' >= 2Y' by changing X and/or Y
    // Iterate through possible target values for Y'
    // Since X, Y <= 10, the optimal Y' will not exceed 10 by much,
    // and iterating up to 10 is sufficient to find the minimum.
    for (int target_Y = 1; target_Y <= 10; ++target_Y) {
        // To satisfy X' >= 2*target_Y, the minimum X' is 2*target_Y.
        // Operations needed: |X - (2*target_Y)| + |Y - target_Y|
        int current_ops = abs(X - (2 * target_Y)) + abs(Y - target_Y);
        min_ops = min(min_ops, current_ops);
    }

    // Option 2: Achieve Y' >= 2X' by changing X and/or Y
    // Iterate through possible target values for X'
    // Similar reasoning as above, X' from 1 to 10 is sufficient.
    for (int target_X = 1; target_X <= 10; ++target_X) {
        // To satisfy Y' >= 2*target_X, the minimum Y' is 2*target_X.
        // Operations needed: |X - target_X| + |Y - (2*target_X)|
        int current_ops = abs(X - target_X) + abs(Y - (2 * target_X));
        min_ops = min(min_ops, current_ops);
    }

    cout << min_ops << "\n";
}

int main() {
    // Fast I/O as requested by problem instructions
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
```