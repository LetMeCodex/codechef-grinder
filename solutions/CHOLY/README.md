# [Chess Olympiad (CHOLY)](https://www.codechef.com/problems/CHOLY)
- **Difficulty Rating**: 641
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if our team can still win a round of 4 chess games. We are given the current number of games won (`X`), drawn (`Y`), and lost (`Z`) by our team. The scoring system is:
- Win: 1 point
- Draw: 0.5 points
- Loss: 0 points

A team wins the round if they accumulate strictly more points than their opponent. We need to output "Yes" if our team can still win, and "No" otherwise.

## Intuition & Mathematical Observation

The core idea is to determine if our team *can still win*. This means we need to consider the *best possible outcome* for our team in the remaining games. If, even under the most favorable circumstances, our team cannot achieve strictly more points than the opponent, then it's impossible to win.

Let's break down the points and scenarios:

1.  **Total Games**: There are always 4 games in a round.
2.  **Games Played So Far**: `X + Y + Z`
3.  **Remaining Games**: `R = 4 - (X + Y + Z)`

4.  **Our Team's Current Points**:
    *   For `X` wins: `X * 1 = X` points
    *   For `Y` draws: `Y * 0.5` points
    *   For `Z` losses: `Z * 0 = 0` points
    *   Total current points for our team: `P_my_current = X + 0.5Y`

5.  **Opponent's Current Points**:
    *   If our team won `X` games, the opponent lost `X` games: `X * 0 = 0` points
    *   If our team drew `Y` games, the opponent drew `Y` games: `Y * 0.5` points
    *   If our team lost `Z` games, the opponent won `Z` games: `Z * 1 = Z` points
    *   Total current points for opponent: `P_opp_current = 0.5Y + Z`

6.  **Best Case for Our Team in Remaining Games**:
    To maximize our team's chances of winning, we assume our team wins *all* `R` remaining games.
    *   Our team gains `R * 1 = R` points.
    *   The opponent gains `R * 0 = 0` points.

7.  **Final Points in Best Case Scenario**:
    *   Our team's maximum possible final points: `P_my_final = P_my_current + R = (X + 0.5Y) + R`
    *   Opponent's minimum possible final points: `P_opp_final = P_opp_current + 0 = (0.5Y + Z)`

8.  **Winning Condition**: Our team can still win if `P_my_final > P_opp_final`.
    Substitute the expressions:
    `(X + 0.5Y + R) > (0.5Y + Z)`

9.  **Substitute `R` and Simplify**:
    Recall `R = 4 - (X + Y + Z)`.
    `X + 0.5Y + (4 - X - Y - Z) > 0.5Y + Z`

    Let's simplify the left side:
    `X - X + 0.5Y - Y + 4 - Z`
    `0 - 0.5Y + 4 - Z`
    `4 - 0.5Y - Z`

    So the inequality becomes:
    `4 - 0.5Y - Z > 0.5Y + Z`

    Now, move all `Y` and `Z` terms to the right side:
    `4 > 0.5Y + Z + 0.5Y + Z`
    `4 > (0.5Y + 0.5Y) + (Z + Z)`
    `4 > Y + 2Z`

This simplified inequality `4 > Y + 2Z` is the condition we need to check. If it holds true, our team can still win; otherwise, it cannot.

## Complexity Analysis

-   **Time Complexity**: The solution involves reading three integer inputs and then performing a constant number of arithmetic operations (multiplication, addition) and a single comparison. These operations take a fixed amount of time regardless of the input values (within standard integer limits). Therefore, the time complexity is $O(1)$.

-   **Space Complexity**: The solution uses a few integer variables (`X`, `Y`, `Z`) to store the input values. This requires a constant amount of memory, which does not grow with the input size. Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries

// Using namespace std; is common in competitive programming to avoid typing std::
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // Unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X, Y, Z;
    // Read the number of wins, draws, and losses so far.
    cin >> X >> Y >> Z;

    // The problem asks if our team can still win the round.
    // A team wins if they receive *strictly* more points than the opposing team.
    // There are 4 games in total.
    // Points: Win = 1, Draw = 0.5, Loss = 0.

    // Let's calculate current points:
    // Our team's current points: X * 1 + Y * 0.5 + Z * 0 = X + 0.5Y
    // Opponent's current points: X * 0 + Y * 0.5 + Z * 1 = 0.5Y + Z

    // Number of games remaining: R = 4 - (X + Y + Z)

    // To determine if our team *can still win*, we assume the best possible outcome
    // for our team in the remaining games: our team wins all R remaining games.
    // If our team wins R games:
    //   Our team gains R * 1 = R points.
    //   Opponent gains R * 0 = 0 points.

    // Our team's maximum possible final points: P_my_final = (X + 0.5Y) + R
    // Opponent's minimum possible final points: P_opp_final = (0.5Y + Z)

    // Our team wins if P_my_final > P_opp_final:
    // (X + 0.5Y + R) > (0.5Y + Z)

    // Substitute R = 4 - (X + Y + Z):
    // X + 0.5Y + (4 - X - Y - Z) > 0.5Y + Z
    // X + 0.5Y + 4 - X - Y - Z > 0.5Y + Z
    // Simplify the inequality:
    // (X - X) + (0.5Y - Y) + 4 - Z > 0.5Y + Z
    // 0 - 0.5Y + 4 - Z > 0.5Y + Z
    // 4 - Z > 0.5Y + 0.5Y + Z
    // 4 - Z > Y + Z
    // 4 > Y + 2Z

    // So, we just need to check if 4 is strictly greater than Y + 2Z.
    if (4 > (Y + 2 * Z)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
```