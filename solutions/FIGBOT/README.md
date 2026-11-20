# [FightBots (FIGBOT)](https://www.codechef.com/problems/FIGBOT)
- **Difficulty Rating**: 1329
- **Solved in**: 1 attempt(s)

## Problem Summary

Alice starts at coordinates (0,0). Bob starts at coordinates (X,Y). The match lasts for N seconds. In each second, Alice makes one move (R, L, U, or D) according to a given string S of length N. Bob can move one unit in any of the four cardinal directions (up, down, left, right) per second. Bob can only start moving after Alice makes her first move. Bob catches Alice if he reaches her exact position at the *same second* she arrives there. The task is to determine if Bob can ever catch Alice.

## Intuition & Mathematical Observation

1.  **Alice's Movement**: Alice's path is deterministic. We can simulate her moves second by second. She starts at (0,0). After `k` moves (0-indexed, i.e., at the `(k+1)`-th second), her position `(alice_x, alice_y)` can be tracked by updating her coordinates based on `S[k]`.

2.  **Bob's Movement and Catching Condition**:
    *   Bob starts at `(X, Y)`.
    *   At any given second `T` (where `T` is the number of seconds elapsed since the start of the match), Alice will be at some position `(Ax, Ay)`.
    *   Bob needs to reach `(Ax, Ay)` from `(X, Y)` in *exactly* `T` seconds.

3.  **Minimum Time (Manhattan Distance)**: The minimum number of steps (and thus minimum time) required for Bob to travel from `(x1, y1)` to `(x2, y2)` is the Manhattan distance: `|x1 - x2| + |y1 - y2|`. Let's call this `manhattan_dist`.

4.  **Exact Time Condition**: For Bob to reach `(Ax, Ay)` in *exactly* `T` seconds, two conditions must be met:
    *   **Condition 1: Sufficient Time**: Bob must have enough time to cover the minimum distance. This means `manhattan_dist <= T`. If `manhattan_dist > T`, Bob cannot reach Alice in time.
    *   **Condition 2: Parity Check**: If `manhattan_dist < T`, Bob has `T - manhattan_dist` "extra" seconds. In these extra seconds, Bob must make moves that effectively cancel each other out (e.g., move right then left, or up then down) to end up at the target position. Each such pair of canceling moves takes 2 seconds. Therefore, the `T - manhattan_dist` extra seconds *must be an even number*.
        Mathematically, this means `(T - manhattan_dist) % 2 == 0`.
        This simplifies to `T % 2 == manhattan_dist % 2`. In other words, the parity of the total time elapsed must be the same as the parity of the Manhattan distance.

5.  **Algorithm**:
    *   Initialize Alice's current position `(alice_x, alice_y)` to `(0,0)`.
    *   Iterate `k` from `0` to `N-1`. This `k` represents the 0-indexed move Alice makes. The `(k+1)`-th second is completed after Alice makes move `S[k]`.
    *   Update `(alice_x, alice_y)` based on `S[k]`.
    *   Calculate `time_elapsed = k + 1`.
    *   Calculate `manhattan_dist = std::abs(alice_x - X) + std::abs(alice_y - Y)`.
    *   Check if `manhattan_dist <= time_elapsed` AND `(manhattan_dist % 2 == time_elapsed % 2)`.
    *   If both conditions are true, Bob can catch Alice. Set a flag `bob_wins = true` and break the loop, as we only need to know if he *can ever* catch her.
    *   After the loop, print "Yes" if `bob_wins` is true, otherwise print "No".

## Complexity Analysis

*   **Time Complexity**:
    *   The `solve()` function contains a single loop that iterates `N` times (from `k = 0` to `N-1`).
    *   Inside the loop, operations like updating Alice's position, calculating Manhattan distance, and performing parity checks all take constant time, $O(1)$.
    *   Therefore, for each test case, the time complexity is $O(N)$.
    *   Given `T` test cases, the total time complexity is $O(T \cdot N)$.
    *   With $N \le 10^5$ and $T \le 10$, the total operations are approximately $10 \cdot 10^5 = 10^6$, which is well within typical time limits.

*   **Space Complexity**:
    *   The variables used to store coordinates, distances, and flags (`N, X, Y, alice_x, alice_y, dist_x, dist_y, manhattan_dist, time_elapsed, bob_wins`) require a constant amount of space, $O(1)$.
    *   The input string `S` of length `N` requires $O(N)$ space to store.
    *   Thus, the overall space complexity is $O(N)$.

## Solution Code

```cpp
#include <iostream> // Required for std::cin, std::cout
#include <string>   // Required for std::string
#include <cmath>    // Required for std::abs

void solve() {
    int N; // Length of the match (number of seconds)
    int X, Y; // Bob's initial coordinates
    std::cin >> N >> X >> Y;
    std::string S; // Alice's sequence of moves
    std::cin >> S;

    // Alice's current position, starting at (0,0)
    int alice_x = 0;
    int alice_y = 0;

    bool bob_wins = false; // Flag to track if Bob can win

    // Iterate through each second of the match
    // 'k' represents the 0-indexed move in string S.
    // The (k+1)-th second is completed after Alice makes move S[k].
    for (int k = 0; k < N; ++k) {
        // Alice makes her move based on S[k]
        char move = S[k];
        if (move == 'R') {
            alice_x++;
        } else if (move == 'L') {
            alice_x--;
        } else if (move == 'U') {
            alice_y++;
        } else if (move == 'D') {
            alice_y--;
        }

        // After (k+1) seconds, Alice is at (alice_x, alice_y).
        // Bob started at (X, Y).
        // We need to check if Bob can reach (alice_x, alice_y) in exactly (k+1) seconds.

        // Calculate the Manhattan distance between Bob's starting position and Alice's current position
        int dist_x = std::abs(alice_x - X);
        int dist_y = std::abs(alice_y - Y);
        int manhattan_dist = dist_x + dist_y;
        
        int time_elapsed = k + 1; // The number of seconds that have passed

        // Bob can reach Alice's current position (alice_x, alice_y) from his starting position (X, Y)
        // in exactly 'time_elapsed' seconds if and only if:
        // 1. The Manhattan distance is less than or equal to the time elapsed.
        //    (Bob must have enough time to cover the minimum distance)
        // 2. The parity of the Manhattan distance is the same as the parity of the time elapsed.
        //    (If Bob has extra time (time_elapsed - manhattan_dist), this extra time must be an even number
        //    of steps, allowing him to move back and forth without changing his final position.)
        if (manhattan_dist <= time_elapsed && (manhattan_dist % 2 == time_elapsed % 2)) {
            bob_wins = true;
            break; // Bob can win, no need to check further seconds
        }
    }

    // Output the result for the current test case
    if (bob_wins) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from being flushed before each std::cin.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Number of test cases
    std::cin >> T;
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}
```