# [Permutation Construct (PERMCON)](https://www.codechef.com/problems/PERMCON)
- **Difficulty Rating**: 1166
- **Solved in**: 2 attempt(s)

## Problem Summary

The problem asks us to construct a permutation $P = [P_1, P_2, \dots, P_N]$ of integers from $1$ to $N$ such that for every $i$ from $1$ to $N$, two conditions are met:
1.  $P_i \neq i$ (i.e., $P$ must be a derangement).
2.  $P_i \equiv i \pmod K$ (i.e., $P_i$ and $i$ must have the same remainder when divided by $K$).

If such a permutation exists, we should print it; otherwise, print `-1`.

## Intuition & Mathematical Observation

The core of the problem lies in the second condition: $P_i \equiv i \pmod K$. This condition implies that an element $i$ must be mapped to an element $P_i$ that belongs to the *same residue class modulo K*. In other words, the permutation operation is restricted to elements within their respective residue classes.

This effectively decomposes the problem into $K$ independent subproblems. For each remainder $r \in \{0, 1, \dots, K-1\}$, we consider the set $S_r = \{j \mid 1 \le j \le N \text{ and } j \equiv r \pmod K\}$. For each such set $S_r$, we need to find a derangement of its elements. That is, if $j \in S_r$, then $P_j$ must also be in $S_r$, and $P_j \neq j$.

A derangement of a set of size $m$ is possible if and only if $m \ge 2$.
*   If $m=0$ or $m=1$, no derangement is possible. For $m=1$, say $S_r = \{x\}$, the only possible mapping is $P_x = x$, which violates $P_x \neq x$.
*   If $m \ge 2$, a simple cyclic shift provides a valid derangement. For example, if $S_r = \{x_1, x_2, \dots, x_m\}$, we can define $P_{x_i} = x_{i+1}$ for $i=1, \dots, m-1$, and $P_{x_m} = x_1$. This ensures $P_j \neq j$ for all $j \in S_r$.

Therefore, a solution exists if and only if *every* residue class $S_r$ (for $r \in \{0, 1, \dots, K-1\}$) has a size of at least 2.

Let's analyze the sizes of these residue classes:
Let $N = qK + \text{rem}$, where $q = \lfloor N/K \rfloor$ and $\text{rem} = N \pmod K$.
*   There are $\text{rem}$ residue classes (e.g., those corresponding to remainders $1, 2, \dots, \text{rem}$ if we consider $1$-based remainders, or $0, 1, \dots, \text{rem}-1$ if $0$-based) that will contain $q+1$ elements.
*   The remaining $K - \text{rem}$ residue classes will contain $q$ elements.

For all classes to have a size of at least 2, we must have $q \ge 2$.
*   **Case 1: $q = 0$ (i.e., $N < K$)**
    In this case, all residue classes $S_r$ for $r \in \{1, \dots, N\}$ have size 1 (e.g., $S_r = \{r\}$). The other $K-N$ classes are empty. Since there are classes of size 1, no derangement is possible.
*   **Case 2: $q = 1$ (i.e., $K \le N < 2K$)**
    In this case, $\text{rem}$ classes have size $q+1 = 2$. The remaining $K-\text{rem}$ classes have size $q=1$. Since there is at least one class of size 1, no derangement is possible.
*   **Case 3: $q \ge 2$ (i.e., $N \ge 2K$)**
    In this case, all classes have size at least $q \ge 2$. Specifically, $\text{rem}$ classes have size $q+1 \ge 3$, and $K-\text{rem}$ classes have size $q \ge 2$. Since all classes have size at least 2, a derangement is always possible.

Combining these observations, a solution exists if and only if $N \ge 2K$. If $N < 2K$, we print `-1`.

If $N \ge 2K$, we construct the permutation as follows:
1.  Group all numbers from $1$ to $N$ by their remainder modulo $K$. Store these groups, for example, in a `std::vector<std::vector<int>> groups(K)`. `groups[r]` will contain all $j$ such that $1 \le j \le N$ and $j \pmod K = r$.
2.  For each group `groups[r]`:
    *   Let the elements in this group be $x_0, x_1, \dots, x_{m-1}$ (where $m$ is the size of the group).
    *   Apply a cyclic shift: set $P_{x_i} = x_{(i+1) \pmod m}$ for all $i=0, \dots, m-1$.
