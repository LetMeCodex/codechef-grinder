# [2 Boxes (BOX2)](https://www.codechef.com/problems/BOX2)
- **Difficulty Rating**: 832
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum number of moves required to reach a state where the absolute difference in the number of stones between two boxes is exactly `K`. We are initially given `X` stones in the first box and `Y` stones in the second box. A single move consists of taking one stone from one box and placing it into the other box.

## Intuition & Mathematical Observation

Let `X'` be the number of stones in the first box and `Y'` be the number of stones in the second box after some moves.

1.  **Constant Total Stones**: A move involves transferring a stone from one box to another. This means the total number of stones across both boxes remains constant. Let `S = X + Y` be the total number of stones. So, `X' + Y' = S`.

2.  **Target Condition**: We want to achieve a state where `|X' - Y'| = K`.

Now, we can substitute `Y' = S - X'` into the target condition:
`|X' - (S - X')| = K`
`|2*X' - S| = K`

This equation implies two possible scenarios:
*   **Scenario 1**: `2*X' - S = K`
    Solving for `X'`: `2*X' = S + K`
    `X' = (S + K) / 2`

*   **Scenario 2**: `2*X' - S = -K` (which is equivalent to `S - 2*X' = K`)
    Solving for `X'`: `2*X' = S - K`
    `X' = (S - K) / 2`

These are the two potential target values for the number of stones in the first box (`X'`). Let's call them `target_X1_A` and `target_X1_B`.

3.  **Condition for Impossibility**:
    For `X'` to be a valid number of stones, it must be an integer. This means that both `(S + K)` and `(S - K)` must be even.
    If `(S + K)` is odd, then `X'` cannot be an integer. `(S + K)` is odd if and only if `S` and `K` have different parities (one is even, the other is odd).
    If `S` and `K` have the same parity (both even or both odd), then `S + K` will be even, and `S - K` will also be even. In this case, integer `X'` values are possible.
    Therefore, if `(S + K) % 2 != 0`, it's impossible to achieve the target difference, and we should output `-1`.

4.  **Calculating Minimum Moves**:
    If a solution is possible, we have two potential target values for `X'`:
    `target_X1_A = (S + K) / 2`
    `target_X1_B = (S - K) / 2`

    Each move changes the number of stones in the first box by exactly `+1` or `-1`. Thus, the number of moves required to change the count of stones in the first box from its current value `X` to a target value `X'` is simply `|X - X'|`.

    We need the *minimum* number of moves, so we calculate the moves for both target possibilities and take the minimum:
    `moves_A = abs(X - target_X1_A)`
    `moves_B = abs(X - target_X1_B)`
    The final answer is `min(moves_A, moves_B)`.

5.  **Data Type Consideration (Important)**:
    The problem constraints state `X, Y, K` can be up to `10^9`.
    `S = X + Y` can be up to `2 * 10^9`. This fits within a standard 32-bit signed `int`.
    However, `S + K` can be up to `2 * 10^9 + 10^9 = 3 * 10^9`. This value *exceeds* the maximum value for a 32-bit signed `int` (approximately `2.147 * 10^9`).
    Therefore, `S` and any intermediate calculations involving `S + K` or `S - K` should use `long long` to prevent integer overflow. The provided solution code uses `int` for these variables, which might pass due to weak test cases or a specific judge environment where `int` is 64-bit. For a robust solution, `long long` is necessary.

## Complexity Analysis

*   **Time Complexity**: The solution involves a fixed number of arithmetic operations (addition, subtraction, division, modulo, absolute value, minimum). These are all constant-time operations. Thus, the `solve()` function runs in $O(1)$ time. Since there are `T` test cases, the total time complexity is $O(T)$.

*   **Space Complexity**: The solution uses a few variables to store `X, Y, K, S`, target values, and move counts. This is a constant amount of memory, independent of the input values. Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, cmath (for abs), algorithm (for min), etc.

// Using namespace std; is requested by the problem statement.
using namespace std;

void solve() {
    int X_int, Y_int, K_int;
    cin >> X_int >> Y_int >> K_int;

    // Use long long for S and intermediate calculations to prevent overflow.
    // X, Y, K can be up to 10^9. S = X + Y can be 2*10^9.
    // S + K can be up to 3*10^9, which exceeds the maximum value for a 32-bit signed int.
    long long X = X_int;
    long long Y = Y_int;
    long long K = K_int;
    
    long long S = X + Y; // Total number of stones, which remains constant.

    // Condition for impossibility:
    // For X1' to be an integer, (S + K) must be even.
    // This means S and K must have the same parity (both even or both odd).
    // If (S + K) is odd, then S and K have different parities, and X1' cannot be an integer.
    if ((S + K) % 2 != 0) {
        cout << -1 << "\n";
        return;
    }

    // If S and K have the same parity, a solution is possible.
    // There are two target configurations for the number of stones in the first box (X1'):
    // 1. X1' such that X1' - (S - X1') = K  => 2*X1' - S = K  => X1' = (S + K) / 2
    // 2. X1' such that (S - X1') - X1' = K  => S - 2*X1' = K  => 2*X1' = S - K => X1' = (S - K) / 2

    long long target_X1_A = (S + K) / 2;
    long long target_X1_B = (S - K) / 2;

    // The number of moves (and thus time) required to change the count of stones
    // in the first box from its current value X to a target value X1' is |X - X1'|.
    // We need the minimum time, so we take the minimum of the two possibilities.
    // std::abs is overloaded for long long.
    long long moves_A = abs(X - target_X1_A);
    long long moves_B = abs(X - target_X1_B);

    cout << min(moves_A, moves_B) << "\n";
}

int main() {
    // Fast I/O setup.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases.
    while (T--) {
        solve(); // Solve each test case.
    }

    return 0;
}

```