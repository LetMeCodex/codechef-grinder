# Can Chef (CANCHEF)

- **Difficulty Rating**: 471
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef wants to travel to DAIICT and return home. The distance to DAIICT is $Y$ kilometers. Chef has $X$ liters of petrol. The car consumes 1 liter of petrol for every 15 kilometers. Determine if Chef has enough petrol to complete the round trip.

## Intuition & Mathematical Observation

The core of the problem lies in comparing the total distance Chef needs to travel with the maximum distance Chef can travel with the available petrol.

1.  **Total Distance to Travel**: Chef needs to go to DAIICT and then return home. So, the total distance is $Y$ (to DAIICT) + $Y$ (back home) = $2 \times Y$ kilometers.

2.  **Maximum Distance Possible with Available Petrol**: Chef has $X$ liters of petrol, and the car runs 15 kilometers per liter. Therefore, the maximum distance Chef can cover is $X \times 15$ kilometers.

3.  **Condition for Success**: Chef can complete the journey if and only if the maximum distance they can travel is greater than or equal to the total distance they need to travel.
    Mathematically, this condition is:
    $X \times 15 \ge 2 \times Y$

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The solution involves a fixed number of arithmetic operations and comparisons for each test case. The number of test cases is read once, and then a constant amount of work is done per test case. Thus, the time complexity is constant.

-   **Space Complexity**: $O(1)$
    The solution uses a fixed number of variables ($T$, $X$, $Y$, `total_distance_needed`, `max_distance_possible`) regardless of the input size. Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Using the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can speed up I/O operations.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // further speeding up I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases from input

    // Loop through each test case
    while (T--) {
        int X, Y; // Variables to store the amount of petrol (X liters)
                  // and the distance to DAIICT (Y kilometers)
        cin >> X >> Y; // Read X and Y for the current test case

        // Chef needs to travel to DAIICT and then return home.
        // So, the total distance to be covered is twice the distance to DAIICT.
        int total_distance_needed = 2 * Y;

        // The car runs 15 kilometers using 1 liter of petrol.
        // With X liters of petrol, Chef can cover a maximum distance of X * 15 kilometers.
        int max_distance_possible = X * 15;

        // Determine if Chef has enough petrol to cover the total required distance.
        // If the maximum distance Chef can cover is greater than or equal to
        // the total distance needed, then it's possible.
        if (max_distance_possible >= total_distance_needed) {
            cout << "YES\n"; // Print YES if it's possible
        } else {
            cout << "NO\n"; // Print NO otherwise
        }
    }

    return 0; // Indicate successful program execution
}
```