# [Crazy Bishops on Chessboard (CRZBISHOP)](https://www.codechef.com/problems/CRZBISHOP)
- **Difficulty Rating**: 1351
- **Solved in**: 2 attempt(s)

## Problem Summary

The problem asks for the minimum number of moves required to place $N$ bishops on the main diagonal of an $N \times N$ chessboard. The target positions are $(1,1), (2,2), \dots, (N,N)$.

Initially, $N$ bishops are placed as follows:
- Bishop $B_k$ is at $(1,k)$ if $k$ is odd.
- Bishop $B_k$ is at $(2,k)$ if $k$ is even.

A bishop can move to any empty cell along a diagonal in one move.

## Intuition & Mathematical Observation

Let's denote the initial position of bishop $B_k$ as $IP_k$ and its target position as $TP_k = (k,k)$. We want to find the minimum total moves. A bishop requires 1 move if it can reach an empty target cell directly. It requires 2 moves if its path is blocked or its target cell is occupied, necessitating an intermediate empty cell.

We analyze the problem based on the value of $N$:

**Case 1: $N=1$**
- Bishop $B_1$ is at $(1,1)$. Its target is $TP_1=(1,1)$.
- It's already in place. **0 moves**.

**Case 2: $N=2$**
- Bishop $B_1$ is at $(1,1)$. Its target is $TP_1=(1,1)$.
- Bishop $B_2$ is at $(2,2)$. Its target is $TP_2=(2,2)$.
- Both are already in place. **0 moves**.

**Case 3: $N \ge 3$**
For $N \ge 3$, a more complex strategy is needed to minimize moves due to potential conflicts and blockages. The optimal strategy involves a few initial moves to clear paths and then handling conflicts efficiently:

1.  **Bishop $B_1$**: $IP_1=(1,1)$, $TP_1=(1,1)$. $B_1$ is already in its target position. **0 moves**.

2.  **Bishop $B_2$**: $IP_2=(2,2)$, $TP_2=(2,2)$. While $B_2$ is initially at its target, this blocks $B_3$ from moving to $TP_2$. To resolve this, we move $B_2$ from $(2,2)$ to $TP_N=(N,N)$. This is a 1-move diagonal move (along $r-c=0$) and is possible because all intermediate cells $(3,3), \dots, (N-1,N-1)$ are initially empty. This costs **1 move**.
    *After this move, $TP_1$ has $B_1$, $TP_N$ has $B_2$. $TP_2, \dots, TP_{N-1}$ are empty.*

3.  **Bishop $B_3$**: $IP_3=(1,3)$. Its "natural" target is $TP_2=(2,2)$ because $(1,3)$ and $(2,2)$ are on the same anti-diagonal ($r+c=4$). Since $TP_2$ is now empty (as $B_2$ moved out), $B_3$ can move to $(2,2)$ in 1 move. This costs **1 move**.

    At this point, $B_1 \to TP_1$, $B_2 \to TP_N$, $B_3 \to TP_2$. Total 2 moves.
    We are left with $N-3$ bishops ($B_4, \dots, B_N$) and $N-3$ target cells ($TP_3, \dots, TP_{N-1}$).

