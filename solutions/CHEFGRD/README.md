```cpp
#include <iostream>
#include <cmath>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        long long n, xs, ys;
        std::cin >> n >> xs >> ys;
        
        // The center of the grid is at ((N+1)/2, (N+1)/2).
        // Since N is odd, N+1 is even, so (N+1)/2 is an integer.
        long long center_coord = (n + 1) / 2;
        
        // Calculate the absolute difference in coordinates from the center.
        long long dist_x_abs = std::abs(xs - center_coord);
        long long dist_y_abs = std::abs(ys - center_coord);
        
        // Condition for 0 cost:
        // Akash can reach the center using only diagonal moves if and only if
        // the absolute difference in his x-coordinate from the center is equal to
        // the absolute difference in his y-coordinate from the center.
        // That is, |xs - center_coord| == |ys - center_coord|.
        //
        // Additionally, consider the grid colored like a chessboard.
        // A diagonal move always stays on the same color.
        // A horizontal or vertical move always switches the color.
        // The center cell ((N+1)/2, (N+1)/2) has a sum of coordinates (N+1)/2 + (N+1)/2 = N+1.
        // Since N is odd, N+1 is even. So, the center cell has an even sum of coordinates.
        // A cell (r, c) has the same color as the center if r+c is even, which means r and c have the same parity.
        // If the starting cell (xs, ys) has the same parity (i.e., xs % 2 == ys % 2), it's on the same color square as the center.
        //
        // If Akash is on a square of the same color as the center (xs % 2 == ys % 2),
        // AND he is not on a direct diagonal to the center (|xs - center_coord| != |ys - center_coord|),
        // he can still reach the center with 0 cost. This is because if the parities match,
        // there exists a path of diagonal moves from (xs, ys) to some cell (x', y')
        // such that |x' - center_coord| = |y' - center_coord|.
        //
        // Therefore, the cost is 0 if:
        // 1. |xs - center_coord| == |ys - center_coord| (already on a diagonal to the center)
        // OR
        // 2. xs and ys have the same parity (xs % 2 == ys % 2) (on the same color square as the center).
        
        if (dist_x_abs == dist_y_abs || (xs % 2) == (ys % 2)) {
            std::cout << 0 << "\n";
        } else {
            // If neither of the above conditions is met, it means:
            // - |xs - center_coord| != |ys - center_coord| (not on a direct diagonal to the center)
            // - xs and ys have different parity (xs % 2 != ys % 2) (on a different color square than the center)
            //
            // In this scenario, Akash must make at least one horizontal or vertical move to change the color of his square.
            // A single horizontal or vertical move changes the parity of the sum of coordinates (xs + ys).
            // If xs and ys have different parity, xs + ys is odd. After one move, the new sum will be even, matching the center's parity.
            // It can be shown that one such move is always sufficient to reach a cell from which the center is reachable by diagonal moves.
            // Thus, the minimum cost is 1.
            std::cout << 1 << "\n";
        }
    }
    return 0;
}
```

## Akash and Grid (CHEFGRD)

### Difficulty Rating: 1311
### Solved in: 1 attempt(s)

## Problem Summary

The problem asks for the minimum number of gold coins required for Akash to travel from a starting cell $(xs, ys)$ to the center cell of an $N \times N$ grid. Akash can move freely along diagonals any number of steps. Moving one step horizontally or vertically costs 1 gold coin. The grid size $N$ is always odd.

## Intuition & Mathematical Observation

1.  **Center of the Grid**: Since $N$ is odd, the center of the grid is at coordinates $((N+1)/2, (N+1)/2)$. Let's denote this as $(cx, cy)$.

2.  **Diagonal Movement**: Akash can move freely along diagonals. This means if he is at $(r, c)$, he can reach any cell $(r \pm k, c \pm k)$ or $(r \pm k, c \mp k)$ for any $k \ge 1$ using only diagonal moves.

3.  **Costly Movement**: Horizontal and vertical moves cost 1 coin.

4.  **Goal**: Minimize the number of coins spent. This means maximizing the use of free diagonal moves.

5.  **Reaching the Center with 0 Cost**:
    Akash can reach the center $(cx, cy)$ using only diagonal moves if and only if he is already on a "diagonal path" leading to the center. This condition is met when the absolute difference between his current x-coordinate and the center's x-coordinate is equal to the absolute difference between his current y-coordinate and the center's y-coordinate. Mathematically, this is $|xs - cx| = |ys - cy|$.

