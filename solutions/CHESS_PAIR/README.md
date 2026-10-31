# [Chess Pairing (CHESS_PAIR)](https://www.codechef.com/problems/CHESS_PAIR)
- **Difficulty Rating**: 892
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem describes a chess tournament with $2N$ players in total. Among these, $X$ players are rated, and the remaining $2N - X$ players are unrated. All $2N$ players are paired up, forming $N$ pairs. The task is to find the minimum possible number of rated players who are paired against another rated player.

## Intuition & Mathematical Observation
The core idea is to minimize the number of rated players paired against other rated players. This is equivalent to maximizing the number of rated players paired against unrated players. Let's denote the number of unrated players as $U = 2N - X$.

We want to form as many Rated-Unrated (R-U) pairs as possible. Each R-U pair uses one rated player and one unrated player.

There are two main scenarios based on the relative counts of rated and unrated players:

**Case 1: Enough Unrated Players ($X \le N$)**
If the number of rated players ($X$) is less than or equal to the number of unrated players ($U$), i.e., $X \le 2N - X$.
This inequality simplifies to $2X \le 2N$, which means $X \le N$.
In this scenario, we have enough unrated players to pair with *all* rated players. We can form $X$ R-U pairs, using all $X$ rated players and $X$ unrated players. The remaining $U - X$ unrated players will then be paired among themselves (forming Unrated-Unrated or U-U pairs).
Since every rated player is paired with an unrated player, no rated player is paired against another rated player.
Therefore, the minimum number of rated players paired against other rated players is **0**.

**Case 2: Not Enough Unrated Players ($X > N$)**
If the number of rated players ($X$) is greater than the number of unrated players ($U$), i.e., $X > 2N - X$.
This inequality simplifies to $2X > 2N$, which means $X > N$.
In this scenario, we don't have enough unrated players to pair with all rated players. To maximize R-U pairs, we use all $U$ unrated players to form $U$ R-U pairs.
After forming these $U$ R-U pairs:
*   All $U$ unrated players are used up.
*   The number of rated players remaining is $X - U$.

These $X - U$ remaining rated players have no unrated opponents left. They *must* be paired among themselves. They will form $(X - U) / 2$ pairs of Rated-Rated (R-R).
Each R-R pair consists of two rated players, both of whom are paired against a rated opponent. Thus, each R-R pair contributes 2 to our count.
The total number of rated players paired against other rated players will be $2 \times (\text{number of R-R pairs})$.
Total count = $2 \times \frac{X - U}{2} = X - U$.

Substituting $U = 2N - X$ into the expression:
Total count = $X - (2N - X)$
Total count = $X - 2N + X$
Total count = $2X - 2N$
Total count = $2(X - N)$

So, in this case, the minimum number of rated players paired against other rated players is $2(X - N)$.

Combining both cases, the solution depends on whether $X \le N$ or $X > N$.

## Complexity Analysis
-   **Time Complexity**: The `solve()` function performs a constant number of operations (reading two integers, a conditional check, and simple arithmetic). The `main()` function calls `solve()` `T` times. Therefore, the total time complexity is $O(T)$, where $T$ is the number of test cases.
-   **Space Complexity**: The solution uses a fixed number of integer variables (`N`, `X`, `T`) regardless of the input size. Thus, the space complexity is $O(1)$.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace for convenience in competitive programming
using namespace std;

void solve() {
    int N, X;
    cin >> N >> X; // Read N and X for the current test case

    // Total players = 2N
    // Rated players = X
    // Unrated players = 2N - X

    // We want to minimize the number of rated players whose opponents are also rated.
    // This is achieved by maximizing the number of Rated-Unrated (R-U) pairs.

    // Case 1: If the number of rated players (X) is less than or equal to
    // the number of unrated players (2N - X).
    // This simplifies to X <= N.
    // In this scenario, we can pair every rated player with an unrated player.
    // No rated player will have a rated opponent.
    if (X <= N) {
        cout << 0 << "\n";
    }
    // Case 2: If the number of rated players (X) is greater than
    // the number of unrated players (2N - X).
    // This simplifies to X > N.
    // In this scenario, we use all (2N - X) unrated players to form R-U pairs.
    // This leaves X - (2N - X) = 2X - 2N rated players without an unrated opponent.
    // These remaining (2X - 2N) rated players must be paired among themselves.
    // They will form (2X - 2N) / 2 = X - N pairs of Rated-Rated (R-R).
    // Each R-R pair consists of two rated players, both of whom have rated opponents.
    // So, each R-R pair contributes 2 to our count.
    // The total count is 2 * (number of R-R pairs) = 2 * (X - N).
    else { // X > N
        cout << 2 * (X - N) << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times, solving each test case
        solve();
    }

    return 0; // Indicate successful execution
}
```