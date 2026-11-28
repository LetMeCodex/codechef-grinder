# [Trace of Matrix (TRACE)](https://www.codechef.com/problems/TRACE)
- **Difficulty Rating**: 1198
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the maximum possible trace among all square submatrices of a given $N \times N$ matrix. The trace of a square matrix is defined as the sum of its diagonal elements. We are given an $N \times N$ matrix $A$ where all elements $A_{ij} \ge 1$.

## Intuition & Mathematical Observation

1.  **Understanding Square Submatrices and Trace**:
    *   A square submatrix is uniquely defined by its top-left corner $(r, c)$ and its side length $L$.
    *   For a submatrix starting at $A[r][c]$ with side length $L$, its diagonal elements are $A[r][c], A[r+1][c+1], \dots, A[r+L-1][c+L-1]$.
    *   The trace of this submatrix is the sum of these $L$ elements.

2.  **Iterating Through All Possible Submatrices**:
    To find the maximum trace, we need to consider every possible square submatrix.
    *   **Top-left corner**: A submatrix can start at any cell $(r, c)$ in the original matrix, where $0 \le r < N$ and $0 \le c < N$.
    *   **Side length**: For a fixed top-left corner $(r, c)$, the maximum possible side length $L$ is limited by the remaining rows and columns. Specifically, $L$ can range from $1$ up to $\min(N-r, N-c)$.

3.  **Efficient Trace Calculation**:
    A naive approach would be to iterate through all $(r, c)$, then all $L$, and for each $(r, c, L)$ combination, sum up the $L$ diagonal elements. This would result in an $O(N^4)$ time complexity, which is too slow for $N=100$.

    We can optimize the trace calculation by observing the relationship between traces of submatrices of increasing size, all starting at the same top-left corner $(r, c)$:
    *   The trace of a $1 \times 1$ submatrix starting at $(r, c)$ is $A[r][c]$.
    *   The trace of a $2 \times 2$ submatrix starting at $(r, c)$ is $A[r][c] + A[r+1][c+1]$.
    *   The trace of an $L \times L$ submatrix starting at $(r, c)$ is the trace of the $(L-1) \times (L-1)$ submatrix starting at $(r, c)$ plus the element $A[r+L-1][c+L-1]$.

    This observation leads to an efficient algorithm:
    *   Initialize `max_trace = 0`.
    *   Iterate through every possible top-left corner $(r, c)$ of a submatrix (from $r=0$ to $N-1$, and $c=0$ to $N-1$).
    *   For each $(r, c)$:
        *   Initialize `current_sum = 0`. This `current_sum` will store the trace of the submatrix currently being considered.
        *   Iterate with an offset `k` starting from $0$. `k` represents how far down and right we are from $(r, c)$ along the diagonal.
        *   As long as the cell $(r+k, c+k)$ is within the matrix bounds:
            *   Add $A[r+k][c+k]$ to `current_sum`.
            *   At this point, `current_sum` holds the trace of the $(k+1) \times (k+1)$ submatrix starting at $(r, c)$.
            *   Update `max_trace = max(max_trace, current_sum)`.
        *   Increment `k`.

4.  **Data Types**:
    Given $N \le 100$ and $A_{ij} \le 100$, the maximum possible trace for a $100 \times 100$ submatrix would be $100 \times 100 = 10000$. This value fits comfortably within a standard `int`. However, using `long long` for `max_trace` and `current_sum` is a safe and recommended practice in competitive programming to prevent potential overflow issues, even if not strictly necessary here. Since $A_{ij} \ge 1$, `max_trace` will always be at least 1 (for any $1 \times 1$ submatrix), so initializing it to 0 is safe.

## Complexity Analysis

*   **Time Complexity**:
    *   The outermost two loops iterate $N$ times for `r` and $N$ times for `c`, contributing $O(N^2)$.
    *   The innermost loop (for `k`) iterates at most $N$ times (e.g., when $r=0, c=0$, `k` goes from $0$ to $N-1$).
    *   Therefore, the total time complexity is $O(N \times N \times N) = O(N^3)$.
    *   Given $N=100$, $N^3 = 100^3 = 1,000,000$ operations. This is well within typical time limits (usually $10^8$ operations per second).

*   **Space Complexity**:
    *   We store the input matrix $A$, which requires $N \times N$ integers. This contributes $O(N^2)$ space.
    *   All other variables (`N`, `max_trace`, `current_sum`, loop counters) use constant space.
    *   Therefore, the total space complexity is $O(N^2)$.
    *   Given $N=100$, $N^2 = 100^2 = 10,000$ integers. If an integer takes 4 bytes, this is approximately $40$ KB, which is well within typical memory limits.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Using namespace std; as requested by critical instructions
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A[i][j];
        }
    }

    long long max_trace = 0; // A_ij >= 1, so trace will be positive. Initialize to 0 is safe.
                             // Max trace for N=100, A_ij=100 is 100*100 = 10000, which fits in int.
                             // Using long long is a safe general practice, though not strictly necessary here.

    // Iterate over all possible top-left corners (r, c) of a submatrix
    // r and c are 0-indexed row and column.
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            // For each (r, c), consider all possible square submatrices
            // that start at (r, c).
            // A submatrix of size l x l starting at (r, c) has diagonal elements:
            // A[r][c], A[r+1][c+1], ..., A[r+l-1][c+l-1]
            
            long long current_sum = 0;
            // Iterate through possible lengths 'l' for submatrices starting at (r,c).
            // 'k' represents the offset from (r,c) along the diagonal.
            // So, l = k+1.
            // The diagonal elements are A[r+k][c+k].
            // The loop continues as long as r+k and c+k are within matrix bounds.
            for (int k = 0; r + k < N && c + k < N; ++k) {
                current_sum += A[r+k][c+k];
                // After adding A[r+k][c+k], current_sum is the trace of a (k+1)x(k+1) submatrix
                // starting at (r,c). Update max_trace if this is larger.
                max_trace = max(max_trace, current_sum);
            }
        }
    }
    
    cout << max_trace << "\n";
}

int main() {
    // Fast I/O as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
```