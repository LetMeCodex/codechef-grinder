# [Painting Walls (PAINTCHRIS)](https://www.codechef.com/problems/PAINTCHRIS)
- **Difficulty Rating**: 567
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef has a budget of `Z` rupees. He wants to paint walls, each of which is `X` meters long and `Y` meters wide. The cost of painting is 2 rupees per square meter. The task is to determine the maximum number of *complete* walls Chef can paint within his budget.

## Intuition & Mathematical Observation

The problem asks us to find how many complete units (walls) can be afforded given a total budget and the cost per unit.

1.  **Calculate the area of one wall**: Each wall is a rectangle with length `X` and width `Y`. The area of one wall is simply `X * Y` square meters.
2.  **Calculate the cost to paint one wall**: The painting cost is 2 rupees per square meter. So, to paint one entire wall, the cost will be `(Area of one wall) * 2`.
3.  **Calculate the maximum number of walls**: Chef has a total budget `Z`. To find out how many complete walls he can paint, we divide his total budget by the cost of painting one wall. Since Chef can only paint *complete* walls, we must use integer division. Integer division automatically truncates any fractional part, effectively giving us the floor of the division, which is exactly what we need (e.g., if he can afford 2.5 walls, he can only paint 2 complete walls).

So, the formula will be:
`Number of walls = Z / ( (X * Y) * 2 )`

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    The program processes `T` test cases. For each test case, it performs a fixed number of arithmetic operations (multiplications, division) and input/output operations. These operations take constant time, independent of the input values `X`, `Y`, or `Z`. Therefore, the total time complexity is directly proportional to the number of test cases, `T`.

*   **Space Complexity**: $O(1)$
    The program uses a few integer variables to store `T`, `X`, `Y`, `Z`, and intermediate calculations (`area_per_wall`, `cost_per_wall`, `max_walls`). The amount of memory used is constant and does not depend on the input values or the number of test cases.

## Solution Code

```cpp
#include <bits/stdc++.h> // Include all standard libraries

using namespace std; // Use the standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin/cout from the C standard streams and disables synchronization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) {
        int X, Y, Z;
        cin >> X >> Y >> Z; // Read the dimensions (X, Y) and budget (Z) for the current test case

        // Calculate the area of a single wall.
        // X and Y are in meters, so X * Y gives area in square meters.
        int area_per_wall = X * Y;

        // Calculate the total cost to paint one wall completely.
        // The cost is 2 rupees per square meter.
        int cost_per_wall = area_per_wall * 2;

        // Calculate the maximum number of walls Chef can paint completely.
        // This is the total budget divided by the cost of one wall.
        // Integer division automatically truncates the decimal part,
        // effectively performing the floor operation, which is what we need
        // since Chef can only paint a whole number of walls completely.
        // Note: cost_per_wall will always be at least 2 (since X, Y >= 1),
        // so division by zero is not possible.
        int max_walls = Z / cost_per_wall;

        // Output the result for the current test case, followed by a newline.
        cout << max_walls << "\n";
    }

    return 0; // Indicate successful execution
}
```