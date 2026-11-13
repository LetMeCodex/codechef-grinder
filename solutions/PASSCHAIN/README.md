# [Passing Chain (PASSCHAIN)](https://www.codechef.com/problems/PASSCHAIN)
- **Difficulty Rating**: 570
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a game involving `N` players, numbered from 1 to `N`. The ball initially starts with player 1. Each player has a "passing power" `K`. If a player `P` has the ball, they can pass it to player `P+K`. This process continues as long as the player with the ball can pass it to a valid player (i.e., `P+K` is within the range `[1, N]`). The goal is to determine the number of the player who has the ball at the end of the game, when no further passes can be made.

## Intuition & Mathematical Observation

Let's trace the path of the ball:
1.  The ball starts with player 1.
2.  Player 1 passes it to player `1 + K`.
3.  Player `1 + K` passes it to player `(1 + K) + K = 1 + 2K`.
4.  Player `1 + 2K` passes it to player `(1 + 2K) + K = 1 + 3K`.
... and so on.

The players who receive the ball form an arithmetic progression: `1, 1+K, 1+2K, 1+3K, ...`.
The game stops when the current player, say `P_current`, cannot pass the ball to `P_current + K` because `P_current + K` would be greater than `N`. This means `P_current` is the last player in this sequence such that `P_current <= N` and `P_current + K > N`.

Our task is to find this `P_current`. We can simulate this process directly:
Start with `current_player = 1`.
Repeatedly add `K` to `current_player` as long as `current_player + K` does not exceed `N`.
Once `current_player + K > N`, the loop terminates, and `current_player` will hold the number of the final player.

For example, if `N=10` and `K=3`:
1.  `current_player = 1`. `1 + 3 = 4 <= 10`. `current_player` becomes 4.
2.  `current_player = 4`. `4 + 3 = 7 <= 10`. `current_player` becomes 7.
3.  `current_player = 7`. `7 + 3 = 10 <= 10`. `current_player` becomes 10.
4.  `current_player = 10`. `10 + 3 = 13 > 10`. The loop terminates.
The final player is 10.

This iterative approach perfectly matches the problem's logic.

## Complexity Analysis

-   **Time Complexity**: $O(N/K)$
    The `while` loop iterates, incrementing `current_player` by `K` in each step. `current_player` starts at 1 and goes up to at most `N`. In the worst case, when `K=1`, the loop runs approximately `N-1` times. Thus, for a single test case, the time complexity is proportional to `N/K`. Since there are `T` test cases, the total time complexity is $O(T \cdot N/K)$. Given the constraints (N up to 10^9, but K can also be large), this is efficient enough. If K is small (e.g., K=1), it's $O(N)$.

-   **Space Complexity**: $O(1)$
    The solution uses a fixed number of integer variables (`T`, `N`, `K`, `current_player`) regardless of the input size. Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries, as suggested

// Using the standard namespace, as suggested
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int N, K; // Variables to store the number of players and passing power
        cin >> N >> K; // Read N and K for the current test case

        int current_player = 1; // The ball initially starts with player 1

        // Simulate the passing chain.
        // The loop continues as long as the current player can pass the ball
        // to a valid player (i.e., current_player + K is within the range [1, N]).
        while (current_player + K <= N) {
            current_player = current_player + K; // Pass the ball to the next player
        }

        // After the loop terminates, 'current_player' holds the ball and cannot
        // pass it further. This is the final player.
        cout << current_player << "\n"; // Output the number of the final player, followed by a newline
    }

    return 0; // Indicate successful execution
}
```