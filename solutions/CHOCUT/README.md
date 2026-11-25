# [Chococut (CHOCUT)](https://www.codechef.com/problems/CHOCUT)
- **Difficulty Rating**: 1003
- **Solved in**: 1 attempt(s)

## Problem Summary

Alice has a chocolate bar of size $N \times M$ squares. She wants to cut it into two pieces using a single straight cut, which can be either horizontal or vertical. After making the cut, she must give one of the two resulting pieces to Bob. The condition for giving a piece to Bob is that it must contain at least $K$ squares. Alice's goal is to maximize the number of squares she keeps for herself. If she cannot make any cut that satisfies Bob's condition, she keeps 0 squares.

## Intuition & Mathematical Observation

The problem asks us to find the maximum number of squares Alice can keep. This suggests we should explore all possible valid scenarios and pick the best one.

There are three main possibilities for Alice:

1.  **No cut**: Alice keeps the entire chocolate bar ($N \times M$ squares). This is only a valid strategy if Bob requires 0 squares (i.e., $K \le 0$). Since problem constraints state $K \ge 0$, this option is relevant only if $K=0$. In this case, Alice can conceptually give Bob a "zero-square" piece (meaning Bob needs nothing), and she keeps the whole bar.

2.  **Horizontal cut**: Alice makes a cut parallel to the $M$ columns, dividing the $N$ rows into two parts.
    *   A horizontal cut can be made after `r` rows, where `r` must be between `1` and `N-1` (exclusive) to create two distinct, non-empty pieces.
    *   This cut results in two pieces: one of size `r x M` and another of size `(N-r) x M`.
    *   Let `size1 = r * M` and `size2 = (N - r) * M`.
    *   For each possible `r`, Alice has two choices:
        *   If `size1 >= K`, she can give `size1` to Bob and keep `size2`.
        *   If `size2 >= K`, she can give `size2` to Bob and keep `size1`.
    *   She will consider both valid options (if any) and update her maximum kept squares.

3.  **Vertical cut**: Alice makes a cut parallel to the $N$ rows, dividing the $M$ columns into two parts.
    *   A vertical cut can be made after `c` columns, where `c` must be between `1` and `M-1` (exclusive) to create two distinct, non-empty pieces.
    *   This cut results in two pieces: one of size `N x c` and another of size `N x (M-c)`.
    *   Let `size1 = N * c` and `size2 = N * (M - c)`.
    *   Similar to the horizontal cut, for each possible `c`, Alice has two choices:
        *   If `size1 >= K`, she can give `size1` to Bob and keep `size2`.
        *   If `size2 >= K`, she can give `size2` to Bob and keep `size1`.
    *   She will consider both valid options (if any) and update her maximum kept squares.

Alice initializes her maximum kept squares to 0. She then iterates through all these possibilities. If, after checking all options, `max_alice_squares` is still 0, it means no valid cut could be made to satisfy Bob, which aligns with the problem statement.

**Example Walkthrough:**
Suppose $N=3, M=4, K=5$. Total squares = 12.
*   **No cut**: $K=5 > 0$, so this option is not valid for keeping the whole bar. `max_alice_squares = 0`.
*   **Horizontal cuts (r from 1 to N-1=2)**:
    *   `r=1`: Pieces are `1x4` (size 4) and `2x4` (size 8).
        *   `size1=4`: $4 < K=5$. Cannot give to Bob.
        *   `size2=8`: $8 \ge K=5$. Can give 8 to Bob, keep 4. `max_alice_squares = max(0, 4) = 4`.
    *   `r=2`: Pieces are `2x4` (size 8) and `1x4` (size 4).
        *   `size1=8`: $8 \ge K=5$. Can give 8 to Bob, keep 4. `max_alice_squares = max(4, 4) = 4`.
        *   `size2=4`: $4 < K=5$. Cannot give to Bob.
