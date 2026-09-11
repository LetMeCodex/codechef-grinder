# [Decrement OR Increment (DECINC)](https://www.codechef.com/problems/DECINC)
- **Difficulty Rating**: 722
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to read a single integer, `N`. Based on whether `N` is divisible by 4, we need to perform one of two operations and print the result:
1. If `N` is perfectly divisible by 4, we should print `N + 1`.
2. Otherwise (if `N` is not divisible by 4), we should print `N - 1`.

The constraints on `N` are `0 <= N <= 1000`.

## Intuition & Mathematical Observation

The problem statement directly provides the logic required. There are no hidden tricks or complex algorithms involved. The core of the problem lies in checking for divisibility by 4.

1.  **Divisibility Check**: To determine if a number `N` is divisible by another number `D`, we use the modulo operator (`%`). If `N % D` evaluates to `0`, it means `N` is perfectly divisible by `D`. In this problem, `D` is 4. So, we check `N % 4 == 0`.
2.  **Conditional Logic**: Based on the result of the divisibility check, we apply a simple conditional statement (an `if-else` block).
    *   If `N % 4 == 0` is true, we perform `N + 1`.
    *   If `N % 4 == 0` is false, we perform `N - 1`.
3.  **Output**: The final calculated value is then printed to standard output, followed by a newline character.

This problem is a basic test of understanding conditional statements and the modulo operator in programming.

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    The program performs a fixed number of operations regardless of the input value `N` (within the given constraints). These operations include reading an integer, one modulo operation, one arithmetic operation (addition or subtraction), and printing an integer. All these operations take constant time. Therefore, the overall time complexity is constant.

*   **Space Complexity**: $O(1)$
    The program uses a single integer variable `N` to store the input. This requires a constant amount of memory. No additional data structures are used that would scale with the input size. Hence, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare an integer variable N to store the input number.
    // The constraints (0 <= N <= 1000) ensure that 'int' is sufficient
    // to store N and its modified value (N-1 or N+1) without overflow.
    int N;

    // Read the integer N from standard input.
    cin >> N;

    // Check if N is divisible by 4.
    // The modulo operator (%) returns the remainder of a division.
    // If N % 4 is 0, it means N is perfectly divisible by 4.
    if (N % 4 == 0) {
        // If N is divisible by 4, increment its value by 1.
        // Then print the new value followed by a newline character.
        cout << N + 1 << "\n";
    } else {
        // If N is not divisible by 4, decrement its value by 1.
        // Then print the new value followed by a newline character.
        cout << N - 1 << "\n";
    }

    // Return 0 to indicate successful program execution.
    return 0;
}
```