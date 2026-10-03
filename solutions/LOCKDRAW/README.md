# [Chef and Lockout Draws (LOCKDRAW)](https://www.codechef.com/problems/LOCKDRAW)
- **Difficulty Rating**: 982
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a "lockout draw" is possible given three integer scores, `A`, `B`, and `C`. A lockout draw is defined as a scenario where one person's score is exactly equal to the sum of the other two people's scores. We need to output "YES" if such a draw is possible, and "NO" otherwise. This check needs to be performed for multiple test cases.

## Intuition & Mathematical Observation

The core of this problem lies in understanding the definition of a "lockout draw". The problem statement clearly defines it: "one person's score is equal to the sum of the other two people's scores".

Let the three given scores be `A`, `B`, and `C`. We need to check if any of the following three conditions hold true:

1.  **Is `A` equal to the sum of `B` and `C`?** (i.e., `A == B + C`)
2.  **Is `B` equal to the sum of `A` and `C`?** (i.e., `B == A + C`)
3.  **Is `C` equal to the sum of `A` and `B`?** (i.e., `C == A + B`)

If *any* of these three conditions are met, then a lockout draw is possible, and we should output "YES". If none of these conditions are met, then a lockout draw is not possible, and we should output "NO".

This is a straightforward conditional check. No complex algorithms, data structures, or mathematical theorems are required beyond basic arithmetic and logical operations.

## Complexity Analysis

*   **Time Complexity**: $O(1)$ per test case.
    For each test case, we read three integers and perform a fixed number of arithmetic operations (two additions) and comparisons (three equality checks and two logical OR operations). These operations take constant time, regardless of the magnitude of the input integers (within standard integer limits). Therefore, the time complexity for processing a single test case is constant. If there are $T$ test cases, the total time complexity will be $O(T)$.

*   **Space Complexity**: $O(1)$ per test case.
    We only use a few integer variables (`A`, `B`, `C`, and `T`) to store the input values and loop counter. The amount of memory used does not depend on the input values themselves (other than the fixed number of variables). Thus, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common headers like iostream

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

// Function to solve a single test case
void solve() {
    int A, B, C;
    // Read the three problem scores
    cin >> A >> B >> C;

    // Check if any of the three conditions for a draw are met:
    // 1. Bob solves A, Alice solves B and C (A == B + C)
    // 2. Bob solves B, Alice solves A and C (B == A + C)
    // 3. Bob solves C, Alice solves A and B (C == A + B)
    if (A == B + C || B == A + C || C == A + B) {
        cout << "YES\n"; // If any condition is true, a draw is possible
    } else {
        cout << "NO\n";  // Otherwise, a draw is not possible
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