# [Valid Triangles (FLOW013)](https://www.codechef.com/problems/FLOW013)

- **Difficulty Rating**: 750
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to determine whether three given interior angles ($A, B, C$) can form a valid triangle. A triangle is considered valid if and only if the sum of its three interior angles is exactly 180 degrees.

## Intuition & Mathematical Observation
In Euclidean geometry, the sum of the interior angles of any triangle is always 180 degrees. Therefore, the problem simplifies to a basic arithmetic check:
1. Read the three input integers $A, B,$ and $C$.
2. Calculate their sum: $S = A + B + C$.
3. If $S = 180$, output "YES".
4. Otherwise, output "NO".

Since the constraints on the angles are small, standard integer types are sufficient, though `long long` is used here for safety.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. We perform a constant number of operations for each test case.
- **Space Complexity**: $O(1)$, as we only use a fixed amount of memory to store the three angles regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Valid Triangles
 * Logic: A triangle is valid if and only if the sum of its three interior angles is exactly 180 degrees.
 * Time Complexity: O(T), where T is the number of test cases.
 * Space Complexity: O(1), as we only use a few integer variables.
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        long long a, b, c;
        cin >> a >> b >> c;

        // Check if the sum of angles equals 180
        if (a + b + c == 180) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```