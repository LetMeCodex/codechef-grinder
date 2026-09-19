# [Qualify the round (QUALIFY)](https://www.codechef.com/problems/QUALIFY)
- **Difficulty Rating**: 594
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if Chef qualifies for a programming round. To qualify, Chef needs to achieve a total score of at least `X` points. Chef solves `A` easy problems, each worth 1 point, and `B` hard problems, each worth 2 points. We need to calculate Chef's total score and print "Qualify" if his score is `X` or more, otherwise print "NotQualify". This process needs to be repeated for `T` test cases.

## Intuition & Mathematical Observation

The problem is a straightforward application of basic arithmetic and conditional logic.

1.  **Calculate points from easy problems**: Chef solves `A` easy problems, and each is worth 1 point. So, points from easy problems = `A * 1`.
2.  **Calculate points from hard problems**: Chef solves `B` hard problems, and each is worth 2 points. So, points from hard problems = `B * 2`.
3.  **Calculate total score**: Chef's total score is the sum of points from easy and hard problems: `total_score = (A * 1) + (B * 2)`.
4.  **Check qualification**: Compare the `total_score` with the minimum required points `X`.
    *   If `total_score >= X`, Chef qualifies.
    *   Otherwise (`total_score < X`), Chef does not qualify.

This direct calculation and comparison is the core of the solution.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    For each test case, we perform a constant number of operations: two multiplications, one addition, and one comparison. These operations take constant time, $O(1)$. Since there are `T` test cases, the total time complexity will be $T \times O(1) = O(T)$.

-   **Space Complexity**: $O(1)$
    For each test case, we use a few integer variables (`X`, `A`, `B`, `total_score`) to store input and intermediate results. The memory used by these variables is constant and does not depend on the input values or the number of test cases (beyond storing `T` itself). Thus, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries, as requested

// Use the standard namespace to avoid repeatedly typing std::
using namespace std;

// Function to solve a single test case
void solve() {
    int X, A, B;
    // Read the minimum required points (X),
    // number of easy problems solved (A),
    // and number of hard problems solved (B) for the current test case.
    cin >> X >> A >> B;

    // Calculate Chef's total score.
    // Easy problems are worth 1 point each (A * 1).
    // Hard problems are worth 2 points each (B * 2).
    int total_score = (A * 1) + (B * 2);

    // Check if Chef's total score is sufficient to qualify.
    // Chef qualifies if the total score is greater than or equal to X.
    if (total_score >= X) {
        // If Chef qualifies, print "Qualify" followed by a newline.
        cout << "Qualify\n";
    } else {
        // Otherwise, Chef does not qualify, so print "NotQualify" followed by a newline.
        cout << "NotQualify\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard I/O.
    // cin.tie(NULL) prevents cout from being flushed before each cin operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    // Read the number of test cases.
    cin >> T;
    // Loop T times, calling the solve() function for each test case.
    while (T--) {
        solve();
    }

    return 0; // Indicate successful program execution.
}
```