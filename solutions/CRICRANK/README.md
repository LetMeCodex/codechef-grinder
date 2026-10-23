# [Cricket Ranking (CRICRANK)](https://www.codechef.com/problems/CRICRANK)
- **Difficulty Rating**: 966
- **Solved in**: 2 attempt(s)

## Problem Summary

The problem asks us to compare two cricket players, Player A and Player B, based on three key statistics: Runs, Wickets, and Catches. For each player, we are given their scores for these three statistics. We need to determine which player is "better" overall. The rule for determining the better player is straightforward: the player who performs better in at least two out of the three statistics is considered the winner. It's guaranteed that for each individual statistic, the scores of Player A and Player B will always be different (i.e., no ties within a single statistic). We need to process multiple test cases.

## Intuition & Mathematical Observation

The core of this problem is a direct comparison of three pairs of numbers. Since ties within a statistic are not possible (e.g., `R1 != R2`), for each statistic, one player will always be strictly better than the other.

Our intuition leads to a simple counting approach:
1. Initialize a counter, say `a_wins`, to zero. This counter will track how many statistics Player A is better in.
2. Compare Player A's Runs (`R1`) with Player B's Runs (`R2`). If `R1 > R2`, increment `a_wins`.
3. Compare Player A's Wickets (`W1`) with Player B's Wickets (`W2`). If `W1 > W2`, increment `a_wins`.
4. Compare Player A's Catches (`C1`) with Player B's Catches (`C2`). If `C1 > C2`, increment `a_wins`.
5. After checking all three statistics, we evaluate `a_wins`:
    - If `a_wins` is 2 or 3, it means Player A is better in a majority of the statistics, so Player A is the overall winner.
    - If `a_wins` is 0 or 1, it means Player B is better in a majority (2 or 3) of the statistics, so Player B is the overall winner.

This approach directly implements the problem's winning condition. There are no complex algorithms or data structures required, just simple conditional logic.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    For each test case, we perform a constant number of operations:
    -   Reading 6 integers.
    -   Three `if` comparisons and potential increments.
    -   One final `if` comparison and printing the result.
    Since all these operations take constant time, the work done per test case is $O(1)$. If there are $T$ test cases, the total time complexity will be $T \times O(1) = O(T)$.

-   **Space Complexity**: $O(1)$
    We use a fixed number of integer variables to store the number of test cases (`T`), the statistics for Player A (`R1, W1, C1`), the statistics for Player B (`R2, W2, C2`), and a counter for Player A's wins (`a_wins`). The memory used by these variables does not depend on the input values or the number of test cases (beyond storing `T` itself). Therefore, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <iostream> // Use iostream specifically for minimal includes

// It's generally good practice to avoid 'using namespace std;' in headers
// or large projects, but for competitive programming, it's common and acceptable.
// For this minimal code, we can explicitly use std:: for clarity.

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a crucial competitive programming optimization.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Declare variable for the number of test cases
    std::cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int R1, W1, C1; // Stats for player A: Runs, Wickets, Catches
        std::cin >> R1 >> W1 >> C1; // Read player A's stats

        int R2, W2, C2; // Stats for player B: Runs, Wickets, Catches
        std::cin >> R2 >> W2 >> C2; // Read player B's stats

        int a_wins = 0; // Counter for how many stats player A is better in

        // Compare Runs
        if (R1 > R2) {
            a_wins++; // Player A is better in runs
        }
        // Since R1 != R2 is guaranteed, if R1 is not greater than R2, then R2 must be greater than R1.
        // We don't need to explicitly count B's wins; we can infer it from A's wins.

        // Compare Wickets
        if (W1 > W2) {
            a_wins++; // Player A is better in wickets
        }
        // Since W1 != W2 is guaranteed, if W1 is not greater than W2, then W2 must be greater than W1.

        // Compare Catches
        if (C1 > C2) {
            a_wins++; // Player A is better in catches
        }
        // Since C1 != C2 is guaranteed, if C1 is not greater than C2, then C2 must be greater than C1.

        // Determine the overall better player based on the majority of stats
        // There are 3 stats. If A wins 2 or 3 stats, A is better.
        // If A wins 0 or 1 stats, B is better.
        if (a_wins >= 2) { // Player A is better in 2 or 3 stats
            std::cout << "A\n"; // Player A is better overall
        } else { // Player A is better in 0 or 1 stats, meaning B is better in 2 or 3 stats
            std::cout << "B\n"; // Player B is better overall
        }
    }

    return 0; // Indicate successful execution
}
```