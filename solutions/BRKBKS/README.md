# [Breaking Bricks (BRKBKS)](https://www.codechef.com/problems/BRKBKS)
- **Difficulty Rating**: 1247
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine the minimum number of hits required to break three bricks. We are given Ada's strength `S` and the widths of the three bricks `W1, W2, W3` (stacked from top to bottom). Ada can only break a *contiguous* block of bricks whose total width is less than or equal to her strength `S`.

## Intuition & Mathematical Observation
The core idea is to find the *minimum* number of hits. This suggests a greedy approach: try to break as many bricks as possible in each hit. The number of hits can only be 1, 2, or 3. It cannot be more than 3 because Ada can always break one brick at a time (since `W_i` are small positive integers and `S >= 1`, any single brick `W_i` will have `W_i <= S`).

We check the possibilities in increasing order of hits:

### Case 1: 1 Hit
The most optimal scenario is to break all three bricks in a single hit.
This is possible if the sum of the widths of all three bricks is less than or equal to Ada's strength `S`.
- **Condition**: `W1 + W2 + W3 <= S`
If this condition is met, the answer is `1`.

### Case 2: 2 Hits
If 1 hit is not possible, we check if it can be done in 2 hits. Ada must break a contiguous block in the first hit, leaving another contiguous block that can be broken in the second hit.
Considering the initial stack `W1, W2, W3`:

1.  **Break `W1, W2` first, then `W3`:**
    *   In the first hit, Ada breaks the top two bricks `W1` and `W2`. This is possible if `W1 + W2 <= S`.
    *   After the first hit, only `W3` remains. Ada then breaks `W3` in the second hit. This is possible if `W3 <= S`.
    *   **Combined condition**: `(W1 + W2 <= S)` AND `(W3 <= S)`

2.  **Break `W2, W3` first, then `W1`:**
    *   In the first hit, Ada breaks the bottom two bricks `W2` and `W3`. This is possible if `W2 + W3 <= S`.
    *   After the first hit, only `W1` remains. Ada then breaks `W1` in the second hit. This is possible if `W1 <= S`.
    *   **Combined condition**: `(W2 + W3 <= S)` AND `(W1 <= S)`

If either of these combined conditions is true, then the answer is `2`. The solution code's `if` statement `(W1 + W2 <= S && W3 <= S) || (W1 <= S && W2 + W3 <= S)` correctly covers these two possibilities.

### Case 3: 3 Hits
If neither 1 hit nor 2 hits are possible, then it must take 3 hits. This is always achievable by breaking one brick at a time:
- Hit 1: Break `W1` (possible since `W1 <= S` for a single brick).
- Hit 2: Break `W2` (possible since `W2 <= S` for a single brick).
- Hit 3: Break `W3` (possible since `W3 <= S` for a single brick).
Therefore, if the conditions for 1 or 2 hits are not met, the answer is `3`.

The solution logic proceeds by checking these cases sequentially: first 1 hit, then 2 hits, and finally defaults to 3 hits.

## Complexity Analysis
-   **Time Complexity**: $O(1)$
    The solution involves a fixed number of arithmetic operations (additions) and comparisons. These operations take constant time, regardless of the input values (within typical integer limits). The `solve()` function performs a constant amount of work. Since the `solve()` function is called `T` times for `T` test cases, the total time complexity is $O(T)$.
-   **Space Complexity**: $O(1)$
    The solution uses a fixed number of integer variables (`S, W1, W2, W3, T`) to store input and loop counters. The memory usage does not scale with the input values, making it constant space.

## Solution Code
```cpp
#include <bits/stdc++.h> 

// Using namespace std; as requested by problem statement
using namespace std;

void solve() {
    int S, W1, W2, W3;
    cin >> S >> W1 >> W2 >> W3;

    // Case 1: All three bricks break in 1 hit
    // Sum of all widths must be less than or equal to strength S.
    if (W1 + W2 + W3 <= S) {
        cout << 1 << "\n";
        return;
    }

    // Case 2: All three bricks break in 2 hits
    // If not 1 hit, we check if 2 hits are possible.
    // Ada can choose to hit a contiguous block from either end.
    // The goal is to break a contiguous block of bricks in the first hit,
    // leaving another contiguous block that can be broken in the second hit.

    // There are two fundamental patterns for 2 hits:
    // Pattern 1: Break two bricks from one end, then the remaining one.
    //   - This covers breaking (W1,W2) then (W3) from the original stack.
    //     Conditions: (W1 + W2 <= S) AND (W3 <= S)

    // Pattern 2: Break one brick from one end, then the remaining two.
    //   - This covers breaking (W1) then (W2,W3) from the original stack,
    //     OR breaking (W3) then (W1,W2) from the other end.
    //     Conditions: (W1 <= S) AND (W2 + W3 <= S)

    // If either of these patterns is possible, then 2 hits are sufficient.
    if ((W1 + W2 <= S && W3 <= S) || 
        (W1 <= S && W2 + W3 <= S)) { 
        cout << 2 << "\n";
        return;
    }

    // Case 3: If not 1 hit and not 2 hits, it must be 3 hits.
    // This is always possible by breaking one brick at a time, as the problem guarantees
    // that Ada can break all bricks. Given W_i <= 2 and S >= 1, this implies that
    // any single brick can be broken if it's the only one left.
    cout << 3 << "\n";
}

int main() {
    // Fast I/O as requested
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