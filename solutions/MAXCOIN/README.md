# [Maximum Coins (MAXCOIN)](https://www.codechef.com/problems/MAXCOIN)
- **Difficulty Rating**: 951
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef plays `N` games. Each game `i` (where `i` ranges from 1 to `N`) has a coin value of `2^i`. Chef must win exactly `X` games and lose the remaining `N-X` games. If Chef wins a game, he receives its coin value. If he loses a game, he must pay its coin value. The objective is to determine the maximum total coins Chef can have at the end.

## Intuition & Mathematical Observation

To maximize the total coins, Chef needs to maximize the sum of coins from won games and minimize the sum of coins paid for lost games. This leads to a straightforward greedy strategy:

1.  **Win the games with the highest coin values**: To maximize the gains, Chef should choose the `X` games with the largest `2^i` values to win. These will be games `N, N-1, ..., N-X+1`.
2.  **Lose the games with the lowest coin values**: To minimize the losses, Chef should choose the `N-X` games with the smallest `2^i` values to lose. These will be games `1, 2, ..., N-X`.

Let's denote the sum of coins from won games as `S_win` and the sum of coins paid for lost games as `S_loss`. The total coins will be `S_win - S_loss`.

The coin values are powers of 2: `2^1, 2^2, ..., 2^N`.
We use the formula for the sum of a geometric series: `2^1 + 2^2 + ... + 2^k = 2^(k+1) - 2`.

*   **Calculating `S_win`**:
    The games won are `N, N-1, ..., N-X+1`.
    `S_win = 2^N + 2^(N-1) + ... + 2^(N-X+1)`
    This can be expressed as the sum of all powers of 2 up to `N`, minus the sum of powers of 2 up to `N-X`:
    `S_win = (2^1 + ... + 2^N) - (2^1 + ... + 2^(N-X))`
    Applying the geometric series sum formula:
    `S_win = (2^(N+1) - 2) - (2^(N-X+1) - 2)`
    `S_win = 2^(N+1) - 2^(N-X+1)`

*   **Calculating `S_loss`**:
    The games lost are `1, 2, ..., N-X`.
    `S_loss = 2^1 + 2^2 + ... + 2^(N-X)`
    Applying the geometric series sum formula:
    `S_loss = 2^(N-X+1) - 2`

*   **Calculating Total Coins**:
    `Total Coins = S_win - S_loss`
    `Total Coins = (2^(N+1) - 2^(N-X+1)) - (2^(N-X+1) - 2)`
    `Total Coins = 2^(N+1) - 2 * 2^(N-X+1) + 2`
    `Total Coins = 2^(N+1) - 2^(1 + N-X+1) + 2`
    `Total Coins = 2^(N+1) - 2^(N-X+2) + 2`

This final formula gives the maximum total coins. We use `long long` for calculations involving powers of 2 to prevent overflow, as `N` can be up to 60, making `2^61` a possible value. The bit shift operator `1LL << k` is used to compute `2^k`.

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    The `solve` function involves a few arithmetic operations and bit shifts, all of which take constant time. Reading input and printing output also take constant time. Since the `solve` function is called `T` times, the overall time complexity is $O(T)$.

*   **Space Complexity**: $O(1)$
    The `solve` function uses a fixed number of variables (`N`, `X`, `total_coins`) regardless of the input size. Thus, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Required by problem statement

// Required by problem statement
using namespace std;

void solve() {
    int N, X;
    cin >> N >> X;

    // The strategy to maximize coins is to win the X games with the highest coin values
    // and lose the (N-X) games with the lowest coin values.
    //
    // The coin values are 2^1, 2^2, ..., 2^N.
    //
    // Chef wins games N, N-1, ..., N-X+1.
    // Sum of coins from wins: S_win = 2^N + 2^(N-1) + ... + 2^(N-X+1)
    //
    // Chef loses games 1, 2, ..., N-X.
    // Sum of coins paid for losses: S_loss = 2^1 + 2^2 + ... + 2^(N-X)
    //
    // Total coins = S_win - S_loss.
    //
    // We use the formula for the sum of a geometric series: 2^1 + ... + 2^k = 2^(k+1) - 2.
    //
    // S_win can be written as (2^1 + ... + 2^N) - (2^1 + ... + 2^(N-X)).
    // S_win = (2^(N+1) - 2) - (2^(N-X+1) - 2)
    // S_win = 2^(N+1) - 2^(N-X+1)
    // (This formula holds even if N-X = 0, as 2^1 - 2 = 0.)
    //
    // S_loss = 2^(N-X+1) - 2.
    // (This formula also holds if N-X = 0, as 2^1 - 2 = 0.)
    //
    // Total coins = S_win - S_loss
    // Total coins = (2^(N+1) - 2^(N-X+1)) - (2^(N-X+1) - 2)
    // Total coins = 2^(N+1) - 2 * 2^(N-X+1) + 2
    // Total coins = 2^(N+1) - 2^(N-X+1+1) + 2
    // Total coins = 2^(N+1) - 2^(N-X+2) + 2

    long long total_coins = (1LL << (N + 1)) - (1LL << (N - X + 2)) + 2;
    
    cout << total_coins << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
```