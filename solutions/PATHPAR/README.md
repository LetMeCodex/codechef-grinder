# [Path Parity (PATHPAR)](https://www.codechef.com/problems/PATHPAR)
- **Difficulty Rating**: 1098
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to consider an $N \times N$ grid where each cell $(i, j)$ (1-indexed) has a value $A[i][j] = i + N \times (j - 1)$. We need to find a path from cell $(1, 1)$ to cell $(N, N)$ by only moving down (to $(i+1, j)$) or right (to $(i, j+1)$). The "score" of a path is the sum of the values of all cells visited along that path. Given $N$ and a target parity $K$ (where $K=0$ for even and $K=1$ for odd), we must determine if there exists a path whose score has parity $K$.

## Intuition & Mathematical Observation

The core of the problem lies in analyzing the parity of the sum of cell values along any valid path. A path from $(1, 1)$ to $(N, N)$ always consists of $N-1$ down moves and $N-1$ right moves, totaling $2(N-1)$ moves. This means any path visits $2(N-1) + 1$ cells.

Let's analyze the parity of $A[i][j]$:
$A[i][j] \pmod 2 = (i + N \times (j - 1)) \pmod 2$.

We consider two main cases based on the parity of $N$:

### Case 1: $N$ is odd

If $N$ is odd, then $N \pmod 2 = 1$.
So, $N \times (j - 1) \pmod 2 = (j - 1) \pmod 2$.
Therefore, $A[i][j] \pmod 2 = (i + j - 1) \pmod 2$.

The sum of parities along a path $P = \{(r_1, c_1), \dots, (r_m, c_m)\}$ (where $m = 2(N-1)+1$ is the total number of cells visited) is:
$\sum_{p=1}^{m} A[r_p][c_p] \pmod 2 = \sum_{p=1}^{m} (r_p + c_p - 1) \pmod 2$
$= \left( \sum_{p=1}^{m} (r_p + c_p) - \sum_{p=1}^{m} 1 \right) \pmod 2$
$= \left( \sum_{p=1}^{m} (r_p + c_p) - m \right) \pmod 2$.

Let's analyze the parity of $\sum_{p=1}^{m} (r_p + c_p)$.
The path starts at $(1, 1)$, where $r_1+c_1 = 1+1 = 2$ (even).
Each move (down or right) changes $(i, j)$ to $(i+1, j)$ or $(i, j+1)$. In both cases, the sum of coordinates $(i+j)$ changes to $(i+j)+1$, thus flipping its parity.
Since the path visits $m$ cells, it makes $m-1$ moves. The sequence of parities for $(r_p+c_p)$ will be: Even, Odd, Even, Odd, ..., Even (since $m-1 = 2(N-1)$ is even, the last cell $(N,N)$ will have $N+N=2N$ which is even, matching the starting parity).
The sum of an odd number of terms ($m$ terms) with alternating parities starting and ending with Even (E, O, E, O, ..., E) will always be Even.
So, $\sum_{p=1}^{m} (r_p + c_p)$ is always even.

Now, substitute this back into the path sum parity:
Path sum parity $= (\text{Even} - m) \pmod 2$.
Since $m = 2(N-1)+1$, $m$ is always odd.
Path sum parity $= (\text{Even} - \text{Odd}) \pmod 2 = \text{Odd} \pmod 2 = 1$.

**Conclusion for $N$ odd**: Any path from $(1, 1)$ to $(N, N)$ will have an odd score.
*   If $K=0$ (target even parity), it's impossible. Output "No".
*   If $K=1$ (target odd parity), it's always possible. Output "Yes".

### Case 2: $N$ is even

If $N$ is even, then $N \pmod 2 = 0$.
So, $N \times (j - 1)$ is always even.
Therefore, $A[i][j] \pmod 2 = i \pmod 2$.

The sum of parities along a path $P = \{(r_1, c_1), \dots, (r_m, c_m)\}$ is:
$\sum_{p=1}^{m} A[r_p][c_p] \pmod 2 = \sum_{p=1}^{m} r_p \pmod 2$.

We need to check if we can achieve both $K=0$ and $K=1$ for $\sum r_p \pmod 2$. Let's consider two specific paths:

