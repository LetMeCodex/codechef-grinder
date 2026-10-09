# [All Zero (ALLZR)](https://www.codechef.com/problems/ALLZR)
- **Difficulty Rating**: 626
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks whether it's possible to make three given positive integers `A`, `B`, and `C` all equal to zero by applying two types of operations any number of times. The operations are:

1.  **Type 1**: Decrement `A` by 1 and `B` by 2.
2.  **Type 2**: Decrement `B` by 1 and `C` by 3.

We need to output "Yes" if it's possible, and "No" otherwise.

## Intuition & Mathematical Observation

Let's denote the number of times we perform Type 1 operations as `x` and the number of times we perform Type 2 operations as `y`. Both `x` and `y` must be non-negative integers.

After `x` Type 1 operations and `y` Type 2 operations, the initial values `A`, `B`, `C` will transform into:
*   New `A` = `A - x`
*   New `B` = `B - 2x - y`
*   New `C` = `C - 3y`

For all three values to become zero, we must satisfy the following system of equations:
1.  `A - x = 0`
2.  `B - 2x - y = 0`
3.  `C - 3y = 0`

Let's solve this system step-by-step:

**Step 1: Determine `x` from equation (1)**
From `A - x = 0`, we directly get `x = A`.
Since `A` is given as a positive integer, `x` will always be positive, satisfying the non-negative requirement for `x`.

**Step 2: Determine `y` from equation (2) using `x`**
Substitute `x = A` into `B - 2x - y = 0`:
`B - 2A - y = 0`
`y = B - 2A`

For `y` to be a valid number of operations, it must be non-negative. Therefore, we must have `B - 2A >= 0`, which implies `B >= 2A`.
If `B < 2A`, then `y` would be negative, meaning it's impossible to reach zero for `B` and `C` with a non-negative number of Type 2 operations. In this case, the answer is "No".

**Step 3: Verify consistency with equation (3) using `y`**
Substitute `y = B - 2A` into `C - 3y = 0`:
`C - 3 * (B - 2A) = 0`
This implies that `C` must be exactly `3` times `(B - 2A)`.
So, `C = 3 * (B - 2A)`.

If this condition holds true, along with `B >= 2A`, then we have found valid non-negative integers `x` and `y` that make all `A`, `B`, and `C` zero. Thus, the answer is "Yes". Otherwise, if `C` is not equal to `3 * (B - 2A)`, it's impossible, and the answer is "No".

**Summary of conditions for "Yes":**
1.  `B >= 2 * A` (ensures `y` is non-negative)
2.  `C == 3 * (B - 2 * A)` (ensures `C` becomes zero with the calculated `y`)

If both conditions are met, output "Yes". Otherwise, output "No".

## Complexity Analysis

*   **Time Complexity**: $O(1)$ per test case. For each test case, the solution performs a fixed number of arithmetic operations (multiplications, subtractions) and comparisons. Since there are `t` test cases, the total time complexity is $O(t)$.
*   **Space Complexity**: $O(1)$. The solution uses a constant amount of extra space to store a few integer variables (`a`, `b`, `c`, `x`, `y`, `t`).

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c; // Read the initial values of A, B, C

        bool possible = false;

        // Let x be the number of type 1 operations and y be the number of type 2 operations.
        // We want to find non-negative integers x and y such that:
        // A - x = 0  => x = A
        // B - 2x - y = 0 => y = B - 2x
        // C - 3y = 0 => C = 3y

        // From the first equation, x must be equal to A.
        // Since x must be non-negative, this is always true given the constraints (A >= 1).
        int x = a;

        // Substitute x into the second equation:
        // y = B - 2*A
        // For y to be a valid number of operations, it must be non-negative.
        // So, B - 2*A >= 0, which means B >= 2*A.
        if (b < 2 * a) {
            // If B is less than 2*A, y would be negative, which is impossible.
            cout << "No\n";
            continue; // Move to the next test case
        }

        // Now calculate y, which is guaranteed to be non-negative at this point:
        int y = b - 2 * a;

        // Substitute y into the third equation:
        // C - 3*y = 0
        // This means C must be exactly 3 times y.
        // So, C = 3 * (B - 2*A).
        if (c == 3 * y) {
            possible = true; // All conditions met
        }

        if (possible) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}

```