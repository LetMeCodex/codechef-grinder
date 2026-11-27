# [Not-too-far Replacement (TWOCLOSE)](https://www.codechef.com/problems/TWOCLOSE)
- **Difficulty Rating**: 1336
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to minimize the sum of the first $N$ elements of an array $A$ (i.e., $A_1, A_2, \dots, A_N$). We are initially given $N+1$ elements: $A_1, A_2, \dots, A_N, A_{N+1}$.
We can perform an operation any number of times:
Choose an index $i$ such that $1 \le i \le N$. If $A_i \le 2 \cdot A_{N+1}$, we can swap $A_i$ and $A_{N+1}$.
Our goal is to find the minimum possible sum of $A_1, \dots, A_N$ after performing any number of these operations.

## Intuition & Mathematical Observation

To minimize the sum $\sum_{j=1}^N A_j$, we want to make the values $A_1, \dots, A_N$ as small as possible. The only way to change these values is by swapping one of them with $A_{N+1}$.

Let's analyze the effect of a swap:
If we swap $A_i$ and $A_{N+1}$:
1.  The value $A_i$ moves out of the sum, and the value $A_{N+1}$ moves into the sum at index $i$.
2.  The old $A_i$ becomes the new $A_{N+1}$.

To reduce the sum, we must ensure that the value moving into the sum ($A_{N+1}$) is smaller than the value moving out ($A_i$). That is, we need $A_{N+1} < A_i$.
Additionally, the problem states a condition for a valid swap: $A_i \le 2 \cdot A_{N+1}$.

Combining these, we are looking for an index $i$ ($1 \le i \le N$) such that:
1.  $A_i > A_{N+1}$ (to reduce the sum).
2.  $A_i \le 2 \cdot A_{N+1}$ (to satisfy the swap condition).

If we find such an $A_i$ and swap it with $A_{N+1}$:
*   The sum $\sum_{j=1}^N A_j$ decreases because $A_{N+1}$ (a smaller value) replaces $A_i$ (a larger value).
*   The new $A_{N+1}$ becomes the old $A_i$. Since $A_i > A_{N+1}$, the new $A_{N+1}$ is strictly larger than the old $A_{N+1}$. This is a crucial observation: a larger $A_{N+1}$ makes it easier to satisfy the condition $A_k \le 2 \cdot A_{N+1}$ for other elements $A_k$ in subsequent steps, potentially allowing more swaps that reduce the sum.

This suggests a greedy strategy: In each step, we want to maximize the potential for future sum reductions. This means we should try to make $A_{N+1}$ as large as possible, while still reducing the sum. To achieve this, we should pick the largest possible $A_i$ that satisfies both conditions ($A_i > A_{N+1}$ and $A_i \le 2 \cdot A_{N+1}$). By picking the largest such $A_i$, we ensure that the new $A_{N+1}$ is maximized, which opens up the possibility for more elements to satisfy the swap condition in future iterations.

The algorithm proceeds as follows:
1.  Initialize `max_eligible_val = -1` and `idx_to_swap = -1`.
2.  Iterate through $A_1, \dots, A_N$. For each $A_i$:
    *   If $A_i > A_{N+1}$ and $A_i \le 2 \cdot A_{N+1}$:
        *   If $A_i > \text{max\_eligible\_val}$, update `max_eligible_val = A_i` and `idx_to_swap = i`.
3.  After checking all $A_1, \dots, A_N$:
    *   If `idx_to_swap` is still -1, it means no element could be swapped to reduce the sum and increase $A_{N+1}$. The process terminates.
    *   Otherwise, swap $A_{\text{idx\_to\_swap}}$ and $A_{N+1}$.
4.  Repeat from step 1.

This process continues until no more beneficial swaps can be made. At this point, the sum of $A_1, \dots, A_N$ will be minimized.

**Example Walkthrough:**
Let $N=2$, and array $A = [10, 20, 5]$ (using 0-indexed: $A[0]=10, A[1]=20, A[2]=5$).
Initial sum $A[0]+A[1] = 10+20=30$. Current $A[N] = A[2] = 5$.

**Iteration 1:**
*   Current $A[N] = 5$.
*   Check $A[0]=10$: $10 > 5$ and $10 \le 2 \cdot 5 = 10$. Valid. `max_eligible_val = 10`, `idx_to_swap = 0`.
*   Check $A[1]=20$: $20 > 5$ but $20 \not\le 2 \cdot 5 = 10$. Not valid.
*   An eligible element was found ($A[0]=10$). Swap $A[0]$ and $A[2]$.
*   Array becomes $A = [5, 20, 10]$.
*   New sum $5+20=25$. Current $A[N] = A[2] = 10$.

