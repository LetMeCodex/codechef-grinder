# [Move Grid (MOVEMENT)](https://www.codechef.com/problems/MOVEMENT)
- **Difficulty Rating**: 215
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the final coordinates of a point on a 2D grid. The point starts at `(0, 0)`. We are given four integer values: `A`, `B`, `C`, and `D`. The point undergoes a sequence of moves:
1. Moves `A` units along the positive X-axis.
2. Moves `B` units along the positive Y-axis.
3. Moves `C` units along the negative X-axis.
4. Moves `D` units along the negative Y-axis.

We need to output the final `(x, y)` coordinates of the point.

## Intuition & Mathematical Observation

This is a straightforward coordinate geometry problem. The movements along the X-axis are independent of the movements along the Y-axis. We can calculate the net change for each axis separately.

Let the initial position be `(initial_x, initial_y) = (0, 0)`.

1.  **Movement along X-axis**:
    *   Moving `A` units along the positive X-axis increases the X-coordinate by `A`.
    *   Moving `C` units along the negative X-axis decreases the X-coordinate by `C`.
    *   Therefore, the net change in the X-coordinate is `+A - C`.
    *   The final X-coordinate will be `initial_x + A - C = 0 + A - C = A - C`.

2.  **Movement along Y-axis**:
    *   Moving `B` units along the positive Y-axis increases the Y-coordinate by `B`.
    *   Moving `D` units along the negative Y-axis decreases the Y-coordinate by `D`.
    *   Therefore, the net change in the Y-coordinate is `+B - D`.
    *   The final Y-coordinate will be `initial_y + B - D = 0 + B - D = B - D`.

The order of these movements does not affect the final position because they are additive changes to independent coordinates. We can simply sum up all positive and negative movements for each axis.

The solution involves reading the four integers and then calculating `A - C` for the final X-coordinate and `B - D` for the final Y-coordinate.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The solution involves reading four integer inputs, performing a few arithmetic operations (additions and subtractions), and printing two integer outputs. All these operations take a constant amount of time, regardless of the magnitude of the input values (within standard integer limits).

-   **Space Complexity**: $O(1)$
    The solution uses a fixed number of variables (`a`, `b`, `c`, `d`, `final_x`, `final_y`) to store the input values and the calculated final coordinates. The memory usage does not grow with the input values, making it constant space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin/cout from C's stdio and disables synchronization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare variables to store the movement units.
    int a, b, c, d;
    // Read the four integer inputs.
    cin >> a >> b >> c >> d;

    // Initial position is (0, 0).
    // We use long long for final_x and final_y just in case,
    // though for this problem, int would suffice given the constraints.
    long long final_x = 0;
    long long final_y = 0;

    // Move A units along positive X axis
    final_x += a;

    // Move B units along positive Y axis
    final_y += b;

    // Move C units along negative X axis
    final_x -= c;

    // Move D units along negative Y axis
    final_y -= d;

    // Print the final X and Y coordinates, separated by a space,
    // followed by a newline character.
    cout << final_x << " " << final_y << "\n";

    return 0;
}
```