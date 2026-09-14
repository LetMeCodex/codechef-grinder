# [Mana Points (MANAPTS)](https://www.codechef.com/problems/MANAPTS)

- **Difficulty Rating**: 327
- **Solved in**: 1 attempt(s)

## Problem Summary
Chefario has $Y$ mana points available, and each special attack requires $X$ mana points. The goal is to determine the maximum number of special attacks Chefario can perform given his current mana pool.

## Intuition & Mathematical Observation
To find the maximum number of attacks, we need to find the largest integer $k$ that satisfies the inequality:
$$k \times X \le Y$$

By rearranging this inequality, we get:
$$k \le \frac{Y}{X}$$

Since $k$ must be an integer, the maximum value for $k$ is simply the result of integer division of $Y$ by $X$ (i.e., $\lfloor Y/X \rfloor$). In C++, the `/` operator performs integer division by default, which truncates the decimal part, perfectly matching our requirement. If $Y < X$, the result is $0$, which is also handled correctly by this logic.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a single constant-time division operation.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chefario has Y mana points and each special attack costs X mana points.
 * To find the maximum number of attacks, we need to find the largest integer k
 * such that k * X <= Y.
 * This is equivalent to the integer division of Y by X: floor(Y / X).
 * 
 * Constraints:
 * T <= 10^5
 * X <= 100
 * Y <= 1000
 * Since Y/X will not exceed 1000, standard 'int' is sufficient.
 * Time Complexity: O(T)
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O setup for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int x, y;
        cin >> x >> y;
        
        // The maximum number of attacks is simply the quotient of Y divided by X.
        // If Y < X, the result is 0, which is correctly handled by integer division.
        int max_attacks = y / x;
        
        cout << max_attacks << "\n";
    }
    
    return 0;
}
```