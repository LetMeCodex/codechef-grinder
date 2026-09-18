# [The Last Levels (LASTLEVELS)](https://www.codechef.com/problems/LASTLEVELS)

- **Difficulty Rating**: 679
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is playing a game consisting of $X$ levels. Each level takes $Y$ minutes to complete. After every 3 levels, Chef takes a break of $Z$ minutes. However, Chef does **not** take a break after completing the final level. We need to calculate the total time (playing time + break time) spent by Chef to complete the game.

## Intuition & Mathematical Observation
To solve this problem, we can break the total time into two components:

1.  **Playing Time**: Since every level takes $Y$ minutes and there are $X$ levels, the total time spent playing is simply $X \times Y$.
2.  **Break Time**: Breaks occur after every 3rd level, but not after the last one. 
    *   If $X=3$, there are 0 breaks.
    *   If $X=4$, there is 1 break (after level 3).
    *   If $X=6$, there is 1 break (after level 3, but not after level 6).
    *   If $X=7$, there are 2 breaks (after level 3 and level 6).

The number of breaks can be calculated using the formula: `(X - 1) / 3` using integer division. This formula effectively ignores the break that would have occurred after the final level if $X$ is a multiple of 3, and correctly counts the breaks for other values of $X$.

**Total Time = $(X \times Y) + (\lfloor \frac{X-1}{3} \rfloor \times Z)$**

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves basic arithmetic operations. For $T$ test cases, the complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has X levels to complete.
 * Each level takes Y minutes.
 * A break of Z minutes is taken after every 3 levels, 
 * but not after the final level if the game is completed.
 * 
 * Total time = (Total time spent playing) + (Total time spent on breaks)
 * Total time spent playing = X * Y
 * Number of breaks = (X - 1) / 3 (using integer division)
 * Total time spent on breaks = ((X - 1) / 3) * Z
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;

        // Calculate total playing time
        long long total_playing_time = x * y;

        // Calculate number of breaks
        // A break occurs after every 3 levels, but not after the last level.
        // If X = 3, breaks = 0. If X = 4, breaks = 1.
        // The formula (x - 1) / 3 correctly handles this.
        long long num_breaks = (x - 1) / 3;
        long long total_break_time = num_breaks * z;

        long long total_time = total_playing_time + total_break_time;

        cout << total_time << "\n";
    }

    return 0;
}
```