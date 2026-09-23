# [Cyclic Quadrilateral (CYCLICQD)](https://www.codechef.com/problems/CYCLICQD)
- **Difficulty Rating**: 735
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a given quadrilateral is cyclic. We are provided with four integer angles, `A`, `B`, `C`, and `D`, which represent the angles of the quadrilateral in order along its perimeter. The problem statement guarantees that the sum of these angles (`A + B + C + D`) is always 360 degrees. For each test case, we need to output "YES" if the quadrilateral is cyclic, and "NO" otherwise.

## Intuition & Mathematical Observation

A quadrilateral is defined as cyclic if all its vertices lie on a single circle. A fundamental property of cyclic quadrilaterals is that **the sum of opposite angles is 180 degrees**.

Given the angles `A`, `B`, `C`, `D` in order:
- `A` and `C` are opposite angles.
- `B` and `D` are opposite angles.

For the quadrilateral to be cyclic, both of the following conditions must hold true:
1. `A + C = 180` degrees
2. `B + D = 180` degrees

However, we are also guaranteed that the sum of all angles is `A + B + C + D = 360` degrees. Let's see if checking just one condition is sufficient:

If we assume `A + C = 180` degrees, we can substitute this into the total sum equation:
`(A + C) + B + D = 360`
`180 + B + D = 360`
`B + D = 360 - 180`
`B + D = 180` degrees

This shows that if one pair of opposite angles sums to 180 degrees, the other pair *must also* sum to 180 degrees, given that the total sum of angles is 360 degrees. Therefore, we only need to check one pair of opposite angles. For instance, if `A + C` equals 180, the quadrilateral is cyclic. Otherwise, it is not.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    For each test case, we perform a constant number of operations: reading four integers, one addition, and one comparison. This takes $O(1)$ time per test case. Since there are $T$ test cases, the total time complexity is $T \times O(1) = O(T)$.

-   **Space Complexity**: $O(1)$
    We only use a few integer variables (`T`, `A`, `B`, `C`, `D`) to store input and intermediate results. The amount of memory used does not depend on the input values or the number of test cases, making the space complexity constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream and many other standard libraries

// Use the standard namespace as requested
using namespace std;

int main() {
    // Enable fast I/O operations as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare variable for the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int A, B, C, D; // Declare variables for the four angles
        cin >> A >> B >> C >> D; // Read the four angles for the current test case

        // A quadrilateral is cyclic if the sum of opposite angles is 180 degrees.
        // Given A, B, C, D in order along its perimeter, A and C are opposite angles.
        // The problem also guarantees A + B + C + D = 360.
        // If A + C = 180, then B + D must also be 180 (since 360 - 180 = 180).
        // Therefore, checking only one pair of opposite angles (e.g., A + C) is sufficient.
        if (A + C == 180) {
            cout << "YES\n"; // If the condition is met, print "YES"
        } else {
            cout << "NO\n"; // Otherwise, print "NO"
        }
    }

    return 0; // Indicate successful program execution
}
```