# [Lit Up (LITUP)](https://www.codechef.com/problems/LITUP)
- **Difficulty Rating**: 1114
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to place exactly two floodlights in a line of `N` stalls, numbered 1 to `N`. Each stall `i` has an associated cost `C[i-1]` to place a floodlight there. A floodlight placed at stall `P` illuminates all stalls in the range `[max(1, P-K), min(N, P+K)]`, where `K` is a given coverage radius.

We need to find the minimum total cost to place two floodlights such that:
1. Stall 1 is covered.
2. Stall `N` is covered.
3. All stalls from 1 to `N` are covered (i.e., there are no gaps in coverage between stall 1 and stall `N`).

If it's impossible to satisfy these conditions with two floodlights, we should output -1.

## Intuition & Mathematical Observation

The problem constraints (`N` up to 100) suggest that a solution with complexity around $O(N^2)$ or $O(N^3)$ per test case would be acceptable. Since we need to place exactly two floodlights, a brute-force approach of trying all possible pairs of positions for the two floodlights seems feasible.

Let's denote the positions of the two floodlights as `i` and `j`, where `1 <= i < j <= N`. For each such pair, we need to check if the three conditions are met:

1.  **Stall 1 must be covered:**
    A floodlight at `i` covers `[max(1, i-K), min(N, i+K)]`. For stall 1 to be covered, the leftmost point of its coverage must be 1 or less. So, `i - K <= 1`, which implies `i <= K + 1`.

2.  **Stall N must be covered:**
    A floodlight at `j` covers `[max(1, j-K), min(N, j+K)]`. For stall `N` to be covered, the rightmost point of its coverage must be `N` or more. So, `j + K >= N`, which implies `j >= N - K`.

3.  **All stalls from 1 to N must be covered (no gaps):**
    The first floodlight at `i` covers up to `min(N, i+K)`. The second floodlight at `j` covers from `max(1, j-K)`. For there to be no gap, the coverage of the first light must extend to at least one stall before the coverage of the second light begins. That is, `min(N, i+K) >= max(1, j-K) - 1`.
    In the critical case where `i+K < N` and `j-K > 1`, this simplifies to `i+K >= (j-K) - 1`. Rearranging this, we get `i+K >= j-K-1`, or `j <= i + 2K + 1`. This condition ensures that the rightmost point covered by the first floodlight is adjacent to or overlaps with the leftmost point covered by the second floodlight.

**Algorithm:**
1. Initialize `min_total_cost` to a very large value (e.g., `std::numeric_limits<long long>::max()`).
2. Iterate `i` from 1 to `N` (representing the position of the first floodlight).
3. Inside this loop, iterate `j` from `i+1` to `N` (representing the position of the second floodlight, ensuring `j > i` and distinct positions).
4. For each pair `(i, j)`:
    a. Check if `i <= K + 1` (Condition 1).
    b. Check if `j >= N - K` (Condition 2).
    c. Check if `j <= i + 2 * K + 1` (Condition 3).
5. If all three conditions are true, then this pair `(i, j)` is a valid placement. Calculate the `current_cost = C[i-1] + C[j-1]` (remembering `C` is 0-indexed).
6. Update `min_total_cost = std::min(min_total_cost, current_cost)`.
7. After checking all possible pairs, if `min_total_cost` is still its initial large value, it means no valid pair was found, so output -1. Otherwise, output `min_total_cost`.

This approach systematically checks all valid configurations and finds the minimum cost.

## Complexity Analysis

-   **Time Complexity**:
    -   The outer loop iterates `N` times (for `i`).
    -   The inner loop iterates up to `N` times (for `j`).
    -   Inside the inner loop, we perform a constant number of comparisons and an addition.
    -   Thus, the total time complexity for each test case is $O(N^2)$.
    -   Given `T` test cases, the overall time complexity is $O(T \cdot N^2)$.
    -   With `N=100` and `T=100`, this is $100 \cdot 100^2 = 100 \cdot 10000 = 10^6$ operations, which is well within typical time limits.

-   **Space Complexity**:
    -   We use a `std::vector<int> C` of size `N` to store the costs. This requires $O(N)$ space.
    -   All other variables use constant space.
    -   Therefore, the total space complexity is $O(N)$.
    -   With `N=100`, this is negligible.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // Required for std::min
#include <limits>    // Required for std::numeric_limits

void solve() {
    int N, K;
    std::cin >> N >> K;
    std::vector<int> C(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> C[i];
    }

    // Initialize min_total_cost to a value larger than any possible sum of costs.
    // Max C_i is 100, so max sum is 100 + 100 = 200.
    // Using long long and numeric_limits for robustness, though int would suffice for 200.
    long long min_total_cost = std::numeric_limits<long long>::max();

    // Iterate over all possible positions for the first floodlight (1-indexed: 1 to N)
    for (int i = 1; i <= N; ++i) {
        // Iterate over all possible positions for the second floodlight (1-indexed: i+1 to N)
        // This ensures j > i, so the two stalls are distinct and ordered.
        for (int j = i + 1; j <= N; ++j) {
            // Condition 1: Stall 1 must be covered.
            // Light at 'i' covers [max(1, i-K), min(N, i+K)].
            // For stall 1 to be covered, i-K <= 1 => i <= K+1.
            bool condition1 = (i <= K + 1);

            // Condition 2: Stall N must be covered.
            // Light at 'j' covers [max(1, j-K), min(N, j+K)].
            // For stall N to be covered, j+K >= N => j >= N-K.
            bool condition2 = (j >= N - K);

            // Condition 3: No gap between the coverage of light 'i' and light 'j'.
            // The rightmost point covered by light 'i' is min(N, i+K).
            // The leftmost point covered by light 'j' is max(1, j-K).
            // We need min(N, i+K) >= max(1, j-K) - 1.
            // This simplifies to j <= i + 2*K + 1 in the critical case.
            bool condition3 = (j <= i + 2 * K + 1);

            if (condition1 && condition2 && condition3) {
                // If all conditions are met, this is a valid pair.
                // Calculate the cost (using 0-indexed C array: C[i-1] and C[j-1]).
                long long current_cost = static_cast<long long>(C[i-1]) + C[j-1];
                min_total_cost = std::min(min_total_cost, current_cost);
            }
        }
    }

    // If min_total_cost is still its initial large value, no valid pair was found.
    if (min_total_cost == std::numeric_limits<long long>::max()) {
        std::cout << -1 << "\n";
    } else {
        std::cout << min_total_cost << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases.
    while (T--) {
        solve(); // Solve each test case.
    }

    return 0;
}
```