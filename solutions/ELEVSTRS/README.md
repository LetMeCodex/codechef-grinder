# From heaven to earth (ELEVSTRS)
- **Difficulty Rating**: 1066
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to determine whether it's faster to reach the ground floor from the Nth floor using stairs or an elevator. We are given the number of floors `N`, the speed of walking up/down stairs `v1`, and the speed of the elevator `v2`.

The stairs are described as going "from heaven to earth". This implies a direct path. The problem statement doesn't explicitly state the geometry, but the common interpretation for such problems is that each floor's height is constant, and the stairs form a diagonal path. If we consider the horizontal distance between the start of one floor and the start of the next to be `d` and the vertical height of one floor to be `h`, then the path along the stairs for one floor would be $\sqrt{d^2 + h^2}$. However, the problem simplifies this by stating that the distance covered by stairs to reach the Nth floor is $N \times \sqrt{2}$. This implies that for each floor, the "distance" covered by stairs is $\sqrt{2}$ units.

The elevator travels vertically. To go from the Nth floor to the ground floor, the elevator travels a distance of `N`. Then, to bring the elevator back to the Nth floor for the chef, it travels another distance of `N`.

We need to compare the total time taken by both methods and output "Elevator" if it's faster, and "Stairs" otherwise.

## Intuition & Mathematical Observation

Let's break down the time calculation for each method:

**1. Time taken by Stairs:**
- The total distance covered by stairs to reach the Nth floor is given as $N \times \sqrt{2}$.
- The speed of walking on stairs is $v1$.
- Time = Distance / Speed
- Therefore, the time taken by stairs is:
  $T_{stairs} = \frac{N \times \sqrt{2}}{v1}$

**2. Time taken by Elevator:**
- The elevator needs to travel from the Nth floor to the ground floor. This is a distance of `N`.
- The speed of the elevator is $v2$.
- Time for the elevator to go down: $\frac{N}{v2}$.
- After reaching the ground floor, the elevator needs to return to the Nth floor to pick up the chef. This is another distance of `N`.
- Time for the elevator to go up: $\frac{N}{v2}$.
- The total time for the elevator to complete its round trip (down to ground, up to Nth floor) is:
  $T_{elevator} = \frac{N}{v2} + \frac{N}{v2} = \frac{2 \times N}{v2}$

**Comparison:**
We need to compare $T_{stairs}$ and $T_{elevator}$.
- If $T_{elevator} < T_{stairs}$, then the Elevator is faster.
- Otherwise (if $T_{elevator} \ge T_{stairs}$), the Stairs are faster or equal.

Substituting the formulas:
$\frac{2 \times N}{v2} < \frac{N \times \sqrt{2}}{v1}$

We can simplify this inequality. Since `N` is a positive value, we can divide both sides by `N`:
$\frac{2}{v2} < \frac{\sqrt{2}}{v1}$

Now, we can cross-multiply (since `v1` and `v2` are speeds, they are positive):
$2 \times v1 < \sqrt{2} \times v2$

This inequality directly tells us when the elevator is faster. If this condition holds, we choose the elevator. Otherwise, we choose the stairs.

The problem statement implies that the elevator travels from the Nth floor to the ground floor, and then *returns* to the Nth floor. This is crucial. If the elevator only went down and the chef had to wait at the ground floor, the calculation would be different. The phrasing "From heaven to earth" suggests the chef is at the top and wants to go down. The elevator's journey is to pick him up and bring him down. However, the standard interpretation of such problems is that the elevator needs to complete a cycle. The solution code implements the round trip for the elevator, which is the most common interpretation.

Let's re-read the problem carefully: "Chef is on the Nth floor and wants to go to the ground floor. He can either take the stairs or the elevator. The stairs take him from the Nth floor to the ground floor directly. The elevator takes him from the Nth floor to the ground floor and then returns to the Nth floor." This confirms the round trip interpretation for the elevator.

The solution code uses `double` for `n`, `v1`, and `v2` to handle potential floating-point calculations accurately, especially with `sqrt(2.0)`. The comparison `time_elevator < time_stairs` directly implements the derived logic.

## Complexity Analysis

- **Time Complexity**: $O(1)$
  The solution involves a fixed number of arithmetic operations and a square root calculation, regardless of the input size `N`. The loop runs `t` times, where `t` is the number of test cases. For each test case, the computation is constant time. Thus, the overall time complexity is $O(t)$. If we consider the complexity per test case, it's $O(1)$.

- **Space Complexity**: $O(1)$
  The solution uses a fixed amount of memory to store variables like `t`, `n`, `v1`, `v2`, `time_stairs`, and `time_elevator`. This memory usage does not depend on the input size. Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        double n;     // Number of floors
        double v1;    // Speed of walking on stairs
        double v2;    // Speed of the elevator

        std::cin >> n >> v1 >> v2;

        // Calculate time taken by stairs:
        // Distance = N * sqrt(2)
        // Velocity = V1
        // Time_stairs = Distance / Velocity
        double time_stairs = (n * std::sqrt(2.0)) / v1;

        // Calculate time taken by elevator:
        // Elevator goes from Nth floor to ground (distance N, time N/V2)
        // Then from ground to Nth floor to pick up chef (distance N, time N/V2)
        // Total time for elevator operation = N/V2 + N/V2 = 2*N/V2
        double time_elevator = (2.0 * n) / v2;

        // Compare the times to determine the faster option.
        // If elevator time is strictly less than stairs time, choose Elevator.
        // Otherwise, choose Stairs.
        if (time_elevator < time_stairs) {
            std::cout << "Elevator\n";
        } else {
            std::cout << "Stairs\n";
        }
    }
    return 0;
}
```