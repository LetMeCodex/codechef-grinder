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