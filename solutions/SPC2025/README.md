# [New-Pro Coder (SPC2025)](https://www.codechef.com/problems/SPC2025)
- **Difficulty Rating**: 467
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a person named Ved is a "NEWBIE" or a "PRO" based on two given integers: `N`, representing the total number of lines of code Ved wrote, and `M`, representing the number of lines that contain errors. The specific condition for being a "NEWBIE" or "PRO" is not explicitly stated in the problem description but is implied by the solution logic: if the number of error lines (`M`) is at least half of the total lines (`N`), Ved is considered a "NEWBIE"; otherwise, Ved is a "PRO".

## Intuition & Mathematical Observation

The core of this problem lies in a straightforward comparison. We are given `N` (total lines) and `M` (error lines). The condition to check is whether `M` is "at least half of `N`".

Mathematically, "at least half of `N`" can be expressed as `M >= N / 2`.

To avoid potential issues with floating-point numbers or integer division truncation (e.g., if `N` is odd, `N/2` might truncate), it's safer and more common in competitive programming to multiply by 2 on the other side:

`2 * M >= N`

This inequality directly translates to the condition used in the solution. If this condition holds true, it means Ved has a significant proportion of errors (at least 50% of the lines), classifying them as a "NEWBIE". If the condition is false, it implies Ved has fewer than half the lines with errors, making them a "PRO".

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The solution involves reading two integers, performing a single arithmetic comparison (`2 * M >= N`), and then printing a fixed string. All these operations take a constant amount of time, regardless of the magnitude of `N` and `M` (within standard integer limits). Therefore, the time complexity is constant.

-   **Space Complexity**: $O(1)$
    The solution uses a fixed amount of memory to store two integer variables (`N` and `M`). No dynamic data structures or arrays are used, and the memory usage does not scale with the input values. Hence, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin/cout from the C standard I/O and prevents flushing cout before cin.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // Declare two integer variables N and M.
    int N, M;

    // Read the two space-separated integers from standard input.
    std::cin >> N >> M;

    // Apply the condition: if 2 * M is greater than or equal to N,
    // it means errors are present in at least half of the total lines.
    if (2 * M >= N) {
        // If the condition is true, Ved is a NEWBIE.
        std::cout << "NEWBIE\n";
    } else {
        // Otherwise, Ved is a PRO.
        std::cout << "PRO\n";
    }

    // Return 0 to indicate successful execution.
    return 0;
}
```