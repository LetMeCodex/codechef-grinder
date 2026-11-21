# [Distinct Opposite Sums (DISTOPPSUMS)](https://www.codechef.com/problems/DISTOPPSUMS)
- **Difficulty Rating**: 1135
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to construct a permutation `P` of length `N` (where `N` is an even integer) using numbers from `1` to `N`. The permutation must satisfy a specific condition: all `N/2` sums of opposite elements, i.e., `P[i] + P[N-1-i]` for `0 <= i < N/2`, must be distinct. We need to output any such valid permutation.

## Intuition & Mathematical Observation

The core idea is to strategically pair small numbers with large numbers to control the resulting sums `P[i] + P[N-1-i]`. Since `N` is always even, we can categorize `N` into two cases based on its remainder when divided by 4: `N % 4 == 0` or `N % 4 == 2`. These two cases require slightly different constructions to ensure distinct sums.

Let's denote the `k`-th sum as $S_k = P[k] + P[N-1-k]$ for $0 \le k < N/2$. We need all $S_k$ to be distinct.

### Case 1: `N % 4 == 0`

In this case, we can assign the smallest `N/2` numbers (`1` to `N/2`) to the first `N/2` positions in reverse order, and the largest `N/2` numbers (`N/2 + 1` to `N`) to the last `N/2` positions, also in reverse order.

Specifically, for `0 <= i < N/2`:
*   `P[i] = N/2 - i`
*   `P[N-1-i] = N - i`

Let's verify this construction:
1.  **Permutation Validity**:
    *   `P[i]` takes values: `N/2, N/2-1, ..., 1`. These are the numbers from `1` to `N/2`.
    *   `P[N-1-i]` takes values: `N, N-1, ..., N/2+1`. These are the numbers from `N/2+1` to `N`.
    Since these two sets of values are disjoint and cover all numbers from `1` to `N` exactly once, `P` is a valid permutation.

2.  **Distinct Sums**:
    The sum for index `i` is $S_i = P[i] + P[N-1-i] = (N/2 - i) + (N - i) = 3N/2 - 2i$.
    As `i` ranges from `0` to `N/2 - 1`:
    *   For `i=0`, $S_0 = 3N/2$.
    *   For `i=1`, $S_1 = 3N/2 - 2$.
    *   ...
    *   For `i=N/2 - 1`, $S_{N/2-1} = 3N/2 - 2(N/2 - 1) = 3N/2 - N + 2 = N/2 + 2$.
    The sums generated are $3N/2, 3N/2 - 2, ..., N/2 + 2$. These are `N/2` distinct values, decreasing by 2. Thus, all sums are distinct.

    **Example (N=4):**
    `i=0: P[0] = 4/2 - 0 = 2, P[3] = 4 - 0 = 4`. Sum $S_0 = 2+4=6$.
    `i=1: P[1] = 4/2 - 1 = 1, P[2] = 4 - 1 = 3`. Sum $S_1 = 1+3=4$.
    Permutation: `[2, 1, 3, 4]`. Sums: `6, 4` (distinct).

### Case 2: `N % 4 == 2`

For this case, we use a different pattern. We assign numbers `1` to `N/2` to the even indices and numbers `N/2+1` to `N` to the odd indices.

Specifically, for `0 <= i < N`:
*   If `i` is even: `P[i] = i/2 + 1`
*   If `i` is odd: `P[i] = N - (i-1)/2`

Let's verify this construction:
1.  **Permutation Validity**:
    *   For even `i` (`0, 2, ..., N-2`): `P[i]` takes values `1, 2, ..., N/2`.
    *   For odd `i` (`1, 3, ..., N-1`): `P[i]` takes values `N, N-1, ..., N - (N-1-1)/2 = N - (N/2 - 1) = N/2 + 1`.
    Again, these two sets of values are disjoint and cover all numbers from `1` to `N` exactly once, so `P` is a valid permutation.