3.  Print the resulting permutation $P_1, P_2, \dots, P_N$.

This strategy guarantees $P_i \neq i$ (because $m \ge 2$) and $P_i \equiv i \pmod K$ (because elements are only permuted within their residue classes).

## Complexity Analysis

*   **Time Complexity**:
    *   Reading $N$ and $K$: $O(1)$.
    *   Grouping elements: We iterate from $i=1$ to $N$, performing a modulo operation and a `push_back`. This takes $O(N)$ time.
    *   Constructing the permutation: We iterate through $K$ groups. For each group, we iterate through its elements to apply the cyclic shift. The total number of elements across all groups is $N$. Thus, this step takes $O(N)$ time.
    *   Printing the permutation: We iterate from $i=1$ to $N$ to print $P_i$. This takes $O(N)$ time.
    *   Overall, for each test case, the time complexity is $O(N)$.

*   **Space Complexity**:
    *   `groups` vector of vectors: This structure stores all $N$ numbers from $1$ to $N$. This requires $O(N)$ space.
    *   `p` vector: This vector stores the resulting permutation of $N$ elements. This requires $O(N)$ space.
    *   Overall, the space complexity for each test case is $O(N)$.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <numeric> // Not strictly needed for this solution, but good for general utility

void solve() {
    int n, k;
    std::cin >> n >> k;

    // Condition for no solution:
    // If N < 2K, at least one residue class modulo K will contain only one element.
    // A derangement of a set of size 1 is impossible.
    //
    // Let N = qK + r, where 0 <= r < K.
    // The sizes of residue classes (j % K) are:
    // - q+1 for 'rem' classes (1 to rem)
    // - q for K-'rem' classes (rem+1 to K-1, and 0)
    //
    // If q = 0 (i.e., N < K): All classes 1 to N have size 1. No solution.
    // If q = 1 (i.e., K <= N < 2K):
    //   Classes 1 to N%K have size 2.
    //   Classes N%K+1 to K-1 (and 0) have size 1.
    //   Since there's at least one class of size 1, no solution.
    //
    // Thus, if N < 2K, no solution exists.
    if (n < 2 * k) {
        std::cout << -1 << "\n";
        return;
    }

    // If N >= 2K, then q = floor(N/K) >= 2.
    // This means all residue classes modulo K will have size at least 2.
    // For a set of size m >= 2, a cyclic shift is a valid derangement.
    // Example: for {x1, x2, ..., xm}, map x_i to x_{i+1} (with x_m mapping to x_1).
    
    // Store elements grouped by their remainder modulo K.
    // groups[r] will contain all numbers j such that 1 <= j <= N and j % K == r.
    // Note: i % k for i=1..N will produce remainders 1, 2, ..., k-1, 0.
    // So groups[0] will store multiples of K, groups[1] for 1, 1+K, etc.
    std::vector<std::vector<int>> groups(k);
    for (int i = 1; i <= n; ++i) {
        groups[i % k].push_back(i);
    }

    // P will store the resulting permutation. P[i] is the value at index i.
    // Using 1-based indexing for P for convenience, so size N+1.
    std::vector<int> p(n + 1);

    // For each remainder group, apply a cyclic shift.
    for (int r = 0; r < k; ++r) {
        const auto& current_group = groups[r];
        int group_size = current_group.size();
        
        // As established, group_size >= 2 when N >= 2K, so a cyclic shift is always valid.
        for (int i = 0; i < group_size; ++i) {
            int current_val = current_group[i];
            int next_val = current_group[(i + 1) % group_size]; // Cyclic shift
            p[current_val] = next_val;
        }
    }

    // Print the permutation P_1, P_2, ..., P_N.
    for (int i = 1; i <= n; ++i) {
        std::cout << p[i] << (i == n ? "" : " ");
    }
    std::cout << "\n";
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
```