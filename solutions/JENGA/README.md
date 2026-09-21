# [Jenga Night (JENGA)](https://www.codechef.com/problems/JENGA)
- **Difficulty Rating**: 613
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a Jenga game scenario involving $N$ players and $X$ Jenga tiles. In each round, every player takes exactly one tile. A game is considered "valid" if and only if two conditions are met:
1. All players have a tile in each round.
2. All tiles are used at the end.

We need to determine if a given game configuration (specified by $N$ and $X$) is valid and output "YES" or "NO" accordingly.

## Intuition & Mathematical Observation

Let's analyze the two conditions for a valid Jenga game:

1.  **All players have a tile in each round:**
    In a single round, $N$ players will collectively take $N \times 1 = N$ tiles. For all players to have a tile in *each* round, there must be enough tiles to distribute among all $N$ players for at least one round. This implies that the total number of tiles $X$ must be at least $N$. If $X < N$, it's impossible for all $N$ players to even get one tile in the first round. So, this condition translates to $X \ge N$.

2.  **All tiles are used at the end:**
    Since $N$ tiles are used in each round, if the game runs for $R$ rounds, a total of $R \times N$ tiles are used. For all $X$ tiles to be used exactly at the end, the total number of tiles $X$ must be a perfect multiple of $N$. In other words, $X$ must be perfectly divisible by $N$, which can be expressed mathematically as $X \pmod N = 0$.

**Combining the conditions:**
A game is valid if and only if both $X \ge N$ AND $X \pmod N = 0$.

Let's consider the implications of the second condition, $X \pmod N = 0$:
If $X \pmod N = 0$, it means that $X$ can be written as $X = k \times N$ for some integer $k$.
Given the problem constraints, $N$ and $X$ are positive integers ($1 \le N, X \le 1000$).
Since $N$ and $X$ are positive, $k$ must also be a positive integer.
If $k$ is a positive integer, then the smallest possible value for $k$ is $1$.
Therefore, $X = k \times N \ge 1 \times N = N$.
This observation is crucial: if $X$ is a positive multiple of $N$ (i.e., $X \pmod N = 0$), it automatically implies that $X \ge N$.

**Conclusion:**
The single condition $X \pmod N = 0$ is sufficient to determine if the game is valid. If $X$ is perfectly divisible by $N$, then both conditions are met, and the answer is "YES". Otherwise, if $X$ is not perfectly divisible by $N$, at least one of the conditions (specifically, "all tiles are used at the end") is not met, and the answer is "NO".

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    The program iterates $T$ times for the number of test cases. Inside the loop, it performs a constant number of operations: reading two integers, one modulo operation, and one comparison. These operations take constant time, $O(1)$. Therefore, the total time complexity is directly proportional to the number of test cases, $T$.

-   **Space Complexity**: $O(1)$
    The program uses a fixed number of integer variables ($T$, $N$, $X$) regardless of the input values. The memory usage does not scale with the input size. Hence, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries

// It's common practice in competitive programming to use the entire std namespace
// to avoid repeatedly typing std::
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin/cout from the C standard streams and disables synchronization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int N, X;
        cin >> N >> X; // Read N (number of people) and X (number of tiles)

        // A Jenga game is considered "valid" if two conditions are met:
        // 1. All players have a tile in each round.
        //    This implies that the total number of tiles X must be at least N.
        //    If X < N, there aren't enough tiles for even one round for all N players.
        // 2. All tiles are used at the end.
        //    Since N tiles are used per round (1 tile per player), the total number of tiles X
        //    must be perfectly divisible by N. That is, X % N must be equal to 0.

        // Let's analyze the combined condition:
        // Given the constraints 1 <= N, X <= 1000:
        // Both N and X are positive integers.
        // If X % N == 0, it means X is a positive multiple of N.
        // The smallest positive multiple of N is N itself (when X = 1 * N).
        // Any other positive multiple of N (e.g., 2*N, 3*N, ...) will be greater than N.
        // Therefore, if X % N == 0 and N, X are positive, it automatically implies that X >= N.
        // So, checking only if X is perfectly divisible by N (X % N == 0) is sufficient
        // to satisfy both conditions for a valid game.

        if (X % N == 0) {
            cout << "YES\n"; // If X is a multiple of N, the game is valid
        } else {
            cout << "NO\n";  // Otherwise, the game is not valid
        }
    }

    return 0; // Indicate successful execution
}
```