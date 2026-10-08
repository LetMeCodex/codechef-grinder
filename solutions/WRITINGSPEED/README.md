# [Writing Speed (WRITINGSPEED)](https://www.codechef.com/problems/WRITINGSPEED)
- **Difficulty Rating**: 271
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if Rahul can complete a 5-page assignment within a 60-minute deadline. We are given `X`, the time in minutes Rahul takes to write a single page. We need to output "YES" if he can finish on time, and "NO" otherwise.

## Intuition & Mathematical Observation

The core of this problem is a simple calculation and comparison.

1.  **Total Pages**: Rahul needs to write 5 pages.
2.  **Time per Page**: He takes `X` minutes to write one page.
3.  **Total Time Required**: To write all 5 pages, the total time Rahul will need is `5 * X` minutes.
4.  **Deadline**: The assignment must be completed within 60 minutes.

To determine if Rahul can complete the assignment on time, we simply compare the `Total Time Required` with the `Deadline`.

*   If `(5 * X) <= 60`, Rahul can finish on time.
*   If `(5 * X) > 60`, Rahul cannot finish on time.

Based on this comparison, we print "YES" or "NO".

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    The program performs a fixed number of operations: reading one integer, one multiplication, one comparison, and one print operation. These operations do not depend on the magnitude of the input `X` (within its constraints) or any other variable input size. Hence, the time complexity is constant.

*   **Space Complexity**: $O(1)$
    The program uses a few integer variables (`X`, `total_time_needed`) to store input and intermediate results. The memory used by these variables is constant and does not scale with the input value `X`. Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace to avoid typing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X; // Declare an integer variable X to store the time taken to write one page.
           // X is constrained between 1 and 1000, so 'int' is sufficient.
    
    // Read the value of X from standard input.
    cin >> X;

    // Calculate the total time Rahul needs to complete the 5-page assignment.
    // Total pages = 5. Time per page = X minutes.
    // Total time needed = 5 * X minutes.
    int total_time_needed = 5 * X;

    // The assignment is due in 60 minutes.
    // Check if the total time Rahul needs is less than or equal to the available time.
    if (total_time_needed <= 60) {
        // If Rahul can complete the assignment within 60 minutes, print "YES".
        cout << "YES\n";
    } else {
        // Otherwise, Rahul cannot complete the assignment in time, so print "NO".
        cout << "NO\n";
    }

    return 0; // Indicate successful program execution.
}
```