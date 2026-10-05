# [Cricket Match (CRICMATCH)](https://www.codechef.com/problems/CRICMATCH)
- **Difficulty Rating**: 505
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if Chef's team can win a cricket match given the number of runs required (`N`) and the number of overs remaining (`M`). We need to output "YES" if they can win, and "NO" otherwise. The key rule provided is that a player can score a maximum of 6 runs in a single ball.

## Intuition & Mathematical Observation

To figure out if Chef's team can win, we need to calculate the *maximum possible runs* they can score with the `M` overs remaining. If the runs required (`N`) are less than or equal to this maximum possible score, then they can win. Otherwise, they cannot.

Let's break down the maximum scoring potential:
1.  **Balls per over**: In cricket, one over consists of 6 balls.
2.  **Maximum runs per ball**: The problem states that a player can score a maximum of 6 runs in a single ball.
3.  **Maximum runs per over**: If a player scores 6 runs on every ball in an over, the maximum runs scored in one over would be `6 balls * 6 runs/ball = 36 runs`.
4.  **Maximum total runs**: If there are `M` overs remaining, and Chef's team scores the maximum possible runs in every over, the total maximum runs they can score would be `M overs * 36 runs/over = M * 36`.

So, the `max_possible_runs` Chef's team can score is `M * 36`.

Now, we compare this with the `N` runs required:
*   If `N <= max_possible_runs` (i.e., `N <= M * 36`), Chef's team can score enough runs to win or tie. So, the answer is "YES".
*   If `N > max_possible_runs` (i.e., `N > M * 36`), Chef's team cannot score enough runs. So, the answer is "NO".

This logic is applied independently for each test case.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    The program reads `T` test cases. For each test case, it performs a constant number of operations: reading two integers (`N`, `M`), one multiplication (`M * 36`), one comparison (`N <= max_possible_runs`), and one print operation. Since all these operations take constant time, the total time complexity is directly proportional to the number of test cases, `T`.

*   **Space Complexity**: $O(1)$
    The program uses a fixed number of integer variables (`T`, `N`, `M`, `max_possible_runs`) regardless of the input values or the number of test cases. No data structures that scale with input size are used. Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream and many other standard libraries

// Using the entire std namespace as requested
using namespace std;

int main() {
    // Enable fast I/O operations.
    // This unties C++ standard streams from C standard streams
    // and prevents flushing cout before cin, speeding up input/output.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int N, M; // Declare integer variables N (runs required) and M (overs remaining).
        cin >> N >> M; // Read N and M for the current test case.

        // Calculate the maximum possible runs Chef's team can score.
        // 1 over consists of 6 balls.
        // A player can score a maximum of 6 runs in a ball.
        // So, maximum runs per over = 6 balls * 6 runs/ball = 36 runs.
        // Maximum total runs in M overs = M * 36 runs.
        int max_possible_runs = M * 36;

        // Check if the runs required (N) are less than or equal to the
        // maximum runs Chef's team can possibly score.
        if (N <= max_possible_runs) {
            // If yes, Chef's team can win. Print "YES" followed by a newline.
            cout << "YES\n";
        } else {
            // If no, Chef's team cannot win. Print "NO" followed by a newline.
            cout << "NO\n";
        }
    }

    return 0; // Indicate successful program execution.
}
```