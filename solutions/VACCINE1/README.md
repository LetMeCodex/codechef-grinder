# [Vaccine Production (VACCINE1)](https://www.codechef.com/problems/VACCINE1)
- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the minimum number of days required to produce a total of `p` vaccines. We are given information about two vaccine production factories:
1. **Factory 1**: Starts production on day `d1` and produces `v1` vaccines each day thereafter.
2. **Factory 2**: Starts production on day `d2` and produces `v2` vaccines each day thereafter.

We need to find the first day `day` on which the cumulative number of vaccines produced by both factories combined is greater than or equal to `p`.

## Intuition & Mathematical Observation

The problem can be solved by simulating the vaccine production day by day. We need to keep track of the current day and the total number of vaccines produced so far.

Here's the step-by-step intuition:
1. **Initialization**: Start with `current_vaccines = 0` and `day = 0`.
2. **Daily Simulation**: In a loop, increment the `day` counter.
3. **Factory 1 Production**: On each `day`, check if Factory 1 has started production. This happens if `day >= d1`. If it has, add `v1` to `current_vaccines`.
4. **Factory 2 Production**: Similarly, check if Factory 2 has started production. This happens if `day >= d2`. If it has, add `v2` to `current_vaccines`.
5. **Goal Check**: After updating `current_vaccines` for the current `day`, check if `current_vaccines` has reached or exceeded `p`. If it has, then the current `day` is our answer, and we can stop the simulation.

The constraints on `d1, v1, d2, v2, p` are small (up to 100). This means the total number of days required will also be small. For example, if `p=100`, `d1=100`, `v1=1`, `d2=100`, `v2=1`, then production starts on day 100, producing 2 vaccines per day. It would take `100 + (100/2) - 1 = 149` days. A simple day-by-day simulation will be very efficient and easily pass within the time limits.

## Complexity Analysis

*   **Time Complexity**: The simulation loop runs until `current_vaccines` reaches `p`. In the worst case, production might start late (e.g., `d1=100, d2=100`) and daily production might be minimal (e.g., `v1=1, v2=1`). The maximum `p` is 100.
    The maximum number of days will be roughly `max(d1, d2) + p / min(v1, v2)`. Given the constraints (`d1, d2, v1, v2, p <= 100`), this translates to approximately `100 + 100/1 = 200` days. Since each iteration of the loop takes constant time, the total time complexity is proportional to the maximum number of days, which is a small constant. Therefore, the time complexity is $O(P + \max(D_1, D_2))$, which for the given constraints is effectively $O(1)$.

*   **Space Complexity**: The solution uses a fixed number of integer variables to store inputs (`d1, v1, d2, v2, p`), the current vaccine count (`current_vaccines`), and the current day (`day`). These variables consume a constant amount of memory regardless of the input values. Thus, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <iostream>
#include <algorithm> // Not strictly needed for this solution, but often useful

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is good practice for competitive programming but not strictly necessary
    // for problems with small input sizes like this one.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // Declare variables for input:
    // d1, v1: start day and daily production for factory 1
    // d2, v2: start day and daily production for factory 2
    // p: target total vaccines
    int d1, v1, d2, v2, p;
    std::cin >> d1 >> v1 >> d2 >> v2 >> p;

    // Initialize total vaccines produced and the current day.
    // Using long long for current_vaccines is a safe practice to prevent overflow,
    // though for p <= 100, int would also suffice.
    long long current_vaccines = 0;
    int day = 0;

    // Simulate day by day until the target number of vaccines is reached.
    while (current_vaccines < p) {
        day++; // Advance to the next day

        // Check if factory 1 is active on the current day and add its production
        if (day >= d1) {
            current_vaccines += v1;
        }

        // Check if factory 2 is active on the current day and add its production
        if (day >= d2) {
            current_vaccines += v2;
        }
    }

    // Output the first day on which 'p' vaccines are produced or exceeded.
    std::cout << day << std::endl;

    return 0;
}

```