6.  **Chessboard Coloring**: Consider coloring the grid like a chessboard. A cell $(r, c)$ can be assigned a color based on the parity of $r+c$.
    *   If $r+c$ is even, it's one color (e.g., white).
    *   If $r+c$ is odd, it's the other color (e.g., black).
    A diagonal move from $(r, c)$ to $(r \pm 1, c \pm 1)$ or $(r \pm 1, c \mp 1)$ results in a new sum of coordinates $(r \pm 1) + (c \pm 1) = r+c \pm 2$ or $(r \pm 1) + (c \mp 1) = r+c$. In all cases, the parity of the sum of coordinates remains unchanged. Thus, diagonal moves always keep Akash on squares of the same color.
    A horizontal or vertical move from $(r, c)$ to $(r \pm 1, c)$ or $(r, c \pm 1)$ changes the sum of coordinates by $\pm 1$, thus flipping the parity. This means a horizontal or vertical move always switches the color of the square.

7.  **Center's Color**: The center cell $(cx, cy)$ has $cx = cy = (N+1)/2$. The sum of coordinates is $cx + cy = (N+1)/2 + (N+1)/2 = N+1$. Since $N$ is odd, $N+1$ is even. Therefore, the center cell is always on an "even sum" colored square.

8.  **0 Cost Condition Refined**:
    Akash can reach the center with 0 cost if he can reach *any* cell $(x', y')$ from $(xs, ys)$ using only diagonal moves, such that $(x', y')$ is on a diagonal path to the center.
    *   A cell $(x', y')$ is reachable from $(xs, ys)$ using only diagonal moves if $|x' - xs| = |y' - ys|$.
    *   A cell $(x', y')$ is on a diagonal path to the center if $|x' - cx| = |y' - cy|$.
    We need to find if there exists $(x', y')$ satisfying both conditions. This is possible if:
    *   $|xs - cx| = |ys - cy|$ (This is the original condition for 0 cost).
    *   OR, if $xs$ and $ys$ have the same parity ($xs \% 2 == ys \% 2$). If $xs$ and $ys$ have the same parity, then $xs+ys$ is even. Since $cx+cy$ is also even, this implies that $(xs, ys)$ is on the same color square as the center. If they are on the same color square, it can be shown that there exists a cell $(x', y')$ reachable diagonally from $(xs, ys)$ that is also on a diagonal to the center.

    So, the cost is 0 if $|xs - cx| = |ys - cy|$ OR $xs \% 2 == ys \% 2$.

9.  **1 Cost Condition**:
    If the 0-cost condition is not met, it means:
    *   $|xs - cx| \neq |ys - cy|$ (Akash is not on a direct diagonal to the center).
    *   $xs \% 2 \neq ys \% 2$ (Akash is on a different color square than the center).
    In this case, Akash must make at least one horizontal or vertical move to change the color of his square to match the center's color. A single horizontal or vertical move is sufficient to change the parity of the sum of coordinates. After one move, Akash will be on a square with the same parity sum as the center. It can be shown that one such move is always sufficient to reach a state from which the center is reachable diagonally. Therefore, the minimum cost is 1.

## Complexity Analysis

*   **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a few constant-time arithmetic operations and comparisons.
*   **Space Complexity**: $O(1)$, as we only use a few variables to store intermediate calculations for each test case.

## Solution Code

```cpp
#include <iostream>
#include <cmath>
#include <algorithm>

int main() {
    // Optimize C++ standard streams for competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        long long n, xs, ys; // Grid size N, starting coordinates (xs, ys)
        std::cin >> n >> xs >> ys;
        
        // Calculate the coordinates of the center of the grid.
        // Since N is odd, (N+1)/2 is an integer.
        long long center_coord = (n + 1) / 2;
        
        // Calculate the absolute differences in coordinates from the center.
        long long dist_x_abs = std::abs(xs - center_coord);
        long long dist_y_abs = std::abs(ys - center_coord);
        
        // Condition for 0 cost:
        // Akash can reach the center with 0 cost if:
        // 1. He is already on a diagonal path to the center: |xs - center_coord| == |ys - center_coord|.
        // OR
        // 2. He is on a square of the same color as the center. The center has an even sum of coordinates (N+1).
        //    A square (r, c) has the same color as the center if r+c is even, which means r and c have the same parity (r % 2 == c % 2).
        //    So, if xs and ys have the same parity (xs % 2 == ys % 2), he is on the same color square.
        
        if (dist_x_abs == dist_y_abs || (xs % 2) == (ys % 2)) {
            // If either condition is met, 0 coins are needed.
            std::cout << 0 << "\n";
        } else {
            // If neither of the 0-cost conditions is met, it means:
            // - Akash is not on a direct diagonal to the center (|xs - center_coord| != |ys - center_coord|).
            // - Akash is on a different color square than the center (xs % 2 != ys % 2).
            // In this case, Akash must make at least one horizontal or vertical move to change the color of his square.
            // One such move is always sufficient to reach a state from which the center is reachable diagonally.
            // Thus, the minimum cost is 1 coin.
            std::cout << 1 << "\n";
        }
    }
    return 0;
}
```