# [Red Light, Green Light (DOLL)](https://www.codechef.com/problems/DOLL)
- **Difficulty Rating**: 984
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a scenario from the Squid Game, specifically the "Red Light, Green Light" game. Gi-Hun and Ali are playing, and there are `N` players standing between them. The doll (Young-hee) is watching. Gi-Hun needs to see Ali, but some players might be blocking his line of sight.

We are given:
1.  `N`: The total number of players standing between Gi-Hun and Ali.
2.  `K`: The height of Gi-Hun (and Ali). This `K` represents the maximum height a player can have without blocking the line of sight.
3.  `H_i`: The height of each of the `N` players.

A player blocks Gi-Hun's line of sight if their height `H_i` is strictly greater than `K`. Players whose height `H_i` is less than or equal to `K` do not block the view. The goal is to find the minimum number of players who need to be "shot" (removed) so that Gi-Hun can see Ali.

## Intuition & Mathematical Observation

The problem statement clearly defines what constitutes a "blocking" player: any player whose height `H_i` is strictly greater than `K`. Conversely, players with height `H_i \le K` do *not* block the view.

Since we want to find the *minimum* number of players to shoot, we should only remove those who are absolutely necessary. Based on the definition, only players with `H_i > K` are necessary to remove. Players with `H_i \le K` do not need to be removed as they don't obstruct the view.

Therefore, the solution is straightforward:
1.  Initialize a counter for "shot players" to zero.
2.  Iterate through all `N` players.
3.  For each player, read their height `H_i`.
4.  If `H_i > K`, increment the "shot players" counter.
5.  After checking all players, the final value of the counter will be the minimum number of players that need to be shot.

This approach directly follows the problem's criteria and ensures we only count players who *must* be removed.

## Complexity Analysis

*   **Time Complexity**: $O(N)$ per test case.
    *   Reading `N` and `K` takes constant time, $O(1)$.
    *   The core logic involves a single loop that iterates `N` times. Inside the loop, we perform a constant number of operations: reading `H_i`, a comparison (`H_i > K`), and potentially an increment. Each of these operations takes $O(1)$ time.
    *   Therefore, for one test case, the total time complexity is dominated by the loop, making it $O(N)$.
    *   If there are `T` test cases, the total time complexity will be $O(T \cdot N)$.

*   **Space Complexity**: $O(1)$ per test case.
    *   We only use a few integer variables to store `N`, `K`, `H_i`, and `shot_players_count`. The amount of memory used does not depend on the input size `N`. This makes the space complexity constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries, as requested

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

// Function to solve a single test case
void solve() {
    int N, K;
    // Read the number of players (N) and the height of Gi-Hun/Ali (K)
    cin >> N >> K;

    int shot_players_count = 0; // Initialize a counter for players who need to be shot

    // Loop through each of the N players between Gi-Hun and Ali
    for (int i = 0; i < N; ++i) {
        int H_i;
        // Read the height of the current player
        cin >> H_i;

        // According to the problem statement, a player blocks the line of sight
        // if their height H_i is strictly greater than K.
        // Players with height H_i <= K do not block the line of sight.
        if (H_i > K) {
            shot_players_count++; // Increment the counter if the player blocks the view
        }
    }

    // Output the minimum number of players who need to be shot for this test case
    cout << shot_players_count << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming to prevent TLE (Time Limit Exceeded)
    // on problems with large inputs.
    ios_base::sync_with_stdio(false); // Unties C++ streams from C standard streams
    cin.tie(NULL);                   // Prevents cin from flushing cout before each input operation

    int T;
    // Read the total number of test cases
    cin >> T;

    // Loop T times, calling the solve function for each test case
    while (T--) {
        solve();
    }

    return 0; // Indicate successful program execution
}
```