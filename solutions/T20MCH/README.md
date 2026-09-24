# [Possible Victory (T20MCH)](https://www.codechef.com/problems/T20MCH)
- **Difficulty Rating**: 769
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if Team B can achieve a "possible victory" in a T20 cricket match. We are given three integers:
1.  `R`: Team A's total score.
2.  `O`: The number of overs Team B has already played.
3.  `C`: Team B's current score.

Team B wins if their final score is strictly greater than Team A's score (`R`). We need to assume Team B plays optimally to maximize their score in the remaining overs. A T20 match consists of 20 overs per team.

## Intuition & Mathematical Observation

To determine if a "possible victory" exists for Team B, we need to calculate the *maximum possible score* Team B can achieve. If this maximum possible score is greater than Team A's score (`R`), then Team B can win.

Here's the breakdown of the calculation:

1.  **Total Overs in a T20 Match**: Each team plays 20 overs.
2.  **Overs Remaining for Team B**: If Team B has already played `O` overs, the number of overs they have left to play is `20 - O`.
3.  **Maximum Runs per Over**: To maximize runs, we consider the best possible scenario for each ball. In cricket, a maximum of 6 runs (a six) can be scored off a single legal delivery. Since an over consists of 6 balls, the maximum runs Team B can score in one over is `6 balls * 6 runs/ball = 36 runs`.
4.  **Maximum Runs in Remaining Overs**: If there are `remaining_overs` left, and Team B can score a maximum of 36 runs in each of these overs, then the maximum runs they can score in the remaining overs is `remaining_overs * 36`.
5.  **Maximum Total Score for Team B**: Team B's current score (`C`) plus the maximum runs they can score in the remaining overs will give their maximum possible final score. So, `max_team_b_score = C + (remaining_overs * 36)`.
6.  **Winning Condition**: If `max_team_b_score` is strictly greater than `R`, Team B can win. Otherwise, they cannot.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The solution involves a fixed number of arithmetic operations (subtraction, multiplication, addition, and comparison) and input/output operations, regardless of the magnitude of the input integers. These operations take constant time.

-   **Space Complexity**: $O(1)$
    The solution uses a fixed number of integer variables (`R`, `O`, `C`, `remaining_overs`, `max_runs_in_remaining_overs`, `max_team_b_score`) to store input and intermediate results. The memory usage does not scale with the input values.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream and many other standard libraries

// Using the standard namespace as requested
using namespace std;

int main() {
    // Enable fast I/O operations as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare three integer variables to store the input values:
    // R: Team A's total score
    // O: Number of overs Team B has already played
    // C: Team B's current score
    int R, O, C;

    // Read the three integers from standard input
    cin >> R >> O >> C;

    // Calculate the number of overs remaining for Team B to play.
    // A T20 match has 20 overs per team.
    int remaining_overs = 20 - O;

    // Calculate the maximum runs Team B can score in the remaining overs.
    // In each over, there are 6 balls.
    // On each ball, a maximum of 6 runs can be scored.
    // So, maximum runs per over = 6 balls * 6 runs/ball = 36 runs.
    // Maximum runs in remaining overs = remaining_overs * 36.
    int max_runs_in_remaining_overs = remaining_overs * 36;

    // Calculate the maximum total score Team B can achieve.
    // This is their current score plus the maximum runs they can score in the remaining overs.
    int max_team_b_score = C + max_runs_in_remaining_overs;

    // Check if Team B's maximum possible score is strictly greater than Team A's score (R).
    // If it is, Team B can win.
    if (max_team_b_score > R) {
        // Output "YES" if Team B can win
        cout << "YES\n";
    } else {
        // Otherwise, output "NO"
        cout << "NO\n";
    }

    // Return 0 to indicate successful execution
    return 0;
}
```