*   **Vertical cuts (c from 1 to M-1=3)**:
    *   `c=1`: Pieces are `3x1` (size 3) and `3x3` (size 9).
        *   `size1=3`: $3 < K=5$. Cannot give to Bob.
        *   `size2=9`: $9 \ge K=5$. Can give 9 to Bob, keep 3. `max_alice_squares = max(4, 3) = 4`.
    *   `c=2`: Pieces are `3x2` (size 6) and `3x2` (size 6).
        *   `size1=6`: $6 \ge K=5$. Can give 6 to Bob, keep 6. `max_alice_squares = max(4, 6) = 6`.
        *   `size2=6`: $6 \ge K=5$. Can give 6 to Bob, keep 6. `max_alice_squares = max(6, 6) = 6`.
    *   `c=3`: Pieces are `3x3` (size 9) and `3x1` (size 3).
        *   `size1=9`: $9 \ge K=5$. Can give 9 to Bob, keep 3. `max_alice_squares = max(6, 3) = 6`.
        *   `size2=3`: $3 < K=5$. Cannot give to Bob.

Final `max_alice_squares = 6`.

## Complexity Analysis

*   **Time Complexity**:
    *   Reading input `N, M, K`: $O(1)$.
    *   Checking the "no cut" option: $O(1)$.
    *   Loop for horizontal cuts: This loop runs `N-1` times (from `r=1` to `N-1`). Inside the loop, operations are constant time. So, $O(N)$.
    *   Loop for vertical cuts: This loop runs `M-1` times (from `c=1` to `M-1`). Inside the loop, operations are constant time. So, $O(M)$.
    *   For each test case, the total time complexity is $O(N + M)$.
    *   Given $T$ test cases, the overall time complexity is $O(T \cdot (N + M))$.
    *   With constraints $T \le 100$ and $N, M \le 100$, the maximum operations would be approximately $100 \cdot (100 + 100) = 20000$, which is very efficient and well within typical time limits.

*   **Space Complexity**:
    *   The solution uses a few integer variables (`N, M, K, max_alice_squares, r, c, size1, size2`). These variables consume a constant amount of memory regardless of the input size.
    *   Therefore, the space complexity is $O(1)$ per test case.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, algorithm, etc.

// Using namespace std; as requested
using namespace std;

void solve() {
    int N, M, K;
    cin >> N >> M >> K; // Read N, M, K for the current test case

    int max_alice_squares = 0; // Initialize maximum squares Alice can keep

    // Option 1: Alice makes no cut and keeps the entire bar.
    // This is only possible if Bob is happy receiving 0 squares (i.e., K <= 0).
    // The problem constraints state K >= 0. So this condition applies specifically if K=0.
    if (0 >= K) {
        max_alice_squares = max(max_alice_squares, N * M);
    }

    // Option 2: Alice makes a horizontal cut.
    // A horizontal cut divides the N rows into two parts: 'r' rows and 'N-r' rows.
    // 'r' must be between 1 and N-1 to create two distinct pieces.
    for (int r = 1; r < N; ++r) {
        int size1 = r * M;         // Squares in the first piece (r x M)
        int size2 = (N - r) * M;   // Squares in the second piece ((N-r) x M)

        // If the first piece (size1) is large enough for Bob, Alice can give it to Bob
        // and keep the second piece (size2).
        if (size1 >= K) {
            max_alice_squares = max(max_alice_squares, size2);
        }
        // If the second piece (size2) is large enough for Bob, Alice can give it to Bob
        // and keep the first piece (size1).
        if (size2 >= K) {
            max_alice_squares = max(max_alice_squares, size1);
        }
    }

    // Option 3: Alice makes a vertical cut.
    // A vertical cut divides the M columns into two parts: 'c' columns and 'M-c' columns.
    // 'c' must be between 1 and M-1 to create two distinct pieces.
    for (int c = 1; c < M; ++c) {
        int size1 = N * c;         // Squares in the first piece (N x c)
        int size2 = N * (M - c);   // Squares in the second piece (N x (M-c))

        // If the first piece (size1) is large enough for Bob, Alice can give it to Bob
        // and keep the second piece (size2).
        if (size1 >= K) {
            max_alice_squares = max(max_alice_squares, size2);
        }
        // If the second piece (size2) is large enough for Bob, Alice can give it to Bob
        // and keep the first piece (size1).
        if (size2 >= K) {
            max_alice_squares = max(max_alice_squares, size1);
        }
    }

    // Output the maximum number of squares Alice can keep.
    cout << max_alice_squares << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}
```