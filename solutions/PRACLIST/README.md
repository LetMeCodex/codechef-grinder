# [How many unattempted problems (PRACLIST)](https://www.codechef.com/problems/PRACLIST)
- **Difficulty Rating**: 264
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the number of unattempted problems in the "Beginner" section of CodeChef. We are given two integers:
1.  `X`: The total number of problems available in the "All Problems" list for the Beginner section.
2.  `Y`: The number of problems that have already been "Attempted" by a user in the Beginner section.

Our task is to find and output the count of problems that are yet to be attempted.

## Intuition & Mathematical Observation

This problem is a straightforward application of basic arithmetic. If we have a total number of items (`X`) and a subset of those items have been processed or used (`Y`), then the number of items remaining or unprocessed is simply the total minus the processed amount.

In this specific context:
*   Total problems available = `X`
*   Problems already attempted = `Y`
*   Problems unattempted = Total problems - Problems attempted

Therefore, the number of unattempted problems can be calculated directly as `X - Y`. There are no complex algorithms, data structures, or advanced mathematical concepts required.

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    The solution involves reading two integers from input, performing a single subtraction operation, and printing one integer to output. All these operations take a constant amount of time, regardless of the magnitude of `X` or `Y` (within integer limits). Hence, the time complexity is constant.

*   **Space Complexity**: $O(1)$
    The solution uses a fixed number of integer variables (`X`, `Y`, `unattempted_problems`) to store the input and the result. The memory usage does not grow with the input values. Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin/cout from the C standard I/O library and
    // disables synchronization with C's stdio.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // Declare two integer variables to store the input values.
    // X: total count of 'All Problems' in the Beginner section.
    // Y: count of 'Attempted' problems among them.
    int X, Y;

    // Read the two space-separated integers from standard input.
    std::cin >> X >> Y;

    // Calculate the number of 'Un-attempted' problems.
    // This is simply the total problems minus the attempted problems.
    int unattempted_problems = X - Y;

    // Print the result to standard output, followed by a newline character.
    std::cout << unattempted_problems << "\n";

    // Indicate successful execution of the program.
    return 0;
}
```