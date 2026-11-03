# Scoring (SCORING)
- **Difficulty Rating**: 569
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to find the individual scores of Alice and Bob given two pieces of information:
1. The difference between Alice's score and Bob's score is $X$.
2. The sum of Alice's score and Bob's score is $Y$.

We are guaranteed that a valid integer solution exists.

## Intuition & Mathematical Observation
Let Alice's score be $A$ and Bob's score be $B$. We are given the following system of linear equations:
1. $A - B = X$
2. $A + B = Y$

This is a classic system of two linear equations with two variables. We can solve for $A$ and $B$ using algebraic manipulation.

**Method 1: Elimination**
Add equation (1) and equation (2):
$(A - B) + (A + B) = X + Y$
$2A = X + Y$
$A = \frac{X + Y}{2}$

Substitute the value of $A$ back into equation (2):
$\frac{X + Y}{2} + B = Y$
$B = Y - \frac{X + Y}{2}$
$B = \frac{2Y - (X + Y)}{2}$
$B = \frac{2Y - X - Y}{2}$
$B = \frac{Y - X}{2}$

**Method 2: Substitution**
From equation (1), we can express $A$ in terms of $B$ and $X$:
$A = X + B$

Substitute this into equation (2):
$(X + B) + B = Y$
$X + 2B = Y$
$2B = Y - X$
$B = \frac{Y - X}{2}$

Now substitute the value of $B$ back into the expression for $A$:
$A = X + \frac{Y - X}{2}$
$A = \frac{2X + Y - X}{2}$
$A = \frac{X + Y}{2}$

Both methods yield the same results:
Alice's score ($A$) = $\frac{X + Y}{2}$
Bob's score ($B$) = $\frac{Y - X}{2}$

The problem statement guarantees that a valid integer solution exists. This implies that $(X + Y)$ and $(Y - X)$ must both be even. This is consistent because if $A$ and $B$ are integers, then their sum ($A+B$) and their difference ($A-B$) must have the same parity. Therefore, $X$ and $Y$ must have the same parity, which means their sum and difference will always be even.

## Complexity Analysis
- **Time Complexity**: $O(1)$
  The solution involves a fixed number of arithmetic operations (addition, subtraction, division) for each test case. The number of test cases is read from input, but the computation per test case is constant.

- **Space Complexity**: $O(1)$
  The solution uses a constant amount of extra space to store variables like `t`, `x`, `y`, `alice_score`, and `bob_score`. This space requirement does not grow with the input size.

## Solution Code
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C stdio.
    // cin.tie(NULL) unties cin from cout, allowing input and output operations to not block each other.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Number of test cases
    cin >> t;
    while (t--) {
        int x, y; // x: difference, y: sum
        cin >> x >> y;

        // Let Alice's score be A and Bob's score be B.
        // We are given two equations:
        // 1. A - B = X (Alice scored X more points than Bob)
        // 2. A + B = Y (Total points scored by both was Y)

        // Solving the system of linear equations:
        // Adding equation 1 and equation 2:
        // (A - B) + (A + B) = X + Y
        // 2A = X + Y
        // A = (X + Y) / 2

        // Substituting A back into equation 2:
        // ((X + Y) / 2) + B = Y
        // B = Y - ((X + Y) / 2)
        // B = (2Y - (X + Y)) / 2
        // B = (2Y - X - Y) / 2
        // B = (Y - X) / 2

        // Since the problem guarantees a valid solution, (X + Y) and (Y - X) will always be even.
        // This is because X and Y must have the same parity.
        // If A and B are integers, then A-B and A+B must have the same parity.
        // X = A-B, Y = A+B. So X and Y must have the same parity.
        // If X and Y have the same parity, then X+Y is even and Y-X is even.

        int alice_score = (x + y) / 2;
        int bob_score = (y - x) / 2;

        cout << alice_score << " " << bob_score << "\n";
    }
    return 0;
}
```