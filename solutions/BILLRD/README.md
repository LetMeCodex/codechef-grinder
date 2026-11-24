# [Point Of Impact (BILLRD)](https://www.codechef.com/problems/BILLRD)
- **Difficulty Rating**: -1
- **Solved in**: 2 attempt(s)

## Problem Summary
We are given a square table of size $N \times N$. A billiard ball starts at coordinates $(x, y)$ and moves with a velocity of $(1, 1)$. When the ball hits any of the four walls, its velocity component perpendicular to that wall reverses. The ball stops if it hits a corner. We need to find the final coordinates of the ball after $K$ collisions.

## Intuition & Mathematical Observation

The key observation is that the ball's movement is confined within a square. The velocity components $(v_x, v_y)$ can only be $(1, 1)$, $(-1, 1)$, $(-1, -1)$, or $(1, -1)$.

Let's analyze the path of the ball.
Initially, the ball is at $(x, y)$ with velocity $(1, 1)$.

1.  **First Collision**:
    *   The ball moves towards the top-right corner.
    *   It will hit either the right wall (at $x=N$) or the top wall (at $y=N$).
    *   The distance to the right wall is $N - x$.
    *   The distance to the top wall is $N - y$.
    *   The ball travels the minimum of these two distances. Let this minimum distance be $d_1$.
    *   The new position will be $(x + 1 \cdot d_1, y + 1 \cdot d_1)$.
    *   If $N - x < N - y$, it hits the right wall. The velocity becomes $(-1, 1)$.
    *   If $N - y < N - x$, it hits the top wall. The velocity becomes $(1, -1)$.
    *   If $N - x = N - y$, it hits the top-right corner $(N, N)$. The ball stops.

2.  **Second Collision**:
    *   Suppose it hit the right wall and velocity is now $(-1, 1)$. The ball is at $(N, y + (N-x))$.
    *   It moves towards the top-left.
    *   Distance to the left wall ($x=0$) is $N$.
    *   Distance to the top wall ($y=N$) is $N - (y + (N-x))$.
    *   The ball travels the minimum of these two distances. Let this minimum distance be $d_2$.
    *   The new position will be $(N - 1 \cdot d_2, y + (N-x) + 1 \cdot d_2)$.
    *   If $N < N - (y + (N-x))$, it hits the left wall. Velocity becomes $(1, 1)$.
    *   If $N - (y + (N-x)) < N$, it hits the top wall. Velocity becomes $(-1, -1)$.
    *   If $N = N - (y + (N-x))$, it hits the top-left corner $(0, N)$. The ball stops.

This simulation can be tedious. Let's look for a pattern in the velocity changes.
The velocity vector $(v_x, v_y)$ cycles through:
$(1, 1) \xrightarrow{\text{hit vertical wall}} (-1, 1) \xrightarrow{\text{hit horizontal wall}} (-1, -1) \xrightarrow{\text{hit vertical wall}} (1, -1) \xrightarrow{\text{hit horizontal wall}} (1, 1)$

This cycle of velocity changes repeats every 4 collisions.
*   Collision 1: $(1, 1)$
*   Collision 2: $(-1, 1)$ (if hit vertical first) or $(1, -1)$ (if hit horizontal first)
*   Collision 3: $(-1, -1)$
*   Collision 4: $(1, -1)$ (if hit vertical first) or $(-1, 1)$ (if hit horizontal first)
*   Collision 5: $(1, 1)$

The crucial observation is that the ball stops if it hits a corner. A corner is hit when the distance to the vertical wall and the distance to the horizontal wall are equal at the moment of collision.

Let's consider the state of the ball by its current position $(curr\_x, curr\_y)$ and its direction $(dir\_x, dir\_y)$.

We can simulate the movement for $K$ collisions. However, since the velocity cycle repeats every 4 collisions, we only need to simulate $K \pmod 4$ steps. If $K \pmod 4 = 0$, it means the ball has completed a full cycle of 4 collisions and is about to start the next cycle. So, we should simulate 4 steps in this case.

Let's define the initial state:
$curr\_x = x$, $curr\_y = y$
$dir\_x = 1$, $dir\_y = 1$

We need to simulate for `effective_k = K % 4`. If `effective_k` is 0, we set it to 4.

In each step of the simulation (for $i$ from 0 to `effective_k - 1`):
1.  Calculate the distance to the next vertical wall:
    *   If $dir\_x = 1$ (moving right), distance is $N - curr\_x$.
    *   If $dir\_x = -1$ (moving left), distance is $curr\_x$.
2.  Calculate the distance to the next horizontal wall:
    *   If $dir\_y = 1$ (moving up), distance is $N - curr\_y$.
    *   If $dir\_y = -1$ (moving down), distance is $curr\_y$.
3.  The ball travels a distance $t\_step = \min(\text{distance to vertical wall}, \text{distance to horizontal wall})$.
4.  Update the position:
    *   $curr\_x = curr\_x + dir\_x \cdot t\_step$
    *   $curr\_y = curr\_y + dir\_y \cdot t\_step$
5.  Check for corner collision:
    *   If $\text{distance to vertical wall} == \text{distance to horizontal wall}$, the ball hit a corner. The simulation stops.
    *   If the ball hit a vertical wall (i.e., distance to vertical wall was the minimum and not equal to distance to horizontal wall), reverse $dir\_x$: $dir\_x = -dir\_x$.
    *   If the ball hit a horizontal wall (i.e., distance to horizontal wall was the minimum and not equal to distance to vertical wall), reverse $dir\_y$: $dir\_y = -dir\_y$.

After `effective_k` steps (or if the ball stopped at a corner), the final $(curr\_x, curr\_y)$ is the answer.

