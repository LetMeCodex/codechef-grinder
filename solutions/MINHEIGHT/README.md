# [Roller Coaster (MINHEIGHT)](https://www.codechef.com/problems/MINHEIGHT)
- **Difficulty Rating**: 285
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a person of height $x$ can ride a roller coaster. The roller coaster has a minimum height requirement of $h$. If the person's height $x$ is greater than or equal to the minimum height requirement $h$, they can ride. Otherwise, they cannot. We are given $t$ test cases, each with a person's height $x$ and the roller coaster's minimum height requirement $h$.

## Intuition & Mathematical Observation
The core of the problem lies in a simple comparison. The roller coaster has a rule: you must be at least a certain height to ride. This translates directly to a mathematical inequality.

Let $x$ be the height of the person.
Let $h$ be the minimum height requirement for the roller coaster.

The condition for being able to ride the roller coaster is:
$x \ge h$

If this condition is true, the answer is "YES".
If this condition is false (i.e., $x < h$), the answer is "NO".

The problem is straightforward and doesn't involve any complex algorithms or data structures. It's a direct application of conditional logic.

## Complexity Analysis
- **Time Complexity**: $O(1)$
  For each test case, we perform a single comparison ($x \ge h$) and then print a string. This operation takes constant time. Since there are $t$ test cases, the total time complexity is $O(t \times 1) = O(t)$. However, if we consider the complexity per test case, it is $O(1)$.

- **Space Complexity**: $O(1)$
  We only use a few variables to store the input values ($t$, $x$, and $h$) and loop counters. The amount of memory used does not grow with the input size, making the space complexity constant.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Number of test cases
    cin >> t;

    // Loop through each test case
    while (t--) {
        int x, h; // x: person's height, h: minimum height requirement
        cin >> x >> h;

        // Check if the person's height meets the minimum requirement
        if (x >= h) {
            cout << "YES\n"; // Person can ride
        } else {
            cout << "NO\n";  // Person cannot ride
        }
    }

    return 0;
}
```