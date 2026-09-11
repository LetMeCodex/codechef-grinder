# [Exams (EXAMCHEF)](https://www.codechef.com/problems/EXAMCHEF)

- **Difficulty Rating**: 519
- **Solved in**: 1 attempt(s)

## Problem Summary
Given $X$ schools, each having $Y$ students, and $Z$ students who passed the exam, determine if more than 50% of the total students passed the exam. Output "YES" if the condition is met, otherwise output "NO".

## Intuition & Mathematical Observation
The total number of students is calculated as $X \times Y$. The condition for passing is that the number of students who passed ($Z$) must be strictly greater than 50% of the total students.

Mathematically, we need to check:
$$Z > \frac{X \times Y}{2}$$

To avoid potential floating-point precision issues or division errors, we can multiply both sides of the inequality by 2:
$$2 \times Z > X \times Y$$

This approach uses integer arithmetic, which is safer and more efficient. Since the maximum value of $X \times Y$ is $5 \times 50 = 250$, standard integer types are sufficient to store the results.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case performs a constant number of arithmetic operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Total students = X * Y
 * Passed students = Z
 * Condition: Z > 50% of (X * Y)
 * Mathematically: Z > (X * Y) / 2
 * To avoid floating point issues, we can multiply both sides by 2:
 * 2 * Z > X * Y
 * 
 * Constraints:
 * X <= 5, Y <= 50, Z <= X*Y
 * Max value of X*Y is 250, so standard 'int' is sufficient.
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;
        
        long long total_students = x * y;
        
        // We need to check if z / total_students > 0.5
        // Which is equivalent to 2 * z > total_students
        if (2 * z > total_students) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```