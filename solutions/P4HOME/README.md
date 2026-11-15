# [Chef and Close Friends (P4HOME)](https://www.codechef.com/problems/P4HOME)
- **Difficulty Rating**: 749
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef is located at an integer point `x`. His friends live at various integer points within the range `[x-y, x+y]`, but *not* at `x` itself. Chef can travel to any integer point within the range `[x-z, x+z]`. We need to determine the total number of friends Chef can visit.

In essence, we need to find the count of integer points `p` such that:
1. `x-y <= p <= x+y` (friends' location range)
2. `x-z <= p <= x+z` (Chef's travel range)
3. `p != x` (friends don't live at Chef's home)

## Intuition & Mathematical Observation

Let's analyze the conditions:

1.  **Friends' Location Range**: Friends are at integer points `p` such that `p \in [x-y, x+y]` and `p \neq x`.
2.  **Chef's Travel Range**: Chef can travel to integer points `p` such that `p \in [x-z, x+z]`.

For Chef to visit a friend, the friend's location `p` must satisfy *both* range conditions. This means `p` must be in the intersection of `[x-y, x+y]` and `[x-z, x+z]`.

Let's find this intersection:
The lower bound of the intersection will be `max(x-y, x-z)`.
The upper bound of the intersection will be `min(x+y, x+z)`.

We can simplify these bounds:
*   `max(x-y, x-z) = x - min(y, z)`
*   `min(x+y, x+z) = x + min(y, z)`

Let `k = min(y, z)`. Then the effective range of points Chef can visit is `[x-k, x+k]`.

Now, we need to count the number of integer points in this range `[x-k, x+k]`, *excluding* `x`.

The number of integer points in a continuous range `[A, B]` is `B - A + 1`.
For the range `[x-k, x+k]`, the number of integer points is:
`(x+k) - (x-k) + 1 = x + k - x + k + 1 = 2k + 1`.

Since friends do not live at `x`, and `x` is always included in the range `[x-k, x+k]` (because `k` is non-negative), we must subtract 1 from our count.

So, the total number of friends Chef can visit is `(2k + 1) - 1 = 2k`.

Substituting `k = min(y, z)` back into the formula, the final number of friends Chef can visit is `2 * min(y, z)`.

This simple formula directly gives the answer for each test case.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    For each of the `T` test cases, we perform a constant number of operations: reading three integers, calculating `min(y, z)`, multiplying by 2, and printing the result. This makes the time complexity directly proportional to the number of test cases.

*   **Space Complexity**: $O(1)$
    We only use a few integer variables (`T`, `x`, `y`, `z`, `k`, `num_friends`) to store input and intermediate results. The amount of memory used does not depend on the input values or the number of test cases (beyond the loop counter), hence it's constant space.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, algorithm, etc.

// Using namespace std; is requested by the problem statement.
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is crucial for problems with large number of test cases.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) {
        int x, y, z;
        cin >> x >> y >> z; // Read Chef's position (x), friend range (y), and travel limit (z)

        // The friends live at integer points in [x-y, x+y] excluding x.
        // Chef can travel to integer points in [x-z, x+z].

        // We need to find the number of friends that are in both ranges,
        // and are not at Chef's home (x).

        // The effective range of friends Chef can visit is the intersection of
        // [x-y, x+y] and [x-z, x+z].
        // This intersection simplifies to [x - min(y, z), x + min(y, z)].
        // Let k = min(y, z). The range is [x-k, x+k].

        // The number of integer points in the range [x-k, x+k] is (x+k) - (x-k) + 1 = 2k + 1.
        // Since friends do not live at Chef's home (x), and x is always included
        // in the range [x-k, x+k] (because k >= 0), we must subtract 1 from this count.
        // So, the number of friends Chef can visit is (2k + 1) - 1 = 2k.

        int k = min(y, z); // Calculate k = min(y, z)
        int num_friends = 2 * k; // Apply the formula 2k

        cout << num_friends << "\n"; // Print the result for the current test case
    }

    return 0; // Indicate successful execution
}
```