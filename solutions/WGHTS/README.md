# [Weights (WGHTS)](https://www.codechef.com/problems/WGHTS)
- **Difficulty Rating**: 697
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a target weight `W` can be measured using any combination of three available weights `X`, `Y`, and `Z`. The key constraint is that each of the available weights (`X`, `Y`, `Z`) can be used at most once. We need to output "YES" if `W` can be formed, and "NO" otherwise.

## Intuition & Mathematical Observation

The problem boils down to checking if the target weight `W` is equal to the sum of any subset of the given three weights `X`, `Y`, and `Z`. Since we can use each weight at most once, the possible combinations of weights we can use are:

1.  **Using a single weight**: `X`, `Y`, or `Z`.
2.  **Using two weights**: `X + Y`, `X + Z`, or `Y + Z`.
3.  **Using all three weights**: `X + Y + Z`.

These are all the possible non-empty subsets of the given weights. If `W` matches any of these sums, then it's possible to measure `W`. Otherwise, it's not.

The solution directly implements this logic by checking each of these possibilities sequentially. A `boolean` flag `possible` is used to track if a match has been found. Once `possible` becomes `true`, further checks are skipped to optimize slightly, though for such a small number of checks, it's not strictly necessary for performance.

## Complexity Analysis

*   **Time Complexity**: $O(1)$ per test case.
    For each test case, the solution performs a fixed, small number of arithmetic operations (additions) and comparisons. Specifically, it checks at most 3 single weights, 3 pairs of weights, and 1 combination of all three weights. This constant number of operations does not depend on the magnitude of `W`, `X`, `Y`, or `Z`. If there are `T` test cases, the total time complexity will be $O(T \times 1) = O(T)$.

*   **Space Complexity**: $O(1)$.
    The solution uses a constant amount of extra space to store a few integer variables (`W`, `X`, `Y`, `Z`, `T`) and a boolean flag (`possible`). This memory usage remains constant regardless of the input values or the number of test cases.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries

using namespace std; // Allows using standard library elements without the std:: prefix

// Function to solve a single test case
void solve() {
    int W, X, Y, Z;
    cin >> W >> X >> Y >> Z; // Read the four weights

    bool possible = false; // Flag to track if W can be measured

    // Check if W can be measured using a single weight
    if (W == X || W == Y || W == Z) {
        possible = true;
    }

    // If not found yet, check combinations of two weights
    // The `!possible` check ensures we only proceed if a solution hasn't been found
    if (!possible && (W == X + Y || W == X + Z || W == Y + Z)) {
        possible = true;
    }

    // If not found yet, check the combination of all three weights
    if (!possible && (W == X + Y + Z)) {
        possible = true;
    }

    // Output the result based on the 'possible' flag
    if (possible) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}
```