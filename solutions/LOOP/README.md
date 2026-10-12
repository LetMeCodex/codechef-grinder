# [Circular Track (LOOP)](https://www.codechef.com/problems/LOOP)
- **Difficulty Rating**: 838
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a circular track of length $M$. There are two checkpoints on this track, labeled $A$ and $B$. We are also given the positions of these checkpoints, $a$ and $b$, respectively, as integers between $1$ and $M$. We need to find the minimum distance between checkpoint $A$ and checkpoint $B$ along the circular track.

## Intuition & Mathematical Observation
The key insight for this problem is that on a circular track, there are always two possible paths between any two points.

Let the total length of the circular track be $M$. The positions of the two checkpoints are $a$ and $b$.

Without loss of generality, let's assume $a \le b$. This simplifies our calculations. If $a > b$, we can simply swap them.

There are two ways to travel from checkpoint $A$ to checkpoint $B$:

1.  **Clockwise direction (or the direct path):** The distance in this direction is simply the difference between their positions: $b - a$.

2.  **Counter-clockwise direction (or the longer path):** To travel in this direction, we can imagine going from $a$ to the end of the track ($M$), then from $M$ back to $1$, and then from $1$ to $b$. However, a more direct way to think about it is that the total length of the track is $M$. If one path has a length of $d_1$, the other path must have a length of $M - d_1$. So, the distance in the counter-clockwise direction is $M - (b - a)$.

The problem asks for the *minimum* distance between $A$ and $B$. Therefore, we need to calculate both distances and choose the smaller one.

So, the minimum distance is $\min(b - a, M - (b - a))$.

If we don't assume $a \le b$ initially, we can calculate the absolute difference $|a - b|$. Let this be $d_{abs} = |a - b|$.
Then the two distances are $d_{abs}$ and $M - d_{abs}$.
The minimum distance is $\min(d_{abs}, M - d_{abs})$.

The provided solution code first ensures that $a$ is the smaller checkpoint by using `std::swap` if $a > b$. This makes the calculation of `dist1` as `b - a` straightforward and always positive. Then, `dist2` is calculated as `m - dist1`, representing the distance in the other direction. Finally, `std::min(dist1, dist2)` returns the shortest path.

## Complexity Analysis
- **Time Complexity**: $O(1)$
    The solution involves a fixed number of arithmetic operations (comparison, subtraction, addition, and `min`) and a single loop that runs $t$ times. Inside the loop, all operations are constant time. Therefore, for $t$ test cases, the total time complexity is $O(t)$. However, if we consider the complexity per test case, it is $O(1)$.

- **Space Complexity**: $O(1)$
    The solution uses a fixed number of variables (`t`, `a`, `b`, `m`, `dist1`, `dist2`) regardless of the input size. Thus, the space complexity is constant.