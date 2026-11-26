# [Walk (WALK)](https://www.codechef.com/problems/WALK)
- **Difficulty Rating**: 1247
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum possible initial velocity `V_0` for a person to walk `N` segments. We are given `N` integers, `w[0], w[1], ..., w[N-1]`, where `w[i]` represents the minimum required velocity for the `i`-th segment (0-indexed).

The rules for walking are:
1.  The velocity on segment `i` must be at least `w[i]`.
2.  After completing each segment, the velocity decreases by exactly 1. That is, if the velocity on segment `i-1` was `V_{i-1}`, then the velocity on segment `i` will be `V_i = V_{i-1} - 1`.

We need to determine the smallest `V_0` that satisfies these conditions for all `N` segments.

## Intuition & Mathematical Observation

Let `V_0` be the initial velocity.
According to the problem statement, the velocity decreases by 1 after each segment.
So, the velocity on segment `0` is `V_0`.
The velocity on segment `1` is `V_1 = V_0 - 1`.
The velocity on segment `2` is `V_2 = V_1 - 1 = (V_0 - 1) - 1 = V_0 - 2`.
Following this pattern, the velocity on segment `i` will be `V_i = V_0 - i`.

Now, we also have the condition that the velocity on segment `i` must be at least `w[i]`.
Combining these two facts, for each segment `i` (from `0` to `N-1`), we must satisfy:
`V_i >= w[i]`
Substituting `V_i = V_0 - i`:
`V_0 - i >= w[i]`

To find the minimum `V_0`, we can rearrange this inequality:
`V_0 >= w[i] + i`

This condition `V_0 >= w[i] + i` must hold true for *all* segments `i` from `0` to `N-1`.
Therefore, `V_0` must be greater than or equal to `w[0] + 0`, `w[1] + 1`, `w[2] + 2`, ..., `w[N-1] + (N-1)`.

To satisfy all these individual conditions simultaneously, the minimum possible `V_0` must be the maximum value among all `(w[i] + i)` terms.
So, `min_V_0 = max(w[i] + i)` for `i` from `0` to `N-1`.

The algorithm is straightforward:
1. Initialize `min_initial_velocity = 0`.
2. Iterate `i` from `0` to `N-1`.
3. In each iteration, calculate `current_required_V0 = w[i] + i`.
4. Update `min_initial_velocity = max(min_initial_velocity, current_required_V0)`.
5. After the loop, `min_initial_velocity` will hold the answer.

## Complexity Analysis

-   **Time Complexity**: $O(N)$
    For each test case, we read `N` integers, which takes $O(N)$ time. Then, we iterate through the `N` segments once to calculate `w[i] + i` and find the maximum, which also takes $O(N)$ time. All other operations are constant time. If there are `T` test cases, the total time complexity would be $O(T \cdot N)$.

-   **Space Complexity**: $O(N)$
    We use a `std::vector<long long> w` of size `N` to store the minimum required velocities for each segment. This consumes $O(N)$ space. All other variables use constant space.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // Required for std::max

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int n; // Number of segments
        std::cin >> n;
        std::vector<long long> w(n); // Vector to store minimum velocities for each segment
        for (int i = 0; i < n; ++i) {
            std::cin >> w[i];
        }

        long long min_initial_velocity = 0; // Initialize with 0, as velocities are non-negative.
                                            // Any w[i] + i will be >= 0 if w[i] >= 0.
                                            // If w[i] can be negative, we might need a smaller initial value,
                                            // but problem constraints usually imply non-negative w[i].
                                            // A safe initial value would be w[0] + 0, or even LLONG_MIN if w[i] could be very small.
                                            // Given typical competitive programming constraints, 0 is fine.

        // Iterate through each segment to find the maximum (w[i] + i)
        for (int i = 0; i < n; ++i) {
            // For the i-th segment (0-indexed):
            // Let V_0 be the initial velocity.
            // Velocity on segment i is V_i = V_0 - i.
            // We must have V_i >= w[i].
            // So, V_0 - i >= w[i], which implies V_0 >= w[i] + i.
            // To satisfy this for all segments, V_0 must be at least the maximum of (w[i] + i) over all i.
            min_initial_velocity = std::max(min_initial_velocity, w[i] + i);
        }
        std::cout << min_initial_velocity << "\n"; // Output the minimum required initial velocity
    }
    return 0;
}

```