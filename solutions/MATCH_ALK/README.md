# [Man of the Match (MATCH_ALK)](https://www.codechef.com/problems/MATCH_ALK)
- **Difficulty Rating**: 825
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the "Man of the Match" from a list of 22 players. For each player, we are given the number of runs they scored and the number of wickets they took. The points system is as follows:
- Each run scored earns 1 point.
- Each wicket taken earns 20 points.

We need to calculate the total points for all 22 players and identify the player with the highest total points. The output should be the 1-based index of this player. The problem guarantees that there will be a unique "Man of the Match" (no ties in total points). The solution must handle multiple test cases.

## Intuition & Mathematical Observation

The core idea is straightforward: for each player, we need to compute their total score based on the given formula and then find the maximum among these scores.

1.  **Point Calculation**: For any given player, if they scored `R` runs and took `W` wickets, their total points will be `R * 1 + W * 20`.

2.  **Finding the Maximum**: We need to iterate through all 22 players. As we process each player, we will:
    *   Calculate their current total points.
    *   Compare these points with the maximum points found so far.
    *   If the current player's points are greater than the `max_points_found_so_far`, we update `max_points_found_so_far` to the current player's points and also store the current player's 1-based index as the `man_of_the_match_index`.

3.  **Initialization**: Before starting the iteration, `max_points_found_so_far` should be initialized to a value lower than any possible score (e.g., -1, since runs and wickets are non-negative, making the minimum possible score 0). The `man_of_the_match_index` can be initialized to an invalid value like -1.

4.  **Uniqueness Guarantee**: The problem statement guarantees a unique "Man of the Match". This simplifies the logic as we don't need to implement any tie-breaking rules (e.g., choosing the player with the lower index in case of a tie). A simple `>` comparison is sufficient to find the strictly highest score.

After iterating through all 22 players, the `man_of_the_match_index` will hold the 1-based index of the player with the highest total points, which is our desired output.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    For each test case, we iterate exactly 22 times (once for each player). Inside the loop, we perform a constant number of operations: reading two integers, two multiplications, one addition, one comparison, and potentially two assignments. Since 22 is a fixed constant, the operations per test case are constant. If there are $T$ test cases, the total time complexity will be $T$ multiplied by this constant factor, resulting in $O(T)$.

*   **Space Complexity**: $O(1)$
    We only use a few integer variables to store `max_points`, `man_of_the_match_index`, `runs`, `wickets`, `current_player_points`, and the loop counter `i`. These variables occupy a constant amount of memory, regardless of the input values (within integer limits). Therefore, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries, as requested

using namespace std; // Uses the standard namespace, as requested

void solve() {
    // Initialize max_points to a value lower than any possible score.
    // The minimum possible score is 0 (0 runs, 0 wickets), so -1 is a safe initial value.
    int max_points = -1; 
    // Initialize man_of_the_match_index to an invalid value.
    // It will be updated with the 1-based index of the first player or any player with a higher score.
    int man_of_the_match_index = -1;

    // Iterate through all 22 players. Player indices are 1-based.
    for (int i = 1; i <= 22; ++i) {
        int runs, wickets;
        // Read the runs scored and wickets taken by the current player.
        cin >> runs >> wickets;

        // Calculate the total points for the current player.
        // Each run earns 1 point, and each wicket earns 20 points.
        int current_player_points = runs * 1 + wickets * 20;

        // Check if the current player's points are greater than the maximum points found so far.
        // The problem guarantees a unique "Man of the Match", so we don't need to handle ties.
        if (current_player_points > max_points) {
            max_points = current_player_points; // Update the maximum points.
            man_of_the_match_index = i;         // Update the index of the player with the maximum points.
        }
    }
    // Output the 1-based index of the player who has the highest total points.
    cout << man_of_the_match_index << "\n";
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // `ios_base::sync_with_stdio(false)` disables synchronization between C-style I/O (stdio)
    // and C++-style I/O (iostream), which can speed up I/O operations.
    // `cin.tie(NULL)` unties `cin` from `cout`, meaning `cin` will not flush `cout` before
    // reading input, further improving performance.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    // Read the number of test cases.
    cin >> t; 
    // Loop through each test case.
    while (t--) { 
        solve(); // Call the solve function to process the current test case.
    }

    return 0; // Indicate successful program execution.
}
```