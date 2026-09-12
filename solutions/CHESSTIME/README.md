# [Chess Time (CHESSTIME)](https://www.codechef.com/problems/CHESSTIME)
- **Difficulty Rating**: 337
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the maximum number of complete chess games a person can play given `N` hours of free time. We are told that each chess game takes at least 20 minutes to complete.

## Intuition & Mathematical Observation

The core idea is to maximize the number of games played within the given `N` hours. Since each game takes *at least* 20 minutes, to play the maximum possible number of games, we should assume that each game takes *exactly* 20 minutes. If a game were to take more than 20 minutes, we would naturally be able to play fewer games.

Here's the breakdown:
1.  **Convert hours to minutes**: The free time is given in hours (`N`), but the game duration is in minutes (20 minutes). To perform calculations consistently, we should convert the total free time into minutes.
    *   1 hour = 60 minutes.
    *   Therefore, `N` hours = `N * 60` minutes.
2.  **Calculate maximum games**: Once we have the total free time in minutes, we can find out how many 20-minute segments fit into that time.
    *   Maximum games = (Total free time in minutes) / (Minutes per game)
    *   Maximum games = (`N * 60`) / `20`
3.  **Simplify the expression**: The expression `(N * 60) / 20` can be simplified:
    *   `60 / 20 = 3`
    *   So, Maximum games = `N * 3`.

This means for every hour of free time, a person can play 3 complete chess games.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    *   The program reads `T` test cases.
    *   For each test case, it performs a constant number of operations: reading an integer `N`, performing a simple multiplication (`N * 3`), and printing the result. These operations take constant time, $O(1)$.
    *   Since these constant-time operations are repeated `T` times, the total time complexity is proportional to the number of test cases, $O(T)$.
*   **Space Complexity**: $O(1)$
    *   The program uses a few integer variables (`T`, `N`, `max_games`) to store input and intermediate results. The memory required for these variables is constant and does not depend on the input values (other than the fixed size of an integer).
    *   Therefore, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries

// Use the standard namespace to avoid prefixing std::
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can speed up I/O operations.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // further optimizing I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int N; // Declare an integer variable N to store the hours of free time.
        cin >> N; // Read the number of hours for the current test case.

        // Calculate the maximum number of complete chess games.
        // One hour has 60 minutes. So, N hours have N * 60 minutes.
        // Each game takes at least 20 minutes. To maximize games, assume each takes exactly 20 minutes.
        // Total minutes / minutes per game = (N * 60) / 20.
        // This simplifies to N * (60 / 20) = N * 3.
        int max_games = N * 3;

        // Output the result for the current test case, followed by a newline character.
        cout << max_games << "\n";
    }

    return 0; // Indicate successful program execution.
}
```