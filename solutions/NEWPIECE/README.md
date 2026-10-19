# [New Piece (NEWPIECE)](https://www.codechef.com/problems/NEWPIECE)
- **Difficulty Rating**: 1216
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks for the minimum number of moves required for a "new piece" to travel from a starting cell `(A, B)` to a destination cell `(P, Q)` on an 8x8 chessboard. The coordinates `A, B, P, Q` are 1-indexed (from 1 to 8).

The movement rule for the new piece is: it can move from its current cell `(X, Y)` to *any* other cell `(X', Y')` on the board, provided that `(X, Y)` and `(X', Y')` have *different* colors. A standard chessboard coloring applies: cells `(i, j)` where `i+j` is even are one color (e.g., white), and cells where `i+j` is odd are the other color (e.g., black).

## Intuition & Mathematical Observation

The key to this problem lies entirely in understanding the piece's movement rule in terms of cell colors.

1.  **Cell Color Property**: On a chessboard, the color of a cell `(i, j)` is determined by the parity of `i+j`. If `i+j` is even, it's one color; if `i+j` is odd, it's the other. We can represent this numerically: `(i + j) % 2`. Let's say `0` represents white and `1` represents black.

2.  **Movement Rule Rephrased**: The piece can move from `(X, Y)` to `(X', Y')` if and only if `(X + Y) % 2 != (X' + Y') % 2`. In simpler terms, it must move to a cell of a *different* color.

Now, let's analyze the minimum number of moves required:

*   **Case 0: Zero Moves**
    *   If the starting cell `(A, B)` is already the same as the destination cell `(P, Q)`, no moves are needed.
    *   Condition: `A == P` and `B == Q`.
    *   Result: `0` moves.

*   **Case 1: One Move**
    *   Can the piece reach `(P, Q)` from `(A, B)` in a single move?
    *   According to the rule, yes, if `(A, B)` and `(P, Q)` have different colors.
    *   Condition: `(A + B) % 2 != (P + Q) % 2`.
    *   If this condition is met, and `(A, B)` is not `(P, Q)` (which is covered by the 0-move case), then 1 move is sufficient.
    *   Result: `1` move.

*   **Case 2: Two Moves**
    *   What if `(A, B)` and `(P, Q)` have the *same* color?
    *   Condition: `(A + B) % 2 == (P + Q) % 2`.
    *   In this situation, the piece *cannot* move directly from `(A, B)` to `(P, Q)` in one step because they share the same color. Therefore, at least two moves are required.
    *   Can it *always* be done in two moves?
        *   From `(A, B)` (let's say it has color C1), the piece must first move to an intermediate cell `(X, Y)` that has a *different* color (C2).
        *   Since an 8x8 chessboard always contains cells of both colors (e.g., `(1,1)` is white, `(1,2)` is black), such an intermediate cell `(X, Y)` *always exists*. The piece can pick any cell of the opposite color.
        *   Once at `(X, Y)` (color C2), can it then move to `(P, Q)` (which has color C1)? Yes, because C1 is different from C2.
        *   Therefore, if `(A, B)` and `(P, Q)` have the same color (and are not the same cell), two moves are always sufficient and necessary.
    *   Result: `2` moves.

These three cases cover all possibilities. The maximum number of moves required is 2.

## Complexity Analysis

*   **Time Complexity**: $O(1)$ per test case.
    For each test case, the solution performs a fixed number of arithmetic operations (addition, modulo) and comparisons. These operations take constant time. If there are $T$ test cases, the total time complexity will be $O(T)$.
*   **Space Complexity**: $O(1)$.
    The solution uses a constant number of integer variables to store coordinates and color parities, regardless of the input values. No data structures that grow with input size are used.

## Solution Code

```cpp
#include <bits/stdc++.h> // Required header as per critical instructions

// Function to solve a single test case
void solve() {
    int A, B, P, Q;
    std::cin >> A >> B >> P >> Q;

    // Case 1: If the starting cell is the same as the destination cell,
    // 0 moves are required.
    if (A == P && B == Q) {
        std::cout << 0 << "\n";
        return;
    }

    // Determine the color of the starting cell (A, B)
    // A cell (i, j) is white if i+j is even, black if i+j is odd.
    // We can use (sum % 2) to represent the color.
    // For example, 0 for white, 1 for black.
    int color_AB = (A + B) % 2;

    // Determine the color of the destination cell (P, Q)
    int color_PQ = (P + Q) % 2;

    // Case 2: If the starting cell and destination cell have different colors,
    // the new piece can move directly from (A, B) to (P, Q) in 1 step,
    // because the rule states it can move to any cell of a different color.
    if (color_AB != color_PQ) {
        std::cout << 1 << "\n";
    } 
    // Case 3: If the starting cell and destination cell have the same color,
    // and they are not the same cell (handled by the first if-condition),
    // the piece cannot move directly in 1 step.
    // It must make an intermediate move.
    // From (A, B) (color C1), it moves to any cell (X, Y) of a different color (C2).
    // From (X, Y) (color C2), it can then move to (P, Q) (color C1),
    // because C1 is different from C2.
    // Since an 8x8 board always has cells of both colors, such an intermediate
    // cell (X, Y) always exists. For example, if (A,B) is white, it can move
    // to (1,2) (black). From (1,2), it can move to (P,Q) (white).
    // Thus, 2 moves are always sufficient and necessary in this case.
    else { // color_AB == color_PQ
        std::cout << 2 << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Number of test cases
    std::cin >> T;
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0;
}
```