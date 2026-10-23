# [Winning World Finals (WFWIN)](https://www.codechef.com/problems/WFWIN)
- **Difficulty Rating**: 1146
- **Solved in**: 2 attempt(s)

## Problem Summary

The problem asks us to determine the maximum number of wrong submissions (`W`) a team can make while still "winning" the World Finals. Winning conditions are defined by two constraints:
1.  The total penalty accumulated must not exceed 1000.
2.  The correct submission must be made strictly before the 300th minute (i.e., at or before minute 299).

We are given two initial values:
*   `M`: The minute at which the *first* submission (which could be wrong or correct) is made.
*   `P`: The initial penalty accumulated *before* any submissions are made in this contest.

Penalties are calculated as follows:
*   Each wrong submission adds 20 penalty points.
*   The correct submission adds penalty points equal to the minute it was submitted.

We need to output the maximum possible `W`.

## Intuition & Mathematical Observation

To maximize the number of wrong submissions (`W`), we must minimize the penalty incurred by the correct submission and the time it takes. This means we should make the correct submission as early as possible after `W` wrong submissions.

Let `W` be the number of wrong submissions.
Let `X_c` be the minute the correct submission is made.

**Strategy for minimizing `X_c`:**
To make `W` wrong submissions and then one correct submission as early as possible, we should submit continuously, one minute after another.
*   The first submission (wrong) is made at minute `M`.
*   The second submission (wrong) is made at minute `M+1`.
*   ...
*   The `W`-th wrong submission is made at minute `M + W - 1`.
*   The correct submission is then made immediately after the `W`-th wrong submission, at minute `M + W`.

So, we establish the relationship: `X_c = M + W`.

Now, let's apply the given constraints to find the maximum `W`.

**Constraint 1: Total Penalty <= 1000**

The total penalty is the sum of:
*   Initial penalty: `P`
*   Penalty from `W` wrong submissions: `W * 20`
*   Penalty from the correct submission time: `X_c`

Total Penalty = `P + (W * 20) + X_c`

Substitute `X_c = M + W` into the equation:
Total Penalty = `P + (W * 20) + (M + W)`
Total Penalty = `P + M + (21 * W)`

The constraint is:
`P + M + (21 * W) <= 1000`

We need to find the maximum `W` that satisfies this. Rearranging the inequality:
`21 * W <= 1000 - P - M`
`W <= (1000 - P - M) / 21`

Let `penalty_budget_for_W = 1000 - P - M`.
If `penalty_budget_for_W` is negative (meaning `P + M` alone already exceeds 1000), then even with zero wrong submissions, the penalty limit is breached. In this case, `W` must be 0. Otherwise, `W` is `penalty_budget_for_W / 21` (using integer division, which naturally floors the result for non-negative dividends).
So, `max_w_by_penalty = max(0, (1000 - P - M) / 21)`.

**Constraint 2: Correct submission strictly before the 300th minute**

This means `X_c < 300`, or equivalently, `X_c <= 299`.

Substitute `X_c = M + W`:
`M + W <= 299`

Rearranging to find the maximum `W` that satisfies this:
`W <= 299 - M`

Let `max_w_by_time = 299 - M`.
Since the problem states `M < 300`, `299 - M` will always be non-negative.

**Final Result:**

The maximum number of wrong submissions `W` must satisfy both constraints simultaneously. Therefore, `W` is the minimum of the maximums allowed by each constraint:
`W = min(max_w_by_penalty, max_w_by_time)`

## Complexity Analysis

*   **Time Complexity**: The `solve()` function performs a fixed number of arithmetic operations (subtractions, multiplications, divisions, comparisons, and `std::min`). These operations take constant time. The `main()` function calls `solve()` `T` times, where `T` is the number of test cases. Therefore, the total time complexity is $O(T)$.

*   **Space Complexity**: The `solve()` function uses a few integer variables to store `M`, `P`, intermediate calculations, and the final result. These variables occupy a constant amount of memory, regardless of the input values. Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <cstdio>    // Required for scanf, printf
#include <algorithm> // Required for std::min

// Function to solve a single test case
void solve() {
    int M, P;
    // Use scanf for faster input
    scanf("%d %d", &M, &P);

    // To maximize the number of wrong submissions (W), we must minimize the
    // penalty incurred by the correct submission.
    // The earliest possible time for the correct submission, after W wrong
    // submissions, is M + W. This is because:
    // 1. The first submission can be made at minute M.
    // 2. Each wrong submission requires at least one minute wait before the next.
    // So, W wrong submissions would be made at M, M+1, ..., M+W-1.
    // The correct submission would then be made at M+W.
    // Let X_c be the time of the correct submission. We assume X_c = M + W.

    // Constraint 1: Total penalty must be <= 1000
    // Initial Penalty (P) + Penalty from W wrong submissions (W * 20) + Penalty from correct submission time (X_c) <= 1000
    // Substituting X_c = M + W:
    // P + (W * 20) + (M + W) <= 1000
    // P + M + (21 * W) <= 1000
    // 21 * W <= 1000 - P - M
    // W <= (1000 - P - M) / 21

    // Calculate the maximum W based on the penalty budget.
    int penalty_budget_for_W = 1000 - P - M;
    int max_w_by_penalty;
    if (penalty_budget_for_W < 0) {
        // If P + M > 1000, even with 0 wrong submissions and the earliest correct submission (at M),
        // the total penalty (P + M) already exceeds 1000.
        // In this scenario, no wrong submissions can be made while winning.
        max_w_by_penalty = 0;
    } else {
        // Otherwise, calculate how many wrong submissions are allowed by the penalty budget.
        // Integer division naturally floors the result for non-negative dividend.
        max_w_by_penalty = penalty_budget_for_W / 21;
    }

    // Constraint 2: The correct submission must be made strictly before the 300th minute.
    // X_c <= 299
    // Substituting X_c = M + W:
    // M + W <= 299
    // W <= 299 - M

    // Calculate the maximum W based on time availability.
    int max_w_by_time = 299 - M; // This will always be non-negative as M < 300.

    // The maximum number of wrong submissions is limited by both the penalty budget
    // and the available time. We take the minimum of these two limits.
    // Both max_w_by_penalty and max_w_by_time are guaranteed to be non-negative.
    int result = std::min(max_w_by_penalty, max_w_by_time);
    
    // Use printf for faster output
    printf("%d\n", result);
}

int main() {
    // No need for std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); with scanf/printf
    int T; // Number of test cases
    scanf("%d", &T);
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}
```