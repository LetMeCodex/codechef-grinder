# [Mark Points (MARKP)](https://www.codechef.com/problems/MARKP)
- **Difficulty Rating**: 1064
- **Solved in**: 3 attempt(s)

## Problem Summary

The problem asks us to determine if a given binary string `S` of length `N` can be formed by applying a specific marking operation. The points are 1-indexed from `1` to `N`.

The operation is:
1. Choose an integer `X` such that `1 < X < N`.
2. This operation marks points `X-1`, `X`, and `X+1`.
3. **Crucially**: This operation can only be performed if all three points (`X-1`, `X`, `X+1`) are intended to be marked according to the target string `S`. That is, `S_{X-1} = '1'`, `S_X = '1'`, and `S_{X+1} = '1'`.

We need to output "Yes" if `S` can be formed, and "No" otherwise.

## Intuition & Mathematical Observation

The core of this problem lies in the constraint: an operation centered at `X` (marking `X-1, X, X+1`) can *only* be performed if `S_{X-1}, S_X, S_{X+1}` are all '1'. This implies a few things:

1.  **Points that are '0' in `S` must remain '0'**: If `S_i = '0'`, then point `i` must not be marked by any operation. Our strategy must ensure this.
2.  **Points that are '1' in `S` must be marked**: If `S_i = '1'`, then point `i` must be marked by at least one operation.

Consider any possible operation centered at `X` (where `1 < X < N`). If `S_{X-1} = '1'`, `S_X = '1'`, and `S_{X+1} = '1'`, then this operation is *consistent* with the target string `S`. Since operations only mark points (they don't unmark them), and we want to achieve `S`, it makes sense to perform *all* such consistent operations. Performing a consistent operation will only mark points that are supposed to be '1' in `S`, and it helps fulfill the requirement that `S_i = '1'` points get marked.

Therefore, the strategy is:
1.  Initialize a new binary string, let's call it `actual_marked_S_str`, of length `N` with all '0's. This string will represent the points that are *actually* marked by all consistent operations.
2.  Iterate through all possible centers `X` (1-indexed) from `2` to `N-1`. In 0-indexed terms, this means iterating `x_center_0_indexed` from `1` to `N-2`.
3.  For each `x_center_0_indexed`:
    *   Check if `S[x_center_0_indexed - 1] == '1'`, `S[x_center_0_indexed] == '1'`, AND `S[x_center_0_indexed + 1] == '1'`.
    *   If this condition is true, it means this operation is consistent with `S`. We perform this operation by setting `actual_marked_S_str[x_center_0_indexed - 1] = '1'`, `actual_marked_S_str[x_center_0_indexed] = '1'`, and `actual_marked_S_str[x_center_0_indexed + 1] = '1'`.
4.  After iterating through all possible centers and performing all consistent operations, `actual_marked_S_str` will contain the maximal set of points that *can* be marked while adhering to the problem's rules.
5.  Finally, compare `actual_marked_S_str` with the target string `S`.
    *   If `actual_marked_S_str` is identical to `S`, it means all points `i` where `S_i = '1'` were successfully marked, and no points `i` where `S_i = '0'` were marked. In this case, output "Yes".
    *   Otherwise, output "No".

This approach is correct because:
*   If `S_i = '0'`, `actual_marked_S_str[i]` will never become '1'. This is guaranteed because an operation is only performed if all three points involved are '1' in `S`. So, if `S_i = '0'`, no operation that marks `i` would ever be considered consistent and thus performed.
*   If `S_i = '1'`, we need to ensure `actual_marked_S_str[i]` becomes '1'. By performing *all* consistent operations, we maximize the chances of marking `S_i = '1'` points. If, after this process, `actual_marked_S_str[i]` is still '0' while `S_i = '1'`, it means point `i` could not be marked by any valid operation, making `S` impossible to achieve.

## Complexity Analysis

-   **Time Complexity**:
    *   Reading `N` and `S`: $O(N)$.
    *   Initializing `actual_marked_S_str`: $O(N)$.
    *   The loop iterates `N-2` times (from `x_center_0_indexed = 1` to `N-2`). Inside the loop, we perform a constant number of character comparisons and assignments ($O(1)$). So, this loop takes $O(N)$ time.
    *   Comparing `actual_marked_S_str` with `S`: $O(N)$.
    *   For each test case, the total time complexity is $O(N)$.
    *   Given that the sum of `N` over all test cases is bounded (typically $\sum N \le 2 \cdot 10^5$), the overall time complexity across all test cases is $O(\sum N)$. This is efficient enough for the given constraints.

-   **Space Complexity**:
    *   Storing the input string `S`: $O(N)$.
    *   Storing the `actual_marked_S_str`: $O(N)$.
    *   The total space complexity for one test case is $O(N)$.
    *   The maximum space used at any point (if memory is reused for each test case) is $O(\max N)$.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <numeric> // Not strictly necessary for this solution

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    // actual_marked_S_str will store the state of points after applying all consistent operations.
    // Initialize all points as unmarked ('0').
    std::string actual_marked_S_str(n, '0');

    // Iterate through all possible centers for an operation (0-indexed).
    // A 1-indexed X such that 1 < X < N means 0-indexed x_idx such that 0 < x_idx < N-1.
    // So, x_idx can range from 1 to N-2.
    for (int x_center_0_indexed = 1; x_center_0_indexed <= n - 2; ++x_center_0_indexed) {
        // An operation centered at x_center_0_indexed marks points:
        // (x_center_0_indexed - 1), x_center_0_indexed, (x_center_0_indexed + 1).
        // For this operation to be consistent with the target string S,
        // all three points must be '1' in S.
        if (s[x_center_0_indexed - 1] == '1' && 
            s[x_center_0_indexed] == '1' && 
            s[x_center_0_indexed + 1] == '1') {
            
            // If all three points are '1' in S, we can perform this operation.
            // Mark these points in our actual_marked_S_str.
            actual_marked_S_str[x_center_0_indexed - 1] = '1';
            actual_marked_S_str[x_center_0_indexed] = '1';
            actual_marked_S_str[x_center_0_indexed + 1] = '1';
        }
    }

    // After applying all consistent operations, compare actual_marked_S_str with the target string S.
    // The problem states S_i = 1 if and only if you marked point i.
    // Our logic ensures actual_marked_S_str[i] is never '1' if s[i] is '0'.
    // So, we only need to check if actual_marked_S_str is exactly equal to s.
    if (actual_marked_S_str == s) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```