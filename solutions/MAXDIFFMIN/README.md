# [Max minus Min (MAXDIFFMIN)](https://www.codechef.com/problems/MAXDIFFMIN)
- **Difficulty Rating**: 339
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to process `T` test cases. In each test case, we are given three integers, `A`, `B`, and `C`, with the guarantee that `A < B < C`. Our task is to calculate and print the value of `max(A, B, C) - min(A, B, C)`.

## Intuition & Mathematical Observation

The core of this problem lies in understanding the given constraint: `A < B < C`. This inequality directly tells us the relative order of the three numbers.

1.  **Finding the Minimum**: Since `A` is strictly less than `B`, and `B` is strictly less than `C`, `A` must be the smallest among the three. Therefore, `min(A, B, C) = A`.
2.  **Finding the Maximum**: Similarly, since `C` is strictly greater than `B`, and `B` is strictly greater than `A`, `C` must be the largest among the three. Therefore, `max(A, B, C) = C`.

Given these observations, the expression `max(A, B, C) - min(A, B, C)` simplifies directly to `C - A`.

Thus, for each test case, we simply need to read the three integers `A`, `B`, and `C`, and then print the result of `C - A`.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    For each of the `T` test cases, we perform a constant number of operations: reading three integers and one subtraction. Since these operations take constant time, the total time complexity is directly proportional to the number of test cases, `T`.

*   **Space Complexity**: $O(1)$
    We only use a few integer variables (`T`, `A`, `B`, `C`) to store input and intermediate results. The amount of memory used does not depend on the magnitude of the input numbers or the number of test cases (as variables are reused for each test case). Hence, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common headers like iostream, algorithm, etc.

// Using the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases.
    cin >> T; // Read the number of test cases.

    // Loop T times, once for each test case.
    while (T--) {
        int A, B, C; // Declare three integer variables A, B, C.
        cin >> A >> B >> C; // Read the three integers for the current test case.

        // The problem states that A < B < C.
        // This means:
        // - The minimum value among A, B, C is A.
        // - The maximum value among A, B, C is C.
        // Therefore, max(A, B, C) - min(A, B, C) simplifies to C - A.

        // Calculate the difference and print it, followed by a newline character.
        cout << C - A << "\n";
    }

    return 0; // Indicate successful execution of the program.
}
```