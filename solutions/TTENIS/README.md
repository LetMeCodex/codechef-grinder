# [Chef and Table Tennis (TTENIS)](https://www.codechef.com/problems/TTENIS)
- **Difficulty Rating**: 1085
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to simulate a table tennis match given a string of '0's and '1's, where '1' represents a point won by Chef and '0' represents a point won by the opponent. We need to determine if Chef wins or loses the match based on standard table tennis rules: a player wins if they reach at least 11 points and have a lead of at least 2 points. The input string represents a complete and valid match.

## Intuition & Mathematical Observation

The core of the problem lies in correctly implementing the winning condition for a table tennis game. The rules are:
1. A player must score at least 11 points.
2. A player must have a lead of at least 2 points over their opponent.

These two conditions together handle both the standard win (e.g., 11-9) and the deuce scenario (e.g., 12-10, 13-11, etc.).

We can simulate the match point by point. We maintain two scores: `chef_score` and `opp_score`. We iterate through the input string. For each character:
- If it's '1', we increment `chef_score`.
- If it's '0', we increment `opp_score`.

After updating the scores for each point, we immediately check if either player has met the winning condition.

Let's analyze the winning condition more formally:
A player wins if:
`(player_score >= 11) AND (player_score - opponent_score >= 2)`

This single logical expression elegantly captures both the minimum score requirement and the lead requirement.

Since the problem guarantees that the input string represents a valid, finished match, we are assured that one of the players will eventually satisfy this winning condition. Therefore, as soon as a player wins, we can print the result ("WIN" for Chef, "LOSE" for the opponent) and terminate the processing for that test case.

The input string is guaranteed to be a complete match, meaning we don't need to worry about the string ending before a winner is determined. The loop will always find a winner and `return` from the `solve` function.

## Complexity Analysis

- **Time Complexity**: $O(N)$, where $N$ is the length of the input string `s`. We iterate through the string once, performing constant time operations for each character.
- **Space Complexity**: $O(1)$. We only use a few integer variables to store the scores and a single string variable to store the input. The space used does not depend on the input size.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Using namespace std; is requested by the problem statement.
using namespace std;

void solve() {
    string s;
    cin >> s; // Read the binary string representing the match points

    int chef_score = 0;
    int opp_score = 0;

    // Iterate through each character (point) in the string
    for (char c : s) {
        if (c == '1') {
            chef_score++; // Chef won the point
        } else { // c == '0'
            opp_score++; // Chef lost the point (opponent won)
        }

        // Check for winner after each point according to table tennis rules
        // A player wins if they have at least 11 points AND a lead of at least 2 points.
        // This single condition covers both the "first to 11" rule and the "deuce" rule (win by 2 points).

        // Check if Chef won
        if (chef_score >= 11 && (chef_score - opp_score >= 2)) {
            cout << "WIN\n"; // Chef wins
            return; // Game finished, exit function for this test case
        }

        // Check if Opponent won
        if (opp_score >= 11 && (opp_score - chef_score >= 2)) {
            cout << "LOSE\n"; // Opponent wins
            return; // Game finished, exit function for this test case
        }
    }
    // The problem guarantees that statistics represent a valid, finished match.
    // Therefore, one of the 'return' statements inside the loop will always be executed.
    // This part of the code should theoretically be unreachable if the problem statement's
    // guarantee holds true and the logic is correct.
}

int main() {
    // Fast I/O setup as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Call the solve function for each test case
    }

    return 0;
}
```