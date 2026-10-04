# [Leg Space (LEGSP)](https://www.codechef.com/problems/LEGSP)
- **Difficulty Rating**: 326
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if Chef is happy with the leg space on a bus. We are given two integers: `N`, the number of students, and `M`, the number of seats in the bus. Chef is happy if the bus is *not full*. We need to output "YES" if Chef is happy, and "NO" otherwise. The problem constraints state that `N` will always be less than or equal to `M` (`N <= M`).

## Intuition & Mathematical Observation

The core of the problem lies in understanding the definition of a "not full" bus.
A bus is considered "not full" if there are fewer students than available seats.
Given:
- `N`: number of students
- `M`: number of seats

Chef is happy if the bus is not full. This translates directly to the condition:
`N < M`

If `N` is strictly less than `M`, it means there are empty seats, and thus the bus is not full. In this case, Chef is happy, and we should output "YES".

The problem constraints state `N <= M`. This means two scenarios are possible:
1. `N < M`: Fewer students than seats. Bus is not full. Chef is happy.
2. `N == M`: Exactly as many students as seats. Bus is full. Chef is not happy.

Therefore, the solution boils down to a simple comparison: if `N < M`, print "YES"; otherwise (if `N == M`), print "NO".

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The program performs a fixed number of operations regardless of the input values `N` and `M` (within typical integer limits). It reads two integers, performs one comparison, and prints a short string. All these operations take constant time.

-   **Space Complexity**: $O(1)$
    The program uses a constant amount of memory to store a few integer variables (`N`, `M`) and for input/output buffers. The memory usage does not scale with the input values.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries, common in competitive programming

using namespace std; // Allows using standard library elements without the std:: prefix

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare two integer variables to store the number of students (N)
    // and the number of seats (M).
    int N, M;

    // Read the values of N and M from standard input.
    cin >> N >> M;

    // Check the condition for Chef's happiness.
    // Chef is happy if the bus is not full, which means there are fewer students
    // than seats (N < M).
    if (N < M) {
        // If N is less than M, print "YES" followed by a newline character.
        cout << "YES\n";
    } else {
        // If N is not less than M, given the constraint N <= M, it must be that N == M.
        // In this case, the bus is full, and Chef is not happy.
        // Print "NO" followed by a newline character.
        cout << "NO\n";
    }

    // Return 0 to indicate successful program execution.
    return 0;
}
```