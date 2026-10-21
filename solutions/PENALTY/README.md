# [Penalty Shots (PENALTY)](https://www.codechef.com/problems/PENALTY)
- **Difficulty Rating**: 925
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a penalty shootout scenario between two teams. There are a total of 10 shots. Team 1 takes the 1st, 3rd, 5th, 7th, and 9th shots, while Team 2 takes the 2nd, 4th, 6th, 8th, and 10th shots. We are given a sequence of 10 integers, where `1` indicates a goal and `0` indicates a miss for each shot in chronological order. The task is to determine the winner of the shootout: output `1` if Team 1 wins, `2` if Team 2 wins, and `0` if the match is a draw.

## Intuition & Mathematical Observation

The problem is a straightforward simulation. We need to keep track of the scores for each team as the shots are taken.

1.  **Initialize Scores**: Start with `score1 = 0` and `score2 = 0`.
2.  **Process Shots**: Iterate through the 10 shots.
    *   For a 0-indexed array `a` storing the shot outcomes:
        *   Shots at indices `0, 2, 4, 6, 8` correspond to Team 1.
        *   Shots at indices `1, 3, 5, 7, 9` correspond to Team 2.
    *   Alternatively, we can observe that Team 1 takes shots when the 0-indexed shot number `i` is even (`i % 2 == 0`), and Team 2 takes shots when `i` is odd (`i % 2 != 0`).
    *   If a shot results in a goal (value is `1`), increment the corresponding team's score.
3.  **Determine Winner**: After all 10 shots are processed:
    *   If `score1 > score2`, Team 1 wins.
    *   If `score2 > score1`, Team 2 wins.
    *   If `score1 == score2`, it's a draw.

There are no complex mathematical observations or tricky edge cases; it's a direct implementation of the rules.

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    For each test case, the solution involves a single loop that iterates exactly 10 times (for the 10 shots). Inside the loop, operations like array access, comparison, and increment are all constant time. Since 10 is a constant, the time taken per test case is constant. If there are $T$ test cases, the total time complexity would be $O(T \times 10)$, which simplifies to $O(T)$.

*   **Space Complexity**: $O(1)$
    The solution uses a `std::vector<int> a` of fixed size 10 to store the shot outcomes. It also uses a few integer variables (`score1`, `score2`, `t`, `i`). All these consume a constant amount of memory regardless of the input values (as the number of shots is fixed at 10). Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <numeric> // Not strictly needed for this solution, but often included.

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        std::vector<int> a(10); // Vector to store the outcomes of 10 shots
        int score1 = 0;        // Score for Team 1
        int score2 = 0;        // Score for Team 2

        // Loop through all 10 shots
        for (int i = 0; i < 10; ++i) {
            std::cin >> a[i]; // Read the outcome of the current shot

            // Check if it's Team 1's shot (0-indexed: 0, 2, 4, 6, 8)
            if (i % 2 == 0) {
                if (a[i] == 1) { // If it's a goal
                    score1++;
                }
            } else { // It's Team 2's shot (0-indexed: 1, 3, 5, 7, 9)
                if (a[i] == 1) { // If it's a goal
                    score2++;
                }
            }
        }

        // Determine the winner based on final scores
        if (score1 > score2) {
            std::cout << 1 << "\n"; // Team 1 wins
        } else if (score2 > score1) {
            std::cout << 2 << "\n"; // Team 2 wins
        } else {
            std::cout << 0 << "\n"; // It's a draw
        }
    }
    return 0; // Indicate successful execution
}

```