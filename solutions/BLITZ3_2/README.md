# [Chess Match (BLITZ3_2)](https://www.codechef.com/problems/BLITZ3_2)
- **Difficulty Rating**: 998
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a blitz chess match where each player starts with 3 minutes on their clock. For every move played by a player, 2 seconds are added to their clock. The game lasts for a total of `N` turns (which implies `N` moves were made in total by both players combined). At the end of the game, White has `A` seconds left on their clock, and Black has `B` seconds left. We need to calculate the total duration of the game in seconds.

## Intuition & Mathematical Observation

The core idea to find the duration of the game is to determine the total "potential" time that could have been on the clocks throughout the game and then subtract the time that remained unused at the end. The difference will represent the total time that was actually spent by both players.

Let's break down the components:

1.  **Initial Time**:
    *   Each player starts with 3 minutes.
    *   3 minutes = 3 * 60 = 180 seconds.
    *   Since there are two players, the total initial time on both clocks combined is 180 seconds/player * 2 players = 360 seconds.

2.  **Time Added (Increments)**:
    *   For each move played, 2 seconds are added to the clock of the player who made the move.
    *   The game lasts for `N` turns. In the context of "2 seconds are added for each move played" and the solution structure, `N` represents the total number of moves made by *both* players combined throughout the game.
    *   Therefore, the total time added to the clocks due to increments is `N` moves * 2 seconds/move = `2 * N` seconds.

3.  **Total Potential Time**:
    *   This is the sum of all initial time and all increments received during the game.
    *   Total Potential Time = (Total Initial Time) + (Total Increments)
    *   Total Potential Time = `360 + (2 * N)` seconds.

4.  **Total Time Remaining**:
    *   At the end of the game, White has `A` seconds and Black has `B` seconds.
    *   Total Time Remaining = `A + B` seconds.

5.  **Duration of the Game**:
    *   The duration of the game is the total time that was *spent* by both players. This is the difference between the total potential time and the total time remaining on the clocks.
    *   Duration = Total Potential Time - Total Time Remaining
    *   Duration = `(360 + 2 * N) - (A + B)` seconds.

This formula directly calculates the total time consumed by both players, which is the duration of the game.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    *   The program processes `T` test cases.
    *   For each test case, it reads three integers (`N`, `A`, `B`), performs a constant number of arithmetic operations (two additions, one multiplication, one subtraction), and then prints the result. All these operations take constant time.
    *   Therefore, the time complexity per test case is $O(1)$.
    *   The total time complexity for `T` test cases is $O(T \times 1) = O(T)$.

-   **Space Complexity**: $O(1)$
    *   The program uses a fixed number of integer variables (`T`, `N`, `A`, `B`, `duration`) regardless of the input values or the number of test cases.
    *   The memory usage does not grow with the input size.
    *   Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries, as requested.

// Using the standard namespace to avoid prefixing std:: to standard library elements.
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and disables synchronization with C's stdio,
    // which can significantly speed up I/O operations.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop through each test case.
    while (T--) {
        int N, A, B; // Declare integer variables N, A, B for each test case.
        // N: total number of turns/moves in the game.
        // A: seconds remaining on white's clock at the end.
        // B: seconds remaining on black's clock at the end.
        cin >> N >> A >> B; // Read N, A, and B for the current test case.

        // Problem analysis:
        // 1. Initial time for each player: 3 minutes = 3 * 60 = 180 seconds.
        //    So, total initial time for both players = 180 + 180 = 360 seconds.
        //
        // 2. Increment per move: 2 seconds.
        //    The game lasts N turns. Each turn involves one move, which adds 2 seconds
        //    to the clock of the player who made that move.
        //    Therefore, across N turns (total N moves by both players), a total of N * 2 seconds are added to the clocks.
        //
        // 3. Total "potential" time on both clocks combined:
        //    This is the sum of all initial times and all increments received.
        //    Total potential time = (Total initial time) + (Total increments)
        //    Total potential time = 360 + (2 * N) seconds.
        //
        // 4. Total time remaining on both clocks at the end: A + B.
        //
        // 5. The duration of the game is the total time that was *spent* by both players.
        //    This is calculated by subtracting the total time remaining from the total potential time.
        int duration = (360 + 2 * N) - (A + B);

        // Print the calculated duration followed by a newline character.
        cout << duration << "\n";
    }

    return 0; // Indicate successful execution of the program.
}
```