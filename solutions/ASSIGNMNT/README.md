# [Pending Assignments (ASSIGNMNT)](https://www.codechef.com/problems/ASSIGNMNT)
- **Difficulty Rating**: 468
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if Chef can complete a set of assignments within a given timeframe. Specifically, Chef has `X` assignments, and each assignment takes `Y` minutes to complete. He has `Z` days available to finish all of them. We need to output "YES" if he can complete all assignments within the available time, and "NO" otherwise.

## Intuition & Mathematical Observation

The core idea to solve this problem is to compare the total time Chef *needs* to complete all assignments with the total time Chef *has available*.

1.  **Calculate Total Time Needed**:
    *   Chef has `X` assignments.
    *   Each assignment takes `Y` minutes.
    *   Therefore, the total time required to complete all assignments is `X * Y` minutes.

2.  **Calculate Total Time Available**:
    *   Chef has `Z` days available.
    *   We need to convert days into minutes to compare it with the time needed.
    *   We know:
        *   1 day = 24 hours
        *   1 hour = 60 minutes
    *   So, 1 day = 24 hours/day \* 60 minutes/hour = 1440 minutes/day.
    *   Therefore, `Z` days = `Z * 1440` minutes.

3.  **Compare and Conclude**:
    *   If the `total_time_needed` is less than or equal to the `total_time_available`, Chef can complete the assignments. In this case, we print "YES".
    *   Otherwise, if `total_time_needed` is greater than `total_time_available`, Chef cannot complete the assignments. In this case, we print "NO".

Given the constraints (`X, Y <= 100`, `Z <= 10`), the maximum values for `total_time_needed` (`100 * 100 = 10000`) and `total_time_available` (`10 * 1440 = 14400`) are relatively small and fit comfortably within a standard 32-bit integer type. However, using `long long` for calculations is a good practice in competitive programming to prevent potential overflows, especially if constraints were larger.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    *   For each test case, the solution performs a fixed number of arithmetic operations (multiplications, comparisons) and input/output operations. These operations take constant time regardless of the input values `X`, `Y`, and `Z`.
    *   Since there are `T` test cases, the total time complexity will be $O(T)$.

-   **Space Complexity**: $O(1)$
    *   The solution uses a fixed number of variables (`X`, `Y`, `Z`, `total_time_needed`, `total_time_available`) to store input and intermediate results. The memory usage does not depend on the magnitude of the input values.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries
using namespace std; // Uses the standard namespace

void solve() {
    int X, Y, Z;
    // Read the number of assignments (X), time per assignment (Y), and days available (Z)
    cin >> X >> Y >> Z;

    // Calculate the total time required to complete all assignments in minutes.
    // X assignments * Y minutes/assignment = total minutes needed.
    // Using long long for calculation to prevent potential overflow,
    // though for given constraints (X, Y <= 100), int would also suffice.
    long long total_time_needed = (long long)X * Y;

    // Calculate the total time available in minutes.
    // 1 day = 24 hours
    // 1 hour = 60 minutes
    // So, 1 day = 24 * 60 = 1440 minutes.
    // Z days * 1440 minutes/day = total minutes available.
    // Using long long for calculation, though for given constraints (Z <= 10),
    // int would also suffice.
    long long total_time_available = (long long)Z * 24 * 60;

    // Compare the total time needed with the total time available.
    // If Chef needs less than or equal to the time available, he can complete them.
    if (total_time_needed <= total_time_available) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin/cout from C's stdio and prevents flushing cout before cin.
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