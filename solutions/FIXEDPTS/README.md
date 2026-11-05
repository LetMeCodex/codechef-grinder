# [Fixed Points (FIXEDPTS)](https://www.codechef.com/problems/FIXEDPTS)
- **Difficulty Rating**: 884
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if it's possible to construct a permutation $P$ of length $N$ (containing elements from $1$ to $N$) such that it has exactly $K$ fixed points. A fixed point is an index $i$ where $P_i = i$. We need to output "Yes" if such a permutation exists, and "No" otherwise, for multiple test cases.

## Intuition & Mathematical Observation

The core of this problem lies in a fundamental property of permutations:

**It is impossible for a permutation of $N$ elements to have exactly $N-1$ fixed points.**

Let's prove this:
Assume, for the sake of contradiction, that a permutation $P$ of $N$ elements has exactly $N-1$ fixed points. This means there is exactly one element, say at index $x$, for which $P_x \neq x$. For all other indices $j \neq x$, we must have $P_j = j$.

Since $P$ is a permutation, the set of values $\{P_1, P_2, \ldots, P_N\}$ must be exactly $\{1, 2, \ldots, N\}$.
From our assumption, for all $j \neq x$, $P_j = j$. This means the values $\{P_j \mid j \neq x\}$ are precisely the set $\{j \mid j \neq x\}$.
The only value remaining in the set $\{1, 2, \ldots, N\}$ that has not been used is $x$.
The only position remaining in the set $\{1, 2, \ldots, N\}$ that has not been assigned a value is $x$.
Therefore, it must be that $P_x = x$.
This contradicts our initial assumption that $P_x \neq x$.
Hence, our assumption was false, and a permutation cannot have exactly $N-1$ fixed points.

**For all other values of $K$ (from $0$ to $N$, excluding $N-1$), such a permutation exists:**

1.  **If $K = N$:**
    The identity permutation $P = [1, 2, \ldots, N]$ has $N$ fixed points (every element is a fixed point).
    *Example: $N=3, K=3 \Rightarrow P=[1,2,3]$*

2.  **If $K \le N-2$ (i.e., $K$ can be $0, 1, \ldots, N-2$):**
    We can construct such a permutation.
    *   First, fix the first $K$ elements: $P_i = i$ for $i = 1, \ldots, K$. These are our $K$ fixed points.
    *   For the remaining $N-K$ elements (indices $K+1, \ldots, N$ and values $K+1, \ldots, N$), we need to arrange them such that *none* are fixed points. This is a derangement problem.
    *   Let $M = N-K$ be the number of elements we need to derange.
    *   Since $K \le N-2$, it implies $M = N-K \ge N-(N-2) = 2$.
    *   Derangements exist for any number of elements $M \ge 2$. A simple way to construct a derangement for $M \ge 2$ elements is a cyclic shift:
        $P_{K+1} = K+2$
        $P_{K+2} = K+3$
        $\ldots$
        $P_{N-1} = N$
        $P_N = K+1$
    *   This arrangement ensures that none of the elements from $K+1$ to $N$ are fixed points.
    *   Thus, such a permutation exists.
    *Example: $N=3, K=0 \Rightarrow M=3$. We need to derange elements $1,2,3$. A derangement is $P=[2,3,1]$.*
    *Example: $N=3, K=1 \Rightarrow M=2$. Fix $P_1=1$. We need to derange elements $2,3$. A derangement is $P_2=3, P_3=2$. The full permutation is $P=[1,3,2]$.*

**Conclusion:**
Based on these observations, the only case where it's impossible to construct a permutation with exactly $K$ fixed points is when $K = N-1$. For all other values of $K$ (from $0$ to $N$), it is possible.

Therefore, the solution is simply to check if $K$ is equal to $N-1$. If it is, output "No"; otherwise, output "Yes".

## Complexity Analysis

*   **Time Complexity**: $O(1)$ per test case.
    The `solve()` function performs a constant number of operations: reading two integers, comparing them, and printing a string. Since there are $T$ test cases, the total time complexity is $O(T)$.

*   **Space Complexity**: $O(1)$ per test case.
    The program uses a constant amount of memory for variables `N`, `K`, and `T`, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Use standard namespace to avoid writing std::
using namespace std;

// Function to solve a single test case
void solve() {
    int N, K; // Declare N and K
    cin >> N >> K; // Read N and K from input

    // The core logic is based on a property of permutations:
    // It is impossible for a permutation of N elements to have exactly N-1 fixed points.
    //
    // Proof:
    // Assume there are N-1 fixed points. Let these be P_i = i for all i except one index, say 'x'.
    // So, P_j = j for all j != x.
    // Since P is a permutation, the set of values {P_1, P_2, ..., P_N} must be {1, 2, ..., N}.
    // The values {P_j | j != x} are {j | j != x}.
    // This means the value 'x' is not used by any P_j where j != x.
    // The only remaining position is 'x', and the only remaining value is 'x'.
    // Therefore, it must be that P_x = x.
    // This contradicts our assumption that 'x' is not a fixed point (P_x != x).
    // Hence, a permutation cannot have exactly N-1 fixed points.
    //
    // For all other values of K (0 to N, excluding N-1), such a permutation exists:
    // 1. If K = N:
    //    The identity permutation P = [1, 2, ..., N] has N fixed points.
    //    Example: N=3, K=3 -> P=[1,2,3]
    // 2. If K < N-1 (i.e., K <= N-2):
    //    We can construct such a permutation.
    //    Fix the first K elements: P_i = i for i = 1, ..., K.
    //    For the remaining N-K elements (indices K+1, ..., N and values K+1, ..., N),
    //    we need to arrange them such that none are fixed points. This is a derangement problem.
    //    Let M = N-K be the number of elements to derange.
    //    Since K <= N-2, it implies M = N-K >= N-(N-2) = 2.
    //    Derangements exist for any number of elements M >= 2.
    //    For example, a cyclic shift can create a derangement:
    //    P_{K+1} = K+2, P_{K+2} = K+3, ..., P_{N-1} = N, P_N = K+1.
    //    This arrangement ensures that none of the elements from K+1 to N are fixed points.
    //    Thus, such a permutation exists.
    //    Example: N=3, K=0 -> P=[2,3,1] (derangement of 3 elements)
    //    Example: N=3, K=1 -> P=[1,3,2] (fix 1, derange 2 and 3)
    //
    // Based on this, the condition is simply: if K is N-1, output "No", otherwise output "Yes".
    if (K == N - 1) {
        cout << "No\n"; // Output "No" if K is N-1
    } else {
        cout << "Yes\n"; // Output "Yes" for all other K values
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    ios_base::sync_with_stdio(false); // Untie C++ streams from C standard streams
    cin.tie(NULL); // Untie cin from cout

    int T; // Declare T for the number of test cases
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times, decrementing T each iteration
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```