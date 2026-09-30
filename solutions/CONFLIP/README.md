```markdown
# [Coin Flip (CONFLIP)](https://www.codechef.com/problems/CONFLIP)
- **Difficulty Rating**: 1135
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to simulate a series of coin-flipping games. For each game, we are given:
1.  `I`: The initial state of all coins (1 for Heads, 2 for Tails).
2.  `N`: The total number of coins in the game.
3.  `Q`: The query state (1 for Heads, 2 for Tails).

In each game, there are `N` coins. For the `k`-th coin (where `k` ranges from 1 to `N`), it is flipped exactly `k` times. After all coins have been flipped according to this rule, we need to determine how many coins end up in the state specified by `Q`. This process is repeated for `G` different games, and for each game, we output the count.

## Intuition & Mathematical Observation

The core of this problem lies in understanding the effect of flipping a coin a certain number of times.

1.  **Effect of Flipping:**
    *   If a coin is flipped an **even** number of times, it returns to its **initial state**. For example, if it starts as Heads and is flipped twice, it goes Heads -> Tails -> Heads.
    *   If a coin is flipped an **odd** number of times, it ends up in the **opposite state** from its initial state. For example, if it starts as Heads and is flipped once, it goes Heads -> Tails. If flipped thrice, Heads -> Tails -> Heads -> Tails.

2.  **Applying to the Problem:**
    For each coin `k` (from 1 to `N`), it is flipped `k` times.
    *   If `k` is an **odd** number, coin `k` will end up in the **opposite state** from its initial state `I`.
    *   If `k` is an **even** number, coin `k` will end up in its **initial state** `I`.

Now, let's analyze the distribution of coins based on `N`:

### Case 1: `N` is an Even Number

If `N` is even, the coins are `1, 2, 3, ..., N`.
*   The odd-numbered coins are `1, 3, 5, ..., N-1`. There are `N/2` such coins. Each of these coins is flipped an odd number of times, so they all end up in the **opposite state** from `I`.
*   The even-numbered coins are `2, 4, 6, ..., N`. There are `N/2` such coins. Each of these coins is flipped an even number of times, so they all end up in their **initial state** `I`.

Therefore, when `N` is even, there will always be `N/2` coins in the initial state `I` and `N/2` coins in the opposite state. Regardless of whether `Q` is `I` or the opposite of `I`, the count of coins ending in state `Q` will always be `N/2`.

### Case 2: `N` is an Odd Number

If `N` is odd, the coins are `1, 2, 3, ..., N`.
*   The odd-numbered coins are `1, 3, 5, ..., N`. There are `(N+1)/2` such coins. Each of these coins is flipped an odd number of times, so they all end up in the **opposite state** from `I`.
*   The even-numbered coins are `2, 4, 6, ..., N-1`. There are `(N-1)/2` such coins. Each of these coins is flipped an even number of times, so they all end up in their **initial state** `I`.

Now, we need to consider the query state `Q`:
*   If `Q` is the same as the initial state `I` (i.e., `I == Q`): We want to count coins that end up in their initial state. This count is `(N-1)/2`.
*   If `Q` is different from the initial state `I` (i.e., `I != Q`): We want to count coins that end up in the opposite state. This count is `(N+1)/2`.

This logic covers all scenarios and allows us to calculate the answer in constant time for each game.

## Complexity Analysis

*   **Time Complexity**: $O(G)$ per test case.
    For each test case, we iterate `G` times. Inside the loop, we perform a few constant-time operations (reading inputs, comparisons, arithmetic divisions). Thus, the time complexity for one test case is directly proportional to `G`.
    Given `T` test cases, the total time complexity is $O(T \cdot G)$. With $T \le 1000$ and $G \le 10^5$, the maximum total operations are approximately $1000 \times 10^5 = 10^8$, which is acceptable for typical time limits (usually 1-2 seconds).

*   **Space Complexity**: $O(1)$.
    The solution only uses a few integer variables to store `G, I, N, Q, T`. No data structures that grow with input size are used.

## Solution Code

```cpp
#include <bits/stdc++.h> // Required by problem statement

// Using namespace std; as requested by problem statement
using namespace std;

void solve() {
    int G;
    cin >> G; // Read the number of games
    while (G--) {
        long long I, N, Q; // N can be up to 10^9, fits in int. Using long long for N, I, Q just to be absolutely safe, though int is sufficient for all.
        cin >> I >> N >> Q; // Read initial state, number of coins/rounds, and query type

        if (N % 2 == 0) {
            // If N is an even number:
            // There are N/2 coins that are flipped an odd number of times (ending in opposite state)
            // and N/2 coins that are flipped an even number of times (ending in initial state).
            // This means there will always be N/2 Heads and N/2 Tails, regardless of the initial state (I)
            // or the specific face being queried (Q).
            cout << N / 2 << "\n";
        } else {
            // If N is an odd number:
            // There are (N+1)/2 coins that are flipped an odd number of times (ending in opposite state)
            // and (N-1)/2 coins that are flipped an even number of times (ending in initial state).

            if (I == Q) {
                // If the initial state (I) is the same as the queried state (Q):
                // We want to count coins that end up in their initial state.
                // This count is (N-1)/2.
                cout << (N - 1) / 2 << "\n";
            } else {
                // If the initial state (I) is different from the queried state (Q):
                // We want to count coins that end up in the opposite state.
                // This count is (N+1)/2.
                cout << (N + 1) / 2 << "\n";
            }
        }
    }
}

int main() {
    // Fast I/O setup as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}
```