# [Distribute Apples (DSTAPLS)](https://www.codechef.com/problems/DSTAPLS)
- **Difficulty Rating**: 1374
- **Solved in**: 1 attempt(s)

## Problem Summary

We are given `N` apples and `K` boxes. Two candidates distribute apples into these boxes, with any remaining apples (after the distribution logic) being discarded.

1.  **Candidate 1:** Distributes `N` apples *evenly* among `K` boxes. This means each box receives `N/K` apples.
2.  **Candidate 2:** Performs `N/K` operations. In each operation, they put `K` apples into a box that currently has the *minimum* number of apples.

The task is to determine if it's possible for the final distribution of apples among the `K` boxes to be *different* for the two candidates. If it's possible, print "YES"; otherwise, print "NO".

## Intuition & Mathematical Observation

Let's analyze how each candidate distributes apples:

1.  **Candidate 1's Distribution:**
    Candidate 1 always distributes apples uniformly. Each of the `K` boxes will contain exactly `N/K` apples. The total apples distributed will be `(N/K) * K`. This distribution is always `[N/K, N/K, ..., N/K]` (K times).

2.  **Candidate 2's Distribution:**
    Candidate 2 performs `N/K` operations. Let `Q = N/K`. So, `Q` operations are performed. In each operation, `K` apples are added to the box with the minimum apples. This strategy aims to keep the distribution as balanced as possible.
    Effectively, Candidate 2 is distributing `Q` "chunks" of `K` apples among `K` boxes.

    Consider how `Q` items (chunks) would be distributed among `K` containers to keep them as balanced as possible:
    *   Each box will receive at least `Q/K` chunks.
    *   `Q % K` boxes will receive an additional chunk (making it `Q/K + 1` chunks).
    *   The remaining `K - (Q % K)` boxes will receive `Q/K` chunks.

    Since each chunk consists of `K` apples:
    *   `Q % K` boxes will contain `(Q/K + 1) * K` apples.
    *   `K - (Q % K)` boxes will contain `(Q/K) * K` apples.

Now, we need to determine when these two distributions can be *different*. Candidate 1's distribution is always uniform. So, the distributions will be different if and only if Candidate 2's distribution is *not* uniform.

Candidate 2's distribution is uniform if and only if all boxes receive the same number of chunks. This happens when `Q % K == 0`.

*   **Case 1: `Q % K == 0`**
    If `Q % K == 0`, then all `K` boxes receive `Q/K` chunks.
    Each box will contain `(Q/K) * K` apples.
    Since `Q = N/K`, substituting this into the expression gives: `((N/K) / K) * K = N/K` apples per box.
    This is exactly the same as Candidate 1's distribution.
    Therefore, if `(N/K) % K == 0`, the distributions are always the same. We should print "NO".

*   **Case 2: `Q % K != 0`**
    If `Q % K != 0`, then some boxes will contain `(Q/K + 1) * K` apples, and others will contain `(Q/K) * K` apples.
    Since `Q % K != 0`, `Q/K + 1` is strictly greater than `Q/K`. This means the number of apples in the boxes will not be uniform.
    As Candidate 1's distribution is always uniform, Candidate 2's non-uniform distribution will be different from Candidate 1's.
    Therefore, if `(N/K) % K != 0`, the distributions can be different. We should print "YES".

**Conclusion:** The distributions can be different if and only if `(N/K) % K != 0`.

## Complexity Analysis

*   **Time Complexity**: For each test case, we perform a few arithmetic operations (division and modulo). These operations take constant time. If there are `T` test cases, the total time complexity will be $O(T)$.
*   **Space Complexity**: We only use a few variables to store `T`, `N`, `K`, and `Q`. This requires a constant amount of memory, so the space complexity is $O(1)$.

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
        long long N, K;
        std::cin >> N >> K; // Read N and K for each test case.

        // Candidate 1: Distributes N apples evenly among K boxes.
        // Each box will end up with N/K apples.
        // This is a uniform distribution: [N/K, N/K, ..., N/K] (K times).

        // Candidate 2: Performs N/K operations. In each operation, puts K apples
        // into a box that currently has the minimum number of apples.
        // Let Q be the total number of operations, Q = N/K.
        // Candidate 2 effectively distributes Q "chunks" of K apples among K boxes.
        // To keep the distribution as balanced as possible, Candidate 2 will ensure:
        // - (Q % K) boxes receive (Q / K + 1) chunks, meaning (Q / K + 1) * K apples.
        // - (K - Q % K) boxes receive (Q / K) chunks, meaning (Q / K) * K apples.

        // The distributions are different if Candidate 2's distribution is not uniform.
        // Candidate 2's distribution is uniform if and only if Q % K == 0.
        // If Q % K == 0:
        //   All boxes for Candidate 2 will have (Q / K) * K = Q apples.
        //   Since Q = N/K, this means all boxes have N/K apples, which is identical to Candidate 1's distribution.
        //   In this case, the distributions are the same.
        // If Q % K != 0:
        //   Candidate 2's distribution will involve at least two different apple counts
        //   ((Q / K + 1) * K and (Q / K) * K). This is a non-uniform distribution.
        //   Since Candidate 1 always produces a uniform distribution, these two distributions will be different.
        //   In this case, the distributions are different.

        long long Q = N / K; // Calculate the number of K-apple chunks.

        if (Q % K == 0) {
            std::cout << "NO\n"; // Distributions are the same.
        } else {
            std::cout << "YES\n"; // Distributions can be different.
        }
    }
    return 0;
}
```