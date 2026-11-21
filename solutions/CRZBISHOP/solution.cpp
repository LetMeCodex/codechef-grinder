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
            //      - If k is even, B_k is at (2,k). It can reach T_j = (j,j) where j = 1+k/2.
            //        This move is possible in 1 step (along r+c=2+k) as no other bishops block its path.
            //      - If k is odd, B_k is at (1,k). It can reach T_j = (j,j) where j = (1+k)/2.
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