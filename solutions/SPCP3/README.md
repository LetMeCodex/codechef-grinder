# [Marbles (SPCP3)](https://www.codechef.com/problems/SPCP3)
- **Difficulty Rating**: 1385
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef has `A` marbles, and his friend has `B` marbles. They want to redistribute marbles such that Chef's final marble count (`C`) is a multiple of his friend's final marble count (`F`). The goal is to achieve this by transferring the minimum possible number of marbles between them. Both Chef and his friend must end up with at least one marble.

## Intuition & Mathematical Observation

1.  **Initial Check**:
    The first step is to check if Chef's current marble count `A` is already a multiple of his friend's current marble count `B`. If `A % B == 0`, then no transfers are needed, and the answer is `0`.

2.  **Target State Properties**:
    Let `C` be Chef's final marble count and `F` be his friend's final marble count.
    The problem states two conditions for the target state:
    *   `C % F == 0` (Chef's marbles are a multiple of friend's marbles).
    *   `C >= 1` and `F >= 1` (Both must have at least one marble).

    A crucial observation is that the total number of marbles in the system remains constant throughout any transfers.
    Let `S = A + B` be the total number of marbles.
    Therefore, `C + F = S`. This implies `C = S - F`.

    Now, substitute `C = S - F` into the condition `C % F == 0`:
    `(S - F) % F == 0`
    Using properties of modular arithmetic, `(X - Y) % Y == X % Y` for positive `Y`.
    So, `S % F == 0`.
    This is a key insight: **The friend's final marble count `F` must be a divisor of the total number of marbles `S` (`A + B`).**

3.  **Minimizing Transfers**:
    We want to minimize the number of marbles transferred. Let `x` be the number of marbles transferred.
    *   If Chef gives `x` marbles to the friend: Chef has `A - x`, Friend has `B + x`. In this case, `F = B + x`, so `x = F - B`.
    *   If Friend gives `x` marbles to Chef: Chef has `A + x`, Friend has `B - x`. In this case, `F = B - x`, so `x = B - F`.
    In both scenarios, the number of marbles transferred is `x = |F - B|`.
    Our objective is to find a valid `F` (a divisor of `S`) that minimizes `|F - B|`.

4.  **Constraints on `F`**:
    We established that `F` must be a divisor of `S`. We also have the conditions `C >= 1` and `F >= 1`.
    *   `F >= 1` is always true for any positive divisor. Since `A, B >= 1`, `S >= 2`, so `F` will always be at least 1.
    *   `C >= 1` means `S - F >= 1`, which implies `F <= S - 1`. This is important because `F` cannot be equal to `S` (if `F=S`, then `C=0`, violating `C>=1`).
    Combining these, `F` must be a divisor of `S` such that `1 <= F <= S - 1`.

5.  **Algorithm**:
    Based on these observations, the algorithm is as follows:
    *   Calculate `S = A + B`.
    *   Initialize `min_transfers` to a very large value (e.g., `INT_MAX`).
    *   Iterate through all possible divisors `F` of `S`. This can be done efficiently by checking numbers `f` from `1` up to `sqrt(S)`.
        *   If `f` divides `S`, then both `f` and `S/f` are divisors.
        *   For each such divisor (let's call it `current_F`), check if it satisfies the conditions `1 <= current_F <= S - 1`.
        *   If `current_F` is valid, calculate the number of transfers: `current_transfers = abs(current_F - B)`.
        *   Update `min_transfers = min(min_transfers, current_transfers)`.
    *   The final `min_transfers` value is the answer.

## Complexity Analysis

*   **Time Complexity**:
    The solution processes `T` test cases. For each test case, it calculates `S = A + B` and then iterates up to `sqrt(S)` to find divisors.
    Given `A, B <= 10^9`, `S` can be up to `2 * 10^9`.
    `sqrt(2 * 10^9)` is approximately `44721`.
    With `T <= 100`, the total time complexity is `O(T * sqrt(A + B))`.
    This evaluates to roughly `100 * 44721 = 4.47 * 10^6` operations, which is well within typical time limits (usually `10^8` operations per second).

*   **Space Complexity**:
    The solution uses a constant number of integer variables to store `t`, `a`, `b`, `total_marbles`, `min_transfers`, and loop counters. It does not use any data structures that scale with the input size.
    Therefore, the space complexity is `O(1)`.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common C++ headers like iostream, algorithm, etc.

using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // Disables synchronization with C's stdio and unties cin from cout.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) { // Loop through each test case
        int a, b;
        cin >> a >> b; // Read Chef's (a) and Friend's (b) initial marble counts

        // Base case: If Chef's marbles are already a multiple of Friend's marbles,
        // no transfers are needed.
        if (a % b == 0) {
            cout << 0 << "\n";
        } else {
            // Let S = A + B be the total number of marbles.
            // Let F be the friend's final marble count.
            // Let C be Chef's final marble count.
            // Conditions: C % F == 0, C >= 1, F >= 1.
            // Also, C + F = S, so C = S - F.
            // Substituting C: (S - F) % F == 0, which simplifies to S % F == 0.
            // This means F must be a divisor of S.
            // Also, C >= 1 implies S - F >= 1, so F <= S - 1.
            // The number of marbles transferred is |F - B|. We want to minimize this.

            int total_marbles = a + b;
            int min_transfers = INT_MAX; // Initialize with a very large value to find the minimum

            // Iterate through all possible divisors of total_marbles (S).
            // We only need to check up to sqrt(S) because if 'f' is a divisor, then 'total_marbles / f' is also a divisor.
            for (int f = 1; f * f <= total_marbles; ++f) {
                if (total_marbles % f == 0) {
                    // 'f' is a divisor
                    int divisor1 = f;
                    int divisor2 = total_marbles / f;

                    // Check divisor1 as a potential final marble count for the friend (F)
                    // Conditions: F >= 1 (always true for f >= 1) and F <= S - 1 (Chef must have at least 1 marble)
                    if (divisor1 <= total_marbles - 1) {
                        min_transfers = min(min_transfers, abs(divisor1 - b));
                    }

                    // Check divisor2 as a potential final marble count for the friend (F)
                    // Conditions: F >= 1 (always true for total_marbles >= 1) and F <= S - 1
                    if (divisor2 <= total_marbles - 1) {
                        min_transfers = min(min_transfers, abs(divisor2 - b));
                    }
                }
            }
            cout << min_transfers << "\n"; // Output the minimum transfers required
        }
    }
    return 0; // Indicate successful execution
}

```