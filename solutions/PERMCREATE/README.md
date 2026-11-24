# [Permutation Creation (PERMCREATE)](https://www.codechef.com/problems/PERMCREATE)
- **Difficulty Rating**: 1323
- **Solved in**: 2 attempt(s)

## Problem Summary

Given an integer $N$, we need to construct a permutation $P$ of numbers from $1$ to $N$ such that for all $1 \le i < N$, the absolute difference $|P_i - P_{i+1}|$ is at least $2$. If no such permutation exists, we should output $-1$.

## Intuition & Mathematical Observation

The core constraint is that adjacent elements in the permutation must have an absolute difference of at least $2$. This means we cannot have consecutive numbers like $(1, 2)$, $(2, 1)$, $(2, 3)$, $(3, 2)$, and so on.

Let's consider small values of $N$:

*   **N = 1**: The permutation is `[1]`. There are no adjacent elements, so the condition is vacuously true. However, the problem statement implies $N \ge 2$ for the condition to be meaningful. If $N=1$ were allowed, `[1]` would be a valid output. The constraints usually clarify this, but assuming $N \ge 2$.

*   **N = 2**: Possible permutations are `[1, 2]` and `[2, 1]`.
    *   For `[1, 2]`, $|1 - 2| = 1$, which is less than $2$.
    *   For `[2, 1]`, $|2 - 1| = 1$, which is less than $2$.
    No valid permutation exists for $N=2$.

*   **N = 3**: Possible permutations are `[1, 2, 3]`, `[1, 3, 2]`, `[2, 1, 3]`, `[2, 3, 1]`, `[3, 1, 2]`, `[3, 2, 1]`.
    Let's check the differences:
    *   `[1, 2, 3]`: $|1-2|=1$ (fails)
    *   `[1, 3, 2]`: $|3-2|=1$ (fails)
    *   `[2, 1, 3]`: $|2-1|=1$ (fails)
    *   `[2, 3, 1]`: $|2-3|=1$ (fails)
    *   `[3, 1, 2]`: $|3-1|=2$, $|1-2|=1$ (fails)
    *   `[3, 2, 1]`: $|3-2|=1$ (fails)
    No valid permutation exists for $N=3$.

*   **N = 4**:
    Let's try to construct one. If we place small numbers together, we run into issues. For example, `[1, 3, 2, 4]` has $|3-2|=1$.
    Consider placing even numbers and odd numbers separately.
    If we try `[2, 4, 1, 3]`:
    *   $|2 - 4| = 2 \ge 2$
    *   $|4 - 1| = 3 \ge 2$
    *   $|1 - 3| = 2 \ge 2$
    This permutation works for $N=4$.

*   **N = 5**:
    Let's try the strategy of placing evens then odds.
    Evens: `[2, 4]`
    Odds: `[1, 3, 5]`
    If we arrange them as `[2, 4, 1, 3, 5]`:
    *   $|2 - 4| = 2 \ge 2$
    *   $|4 - 1| = 3 \ge 2$
    *   $|1 - 3| = 2 \ge 2$
    *   $|3 - 5| = 2 \ge 2$
    This works.

    What if we try descending order for evens and odds?
    Evens: `[4, 2]`
    Odds: `[5, 3, 1]`
    Permutation: `[4, 2, 5, 3, 1]`
    *   $|4 - 2| = 2 \ge 2$
    *   $|2 - 5| = 3 \ge 2$
    *   $|5 - 3| = 2 \ge 2$
    *   $|3 - 1| = 2 \ge 2$
    This also works.

The observation from $N=4$ and $N=5$ suggests a general strategy: **print all even numbers in descending order, followed by all odd numbers in descending order.**

Let's analyze this strategy for $N \ge 5$:

The permutation will look like:
`[N (if even), N-2, ..., 2, N-1 (if odd), N-3, ..., 1]`

Consider the differences:

1.  **Adjacent even numbers**: If we have two consecutive even numbers $e_1$ and $e_2$ in the sequence (e.g., $4, 2$), their difference will be $|e_1 - e_2| = |(2k) - (2(k-1))| = |2k - 2k + 2| = 2$. This is always $\ge 2$.

2.  **Adjacent odd numbers**: Similarly, if we have two consecutive odd numbers $o_1$ and $o_2$ (e.g., $5, 3$), their difference will be $|o_1 - o_2| = |(2k+1) - (2(k-1)+1)| = |2k+1 - (2k-1)| = |2k+1 - 2k + 1| = 2$. This is always $\ge 2$.

