# [Fair Elections (FAIRELCT)](https://www.codechef.com/problems/FAIRELCT)
- **Difficulty Rating**: -1
- **Solved in**: 2 attempt(s)

## Problem Summary

The problem describes a scenario with two candidates, John Jackson and Jack, who possess `N` and `M` vote packs, respectively. Each pack contains a certain number of votes. John Jackson's objective is to achieve a total vote count strictly greater than Jack's. They can perform an operation: swap one of John's vote packs with one of Jack's vote packs. Each such swap costs 1. The task is to find the minimum number of swaps required for John Jackson to win, or output -1 if it's impossible.

## Intuition & Mathematical Observation

The core idea is to maximize John Jackson's total votes (`sumA`) while simultaneously minimizing Jack's total votes (`sumB`) with each swap. We want to reach a state where `sumA > sumB` using the fewest possible swaps.

Consider the effect of swapping one of John's packs, say `A_i`, with one of Jack's packs, `B_j`:
*   John's total votes (`sumA`) change by `B_j - A_i`.
*   Jack's total votes (`sumB`) change by `A_i - B_j`.
*   The difference `sumA - sumB` changes by `(B_j - A_i) - (A_i - B_j) = 2 * (B_j - A_i)`.

To make `sumA` increase as much as possible relative to `sumB` (i.e., maximize `sumA - sumB`), we need to maximize the value `B_j - A_i`. This implies a greedy strategy:
1.  **For `A_i` (John's pack)**: To maximize `B_j - A_i`, we should choose the smallest possible `A_i` from John's available packs. This is because a smaller `A_i` contributes less negatively to the change.
2.  **For `B_j` (Jack's pack)**: To maximize `B_j - A_i`, we should choose the largest possible `B_j` from Jack's available packs. This is because a larger `B_j` contributes more positively to the change.

Based on this, the optimal greedy strategy is:
1.  Sort John's vote packs (`A`) in **ascending** order. This allows us to easily pick the smallest available pack.
2.  Sort Jack's vote packs (`B`) in **descending** order. This allows us to easily pick the largest available pack.
3.  Iterate, performing swaps: In each step, swap the current smallest pack from `A` (let's say `A[i]`) with the current largest pack from `B` (let's say `B[i]`).
4.  **Condition for a beneficial swap**: A swap is only beneficial if `A[i] < B[i]`. If `A[i] >= B[i]`, then swapping them would either not improve John's position (`B_j - A_i <= 0`) or even worsen it. Furthermore, since `A` is sorted ascending and `B` is sorted descending, if `A[i] >= B[i]`, then for any `k > i`, `A[k] >= A[i]` and `B[k] <= B[i]`. This implies `A[k] >= B[k]` for all subsequent pairs, meaning no further beneficial swaps are possible. So, we can stop if this condition is met.
5.  After each swap, update `sumA` and `sumB` and check if `sumA > sumB`. If it is, we have found the minimum number of swaps because we always made the most efficient swap possible at each step.
6.  The maximum number of swaps possible is `min(N, M)`, as each swap consumes one pack from `A` and one from `B`.

**Edge Cases:**
*   If `sumA > sumB` initially, no swaps are needed, so output 0.
*   If after trying all possible beneficial swaps (up to `min(N, M)` swaps), `sumA` is still not strictly greater than `sumB`, then it's impossible to make John Jackson win, so output -1.

## Complexity Analysis

*   **Time Complexity**:
    *   Reading inputs `N`, `M`, and the elements of vectors `A` and `B`: $O(N + M)$.
    *   Calculating initial `sumA` and `sumB`: $O(N + M)$.
    *   Sorting vector `A`: $O(N \log N)$.
    *   Sorting vector `B`: $O(M \log M)$.
    *   The swapping loop runs at most `min(N, M)` times. Inside the loop, operations are constant time. So, $O(\min(N, M))$.
    *   The dominant operations are the sorting steps.
    *   Therefore, the total time complexity is $O(N \log N + M \log M)$.

*   **Space Complexity**:
    *   Storing vector `A`: $O(N)$ space.
    *   Storing vector `B`: $O(M)$ space.
    *   Other variables (`sumA`, `sumB`, `swaps`, `N`, `M`, loop counters) use $O(1)$ space.
    *   Therefore, the total space complexity is $O(N + M)$.

## Solution Code

```cpp
#include <iostream> // For std::cin, std::cout
#include <vector>   // For std::vector
#include <numeric>  // For std::accumulate (though not strictly used, sum is manual)
#include <algorithm> // For std::sort, std::min
#include <functional> // For std::greater

// Function to solve a single test case
void solve() {
    int N, M;
    std::cin >> N >> M;

    // Use int for A and B elements as their values (up to 10^6) fit in int.
    // Sums can exceed int max (2*10^9), so sumA and sumB must be long long.
    std::vector<int> A(N);
    std::vector<int> B(M);
    long long sumA = 0;
    long long sumB = 0;

    // Read A packs and calculate initial sumA
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
        sumA += A[i];
    }

    // Read B packs and calculate initial sumB
    for (int i = 0; i < M; ++i) {
        std::cin >> B[i];
        sumB += B[i];
    }

    // Sort A in ascending order to easily pick the smallest packs
    std::sort(A.begin(), A.end());
    // Sort B in descending order to easily pick the largest packs
    std::sort(B.begin(), B.end(), std::greater<int>());

    int swaps = 0;
    
    // If John Jackson already has strictly more votes, no swaps needed.
    if (sumA > sumB) {
        std::cout << 0 << "\n";
        return;
    }

    // Iterate through possible swaps. We can perform at most min(N, M) swaps
    // because each swap uses one pack from A and one from B.
    int limit = std::min(N, M); 

    for (int i = 0; i < limit; ++i) {
        // The greedy strategy: swap the smallest pack from A (A[i])
        // with the largest pack from B (B[i]).
        // This swap is beneficial only if A[i] < B[i].
        if (A[i] < B[i]) {
            // Update sums after swapping A[i] and B[i]
            // A[i] moves from John's side to Jack's side (sumA decreases by A[i], sumB increases by A[i])
            // B[i] moves from Jack's side to John's side (sumA increases by B[i], sumB decreases by B[i])
            // Net effect on sumA: -A[i] + B[i]
            // Net effect on sumB: -B[i] + A[i]
            sumA = sumA - A[i] + B[i];
            sumB = sumB - B[i] + A[i];
            swaps++;

            // Check if John Jackson wins after this swap
            if (sumA > sumB) {
                std::cout << swaps << "\n";
                return;
            }
        } else {
            // If A[i] >= B[i], then swapping A[i] with B[i] would not increase
            // John's votes more than it decreases Jack's (or would be detrimental).
            // Since A is sorted ascending and B descending, any subsequent A[j] (j > i)
            // will be >= A[i], and any subsequent B[j] (j > i) will be <= B[i].
            // Thus, A[j] >= B[j] will hold for all j > i.
            // No further beneficial swaps are possible.
            break;
        }
    }

    // If the loop finishes and John Jackson still doesn't have strictly more votes,
    // it's impossible to make him win.
    std::cout << -1 << "\n";
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