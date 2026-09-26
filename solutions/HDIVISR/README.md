# [Highest Divisor (HDIVISR)](https://www.codechef.com/problems/HDIVISR)
- **Difficulty Rating**: 860
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the largest integer `X` such that `1 <= X <= 10` and `X` is a divisor of a given integer `N`. The input `N` will be between 1 and 1000, inclusive.

**Example:**
- If `N = 10`, the divisors in the range [1, 10] are 1, 2, 5, 10. The largest among these is 10.
- If `N = 7`, the only divisor in the range [1, 10] is 1, 7. The largest among these is 7.
- If `N = 12`, the divisors in the range [1, 10] are 1, 2, 3, 4, 6. The largest among these is 6.

## Intuition & Mathematical Observation

The core of the problem is to find a divisor within a very small, fixed range `[1, 10]`. We need the *largest* such divisor.

A straightforward approach would be to iterate through the numbers in the specified range and check if they divide `N`. To find the *largest* one efficiently, we can iterate downwards from 10 to 1. The first number `i` we encounter that divides `N` will automatically be the largest such divisor because we are checking in decreasing order. Once we find such an `i`, we can print it and terminate the program, as there won't be any larger divisors in the range.

For any `N >= 1`, the number `1` is always a divisor. Since `1` is included in our range `[1, 10]`, we are guaranteed to find at least one divisor, so the loop will always find an answer.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The loop iterates from `i = 10` down to `1`. In the worst case (e.g., if `N` is a prime number like 7, or if the largest divisor is 1), the loop will run at most 10 times. Each iteration involves a constant number of operations (modulo, comparison, print). Since the number of iterations is fixed and does not depend on the input `N` (it's always at most 10), the time complexity is constant, $O(1)$.

-   **Space Complexity**: $O(1)$
    We only use a few integer variables (`N`, `i`) to store the input and loop counter. No additional data structures are used that scale with the input size. Therefore, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace to avoid writing std::repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare an integer variable N to store the input.
    // N will fit within an 'int' as its maximum value is 1000.
    int N;

    // Read the integer N from standard input.
    cin >> N;

    // Iterate from 10 down to 1.
    // We start from 10 because we are looking for the *largest* divisor
    // in the range [1, 10]. The first one we find will be the answer.
    for (int i = 10; i >= 1; --i) {
        // Check if 'i' divides 'N' evenly.
        // The modulo operator (%) returns the remainder of the division.
        // If the remainder is 0, then 'i' is a divisor of 'N'.
        if (N % i == 0) {
            // If 'i' divides 'N', it is the largest such divisor found so far
            // (and since we iterate downwards, it's the overall largest).
            // Print 'i' followed by a newline character.
            cout << i << "\n";

            // Terminate the program after finding and printing the answer.
            // This is efficient as we don't need to check smaller numbers.
            return 0;
        }
    }

    // This part of the code should theoretically never be reached because
    // the loop is guaranteed to find at least '1' as a divisor for any N >= 1.
    // However, a 'return 0;' at the end of main is standard practice for successful execution.
    return 0;
}
```