# [Reach fast (REACHFAST)](https://www.codechef.com/problems/REACHFAST)
- **Difficulty Rating**: 777
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef is currently at coordinate `A` and wants to reach Chefina, who is at coordinate `B`. In a single step, Chef can move at most `K` units. The goal is to find the minimum number of steps Chef needs to take to reach Chefina's coordinate.

## Intuition & Mathematical Observation

1.  **Calculate the Total Distance:** The first step is to determine the total distance Chef needs to cover. This is simply the absolute difference between Chef's current coordinate `A` and Chefina's coordinate `B`. Let this distance be `D = |A - B|`.

2.  **Maximize Movement per Step:** To minimize the number of steps, Chef should always move the maximum possible distance in each step. Since Chef can move *at most* `K` units, Chef should move exactly `K` units towards Chefina in every step until the destination is reached or surpassed.

3.  **Ceiling Division:** If Chef needs to cover a distance `D` and can cover `K` units per step, the number of steps would ideally be `D / K`. However, steps must be an integer, and Chef must cover *at least* `D` units. This means we need to find the smallest integer greater than or equal to `D / K`. This is known as the **ceiling function**, denoted as `ceil(D / K)`.

4.  **Integer Division Trick for Ceiling:** For positive integers `X` and `Y`, `ceil(X / Y)` can be efficiently computed using integer division as `(X + Y - 1) / Y`.
    *   Let `X = distance` and `Y = K`.
    *   If `distance` is a multiple of `K` (e.g., `distance = 9, K = 3`), then `(9 + 3 - 1) / 3 = 11 / 3 = 3` (integer division). This is correct.
    *   If `distance` is not a multiple of `K` (e.g., `distance = 10, K = 3`), then `(10 + 3 - 1) / 3 = 12 / 3 = 4`. This is also correct, as 3 steps cover 9 units, and one more step is needed for the remaining 1 unit.
    *   If `distance = 0` (Chef is already at Chefina), then `(0 + K - 1) / K = (K - 1) / K = 0` (integer division, since `K >= 1`). This is correct, as 0 steps are needed.

This formula correctly handles all cases where `distance >= 0` and `K >= 1`.

## Complexity Analysis

-   **Time Complexity**: For each test case, we perform a constant number of arithmetic operations (absolute difference, addition, subtraction, division). Therefore, if there are `T` test cases, the total time complexity is $O(T)$.

-   **Space Complexity**: We only use a few integer variables to store `A`, `B`, `K`, `distance`, `steps`, and `T`. This requires a constant amount of memory, regardless of the input values. Thus, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Required header by problem statement

// Required namespace by problem statement
using namespace std;

int main() {
    // Fast I/O as requested by problem statement
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T;
    while (T--) {
        int A, B, K; // Chef's coordinate, Chefina's coordinate, max move per step
        cin >> A >> B >> K;

        // Calculate the absolute distance Chef needs to cover.
        // abs() is from <cmath> or <cstdlib> (included by <bits/stdc++.h>).
        int distance = abs(A - B);

        // Calculate the minimum number of steps.
        // This is equivalent to ceil(distance / K) using integer division.
        // For positive integers X, Y, ceil(X/Y) can be computed as (X + Y - 1) / Y.
        // This formula correctly handles distance = 0 (resulting in 0 steps)
        // and distance > 0 (resulting in the smallest integer >= distance/K steps).
        int steps = (distance + K - 1) / K;

        cout << steps << "\n";
    }

    return 0;
}
```