# [Swish Game (SWISHGAME)](https://www.codechef.com/problems/SWISHGAME)
- **Difficulty Rating**: 1188
- **Solved in**: 1 attempt(s)

## Problem Summary

Toofan plays a game involving `N` rings. He wins if he makes at least `K` "swishes". The game ends under one of three conditions:
1.  Toofan achieves `K` or more swishes (he wins).
2.  It becomes mathematically impossible for Toofan to achieve `K` swishes, even if he makes a swish on every remaining ring.
3.  All `N` rings have been played.

We are given `M`, the number of rings played so far, and a string `S` of length `M` representing the outcomes of these `M` rings ('S' for swish, 'F' for fail). Our task is to determine the total number of rings `N`. It is guaranteed that `N` is unique.

## Intuition & Mathematical Observation

Let `swishes_M` be the number of 'S' (swishes) in the given string `S` of length `M`. We need to find `N`, the total number of rings. The problem statement implies that the game *has already ended* after `M` rings, and we need to find the `N` that makes this true.

We can analyze two main scenarios based on Toofan's current swish count:

**Case 1: Toofan has already achieved `K` or more swishes (`swishes_M >= K`).**
If Toofan has already reached or exceeded `K` swishes after `M` rings, he has won. The problem states the game ends when he wins, or when it's impossible to win, or when all `N` rings are played. If he has won, and the game has ended, it implies that all `N` rings must have been played. If `M < N`, the game would continue even after he wins until all `N` rings are played. Therefore, if `swishes_M >= K`, it must be that `M = N`.
*   **Conclusion for Case 1: If `swishes_M >= K`, then `N = M`.**

**Case 2: Toofan has less than `K` swishes (`swishes_M < K`).**
In this scenario, Toofan has not yet won. Since the game has ended, it must have ended because either:
    a. It became impossible for him to win.
    b. All `N` rings were played, and he still hadn't won.

Let's focus on condition (a): "It became impossible to win."
This means that even if Toofan makes a swish on *every single one* of the remaining `N - M` rings, his total swish count would still be less than `K`.
The maximum possible total swishes he could achieve is `swishes_M` (from the first `M` rings) + `(N - M)` (if all remaining `N-M` rings are swishes).
So, the condition for impossibility is:
`swishes_M + (N - M) < K`

We need to find `N`. Let's rearrange the inequality to solve for `N`:
`N - M < K - swishes_M`
`N < M + K - swishes_M`

Since `N` must be an integer, the largest possible integer `N` that satisfies this strict inequality is:
`N = M + K - swishes_M - 1`

The problem guarantees that `N` is unique. This implies that if `swishes_M < K`, the game *must* have ended because it became impossible to win, and the derived formula `N = M + K - swishes_M - 1` gives the correct total number of rings. This formula also correctly handles the sub-case where `M=N` and `swishes_M < K` (which implies `swishes_M = K-1` for the formula to yield `N=M`).

**Example Walkthrough:**
Let `M = 3`, `K = 5`, `S = "SFS"`.
1.  Count `swishes_M`: `S` has two 'S's, so `swishes_M = 2`.
2.  Compare `swishes_M` with `K`: `2 < 5`, so we are in Case 2.
3.  Apply the formula: `N = M + K - swishes_M - 1`
    `N = 3 + 5 - 2 - 1`
    `N = 8 - 2 - 1`
    `N = 5`
    To verify: If `N=5`, then `M=3` rings are played, `N-M=2` rings remain. Current swishes `2`. Max possible swishes `2 + 2 = 4`. Since `4 < K (5)`, it is indeed impossible to win, so `N=5` is correct.

## Complexity Analysis

*   **Time Complexity**:
    *   Reading `M`, `K`, and the string `S` takes `O(M)` time.
    *   Counting `swishes_M` involves iterating through the string `S` of length `M`, which takes `O(M)` time.
    *   The arithmetic calculation and printing take `O(1)` time.
    *   Therefore, for a single test case, the time complexity is dominated by string processing, resulting in **$O(M)$**.
    *   Given `T` test cases, the total time complexity is **$O(T \cdot M_{max})$**, where `M_{max}` is the maximum possible value of `M` across all test cases.

*   **Space Complexity**:
    *   Storing `M`, `K`, `swishes_M` requires `O(1)` space.
    *   Storing the input string `S` requires `O(M)` space.
    *   Therefore, for a single test case, the space complexity is **$O(M)$**.
    *   Since the string `S` is read for each test case, the memory is reused. Thus, the overall space complexity is **$O(M_{max})$**.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <algorithm> // For std::count, though a manual loop is also fine

void solve() {
    int M, K;
    std::cin >> M >> K;
    std::string S;
    std::cin >> S;

    int swishes_M = 0;
    // Count the total number of 'S' (swishes) in the string S
    for (char c : S) {
        if (c == 'S') {
            swishes_M++;
        }
    }

    // Case 1: Toofan has already achieved K swishes or more.
    // If swishes_M >= K, Toofan has won. The game must have ended
    // because all N rings were finished. If there were rings left (M < N),
    // the game would continue even after winning until all N rings are played.
    // So, if the game ended after M moves, it means M = N.
    if (swishes_M >= K) {
        std::cout << M << "\n";
    } else {
        // Case 2: Toofan has less than K swishes (swishes_M < K).
        // The game must have ended because it became impossible to win,
        // or because all N rings were finished (and he still hadn't won).
        //
        // Let N be the total number of rings.
        // The game ended after M moves.
        //
        // If M < N, the game ended because it became impossible to win:
        // swishes_M + (N - M) < K
        // This implies N < M + K - swishes_M.
        // The maximum integer N satisfying this is M + K - swishes_M - 1.
        //
        // If M = N, the game ended because all rings were finished.
        // In this scenario, swishes_M + (N - M) = swishes_M. Since swishes_M < K,
        // the impossibility condition (swishes_M < K) is also met.
        // This case occurs when swishes_M = K-1, and the formula
        // M + K - swishes_M - 1 simplifies to M + K - (K-1) - 1 = M.
        //
        // The problem guarantees a unique N. This means the derived value
        // N = M + K - swishes_M - 1 must be the correct answer, and it
        // implicitly satisfies all conditions (e.g., game not ending prematurely).
        std::cout << M + K - swishes_M - 1 << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }
    return 0;
}
```