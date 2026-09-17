# [Watching Movies at 2x (MOVIE2X)](https://www.codechef.com/problems/MOVIE2X)

- **Difficulty Rating**: 628
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to watch a movie of total duration $X$ minutes. He decides to watch the first $Y$ minutes at $2\times$ speed and the remaining $(X - Y)$ minutes at normal ($1\times$) speed. We need to calculate the total time Chef spends watching the movie.

## Intuition & Mathematical Observation
The total time spent is the sum of the time taken for the two segments:
1. **First segment**: The first $Y$ minutes are watched at $2\times$ speed. Since speed is doubled, the time taken is halved:
   $$\text{Time}_1 = \frac{Y}{2}$$
2. **Second segment**: The remaining $(X - Y)$ minutes are watched at $1\times$ speed. The time taken remains the same:
   $$\text{Time}_2 = X - Y$$

Combining these, the total time is:
$$\text{Total Time} = \frac{Y}{2} + (X - Y)$$

Given that $Y$ is guaranteed to be even, the division $\frac{Y}{2}$ will always result in an integer, ensuring no precision issues.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves only basic arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The movie has a total duration of X minutes.
 * The first Y minutes are watched at 2x speed, meaning it takes Y/2 minutes to watch.
 * The remaining (X - Y) minutes are watched at 1x speed, meaning it takes (X - Y) minutes.
 * Total time = (Y / 2) + (X - Y).
 * 
 * Constraints:
 * 1 <= X, Y <= 1000
 * Y is even.
 * Time complexity: O(1) per test case.
 * Space complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long X, Y;
    if (cin >> X >> Y) {
        // Calculate time spent:
        // First Y minutes at 2x speed = Y / 2
        // Remaining X - Y minutes at 1x speed = X - Y
        long long total_time = (Y / 2) + (X - Y);
        
        cout << total_time << "\n";
    }

    return 0;
}
```