# [GAME 11 (GAME_XI)](https://www.codechef.com/problems/GAME_XI)
- **Difficulty Rating**: 1353
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to form a cricket team of exactly 11 players. We are given `N` available batsmen with their individual skill values and `M` available bowlers with their individual skill values. The team formation must adhere to two rules:
1.  The team must consist of exactly 11 players in total.
2.  The team must have at least 4 batsmen and at least 4 bowlers.

Our objective is to select 11 players (a combination of batsmen and bowlers) such that the sum of their individual skill values is maximized. We need to output this maximum possible total skill.

## Intuition & Mathematical Observation

To maximize the total skill of the team, we should always pick the most skilled players available for each role. This leads to a greedy approach:

1.  **Sort Skills**: If we need to select `k` batsmen, we should always choose the `k` batsmen with the highest skill values. The same logic applies to bowlers. Therefore, the first step is to sort both the batsmen's skill values and the bowlers' skill values in **descending order**. This allows us to easily access the top `k` players by simply taking the first `k` elements from the sorted list.

2.  **Prefix Sums for Efficient Summation**: After sorting, we might need to calculate the sum of the top `k` skills multiple times for different `k`. A naive summation each time would be inefficient. To optimize this, we can use **prefix sums**.
    *   Create a `pref_A` array where `pref_A[i]` stores the sum of the top `i` batsmen's skills.
    *   Similarly, create a `pref_B` array where `pref_B[i]` stores the sum of the top `i` bowlers' skills.
    With prefix sums, the sum of the top `k` skills can be retrieved in $O(1)$ time after an initial $O(N)$ or $O(M)$ precomputation.

3.  **Iterate Through Valid Combinations**: We need to select exactly 11 players, with at least 4 batsmen and at least 4 bowlers. Let `num_batsmen` be the number of batsmen selected and `num_bowlers` be the number of bowlers selected.
    *   The total number of players must be 11: `num_batsmen + num_bowlers = 11`.
    *   Minimum batsmen: `num_batsmen >= 4`.
    *   Minimum bowlers: `num_bowlers >= 4`.

    From these conditions, we can determine the possible range for `num_batsmen`:
    *   Since `num_bowlers >= 4`, it implies `num_batsmen = 11 - num_bowlers <= 11 - 4 = 7`.
    *   Combining with `num_batsmen >= 4`, the possible values for `num_batsmen` are 4, 5, 6, and 7.

    We can iterate through each of these possible `num_batsmen` values:
    *   For each `num_batsmen`, calculate the required `num_bowlers = 11 - num_batsmen`.
    *   Check if we have enough available players of each type: `N >= num_batsmen` and `M >= num_bowlers`. If not, this combination is impossible.
    *   If valid, calculate the `current_total_skill = pref_A[num_batsmen] + pref_B[num_bowlers]`.
    *   Keep track of the maximum `current_total_skill` found across all valid combinations.

The maximum total skill found after checking all valid combinations will be our answer.

## Complexity Analysis

*   **Time Complexity**:
    *   Reading input: $O(N + M)$
    *   Sorting batsmen skills: $O(N \log N)$
    *   Sorting bowlers skills: $O(M \log M)$
    *   Calculating prefix sums for batsmen: $O(N)$
    *   Calculating prefix sums for bowlers: $O(M)$
    *   Iterating through combinations: The loop runs a constant number of times (4 iterations for `num_batsmen` from 4 to 7). Inside the loop, operations are $O(1)$ (array access, addition, comparison). So, this step is $O(1)$.
    *   Overall, the dominant operations are sorting. Thus, the total time complexity is $\mathcal{O}(N \log N + M \log M)$.

*   **Space Complexity**:
    *   Storing batsmen skills (`A`): $O(N)$
    *   Storing bowlers skills (`B`): $O(M)$
    *   Storing batsmen prefix sums (`pref_A`): $O(N)$
    *   Storing bowlers prefix sums (`pref_B`): $O(M)$
    *   Overall, the total space complexity is $\mathcal{O}(N + M)$.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // Not strictly needed for this specific problem, but useful for other sum operations

void solve() {
    int N, M;
    std::cin >> N >> M;

    std::vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    std::vector<long long> B(M);
    for (int i = 0; i < M; ++i) {
        std::cin >> B[i];
    }

    // Sort skills in descending order to easily pick the top players
    // std::greater<long long>() ensures descending order
    std::sort(A.begin(), A.end(), std::greater<long long>());
    std::sort(B.begin(), B.end(), std::greater<long long>());

    // Calculate prefix sums for top skills.
    // pref_A[k] will store the sum of the top k skills (1-indexed).
    // pref_A[0] will be 0, representing the sum of 0 players.
    std::vector<long long> pref_A(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        pref_A[i + 1] = pref_A[i] + A[i];
    }

    std::vector<long long> pref_B(M + 1, 0);
    for (int i = 0; i < M; ++i) {
        pref_B[i + 1] = pref_B[i] + B[i];
    }

    long long max_total_skill = -1; // Initialize with -1. Since skills are non-negative, any valid sum will be >= 0.

    // Iterate through possible combinations of (batsmen_count, bowlers_count)
    // A team must have exactly 11 players, with at least 4 batsmen and 4 bowlers.
    // This means batsmen_count can range from 4 to 7.
    // Corresponding bowlers_count will be 11 - batsmen_count.
    for (int num_batsmen = 4; num_batsmen <= 7; ++num_batsmen) {
        int num_bowlers = 11 - num_batsmen;

        // Check if we have enough players of each type available
        if (N >= num_batsmen && M >= num_bowlers) {
            long long current_skill = pref_A[num_batsmen] + pref_B[num_bowlers];
            if (current_skill > max_total_skill) {
                max_total_skill = current_skill;
            }
        }
    }

    std::cout << max_total_skill << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
```