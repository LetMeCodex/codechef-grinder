# [Tourist (TOURIST)](https://www.codechef.com/problems/TOURIST)
- **Difficulty Rating**: 706
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to help Chef find the closest attraction to his current location. For each test case, Chef is at a specific coordinate `(A, B)`. There are `N` attractions, each with its own coordinates `(X, Y)`. We need to find the minimum Manhattan distance from Chef's current location `(A, B)` to any of the `N` attractions. The Manhattan distance between two points `(x1, y1)` and `(x2, y2)` is defined as `|x1 - x2| + |y1 - y2|`.

## Intuition & Mathematical Observation

The core of this problem lies in understanding and correctly applying the Manhattan distance formula.

1.  **Manhattan Distance**: For any two points `(x1, y1)` and `(x2, y2)`, the Manhattan distance is calculated as `|x1 - x2| + |y1 - y2|`. This represents the distance if you can only move horizontally or vertically, like navigating city blocks.

2.  **Finding the Minimum**: To find the minimum distance to *any* of the `N` attractions, we can iterate through each attraction one by one.
    *   We'll maintain a variable, say `min_distance`, initialized to a very large value (e.g., the maximum possible integer value).
    *   For each attraction `(X, Y)`:
        *   Calculate its Manhattan distance from Chef's location `(A, B)`: `current_distance = abs(A - X) + abs(B - Y)`.
        *   Compare `current_distance` with `min_distance`. If `current_distance` is smaller, update `min_distance` to `current_distance`.

3.  **Final Result**: After checking all `N` attractions, `min_distance` will hold the smallest Manhattan distance from Chef's location to any of the attractions.

This approach is straightforward and doesn't require any complex data structures or algorithms beyond basic arithmetic and comparison.

## Complexity Analysis

*   **Time Complexity**: $O(T \cdot N)$
    *   For each test case (`T` of them):
        *   Reading `N, A, B` takes constant time, $O(1)$.
        *   We then loop `N` times, once for each attraction.
        *   Inside the loop, reading `X, Y`, calculating the Manhattan distance (`abs` and `+`), and updating `min_distance` (`min`) all take constant time, $O(1)$.
        *   Therefore, for one test case, the operations take $O(N)$ time.
    *   Since there are `T` test cases, the total time complexity is $O(T \cdot N)$.

*   **Space Complexity**: $O(1)$
    *   For each test case, we only store a few integer variables (`N, A, B, X, Y, min_distance, current_distance`). The amount of memory used does not depend on the input size `N` or `T`. Hence, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, cmath, algorithm, limits, etc.

// Use the standard namespace as requested
using namespace std;

void solve() {
    int N, A, B;
    cin >> N >> A >> B;

    // Initialize min_distance with the maximum possible integer value.
    // This ensures that any valid distance calculated will be smaller
    // and correctly update min_distance.
    int min_distance = numeric_limits<int>::max();

    for (int i = 0; i < N; ++i) {
        int X, Y;
        cin >> X >> Y;

        // Calculate Manhattan distance between Chef's current position (A, B)
        // and the current attraction (X, Y).
        // Manhattan distance = |x1 - x2| + |y1 - y2|
        int current_distance = abs(A - X) + abs(B - Y);

        // Update min_distance if the current attraction is closer.
        min_distance = min(min_distance, current_distance);
    }

    // Output the minimum distance found for the current test case.
    cout << min_distance << "\n";
}

int main() {
    // Enable fast I/O operations. This is a standard optimization in competitive programming
    // to speed up input and output, especially for problems with large I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function to handle the current test case
    }

    return 0; // Indicate successful program execution
}
```