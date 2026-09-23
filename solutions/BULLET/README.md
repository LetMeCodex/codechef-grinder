# [Mario and Bullet (BULLET)](https://www.codechef.com/problems/BULLET)
- **Difficulty Rating**: 650
- **Solved in**: 1 attempt(s)

## Problem Summary

Mario has a bullet that travels at a speed of `X` units per second. A Goomba is located `Y` units away from Mario. Mario wants the bullet to hit the Goomba at least `Z` seconds from *now*. Mario can choose to delay shooting the bullet. We need to determine the minimum time Mario must wait before shooting the bullet to satisfy the condition. It's guaranteed that `Y` is always a multiple of `X`.

## Intuition & Mathematical Observation

1.  **Time for Bullet to Travel:** First, let's calculate how long it takes for the bullet to reach the Goomba if Mario shoots it immediately. Given the distance `Y` and speed `X`, the time taken is `Y / X`. Since `Y` is guaranteed to be a multiple of `X`, this will always be an integer. Let's call this `bullet_travel_time`.

    `bullet_travel_time = Y / X`

2.  **Total Time Requirement:** Mario wants the *total time from now* until the bullet hits the Goomba to be at least `Z` seconds. Let `shoot_delay` be the time Mario waits before shooting. The total time elapsed from "now" until the bullet hits the Goomba will be the sum of the `shoot_delay` and the `bullet_travel_time`.

    `total_time = shoot_delay + bullet_travel_time`

    We need this `total_time` to be at least `Z`:

    `shoot_delay + bullet_travel_time >= Z`

3.  **Minimum Shoot Delay:** To find the minimum `shoot_delay`, we can rearrange the inequality:

    `shoot_delay >= Z - bullet_travel_time`

4.  **Non-Negative Delay:** A delay cannot be negative. Mario cannot "un-shoot" a bullet or shoot it before "now". The minimum possible delay is 0 (meaning Mario shoots immediately).
    Therefore, if `Z - bullet_travel_time` results in a negative value, it means the bullet would hit the Goomba in less than `Z` seconds even if shot immediately. In such a scenario, the minimum `shoot_delay` is 0. Otherwise, it's `Z - bullet_travel_time`.

    This can be elegantly expressed using the `max` function:

    `minimum_shoot_delay = max(0, Z - bullet_travel_time)`

This formula directly gives us the minimum time Mario must wait.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    For each test case, we perform a few constant-time operations: reading three integers, one division, one subtraction, one `max` operation, and one print operation. These operations take a constant amount of time, regardless of the input values (within integer limits). Since there are `T` test cases, the total time complexity is directly proportional to `T`.

-   **Space Complexity**: $O(1)$
    The solution uses a fixed number of integer variables (`T`, `X`, `Y`, `Z`, `time_bullet_travel`, `required_delay`, `actual_shoot_delay`) to store input and intermediate results. The amount of memory used does not grow with the input values or the number of test cases (beyond the loop iterations). Thus, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, algorithm, etc. for competitive programming

// Use the standard namespace for brevity in competitive programming
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int X, Y, Z; // Declare integer variables for speed (X), distance (Y), and minimum total time (Z).
        cin >> X >> Y >> Z; // Read X, Y, and Z for the current test case.

        // Calculate the time it takes for the bullet to travel from Mario to the goomba.
        // The problem states that X divides Y, so Y / X will always be an integer.
        int time_bullet_travel = Y / X;

        // We want the total time from 'now' until the bullet hits the goomba to be at least Z.
        // Let 'shoot_delay' be the time Mario waits before shooting.
        // The total time is: shoot_delay + time_bullet_travel.
        // So, we need: shoot_delay + time_bullet_travel >= Z.
        // Rearranging for shoot_delay: shoot_delay >= Z - time_bullet_travel.

        // The minimum possible shoot_delay is 0 (Mario shoots immediately).
        // If Z - time_bullet_travel is negative, it means the bullet would hit
        // the goomba in less than Z seconds even if shot immediately. In this case,
        // the minimum shoot_delay is 0. Otherwise, it's Z - time_bullet_travel.
        // The max(0, ...) function handles this condition correctly.
        int required_delay = Z - time_bullet_travel;
        int actual_shoot_delay = max(0, required_delay);

        // Output the calculated minimum shoot delay, followed by a newline character.
        cout << actual_shoot_delay << "\n";
    }

    return 0; // Indicate successful program execution.
}
```