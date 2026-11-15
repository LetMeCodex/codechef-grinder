# [Fit in Data Type (DATATYPE)](https://www.codechef.com/problems/DATATYPE)
- **Difficulty Rating**: 1133
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a custom data type that can store non-negative integer values. This data type has a maximum capacity `N`, meaning it can store any integer `V` such that `0 <= V <= N`.

When a value `X` is assigned to this data type:
1.  If `X` is within the valid range (`0 <= X <= N`), it is stored as `X`.
2.  If `X` is greater than `N`, it undergoes a "cyclic conversion". This means the value wraps around. For example, if `N=11`, the range is `0-11`. If `X=12`, it becomes `0`. If `X=13`, it becomes `1`, and so on.

The task is to determine the actual value stored in memory for a given `N` and `X`.

## Intuition & Mathematical Observation

The core of this problem lies in understanding the "cyclic conversion" described. When a value `X` exceeds the maximum capacity `N`, it wraps around to the beginning of the range. This behavior is characteristic of the modulo operator.

Let's analyze the range and the cycle:
*   The data type can store values from `0` to `N`, inclusive.
*   The total number of distinct values this data type can hold is `N - 0 + 1 = N + 1`.
*   When `X` is assigned, if `X > N`, it effectively "resets" after `N` and starts counting from `0` again.
    *   `N+1` maps to `0`
    *   `N+2` maps to `1`
    *   `N+3` maps to `2`
    *   ...and so on.

This is precisely what the modulo operator `%` does. If we want to map any non-negative integer `X` into the range `[0, M-1]`, we use `X % M`.
In our case, the range is `[0, N]`, and the size of this range (the modulus `M`) is `N+1`.

Therefore, the value stored in memory will be `X % (N + 1)`.

Let's verify with the problem's examples:
*   **N=11, X=12**: The range is `0-11`. The cycle length is `11+1 = 12`.
    `12 % 12 = 0`. Correct.
*   **N=11, X=13**:
    `13 % 12 = 1`. Correct.
*   **N=11, X=23**:
    `23 % 12 = 11`. Correct.
*   **N=11, X=5**: (X is already within range)
    `5 % 12 = 5`. Correct.

This mathematical observation holds true for all cases, simplifying the problem to a single modulo operation.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    The program iterates `T` times, once for each test case. Inside the loop, it performs a constant number of operations: reading two integers (`N`, `X`), one arithmetic operation (`X % (N + 1)`), and printing one integer. Since each test case is processed in constant time, the total time complexity is directly proportional to the number of test cases, `T`.

*   **Space Complexity**: $O(1)$
    The program uses a fixed number of variables (`T`, `N`, `X`, `stored_value`) regardless of the input values or the number of test cases. No dynamic data structures or arrays are used that would scale with input size. Thus, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries as requested

// Use the standard namespace as requested
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of testcases
    cin >> T; // Read the number of testcases

    // Loop through each testcase
    while (T--) {
        int N, X; // N: maximum value the data type can store, X: value Chef wants to store
        cin >> N >> X; // Read N and X for the current testcase

        // The data type can store values from 0 to N, inclusive.
        // This means there are N+1 distinct values in its range (0, 1, ..., N).
        // When a value X is greater than N, it is cyclically converted.
        // This cyclic conversion is precisely what the modulo operator (%) does.
        // The cycle length (or modulus) is N+1.
        //
        // For example:
        // If N=11, the range is 0-11. The cycle length is 11+1 = 12.
        // - If X=12, it becomes 12 % 12 = 0.
        // - If X=13, it becomes 13 % 12 = 1.
        //
        // If X is already within the range (0 to N), the modulo operation
        // will return X itself, which is correct.
        // For example:
        // If N=15, the range is 0-15. The cycle length is 15+1 = 16.
        // - If X=10, it becomes 10 % 16 = 10.
        // - If X=0, it becomes 0 % 16 = 0.
        //
        // Given the constraints (N, X <= 50), 'int' is sufficient to store
        // N, X, and the result of the modulo operation. No overflow issues.
        int stored_value = X % (N + 1);

        // Output the actual value stored in memory, followed by a newline
        cout << stored_value << "\n";
    }

    return 0; // Indicate successful program execution
}
```