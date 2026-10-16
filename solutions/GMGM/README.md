# [Gun Master (GMGM)](https://www.codechef.com/problems/GMGM)
- **Difficulty Rating**: 783
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to calculate the minimum number of gun switches required to defeat a sequence of monsters. We have two guns: a close-range gun effective against monsters with a distance less than or equal to a given threshold `d`, and a long-range gun effective against monsters with a distance greater than `d`. We start with the close-range gun. For each monster, we must use the appropriate gun. If we don't have the correct gun equipped, we must switch to it.

## Intuition & Mathematical Observation
The core of the problem lies in tracking the current gun we are holding and determining when a switch is necessary. We are given a sequence of monster distances `a[i]` and a threshold `d`.

Let's define the effectiveness of the guns:
- **Close-range gun**: Effective for monsters with distance `a[i] <= d`.
- **Long-range gun**: Effective for monsters with distance `a[i] > d`.

We start with the close-range gun. We iterate through the monsters one by one. For each monster, we check if our current gun is suitable.

- **If we are holding the close-range gun (current_gun = 0):**
    - If the current monster requires the long-range gun (`a[i] > d`), we *must* switch to the long-range gun. This increments our `switches` count, and we update `current_gun` to 1.
    - If the current monster requires the close-range gun (`a[i] <= d`), we don't need to switch. We continue with the close-range gun.

- **If we are holding the long-range gun (current_gun = 1):**
    - If the current monster requires the close-range gun (`a[i] <= d`), we *must* switch to the close-range gun. This increments our `switches` count, and we update `current_gun` to 0.
    - If the current monster requires the long-range gun (`a[i] > d`), we don't need to switch. We continue with the long-range gun.

This greedy approach works because each decision is independent of future decisions regarding *which* gun to switch to. We always switch only when absolutely necessary to engage the current monster. The problem doesn't involve any strategic choices about saving switches for later, as each monster must be dealt with immediately.

The logic can be simplified: a switch is required if the current monster's distance `a[i]` has a different "range requirement" than the gun we are currently holding.

## Complexity Analysis
- **Time Complexity**: $O(N)$
    The code iterates through the `t` test cases. For each test case, it reads `n` integers and then iterates through the `n` monsters once. The operations inside the loop (comparisons and assignments) take constant time. Therefore, the total time complexity for each test case is $O(N)$, and for `t` test cases, it's $O(T \cdot N)$. However, if we consider the total number of monsters across all test cases, the complexity is linear with respect to the total input size. For a single test case, it's $O(N)$.

- **Space Complexity**: $O(N)$
    We use a `std::vector` of size `n` to store the distances of the monsters. This contributes $O(N)$ to the space complexity. The other variables use constant space.

## Solution Code
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int n; // Number of monsters
        int d; // Distance threshold
        std::cin >> n >> d;

        std::vector<int> a(n); // Vector to store monster distances
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        int switches = 0; // Initialize switch count
        // current_gun: 0 for close-range gun, 1 for long-range gun
        // We start with the close-range gun.
        int current_gun = 0; 

        for (int i = 0; i < n; ++i) {
            // Determine the required gun for the current monster
            bool needs_close_range = (a[i] <= d);
            bool needs_long_range = (a[i] > d);

            if (current_gun == 0) { // Currently holding close-range gun
                if (needs_long_range) {
                    // If the monster requires the long-range gun, we must switch.
                    switches++;
                    current_gun = 1; // Now holding long-range gun
                }
                // If needs_close_range, no switch is needed.
            } else { // Currently holding long-range gun
                if (needs_close_range) {
                    // If the monster requires the close-range gun, we must switch.
                    switches++;
                    current_gun = 0; // Now holding close-range gun
                }
                // If needs_long_range, no switch is needed.
            }
        }
        std::cout << switches << "\n"; // Output the total number of switches
    }
    return 0;
}
```