# [Ada School (ADASCOOL)](https://www.codechef.com/problems/ADASCOOL)
- **Difficulty Rating**: 1004
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks whether it's possible to perfectly tile an `N x M` grid using `1 x 2` dominoes. A `1 x 2` domino covers exactly two adjacent cells, either horizontally or vertically. We need to output "YES" if it's possible and "NO" otherwise.

## Intuition & Mathematical Observation

1.  **Total Cells**: An `N x M` grid has a total of `N * M` cells.
2.  **Domino Coverage**: Each `1 x 2` domino covers exactly 2 cells.
3.  **Necessary Condition**: For the grid to be perfectly tiled, the total number of cells (`N * M`) must be an even number. This is because each domino covers 2 cells, so we would need `(N * M) / 2` dominoes. If `N * M` is odd, it's impossible to cover all cells perfectly, as there will always be one cell left over.
4.  **When is `N * M` even?**:
    *   The product `N * M` is even if at least one of `N` or `M` is even.
        *   If `N` is even, then `N * M` is even (e.g., `2 * 3 = 6`, `4 * 5 = 20`).
        *   If `M` is even, then `N * M` is even (e.g., `3 * 2 = 6`, `5 * 4 = 20`).
    *   The product `N * M` is odd only if both `N` and `M` are odd (e.g., `3 * 5 = 15`).
5.  **Sufficient Condition**: It's a well-known result in tiling theory that an `N x M` grid can be perfectly tiled by `1 x 2` dominoes if and only if the total number of cells `N * M` is even.
    *   If `N` is even, we can tile the grid by placing `M` vertical dominoes in each pair of rows (e.g., rows 1-2, 3-4, etc.). Each `2 x M` subgrid can be tiled by `M` horizontal dominoes in the first row and `M` horizontal dominoes in the second row, or by `M` vertical dominoes.
    *   Similarly, if `M` is even, we can tile the grid by placing `N` horizontal dominoes in each pair of columns.
    *   Since the problem doesn't impose any other constraints, this condition is both necessary and sufficient.

**Conclusion**: The grid can be tiled if and only if `N * M` is even. This is equivalent to checking if `N` is even OR `M` is even. If both `N` and `M` are odd, then `N * M` is odd, and tiling is impossible.

## Complexity Analysis

-   **Time Complexity**: For each test case, we read two integers (`N` and `M`) and perform a constant number of arithmetic operations (modulo and logical OR). This takes $O(1)$ time per test case. If there are `T` test cases, the total time complexity is $O(T)$.
-   **Space Complexity**: We only use a few integer variables to store `N`, `M`, and `T`. This requires a constant amount of memory, so the space complexity is $O(1)$.

## Solution Code

```cpp
#include <iostream>

void solve() {
    int N, M;
    std::cin >> N >> M;
    
    // If N*M is odd, it's impossible. This happens if both N and M are odd.
    // If N*M is even, it's always possible. This happens if N is even or M is even (or both).
    if (N % 2 == 0 || M % 2 == 0) {
        std::cout << "YES\n";
    } else {
        // Both N and M are odd
        std::cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // Unties cin from cout and disables synchronization with C stdio.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve();
    }
    
    return 0;
}

```