1.  **Path A: Go all right, then all down.**
    Cells visited: $(1,1), (1,2), \dots, (1,N), (2,N), (3,N), \dots, (N,N)$.
    The $r_p$ values are: $1$ (for $N$ cells), then $2, 3, \dots, N$ (for $N-1$ cells).
    $\sum r_p \pmod 2 = (N \times 1 + \sum_{i=2}^{N} i) \pmod 2$.
    Since $N$ is even, $N \times 1$ is even.
    So, $\sum r_p \pmod 2 = (\sum_{i=2}^{N} i) \pmod 2$.
    We know $\sum_{i=1}^{N} i = \frac{N(N+1)}{2}$.
    Thus, $\sum_{i=2}^{N} i = \frac{N(N+1)}{2} - 1$.
    The parity of $\frac{N(N+1)}{2}$: Since $N$ is even, let $N=2X$. Then $\frac{2X(2X+1)}{2} = X(2X+1)$. The parity of $X(2X+1)$ is the same as the parity of $X$ (since $2X+1$ is always odd). So, $\frac{N(N+1)}{2}$ has the same parity as $N/2$.
    Therefore, for Path A, $\sum r_p \pmod 2 = \left( (N/2 \pmod 2) - 1 \right) \pmod 2$.

2.  **Path B: Go all down, then all right.**
    Cells visited: $(1,1), (2,1), \dots, (N,1), (N,2), \dots, (N,N)$.
    The $r_p$ values are: $1, 2, \dots, N$ (for $N$ cells), then $N$ (for $N-1$ cells).
    $\sum r_p \pmod 2 = (\sum_{i=1}^{N} i + (N-1) \times N) \pmod 2$.
    Since $N$ is even, $(N-1) \times N$ is even.
    So, $\sum r_p \pmod 2 = (\sum_{i=1}^{N} i) \pmod 2$.
    As established, $\sum_{i=1}^{N} i = \frac{N(N+1)}{2}$, which has the same parity as $N/2$.
    Therefore, for Path B, $\sum r_p \pmod 2 = (N/2 \pmod 2)$.

Let $P_{N/2} = N/2 \pmod 2$.
*   Path A parity: $(P_{N/2} - 1) \pmod 2$.
*   Path B parity: $P_{N/2} \pmod 2$.

These two parities are always different. If $P_{N/2}=0$, Path A gives $1$ and Path B gives $0$. If $P_{N/2}=1$, Path A gives $0$ and Path B gives $1$.
This means that when $N$ is even, we can always find a path that results in an even score and another path that results in an odd score.

**Conclusion for $N$ even**: Both $K=0$ and $K=1$ are achievable. Always output "Yes".

### Final Logic

*   If $N$ is odd:
    *   If $K=0$, output "No".
    *   If $K=1$, output "Yes".
*   If $N$ is even:
    *   Output "Yes" (for both $K=0$ and $K=1$).

This logic covers all cases and directly leads to the solution.

## Complexity Analysis

*   **Time Complexity**: For each test case, the solution performs a few constant-time arithmetic operations and comparisons. Therefore, the time complexity per test case is $O(1)$. With $T$ test cases, the total time complexity is $O(T)$.
*   **Space Complexity**: The solution uses a few variables to store $N$, $K$, and the loop counter. This requires a constant amount of memory, so the space complexity is $O(1)$.

## Solution Code

```cpp
#include <iostream>

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        long long n; // Grid size N (can be up to 10^18, so long long is necessary)
        int k;       // Target parity K (0 for even, 1 for odd)
        std::cin >> n >> k;

        // Apply the derived logic:
        // Case 1: N is odd.
        //   As proven, any path sum will have an odd parity.
        //   So, if K=0 (target even), it's impossible.
        //   If K=1 (target odd), it's always possible.
        if (n % 2 != 0) { // N is odd
            if (k == 0) {
                std::cout << "No\n";
            } else { // k == 1
                std::cout << "Yes\n";
            }
        } 
        // Case 2: N is even.
        //   As proven, we can construct paths that yield both even and odd parities for the sum.
        //   So, for any K (0 or 1), it's always possible.
        else { // N is even
            std::cout << "Yes\n";
        }
    }
    return 0;
}

```