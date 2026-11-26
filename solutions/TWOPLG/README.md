# [Two Pile Game (TWOPLG)](https://www.codechef.com/problems/TWOPLG)
- **Difficulty Rating**: 1189
- **Solved in**: 1 attempt(s)

## Problem Summary

Alice and Bob play a game with two piles of items: one with `X` biscuits and another with `Y` cakes. Alice goes first.
In each turn, a player can choose one of three moves:
1.  **Eat one biscuit**: The number of biscuits `X` becomes `X-1`.
2.  **Eat one biscuit and one cake**: `X` becomes `X-1`, `Y` becomes `Y-1`.
3.  **Eat one cake and add one biscuit**: `X` becomes `X+1`, `Y` becomes `Y-1`.

A player loses if they cannot make any valid move. This occurs when `X=0` (no biscuits for move 1) and `Y=0` (no cakes for moves 2 and 3). Both players play optimally. The task is to determine the winner.

## Intuition & Mathematical Observation

This is a classic impartial game. In such games, the winning strategy often depends on identifying "P-positions" (previous player wins, meaning the current player loses) and "N-positions" (next player wins, meaning the current player wins).

Let's analyze the effect of each move on the number of biscuits (`X`) and cakes (`Y`):

1.  **Move 1: (X-1, Y)**
    *   `X` changes parity (if `X` was odd, it becomes even; if `X` was even, it becomes odd).
    *   `Y` remains unchanged.
2.  **Move 2: (X-1, Y-1)**
    *   `X` changes parity.
    *   `Y` changes.
3.  **Move 3: (X+1, Y-1)**
    *   `X` changes parity.
    *   `Y` changes.

A crucial observation is that **all three possible moves change the parity of `X`**. The value of `Y` always decreases or stays the same, but its exact value doesn't directly influence the parity of `X`. The game ends when `X=0` and `Y=0`.

Let's consider the game state based solely on the parity of `X`:

*   **If `X` is odd (N-position for the current player):**
    If it's Alice's turn and `X` is odd, any move she makes will result in a state where `X` is even (`X-1` or `X+1` will be even). If a state with an even `X` is a P-position (meaning the player whose turn it is *loses* from that state), then Alice can always move to a P-position, guaranteeing her win. Thus, if `X` is odd, Alice wins.

*   **If `X` is even (P-position for the current player):**
    If it's Alice's turn and `X` is even, any move she makes will result in a state where `X` is odd (`X-1` or `X+1` will be odd). If a state with an odd `X` is an N-position (meaning the player whose turn it is *wins* from that state), then Alice is forced to move to an N-position for Bob. This means Bob will win from that state, and Alice will lose. Thus, if `X` is even, Bob wins.

**Proof by Induction:**

*   **Base Case:** The losing state is `(0, 0)`. Here, `X=0`, which is an even number. According to our hypothesis, if `X` is even, the current player loses (it's a P-position). This is consistent, as the player whose turn it is at `(0,0)` cannot make a move and thus loses.

*   **Inductive Step:**
    *   Assume that for any state `(X', Y')` where `X'` is odd, it's an N-position (the current player wins).
    *   Assume that for any state `(X'', Y'')` where `X''` is even, it's a P-position (the current player loses).

    *   **Consider a state `(X, Y)` where `X` is odd:**
        Any move the current player makes (if possible) leads to a state `(X_new, Y_new)` where `X_new` is even. By our inductive hypothesis, all states with an even number of biscuits are P-positions. This means the *next* player (who receives the even `X_new` state) will lose. Since the current player can always move to a state where the next player loses, the current state `(X, Y)` (with `X` odd) is an N-position.

    *   **Consider a state `(X, Y)` where `X` is even:**
        Any move the current player makes (if possible) leads to a state `(X_new, Y_new)` where `X_new` is odd. By our inductive hypothesis, all states with an odd number of biscuits are N-positions. This means the *next* player (who receives the odd `X_new` state) will win. Since all possible moves lead to states where the next player wins, the current state `(X, Y)` (with `X` even) is a P-position.

This inductive proof confirms that the winner is solely determined by the parity of `X` at the start of the game:
*   If `X` is odd, Alice wins.
*   If `X` is even, Bob wins.

The constraints on `Y` (i.e., `Y` must be positive for moves 2 and 3) do not change the parity argument. Even if `Y=0`, and `X` is even, Alice can only make Move 1 (if `X>0`), leading to `X-1` (odd). If `X=0` and `Y=0`, Alice loses, which is consistent with `X` being even. If `X` is odd and `Y=0`, Alice can make Move 1, leading to `X-1` (even), which is a P-position for Bob, so Alice wins.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    For each test case, the solution performs a constant number of operations: reading two `long long` integers, performing a modulo operation, and printing a string. These operations take constant time. Since there are `T` test cases, the total time complexity is directly proportional to `T`.

*   **Space Complexity**: $O(1)$
    The solution uses a few variables (`T`, `X`, `Y`) to store input and loop counters. The amount of memory used does not depend on the input values `X` or `Y`, nor on the number of test cases `T` (beyond storing `T` itself). Thus, the space complexity is constant.

## Solution Code

```cpp
#include <iostream> // Required for standard input/output operations

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming to prevent Time Limit Exceeded (TLE)
    // on problems with large numbers of test cases or large inputs.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Declare an integer variable 'T' to store the number of test cases.
    std::cin >> T; // Read the number of test cases from standard input.

    // Loop through each test case. The loop continues as long as T is greater than 0,
    // and T is decremented in each iteration.
    while (T--) {
        long long X, Y; // Declare two long long variables 'X' and 'Y'
                        // to store the initial number of biscuits and cakes.
                        // 'long long' is used because X and Y can be up to 10^9.
        std::cin >> X >> Y; // Read the values of X and Y for the current test case.

        // The winner is determined by the parity of X.
        // If X is odd, Alice wins.
        // If X is even, Bob wins.
        // This is proven by induction as explained in the problem analysis.
        //
        // If X is odd, Alice can always make Move 1 (eat one biscuit).
        // This changes X to X-1, which is an even number.
        // By induction, a state with an even number of biscuits is a P-position (previous player wins).
        // So, Alice moves to a P-position, meaning she wins.
        //
        // If X is even, any move Alice makes will result in a state where the number of biscuits X' is odd:
        // - Move 1: (X-1, Y) -> X-1 is odd.
        // - Move 2: (X-1, Y-1) -> X-1 is odd.
        // - Move 3: (X+1, Y-1) -> X+1 is odd.
        // By induction, a state with an odd number of biscuits is an N-position (next player wins).
        // Since all of Alice's moves lead to N-positions, the current state (X, Y) is a P-position.
        // Thus, Bob wins.
        // This logic holds even for edge cases like X=0 or Y=0.

        if (X % 2 == 1) { // Check if X is odd (remainder is 1 when divided by 2).
            std::cout << "Alice\n"; // If X is odd, Alice wins. Print "Alice".
        } else { // If X is not odd, it must be even.
            std::cout << "Bob\n"; // If X is even, Bob wins. Print "Bob".
        }
    }

    return 0; // Indicate that the program executed successfully.
}
```