# [Add 1 or 2 Game (ADD12GAME)](https://www.codechef.com/problems/ADD12GAME)
- **Difficulty Rating**: 1030
- **Solved in**: 1 attempt(s)

## Problem Summary

This problem describes a game played by two players, Alice and Bob. They start with a sum $X=0$. Their goal is to reach a target sum $N$. In each turn, a player can add either 1 or 2 to the current sum $X$.

The game ends under two conditions:
1.  If the sum $X$ becomes *exactly* $N$, Bob wins.
2.  If the sum $X$ becomes *greater than* $N$, Alice wins.

Both Alice and Bob play optimally, meaning they will always make a move that leads to their win if possible, or force a loss for their opponent otherwise. Alice goes first. We need to determine who wins the game.

## Intuition & Mathematical Observation

This is a classic impartial game theory problem, which can be solved using dynamic programming or recursion with memoization. The key characteristics are:
1.  **Finite States**: The game state is defined by the current sum $X$ and whose turn it is. Since $X$ starts at 0 and goes up to $N+2$ (as $N+1$ or $N+2$ are possible terminal states), and there are two players, the number of states is finite and relatively small ($2 \times (N+3)$ states).
2.  **Optimal Play**: Both players play optimally. This suggests a minimax-like approach.
3.  **Terminal States**: The game ends when $X \ge N$.
    *   If $X = N$: Bob wins.
    *   If $X > N$: Alice wins.

Let's define a function `solve(current_X, is_alice_turn)` that returns the winner of the game starting from `current_X` with `is_alice_turn` indicating whose turn it is.

**Base Cases (Terminal States):**
When `current_X >= N`:
*   If `current_X == N`: The game has ended with the sum exactly $N$. According to the rules, Bob wins. So, `solve` should return "BOB".
*   If `current_X > N`: The game has ended with the sum greater than $N$. According to the rules, Alice wins. So, `solve` should return "ALICE".

**Recursive Step (Non-Terminal States):**

