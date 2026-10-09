# [Valentine Gifts (VAL142)](https://www.codechef.com/problems/VAL142)
- **Difficulty Rating**: 729
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef wants to buy 7 gifts for Valentine's Day. There are specific conditions for the gift values:
1.  Each gift must have a positive integer value.
2.  Each subsequent gift must have a value at least twice the value of the previous gift.

Chef has a budget `X`. The task is to determine if it's possible for Chef to buy 7 gifts satisfying these conditions within the given budget.

## Intuition & Mathematical Observation

To determine if it's *possible* to buy 7 gifts, we need to find the *absolute minimum total cost* required to satisfy all the conditions. If Chef's budget `X` is less than this minimum cost, then it's impossible. If `X` is greater than or equal to this minimum cost, it's always possible (Chef can buy the minimum cost set of gifts, and any remaining budget can be used to increase the value of one or more gifts without violating the conditions).

Let the values of the 7 gifts be $g_1, g_2, g_3, g_4, g_5, g_6, g_7$.

The conditions are:
*   $g_i > 0$ for all $i$ (positive integer values).
*   $g_i \ge 2 \times g_{i-1}$ for $i > 1$.

To minimize the total sum $\sum_{i=1}^7 g_i$, we must minimize each individual $g_i$.

1.  **Minimizing $g_1$**: Since $g_1$ must be a positive integer, its smallest possible value is $1$. So, $g_1 = 1$.
2.  **Minimizing $g_2$**: $g_2 \ge 2 \times g_1$. To minimize $g_2$, we choose $g_2 = 2 \times g_1 = 2 \times 1 = 2$.
3.  **Minimizing $g_3$**: $g_3 \ge 2 \times g_2$. To minimize $g_3$, we choose $g_3 = 2 \times g_2 = 2 \times 2 = 4$.
4.  This pattern continues for all subsequent gifts. Each gift's value is exactly twice the previous one to achieve the minimum possible value while satisfying the condition.

The sequence of minimum gift values will be:
*   $g_1 = 1$
*   $g_2 = 2$
*   $g_3 = 4$
*   $g_4 = 8$
*   $g_5 = 16$
*   $g_6 = 32$
*   $g_7 = 64$

This is a geometric progression where the first term is 1 and the common ratio is 2.

Now, we calculate the total minimum cost by summing these values:
Total Minimum Cost $= 1 + 2 + 4 + 8 + 16 + 32 + 64 = 127$.

Therefore, if Chef's budget `X` is less than 127, it's impossible to buy 7 gifts satisfying the conditions. If `X` is 127 or more, Chef can always buy the gifts with values $[1, 2, 4, 8, 16, 32, 64]$, which cost exactly 127. Since $127 \le X$, this plan is valid.

The solution simply involves checking if $X \ge 127$.

## Complexity Analysis

*   **Time Complexity**: For each test case, we perform a constant number of operations: reading an integer, comparing it with a fixed value (127), and printing a string. This takes $O(1)$ time per test case. If there are $T$ test cases, the total time complexity is $O(T)$.
*   **Space Complexity**: We only use a few integer variables (`T`, `X`) to store input and loop counters. This requires a constant amount of memory, $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries, as requested
using namespace std;     // Uses the standard namespace, as requested

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int X; // Variable to store Chef's budget for the current test case
        cin >> X; // Read the budget X

        // To satisfy the conditions with the minimum possible total cost,
        // Chef should choose the smallest possible positive integer for the first gift,
        // which is 1.
        // For subsequent gifts, to minimize their values while satisfying
        // "at least twice the value of previous gift", Chef should choose
        // exactly twice the value of the previous gift.
        //
        // Let the gift values be g1, g2, g3, g4, g5, g6, g7.
        // g1 = 1 (smallest positive integer)
        // g2 = 2 * g1 = 2
        // g3 = 2 * g2 = 4
        // g4 = 2 * g3 = 8
        // g5 = 2 * g4 = 16
        // g6 = 2 * g5 = 32
        // g7 = 2 * g6 = 64
        //
        // The total minimum cost for these 7 gifts would be:
        // 1 + 2 + 4 + 8 + 16 + 32 + 64 = 127.
        //
        // If Chef's budget X is less than 127, it's impossible to buy 7 gifts
        // satisfying the conditions, because even the absolute minimum cost
        // exceeds the budget.
        // If Chef's budget X is 127 or more, he can always buy the gifts
        // with values [1, 2, 4, 8, 16, 32, 64], which cost exactly 127.
        // Since 127 <= X, this plan is valid.
        // The remaining budget (X - 127) can be used to increase the value
        // of the last gift (or any other gift) if desired, but it's not
        // necessary to find such a specific plan, only to determine if one exists.

        if (X >= 127) {
            cout << "YES\n"; // If budget is sufficient, print YES
        } else {
            cout << "NO\n"; // Otherwise, print NO
        }
    }

    return 0; // Indicate successful execution
}
```