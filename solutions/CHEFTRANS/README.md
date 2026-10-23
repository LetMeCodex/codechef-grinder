# [Chef and Vacation Transportation (CHEFTRANS)](https://www.codechef.com/problems/CHEFTRANS)
- **Difficulty Rating**: 855
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef needs to travel from his home to his office. He has two transportation options:
1.  **Plane and Bus**: This option involves taking a plane for `X` minutes and then a bus for `Y` minutes.
2.  **Direct Train**: This option involves taking a direct train for `Z` minutes.

The task is to determine which option is faster. If the "Plane and Bus" option is faster, print "PLANEBUS". If the "Direct Train" option is faster, print "TRAIN". If both options take the same amount of time, print "EQUAL". This needs to be done for `T` test cases.

## Intuition & Mathematical Observation

The problem boils down to a simple comparison. We need to calculate the total time taken for the "Plane and Bus" option and then compare it with the time taken for the "Direct Train" option.

1.  **Calculate total time for "Plane and Bus"**: This is simply the sum of the plane travel time (`X`) and the bus travel time (`Y`). Let's call this `total_plane_bus_time = X + Y`.
2.  **Compare the times**:
    *   If `total_plane_bus_time < Z`, then "Plane and Bus" is faster.
    *   If `total_plane_bus_time > Z`, then "Direct Train" is faster.
    *   If `total_plane_bus_time == Z`, then both options take the same time.

The problem constraints state that `X, Y, Z` can be up to $10^9$. The sum `X + Y` can therefore be up to $2 \times 10^9$. A standard 32-bit signed integer in C++ can typically hold values up to approximately $2.1 \times 10^9$, which is sufficient to store `X`, `Y`, `Z`, and their sum `X + Y` without any overflow issues.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    *   The program reads `T` test cases.
    *   For each test case, it performs a fixed number of operations: reading three integers, one addition, and two comparisons. These are all constant-time operations.
    *   Therefore, the total time taken is directly proportional to the number of test cases `T`.

*   **Space Complexity**: $O(1)$
    *   The program uses a constant amount of extra space regardless of the input values or the number of test cases. It only stores a few integer variables (`T`, `X`, `Y`, `Z`, `plane_bus_total_time`).

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries, as requested.

// Using namespace std; as requested for competitive programming convenience.
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming to prevent TLE (Time Limit Exceeded)
    // on problems with large input/output.
    ios_base::sync_with_stdio(false); // Unties C++ streams from C standard streams.
    cin.tie(NULL);                   // Unties cin from cout, preventing flushes.

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int X, Y, Z; // Declare integer variables X, Y, Z to store the travel times.
        // X: time for flight, Y: time for bus, Z: time for direct train.
        cin >> X >> Y >> Z; // Read X, Y, and Z for the current test case.

        // Calculate the total time taken for the "Plane and Bus" route.
        // X and Y can be up to 10^9. Their sum (X + Y) can be up to 2 * 10^9.
        // A standard 32-bit signed integer can hold values up to approximately 2.1 * 10^9,
        // so 'int' is sufficient to store this sum without overflow.
        int plane_bus_total_time = X + Y;

        // Compare the total time for the "Plane and Bus" route with the "Train" route time.
        if (plane_bus_total_time < Z) {
            // If Plane and Bus is faster, print "PLANEBUS".
            cout << "PLANEBUS\n";
        } else if (plane_bus_total_time > Z) {
            // If Train is faster, print "TRAIN".
            cout << "TRAIN\n";
        } else { // This condition implies plane_bus_total_time == Z
            // If both options take the same amount of time, print "EQUAL".
            cout << "EQUAL\n";
        }
    }

    return 0; // Indicate successful program execution.
}
```