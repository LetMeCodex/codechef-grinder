This writeup provides a clean, high-quality solution for the CodeChef problem "Diagonal movement (DIAGMOVE)" in GitHub-Flavored Markdown.

---

# [Diagonal movement (DIAGMOVE)](https://www.codechef.com/problems/DIAGMOVE)
- **Difficulty Rating**: 1157
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks whether a target point `(x, y)` can be reached from the origin `(0, 0)` using only diagonal moves. A diagonal move from `(a, b)` allows moving to any of the four points: `(a+1, b+1)`, `(a+1, b-1)`, `(a-1, b+1)`, or `(a-1, b-1)`. We need to determine if `(x, y)` is reachable for given `x` and `y` coordinates.

## Intuition & Mathematical Observation

Let's analyze the effect of a diagonal move on the coordinates `(x, y)`.
A diagonal move changes `(x, y)` to `(x \pm 1, y \pm 1)`. This means both the `x` and `y` coordinates are incremented or decremented by 1.

Consider the parity of `x` and `y` (whether they are even or odd):
- If `x` is even, `x \pm 1` will be odd.
- If `x` is odd, `x \pm 1` will be even.
The same applies to `y`.
Therefore, after any diagonal move, both `x` and `y` coordinates *flip their parity*.

Now, let's look at the parity of `x` and `y` relative to each other:
1.  **Initial state**: We start at `(0, 0)`. Here, `x=0` (even) and `y=0` (even). Both `x` and `y` have the *same parity*.

2.  **After one move**:
    - If we move from `(0, 0)` to `(1, 1)`: `x=1` (odd), `y=1` (odd). Both have the *same parity*.
    - If we move from `(0, 0)` to `(1, -1)`: `x=1` (odd), `y=-1` (odd). Both have the *same parity*.
    - If we move from `(0, 0)` to `(-1, 1)`: `x=-1` (odd), `y=1` (odd). Both have the *same parity*.
    - If we move from `(0, 0)` to `(-1, -1)`: `x=-1` (odd), `y=-1` (odd). Both have the *same parity*.

It appears that after any number of diagonal moves, the `x` and `y` coordinates will always maintain the same parity relationship they started with. Since they start with the same parity (both even), any reachable point `(x, y)` must also have `x` and `y` with the same parity.

**Proof by Induction:**
*   **Base Case**: At `(0, 0)`, `x=0` and `y=0`. Both are even, so they have the same parity.
*   **Inductive Step**: Assume that after `k` moves, we are at `(x_k, y_k)` and `x_k` and `y_k` have the same parity.
    Now, we make one more move to `(x_{k+1}, y_{k+1})`, where `x_{k+1} = x_k \pm 1` and `y_{k+1} = y_k \pm 1`.
    *   If `x_k` and `y_k` are both even: `x_{k+1}` will be odd, and `y_{k+1}` will be odd. Thus, `x_{k+1}` and `y_{k+1}` have the same parity.
    *   If `x_k` and `y_k` are both odd: `x_{k+1}` will be even, and `y_{k+1}` will be even. Thus, `x_{k+1}` and `y_{k+1}` have the same parity.
In both cases, if `x_k` and `y_k` have the same parity, then `x_{k+1}` and `y_{k+1}` also have the same parity.

Therefore, any point `(x, y)` reachable from `(0, 0)` must have `x` and `y` with the same parity.

**Condition for same parity:**
Two numbers `x` and `y` have the same parity if and only if their sum `(x + y)` is even.
*   If `x` is even and `y` is even, `x + y` is even.
*   If `x` is odd and `y` is odd, `x + y` is even.
*   If `x` is even and `y` is odd, `x + y` is odd.
*   If `x` is odd and `y` is even, `x + y` is odd.

So, the condition simplifies to checking if `(x + y) % 2 == 0`. If this condition holds, the point is reachable ("YES"); otherwise, it's not ("NO"). This condition works correctly for negative numbers as well, as C++'s `%` operator handles negative numbers in a way that preserves parity (e.g., `-3 % 2` is `-1`, indicating odd).

The problem statement implies that this parity condition is also sufficient, meaning if the condition holds, the point *can* be reached. This is a common pattern in competitive programming problems involving grid movements and parity.

## Complexity Analysis

*   **Time Complexity**: For each test case, we read two `long long` integers and perform a single addition and a modulo operation. These are constant time operations. Given `T` test cases, the total time complexity is $O(T)$.
*   **Space Complexity**: We only use a few variables (`x`, `y`, `t`) to store input and loop counters. This requires a constant amount of memory, so the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Using namespace std; is requested by the problem statement.
using namespace std;

void solve() {
    long long x, y; // Using long long for x, y to safely handle inputs up to 10^9.
    cin >> x >> y;

    // A point (x, y) is reachable from (0, 0) if and only if
    // x and y have the same parity.
    // This condition is equivalent to (x + y) being an even number.
    // For example:
    // If x is even, y is even -> x+y is even.
    // If x is odd, y is odd -> x+y is even.
    // If x is even, y is odd -> x+y is odd.
    // If x is odd, y is even -> x+y is odd.
    // The modulo operator (%) works correctly with negative numbers in C++ for parity checks.
    // E.g., (-4) % 2 == 0, (-3) % 2 == -1.
    if ((x + y) % 2 == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Fast I/O setup as requested for competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of testcases
    while (t--) { // Loop through each testcase
        solve(); // Call the solve function for each testcase
    }

    return 0;
}

```