4.  **Bishops $B_k$ for $k \ge 4$**:
    *   **If $k$ is even**: $B_k$ is at $(2,k)$. Its "natural" target is $TP_{k/2+1} = (k/2+1, k/2+1)$. For example, $B_4$ at $(2,4)$ wants $TP_3=(3,3)$. These are 1-move diagonal paths.
    *   **If $k$ is odd**: $B_k$ is at $(1,k)$. Its "natural" target is $TP_{(k+1)/2} = ((k+1)/2, (k+1)/2)$. For example, $B_5$ at $(1,5)$ wants $TP_3=(3,3)$. These are also 1-move diagonal paths.

    **Conflict Detection**:
    Notice that for any target cell $TP_j = (j,j)$ where $j \ge 3$:
    - Bishop $B_{2j-2}$ (even index) from $(2, 2j-2)$ wants to move to $TP_j$.
    - Bishop $B_{2j-1}$ (odd index) from $(1, 2j-1)$ wants to move to $TP_j$.
    Both bishops desire the same target cell $TP_j$. This creates a conflict.
    The path of $B_{2j-1}$ from $(1, 2j-1)$ to $(j,j)$ passes through $(2, 2j-2)$, which is initially occupied by $B_{2j-2}$. Thus, $B_{2j-1}$ cannot move to $TP_j$ in 1 move if $B_{2j-2}$ is still there.
    However, $B_{2j-2}$ can move to $TP_j$ in 1 move without being blocked by other initial bishop positions.
    Therefore, $B_{2j-2}$ takes $TP_j$ in 1 move. Bishop $B_{2j-1}$ becomes "conflicted" and cannot reach its target in 1 move. A conflicted bishop requires 2 moves (one to an intermediate empty cell, then to an available target cell).

    **Counting Conflicted Bishops (C)**:
    Conflicts occur for $TP_j$ where $j$ ranges from $3$ up to $\lfloor (N+1)/2 \rfloor$. (The largest $k$ for an odd bishop is $N$, so $2j-1 \le N \implies j \le (N+1)/2$).
    The number of such $j$ values is $\lfloor (N+1)/2 \rfloor - 3 + 1 = \lfloor (N+1)/2 \rfloor - 2$.
    Using integer division in C++ for $N \ge 3$, this is equivalent to `(N - 1) / 2 - 1`.
    Let $C = (N - 1) / 2 - 1$.

