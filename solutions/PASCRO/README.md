# [Rock Paper Scissor (PASCRO)](https://www.codechef.com/problems/PASCRO)
- **Difficulty Rating**: 1226
- **Solved in**: 2 attempt(s)

## Problem Summary

The problem describes a game of Rock-Paper-Scissors played for `N` rounds between Chef and Chefina. Chef's moves for each round are given by string `A`, and Chefina's moves by string `B`. Chef wants to win the overall game, meaning his total number of wins must be strictly greater than Chefina's total number of wins. Chef can change his move in any round, and each change costs 1. The goal is to find the minimum number of changes Chef needs to make to achieve his objective.

## Intuition & Mathematical Observation

1.  **Initial State Analysis**:
    First, we need to determine the outcome of each round based on the initial moves. We count Chef's wins (`chef_wins_count`), Chefina's wins (`chefina_wins_count`), and draws (`draw_count`).

2.  **Goal Definition**:
    Chef's goal is to have `chef_final_wins > chefina_final_wins`.
    Let `S_A` be Chef's initial wins and `S_B` be Chefina's initial wins. The current difference in scores is `D = S_A - S_B`.
    We need the final difference `D' = S_A' - S_B'` to be at least 1.
    If Chef already has `S_A > S_B`, he doesn't need to make any changes, so the answer is 0.
    Otherwise (`S_A <= S_B`), the current difference `D` is less than or equal to 0. The required increase in the difference is `diff_needed = 1 - D`. Since `D <= 0`, `diff_needed` will always be at least 1.

3.  **Impact of Changes**:
    Chef can change his move in a round. To minimize changes, Chef should only make changes that convert a round into a win for himself.
    *   **Converting a Chefina win to a Chef win**: If Chefina initially won a round (e.g., Chef played 'R', Chefina played 'P'), Chef can change his move to win (e.g., change 'R' to 'S').
        *   Effect: Chef's score increases by 1, Chefina's score decreases by 1.
        *   Net change in `(Chef_score - Chefina_score)`: `+1 - (-1) = +2`.
        *   Cost: 1 change.
    *   **Converting a Draw to a Chef win**: If a round was a draw (e.g., Chef played 'R', Chefina played 'R'), Chef can change his move to win (e.g., change 'R' to 'P').
        *   Effect: Chef's score increases by 1, Chefina's score remains 0.
        *   Net change in `(Chef_score - Chefina_score)`: `+1 - 0 = +1`.
        *   Cost: 1 change.
    *   Chef would never change a round he already won, as it would move him away from his goal.

4.  **Optimal Strategy (Greedy Approach)**:
    To achieve the `diff_needed` with the minimum number of changes, Chef should prioritize changes that provide the largest increase in score difference per change.
    *   Converting a Chefina win gives a `+2` difference for 1 change.
    *   Converting a Draw gives a `+1` difference for 1 change.
    Therefore, Chef should first convert as many Chefina wins as possible, as they are more efficient. If the `diff_needed` is still not met, he then uses draws.

