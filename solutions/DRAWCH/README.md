# [Drawing Chances (DRAWCH)](https://www.codechef.com/problems/DRAWCH)
- **Difficulty Rating**: 945
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if it's possible for Alice and Bob to end up with an equal number of wins after a total of `N` matches. We are given the total number of matches `N`, the number of matches already played `M`, and a string `S` of length `M` representing the outcomes of the played matches. '1' in `S` means Alice won that match, and '0' means Bob won. We need to output "Yes" if a tie is possible, and "No" otherwise.

## Intuition & Mathematical Observation

To achieve a tie, Alice and Bob must have an equal number of wins after all `N` matches are played. Let `A_total` be Alice's total wins and `B_total` be Bob's total wins.

1.  **Total Matches Must Be Even**: If `A_total = B_total`, then `A_total + B_total = N` implies `2 * A_total = N`. This means `N` must be an even number. If `N` is odd, it's impossible for both players to have an equal number of wins, so a tie is impossible. This is our first condition.

2.  **Current State Analysis**:
    *   First, we count Alice's wins from the `M` played matches. Let this be `alice_wins_M`.
    *   Bob's wins from the `M` played matches will then be `bob_wins_M = M - alice_wins_M`.
    *   The number of remaining matches is `remaining_matches = N - M`.

3.  **Bridging the Score Difference**:
    Let `current_diff = alice_wins_M - bob_wins_M`. This is the current difference in scores.
    To achieve a tie, the players must adjust their scores in the `remaining_matches` such that their final scores are equal.
    The maximum number of matches Alice can win in the remaining `R` matches is `R` (by winning all of them).
    The maximum number of matches Bob can win in the remaining `R` matches is `R` (by winning all of them).

    Consider the absolute difference in current scores: `abs(current_diff) = abs(alice_wins_M - bob_wins_M)`.
    *   If Alice is currently ahead by `X` points (`current_diff = X > 0`), Bob needs to win enough matches to close this gap. In the `remaining_matches`, Bob can win at most `R` matches more than Alice (if Bob wins all `R` and Alice wins 0). This means Bob can reduce Alice's lead by at most `R`. So, if `X > R`, Bob cannot catch up, and a tie is impossible.
    *   Similarly, if Bob is currently ahead by `Y` points (`current_diff = -Y < 0`), Alice needs to win enough matches. Alice can win at most `R` matches more than Bob in the `remaining_matches`. If `Y > R`, Alice cannot catch up, and a tie is impossible.

    Combining these, the absolute difference in current scores must be less than or equal to the number of remaining matches: `abs(alice_wins_M - bob_wins_M) <= remaining_matches`. This is our second condition.

If both conditions are met, then a tie is possible. Otherwise, it's not.

**Example**:
`N=4, M=1, S="1"`
1.  `N=4` is even. Condition 1 met.
2.  `alice_wins_M = 1`, `bob_wins_M = 0`. `current_diff = 1 - 0 = 1`.
    `remaining_matches = N - M = 4 - 1 = 3`.
    `abs(current_diff) = 1`. `remaining_matches = 3`.
    `1 <= 3`. Condition 2 met.
    Output: "Yes". (Alice has 1 win, Bob 0. 3 matches left. Alice can win 1, Bob 2. Total: Alice 2, Bob 2. Tie!)

`N=2, M=1, S="1"`
1.  `N=2` is even. Condition 1 met.
2.  `alice_wins_M = 1`, `bob_wins_M = 0`. `current_diff = 1 - 0 = 1`.
    `remaining_matches = N - M = 2 - 1 = 1`.
    `abs(current_diff) = 1`. `remaining_matches = 1`.
    `1 <= 1`. Condition 2 met.
    Output: "Yes". (Alice has 1 win, Bob 0. 1 match left. Bob wins it. Total: Alice 1, Bob 1. Tie!)

`N=3, M=1, S="1"`
1.  `N=3` is odd. Condition 1 NOT met.
    Output: "No".

## Complexity Analysis

-   **Time Complexity**:
    -   Reading `N`, `M`, and the string `S` takes `O(M)` time, as `S` has length `M`.
    -   Iterating through the string `S` to count Alice's wins takes `O(M)` time.
    -   All subsequent calculations (differences, remaining matches, parity checks) are constant time operations, `O(1)`.
    -   Therefore, for each test case, the time complexity is dominated by reading and processing the string `S`, which is `O(M)`.
    -   Given `T` test cases, the total time complexity is $O(T \cdot M)$.

-   **Space Complexity**:
    -   Storing the input string `S` requires `O(M)` space.
    -   All other variables (integers `N`, `M`, `alice_wins_M`, `bob_wins_M`, etc.) require `O(1)` space.
    -   Thus, the total space complexity is $O(M)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, string, cmath, etc.

// Using namespace std; is requested by the problem statement.
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;

    int alice_wins_M = 0;
    // Count Alice's wins from the already played matches
    for (char c : S) {
        if (c == '1') {
            alice_wins_M++;
        }
    }

    // Bob's wins from the already played matches can be derived
    int bob_wins_M = M - alice_wins_M;

    // Condition 1: Total number of matches N must be even for a tie to be possible.
    // If N is odd, it's impossible to have equal wins for Alice and Bob.
    if (N % 2 != 0) {
        cout << "No\n";
        return;
    }

    // Condition 2: The absolute difference in current wins must be less than or equal to
    // the number of remaining matches.
    // Let R be the number of remaining matches.
    // To achieve a tie, the current difference in scores must be bridgeable within R matches.
    // The maximum difference that can be made up is R (if one player wins all R matches).
    int remaining_matches = N - M;
    int current_diff = abs(alice_wins_M - bob_wins_M);

    if (current_diff <= remaining_matches) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    // Fast I/O setup as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve();
    }

    return 0;
}
```