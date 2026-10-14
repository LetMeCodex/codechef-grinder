# [Chocolate Cutting (CHOCCUT)](https://www.codechef.com/problems/CHOCCUT)
- **Difficulty Rating**: 512
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks whether a chocolate bar of size $N \times M$ (meaning $N$ rows and $M$ columns) can be divided into two *equal* pieces using a single straight cut. The cut can be either horizontal (parallel to the $M$-length side) or vertical (parallel to the $N$-length side).

## Intuition & Mathematical Observation

The core of the problem lies in understanding what "equal pieces" means in this context. For two pieces to be equal, they must have identical dimensions.

Let's consider the two possible types of cuts:

1.  **Horizontal Cut**:
    *   A horizontal cut divides the $N$ rows of the chocolate bar.
    *   To get two equal pieces, the $N$ rows must be split exactly in half. This means one piece would have $N/2$ rows and the other would also have $N/2$ rows.
    *   This is only possible if $N$ is an even number. If $N$ is even, we can make a cut at $N/2$ rows, resulting in two pieces of size $(N/2) \times M$. These two pieces are identical.
    *   If $N$ is odd, say $N=3$, we cannot split it into two equal integer halves (e.g., $1.5$ rows is not a valid dimension for a piece of chocolate). Thus, a horizontal cut cannot yield two equal pieces if $N$ is odd.

2.  **Vertical Cut**:
    *   A vertical cut divides the $M$ columns of the chocolate bar.
    *   Similarly, to get two equal pieces, the $M$ columns must be split exactly in half. This means one piece would have $M/2$ columns and the other would also have $M/2$ columns.
    *   This is only possible if $M$ is an even number. If $M$ is even, we can make a cut at $M/2$ columns, resulting in two pieces of size $N \times (M/2)$. These two pieces are identical.
    *   If $M$ is odd, a vertical cut cannot yield two equal pieces.

**Combining the observations:**

*   If $N$ is even, we can make a horizontal cut and get two equal pieces. So, the answer is "Yes".
*   If $M$ is even, we can make a vertical cut and get two equal pieces. So, the answer is "Yes".

Therefore, if *either* $N$ is even *or* $M$ is even, it's possible to divide the chocolate bar into two equal pieces.

**What if both $N$ and $M$ are odd?**
If $N$ is odd, a horizontal cut won't work. If $M$ is odd, a vertical cut won't work. Since these are the only two allowed types of cuts, if both $N$ and $M$ are odd, it's impossible to make such a division.
This also makes intuitive sense from the total area perspective: if $N$ and $M$ are both odd, their product $N \times M$ (the total number of unit squares) will also be odd. An odd number cannot be divided into two equal integer parts.

So, the condition simplifies to: "Is $N$ even OR is $M$ even?". This can be checked using `N % 2 == 0 || M % 2 == 0`.

## Complexity Analysis

*   **Time Complexity**: $O(1)$ per test case.
    The `solve()` function involves reading two integers, performing two modulo operations, one logical OR operation, and printing a string. All these operations take constant time. Since there are $T$ test cases, the total time complexity is $O(T)$.
*   **Space Complexity**: $O(1)$ per test case.
    The `solve()` function uses a fixed number of integer variables (`N`, `M`) regardless of the input size. No data structures that grow with input are used. Thus, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries

using namespace std; // Common in competitive programming

void solve() {
    int N, M;
    cin >> N >> M;

    // A chocolate bar of size N x M can be divided into 2 equal pieces
    // if a cut can be made either horizontally or vertically such that
    // the two resulting pieces have equal dimensions.

    // Case 1: Horizontal cut
    // If N is even, we can cut the N rows into N/2 and N/2.
    // This results in two pieces of size (N/2) x M. These are equal.
    // So, if N % 2 == 0, it's possible.

    // Case 2: Vertical cut
    // If M is even, we can cut the M columns into M/2 and M/2.
    // This results in two pieces of size N x (M/2). These are equal.
    // So, if M % 2 == 0, it's possible.

    // If either N is even OR M is even, it's possible to make such a cut.
    // If both N and M are odd, then N*M is odd, meaning the total number of pieces
    // is odd. It's impossible to divide an odd number of pieces into two equal integer parts.
    // In this case, neither N nor M is even, so no valid cut can be made.

    if (N % 2 == 0 || M % 2 == 0) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    // Fast I/O
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