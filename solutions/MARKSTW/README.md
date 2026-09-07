# [Alice and Marks (MARKSTW)](https://www.codechef.com/problems/MARKSTW)
- **Difficulty Rating**: 362
- **Solved in**: 2 attempt(s)

## Problem Summary

Alice and Bob have taken a test. Alice scored `X` marks, and Bob scored `Y` marks. Alice will be happy if her score `X` is at least twice Bob's score `Y`. The task is to determine whether Alice is happy and print "Yes" or "No" accordingly.

## Intuition & Mathematical Observation

The problem statement provides a direct condition for Alice's happiness: "her score is at least twice Bob's score".
Let's translate this into a mathematical inequality:
*   Alice's score: `X`
*   Bob's score: `Y`
*   "Twice Bob's score": `2 * Y`
*   "At least" means "greater than or equal to" (`>=`).

Combining these, Alice is happy if and only if `X >= 2 * Y`.

Our approach will be to:
1.  Read Alice's score `X` and Bob's score `Y`.
2.  Check if the condition `X >= 2 * Y` is true.
3.  If it's true, print "Yes".
4.  Otherwise (if `X < 2 * Y`), print "No".

This is a straightforward conditional check.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The solution involves reading two integers, performing a single multiplication and a single comparison, and then printing a string. All these operations take a constant amount of time, irrespective of the magnitude of `X` and `Y` (within standard integer limits). Therefore, the time complexity is constant.

-   **Space Complexity**: $O(1)$
    The solution uses a fixed amount of memory to store two integer variables (`X` and `Y`). No dynamic data structures or arrays are used, and the memory usage does not scale with the input values. Hence, the space complexity is constant.

## Solution Code

```cpp
#include <iostream> // Specific include for cin/cout, instead of bits/stdc++.h
// #include <bits/stdc++.h> // Can still use this, but iostream is more precise for this problem
using namespace std;

// Function to solve a single test case
void solve() {
    int X, Y;
    // Read Alice's score (X) and Bob's score (Y)
    cin >> X >> Y;

    // Alice is happy if her score X is at least twice Bob's score Y.
    // This condition can be written as X >= 2 * Y.
    if (X >= 2 * Y) {
        // If the condition is met, Alice is happy.
        cout << "Yes\n";
    } else {
        // Otherwise, Alice is not happy.
        cout << "No\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // According to the problem statement's "Input Format",
    // there is only one test case per execution.
    // We do NOT read a 't' for the number of test cases.
    solve(); // Call the solve function once for the single test case

    return 0; // Indicate successful execution
}
```