# Chef in his Office (OFFICE)
- **Difficulty Rating**: 532
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to calculate the total number of hours a chef works in a week. The chef works `X` hours per day from Monday to Thursday (4 days) and `Y` hours on Friday (1 day). We are given `X` and `Y` and need to output the total hours worked in a week.

## Intuition & Mathematical Observation
The problem is a straightforward calculation. We are given the working hours for two distinct periods:
1.  **Monday to Thursday**: This spans 4 days, and on each of these days, the chef works `X` hours.
2.  **Friday**: This is 1 day, and on this day, the chef works `Y` hours.

To find the total hours worked in a week, we simply need to sum the hours from these two periods.

*   Hours worked from Monday to Thursday = (Number of days) * (Hours per day) = $4 \times X$
*   Hours worked on Friday = $Y$

Therefore, the total hours worked in a week is the sum of these two:
Total Hours = $(4 \times X) + Y$

The constraints on `X` (2 <= X <= 12) and `Y` (1 <= Y < X) are small. The maximum possible value for total hours would be when X=12 and Y=11, which is $(4 \times 12) + 11 = 48 + 11 = 59$. This value easily fits within a standard integer type.

## Complexity Analysis
- **Time Complexity**: $O(T)$
    The program iterates through `T` test cases. For each test case, it performs a constant number of arithmetic operations (multiplication and addition) and input/output operations. Thus, the time complexity is directly proportional to the number of test cases, `T`.

- **Space Complexity**: $O(1)$
    The program uses a fixed amount of memory to store variables like `t`, `x`, `y`, and `total_hours`, regardless of the input size or the number of test cases. Therefore, the space complexity is constant.

## Solution Code
```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The employee works for X hours from Monday to Thursday (4 days).
 * The employee works for Y hours on Friday (1 day).
 * Total hours = (4 * X) + Y.
 * 
 * Constraints:
 * T <= 100
 * 2 <= X <= 12
 * 1 <= Y < X
 * 
 * Since X and Y are small, the result will fit in a standard integer.
 * Time Complexity: O(T)
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    // Read the number of test cases
    if (!(cin >> t)) return 0;
    
    // Process each test case
    while (t--) {
        long long x, y;
        // Read the working hours for X and Y
        if (cin >> x >> y) {
            // Calculate total hours: 4 days of X hours + 1 day of Y hours
            long long total_hours = (4 * x) + y;
            // Output the total hours
            cout << total_hours << "\n";
        }
    }

    return 0;
}
```