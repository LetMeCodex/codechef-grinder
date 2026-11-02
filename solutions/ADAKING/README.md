# [Ada King (ADAKING)](https://www.codechef.com/problems/ADAKING)
- **Difficulty Rating**: 1378
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to generate an 8x8 chessboard configuration. Given an integer `K` (where `1 <= K <= 64`), we need to mark exactly `K` cells on the board as "reachable by the king". The king's initial position must be marked 'O', other reachable cells must be marked '.', and all remaining cells must be marked 'X' (obstacles). We need to print the resulting 8x8 board.

## Intuition & Mathematical Observation

The key insight here is that the problem statement is quite flexible. It doesn't ask for the *minimum* number of moves to reach a cell, nor does it require all `K` cells to be reachable *from the initial 'O' position in a single move*. It simply states "mark exactly K cells that are reachable by the king". This implies that if a cell is marked '.', the king can occupy that cell. If the king can occupy cell A, and cell B is adjacent to A, then the king can also occupy cell B.

Given this flexibility, the simplest strategy is to:
1.  Place the king ('O') at an arbitrary starting position. The top-left corner `(0,0)` is a convenient choice. This accounts for 1 reachable cell.
2.  We need `K-1` additional reachable cells.
3.  To ensure connectivity (so the king can indeed "reach" these cells), we can simply mark the next `K-1` cells in a systematic order (e.g., row by row, column by column) as '.' until we have a total of `K` marked cells.
4.  All remaining cells on the board are marked 'X' as obstacles.

For example, if `K=5`:
- `board[0][0] = 'O'` (1st cell)
- `board[0][1] = '.'` (2nd cell)
- `board[0][2] = '.'` (3rd cell)
- `board[0][3] = '.'` (4th cell)
- `board[0][4] = '.'` (5th cell)
All other cells would be 'X'. The king can move from `(0,0)` to `(0,1)`, then to `(0,2)`, and so on, making all marked cells reachable. This strategy works for any `K` from 1 to 64.

The provided solution implements this exact strategy: it initializes an 8x8 board with 'X's, places 'O' at `(0,0)`, and then fills the board with '.'s in row-major order until `K` cells are accounted for.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The board size is fixed at 8x8.
    -   Initializing the board: $O(8 \times 8) = O(64)$.
    -   Placing 'O' and filling `K-1` cells with '.': This involves iterating through the board. In the worst case (`K=64`), it iterates through all 64 cells. This is $O(8 \times 8) = O(64)$.
    -   Printing the board: $O(8 \times 8) = O(64)$.
    Since all these operations are on a fixed-size board, the time complexity for a single test case is constant, $O(1)$.
    For `T` test cases, the total time complexity is $O(T)$.

-   **Space Complexity**: $O(1)$
    The board is stored as an 8x8 grid of characters. This requires $8 \times 8 = 64$ characters of memory. Since the memory usage is constant regardless of the input `K` (as `K` doesn't change the board dimensions), the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, vector, string, etc.

// Using namespace std; is common in competitive programming for brevity.
using namespace std;

void solve() {
    int K;
    cin >> K;

    // Create an 8x8 chessboard.
    // Initialize all cells to 'X' (obstacles).
    vector<string> board(8, string(8, 'X'));

    // Place the king at the top-left corner (0,0).
    board[0][0] = 'O';

    // We need K total reachable cells. Since one is 'O',
    // we need to mark K-1 additional cells as empty ('.').
    int cells_to_fill = K - 1;

    // Iterate through the board in row-major order.
    // Mark cells as '.' until K cells are accounted for.
    for (int r = 0; r < 8; ++r) {
        for (int c = 0; c < 8; ++c) {
            // If we have already marked K cells (1 'O' + K-1 '.'), stop.
            if (cells_to_fill == 0) {
                break;
            }

            // Skip the king's initial position, as it's already 'O'.
            if (r == 0 && c == 0) {
                continue;
            }

            // Mark the current cell as empty (reachable).
            board[r][c] = '.';
            cells_to_fill--;
        }
        // If we have already marked K cells, break from the outer loop too.
        if (cells_to_fill == 0) {
            break;
        }
    }

    // Print the resulting chessboard.
    for (int r = 0; r < 8; ++r) {
        cout << board[r] << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases.
    while (T--) {
        solve(); // Solve each test case.
    }

    return 0;
}
```