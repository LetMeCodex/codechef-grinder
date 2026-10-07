# [Make Arithmetic Progression (AP)](https://www.codechef.com/problems/AP)
- **Difficulty Rating**: 682
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the minimum number of operations required to make three given integers, `X`, `Y`, and `Z`, form an Arithmetic Progression (AP). An operation consists of changing any one of the three integers to any other integer. We need to output either `0` or `1`.

## Intuition & Mathematical Observation

1.  **Definition of an Arithmetic Progression:**
    Three numbers `A, B, C` form an Arithmetic Progression if the difference between consecutive terms is constant. Mathematically, this means `B - A = C - B`.

2.  **Simplifying the AP Condition:**
    We can rearrange the condition `B - A = C - B` algebraically:
    `B - A = C - B`
    `B + B = A + C`
    `2 * B = A + C`
    So, for `X, Y, Z` to be an AP, the condition `2 * Y = X + Z` must hold true.

3.  **Minimum Operations Analysis:**
    *   **Case 0 Operations:** If the given `X, Y, Z` already satisfy `2 * Y = X + Z`, then they already form an AP. In this scenario, no operations are needed, and the answer is `0`.

    *   **Case 1 Operation:** If `2 * Y != X + Z`, then 0 operations are not sufficient. We need to check if 1 operation is always enough.
        Let's consider changing one of the numbers:
        *   **Change X:** We can change `X` to a new value `X'` such that `X', Y, Z` form an AP. For this to happen, `2 * Y = X' + Z`. We can solve for `X'`: `X' = 2 * Y - Z`. Since `Y` and `Z` are integers, `2 * Y - Z` will always be an integer. Thus, we can always change `X` to `2 * Y - Z` in one operation to make it an AP.
        *   **Change Z:** Similarly, we can change `Z` to `Z'` such that `X, Y, Z'` form an AP. For this, `2 * Y = X + Z'`. Solving for `Z'`: `Z' = 2 * Y - X`. This will also always be an integer.
        *   (Note: While we could also consider changing `Y` to `Y'`, this would require `X + Z` to be an even number for `Y' = (X + Z) / 2` to be an integer. However, since changing `X` or `Z` *always* works in one operation, we don't need to worry about the `Y` case or its parity constraint.)

    Since we can always make the sequence an AP by changing either `X` or `Z` to an appropriate integer in just one operation, if 0 operations are not enough, then 1 operation is always sufficient.

4.  **Conclusion:** The minimum number of operations is `0` if `2 * Y == X + Z`, and `1` otherwise.

## Complexity Analysis

*   **Time Complexity**: $O(1)$ per test case.
    For each test case, we read three integers and perform a constant number of arithmetic operations (multiplication, addition, subtraction) and a comparison. This takes constant time. If there are `T` test cases, the total time complexity will be $O(T)$.

*   **Space Complexity**: $O(1)$.
    We only use a few integer variables (`X`, `Y`, `Z`, `T`) to store input and intermediate results. This requires a constant amount of memory, regardless of the input values.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common headers like iostream

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

// Function to solve a single test case
void solve() {
    int X, Y, Z;
    // Read the three integers for the current test case
    cin >> X >> Y >> Z;

    // An arithmetic progression (X, Y, Z) satisfies the condition Y - X = Z - Y.
    // This can be algebraically rearranged to 2 * Y = X + Z.
    // We check if this condition is already met.
    if (2 * Y == X + Z) {
        // If the condition is met, the sequence is already an AP.
        // No operations are required.
        cout << 0 << "\n";
    } else {
        // If the condition is not met, 0 operations are not enough.
        // We need to determine if 1 operation is sufficient.
        // As discussed in the thought process, we can always make it an AP
        // in one operation by changing either X or Z to a suitable integer.
        // For example, to change X: set X' = 2*Y - Z. This will always be an integer.
        // So, 1 operation is always sufficient if 0 operations are not.
        cout << 1 << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    // Read the number of test cases
    cin >> T;
    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful program execution
}
```