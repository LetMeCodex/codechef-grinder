# [Equalizing Numbers (EQLZING)](https://www.codechef.com/problems/EQLZING)

- **Difficulty Rating**: 823
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two integers $A$ and $B$, we are allowed to perform the following operation any number of times:
1. Choose an integer $d$.
2. Either set $A = A + d$ and $B = B - d$, OR set $A = A - d$ and $B = B + d$.

The goal is to determine if it is possible to make $A$ and $B$ equal using these operations.

## Intuition & Mathematical Observation
Let the initial values be $A$ and $B$. After any number of operations, the sum of the two numbers remains invariant:
$$(A + d) + (B - d) = A + B$$
$$(A - d) + (B + d) = A + B$$

If we reach a state where $A' = B' = X$, then the sum must be $X + X = 2X$. This implies that the sum of the two numbers must be an even number for them to be equal.

Furthermore, consider the difference between the two numbers. In each operation, the difference changes by $2d$ or $-2d$. This means the parity of the difference $(A - B)$ remains constant. For the numbers to become equal, the final difference must be $0$. Since $0$ is an even number, the initial difference $(A - B)$ must also be even.

Both conditions (the sum being even and the difference being even) are equivalent to saying that $A$ and $B$ must have the same parity. If $(A + B)$ is even, we can always choose $d = \frac{|A - B|}{2}$ to make both numbers equal to their average $\frac{A+B}{2}$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a simple parity check. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the inputs.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimize standard I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;

        // The operation allows us to shift values between A and B.
        // The sum (A + B) remains constant.
        // For A and B to become equal to some value X, 
        // the sum must be 2X, which is always even.
        // Thus, A and B can be equal if and only if (A + B) is even.
        
        if ((a + b) % 2 == 0) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
```