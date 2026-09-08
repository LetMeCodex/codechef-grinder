# [Determine the Score (DETSCORE)](https://www.codechef.com/problems/DETSCORE)
- **Difficulty Rating**: 267
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate Chef's total score in a placement test. We are given two integers for each test case:
1. `X`: The total points for the entire test.
2. `N`: The number of problems Chef passed.

We are also told that:
- There were exactly 10 problems in the test.
- Each problem was worth the same number of points.
- `X` is guaranteed to be a multiple of 10.

Our task is to output Chef's total score.

## Intuition & Mathematical Observation

The core of this problem lies in correctly interpreting the given information and performing a simple calculation.

1.  **Points per problem**: We know the total points for the test (`X`) and the total number of problems (10). Since each problem is worth the same number of points, we can find the points awarded for a single problem by dividing the total points by the number of problems.
    *   Points per problem = `X / 10`
    *   The problem guarantees that `X` is a multiple of 10, so this division will always result in an integer.

2.  **Chef's total score**: Chef passed `N` problems. To find Chef's total score, we multiply the points awarded for each problem by the number of problems Chef passed.
    *   Chef's total score = (Points per problem) * `N`
    *   Substituting the first observation: Chef's total score = `(X / 10) * N`

This formula directly gives us the required score. The problem is a straightforward arithmetic calculation.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    For each test case, we perform a constant number of arithmetic operations (one division and one multiplication). Since there are $T$ test cases, the total time complexity is directly proportional to $T$. Given the constraints ($T \le 100$), this is extremely efficient.

*   **Space Complexity**: $O(1)$
    We only use a few integer variables to store the input values (`T`, `X`, `N`) and the calculated `score`. The memory usage remains constant regardless of the input values (within integer limits), hence the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Include all standard libraries

// Use the standard namespace
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare variable for number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int X, N; // Declare variables for total points and passed test cases
        cin >> X >> N; // Read X (total points) and N (passed test cases) for the current test case

        // The problem states there are exactly 10 problems, and each is worth the same number of points.
        // Also, X is guaranteed to be a multiple of 10.
        // So, points per problem = X / 10.
        // Chef's total score is (points per problem) * (number of passed problems).
        int score = (X / 10) * N;

        // Output the calculated score followed by a newline
        cout << score << "\n";
    }

    return 0; // Indicate successful execution
}
```