3.  **The transition from the last even number to the first odd number**:
    *   The last even number printed will always be $2$.
    *   The first odd number printed depends on the parity of $N$:
        *   If $N$ is even, the odd numbers start from $N-1$. The difference is $|2 - (N-1)| = |3 - N|$. Since $N \ge 5$, $N-3 \ge 2$, so $|3-N| = N-3 \ge 2$.
        *   If $N$ is odd, the odd numbers start from $N$. The difference is $|2 - N|$. Since $N \ge 5$, $N-2 \ge 3$, so $|2-N| = N-2 \ge 3 \ge 2$.

In all cases for $N \ge 5$, the difference at the transition point is also $\ge 2$.

Therefore, the strategy of printing even numbers in descending order, followed by odd numbers in descending order, works for all $N \ge 5$.

**Summary of findings:**
*   $N=2$: No solution (-1)
*   $N=3$: No solution (-1)
*   $N=4$: Special case, `[2, 4, 1, 3]`
*   $N \ge 5$: General strategy: evens descending, then odds descending.

The code implements this logic. For $N=4$, it uses the hardcoded `[2, 4, 1, 3]` because the general strategy `[4, 2, 3, 1]` would have $|2-3|=1$, failing the condition.

Let's re-check the general strategy for $N=4$:
Evens: `[4, 2]`
Odds: `[3, 1]`
Concatenated: `[4, 2, 3, 1]`
Differences: $|4-2|=2$, $|2-3|=1$ (FAILS).
This confirms why $N=4$ is a special case.

The code's general strategy for $N \ge 5$:
*   Prints even numbers from `(n % 2 == 0 ? n : n - 1)` down to $2$.
*   Prints odd numbers from `(n % 2 == 0 ? n - 1 : n)` down to $1$.

This correctly generates the sequence. For example, if $N=5$:
*   Evens: `(5 % 2 == 0 ? 5 : 5 - 1)` which is $4$. So, `4` down to $2$. Prints `4 2`.
*   Odds: `(5 % 2 == 0 ? 5 - 1 : 5)` which is $5$. So, `5` down to $1$. Prints `5 3 1`.
Combined: `4 2 5 3 1`. This matches our manual check.

If $N=6$:
*   Evens: `(6 % 2 == 0 ? 6 : 6 - 1)` which is $6$. So, `6` down to $2$. Prints `6 4 2`.
*   Odds: `(6 % 2 == 0 ? 6 - 1 : 6)` which is $5$. So, `5` down to $1$. Prints `5 3 1`.
Combined: `6 4 2 5 3 1`.
Differences: $|6-4|=2$, $|4-2|=2$, $|2-5|=3$, $|5-3|=2$, $|3-1|=2$. All $\ge 2$. This works.

The logic seems sound.

## Complexity Analysis

*   **Time Complexity**: $O(N)$
    For each test case, we iterate through the numbers from $N$ down to $1$ to print the permutation. This involves two loops, each iterating at most $N/2$ times. Thus, the time complexity per test case is linear with respect to $N$. If $T$ is the number of test cases, the total time complexity is $O(T \cdot N)$.

*   **Space Complexity**: $O(1)$
    We are not using any auxiliary data structures that grow with the input size $N$. We only use a few variables to store $N$, the loop counters, and the number of test cases. Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>

int main() {
    // Optimize C++ standard streams for competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        int n;
        std::cin >> n; // Read N for the current test case

        if (n == 2 || n == 3) {
            // It can be proven that no such permutation exists for N=2 or N=3.
            std::cout << "-1\n";
        } else if (n == 4) {
            // Special case for N=4. The general strategy (evens then odds) fails.
            // A valid permutation for N=4 is [2, 4, 1, 3].
            // Differences: |4-2|=2, |1-4|=3, |3-1|=2. All are >= 2.
            std::cout << "2 4 1 3\n";
        } else {
            // General strategy for N >= 5:
            // Print all even numbers in descending order, then all odd numbers in descending order.
            // This ensures that:
            // 1. Adjacent evens (e.g., 6, 4) have a difference of 2.
            // 2. Adjacent odds (e.g., 5, 3) have a difference of 2.
            // 3. The transition from the last even number (which is 2) to the first odd number:
            //    - If N is odd (e.g., N=5), first odd is N=5. Difference |5-2|=3 >= 2.
            //    - If N is even (e.g., N=6), first odd is N-1=5. Difference |5-2|=3 >= 2.
            // In both cases for N >= 5, the difference is >= 2.

            // Print even numbers in descending order
            // Start from N if N is even, or N-1 if N is odd.
            for (int i = (n % 2 == 0 ? n : n - 1); i >= 2; i -= 2) {
                std::cout << i << " ";
            }

            // Print odd numbers in descending order
            // Start from N-1 if N is even, or N if N is odd.
            for (int i = (n % 2 == 0 ? n - 1 : n); i >= 1; i -= 2) {
                std::cout << i << (i == 1 ? "" : " "); // No trailing space after the last number
            }
            std::cout << "\n"; // Newline after each test case output
        }
    }
    return 0;
}
```