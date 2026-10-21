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