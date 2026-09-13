# [MATH1 Enrolment (M1ENROL)](https://www.codechef.com/problems/M1ENROL)
- **Difficulty Rating**: 349
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the minimum number of additional seats required in a classroom. We are given two integers: $X$, representing the number of available seats, and $Y$, representing the number of students who want to enroll. If the number of students $Y$ exceeds the available seats $X$, we need to calculate how many more seats must be added to accommodate all students. If $Y$ is less than or equal to $X$, no additional seats are needed.

## Intuition & Mathematical Observation

The core of the problem lies in a simple comparison:

1.  **Case 1: More students than seats ($Y > X$)**
    If the number of interested students ($Y$) is greater than the available seats ($X$), we have a deficit. To accommodate all $Y$ students, we need to increase the number of seats from $X$ to $Y$. The number of additional seats required will be the difference: $Y - X$.

2.  **Case 2: Enough or more seats than students ($Y \le X$)**
    If the number of interested students ($Y$) is less than or equal to the available seats ($X$), it means we already have enough seats (or even more than needed). In this scenario, no additional seats are required. The answer is $0$.

Combining these two cases, the number of additional seats needed can be expressed mathematically as $\max(0, Y - X)$. This formula elegantly covers both scenarios: if $Y > X$, then $Y - X$ is positive, and $\max(0, Y - X)$ yields $Y - X$. If $Y \le X$, then $Y - X$ is zero or negative, and $\max(0, Y - X)$ yields $0$.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    The program reads an integer $T$ indicating the number of test cases. For each test case, it performs a constant number of operations: reading two integers ($X$ and $Y$), a comparison, a subtraction (if needed), and printing the result. Since these operations take constant time, the total time complexity is directly proportional to the number of test cases, $T$. Given $T \le 100$, this is extremely efficient.

*   **Space Complexity**: $O(1)$
    The program uses a fixed amount of memory regardless of the input values $X$ and $Y$. It only stores a few variables like `t`, `x`, and `y`. No data structures that grow with input size are used. Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common headers like iostream

// Using the standard namespace to avoid writing std:: repeatedly
using namespace std;

/**
 * Problem Analysis:
 * We are given X seats and Y interested students.
 * If Y > X, we need to add (Y - X) seats to accommodate all students.
 * If Y <= X, we already have enough seats, so we need to add 0 seats.
 * This can be represented as max(0, Y - X).
 * 
 * Constraints:
 * T <= 100
 * X, Y <= 10^5
 * The result will fit in a standard integer, but using long long is safe practice.
 */

int main() {
    // Fast I/O for competitive programming
    // Disables synchronization with C's stdio library and unties cin from cout.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    // Read the number of test cases. If input fails (e.g., EOF), return 0.
    if (!(cin >> t)) return 0;
    
    // Loop through each test case
    while (t--) {
        long long x, y; // Use long long for x and y to be safe, though int would suffice for 10^5
        cin >> x >> y; // Read the number of seats and students for the current test case
        
        // Apply the logic: if students > seats, calculate the difference; otherwise, 0.
        if (y > x) {
            cout << (y - x) << "\n"; // Print the required additional seats
        } else {
            cout << 0 << "\n";       // Print 0 if no additional seats are needed
        }
    }
    
    return 0; // Indicate successful execution
}

```