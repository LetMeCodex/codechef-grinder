# [One Wrong Step (WRSTP)](https://www.codechef.com/problems/WRSTP)
- **Difficulty Rating**: 1070
- **Solved in**: 1 attempt(s)

## Problem Summary

A robot starts at coordinates `(0,0)`. It is given a sequence of `N` moves, where each move can be 'U' (Up), 'D' (Down), 'L' (Left), or 'R' (Right).
- 'U' increases the y-coordinate by 1.
- 'D' decreases the y-coordinate by 1.
- 'L' decreases the x-coordinate by 1.
- 'R' increases the x-coordinate by 1.

The task is to determine if it's possible to make the robot end up at `(0,0)` by changing *exactly one* of the given moves to any other valid move ('U', 'D', 'L', 'R').

## Intuition & Mathematical Observation

The core idea is to first calculate the robot's final position `(X_final, Y_final)` if all the original moves are executed as given. Then, we analyze how changing a single move affects this final position and what `(X_final, Y_final)` must be for the robot to end up at `(0,0)` after exactly one change.

Let's denote the original final position as `(X_orig, Y_orig)`.

1.  **Calculate `(X_orig, Y_orig)`:**
    We iterate through the given string of moves.
    - For each 'U', `Y_orig` increases by 1.
    - For each 'D', `Y_orig` decreases by 1.
    - For each 'L', `X_orig` decreases by 1.
    - For each 'R', `X_orig` increases by 1.

2.  **Analyze the effect of changing one move:**
    When we change one move, its original effect is undone, and the new move's effect is applied. This results in a net change to `(X_orig, Y_orig)`.

    *   **Changing 'U' to 'D'**:
        - Original effect of 'U': `+1` to `Y_orig`.
        - New effect of 'D': `-1` to `Y_orig`.
        - Net change to `Y_orig`: `(-1) - (+1) = -2`. `X_orig` remains unchanged.
        - For the final position to be `(0,0)`, we need `X_orig = 0` and `Y_orig - 2 = 0`, which implies `Y_orig = 2`.
        - This change is only possible if there was at least one 'U' move. If `Y_orig = 2`, it means there were more 'U' moves than 'D' moves, guaranteeing the existence of at least one 'U' to change.

    *   **Changing 'D' to 'U'**:
        - Original effect of 'D': `-1` to `Y_orig`.
        - New effect of 'U': `+1` to `Y_orig`.
        - Net change to `Y_orig`: `(+1) - (-1) = +2`. `X_orig` remains unchanged.
        - For the final position to be `(0,0)`, we need `X_orig = 0` and `Y_orig + 2 = 0`, which implies `Y_orig = -2`.
        - This change is only possible if there was at least one 'D' move. If `Y_orig = -2`, it means there were more 'D' moves than 'U' moves, guaranteeing the existence of at least one 'D' to change.

    *   **Changing 'L' to 'R'**:
        - Original effect of 'L': `-1` to `X_orig`.
        - New effect of 'R': `+1` to `X_orig`.
        - Net change to `X_orig`: `(+1) - (-1) = +2`. `Y_orig` remains unchanged.
        - For the final position to be `(0,0)`, we need `X_orig + 2 = 0` and `Y_orig = 0`, which implies `X_orig = -2`.
        - This change is only possible if there was at least one 'L' move. If `X_orig = -2`, it means there were more 'L' moves than 'R' moves, guaranteeing the existence of at least one 'L' to change.

    *   **Changing 'R' to 'L'**:
        - Original effect of 'R': `+1` to `X_orig`.
        - New effect of 'L': `-1` to `X_orig`.
        - Net change to `X_orig`: `(-1) - (+1) = -2`. `Y_orig` remains unchanged.
        - For the final position to be `(0,0)`, we need `X_orig - 2 = 0` and `Y_orig = 0`, which implies `X_orig = 2`.
        - This change is only possible if there was at least one 'R' move. If `X_orig = 2`, it means there were more 'R' moves than 'L' moves, guaranteeing the existence of at least one 'R' to change.

3.  **Conclusion:**
    The robot can reach `(0,0)` by changing exactly one move if and only if its original final position `(X_orig, Y_orig)` is one of the following:
    - `(0, 2)`
    - `(0, -2)`
    - `(-2, 0)`
    - `(2, 0)`

We simply calculate `(X_orig, Y_orig)` and check if it matches any of these four conditions.

## Complexity Analysis

-   **Time Complexity**:
    -   Reading the input `N` and string `s`: $O(N)$
    -   Iterating through the string `s` of length `N` to calculate the final coordinates `(x, y)`: $O(N)$
    -   Checking the final `(x, y)` against the four conditions: $O(1)$
    -   Total time complexity per test case: $O(N)$.
    -   Given `T` test cases, the total time complexity is $O(T \cdot N)$. With $N \le 10^5$ and $T \le 10$, this is approximately $10 \cdot 10^5 = 10^6$ operations, which is well within typical time limits.

-   **Space Complexity**:
    -   Storing the input string `s`: $O(N)$
    -   Storing integer variables `N`, `x`, `y`, `T`: $O(1)$
    -   Total space complexity: $O(N)$, dominated by the storage of the input string.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// It's common practice in competitive programming to use the entire std namespace
// to avoid repeatedly typing std::
using namespace std;

void solve() {
    int N; // Number of moves
    cin >> N;
    string s; // String of moves
    cin >> s;

    int x = 0; // Current x-coordinate, robot starts at (0,0)
    int y = 0; // Current y-coordinate

    // Calculate the final position (x, y) after all original moves
    for (char move : s) {
        if (move == 'U') {
            y++;
        } else if (move == 'D') {
            y--;
        } else if (move == 'L') {
            x--;
        } else if (move == 'R') {
            x++;
        }
    }

    // We need to check if changing exactly one move can lead to (0,0).
    // Let the original final position be (X_orig, Y_orig), which is (x, y) here.
    //
    // The possible target (X_orig, Y_orig) values that allow reaching (0,0)
    // by changing exactly one move are:
    // 1. (0, 2): If X_orig=0 and Y_orig=2, changing a 'U' to 'D' results in (0, 2-2) = (0,0).
    // 2. (0, -2): If X_orig=0 and Y_orig=-2, changing a 'D' to 'U' results in (0, -2+2) = (0,0).
    // 3. (-2, 0): If X_orig=-2 and Y_orig=0, changing an 'L' to 'R' results in (-2+2, 0) = (0,0).
    // 4. (2, 0): If X_orig=2 and Y_orig=0, changing an 'R' to 'L' results in (2-2, 0) = (0,0).
    //
    // In all these cases, the existence of the specific move type (U, D, L, or R)
    // is guaranteed by the fact that the coordinate is non-zero in that direction.
    // For example, if Y_orig = 2, it means there were more 'U' moves than 'D' moves,
    // so there must be at least one 'U' to change.

    // Check if the calculated final position (x, y) matches any of these conditions
    if ((x == 0 && y == 2) ||    // Condition for changing U to D
        (x == 0 && y == -2) ||   // Condition for changing D to U
        (x == -2 && y == 0) ||   // Condition for changing L to R
        (x == 2 && y == 0)) {    // Condition for changing R to L
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming to speed up I/O operations.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T;
    while (T--) { // Loop through each test case
        solve();
    }

    return 0;
}
```