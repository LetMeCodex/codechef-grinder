# [A - Save Water Save Life (SAVWATER)](https://www.codechef.com/problems/SAVWATER)
- **Difficulty Rating**: 918
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to determine if a total available amount of water, `C`, is sufficient to meet the needs of `H` households, given their water consumption patterns. Each household has a mandatory freshwater requirement of `x` liters. Additionally, they have a greywater-eligible use of `y` liters, which, after a campaign, can be met by using half the amount of greywater (i.e., `y/2` liters). We need to output "YES" if `C` is enough, and "NO" otherwise.

## Intuition & Mathematical Observation
The core of the problem lies in calculating the total water consumption per household after the campaign and then scaling it up for all `H` households.

1.  **Water Consumption per Household:**
    *   Each household requires `x` liters of freshwater. This is a fixed mandatory amount.
    *   For the greywater-eligible use, `y` liters are initially considered. The campaign reduces the required amount for this use to half, which is `y / 2`. In integer arithmetic, `y / 2` naturally performs the floor operation for positive `y`, which is what we need.
    *   Therefore, the total water consumption for a single household after the campaign is `x + (y / 2)` liters.

2.  **Total Water Needed:**
    *   If there are `H` households, and each consumes `x + (y / 2)` liters, the total water needed is `H * (x + (y / 2))` liters.

3.  **Comparison with Available Water:**
    *   We are given a total available water amount `C`.
    *   We need to check if the `total_water_needed` is less than or equal to `C`.
    *   If `H * (x + (y / 2)) <= C`, then the answer is "YES".
    *   Otherwise, the answer is "NO".

The constraints on `H`, `x`, `y`, and `C` are up to 1000. The maximum possible value for `H * (x + (y/2))` would be `1000 * (1000 + 1000/2) = 1000 * (1000 + 500) = 1000 * 1500 = 1,500,000`. This value fits comfortably within a standard 32-bit integer type. However, using `long long` for `total_water_needed` is a good defensive programming practice to avoid potential overflow issues in similar problems with larger constraints.

## Complexity Analysis
-   **Time Complexity**: $O(1)$
    The solution involves a fixed number of arithmetic operations (addition, division, multiplication, comparison) and input/output operations per test case. The number of operations does not depend on the input values `H`, `x`, `y`, or `C` in terms of scaling. Since the problem involves `T` test cases, the total time complexity is $O(T)$.

-   **Space Complexity**: $O(1)$
    The solution uses a constant amount of extra space to store variables like `H`, `x`, `y`, `C`, `water_per_household`, `total_water_needed`, and `T`. This space requirement does not grow with the input size.

## Solution Code
```cpp
#include <iostream> // Include only necessary headers

// Use the standard namespace
using namespace std;

void solve() {
    int H, x, y, C;
    // Read the four integers for the current test case
    cin >> H >> x >> y >> C;

    // Calculate the water consumption for a single household after the campaign.
    // x liters are for mandatory freshwater use.
    // y liters for greywater-eligible use are reduced to floor(y/2).
    // In C++, integer division `y / 2` automatically performs floor(y/2) for positive y.
    int water_per_household = x + (y / 2);

    // Calculate the total water needed for all H households.
    // The maximum value for H * water_per_household is 1000 * (1000 + 1000/2) = 1,500,000.
    // This fits within an 'int'. Using 'long long' is good practice but not strictly needed here.
    long long total_water_needed = (long long)H * water_per_household;

    // Compare the total water needed with the total available water C.
    if (total_water_needed <= C) {
        // If sufficient water is available, print "YES".
        cout << "YES\n";
    } else {
        // Otherwise, print "NO".
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    // Read the number of test cases
    cin >> T;
    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}
```