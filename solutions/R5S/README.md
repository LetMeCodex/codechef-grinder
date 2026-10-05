# [Reach 5 Star (R5S)](https://www.codechef.com/problems/R5S)
- **Difficulty Rating**: 313
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a user can reach the "5 Star" rating on CodeChef. We are given two integer inputs, `x` and `y`, representing the current rating and the target rating respectively. The condition for reaching 5 Star is that the sum of the current rating (`x`) and the target rating (`y`) must be greater than or equal to 2000. We need to output "YES" if this condition is met, and "NO" otherwise.

## Intuition & Mathematical Observation

The problem statement directly provides the condition for achieving the 5 Star rating: `x + y >= 2000`. There isn't much complex intuition required here. It's a straightforward check based on the given criteria.

The core of the problem is a simple arithmetic comparison. We are given two numbers, `x` and `y`, and we need to check if their sum meets a specific threshold.

Let $S$ be the sum of the current rating and the target rating, i.e., $S = x + y$.
The condition to reach 5 Star is $S \ge 2000$.

Therefore, the logic is:
1. Read the values of `x` and `y`.
2. Calculate their sum: `sum = x + y`.
3. Compare `sum` with 2000.
4. If `sum >= 2000`, output "YES".
5. Otherwise, output "NO".

This is a direct translation of the problem's requirement into a computational step.

## Complexity Analysis

- **Time Complexity**: $O(1)$
The solution involves reading two integers, performing a single addition, and a single comparison. These operations take a constant amount of time, regardless of the magnitude of the input values (within the limits of standard integer types).

- **Space Complexity**: $O(1)$
The solution uses a fixed amount of memory to store the input variables `x` and `y`, and potentially a variable for their sum. This memory usage does not grow with the input size, hence it's constant.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C stdio,
    // potentially speeding up I/O operations.
    // cin.tie(NULL) unties cin from cout, meaning cin operations
    // won't flush cout automatically, further speeding up I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y; // Declare two integer variables to store the current and target ratings.

    // Read the two integer values from standard input.
    cin >> x >> y;

    // Check if the sum of the current rating (x) and the target rating (y)
    // is greater than or equal to 2000.
    if (x + y >= 2000) {
        // If the condition is met, print "YES" followed by a newline character.
        cout << "YES\n";
    } else {
        // If the condition is not met, print "NO" followed by a newline character.
        cout << "NO\n";
    }

    // Return 0 to indicate successful execution of the program.
    return 0;
}
```