*   **If it's Alice's turn (`is_alice_turn = true`):**
    Alice wants to win. She will win if she can make *any* move (add 1 or add 2) that leads to a state from which *she* ultimately wins.
    *   Option 1: Alice adds 1. The new state is `(current_X + 1, false)` (Bob's turn). Let `winner_if_plus_1 = solve(current_X + 1, false)`.
    *   Option 2: Alice adds 2. The new state is `(current_X + 2, false)` (Bob's turn). Let `winner_if_plus_2 = solve(current_X + 2, false)`.
    *   If `winner_if_plus_1 == "ALICE"` OR `winner_if_plus_2 == "ALICE"`, then Alice can force a win. So, `solve` returns "ALICE".
    *   Otherwise (if both moves lead to Bob winning), Alice cannot force a win, so Bob wins. `solve` returns "BOB".

*   **If it's Bob's turn (`is_alice_turn = false`):**
    Bob wants to win. He will win if he can make *any* move (add 1 or add 2) that leads to a state from which *he* ultimately wins.
    *   Option 1: Bob adds 1. The new state is `(current_X + 1, true)` (Alice's turn). Let `winner_if_plus_1 = solve(current_X + 1, true)`.
    *   Option 2: Bob adds 2. The new state is `(current_X + 2, true)` (Alice's turn). Let `winner_if_plus_2 = solve(current_X + 2, true)`.
    *   If `winner_if_plus_1 == "BOB"` OR `winner_if_plus_2 == "BOB"`, then Bob can force a win. So, `solve` returns "BOB".
    *   Otherwise (if both moves lead to Alice winning), Bob cannot force a win, so Alice wins. `solve` returns "ALICE".

**Memoization:**
To avoid recomputing the same states, we use a `map<pair<int, bool>, string>` (or `unordered_map`) to store the results of `solve(current_X, is_alice_turn)`. Before computing a state, we check if its result is already in the map. If yes, we return the stored value. Otherwise, we compute it and store it before returning.

The game starts with `X=0` and Alice's turn, so we call `solve(0, true)`.

## Complexity Analysis

Let $N$ be the target sum.

*   **Time Complexity**: $O(N \log N)$ per test case.
    *   The number of unique states `(current_X, is_alice_turn)` is approximately $2 \times (N+3)$. `current_X` ranges from $0$ to $N+2$.
    *   Each state is computed at most once due to memoization.
    *   For each state, we perform a constant number of operations (map lookups/insertions, comparisons, recursive calls).
    *   Using `std::map<pair<int, bool>, string>` for memoization, each lookup/insertion operation takes $O(\log S)$ time, where $S$ is the number of states. Since $S \approx 2N$, each state computation takes $O(\log N)$ time.
    *   Therefore, the total time complexity is $O(N \log N)$. If `std::unordered_map` were used (with a custom hash for `pair`), the average time complexity would be $O(N)$. Given $N \le 1000$, $O(N \log N)$ is perfectly acceptable.

*   **Space Complexity**: $O(N)$ per test case.
    *   The `memo` map stores results for up to $2 \times (N+3)$ states. Each entry stores an `int`, a `bool`, and a small `string`. This contributes $O(N)$ space.
    *   The maximum depth of the recursion stack can be up to $N+2$ (e.g., if players always add 1). This also contributes $O(N)$ space.
    *   Therefore, the total space complexity is $O(N)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries, as per instruction
using namespace std;     // As per instruction

// N_global stores the current N for the test case.
// Using a global variable for N is acceptable in competitive programming for simplicity
// when N is constant for a given test case and passed implicitly to recursive calls.
int N_global;

// memo stores results of subproblems to avoid recomputing.
// The key is a pair: {current_X, is_alice_turn}.
// current_X: The current sum of X.
// is_alice_turn: true if it's Alice's turn, false if it's Bob's turn.
// The value is a string: "ALICE" or "BOB", indicating the ultimate winner of the game
// starting from that state, assuming optimal play.
map<pair<int, bool>, string> memo;

// solve function determines the winner of the game starting from current_X with
// the given player's turn.
string solve(int current_X, bool is_alice_turn) {
    // Base case: The game ends when current_X reaches or exceeds N_global.
    if (current_X >= N_global) {
        if (current_X == N_global) {
            // If the final sum is exactly N, Bob wins.
            return "BOB";
        } else {
            // If the final sum is greater than N, Alice wins.
            return "ALICE";
        }
    }

    // Memoization check: If this state has been computed before, return the stored result.
    pair<int, bool> state = {current_X, is_alice_turn};
    if (memo.count(state)) {
        return memo[state];
    }

    if (is_alice_turn) {
        // It's Alice's turn. Alice plays optimally to make herself win.
        // Alice wins if she can make ANY move (add 1 or add 2) that leads to a state
        // from which ALICE ultimately wins.
        
        // Option 1: Alice adds 1 to X.
        // The game proceeds with X = current_X + 1, and it becomes Bob's turn.
        string winner_if_plus_1 = solve(current_X + 1, false);
        bool alice_can_win_by_plus_1 = (winner_if_plus_1 == "ALICE");

        // Option 2: Alice adds 2 to X.
        // The game proceeds with X = current_X + 2, and it becomes Bob's turn.
        string winner_if_plus_2 = solve(current_X + 2, false);
        bool alice_can_win_by_plus_2 = (winner_if_plus_2 == "ALICE");

        // If Alice can win by either adding 1 or adding 2, she chooses that move and wins.
        if (alice_can_win_by_plus_1 || alice_can_win_by_plus_2) {
            return memo[state] = "ALICE";
        } else {
            // If both of Alice's moves lead to a state where Bob ultimately wins,
            // then Alice cannot force a win, so Bob wins.
            return memo[state] = "BOB";
        }
    } else { // It's Bob's turn
        // Bob plays optimally to make himself win.
        // Bob wins if he can make ANY move (add 1 or add 2) that leads to a state
        // from which BOB ultimately wins.

        // Option 1: Bob adds 1 to X.
        // The game proceeds with X = current_X + 1, and it becomes Alice's turn.
        string winner_if_plus_1 = solve(current_X + 1, true);
        bool bob_can_win_by_plus_1 = (winner_if_plus_1 == "BOB");

        // Option 2: Bob adds 2 to X.
        // The game proceeds with X = current_X + 2, and it becomes Alice's turn.
        string winner_if_plus_2 = solve(current_X + 2, true);
        bool bob_can_win_by_plus_2 = (winner_if_plus_2 == "BOB");

        // If Bob can win by either adding 1 or adding 2, he chooses that move and wins.
        if (bob_can_win_by_plus_1 || bob_can_win_by_plus_2) {
            return memo[state] = "BOB";
        } else {
            // If both of Bob's moves lead to a state where Alice ultimately wins,
            // then Bob cannot force a win, so Alice wins.
            return memo[state] = "ALICE";
        }
    }
}

// Function to handle a single test case.
void solve_test_case() {
    cin >> N_global;
    memo.clear(); // Clear the memoization table for the new test case.
                  // This is crucial for correctness when N_global changes.
    
    // Start the game from X=0, with Alice taking the first turn.
    cout << solve(0, true) << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T;
    while (T--) {
        solve_test_case();
    }

    return 0;
}
```