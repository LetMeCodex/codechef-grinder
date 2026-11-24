# [Yet Another Number Game (NUMGAME)](https://www.codechef.com/problems/NUMGAME)
- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary

This problem describes a game played by two players, Alice and Bob, starting with an integer `N`.

The rules are as follows:
1.  Players take turns. Alice goes first.
2.  In each turn, a player chooses a proper divisor `d` of the current number `N`. A proper divisor `d` means `d < N` and `N % d == 0`.
3.  The player then replaces `N` with `N - d`.
4.  The player who cannot make a move loses. This occurs when `N` becomes 1, as 1 has no proper divisors.

The goal is to determine the winner of the game, assuming optimal play from both Alice and Bob.

## Intuition & Mathematical Observation

This is an impartial game, which can often be analyzed using the concepts of P-positions (previous player winning, current player losing) and N-positions (next player winning, current player winning). A position is a P-position if all moves from it lead to N-positions. A position is an N-position if there is at least one move from it that leads to a P-position. The player who cannot make a move loses, meaning `N=1` is a P-position.

Let's analyze the game based on the parity of `N`:

1.  **Base Cases:**
    *   If `N = 1`: No proper divisors. The current player cannot make a move and loses. So, `N=1` is a P-position (Bob wins if Alice starts with 1).
    *   If `N = 2`: The only proper divisor is `d=1`. Alice subtracts 1, `N` becomes `2-1=1`. Since `N=1` is a P-position, Alice has moved to a P-position. Thus, `N=2` is an N-position (Alice wins).
    *   If `N = 3`: The only proper divisor is `d=1`. Alice subtracts 1, `N` becomes `3-1=2`. Since `N=2` is an N-position, Alice has moved to an N-position. As this is the only move, `N=3` is a P-position (Bob wins).
    *   If `N = 4`: Proper divisors are `d=1, 2`.
        *   If Alice chooses `d=1`, `N` becomes `4-1=3`. `N=3` is a P-position.
        *   Since Alice can move to a P-position, `N=4` is an N-position (Alice wins). (She would choose `d=1` to win).

2.  **Generalizing by Parity:**

    *   **Case 1: `N` is an even number.**
        *   Alice can always choose `d=1` as a proper divisor (since `N > 1`, 1 is always a proper divisor).
        *   If Alice subtracts `d=1`, the new number becomes `N - 1`.
        *   Since `N` is even, `N - 1` will be an odd number.
        *   If we can prove that all odd numbers are P-positions (losing positions for the current player), then Alice can always move to a P-position and thus `N` (even) would be an N-position (winning for Alice).

    *   **Case 2: `N` is an odd number.**
        *   Any proper divisor `d` of an odd number `N` must also be odd. (Proof: If `d` were even, then `N = k \times d` would be even, which contradicts `N` being odd).
        *   If Alice subtracts an odd divisor `d` from an odd `N`, the new number becomes `N - d`.
        *   `N - d` will always be an even number (odd - odd = even).
        *   If we can prove that all even numbers are N-positions (winning positions for the current player), then any move Alice makes from an odd `N` leads to an N-position. This means `N` (odd) would be a P-position (losing for Alice, Bob wins).

3.  **Inductive Proof (Combining the above):**
    Let's prove by induction that:
    *   If `N` is even, it's an N-position (Alice wins).
    *   If `N` is odd, it's a P-position (Bob wins).

    *   **Base Cases:** We've already shown this for `N=1, 2, 3, 4`.
        *   `N=1` (odd) is P-position.
        *   `N=2` (even) is N-position.
        *   `N=3` (odd) is P-position.
        *   `N=4` (even) is N-position.

    *   **Inductive Hypothesis:** Assume for all `k < N`, if `k` is even, it's an N-position, and if `k` is odd, it's a P-position.

    *   **Inductive Step for `N`:**
        *   **If `N` is even:**
            *   Alice can choose `d=1` as a proper divisor (since `N > 1`).
            *   The new number is `N - 1`. `N - 1` is odd.
            *   By the inductive hypothesis, `N - 1` is a P-position.
            *   Since Alice can make a move to a P-position, `N` is an N-position.
        *   **If `N` is odd:**
            *   Any proper divisor `d` of `N` must be odd.
            *   The new number is `N - d`. `N - d` is even (odd - odd = even).
            *   By the inductive hypothesis, `N - d` is an N-position.
            *   Since *all* possible moves from `N` lead to N-positions, `N` is a P-position.

**Conclusion:**
The winner of the game depends solely on the parity of the starting number `N`:
*   If `N` is even, Alice wins.
*   If `N` is odd, Bob wins.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    For each of the `T` test cases, the solution performs a single modulo operation (`n % 2`) and a comparison. These operations take constant time. Therefore, the total time complexity is directly proportional to the number of test cases.

*   **Space Complexity**: $O(1)$
    The solution uses a few integer variables (`t`, `n`) to store input and loop counters. The amount of memory used does not depend on the input size `N` or the number of test cases `T`. Thus, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // As requested

// Using namespace std; as requested
using namespace std;

int main() {
    // Fast I/O as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        int n;
        cin >> n; // Read N for each test case

        // The game outcome depends only on the parity of N.
        //
        // If N is even:
        // Alice can always subtract 1 (which is a proper divisor for any N > 1).
        // This move leads to N-1, which is an odd number.
        // As proven by induction, all odd numbers are losing positions.
        // Since Alice can move to a losing position, N is a winning position for Alice.
        // (For N=2, Alice subtracts 1 to get 1. 1 is a losing position. Alice wins.)
        //
        // If N is odd:
        // Any proper divisor 'd' of an odd number N must also be odd.
        // Subtracting an odd divisor 'd' from an odd N results in N-d, which is an even number.
        // As proven by induction, all even numbers are winning positions.
        // Since all possible moves from N lead to winning positions, N is a losing position for Alice.
        // (For N=1, Alice cannot make a move and loses. Bob wins.)
        //
        // Therefore:
        // If N is even, Alice wins.
        // If N is odd, Bob wins.

        if (n % 2 == 0) {
            cout << "ALICE\n";
        } else {
            cout << "BOB\n";
        }
    }

    return 0;
}
```