2.  **Distinct Sums**:
    We need to consider the parity of `k` for the sum $S_k = P[k] + P[N-1-k]$.
    *   **If `k` is even**:
        *   `P[k] = k/2 + 1` (since `k` is even).
        *   `N-1-k` is odd (since `N` is even, `N-1` is odd; `odd - even = odd`).
        *   `P[N-1-k] = N - ((N-1-k)-1)/2 = N - (N-k-2)/2 = N - N/2 + k/2 + 1 = N/2 + k/2 + 1`.
        *   Sum $S_k = (k/2 + 1) + (N/2 + k/2 + 1) = N/2 + k + 2$.
        For even `k` (`0, 2, ..., N/2 - 2`): these sums are $N/2+2, N/2+4, ..., N$. These are distinct and increase by 2.

    *   **If `k` is odd**:
        *   `P[k] = N - (k-1)/2` (since `k` is odd).
        *   `N-1-k` is even (since `N` is even, `N-1` is odd; `odd - odd = even`).
        *   `P[N-1-k] = (N-1-k)/2 + 1`.
        *   Sum $S_k = (N - (k-1)/2) + ((N-1-k)/2 + 1) = N - k/2 + 1/2 + N/2 - k/2 - 1/2 + 1 = 3N/2 - k + 1$.
        For odd `k` (`1, 3, ..., N/2 - 1`): these sums are $3N/2, 3N/2-2, ..., N+2$. These are distinct and decrease by 2.

    **Combining the sums**:
    *   Sums for even `k`: $[N/2+2, N]$ (all even numbers in this range).
    *   Sums for odd `k`: $[N+2, 3N/2]$ (all even numbers in this range).
    The maximum sum from the first set is `N`. The minimum sum from the second set is `N+2`. Since these ranges are disjoint, all `N/2` sums are distinct.

    **Example (N=6):**
    `i=0 (even): P[0] = 0/2 + 1 = 1`
    `i=1 (odd): P[1] = 6 - (1-1)/2 = 6`
    `i=2 (even): P[2] = 2/2 + 1 = 2`
    `i=3 (odd): P[3] = 6 - (3-1)/2 = 5`
    `i=4 (even): P[4] = 4/2 + 1 = 3`
    `i=5 (odd): P[5] = 6 - (5-1)/2 = 4`
    Permutation: `[1, 6, 2, 5, 3, 4]`

    Sums:
    `k=0 (even): S_0 = P[0] + P[5] = 1 + 4 = 5`. (Formula: $N/2+0+2 = 3+2=5$)
    `k=1 (odd): S_1 = P[1] + P[4] = 6 + 3 = 9`. (Formula: $3N/2-1+1 = 9-1+1=9$)
    `k=2 (even): S_2 = P[2] + P[3] = 2 + 5 = 7`. (Formula: $N/2+2+2 = 3+4=7$)
    Sums: `5, 9, 7` (distinct).

Both constructions provide a valid permutation with distinct opposite sums.

## Complexity Analysis

Let `N` be the size of the permutation.

-   **Time Complexity**:
    *   Reading input `N`: $O(1)$.
    *   Initializing `std::vector<int> p(n)`: $O(N)$.
    *   The loop to fill the permutation `p`: This loop runs either `N/2` times (for `N % 4 == 0`) or `N` times (for `N % 4 == 2`). In both cases, it's $O(N)$.
    *   The loop to print the permutation `p`: This loop runs `N` times, so it's $O(N)$.
    *   For each test case, the time complexity is $O(N)$.
    *   The problem states that the sum of `N` over all test cases does not exceed $2 \cdot 10^5$. Therefore, the total time complexity across all test cases is $O(\sum N)$, which is efficient enough for the given constraints.

-   **Space Complexity**:
    *   The `std::vector<int> p` stores `N` integers. This requires $O(N)$ space.
    *   Since the vector is reallocated for each test case, the maximum space used at any point is proportional to the maximum `N` in any single test case.
    *   Thus, the space complexity is $O(N)$.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <numeric> // Not strictly needed for this solution, but often useful
#include <algorithm> // Not strictly needed for this solution, but often useful

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> p(n);

    if (n % 4 == 0) {
        // Construction for N % 4 == 0
        // For 0-indexed array P:
        // P[i] = N/2 - i for 0 <= i < N/2
        // P[N-1-i] = N - i for 0 <= i < N/2
        // This pairs (N/2, N), (N/2-1, N-1), ..., (1, N/2+1)
        // Example N=4:
        // i=0: P[0] = 2, P[3] = 4
        // i=1: P[1] = 1, P[2] = 3
        // Result: [2, 1, 3, 4]
        for (int i = 0; i < n / 2; ++i) {
            p[i] = n / 2 - i;         // Assigns N/2, N/2-1, ..., 1 to P[0]...P[N/2-1]
            p[n - 1 - i] = n - i;     // Assigns N, N-1, ..., N/2+1 to P[N-1]...P[N/2]
        }
    } else { // n % 4 == 2
        // Construction for N % 4 == 2
        // For 0-indexed array P:
        // P[i] = i/2 + 1 if i is even
        // P[i] = N - (i-1)/2 if i is odd
        // Example N=6:
        // i=0 (even): P[0]=1
        // i=1 (odd): P[1]=6
        // i=2 (even): P[2]=2
        // i=3 (odd): P[3]=5
        // i=4 (even): P[4]=3
        // i=5 (odd): P[5]=4
        // Result: [1, 6, 2, 5, 3, 4]
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) { // Even index
                p[i] = i / 2 + 1;
            } else { // Odd index
                p[i] = n - (i - 1) / 2;
            }
        }
    }

    // Output the permutation
    for (int i = 0; i < n; ++i) {
        std::cout << p[i] << (i == n - 1 ? "" : " ");
    }
    std::cout << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }
    return 0;
}
```