Let's trace an example: $N=10, K=3, x=2, y=3$.
Initial: $(2, 3)$, $dir = (1, 1)$. $K=3$. $effective\_k = 3$.

**Step 1 (i=0):**
*   $curr\_x = 2, curr\_y = 3, dir\_x = 1, dir\_y = 1$.
*   Dist to vertical (right): $10 - 2 = 8$.
*   Dist to horizontal (up): $10 - 3 = 7$.
*   $t\_step = \min(8, 7) = 7$.
*   Update position: $curr\_x = 2 + 1 \cdot 7 = 9$, $curr\_y = 3 + 1 \cdot 7 = 10$.
*   Hit horizontal wall (since $7 < 8$). Reverse $dir\_y$.
*   New state: $(9, 10)$, $dir = (1, -1)$.

**Step 2 (i=1):**
*   $curr\_x = 9, curr\_y = 10, dir\_x = 1, dir\_y = -1$.
*   Dist to vertical (right): $10 - 9 = 1$.
*   Dist to horizontal (down): $10$.
*   $t\_step = \min(1, 10) = 1$.
*   Update position: $curr\_x = 9 + 1 \cdot 1 = 10$, $curr\_y = 10 + (-1) \cdot 1 = 9$.
*   Hit vertical wall (since $1 < 10$). Reverse $dir\_x$.
*   New state: $(10, 9)$, $dir = (-1, -1)$.

**Step 3 (i=2):**
*   $curr\_x = 10, curr\_y = 9, dir\_x = -1, dir\_y = -1$.
*   Dist to vertical (left): $10$.
*   Dist to horizontal (down): $9$.
*   $t\_step = \min(10, 9) = 9$.
*   Update position: $curr\_x = 10 + (-1) \cdot 9 = 1$, $curr\_y = 9 + (-1) \cdot 9 = 0$.
*   Hit horizontal wall (since $9 < 10$). Reverse $dir\_y$.
*   New state: $(1, 0)$, $dir = (-1, 1)$.

Simulation ends as $i=2$ is the last iteration for $effective\_k=3$.
Final position: $(1, 0)$.

Consider a case where it hits a corner: $N=10, K=1, x=5, y=5$.
Initial: $(5, 5)$, $dir = (1, 1)$. $K=1$. $effective\_k = 1$.

**Step 1 (i=0):**
*   $curr\_x = 5, curr\_y = 5, dir\_x = 1, dir\_y = 1$.
*   Dist to vertical (right): $10 - 5 = 5$.
*   Dist to horizontal (up): $10 - 5 = 5$.
*   $t\_step = \min(5, 5) = 5$.
*   Update position: $curr\_x = 5 + 1 \cdot 5 = 10$, $curr\_y = 5 + 1 \cdot 5 = 10$.
*   Hit corner (since $5 == 5$). `stopped_at_corner` becomes true. Break loop.

Final position: $(10, 10)$.

The logic for `effective_k` needs to be precise. If $K$ is a multiple of 4, say $K=4$, then $K \pmod 4 = 0$. The loop for $i=0, 1, 2, 3$ will run. After 4 collisions, the direction vector will be back to its original state. So, if $K \pmod 4 = 0$, we should simulate 4 steps. If $K \pmod 4 = r$ where $r \neq 0$, we simulate $r$ steps. This is handled by setting `effective_k = K % 4; if (effective_k == 0) effective_k = 4;`.

The problem statement says "K collisions". If $K=1$, we simulate 1 collision. If $K=4$, we simulate 4 collisions.
The code implements this correctly.

## Complexity Analysis
- **Time Complexity**: $O(1)$
    The simulation loop runs at most 4 times (for `effective_k`). Inside the loop, operations are constant time. Therefore, the time complexity is constant, independent of $N$ and $K$.
- **Space Complexity**: $O(1)$
    We only use a few variables to store the current position, direction, and loop counters. The space used is constant.

## Solution Code
```cpp
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        long long N, K, x, y;
        cin >> N >> K >> x >> y;

        // The direction vector (dir_x, dir_y) cycles through (1,1) -> (-1,1) -> (-1,-1) -> (1,-1) -> (1,1)
        // every 4 collisions. So we only need to simulate K mod 4 steps.
        // If K mod 4 is 0, it means the 4th step in the cycle.
        long long effective_k = K % 4;
        if (effective_k == 0) {
            effective_k = 4;
        }

        long long curr_x = x;
        long long curr_y = y;
        long long dir_x = 1;
        long long dir_y = 1;

        bool stopped_at_corner = false;

        for (long long i = 0; i < effective_k; ++i) {
            long long dx_dist, dy_dist;

            // Calculate distance to the next vertical wall
            if (dir_x == 1) { // Moving right
                dx_dist = N - curr_x;
            } else { // Moving left
                dx_dist = curr_x;
            }

            // Calculate distance to the next horizontal wall
            if (dir_y == 1) { // Moving up
                dy_dist = N - curr_y;
            } else { // Moving down
                dy_dist = curr_y;
            }

            long long t_step = min(dx_dist, dy_dist);

            // Update position
            curr_x += dir_x * t_step;
            curr_y += dir_y * t_step;

            // Check if it hit a corner
            if (dx_dist == dy_dist) {
                stopped_at_corner = true;
                break; // Ball stops at a corner
            } else if (dx_dist < dy_dist) {
                // Hit a vertical wall
                dir_x = -dir_x;
            } else {
                // Hit a horizontal wall
                dir_y = -dir_y;
            }
        }

        cout << curr_x << " " << curr_y << endl;
    }

    return 0;
}
```