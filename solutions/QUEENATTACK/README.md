# [The Attack of Queen (QUEENATTACK)](https://www.codechef.com/problems/QUEENATTACK)
- **Difficulty Rating**: 1076
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the total number of cells a Queen can attack on an `N x N` chessboard, given its position `(X, Y)`. The board is 1-indexed, meaning rows and columns range from 1 to `N`. A Queen attacks horizontally, vertically, and diagonally in all eight directions, as far as the edge of the board.

## Intuition & Mathematical Observation

The key insight is that a Queen's attack range in each of the eight directions (left, right, up, down, top-left, top-right, bottom-left, bottom-right) is independent of the others. We simply need to count how many cells are reachable in each direction until we hit the board's edge, and then sum these counts. The Queen's own cell `(X, Y)` is not considered attacked.

Let the board size be `N x N` and the Queen's position be `(X, Y)`.

1.  **Horizontal Attacks (Row `X`):**
    *   **Left**: The Queen can attack cells `(X, 1)` through `(X, Y-1)`. The number of such cells is `Y - 1`.
    *   **Right**: The Queen can attack cells `(X, Y+1)` through `(X, N)`. The number of such cells is `N - Y`.

2.  **Vertical Attacks (Column `Y`):**
    *   **Up**: The Queen can attack cells `(1, Y)` through `(X-1, Y)`. The number of such cells is `X - 1`.
    *   **Down**: The Queen can attack cells `(X+1, Y)` through `(N, Y)`. The number of such cells is `N - X`.

3.  **Diagonal Attacks:** For diagonal moves, both the row and column change by the same absolute amount. Let `k` be the distance from the Queen.

    *   **Top-Left Diagonal (decreasing row, decreasing column):**
        Cells are of the form `(X-k, Y-k)`.
        The maximum `k` is limited by reaching row 1 (`X-k >= 1 \implies k \le X-1`) and column 1 (`Y-k >= 1 \implies k \le Y-1`).
        So, the number of cells is `min(X - 1, Y - 1)`.

    *   **Top-Right Diagonal (decreasing row, increasing column):**
        Cells are of the form `(X-k, Y+k)`.
        The maximum `k` is limited by reaching row 1 (`X-k >= 1 \implies k \le X-1`) and column `N` (`Y+k \le N \implies k \le N-Y`).
        So, the number of cells is `min(X - 1, N - Y)`.

    *   **Bottom-Left Diagonal (increasing row, decreasing column):**
        Cells are of the form `(X+k, Y-k)`.
        The maximum `k` is limited by reaching row `N` (`X+k \le N \implies k \le N-X`) and column 1 (`Y-k >= 1 \implies k \le Y-1`).
        So, the number of cells is `min(N - X, Y - 1)`.

    *   **Bottom-Right Diagonal (increasing row, increasing column):**
        Cells are of the form `(X+k, Y+k)`.
        The maximum `k` is limited by reaching row `N` (`X+k \le N \implies k \le N-X`) and column `N` (`Y+k \le N \implies k \le N-Y`).
        So, the number of cells is `min(N - X, N - Y)`.

The total number of attacked cells is the sum of cells from all these eight directions. The provided solution directly implements these calculations. Using `long long` for `N, X, Y` and `attacked_cells` is a good practice as `N` can be up to `10^6`, and the sum of attacked cells can exceed the range of a 32-bit integer.

## Complexity Analysis

*   **Time Complexity**: For each test case, the solution performs a fixed number of arithmetic operations (subtractions, additions, and `min` function calls). These operations take constant time. Therefore, the time complexity per test case is $O(1)$. If there are `T` test cases, the total time complexity is $O(T)$.

*   **Space Complexity**: The solution uses a few variables (`N`, `X`, `Y`, `attacked_cells`, `T`) to store input and intermediate results. The amount of memory used does not depend on the input size `N`. Thus, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, algorithm, etc.

// Using namespace std; is requested
using namespace std;

int main() {
    // Fast I/O as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        long long N, X, Y; // N, X, Y can be up to 10^6. Using long long for safety.
        cin >> N >> X >> Y; // Read board size N, Queen's position (X, Y)

        long long attacked_cells = 0;

        // Calculate horizontal attacks
        // Cells to the left of the Queen (row X, columns 1 to Y-1)
        attacked_cells += (Y - 1);
        // Cells to the right of the Queen (row X, columns Y+1 to N)
        attacked_cells += (N - Y);

        // Calculate vertical attacks
        // Cells above the Queen (rows 1 to X-1, column Y)
        attacked_cells += (X - 1);
        // Cells below the Queen (rows X+1 to N, column Y)
        attacked_cells += (N - X);

        // Calculate diagonal attacks

        // Top-left diagonal: cells (X-k, Y-k)
        // Limited by distance to row 1 (X-1) and column 1 (Y-1)
        attacked_cells += min(X - 1, Y - 1);

        // Top-right diagonal: cells (X-k, Y+k)
        // Limited by distance to row 1 (X-1) and column N (N-Y)
        attacked_cells += min(X - 1, N - Y);

        // Bottom-left diagonal: cells (X+k, Y-k)
        // Limited by distance to row N (N-X) and column 1 (Y-1)
        attacked_cells += min(N - X, Y - 1);

        // Bottom-right diagonal: cells (X+k, Y+k)
        // Limited by distance to row N (N-X) and column N (N-Y)
        attacked_cells += min(N - X, N - Y);

        // Output the total number of attacked cells for the current test case
        cout << attacked_cells << "\n";
    }
    return 0;
}
```