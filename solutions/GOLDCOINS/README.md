# [Gold Coins 101 (GOLDCOINS)](https://www.codechef.com/problems/GOLDCOINS)
- **Difficulty Rating**: 253
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a game between Chef and Chefina where they score goals. We are given the number of gold coins awarded to the winner (`A`) and the loser (`B`). We are also given the goals scored by Chef (`X`) and Chefina (`Y`). It's guaranteed that `X` will not be equal to `Y`. The task is to determine and output the number of gold coins Chef receives. Chef wins if `X > Y`, and loses if `X < Y`.

## Intuition & Mathematical Observation

The problem boils down to a straightforward conditional check. We need to determine if Chef won or lost the game.
1. **Compare Chef's goals (`X`) with Chefina's goals (`Y`)**:
   - If `X > Y`, Chef has scored more goals than Chefina, which means Chef is the winner. In this case, Chef receives `A` gold coins.
   - If `X < Y`, Chef has scored fewer goals than Chefina, which means Chef is the loser. In this case, Chef receives `B` gold coins.

Since the problem statement guarantees that `X != Y`, there is no possibility of a tie, simplifying the logic to just these two cases. There are no complex mathematical operations or data structures required; a simple `if-else` statement is sufficient.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The solution involves reading four integer inputs, performing a single comparison (`X > Y`), and then printing one integer output. All these operations take a constant amount of time, regardless of the magnitude of the input values (within integer limits). Therefore, the time complexity is constant.

-   **Space Complexity**: $O(1)$
    The solution uses a fixed number of integer variables (`A`, `B`, `X`, `Y`) to store the input values. The memory usage does not scale with the input values or any other problem parameter. Thus, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

using namespace std; // Uses the standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare four integer variables to store the input values:
    // A: coins rewarded to the winner
    // B: coins rewarded to the loser
    // X: goals scored by Chef
    // Y: goals scored by Chefina
    int A, B, X, Y;

    // Read the four space-separated integers from the standard input.
    cin >> A >> B >> X >> Y;

    // Determine the winner of the game.
    // The player scoring the maximum goals wins.
    // We need to find out if Chef won or lost to determine the coins Chef receives.
    if (X > Y) {
        // If Chef's goals (X) are greater than Chefina's goals (Y),
        // Chef wins the game.
        // The winner receives A gold coins.
        cout << A << "\n";
    } else {
        // If Chef's goals (X) are not greater than Chefina's goals (Y),
        // and it's given that X != Y, this implies X < Y.
        // Therefore, Chef loses the game.
        // The loser receives B gold coins.
        cout << B << "\n";
    }

    // Return 0 to indicate successful execution of the program.
    return 0;
}
```