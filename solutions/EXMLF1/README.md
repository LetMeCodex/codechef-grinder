# [EXML Race (EXMLF1)](https://www.codechef.com/problems/EXMLF1)
- **Difficulty Rating**: 684
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes an EXML race featuring `N` AI-driven cars. For each car, we are given the distance `d_i` it traveled and the time `t_i` it took to cover that distance. We need to determine the label of the fastest car. If multiple cars achieve the same maximum speed, we should output the label of the car with the smallest index (label). Car labels are 1-indexed.

**Input:**
- `T`: Number of test cases.
- For each test case:
    - `N`: Number of AI-driven cars.
    - `N` lines follow, each with `d_i` (distance) and `t_i` (time) for car `i`.
    - It's guaranteed that `d_i` is a multiple of `t_i`.

**Output:**
- For each test case, print the label of the fastest car, applying the tie-breaking rule.

## Intuition & Mathematical Observation

1.  **Speed Calculation**: The fundamental formula for speed is `speed = distance / time`. Since the problem guarantees that `d_i` is always a multiple of `t_i`, we can use integer division (`d / t`) to accurately calculate the speed of each car.

2.  **Finding the Maximum Speed**: To find the fastest car, we need to iterate through all `N` cars. For each car, we calculate its speed. We maintain two variables: `max_speed` (to store the highest speed encountered so far) and `winner_label` (to store the label of the car that achieved `max_speed`).

3.  **Tie-breaking Rule**: The problem states: "If multiple cars have the same maximum speed, output the one with the smallest label."
    *   We initialize `max_speed` to 0 (since speeds are positive) and `winner_label` to 0.
    *   We iterate through the cars from label `i = 1` to `N`.
    *   If the `current_speed` of car `i` is **greater than** `max_speed`:
        *   We update `max_speed = current_speed`.
        *   We update `winner_label = i`.
    *   If the `current_speed` of car `i` is **equal to** `max_speed`:
        *   We **do not** update `winner_label`. This is the key to handling the tie-breaking rule. Since we are iterating from `i = 1` upwards, if a car `j` (where `j < i`) already achieved `max_speed`, `winner_label` would correctly hold `j`. If car `i` also achieves `max_speed`, its label `i` will be greater than `j`. By not updating, `winner_label` will retain the smaller label `j`, thus satisfying the condition of outputting the minimum label among fastest cars.

This approach ensures that `winner_label` always stores the label of the car with the maximum speed, and in case of ties, it stores the smallest such label.

## Complexity Analysis

-   **Time Complexity**: $O(N)$ per test case.
    *   The `solve` function contains a single loop that iterates `N` times (from `i = 1` to `N`).
    *   Inside the loop, operations like input reading, division, and comparison are all constant time operations.
    *   Since there are `T` test cases, the total time complexity will be $O(T \cdot N)$.
    *   Given constraints: $T \le 100$ and $N \le 100$. The maximum number of operations would be approximately $100 \times 100 = 10000$, which is very efficient and well within typical time limits.

-   **Space Complexity**: $O(1)$ per test case.
    *   The solution uses a fixed number of integer variables (`N`, `max_speed`, `winner_label`, `d`, `t`, `current_speed`) regardless of the input size `N`. These variables consume a constant amount of memory.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries, common in competitive programming

// Function to solve a single test case
void solve() {
    int N; // Number of AI-driven cars
    std::cin >> N;

    int max_speed = 0;      // Stores the maximum speed found so far. Speeds are positive, so 0 is a safe initial minimum.
    int winner_label = 0;   // Stores the label of the car with max_speed. Car labels are 1-indexed.

    // Iterate through each car from 1 to N
    for (int i = 1; i <= N; ++i) {
        int d, t; // Distance traveled and time taken for the current car
        std::cin >> d >> t;

        // Calculate the speed of the current car.
        // d_i is guaranteed to be a multiple of t_i, so integer division is exact.
        int current_speed = d / t;

        // Check if the current car is faster than the fastest car found so far
        if (current_speed > max_speed) {
            max_speed = current_speed; // Update max_speed
            winner_label = i;          // Update winner_label to the current car's label
        }
        // If current_speed == max_speed, we do nothing.
        // This is because we are looking for the minimum label among fastest cars.
        // Since we iterate 'i' from 1 to N, if a car 'j' (where j < i) already
        // achieved 'max_speed', then 'winner_label' would be 'j'.
        // If car 'i' also achieves 'max_speed', its label 'i' will be greater than 'j'.
        // Thus, 'winner_label' already holds the minimum label for 'max_speed'.
    }

    // Output the label of the fastest car (with minimum label in case of ties)
    std::cout << winner_label << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Number of test cases
    std::cin >> T;
    while (T--) { // Loop through each test case
        solve();
    }

    return 0;
}
```