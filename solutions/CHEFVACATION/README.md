# [Chef on Vacation (CHEFVACATION)](https://www.codechef.com/problems/CHEFVACATION)
- **Difficulty Rating**: 891
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef has a total of `Z` days for his vacation. During this vacation, he plans to go on two separate trips: one with his family, which lasts `X` days, and another with his friends, which lasts `Y` days. The problem states that these two trips cannot overlap. We need to determine if Chef has enough vacation days to go on *both* trips. If he does, output "YES"; otherwise, output "NO".

## Intuition & Mathematical Observation

The core of this problem lies in understanding the constraint that the two trips cannot overlap. If two events cannot overlap, the total time required to complete both events sequentially is simply the sum of their individual durations.

1.  **Total days required**: To go on both the family trip (duration `X`) and the friends trip (duration `Y`), Chef will need a total of `X + Y` days. This is the minimum number of days required because the trips must be taken one after another.
2.  **Available days**: Chef has `Z` days available for his vacation.
3.  **Condition for feasibility**: Chef can go on both trips if and only if the total days required (`X + Y`) are less than or equal to the total available vacation days (`Z`).

This leads to a straightforward mathematical condition: `X + Y <= Z`.

If this condition is true, Chef has enough days, and the answer is "YES".
If this condition is false, Chef does not have enough days, and the answer is "NO".

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    *   The program iterates `T` times, once for each test case.
    *   Inside the loop, for each test case, it performs a constant number of operations: reading three integers (`X`, `Y`, `Z`), one addition (`X + Y`), one comparison (`<=`), and one print operation. All these operations take constant time, $O(1)$.
    *   Therefore, the total time complexity is proportional to the number of test cases, $O(T)$.

*   **Space Complexity**: $O(1)$
    *   The program uses a few integer variables (`T`, `X`, `Y`, `Z`) to store input and intermediate values.
    *   The memory used by these variables is constant and does not depend on the input size (other than the fixed size of an integer).
    *   Hence, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace to avoid prefixing standard library elements with std::
using namespace std;

// Main function where the program execution begins
int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can speed up I/O operations.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // further speeding up I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare an integer variable 'T' to store the number of test cases.
    int T;
    // Read the number of test cases from standard input.
    cin >> T;

    // Loop 'T' times, processing one test case in each iteration.
    while (T--) {
        // Declare three integer variables X, Y, and Z.
        // X: duration of the family trip.
        // Y: duration of the friends trip.
        // Z: total duration of the vacation.
        int X, Y, Z;
        // Read the values of X, Y, and Z for the current test case.
        cin >> X >> Y >> Z;

        // The Chef can go on both trips if and only if the total days required for both trips
        // (X + Y) is less than or equal to the total available vacation days (Z).
        // This is because the trips cannot overlap, so the minimum total time needed is the sum of their durations.
        if (X + Y <= Z) {
            // If the condition is met, Chef can go on both trips. Print "YES".
            cout << "YES\n";
        } else {
            // Otherwise, Chef cannot go on both trips as there aren't enough days. Print "NO".
            cout << "NO\n";
        }
    }

    // Return 0 to indicate successful program execution.
    return 0;
}
```