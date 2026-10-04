# [Change Row and Column Both (CHANGEPOS)](https://www.codechef.com/problems/CHANGEPOS)
- **Difficulty Rating**: 660
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum number of moves Chef needs to get from a starting cell `(sx, sy)` to an ending cell `(ex, ey)` on a grid. A move is defined as changing both the row and the column simultaneously. That is, if Chef is at `(r1, c1)` and moves to `(r2, c2)`, it must be true that `r1 != r2` AND `c1 != c2`. The grid dimensions are not explicitly given but are usually large enough (e.g., 10x10 for typical CodeChef problems if not specified, or effectively infinite for coordinate-based problems). We are guaranteed that `(sx, sy)` is not equal to `(ex, ey)`.

## Intuition & Mathematical Observation

Let's analyze the conditions for making a move: `current_row != next_row` AND `current_col != next_col`.

1.  **Case 1: One Move is Possible**
    If Chef can reach the destination `(ex, ey)` from `(sx, sy)` in a single move, it must satisfy the move condition directly. This means:
    `sx != ex` AND `sy != ey`
    If both these conditions are true, Chef can simply make one move directly to the destination.

2.  **Case 2: One Move is Not Possible**
    If the conditions for one move are not met, it means either `sx == ex` OR `sy == ey` (or both). In this scenario, Chef cannot move directly to `(ex, ey)` because at least one coordinate would remain the same, violating the move rule.
    For example, if `sx == ex`, Chef needs to change rows to make a valid move, but the destination is in the same row. A direct move is impossible.

    In such cases, Chef must make at least two moves. The question then becomes: can Chef *always* reach the destination in exactly two moves if one move is not possible?

    Let's consider an intermediate cell `(cx, cy)`. Chef would move from `(sx, sy)` to `(cx, cy)`, and then from `(cx, cy)` to `(ex, ey)`.
    For the first move to be valid: `sx != cx` AND `sy != cy`.
    For the second move to be valid: `cx != ex` AND `cy != ey`.

    We need to find a `cx` and `cy` that satisfy these four conditions.
    *   For `cx`: it must be different from `sx` and `ex`.
    *   For `cy`: it must be different from `sy` and `ey`.

    Since the problem implies a standard grid (e.g., 1-10 rows/columns, or even larger), there are always enough distinct rows/columns to pick from.
    *   **Finding `cx`**:
        *   If `sx == ex`: We need `cx != sx`. Since there are at least 10 rows, we can always pick a `cx` that is different from `sx`. For example, if `sx=1`, we can pick `cx=2`.
        *   If `sx != ex`: We need `cx != sx` AND `cx != ex`. Since there are at least 10 rows, we can always pick a `cx` that is different from both `sx` and `ex`. For example, if `sx=1, ex=2`, we can pick `cx=3`.
    *   **Finding `cy`**: The same logic applies to `cy`. We can always find a `cy` that is different from `sy` and `ey`.

    Since we can always find such an intermediate cell `(cx, cy)`, it means that if one move is not possible, two moves are always sufficient.

**Conclusion:**
The minimum number of moves is:
*   `1` if `sx != ex` AND `sy != ey`.
*   `2` otherwise (i.e., if `sx == ex` OR `sy == ey`).

## Complexity Analysis

*   **Time Complexity**: For each test case, the solution reads four integers and performs a constant number of comparisons and a print operation. This takes $O(1)$ time per test case. If there are $T$ test cases, the total time complexity is $O(T)$.

*   **Space Complexity**: The solution uses a few integer variables to store the coordinates and the number of test cases. This amount of memory is constant and does not depend on the input values. Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, etc.

// Using namespace std; is requested by the problem statement.
using namespace std; 

int main() {
    // Fast I/O as requested.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey; // Read coordinates of starting and ending cells

        // If both the row and column coordinates of the start and end cells are different,
        // Chef can move directly from (sx, sy) to (ex, ey) in one move.
        // This is because the move condition is (current_row != next_row AND current_col != next_col).
        if (sx != ex && sy != ey) {
            cout << 1 << "\n";
        } 
        // If either sx == ex or sy == ey (or both, but the problem guarantees (sx,sy) != (ex,ey)),
        // Chef cannot reach the destination in one move.
        // For example, if sx == ex, Chef needs to change row to make a valid move,
        // but the destination is in the same row. So, a direct move is impossible.
        // In such cases, Chef must make an intermediate move to a cell (cx, cy).
        // We can always find an intermediate cell (cx, cy) such that:
        // 1. The first move from (sx, sy) to (cx, cy) is valid (sx != cx AND sy != cy).
        // 2. The second move from (cx, cy) to (ex, ey) is valid (cx != ex AND cy != ey).
        // Since the grid is 10x10 (rows 1-10, columns 1-10), there are always enough distinct
        // rows/columns to pick for cx and cy that satisfy these conditions.
        // For example, to pick cx: it must be different from sx and ex.
        // If sx == ex, we just need cx != sx. There are 9 other rows available.
        // If sx != ex, we need cx != sx and cx != ex. There are 8 other rows available.
        // In both scenarios, we can always pick a valid cx. The same logic applies for cy.
        // Thus, 2 moves are always sufficient if 1 move is not possible.
        else {
            cout << 2 << "\n";
        }
    }
    return 0;
}
```