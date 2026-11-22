# [The Grid Fill Problem (FILLGRID)](https://www.codechef.com/problems/FILLGRID)
- **Difficulty Rating**: 1393
- **Solved in**: 2 attempt(s)

## Problem Summary

The problem asks us to construct an $N \times N$ grid where each cell must contain either `1` or `-1`. The grid must satisfy a specific condition: for every row and every column, the product of the sum of its elements and the product of its elements must be strictly less than zero. We are guaranteed that a solution always exists.

## Intuition & Mathematical Observation

Let's analyze the given condition for an arbitrary row or column. Suppose a particular row or column contains $k$ occurrences of `-1` and consequently $N-k$ occurrences of `1`.

1.  **Sum of elements ($S$)**:
    The sum $S$ for this row/column would be $k \cdot (-1) + (N-k) \cdot 1 = -k + N - k = N - 2k$.

2.  **Product of elements ($P$)**:
    The product $P$ for this row/column would be $(-1)^k \cdot (1)^{N-k} = (-1)^k$.

The problem condition states that $S \cdot P < 0$. Substituting our expressions for $S$ and $P$:
$(N - 2k) \cdot (-1)^k < 0$.

We need to find a pattern for placing `1`s and `-1`s such that for every row and every column, the number of `-1`s ($k$) satisfies this inequality.

Let's consider two cases based on the parity of $N$:

### Case 1: $N$ is Even

If $N$ is even, we can try a simple strategy: fill *all* cells with `-1`.
In this scenario, for any row or column, the number of `-1`s is $k = N$.
Since $N$ is even, $k=N$ is also an even number.

Let's check the condition with $k=N$:
*   **Sum ($S$)**: $S = N - 2k = N - 2N = -N$.
*   **Product ($P$)**: $P = (-1)^k = (-1)^N$. Since $N$ is even, $P = 1$.
*   **Condition Check**: $S \cdot P = (-N) \cdot 1 = -N$.
Since $N$ is a positive integer ($N \ge 1$), $-N$ is strictly less than zero.
Thus, filling the entire grid with `-1`s satisfies the condition for all even $N$.

### Case 2: $N$ is Odd

If $N$ is odd, the strategy from the even case (all `-1`s) would not work. If $N$ is odd, then $k=N$ would be odd, making $P = (-1)^N = -1$. Then $S \cdot P = (-N) \cdot (-1) = N$, which is not less than zero.

Instead, let's try to make $k$ odd. If $k$ is odd, then $(-1)^k = -1$.
The condition $(N - 2k) \cdot (-1)^k < 0$ becomes $(N - 2k) \cdot (-1) < 0$.
This simplifies to $-(N - 2k) < 0$, or $N - 2k > 0$.
This means $N > 2k$, or $k < N/2$.

A simple way to achieve an odd $k$ (and satisfy $k < N/2$ for most odd $N$) is to place exactly one `-1` in each row and each column. This means $k=1$ for every row and column.
Since $k=1$ is odd, $P = (-1)^1 = -1$.
Let's check the condition with $k=1$:
*   **Sum ($S$)**: $S = N - 2k = N - 2 \cdot 1 = N - 2$.
*   **Product ($P$)**: $P = (-1)^1 = -1$.
*   **Condition Check**: $S \cdot P = (N - 2) \cdot (-1) = 2 - N$.
We need $2 - N < 0$, which implies $N > 2$.
Since $N$ is odd, this strategy works for $N \ge 3$.

To implement this, we can place `-1`s along the main diagonal (i.e., `grid[i][i] = -1`) and `1`s in all other cells. This ensures that every row and every column has exactly one `-1`.

**Example for $N=3$ (odd):**
```
-1  1  1
 1 -1  1
 1  1 -1
```
For any row/column, $k=1$. $S = 3 - 2(1) = 1$. $P = (-1)^1 = -1$. $S \cdot P = 1 \cdot (-1) = -1 < 0$. This works.

### Edge Case: $N=1$

The problem constraints state $1 \le N \le 1000$. For $N=1$, the grid is a $1 \times 1$ matrix.
*   If the cell is `1`: $S=1, P=1 \implies S \cdot P = 1 \not< 0$.
*   If the cell is `-1`: $S=-1, P=-1 \implies S \cdot P = 1 \not< 0$.
It appears that for $N=1$, no solution exists that satisfies the condition. However, the problem statement guarantees that a solution always exists. This suggests that either $N=1$ test cases are not present, or the problem setters implicitly assume $N \ge 2$ for the condition to apply. Given that the provided solution (and many others following this logic) passes, we proceed with the general cases, acknowledging this specific edge case. The code for $N=1$ (which is odd) would output `[-1]`.

## Complexity Analysis

*   **Time Complexity**: The solution iterates through the $N \times N$ grid once to print the elements. This involves $N^2$ print operations. Thus, the time complexity for each test case is $O(N^2)$.
*   **Space Complexity**: The solution only uses a few variables to store $N$ and loop indices. It does not use any auxiliary data structures whose size depends on $N$. Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <iostream>
#include <vector> // Not strictly needed for this solution, but often useful

void solve() {
    int N;
    std::cin >> N;

    if (N % 2 == 0) {
        // N is even. Fill all cells with -1.
        // For any row/column: k=N (even). S = N - 2N = -N. P = (-1)^N = 1. S*P = -N < 0.
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                std::cout << -1 << (j == N - 1 ? "" : " ");
            }
            std::cout << std::endl;
        }
    } else {
        // N is odd. Fill main diagonal with -1, others with 1.
        // For any row/column: k=1 (odd). S = N - 2*1 = N-2. P = (-1)^1 = -1. S*P = -(N-2) = 2-N.
        // For N >= 3, 2-N is negative. So S*P < 0.
        // (Note: For N=1, 2-N = 1, which is not < 0. This case is implicitly handled by problem constraints/test cases.)
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == j) {
                    std::cout << -1 << (j == N - 1 ? "" : " ");
                } else {
                    std::cout << 1 << (j == N - 1 ? "" : " ");
                }
            }
            std::cout << std::endl;
        }
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```