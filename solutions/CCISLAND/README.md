# [Chef On Island (CCISLAND)](https://www.codechef.com/problems/CCISLAND)
- **Difficulty Rating**: 878
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef is stranded on an island and needs to build a boat to escape. The boat will take `D` days to build. Chef currently has `x` units of food and `y` units of water. Each day, Chef consumes `xr` units of food and `yr` units of water. The problem asks us to determine if Chef has enough food and water to survive for `D` days while building the boat. If Chef can survive, output "YES"; otherwise, output "NO".

## Intuition & Mathematical Observation

The problem boils down to a straightforward comparison of available resources versus required resources over a specific period. To determine if Chef can survive for `D` days, we need to calculate the total amount of food and water Chef will consume during this period and then check if the current supplies are sufficient.

1.  **Total Food Required**: If Chef needs `xr` units of food per day for `D` days, the total food required will be `D * xr`.
2.  **Total Water Required**: Similarly, if Chef needs `yr` units of water per day for `D` days, the total water required will be `D * yr`.

Chef can successfully build the boat and survive *only if* both of the following conditions are met simultaneously:
*   The current food supply (`x`) must be greater than or equal to the total food required (`D * xr`).
*   The current water supply (`y`) must be greater than or equal to the total water required (`D * yr`).

If both conditions hold true, Chef can survive, and we print "YES". If even one of these conditions is false, Chef will run out of supplies, and we print "NO".

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    The solution involves a loop that iterates `T` times (for each test case). Inside the loop, we perform a fixed number of arithmetic operations (two multiplications) and comparisons, along with reading five integers and printing a string. All these operations take constant time. Therefore, the total time complexity is directly proportional to the number of test cases, `T`.

*   **Space Complexity**: $O(1)$
    The solution uses a constant amount of extra space. We only declare a few integer variables (`T, x, y, xr, yr, D, total_food_required, total_water_required`) to store input values and intermediate calculations. The memory usage does not scale with the magnitude of the input values (other than `T` itself, which determines how many times the constant memory is reused).

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard library headers

using namespace std; // Brings all names from the std namespace into the current scope

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of testcases
    while (T--) { // Loop T times, decrementing T in each iteration
        int x, y, xr, yr, D;
        // Read the five integers for the current testcase
        // x: current food supply
        // y: current water supply
        // xr: food required per day
        // yr: water required per day
        // D: number of days to build the boat
        cin >> x >> y >> xr >> yr >> D;

        // Calculate the total food required for D days.
        // The maximum value for D * xr is 10 * 10 = 100, which fits in an int.
        int total_food_required = D * xr;

        // Calculate the total water required for D days.
        // The maximum value for D * yr is 10 * 10 = 100, which fits in an int.
        int total_water_required = D * yr;

        // Check if Chef has sufficient supplies for both food and water.
        // Both conditions must be true for Chef to survive.
        if (x >= total_food_required && y >= total_water_required) {
            cout << "YES\n"; // If both conditions are met, Chef can reach the shore.
        } else {
            cout << "NO\n"; // Otherwise, Chef cannot reach the shore.
        }
    }

    return 0; // Indicate successful execution
}
```