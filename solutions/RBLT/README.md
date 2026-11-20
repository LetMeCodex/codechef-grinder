# [Balanced Lighting (RBLT)](https://www.codechef.com/problems/RBLT)
- **Difficulty Rating**: 755
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if it's possible to achieve a "balanced" lighting configuration for `N` lights. Each light can be one of three states:
1.  **Red (1)**: An existing red light.
2.  **Blue (2)**: An existing blue light.
3.  **Undecided (0)**: A light whose color can be chosen as either red or blue.

A balanced configuration is defined as having an equal number of red and blue lights. We are allowed to change undecided lights (0) to either red (1) or blue (2), but we cannot change the color of an already red or blue light, nor can we remove any lights. We need to output "Yes" if a balanced configuration is possible, and "No" otherwise.

## Intuition & Mathematical Observation

The core of the problem lies in understanding what a "balanced" configuration implies and how the undecided lights can be used.

1.  **Definition of Balanced**: If a configuration is balanced, it means `(number of red lights) == (number of blue lights)`.
2.  **Total Lights `N`**: Let `R` be the number of red lights and `B` be the number of blue lights. If `R == B`, then the total number of colored lights `R + B = 2 * R`. Since `R + B` must be equal to the total number of lights `N` (as all undecided lights will eventually be colored), this implies `N = 2 * R`.
3.  **Observation 1: `N` must be even**: From `N = 2 * R`, it's clear that `N` must be an even number. If `N` is odd, it's impossible to have an equal number of red and blue lights, so we can immediately say "No".
4.  **Observation 2: Target Counts**: If `N` is even, then for a balanced configuration, we must have exactly `N/2` red lights and `N/2` blue lights. Let `target_count = N/2`.
5.  **Observation 3: Constraints from Existing Lights**:
    *   We count the initial number of red lights (`red_count`) and blue lights (`blue_count`) from the input.
    *   We cannot change existing red lights to blue, or existing blue lights to red. We also cannot remove lights.
    *   If `red_count > target_count` (i.e., we already have more red lights than required for a balanced configuration), it's impossible to reduce the number of red lights. So, the answer is "No".
    *   Similarly, if `blue_count > target_count`, it's impossible. The answer is "No".
6.  **Observation 4: Utilizing Undecided Lights**:
    *   If `N` is even, and both `red_count <= target_count` and `blue_count <= target_count`, can we always achieve a balanced configuration?
    *   We need `(target_count - red_count)` more red lights.
    *   We need `(target_count - blue_count)` more blue lights.
    *   The total number of lights we need to assign from the undecided ones is `(target_count - red_count) + (target_count - blue_count)`.
    *   This sum simplifies to `2 * target_count - (red_count + blue_count)`.
    *   Since `target_count = N/2`, `2 * target_count = N`.
    *   So, the total number of undecided lights we *need* to assign is `N - (red_count + blue_count)`.
    *   The actual number of undecided lights available is `N - (red_count + blue_count)` (because `red_count + blue_count + undecided_count = N`).
    *   Since the number of needed assignments exactly matches the number of available undecided lights, and both `(target_count - red_count)` and `(target_count - blue_count)` are non-negative, we can always make the necessary assignments.
    *   Therefore, if all previous conditions pass, the answer is "Yes".

**In summary, the logic is:**
1.  Read `N` and count initial `red_count` and `blue_count`.
2.  If `N` is odd, output "No".
3.  Calculate `target_count = N / 2`.
4.  If `red_count > target_count` or `blue_count > target_count`, output "No".
5.  Otherwise (if `N` is even, and both existing counts are less than or equal to `target_count`), output "Yes".

## Complexity Analysis

*   **Time Complexity**: $O(N)$ per test case.
    *   We iterate through the `N` lights once to count the existing red and blue lights. All other operations (reading `N`, comparisons, arithmetic) take constant time.
    *   For `T` test cases, the total time complexity would be $O(\sum N)$, where $\sum N$ is the sum of `N` over all test cases. Given typical competitive programming constraints, this is efficient enough.
*   **Space Complexity**: $O(1)$.
    *   We only use a few integer variables (`N`, `red_count`, `blue_count`, `C_i`, `target_count`) to store counts and temporary values. No data structures that scale with `N` (like arrays or vectors) are used.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, etc.

// Using namespace std; is common in competitive programming
// as requested by the problem instructions.
using namespace std; 

void solve() {
    int N;
    cin >> N; // Read N, the number of lights
    
    int red_count = 0;
    int blue_count = 0;
    
    // Iterate through the lights to count existing red and blue lights
    for (int i = 0; i < N; ++i) {
        int C_i;
        cin >> C_i; // Read the color of the i-th light
        if (C_i == 1) { // If it's red
            red_count++;
        } else if (C_i == 2) { // If it's blue
            blue_count++;
        }
        // If C_i == 0, it's undecided, we don't count it here.
        // Its role is implicitly handled by the logic.
    }
    
    // Condition 1: If N is odd, it's impossible to have an equal number of red and blue lights.
    if (N % 2 != 0) {
        cout << "No\n";
        return;
    }
    
    // If N is even, we need N/2 red lights and N/2 blue lights for a balanced configuration.
    int target_count = N / 2;
    
    // Condition 2: Check if we already have more red lights than the target.
    // If red_count > target_count, we cannot remove red lights, so it's impossible.
    if (red_count > target_count) {
        cout << "No\n";
        return;
    }
    
    // Condition 3: Check if we already have more blue lights than the target.
    // If blue_count > target_count, we cannot remove blue lights, so it's impossible.
    if (blue_count > target_count) {
        cout << "No\n";
        return;
    }
    
    // If N is even, and both red_count and blue_count are less than or equal to N/2,
    // then we have enough undecided lights to fill the gaps and achieve a balanced configuration.
    // The number of undecided lights is exactly N - (red_count + blue_count).
    // The number of red lights needed from undecided is (target_count - red_count).
    // The number of blue lights needed from undecided is (target_count - blue_count).
    // The sum of needed lights is (N/2 - red_count) + (N/2 - blue_count) = N - (red_count + blue_count),
    // which is exactly the total number of undecided lights. Since both needed counts are non-negative,
    // we can always make the assignment.
    cout << "Yes\n";
}

int main() {
    // Enable fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve();
    }
    
    return 0;
}
```