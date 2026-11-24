# [Download file (DWNLD)](https://www.codechef.com/problems/DWNLD)
- **Difficulty Rating**: 1147
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef wants to download a file, which is divided into `N` usage periods. For each period `i`, the download takes `Ti` minutes and consumes `Di` MBs per minute. Chef has `K` free minutes initially. He only has to pay for the download minutes *after* these `K` free minutes have been completely used up. The cost for a paid minute is `Di` (MBs per minute). The task is to calculate the total amount Chef has to pay.

## Intuition & Mathematical Observation

The problem asks us to simulate the download process while keeping track of the remaining free minutes. The core idea is to prioritize using the free minutes first.

We can iterate through each of the `N` usage periods. For each period, we consider the `Ti` minutes it takes and the `Di` MBs per minute cost.

1.  **Check for remaining free minutes (`K`):**
    *   If `K > 0` (there are still free minutes available):
        *   **Case 1: Current period's minutes (`Ti`) are less than or equal to `K`:**
            This means the entire current period is covered by the free minutes. We use `Ti` free minutes, so we subtract `Ti` from `K`. No cost is incurred for this period.
        *   **Case 2: Current period's minutes (`Ti`) are greater than `K`:**
            This means the free minutes `K` will cover only a part of the current period. The first `K` minutes of this period are free. The remaining `(Ti - K)` minutes will be paid. We calculate the cost for these paid minutes as `(Ti - K) * Di` and add it to our `total_cost`. After this, all free minutes are exhausted, so we set `K = 0`.
    *   If `K == 0` (no free minutes left):
        *   All minutes in the current period (and any subsequent periods) must be paid for. We calculate the cost for this period as `Ti * Di` and add it to `total_cost`.

We continue this process for all `N` periods. Finally, the accumulated `total_cost` will be our answer.

## Complexity Analysis

*   **Time Complexity**: $O(N)$ per test case.
    The solution involves a single loop that iterates `N` times (for each usage period). Inside the loop, all operations (comparisons, additions, subtractions, multiplications) are constant time. If there are `TC` test cases, the total time complexity would be $O(TC \cdot N)$. Given `TC <= 100` and `N <= 10`, the maximum operations are roughly $100 \cdot 10 = 1000$, which is extremely efficient.

*   **Space Complexity**: $O(1)$.
    The solution uses a fixed number of variables (`TC`, `N`, `K`, `total_cost`, `Ti`, `Di`) regardless of the input size `N`. No auxiliary data structures are used that grow with `N`.

## Solution Code

```cpp
#include <bits/stdc++.h> 

// Using namespace std; as per instructions
using namespace std;

int main() {
    // Fast I/O as per instructions
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TC; // Number of test cases
    cin >> TC;
    while (TC--) {
        int N; // Number of usage periods
        int K; // Free minutes
        cin >> N >> K;

        int total_cost = 0; // Total amount Chef has to pay.
                            // Max cost: N * Ti * Di = 10 * 10 * 10 = 1000. Fits comfortably in an int.

        for (int i = 0; i < N; ++i) {
            int Ti, Di; // Minutes and MBs per minute for current period
            cin >> Ti >> Di;

            if (K > 0) {
                // If there are still free minutes left
                if (Ti <= K) {
                    // Current period is entirely covered by free minutes
                    K -= Ti;
                    // No cost for this period, total_cost remains unchanged
                } else {
                    // Current period is partially covered by free minutes
                    // The first 'K' minutes are free.
                    // The remaining 'Ti - K' minutes are paid.
                    total_cost += (Ti - K) * Di;
                    K = 0; // All free minutes are now used up
                }
            } else {
                // No free minutes left, all minutes are paid
                total_cost += Ti * Di;
            }
        }
        cout << total_cost << "\n"; // Output total cost for the test case
    }

    return 0;
}
```