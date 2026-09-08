# [Reach on Time (TIMELY)](https://www.codechef.com/problems/TIMELY)
- **Difficulty Rating**: 279
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef needs exactly 30 minutes to travel from his home to the office. He leaves his home `X` minutes before the official deadline. We need to determine if Chef will reach the office on time or early. If he reaches on time or early, output "YES"; otherwise, output "NO".

## Intuition & Mathematical Observation

The core of this problem is a simple comparison. Chef requires 30 minutes to reach the office. He has `X` minutes available before the deadline.

*   If the time Chef has available (`X`) is greater than or equal to the time he needs (30 minutes), he will reach the office on time or even early. In this scenario, the answer is "YES".
*   If the time Chef has available (`X`) is less than the time he needs (30 minutes), he will be late. In this scenario, the answer is "NO".

This translates directly to the condition: `X >= 30`.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    For each test case, we perform a single integer read, a comparison, and a print operation. These are all constant time operations, $O(1)$. Since there are `T` test cases, the total time complexity is $T \times O(1) = O(T)$. Given the constraint $1 \le T \le 60$, this is extremely efficient.

*   **Space Complexity**: $O(1)$
    We only use a few integer variables to store `t` (number of test cases) and `x` (minutes available). The amount of memory used does not depend on the input size `X` or `T`, making it constant space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef needs 30 minutes to reach the office.
 * Chef leaves X minutes before the deadline.
 * If X >= 30, Chef reaches on time or early (YES).
 * If X < 30, Chef reaches late (NO).
 * 
 * Constraints: 1 <= T <= 60, 1 <= X <= 60.
 * Time Complexity: O(T)
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O setup to speed up input/output operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    // Read the number of test cases. If input fails, return 0.
    if (!(cin >> t)) return 0;
    
    // Loop through each test case
    while (t--) {
        int x;
        // Read the minutes Chef has available
        cin >> x;
        
        // Check if the time taken (30 minutes) is less than or equal to 
        // the time available (X minutes).
        if (x >= 30) {
            // If X is 30 or more, Chef reaches on time or early.
            cout << "YES" << "\n";
        } else {
            // If X is less than 30, Chef reaches late.
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}

```