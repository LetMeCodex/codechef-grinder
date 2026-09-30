# [Rush to Exam (RUSHTOEXAM)](https://www.codechef.com/problems/RUSHTOEXAM)
- **Difficulty Rating**: 253
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef has an exam coming up and needs to read a book. He has `N` hours available to study. The book has `M` pages, and Chef can read `A` pages per hour. The task is to determine if Chef can finish reading the entire book within the `N` hours he has, and print "Yes" or "No" accordingly.

**Input:**
A single line containing three integers: `N`, `M`, `A`.
*   `N`: Total hours Chef has (1 <= N <= 24)
*   `M`: Total pages in the book (1 <= M <= 1000)
*   `A`: Pages Chef can read per hour (1 <= A <= 10)

**Output:**
Print "Yes" if Chef can read `M` pages in `N` hours, otherwise print "No".

## Intuition & Mathematical Observation

The problem is a straightforward calculation. To determine if Chef can finish the book, we need to find out the total number of pages he *can* read in the given `N` hours.

If Chef reads `A` pages per hour and has `N` hours, the total number of pages he can read is simply the product of hours and pages per hour:
`Total pages Chef can read = N * A`

Once we have this value, we compare it with the total pages required for the book, `M`.
*   If `Total pages Chef can read >= M`, it means Chef can read enough pages (or more than enough) to finish the book. In this case, the answer is "Yes".
*   If `Total pages Chef can read < M`, it means Chef cannot read all the required pages within the given time. In this case, the answer is "No".

This approach directly translates the problem statement into a simple arithmetic operation and a comparison.

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    The solution involves a fixed number of operations: reading three integers, one multiplication, and one comparison. These operations take constant time regardless of the input values (within the given constraints for integers). Therefore, the time complexity is constant.

*   **Space Complexity**: $O(1)$
    The solution uses a fixed number of variables (`N`, `M`, `A`, `pages_chef_can_read`) to store input and intermediate results. The amount of memory used does not depend on the magnitude of the input values. Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Using the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from the C standard I/O library and
    // prevents flushing cout before cin reads, speeding up I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem statement describes a single test case:
    // "The first and only line contains 3 integers - N, M and A."
    // We will follow this specific input format, which implies a single test case.
    // Therefore, we read N, M, A directly without a loop for multiple test cases.

    int N, M, A; // Declare variables for hours (N), pages to read (M), pages per hour (A)

    // Read the three integers from standard input
    cin >> N >> M >> A;

    // Calculate the total number of pages Chef can read in N hours.
    // Given the constraints (N <= 24, A <= 10), the maximum value for N * A is 24 * 10 = 240.
    // This value fits comfortably within an 'int' data type, so no overflow risk.
    int pages_chef_can_read = N * A;

    // Compare the pages Chef can read with the required pages M.
    // If Chef can read a number of pages greater than or equal to M, he can finish.
    if (pages_chef_can_read >= M) {
        // If Chef can read enough pages, print "Yes" followed by a newline.
        cout << "Yes\n";
    } else {
        // Otherwise, Chef cannot read enough pages, print "No" followed by a newline.
        cout << "No\n";
    }

    return 0; // Indicate successful execution
}
```