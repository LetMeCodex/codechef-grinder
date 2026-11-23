# [Chef and Difficult Contests (CHFTIRED)](https://www.codechef.com/problems/CHFTIRED)
- **Difficulty Rating**: 1130
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks whether it's possible to make two given positive integers, `a` and `b`, equal using a specific operation. The operation involves choosing a positive integer `d` and then performing one of two actions:
1.  Add `d` to `a` and `d-1` to `b`.
2.  Add `d-1` to `a` and `d` to `b`.

We need to output "YES" if it's possible to make `a` and `b` equal, and "NO" otherwise, for multiple test cases.

## Intuition & Mathematical Observation

The core of this problem lies in understanding how the difference between `a` and `b` changes with each operation. Let's analyze the change in `b - a`:

Let the initial values be `a_0` and `b_0`.

**Case 1: Add `d` to `a` and `d-1` to `b`**
*   New `a` becomes `a_1 = a_0 + d`
*   New `b` becomes `b_1 = b_0 + (d-1)`
*   The new difference `b_1 - a_1 = (b_0 + d - 1) - (a_0 + d) = b_0 - a_0 - 1`.
    In this case, the difference `b - a` **decreases by 1**.

**Case 2: Add `d-1` to `a` and `d` to `b`**
*   New `a` becomes `a_1 = a_0 + (d-1)`
*   New `b` becomes `b_1 = b_0 + d`
*   The new difference `b_1 - a_1 = (b_0 + d) - (a_0 + d - 1) = b_0 - a_0 + 1`.
    In this case, the difference `b - a` **increases by 1**.

Notice that in both cases, the value of `d` (as long as `d >= 1`) doesn't affect the *change* in the difference `b - a`. It only affects the absolute values of `a` and `b`.
Crucially, we can always choose `d=1`.
*   If we choose `d=1` in Case 1: Add 1 to `a`, add 0 to `b`. `b-a` decreases by 1.
*   If we choose `d=1` in Case 2: Add 0 to `a`, add 1 to `b`. `b-a` increases by 1.

This means that in each step, we can either increase the difference `b - a` by 1 or decrease it by 1. Since we can change the difference by exactly +1 or -1, we can always reach a state where `b - a = 0` (i.e., `a = b`) by repeatedly applying the operation that reduces the absolute difference `|b - a|`.

For example:
*   If `b > a`, we can repeatedly apply Case 1 (e.g., with `d=1`) to decrease `b-a` until it becomes 0.
*   If `a > b`, we can repeatedly apply Case 2 (e.g., with `d=1`) to increase `b-a` until it becomes 0.

The problem states that `a` and `b` are initially positive (`1 <= a, b`). Since `d >= 1`, `d` and `d-1` are always non-negative (0 or positive). Thus, `a` and `b` will always remain positive throughout the operations.

Therefore, it is always possible to make `a` and `b` equal. The answer for every test case is "YES".

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    The program iterates `T` times for the number of test cases. In each test case, it performs a constant number of operations: reading two `long long` integers and printing a fixed string "YES\n". Thus, the total time complexity is directly proportional to the number of test cases.

*   **Space Complexity**: $O(1)$
    The program uses a few variables (`T`, `a`, `b`) to store input and loop counters. These variables consume a constant amount of memory regardless of the input values or the number of test cases. No dynamic data structures are used.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

using namespace std; // Use the standard namespace as requested

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        long long a, b; // Declare a and b as long long as per problem instructions
        cin >> a >> b; // Read the two integers for the current test case
        
        // As analyzed:
        // The difference (b - a) can be changed by +1 or -1 in each step.
        // This is achieved by choosing d=1 for the magical operation.
        //
        // If d=1:
        // 1. Add 1 to a, add 0 to b. (b-a) decreases by 1.
        // 2. Add 0 to a, add 1 to b. (b-a) increases by 1.
        //
        // Since a and b are initially positive (1 <= a, b) and the operations
        // always add non-negative values (d or d-1), a and b will always remain positive.
        //
        // Therefore, we can always reach a state where a = b by repeatedly
        // applying the operation that reduces the absolute difference |b-a|.
        cout << "YES\n"; // Print "YES" for every test case
    }

    return 0; // Indicate successful execution
}
```