5.  **Total Moves Calculation**:
    - 1 move for $B_2$ to $TP_N$.
    - 1 move for $B_3$ to $TP_2$.
    - For the remaining $N-3$ bishops ($B_4, \dots, B_N$) and $N-3$ target cells ($TP_3, \dots, TP_{N-1}$):
        - $C$ bishops (the conflicted odd-indexed ones) require 2 moves each.
        - The remaining $(N-3 - C)$ bishops (the even-indexed ones that take their targets, and any odd-indexed ones that aren't conflicted) require 1 move each.
    Total moves = $1 \text{ (for } B_2) + 1 \text{ (for } B_3) + (N - 3 - C) \times 1 + C \times 2$
                $= 2 + N - 3 - C + 2C$
                $= N - 1 + C$

    Substitute $C = (N - 1) / 2 - 1$:
    Total moves = $(N - 1) + ((N - 1) / 2 - 1)$
                $= N - 1 + (N - 1) / 2 - 1$
                $= N - 2 + (N - 1) / 2$

This formula holds for $N \ge 3$.

**Example Walkthroughs:**
-   **N=3**: `ans = 3 - 2 + (3 - 1) / 2 = 1 + 1 = 2`.
    ($B_1 \to TP_1$ (0 moves), $B_2 \to TP_3$ (1 move), $B_3 \to TP_2$ (1 move)). Total 2.
-   **N=4**: `ans = 4 - 2 + (4 - 1) / 2 = 2 + 1 = 3`.
    ($B_1 \to TP_1$ (0 moves), $B_2 \to TP_4$ (1 move), $B_3 \to TP_2$ (1 move), $B_4 \to TP_3$ (1 move)). Total 3.
-   **N=5**: `ans = 5 - 2 + (5 - 1) / 2 = 3 + 2 = 5`.
    ($B_1 \to TP_1$ (0 moves), $B_2 \to TP_5$ (1 move), $B_3 \to TP_2$ (1 move)).
    Remaining: $B_4$ at $(2,4)$, $B_5$ at $(1,5)$. Targets: $TP_3, TP_4$.
    $B_4$ takes $TP_3$ (1 move). $B_5$ is conflicted and takes $TP_4$ (2 moves).
    Total $1+1+1+2 = 5$.

The derived formula correctly covers all cases.

## Complexity Analysis

-   **Time Complexity**: The solution involves reading the number of test cases $T$ and then for each test case, reading $N$ and performing a constant number of arithmetic operations. Thus, the time complexity is $O(1)$ per test case, leading to a total time complexity of $O(T)$. Given $T \le 10^5$, this is highly efficient.

-   **Space Complexity**: The solution uses a few variables to store $T$, $N$, and the calculated answer. This requires a constant amount of memory, resulting in a space complexity of $O(1)$.

## Solution Code

```cpp
#include <iostream>

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases.
    while (T--) {
        long long N;
        std::cin >> N; // Read the size of the matrix N.

        if (N <= 2) {
            // For N=1 and N=2, all bishops are already in their final positions.
            // (1,1) for N=1.
            // (1,1), (2,2) for N=2.
            // So, 0 moves are required.
            std::cout << 0 << "\n";
        } else {
            // For N >= 3, the minimum number of moves can be calculated with a formula.
            // The derivation is as follows:
            // 1. Bishop B1 (at (1,1)) is already in its target position T1. (0 moves)
            // 2. Bishop B2 (at (2,2)) is initially at T2. However, B3 (at (1,3)) can reach T2.
            //    To resolve this, B2 is moved from (2,2) to T_N (N,N). This is a 1-move diagonal
            //    move (along r-c=0) and is possible because all intermediate cells (3,3)...(N-1,N-1)
            //    are initially empty. This costs 1 move.
            //    After this, T1 has B1, TN has B2. T2, ..., T(N-1) are empty.
            // 3. We now need to place N-2 bishops (B3, ..., BN) into N-2 target cells (T2, ..., T(N-1)).
            //    - B3 (at (1,3)) can move to T2 (2,2) in 1 move (along r+c=4). This is possible
            //      because T2 is now empty (B2 moved out). This costs 1 move.
            //    - For other bishops B_k (k >= 4):
            //      - If k is even, B_k is at (2,k). It can reach T_j = (j,j) where j = k/2+1.
            //        This move is possible in 1 step (along r+c=2+k) as no other bishops block its path.
            //      - If k is odd, B_k is at (1,k). It can reach T_j = (j,j) where j = (k+1)/2.
            //        However, this move passes through (2,k-1). Since k is odd, k-1 is even,
            //        meaning B(k-1) is initially at (2,k-1). So B_k (odd) cannot move to T_j
            //        if B(k-1) is still there.
            // 4. Conflicts:
            //    For target cells T_j where j >= 3, two bishops desire it:
            //    - B(2j-2) (even index) from (2, 2j-2) desires T_j.
            //    - B(2j-1) (odd index) from (1, 2j-1) desires T_j.
            //    The strategy is to let B(2j-2) take T_j in 1 move. B(2j-1) is then "conflicted"
            //    as T_j is taken. A conflicted bishop cannot reach its desired T_j and cannot
            //    reach any other T_k in one move. Thus, a conflicted bishop requires 2 moves
            //    (one to an intermediate empty cell, then to an available target cell).
            // 5. Counting conflicts (C):
            //    Conflicts occur for T_j where j ranges from 3 up to floor((N+1)/2).
            //    The number of such j values is floor((N+1)/2) - 3 + 1 = floor((N+1)/2) - 2.
            //    Using integer division for N >= 3, floor((N+1)/2) - 2 is equivalent to (N-1)/2 - 1.
            //    Let C = (N - 1) / 2 - 1.
            // 6. Total moves calculation:
            //    - 1 move for B2 to TN.
            //    - 1 move for B3 to T2.
            //    - For the remaining N-3 bishops (B4 to BN) and N-3 target cells (T3 to T(N-1)):
            //      - C bishops are conflicted and require 2 moves each.
            //      - The remaining (N-3 - C) bishops require 1 move each.
            //    Total moves = 1 (for B2) + 1 (for B3) + (N - 3 - C) * 1 + C * 2
            //                = 2 + N - 3 - C + 2C
            //                = N - 1 + C
            //    Substituting C = (N - 1) / 2 - 1:
            //    ans = (N - 1) + ((N - 1) / 2 - 1)
            //    ans = N - 1 + (N - 1) / 2 - 1
            //    ans = N - 2 + (N - 1) / 2
            long long ans = N - 2 + (N - 1) / 2;
            std::cout << ans << "\n";
        }
    }
    return 0;
}
```