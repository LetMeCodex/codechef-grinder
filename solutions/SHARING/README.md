# [Sharing Cookies (SHARING)](https://www.codechef.com/problems/SHARING)
- **Difficulty Rating**: 232
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the minimum number of cookies Alice needs to give to Bob so that both of them end up with an equal number of cookies. We are given Alice's initial number of cookies, `A`, and Bob's initial number of cookies, `B`. It's guaranteed that `A > B`. If it's impossible to achieve an equal distribution using only whole cookies, we should output -1.

## Intuition & Mathematical Observation

Let's denote the number of cookies Alice initially has as `A` and Bob's as `B`.
Our goal is for them to have an equal number of cookies. Let `X` be the number of cookies Alice gives to Bob.

After Alice gives `X` cookies to Bob:
*   Alice will have `A - X` cookies.
*   Bob will have `B + X` cookies.

For them to have an equal number of cookies, their final counts must be the same:
`A - X = B + X`

Now, we need to solve this equation for `X` to find out how many cookies Alice must give:
1.  Add `X` to both sides:
    `A = B + X + X`
    `A = B + 2X`
2.  Subtract `B` from both sides:
    `A - B = 2X`
3.  Divide by 2:
    `X = (A - B) / 2`

This equation tells us the number of cookies `X` Alice needs to give Bob. However, there's a crucial condition: `X` must be a whole number (an integer), because cookies cannot be split into fractions.

*   Since the problem states `A > B`, the difference `(A - B)` will always be a positive integer.
*   For `X = (A - B) / 2` to be an integer, the numerator `(A - B)` must be an **even number**. If `(A - B)` is odd, then dividing it by 2 will result in a non-integer (e.g., 3/2 = 1.5), which is not a valid number of whole cookies.

Therefore, our logic is:
1.  Calculate the difference in cookies: `difference = A - B`.
2.  Check if `difference` is an even number. This can be done using the modulo operator: `difference % 2 == 0`.
3.  If `difference` is even, then it's possible to share equally. The number of cookies Alice gives is `difference / 2`.
4.  If `difference` is odd, it's impossible to share equally with whole cookies. In this case, we output -1.

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    The solution involves reading two integers, performing a subtraction, a modulo operation, and a division, followed by a print operation. All these operations take constant time, regardless of the magnitude of `A` and `B` (within integer limits).

*   **Space Complexity**: $O(1)$
    The solution uses a few integer variables (`A`, `B`, `difference`) to store input and intermediate calculations. The amount of memory used is constant and does not depend on the input values.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries, as requested.

using namespace std; // Uses the standard namespace, as requested.

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and disables synchronization with C's stdio.
    // As requested by the problem statement.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare two integer variables A and B to store the number of cookies
    // Alice and Bob have, respectively.
    // Constraints: 1 <= B < A <= 10. 'int' is perfectly sufficient.
    int A, B;

    // Read the two integers A and B from standard input.
    // As per the input format, these are on a single line.
    cin >> A >> B;

    // The goal is for Alice and Bob to have an equal number of cookies.
    // Let X be the number of cookies Alice gives to Bob.
    // After Alice gives X cookies:
    // Alice will have (A - X) cookies.
    // Bob will have (B + X) cookies.

    // For them to have an equal number of cookies, their counts must be the same:
    // A - X = B + X

    // Now, we solve this equation for X:
    // A - B = X + X
    // A - B = 2 * X
    // X = (A - B) / 2

    // For X to be a valid number of cookies Alice gives to Bob, it must satisfy two conditions:
    // 1. X must be a non-negative integer.
    //    Since A > B (given in problem statement), (A - B) will always be a positive integer.
    //    Thus, X will always be positive.
    // 2. X must be an integer (no fractional cookies).
    //    This means (A - B) must be an even number. If (A - B) is odd, then (A - B) / 2
    //    will not be an integer, and it's impossible to share equally with whole cookies.

    // Calculate the difference in cookies.
    int difference = A - B;

    // Check if the difference is an even number.
    if (difference % 2 == 0) {
        // If the difference is even, it's possible to share equally.
        // Alice needs to give Bob half of the difference.
        cout << difference / 2 << "\n";
    } else {
        // If the difference is odd, it's impossible to share equally.
        // Output -1 as per problem requirements.
        cout << -1 << "\n";
    }

    return 0; // Indicate successful execution.
}
```