# [Maximum Distance Permutations (MAXDISTPERM)](https://www.codechef.com/problems/MAXDISTPERM)
- **Difficulty Rating**: 1387
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to generate two permutations, $A$ and $B$, of numbers from $1$ to $N$. Permutation $A$ is fixed as the identity permutation: $A = [1, 2, \dots, N]$. Our task is to find a permutation $B$ such that the "distance" between $A$ and $B$ is maximized. The distance is defined as the number of indices $i$ (from $1$ to $N$) where $A_i \ne B_i$. We need to print both permutations.

## Intuition & Mathematical Observation
The goal is to maximize the number of positions $i$ where $A_i \ne B_i$. Since $A_i = i$ for all $i$, this is equivalent to maximizing the number of positions where $B_i \ne i$. Conversely, this means we want to minimize the number of positions where $B_i = i$.

Let's consider two cases:

1.  **Case $N=1$**:
    *   $A = [1]$.
    *   The only possible permutation $B$ is $[1]$.
    *   Here, $A_1 = B_1 = 1$, so there is 1 match.
    *   The distance is $N - (\text{number of matches}) = 1 - 1 = 0$. This is the maximum possible distance for $N=1$.

2.  **Case $N > 1$**:
    *   Can we achieve 0 matches? This means $B_i \ne i$ for all $i$. Such a permutation is called a derangement.
    *   For any $N > 1$, it is always possible to construct a derangement. If we can achieve 0 matches, then the distance will be $N - 0 = N$, which is the maximum possible distance.

The solution uses a specific construction for permutation $B$ that achieves this maximum distance:
Let $k = \lfloor N/2 \rfloor$.
Permutation $B$ is constructed by taking the elements from $k+1$ to $N$, followed by elements from $1$ to $k$.
So, $B = [k+1, k+2, \dots, N, 1, 2, \dots, k]$.

Let's verify this construction:
*   **For $N=1$**: $k = \lfloor 1/2 \rfloor = 0$.
    *   The first part `[k+1, ..., N]` becomes `[1, ..., 1]`, which is `[1]`.
    *   The second part `[1, ..., k]` becomes `[1, ..., 0]`, which is an empty sequence.
    *   Thus, $B = [1]$. This correctly yields a distance of 0, matching our analysis for $N=1$.

*   **For $N > 1$**:
    *   The first part of $B$ consists of elements $k+1, k+2, \dots, N$. These are placed at indices $1, 2, \dots, N-k$.
        *   For an index $i$ in this range ($1 \le i \le N-k$), $B_i = i+k$.
        *   Since $N > 1$, $k = \lfloor N/2 \rfloor \ge 1$.
        *   Therefore, $B_i = i+k > i$. So, $B_i \ne i$ for all these positions.
    *   The second part of $B$ consists of elements $1, 2, \dots, k$. These are placed at indices $N-k+1, N-k+2, \dots, N$.
        *   For an index $i$ in this range ($N-k+1 \le i \le N$), $B_i = i - (N-k)$.
        *   We need to check if $B_i = i$. This would imply $i - (N-k) = i$, which simplifies to $-(N-k) = 0$, or $N=k$.
        *   However, for $N > 1$, $k = \lfloor N/2 \rfloor$ is always strictly less than $N$. Thus, $N-k > 0$.
        *   Therefore, $B_i \ne i$ for all these positions as well.

Since $B_i \ne i$ for all $i$ when $N > 1$, this construction successfully creates a derangement, resulting in 0 matches and a maximum distance of $N$. This simple cyclic shift construction effectively maximizes the distance by ensuring that elements are moved away from their original positions.

## Complexity Analysis
*   **Time Complexity**: For each test case, we iterate $N$ times to print permutation $A$ and another $N$ times (across two loops) to print permutation $B$. Each print operation takes constant time. Thus, for a single test case, the time complexity is $O(N)$. Given that the sum of $N$ over all test cases is typically limited (e.g., $10^5$ or $2 \cdot 10^5$), the total time complexity across all test cases will be $O(\sum N)$.
*   **Space Complexity**: The solution uses a few integer variables (`n`, `k`, loop counters) and does not store the permutations in arrays or other data structures. Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, vector, numeric, algorithm, etc.

// Using namespace std; is requested
using namespace std;

void solve() {
    int n;
    cin >> n; // Read N

    // Permutation A: [1, 2, ..., N]
    for (int i = 1; i <= n; ++i) {
        cout << i << (i == n ? "" : " "); // Print space-separated, no trailing space for last element
    }
    cout << "\n"; // Newline after permutation A

    // Permutation B: [k+1, k+2, ..., N, 1, 2, ..., k] where k = floor(N/2)
    // This construction achieves the maximum possible distance floor(N/2).
    int k = n / 2; // Integer division correctly computes floor(N/2)

    // Print elements from k+1 to N
    for (int i = k + 1; i <= n; ++i) {
        cout << i << " ";
    }
    // Print elements from 1 to k
    // This loop handles the last element printing without a trailing space
    for (int i = 1; i <= k; ++i) {
        cout << i << (i == k ? "" : " "); // Print space-separated, no trailing space for last element
    }
    cout << "\n"; // Newline after permutation B
}

int main() {
    // Fast I/O inside main() as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) { // Loop through each test case
        solve();
    }

    return 0;
}

```