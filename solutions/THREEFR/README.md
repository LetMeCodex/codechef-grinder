# [Three Friends (THREEFR)](https://www.codechef.com/problems/THREEFR)
- **Difficulty Rating**: 1074
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if three friends, A, B, and C, can make three specific statements about their age differences true simultaneously. Let their ages be $a, b, c$. The statements are:
1. "My age difference with B is X." This implies $|a - b| = X$.
2. "My age difference with C is Y." This implies $|b - c| = Y$.
3. "My age difference with A is Z." This implies $|c - a| = Z$.

We are given three positive integers $X, Y, Z$ (representing the absolute age differences) and need to output "yes" if such ages $a, b, c$ can exist, and "no" otherwise.

## Intuition & Mathematical Observation

Let's define the actual (signed) age differences:
- Let $x = a - b$
- Let $y = b - c$
- Let $z = c - a$

From the problem statements, we are given the absolute values of these differences:
- $|x| = X$
- $|y| = Y$
- $|z| = Z$

A crucial observation comes from summing these signed differences:
$x + y + z = (a - b) + (b - c) + (c - a)$
$x + y + z = a - b + b - c + c - a$
$x + y + z = 0$

This means that for the three statements to be true, there must exist choices for $x, y, z$ such that:
1. $x \in \{X, -X\}$ (since $|x|=X$)
2. $y \in \{Y, -Y\}$ (since $|y|=Y$)
3. $z \in \{Z, -Z\}$ (since $|z|=Z$)
4. $x + y + z = 0$

Since $X, Y, Z$ are positive integers (given $1 \le X, Y, Z \le 1000$), $x, y, z$ cannot all be positive (their sum $X+Y+Z$ would be greater than 0) and cannot all be negative (their sum $-X-Y-Z$ would be less than 0). Therefore, for their sum to be zero, there must be a mix of positive and negative values among $x, y, z$.

This leads to two possible scenarios for the signs of $x, y, z$:

**Scenario 1: Two values are positive, one is negative.**
- If $x=X, y=Y, z=-Z$: Then $X + Y - Z = 0 \implies X + Y = Z$.
- If $x=X, y=-Y, z=Z$: Then $X - Y + Z = 0 \implies X + Z = Y$.
- If $x=-X, y=Y, z=Z$: Then $-X + Y + Z = 0 \implies Y + Z = X$.

**Scenario 2: One value is positive, two are negative.**
- If $x=X, y=-Y, z=-Z$: Then $X - Y - Z = 0 \implies X = Y + Z$.
- If $x=-X, y=Y, z=-Z$: Then $-X + Y - Z = 0 \implies Y = X + Z$.
- If $x=-X, y=-Y, z=Z$: Then $-X - Y + Z = 0 \implies Z = X + Y$.

Notice that the conditions derived from Scenario 2 are identical to those from Scenario 1. For example, $X = Y+Z$ is the same as $Y+Z = X$.

Therefore, the problem boils down to checking if any one of the given absolute differences ($X, Y, Z$) is equal to the sum of the other two. If this condition holds for at least one permutation, then we can assign signs to $x, y, z$ such that their sum is zero, and thus the statements can be true.

The final condition to check is:
`if (X + Y == Z || X + Z == Y || Y + Z == X)`

If this condition is true, output "yes"; otherwise, output "no".

## Complexity Analysis

-   **Time Complexity**: For each test case, we read three integers ($X, Y, Z$) and perform a constant number of arithmetic operations (three additions) and comparisons. This is an $O(1)$ operation per test case. If there are $T$ test cases, the total time complexity is $O(T)$. Given $T \le 1000$, this is very efficient.

-   **Space Complexity**: We only use a few integer variables to store $X, Y, Z$ and the number of test cases $T$. This is a constant amount of memory, independent of the input values. Thus, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

// Function to solve a single test case
void solve() {
    int X, Y, Z;
    // Read the three absolute differences
    cin >> X >> Y >> Z;

    // The core condition for the statements to be true is that the sum of the
    // actual differences (x, y, z) must be zero: x + y + z = 0.
    // We are given X = |x|, Y = |y|, Z = |z|. We need to determine if there
    // exist choices for the signs of x, y, z such that their sum is zero.
    //
    // Since X, Y, Z are positive (1 <= X, Y, Z <= 1000), the only way for
    // x + y + z = 0 is if some values are positive and some are negative.
    // This leads to three possible scenarios:
    // 1. Two values are positive, one is negative. E.g., x=X, y=Y, z=-Z.
    //    This implies X + Y - Z = 0, which simplifies to X + Y = Z.
    // 2. One value is positive, two are negative. E.g., x=X, y=-Y, z=-Z.
    //    This implies X - Y - Z = 0, which simplifies to X = Y + Z.
    //
    // Considering all permutations for which value is positive/negative,
    // the conditions boil down to checking if any one of X, Y, Z is equal
    // to the sum of the other two.
    if (X + Y == Z || X + Z == Y || Y + Z == X) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    // Read the number of test cases
    cin >> T;
    // Loop through each test case
    while (T--) {
        solve();
    }

    return 0; // Indicate successful execution
}
```