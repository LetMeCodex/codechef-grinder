# [Expert Setter (EXPERT)](https://www.codechef.com/problems/EXPERT)

- **Difficulty Rating**: 561
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a developer is an "expert" based on their problem-solving record. A developer is considered an expert if at least 50% of their submitted problems are approved. Given $X$ (total problems submitted) and $Y$ (problems approved), we need to output "YES" if the condition is met, and "NO" otherwise.

## Intuition & Mathematical Observation
The condition for being an expert is:
$$\frac{Y}{X} \geq 0.5$$

To avoid potential floating-point precision errors (which can occur when using `double` or `float`), we can rearrange the inequality by multiplying both sides by $2X$:
$$2 \times Y \geq X$$

This transformation allows us to perform the check using simple integer arithmetic, which is both faster and safer. Since the constraints state $1 \leq Y \leq X \leq 10^6$, the values will easily fit within standard integer types, though `long long` is used in the implementation for safety.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and perform the comparison, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * An expert is defined as someone who has at least 50% of their problems approved.
 * Given X total problems and Y approved problems:
 * The condition is (Y / X) >= 0.5
 * To avoid floating point precision issues, we can multiply both sides by 2X:
 * 2 * Y >= X
 * 
 * Constraints:
 * 1 <= T <= 1000
 * 1 <= Y <= X <= 10^6
 * Since X and Y fit within standard integer types, long long is safe but int is sufficient.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y;
        cin >> x >> y;
        
        // Check if at least 50% of problems are approved
        // 2 * Y >= X is equivalent to Y/X >= 0.5
        if (2 * y >= x) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```