5.  **Algorithm Steps**:
    a. Calculate `chef_wins_count`, `chefina_wins_count`, and `draw_count` from the initial moves.
    b. If `chef_wins_count > chefina_wins_count`, output 0 and terminate.
    c. Calculate `current_diff = chef_wins_count - chefina_wins_count`.
    d. Calculate `diff_needed = 1 - current_diff`. This is the minimum total difference increase required.
    e. Initialize `changes = 0`.
    f. **Phase 1: Utilize Chefina's wins.**
        Each conversion costs 1 change and provides `+2` to the difference.
        The number of Chefina wins we ideally need to convert to cover `diff_needed` is `k1_ideal = ceil(diff_needed / 2.0)`. In integer arithmetic, this is `(diff_needed + 1) / 2`.
        *   If `k1_ideal <= chefina_wins_count`: We have enough Chefina-win rounds to achieve the goal.
            `changes = k1_ideal`.
        *   Else (`k1_ideal > chefina_wins_count`): We must convert all `chefina_wins_count` rounds that Chefina initially won.
            `changes = chefina_wins_count`.
            `diff_achieved_by_k1 = 2 * chefina_wins_count`.
            `remaining_diff_needed = diff_needed - diff_achieved_by_k1`.
            This `remaining_diff_needed` must be covered by converting draws.
    g. **Phase 2: Utilize Draws (if needed).**
        Each conversion costs 1 change and provides `+1` to the difference.
        The number of draws to convert (`k2_needed`) is simply `remaining_diff_needed`.
        Add `k2_needed` to `changes`. (It's guaranteed that `remaining_diff_needed <= draw_count` because the total possible difference increase from all Chefina wins and draws is `2 * chefina_wins_count + draw_count`, which is always sufficient to cover `diff_needed`).
    h. Output `changes`.

## Complexity Analysis

*   **Time Complexity**:
    *   The `get_round_outcome` function takes $O(1)$ time.
    *   The loop to calculate initial scores and categorize rounds iterates `N` times, performing $O(1)$ work in each iteration. This takes $O(N)$ time.
    *   All subsequent calculations for `diff_needed` and `changes` are $O(1)$.
    *   Therefore, for a single test case, the time complexity is $O(N)$.
    *   Given `T` test cases, the total time complexity is $O(T \cdot N)$.

*   **Space Complexity**:
    *   Storing the input strings `A` and `B` requires $O(N)$ space.
    *   All other variables used for counts and differences require $O(1)$ space.
    *   Thus, the total space complexity is $O(N)$.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

// Function to determine the winner of a single round
// Returns 1 if Chef wins, -1 if Chefina wins, 0 if it's a draw.
int get_round_outcome(char chef_move, char chefina_move) {
    if (chef_move == chefina_move) {
        return 0; // Draw
    }
    if (chef_move == 'R') {
        if (chefina_move == 'S') return 1; // Rock beats Scissors
        if (chefina_move == 'P') return -1; // Paper beats Rock
    } else if (chef_move == 'P') {
        if (chefina_move == 'R') return 1; // Paper beats Rock
        if (chefina_move == 'S') return -1; // Scissors beats Paper
    } else if (chef_move == 'S') {
        if (chefina_move == 'P') return 1; // Scissors beats Paper
        if (chefina_move == 'R') return -1; // Rock beats Scissors
    }
    return 0; // Should not be reached with valid inputs 'R', 'P', 'S'
}

void solve() {
    int N;
    std::cin >> N;
    std::string A, B;
    std::cin >> A >> B;

    int chef_wins_count = 0;
    int chefina_wins_count = 0;
    int draw_count = 0;

    // Calculate initial scores and categorize rounds
    for (int i = 0; i < N; ++i) {
        int outcome = get_round_outcome(A[i], B[i]);
        if (outcome == 1) {
            chef_wins_count++;
        } else if (outcome == -1) {
            chefina_wins_count++;
        } else { // outcome == 0
            draw_count++;
        }
    }

    // If Chef already wins, 0 changes are needed.
    if (chef_wins_count > chefina_wins_count) {
        std::cout << 0 << "\n";
        return;
    }

    // Chef needs to win, meaning Chef's final score must be strictly greater than Chefina's final score.
    // Let S_A be Chef's initial score and S_B be Chefina's initial score.
    // We need S_A' > S_B'.
    // The current difference is D = S_A - S_B. Since S_A <= S_B, D <= 0.
    // We need the final difference D' = S_A' - S_B' >= 1.
    // The required increase in difference is at least 1 - D.
    int current_diff = chef_wins_count - chefina_wins_count;
    int diff_needed = 1 - current_diff; // This will be >= 1 since current_diff <= 0

    int changes = 0;

    // Strategy:
    // 1. Prioritize converting Chefina's wins to Chef's wins.
    //    Each such conversion costs 1 change and increases the score difference by 2.
    //    We have `chefina_wins_count` such rounds available.
    // 2. If more difference is needed, convert draws to Chef's wins.
    //    Each such conversion costs 1 change and increases the score difference by 1.
    //    We have `draw_count` such rounds available.

    // Calculate how many Chefina-win conversions (k1) are ideally needed.
    // We need 2 * k1 >= diff_needed.
    // Minimum k1 = ceil(diff_needed / 2.0)
    // Using integer division: k1_needed = (diff_needed + 1) / 2
    int k1_needed = (diff_needed + 1) / 2;

    if (k1_needed <= chefina_wins_count) {
        // We can achieve the goal by only converting Chefina's wins.
        changes = k1_needed;
    } else {
        // We must convert all Chefina's wins first.
        changes = chefina_wins_count;
        int diff_achieved_by_k1 = 2 * chefina_wins_count;
        
        // Calculate the remaining difference needed after converting all Chefina's wins.
        int remaining_diff_needed = diff_needed - diff_achieved_by_k1;
        
        // Now we need to cover the remaining difference using draws.
        // Each draw conversion gives +1 difference.
        int k2_needed = remaining_diff_needed;
        
        // Add the draw conversions to the total changes.
        // It's guaranteed that remaining_diff_needed will be <= draw_count.
        changes += k2_needed;
    }

    std::cout << changes << "\n";
}

int main() {
    // Fast I/O for competitive programming
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