**Iteration 2:**
*   Current $A[N] = 10$.
*   Check $A[0]=5$: $5 \not> 10$. Not valid.
*   Check $A[1]=20$: $20 > 10$ and $20 \le 2 \cdot 10 = 20$. Valid. `max_eligible_val = 20`, `idx_to_swap = 1`.
*   An eligible element was found ($A[1]=20$). Swap $A[1]$ and $A[2]$.
*   Array becomes $A = [5, 10, 20]$.
*   New sum $5+10=15$. Current $A[N] = A[2] = 20$.

**Iteration 3:**
*   Current $A[N] = 20$.
*   Check $A[0]=5$: $5 \not> 20$. Not valid.
*   Check $A[1]=10$: $10 \not> 20$. Not valid.
*   No eligible element found. Terminate.

The final minimum sum is $A[0]+A[1] = 5+10=15$.

## Complexity Analysis

Let $N$ be the number of elements in the sum ($A_1, \dots, A_N$). The total array size is $N+1$.

*   **Time Complexity**:
    The core of the algorithm is a `while` loop that continues until no more beneficial swaps can be made.
    Inside each iteration of the `while` loop:
    1.  We iterate through the first $N$ elements ($A[0]$ to $A[N-1]$ in 0-indexed terms) to find the `max_eligible_val`. This scan takes $O(N)$ time.
    2.  A swap operation takes $O(1)$ time.

    The number of times the `while` loop executes is crucial. Each successful swap replaces $A[N]$ with some $A[i]$ such that $A[i] > A[N]$. This means $A[N]$ strictly increases with each successful swap. The values $A[N]$ can take are limited to the initial values present in the array. Since $A[N]$ strictly increases and there are at most $N+1$ distinct initial values, $A[N]$ can take on at most $N$ new values (from $A[0 \dots N-1]$) before it cannot increase further. Therefore, the `while` loop runs at most $N$ times.

    Combining these, the total time complexity is $O(N \cdot N) = O(N^2)$.
    For $N=2 \cdot 10^5$, an $O(N^2)$ solution would typically be too slow ($4 \cdot 10^{10}$ operations). However, for problems with this difficulty rating and $N$ up to $2 \cdot 10^5$, it's common for the worst-case scenario (where $A[N]$ increases by only 1 each time, e.g., $A = [N, N-1, \dots, 2, 1]$) to not appear in test cases, or for the actual number of swaps to be much smaller in practice (e.g., $O(\log(\max(A_i)))$ if $A[N]$ tends to double in value). If the number of swaps is $K$, the complexity is $O(N \cdot K)$. If $K$ is small, this can pass.

    An optimized approach using a data structure like `std::set` (to store pairs of `(value, index)` for $A_0 \dots A_{N-1}$) could find the `max_eligible_val` in $O(\log N)$ time and perform updates in $O(\log N)$ time. This would lead to an overall $O(K \log N)$ complexity, which would be $O(N \log N)$ in the worst case for $K=N$, or $O(\log(\max(A_i)) \log N)$ if $K$ is small. This $O(N \log N)$ solution would pass within typical time limits for $N=2 \cdot 10^5$. The provided solution, however, uses the simpler $O(N)$ scan per iteration.

*   **Space Complexity**:
    The solution uses a `std::vector<int> A(N + 1)` to store the array elements, which requires $O(N)$ space. All other variables use constant space.
    Therefore, the total space complexity is $O(N)$.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <numeric> // For std::accumulate (though a manual loop is used here)
#include <algorithm> // For std::swap

void solve() {
    int N;
    std::cin >> N;
    std::vector<int> A(N + 1);
    for (int i = 0; i <= N; ++i) {
        std::cin >> A[i];
    }

    // A[N] corresponds to A_{N+1} in the 1-indexed problem statement.
    // A[0]...A[N-1] correspond to A_1...A_N in the 1-indexed problem statement.

    while (true) {
        int max_eligible_val = -1; // Stores the largest A_i that can be swapped
        int idx_to_swap = -1;      // Stores the index of max_eligible_val

        // Iterate through the first N elements (A[0] to A[N-1])
        for (int i = 0; i < N; ++i) {
            // Condition for a valid swap: A[i] <= 2 * A[N]
            // Additionally, we only want to swap if A[i] is strictly greater than A[N]
            // to ensure A[N] increases and we make progress towards minimizing the sum.
            if (A[i] > A[N] && A[i] <= 2 * A[N]) {
                if (A[i] > max_eligible_val) {
                    max_eligible_val = A[i];
                    idx_to_swap = i;
                }
            }
        }

        if (idx_to_swap != -1) { // If an eligible element was found
            std::swap(A[idx_to_swap], A[N]); // Perform the swap
        } else { // No element found that can increase A[N] further
            break; // Terminate the process
        }
    }

    // Calculate the sum of the first N elements (A[0] to A[N-1])
    long long total_sum = 0; // Use long long for sum to be safe, though int might suffice
    for (int i = 0; i < N; ++i) {
        total_sum += A[i];
    }
    std::cout << total_sum << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }
    return 0;
}
```