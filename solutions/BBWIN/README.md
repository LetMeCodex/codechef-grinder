# [Extreme Basketball (BBWIN)](https://www.codechef.com/problems/BBWIN)
- **Difficulty Rating**: 853
- **Solved in**: 1 attempt(s)

## Problem Summary

Alice and Bob are playing a game of basketball. Alice currently has `A` points, and Bob has `B` points. Alice wants to win the game by a margin of at least 10 points. She has a special ability to prevent Bob from scoring any more points. Alice can score either 2 or 3 points with each shot she takes. The task is to determine the minimum number of additional shots Alice needs to take to achieve her goal.

## Intuition & Mathematical Observation

1.  **Bob's Score Remains Constant**: The problem states that Alice can prevent Bob from scoring. This means Bob's final score will remain `B`.

2.  **Alice's Target Score**: Alice needs to win by at least 10 points. Since Bob's final score is `B`, Alice's final score (`A_final`) must satisfy the condition `A_final >= B + 10`.

3.  **Points Alice Needs to Score**:
    *   Alice currently has `A` points.
    *   Her target final score is `B + 10`.
    *   The number of *additional* points Alice needs to score is `P = (B + 10) - A`.

4.  **Edge Case: Already Won**:
    *   If `P <= 0`, it means Alice's current score `A` is already greater than or equal to `B + 10`. In this scenario, she has already achieved her goal (or surpassed it), so she doesn't need to take any more shots. The answer is 0.

5.  **Minimizing Shots for Positive Points Needed**:
    *   If `P > 0`, Alice needs to score `P` additional points.
    *   To minimize the number of shots, Alice should maximize the points scored per shot. She can score either 2 or 3 points per shot. Therefore, she should always aim for 3 points per shot.
    *   The minimum number of shots `k` required to score at least `P` points, with each shot yielding 3 points, is `ceil(P / 3)`.
    *   In integer arithmetic, `ceil(X / Y)` for positive integers `X` and `Y` can be calculated as `(X + Y - 1) / Y`.
    *   Applying this formula, `k = (P + 3 - 1) / 3 = (P + 2) / 3`.

Combining these observations, we first calculate the `points_needed`. If it's non-positive, the answer is 0. Otherwise, we apply the ceiling division formula to find the minimum shots.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The `solve()` function involves a few arithmetic operations (subtraction, addition, division) and a comparison. All these operations take constant time. Since the `solve()` function is called `t` times, the total time complexity is $O(t)$.

-   **Space Complexity**: $O(1)$
    The solution uses a fixed number of integer variables (`A`, `B`, `target_alice_score`, `points_needed`, `shots`) regardless of the input values. This constant amount of memory usage leads to an $O(1)$ space complexity.

## Solution Code

```cpp
#include <bits/stdc++.h> // Standard header for competitive programming

// Use the standard namespace to avoid prefixing std::
using namespace std;

// Function to solve a single test case
void solve() {
    int A, B; // Alice's and Bob's initial scores
    cin >> A >> B;

    // Alice needs to end with at least 10 points more than Bob.
    // Bob's score remains B as Alice prevents him from scoring.
    // So, Alice's final score A_final must satisfy A_final >= B + 10.
    int target_alice_score = B + 10;

    // Calculate how many additional points Alice needs to score.
    // If Alice's current score A is already >= target_alice_score,
    // then points_needed will be 0 or negative.
    int points_needed = target_alice_score - A;

    // If points_needed is 0 or negative, Alice already has a dominant victory
    // or needs no additional points. So, 0 shots are needed.
    if (points_needed <= 0) {
        cout << 0 << "\n";
    } else {
        // Alice needs to score 'points_needed' additional points.
        // To minimize the number of shots, she should maximize points per shot.
        // Each shot can score 2 or 3 points. So, she should aim for 3 points per shot.
        // The minimum number of shots 'k' required to score at least 'P' points
        // (where P = points_needed) is ceil(P / 3).
        // In integer arithmetic, ceil(X / Y) for positive integers X and Y
        // can be calculated as (X + Y - 1) / Y.
        // Here, Y = 3, so it's (points_needed + 3 - 1) / 3 = (points_needed + 2) / 3.
        int shots = (points_needed + 2) / 3;
        cout << shots << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Number of test cases
    cin >> t;
    while (t--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```