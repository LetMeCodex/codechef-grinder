# [Run for Fun (RURT)](https://www.codechef.com/problems/RURT)
- **Difficulty Rating**: 375
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the number of times Chef will stop to rest during a race. Chef needs to run a total distance of `Y` kilometers. He takes a rest after every `X` kilometers. We need to count how many times Chef rests *before* reaching the finish line. This means a rest counts only if the distance covered at the rest point is strictly less than the total race distance `Y`.

## Intuition & Mathematical Observation

Chef rests at distances `X`, `2*X`, `3*X`, and so on. Let's say Chef takes `k` rests. The `k`-th rest occurs at `k * X` kilometers.

According to the problem statement, Chef rests *before* reaching the finish line. This implies that the distance covered at the rest point must be strictly less than the total race distance `Y`. So, we are looking for the number of positive integer values `k` such that:
`k * X < Y`

To find the maximum such integer `k`, we can rearrange the inequality:
`k < Y / X`

Since `k` must be an integer, the largest possible integer `k` that satisfies this condition is `floor((Y - 1) / X)`.
Let's verify with examples:

1.  **Example 1**: `X = 3`, `Y = 10`
    *   Chef rests at 3km, 6km, 9km.
    *   At 12km (`4*3`), Chef would have passed the finish line (10km).
    *   So, Chef rests 3 times.
    *   Using the formula: `(10 - 1) / 3 = 9 / 3 = 3`. This matches.

2.  **Example 2**: `X = 3`, `Y = 9`
    *   Chef rests at 3km, 6km.
    *   At 9km (`3*3`), Chef is exactly at the finish line. The problem states "before reaching the finish line", so this rest does not count.
    *   So, Chef rests 2 times.
    *   Using the formula: `(9 - 1) / 3 = 8 / 3 = 2` (integer division). This matches.

The C++ integer division `(Y - 1) / X` correctly computes `floor((Y - 1) / X)` for positive `Y` and `X`.

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    The solution involves reading two integers, performing a single subtraction and a single division, and then printing the result. All these operations take constant time, regardless of the magnitude of `X` and `Y`.

*   **Space Complexity**: $O(1)$
    The solution uses a fixed number of variables (`X`, `Y`, `rests`) to store input and intermediate results. The memory usage does not scale with the input values.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // Use the standard namespace as requested.
    using namespace std;

    int X, Y;
    // Read the two space-separated integers X and Y.
    // X: kilometers Chef can run before needing a rest.
    // Y: total distance of the race in kilometers.
    cin >> X >> Y;

    // Calculate the number of times Chef will stop to rest before reaching the finish line.
    // Chef rests after every X kilometers. A rest counts if the distance covered
    // at the rest point is strictly less than the total race distance Y.
    // We are looking for the count of positive integers 'k' such that 'k * X < Y'.
    // This inequality is equivalent to 'k < Y / X'.
    // Since 'k' must be an integer, the largest possible 'k' is floor((Y - 1) / X).
    // The number of such positive integers 'k' is precisely floor((Y - 1) / X).
    // In C++, integer division for positive numbers automatically performs the floor operation.
    int rests = (Y - 1) / X;

    // Print the calculated number of rests, followed by a newline character.
    cout << rests << "\n";

    return 0; // Indicate successful execution.
}
```