# [Bells of Pilgrimage (PILBELLS)](https://www.codechef.com/problems/PILBELLS)
- **Difficulty Rating**: 885
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the final mana level of a pilgrim after ringing a certain number of bells. We are given:
*   `N`: The total number of bells available.
*   `X`: The number of initial bells that provide a higher mana bonus.
*   `K`: The total number of bells the pilgrim actually rings.
*   `P`: The pilgrim's initial mana level.

The rules for mana gain are:
1.  The first `X` bells rung each provide `+10` mana.
2.  Any bells rung after the first `X` bells (i.e., from `X+1`-th bell up to `K`-th bell) each provide `+5` mana.
3.  If the pilgrim rings all `N` bells (i.e., `K == N`), an additional `+20` mana bonus is awarded.

We need to output the final mana level.

## Intuition & Mathematical Observation

The problem can be solved by directly applying the given rules to calculate the mana. We need to categorize the `K` bells rung into two groups: those that give `+10` mana and those that give `+5` mana.

1.  **Initial Mana**: The pilgrim starts with `P` mana.
2.  **Mana from +10 bells**: The first `X` bells provide `+10` mana. However, the pilgrim only rings `K` bells in total. So, the number of bells that actually contribute `+10` mana is the minimum of `K` (total bells rung) and `X` (the threshold for `+10` mana).
    *   Let `bells_10_count = min(K, X)`.
    *   Mana gained: `bells_10_count * 10`.
3.  **Mana from +5 bells**: These are the bells rung *after* the first `X` bells, up to the `K`-th bell. The number of such bells is simply the total bells rung (`K`) minus the bells that already provided `+10` mana.
    *   Let `bells_5_count = K - bells_10_count`.
    *   Mana gained: `bells_5_count * 5`.
    *   *Self-check*: If `K <= X`, then `bells_10_count` will be `K`. Consequently, `bells_5_count` will be `K - K = 0`, which correctly means no bells beyond the `+10` threshold were rung.
4.  **Bonus Mana**: If the total bells rung (`K`) is equal to the total available bells (`N`), an additional `+20` mana is awarded.
    *   If `K == N`, add `+20`.

By summing the initial mana and all mana gains, we get the final mana level. This approach involves simple arithmetic operations and a conditional check, making it very efficient.

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    For each test case, the solution performs a fixed number of operations: reading four integers, a `min` operation, a few multiplications, additions, subtractions, and a single conditional check. These operations take constant time, irrespective of the input values (within typical integer limits). Therefore, the time complexity per test case is constant.
*   **Space Complexity**: $O(1)$
    The solution uses a few integer variables (`N`, `X`, `K`, `P`, `current_mana`, `bells_10_count`, `bells_5_count`) to store input and intermediate results. The amount of memory used does not depend on the input values, making the space complexity constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, algorithm, etc.
using namespace std;

void solve() {
    int N, X, K, P;
    cin >> N >> X >> K >> P;

    long long current_mana = P; // Initialize with initial mana level

    // Calculate mana from bells that provide +10.
    // These are the first X bells, but we only count up to K bells rung.
    // So, the number of such bells is the minimum of K (bells rung so far) and X (bells that give +10).
    int bells_10_count = min(K, X);
    current_mana += (long long)bells_10_count * 10;

    // Calculate mana from bells that provide +5.
    // These are bells rung after the first X bells, up to K bells.
    // The number of such bells is the total bells rung (K) minus the bells that already provided +10.
    // If K <= X, then bells_10_count will be K, and bells_5_count will be K - K = 0, which is correct.
    int bells_5_count = K - bells_10_count;
    current_mana += (long long)bells_5_count * 5;

    // Add the bonus mana if all N bells have been rung.
    if (K == N) {
        current_mana += 20;
    }

    cout << current_mana << "\n"; // Output the final current mana level
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times to solve each test case
        solve();
    }

    return 0;
}
```