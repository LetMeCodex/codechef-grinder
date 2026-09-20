# [Bucket and Water Flow (WATERFLOW)](https://www.codechef.com/problems/WATERFLOW)
- **Difficulty Rating**: 483
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the final state of a bucket after a certain amount of water has been added to it. We are given four integer values for each test case:
1.  `W`: The initial amount of water already present in the bucket.
2.  `X`: The maximum capacity of the bucket.
3.  `Y`: The rate at which water flows into the bucket per unit of time.
4.  `Z`: The total time for which water flows into the bucket.

Based on these values, we need to output one of three strings:
*   `"overflow"`: If the total water in the bucket exceeds its capacity.
*   `"filled"`: If the total water in the bucket exactly matches its capacity.
*   `"unfilled"`: If the total water in the bucket is less than its capacity.

## Intuition & Mathematical Observation

The core idea is to calculate the total amount of water that will be in the bucket after the flow, and then compare this total with the bucket's maximum capacity.

1.  **Calculate Water Added**: The problem states that water flows at a rate `Y` for `Z` units of time. The total amount of water added to the bucket during this period can be calculated by multiplying the rate by the time: `Water_Added = Y * Z`.

2.  **Calculate Total Potential Water**: The bucket initially contains `W` units of water. After `Water_Added` units flow in, the total potential water in the bucket will be `Total_Potential_Water = W + Water_Added`. We call it "potential" because if this amount exceeds the bucket's capacity, the excess will overflow, but for comparison, we consider this sum.

3.  **Compare with Capacity**: Now, we compare `Total_Potential_Water` with the bucket's maximum capacity `X`:
    *   If `Total_Potential_Water > X`: The bucket cannot hold all the water, so it will `overflow`.
    *   If `Total_Potential_Water == X`: The bucket is exactly full, so it is `filled`.
    *   If `Total_Potential_Water < X`: The bucket still has space, so it is `unfilled`.

This logic directly translates into a few arithmetic operations and conditional statements.

## Complexity Analysis

*   **Time Complexity**: $O(1)$ per test case.
    For each test case, the solution performs a constant number of arithmetic operations (one multiplication, one addition) and a constant number of comparisons. These operations take a fixed amount of time regardless of the input values (within integer limits). Since there are `T` test cases, the total time complexity will be $O(T)$.

*   **Space Complexity**: $O(1)$.
    The solution uses a fixed number of integer variables (`W`, `X`, `Y`, `Z`, `water_added`, `total_potential_water`, `T`) to store input and intermediate results. The memory usage does not grow with the input values or the number of test cases (beyond the fixed variables for the current test case). Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <iostream> // Required for standard input/output operations (cin, cout)
#include <bits/stdc++.h> // A common header in competitive programming that includes many standard libraries

// Using the standard namespace to avoid repeatedly writing std::
using namespace std;

// Function to solve a single test case
void solve() {
    int W, X, Y, Z;
    // Read the four space-separated integers for the current test case
    cin >> W >> X >> Y >> Z;

    // Calculate the total amount of water added to the bucket
    // Water flow rate (Y) * Time (Z)
    int water_added = Y * Z;

    // Calculate the total potential water level if the bucket could hold it all
    // Initial water (W) + Water added
    int total_potential_water = W + water_added;

    // Compare the total potential water with the maximum capacity (X)
    if (total_potential_water > X) {
        // If total water exceeds capacity, it overflows
        cout << "overflow\n";
    } else if (total_potential_water == X) {
        // If total water exactly matches capacity, it's filled
        cout << "filled\n";
    } else { // total_potential_water < X
        // If total water is less than capacity, it's unfilled
        cout << "unfilled\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    // Read the number of test cases
    cin >> T;
    // Loop T times, calling the solve function for each test case
    while (T--) {
        solve();
    }

    return 0; // Indicate successful execution
}
```