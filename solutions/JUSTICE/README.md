# [International Justice Day (JUSTICE)](https://www.codechef.com/problems/JUSTICE)
- **Difficulty Rating**: 264
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem "International Justice Day (JUSTICE)" presents a scenario where the outcome of a trial depends on the "convincing power" of the prosecution and the defense. We are given two integer values: `X`, representing the convincing power of the prosecution, and `Y`, representing the convincing power of the defense.

The rules for conviction are straightforward:
*   If the prosecution's convincing power (`X`) is greater than or equal to the defense's convincing power (`Y`), the accused is convicted.
*   Otherwise (if `X` is strictly less than `Y`), the accused is acquitted.

Our task is to print "YES" if the accused is convicted, and "NO" if they are acquitted.

## Intuition & Mathematical Observation

This problem is a direct application of a simple conditional statement. The core logic is explicitly stated in the problem description: "The accused will be convicted if the convincing power of the prosecution is greater than or equal to the convincing power of the defense."

There are no complex algorithms, data structures, or advanced mathematical concepts required. We simply need to:
1.  Read the two integer inputs, `X` and `Y`.
2.  Compare `X` and `Y` using the "greater than or equal to" operator (`>=`).
3.  If `X >= Y` evaluates to true, print "YES".
4.  Otherwise (if `X < Y`), print "NO".

This is a fundamental comparison operation, making the problem very basic.

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    The solution involves a fixed number of operations regardless of the input values (within integer limits):
    1.  Reading two integers.
    2.  Performing a single comparison.
    3.  Printing a short string.
    All these operations take constant time. Therefore, the overall time complexity is $O(1)$.

*   **Space Complexity**: $O(1)$
    The solution uses a constant amount of memory to store the two input integers (`X` and `Y`) and a few auxiliary variables for I/O optimization. The memory usage does not grow with the magnitude of the input values. Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace to avoid prefixing std::
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from the C standard streams and disables synchronization,
    // making I/O operations faster.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare two integer variables to store the convincing powers.
    // X for prosecution, Y for defense.
    int X, Y;

    // Read the two integers from standard input.
    cin >> X >> Y;

    // According to the problem statement, the accused will be convicted if
    // the convincing power of the prosecution (X) is greater than or equal to
    // the convincing power of the defense (Y).
    if (X >= Y) {
        // If the condition is met, print "YES".
        // Use "\n" for a newline character, which is generally faster than endl.
        cout << "YES\n";
    } else {
        // Otherwise (if X < Y), print "NO".
        cout << "NO\n";
    }

    // The main function should return 0 to indicate successful execution.
    return 0;
}
```