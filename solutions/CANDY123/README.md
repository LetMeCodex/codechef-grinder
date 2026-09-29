# [Bear and Candies 123 (CANDY123)](https://www.codechef.com/problems/CANDY123)
- **Difficulty Rating**: 1028
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a game played by Limak and Bob involving candies. Limak has a maximum capacity `A` for candies, and Bob has a maximum capacity `B`. They take turns eating candies according to a specific rule:
- In turn 1, Limak eats 1 candy.
- In turn 2, Bob eats 2 candies.
- In turn 3, Limak eats 3 candies.
- In turn 4, Bob eats 4 candies.
- And so on... In turn `k`, the current player eats `k` candies.

If a player's total candies eaten would exceed their capacity after eating `k` candies in their turn, they lose the game, and the other player wins. We need to determine the winner of the game for given `A` and `B`.

## Intuition & Mathematical Observation

The game proceeds in a very structured manner: Limak takes odd turns (1, 3, 5, ...) and Bob takes even turns (2, 4, 6, ...). The number of candies eaten in turn `k` is simply `k`. The game ends as soon as one player cannot eat the required number of candies without exceeding their total capacity.

Given that the maximum capacities `A` and `B` are relatively small (up to 1000), the total number of candies eaten will not grow excessively large. The sum of candies eaten up to turn `k` is `1 + 2 + ... + k = k * (k + 1) / 2`. If `A` and `B` are both 1000, the total candies eaten by both players combined can be at most `A + B = 2000`.
We can estimate the maximum number of turns: `k * (k + 1) / 2` should be roughly `2000`. This implies `k^2` is roughly `4000`, so `k` is approximately `sqrt(4000) ≈ 63`. This means the game will end within about 60-70 turns.

This small number of turns makes a direct simulation of the game highly efficient and the most straightforward approach.

The simulation strategy is as follows:
1.  Initialize `current_limak_candies = 0`, `current_bob_candies = 0`, and `turn = 1`.
2.  Enter an infinite loop (`while (true)`), which will be broken when a winner is determined.
3.  Inside the loop:
    *   **If `turn` is odd (Limak's turn):**
        *   Check if `current_limak_candies + turn <= A`.
        *   If true, Limak eats `turn` candies: `current_limak_candies += turn`.
        *   If false, Limak cannot eat `turn` candies. He loses, so Bob wins. Print "Bob" and terminate the function for this test case.
    *   **If `turn` is even (Bob's turn):**
        *   Check if `current_bob_candies + turn <= B`.
        *   If true, Bob eats `turn` candies: `current_bob_candies += turn`.
        *   If false, Bob cannot eat `turn` candies. He loses, so Limak wins. Print "Limak" and terminate the function for this test case.
4.  Increment `turn` for the next round.

This simulation perfectly models the game rules and will correctly identify the winner.

## Complexity Analysis

-   **Time Complexity**: The `solve()` function simulates the game turn by turn. The game ends when the total candies eaten by one player exceeds their capacity. The maximum total candies for both players combined is `A + B`. Since `A, B <= 1000`, `A + B <= 2000`. The sum of candies eaten up to turn `k` is `k * (k + 1) / 2`. For this sum to exceed `2000`, `k` must be approximately `sqrt(2 * 2000) = sqrt(4000) ≈ 63.2`. This means the `while` loop runs at most about 64 times. Each iteration involves a few constant-time arithmetic operations and comparisons. Therefore, the time complexity for a single test case is effectively constant, $O(1)$, as it's bounded by a small constant number of operations regardless of the input values within the given constraints. For `t` test cases, the total time complexity is $O(t)$.

-   **Space Complexity**: The solution uses a fixed number of integer variables (`A`, `B`, `current_limak_candies`, `current_bob_candies`, `turn`, `t`). These variables consume a constant amount of memory, irrespective of the input values. Thus, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream and other standard libraries

// Using namespace std; for convenience as requested
using namespace std;

void solve() {
    int A, B;
    cin >> A >> B; // Read A (Limak's capacity) and B (Bob's capacity) for the current test case

    int current_limak_candies = 0; // Total candies Limak has eaten so far
    int current_bob_candies = 0;   // Total candies Bob has eaten so far
    int turn = 1;                  // Current turn number (1, 2, 3, ...)

    while (true) { // The game continues until a player loses
        if (turn % 2 != 0) { // Limak's turn (odd turn number: 1, 3, 5, ...)
            // Check if Limak can eat 'turn' candies without exceeding his total capacity A
            if (current_limak_candies + turn <= A) {
                current_limak_candies += turn; // Limak eats the candies
            } else {
                // Limak cannot eat 'turn' candies, so he loses. Bob wins.
                cout << "Bob\n";
                return; // End the game for this test case
            }
        } else { // Bob's turn (even turn number: 2, 4, 6, ...)
            // Check if Bob can eat 'turn' candies without exceeding his total capacity B
            if (current_bob_candies + turn <= B) {
                current_bob_candies += turn; // Bob eats the candies
            } else {
                // Bob cannot eat 'turn' candies, so he loses. Limak wins.
                cout << "Limak\n";
                return; // End the game for this test case
            }
        }
        turn++; // Move to the next turn
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases

    while (t--) { // Loop through each test case
        solve(); // Call the solve function to handle the current test case
    }

    return 0; // Indicate successful program execution
}
```