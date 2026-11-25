# [Journey of the Knight (KNIGHT2)](https://www.codechef.com/problems/KNIGHT2)
- **Difficulty Rating**: 1144
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a knight can reach a target square $(X_2, Y_2)$ from a starting square $(X_1, Y_1)$ in *exactly* 100 moves. The board is an 8x8 chessboard, and the coordinates are 1-indexed ($1 \le X, Y \le 8$). A knight moves in an 'L' shape: two squares in one cardinal direction (horizontal or vertical) and then one square perpendicular to that direction.

## Intuition & Mathematical Observation

The core of this problem lies in understanding the properties of a knight's move on a chessboard.

1.  **Chessboard Coloring and Parity:**
    A standard chessboard has alternating colors (black and white). We can assign a "color" to any square $(x, y)$ based on the parity of the sum of its coordinates $(x+y)$.
    *   If $(x+y)$ is even, let's say it's a "white" square.
    *   If $(x+y)$ is odd, let's say it's a "black" square.

2.  **Knight's Move and Color Change:**
    Consider a knight moving from $(x, y)$ to $(x', y')$. A knight's move always involves changing one coordinate by $\pm 1$ and the other by $\pm 2$.
    *   Case 1: $x' = x \pm 1$, $y' = y \pm 2$.
        The change in the sum is $(x' + y') - (x + y) = (\pm 1) + (\pm 2)$, which can be $\pm 3$ or $\pm 1$. All these values are odd.
    *   Case 2: $x' = x \pm 2$, $y' = y \pm 1$.
        The change in the sum is $(x' + y') - (x + y) = (\pm 2) + (\pm 1)$, which can be $\pm 3$ or $\pm 1$. All these values are odd.
    Since the change in $(x+y)$ is always an odd number, a knight's move *always flips the parity* of $(x+y)$. This means a knight always moves from a "white" square to a "black" square, or vice-versa.

3.  **Even Number of Moves:**
    If a knight makes an even number of moves:
    *   After 1 move: Color changes.
    *   After 2 moves: Color changes back to the original color.
    *   After 3 moves: Color changes again.
    *   ...
    In general, after an even number of moves, the knight must end up on a square of the *same color* as its starting square. Conversely, after an odd number of moves, it must end up on a square of a *different color*.

4.  **Applying to the Problem (100 Moves):**
    The problem requires exactly 100 moves. Since 100 is an even number, the knight must end up on a square of the same color as its starting square.
    Therefore, a necessary condition for the knight to reach $(X_2, Y_2)$ from $(X_1, Y_1)$ in 100 moves is that $(X_1 + Y_1)$ and $(X_2 + Y_2)$ must have the same parity.
    Mathematically: $(X_1 + Y_1) \pmod 2 = (X_2 + Y_2) \pmod 2$.

5.  **Sufficiency of the Condition:**
    Is this condition also sufficient?
    *   The problem states the board is 8x8. It's a known fact that on an 8x8 board, any two squares of the same color are reachable by a knight. Furthermore, the maximum number of moves required to reach any square from any other square on an 8x8 board is 6.
    *   If $(X_1 + Y_1)$ and $(X_2 + Y_2)$ have the same parity, it means the minimum number of moves, let's call it $M$, required to reach $(X_2, Y_2)$ from $(X_1, Y_1)$ must be an even number (since each move flips the color).
    *   We need to make *exactly* 100 moves. Since $M$ is even and $M \le 6$, we can reach the target square in $M$ moves.
    *   We then have $(100 - M)$ moves remaining. Since $M$ is even, $(100 - M)$ is also an even number.
    *   We can "waste" these remaining moves by repeatedly moving the knight back and forth between the target square $(X_2, Y_2)$ and one of its adjacent squares (in terms of knight moves). For example, if $(X_2, Y_2)$ can move to $(X_A, Y_A)$, we can move $(X_2, Y_2) \to (X_A, Y_A) \to (X_2, Y_2)$. This sequence uses 2 moves and returns the knight to $(X_2, Y_2)$.
    *   Since every square on an 8x8 board has at least two valid knight moves (even corner squares like (1,1) have moves to (2,3) and (3,2)), this back-and-forth strategy is always possible.
    *   We can perform $(100 - M) / 2$ such pairs of moves. This ensures the knight ends up at $(X_2, Y_2)$ after exactly 100 moves.

Therefore, the condition $(X_1 + Y_1) \pmod 2 = (X_2 + Y_2) \pmod 2$ is both necessary and sufficient.

## Complexity Analysis

-   **Time Complexity**: For each test case, the solution performs a few constant-time arithmetic operations (addition, modulo, comparison). This is $O(1)$ per test case. If there are $T$ test cases, the total time complexity is $O(T)$.
-   **Space Complexity**: The solution only uses a few integer variables to store the input coordinates and the number of test cases. This is $O(1)$ constant space.

## Solution Code

```cpp
#include <iostream> // Required for standard input/output operations (cin, cout)

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin/cout from C's stdio and prevents flushing cout before cin.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    std::cin >> T; // Read the value of T from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int X1, Y1, X2, Y2; // Declare integer variables for the coordinates.
        // Read the starting coordinates (X1, Y1) and ending coordinates (X2, Y2).
        std::cin >> X1 >> Y1 >> X2 >> Y2;

        // A knight's move always changes the color of the square it is on.
        // The color of a square (x, y) can be determined by the parity of (x + y).
        // If (x + y) is even, it's one color. If (x + y) is odd, it's the other color.

        // After an even number of moves (like 100), the knight must end up on a square
        // of the same color as its starting square.
        // This means the parity of (X1 + Y1) must be the same as the parity of (X2 + Y2).

        // Check if the parities match.
        // (X1 + Y1) % 2 gives 0 if the sum is even, and 1 if the sum is odd.
        if ((X1 + Y1) % 2 == (X2 + Y2) % 2) {
            // If the parities match, the squares are of the same color.
            // On an 8x8 board, any two squares of the same color are reachable by a knight.
            // The maximum number of moves required between any two squares is 6.
            // Since 100 is an even number, and the minimum moves M will also be even
            // (because start and end squares have the same color), we can always reach
            // the target in exactly 100 moves. We can "waste" (100 - M) moves by
            // repeatedly moving back and forth between the target square and one of its
            // adjacent squares (in terms of knight moves). Since (100 - M) is even,
            // this strategy works. Every square on an 8x8 board has at least two
            // valid knight moves, so moving away and back is always possible.
            std::cout << "YES\n";
        } else {
            // If the parities do not match, the squares are of different colors.
            // It's impossible to reach a square of a different color in an even number of moves.
            std::cout << "NO\n";
        }
    }

    return 0; // Indicate successful program execution.
}

```