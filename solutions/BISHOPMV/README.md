# [Bishop Moves (BISHOPMV)](https://www.codechef.com/problems/BISHOPMV)
- **Difficulty Rating**: 914
- **Solved in**: 2 attempt(s)

## Problem Summary

The problem asks us to find the minimum number of moves a bishop needs to travel from a starting square $(X_1, Y_1)$ to an ending square $(X_2, Y_2)$ on a standard 8x8 chessboard. A bishop moves any number of squares diagonally in a single move. If the target square is unreachable, we should output -1.

## Intuition & Mathematical Observation

The core of solving this problem lies in understanding the fundamental properties of a bishop's movement on a chessboard:

1.  **Color Invariance**: A bishop always stays on squares of the same color.
    *   On a chessboard, squares can be colored based on the parity of the sum of their coordinates. For example, $(x, y)$ is "white" if $x+y$ is even, and "black" if $x+y$ is odd (or vice-versa, the specific colors don't matter, only that squares of the same parity sum have the same color).
    *   If the starting square $(X_1, Y_1)$ and the ending square $(X_2, Y_2)$ have different colors, it's impossible for a bishop to reach the target. We can check this by comparing the parity of $X_1+Y_1$ and $X_2+Y_2$. If `(X1 + Y1) % 2 != (X2 + Y2) % 2`, then the squares are of different colors, and the answer is `-1`.

2.  **One Move Condition**: A bishop can reach any square on the same diagonal in a single move.
    *   There are two types of diagonals on a chessboard:
        *   Diagonals where the sum of coordinates ($x+y$) is constant.
        *   Diagonals where the difference of coordinates ($x-y$) is constant.
    *   If the starting and ending squares lie on the same diagonal, the bishop can reach the target in 1 move. This means either $X_1+Y_1 = X_2+Y_2$ OR $X_1-Y_1 = X_2-Y_2$.
    *   If this condition is met (and they are of the same color, which is implicitly handled by the first check), the answer is `1`.

3.  **Two Moves Condition**: If the squares are of the same color but not reachable in 1 move, they are always reachable in 2 moves.
    *   This is a known property for bishops on a standard chessboard. A bishop can always reach any square of the same color in at most two moves.
    *   The strategy involves moving from $(X_1, Y_1)$ to an intermediate square $(X_m, Y_m)$ along one type of diagonal (e.g., $X_1+Y_1 = X_m+Y_m$), and then from $(X_m, Y_m)$ to $(X_2, Y_2)$ along the *other* type of diagonal (e.g., $X_m-Y_m = X_2-Y_2$).
    *   Such an intermediate square $(X_m, Y_m)$ always exists within the board boundaries (1 to 8) and will have integer coordinates, provided the start and end squares are of the same color.
    *   Therefore, if the squares are of the same color and not reachable in 1 move, the answer is `2`.

Combining these observations gives us a complete strategy:
1.  Check if colors are different. If so, output -1.
2.  Else, check if they are on the same diagonal. If so, output 1.
3.  Else (they are same color, but not on same diagonal), output 2.

## Complexity Analysis

*   **Time Complexity**: For each test case, the solution performs a fixed number of arithmetic operations (addition, subtraction, modulo) and comparisons. This takes constant time, $O(1)$. Since there are $T$ test cases, the total time complexity is $O(T)$.
*   **Space Complexity**: The solution only uses a few integer variables to store coordinates and the number of test cases. This requires a constant amount of memory, $O(1)$.

## Solution Code

```cpp
#include <cstdio> // Required for scanf, printf

// No need for 'using namespace std;' when using cstdio functions

void solve() {
    int X1, Y1, X2, Y2;
    // Use scanf for faster input
    scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2);

    // Step 1: Check if the squares are of the same color.
    // Bishops always stay on squares of the same color.
    // If the starting and ending squares have different colors, it's impossible to reach.
    if ((X1 + Y1) % 2 != (X2 + Y2) % 2) {
        // Use printf for faster output
        printf("-1\n");
        return;
    }

    // Step 2: If they are of the same color, check for 1 move.
    // A bishop can reach any square on the same diagonal in 1 move.
    // There are two types of diagonals:
    // 1. Where x + y is constant.
    // 2. Where x - y is constant.
    if (X1 + Y1 == X2 + Y2 || X1 - Y1 == X2 - Y2) {
        printf("1\n");
        return;
    }

    // Step 3: If they are of the same color and not reachable in 1 move, they are reachable in 2 moves.
    // This is a known property for bishops on a standard chessboard.
    // An intermediate square always exists within the board boundaries (1 to 8).
    // The bishop can move from (X1, Y1) to an intermediate square (Xm, Ym) along one diagonal type,
    // and then from (Xm, Ym) to (X2, Y2) along the other diagonal type.
    printf("2\n");
}

int main() {
    // No need for ios_base::sync_with_stdio(false); cin.tie(NULL); with scanf/printf
    
    int T;
    scanf("%d", &T); // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the function to solve the current test case
    }

    return 0; // Indicate successful execution
}
```