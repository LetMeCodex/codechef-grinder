# [Gymkhana Election IIIT-A (CS2023_GYM)](https://www.codechef.com/problems/CS2023_GYM)
- **Difficulty Rating**: 629
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the minimum number of votes Om needs to secure a **strict majority win** in an election. There are `N` nominated members in total (including Om) and `M` total voters. A strict majority win means Om must receive strictly more votes than *any other* nominee. We need to find this minimum number of votes for Om, assuming the worst-case scenario where other nominees try to maximize their chances against Om.

## Intuition & Mathematical Observation

Let `V_Om` be the number of votes Om receives.
The condition for a strict majority win is that `V_Om` must be strictly greater than the votes received by any other nominee. That is, `V_Om > V_i` for all `i` where `i` is an opponent nominee.

To *ensure* this win, Om must consider the worst-case scenario. The worst-case scenario for Om is when the remaining `M - V_Om` votes (after Om has cast `V_Om` votes) are distributed among the `N-1` other nominees in a way that poses the biggest threat to Om.

The biggest threat occurs when all the remaining `M - V_Om` votes are consolidated and given to a *single* one of the other `N-1` nominees. This single opponent would then have the maximum possible votes among all other nominees. Let's call this maximum `V_opponent_max`.

So, in the worst-case:
`V_opponent_max = M - V_Om`

For Om to ensure a strict majority win, Om's votes must be strictly greater than this `V_opponent_max`:
`V_Om > V_opponent_max`

Substituting `V_opponent_max`:
`V_Om > M - V_Om`

Now, we solve this inequality for `V_Om`:
`2 * V_Om > M`
`V_Om > M / 2`

Since `V_Om` must be an integer (as it represents a number of votes), the smallest integer value for `V_Om` that satisfies `V_Om > M / 2` is `floor(M / 2) + 1`.

For example:
*   If `M = 10`, then `M / 2 = 5`. `V_Om > 5`, so the minimum integer `V_Om` is `6`. `floor(10/2) + 1 = 5 + 1 = 6`.
*   If `M = 11`, then `M / 2 = 5.5`. `V_Om > 5.5`, so the minimum integer `V_Om` is `6`. `floor(11/2) + 1 = 5 + 1 = 6`. (In C++ integer division, `11 / 2` evaluates to `5`).

The number of other nominees `N-1` (as long as it's at least 1, which is guaranteed by `N >= 2` in constraints) does not affect this calculation because the worst-case strategy for opponents is to concentrate all votes on a single candidate.

Therefore, the minimum number of votes Om needs is `M / 2 + 1` (using integer division for `M / 2`).

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    The solution involves a loop that iterates `T` times (for each test case). Inside the loop, we perform a constant number of operations: reading two `long long` integers, one arithmetic calculation (`M / 2 + 1`), and printing the result. Each of these operations takes constant time. Thus, the total time complexity is directly proportional to the number of test cases, `T`.

-   **Space Complexity**: $O(1)$
    The solution uses a fixed number of variables (`T`, `N`, `M`, `required_votes`) to store input and intermediate results. The memory usage does not depend on the input values `N` or `M`, or the number of test cases `T` beyond storing `T` itself. Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <iostream> // Required for standard input/output operations (cin, cout)

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Variable to store the number of test cases
    std::cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        long long N, M; // N: number of nominated members, M: total number of voters
                        // Using long long for N and M as they can be up to 10^9
        std::cin >> N >> M; // Read N and M for the current test case

        // Problem: Find the minimum number of votes Om requires to ensure a strict majority win.
        // A strict majority win means Om must have strictly more votes than any other nominee.
        // Let V_Om be the number of votes Om receives.
        // Let V_i be the votes for any other nominee i.
        // We need V_Om > V_i for all other nominees i.

        // To "ensure" this, we must consider the worst-case scenario for Om.
        // The worst-case scenario is when the other nominees try to maximize
        // the votes of one of their members to challenge Om.
        
        // If Om gets V_Om votes, then M - V_Om votes are remaining to be distributed
        // among the N-1 other nominees.
        
        // Since N >= 2 (as per constraints), there is at least one other nominee (N-1 >= 1).
        // In the worst case, all M - V_Om remaining votes could be given to a single
        // one of the other N-1 nominees.
        // Let's call this maximum possible votes for an opponent V_opponent_max.
        // V_opponent_max = M - V_Om.

        // For Om to ensure a strict majority win, Om's votes must be strictly greater
        // than V_opponent_max.
        // So, we need:
        // V_Om > M - V_Om

        // Now, solve for V_Om:
        // 2 * V_Om > M
        // V_Om > M / 2

        // Since V_Om must be an integer (number of votes), the smallest integer
        // that satisfies V_Om > M / 2 is floor(M / 2) + 1.
        // In C++ integer division, M / 2 automatically computes floor(M / 2) for positive M.
        long long required_votes = M / 2 + 1;

        // Output the result for the current test case, followed by a newline.
        std::cout << required_votes << "\n";
    }

    return 0; // Indicate successful execution
}
```