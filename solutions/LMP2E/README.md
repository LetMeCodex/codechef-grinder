# [Winter is Coming (LMP2E)](https://www.codechef.com/problems/LMP2E)
- **Difficulty Rating**: 723
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef experiences `N` different temperatures $T_1, T_2, \dots, T_N$ over `N` days. He wants to be comfortable each day. Chef has a jacket, and his comfort rules are interpreted as follows (common for this type of problem, and consistent with the provided solution code):

*   If the temperature $T_i$ is less than $A$ ($T_i < A$), Chef *must* wear a jacket to be comfortable.
*   If the temperature $T_i$ is greater than $B$ ($T_i > B$), Chef *must not* wear a jacket to be comfortable.
*   If the temperature $T_i$ is between $A$ and $B$ inclusive ($A \le T_i \le B$), Chef is comfortable *either* with or without a jacket.

Chef starts the first day without a jacket. We need to find the minimum number of times Chef puts on his jacket throughout the `N` days. Removing a jacket does not count towards this total.

## Intuition & Mathematical Observation

The core idea is to process the temperatures day by day and make decisions greedily to minimize the "put on jacket" actions. We maintain a boolean variable, `has_jacket`, to track whether Chef is currently wearing the jacket. `wear_count` stores the total number of times Chef has put on the jacket. Chef starts without a jacket, so `has_jacket` is initially `false` and `wear_count` is `0`.

Let's analyze the three possible scenarios for each day's temperature $T_i$:

1.  **$T_i < A$ (Too cold without a jacket):**
    *   In this situation, Chef *must* wear a jacket to be comfortable.
    *   If `has_jacket` is currently `false` (Chef is not wearing a jacket), he needs to put it on. We increment `wear_count` and set `has_jacket = true`.
    *   If `has_jacket` is already `true` (Chef is already wearing a jacket), he remains comfortable, and no action is needed.

2.  **$T_i > B$ (Too hot with a jacket):**
    *   In this situation, Chef *must not* wear a jacket to be comfortable.
    *   If `has_jacket` is currently `true` (Chef is wearing a jacket), he needs to take it off. We set `has_jacket = false`. This action does not increment `wear_count` as per the problem statement.
    *   If `has_jacket` is already `false` (Chef is not wearing a jacket), he remains comfortable, and no action is needed.

3.  **$A \le T_i \le B$ (Comfortable either way):**
    *   In this situation, Chef is comfortable whether he wears a jacket or not.
    *   To minimize the `wear_count`, Chef should avoid putting on a jacket unnecessarily. The best strategy here is to *maintain his current state*.
    *   If `has_jacket` is `true`, he continues wearing it.
    *   If `has_jacket` is `false`, he continues not wearing it.
    *   In both cases, no action is taken, and `wear_count` remains unchanged.

By following this greedy strategy, we ensure that Chef only puts on a jacket when absolutely necessary. Since taking off a jacket is "free" (doesn't count towards `wear_count`), this strategy is optimal.

## Complexity Analysis

*   **Time Complexity**: The solution iterates through the `N` temperatures exactly once for each test case. Inside the loop, all operations (comparisons, assignments) are constant time. Therefore, the time complexity for processing `N` temperatures is $O(N)$. Given `T` test cases, the total time complexity will be $O(T \cdot N)$.
*   **Space Complexity**: The solution uses a fixed number of variables (`N`, `A`, `B`, `wear_count`, `has_jacket`, `T_i`) regardless of the input size `N`. Thus, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Required include as per problem instructions

// Using namespace std; as per problem instructions
using namespace std;

void solve() {
    int N, A, B;
    cin >> N >> A >> B;
    
    int wear_count = 0;
    bool has_jacket = false; // Chef is not wearing a jacket initially
    
    for (int i = 0; i < N; ++i) {
        int T_i;
        cin >> T_i;
        
        if (T_i < A) {
            // Chef must wear a jacket to be comfortable.
            // (Since T_i < A and A <= B, it implies T_i <= B, so wearing a jacket works).
            if (!has_jacket) {
                // If not currently wearing, Chef puts on a jacket.
                wear_count++;
                has_jacket = true;
            }
            // If already wearing, Chef remains comfortable. No action needed.
        } else if (T_i > B) {
            // Chef must remove the jacket to be comfortable.
            // (Since T_i > B and B >= A, it implies T_i >= A, so not wearing a jacket works).
            has_jacket = false; // Removing a jacket doesn't count as an action.
            // If already not wearing, Chef remains comfortable. No action needed.
        } else { // A <= T_i <= B
            // Chef can be comfortable either with or without a jacket.
            // To minimize wear_count, Chef should maintain his current state.
            // If has_jacket is false: Chef is comfortable (T_i >= A). Stays without jacket.
            // If has_jacket is true: Chef is comfortable (T_i <= B). Stays with jacket.
            // In both cases, no change to has_jacket or wear_count is needed.
        }
    }
    
    cout << wear_count << "\n";
}

int main() {
    // Fast I/O as per problem instructions
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
```