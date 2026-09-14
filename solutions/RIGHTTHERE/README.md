# [Right There (RIGHTTHERE)](https://www.codechef.com/problems/RIGHTTHERE)
- **Difficulty Rating**: 299
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if Chef can host a party. We are given two integers for each test case:
1. `N`: The total number of people Chef wants to invite to the party.
2. `X`: The maximum capacity of the hall where Chef plans to host the party.

Chef can host the party only if the number of people he wants to invite (`N`) is less than or equal to the hall's capacity (`X`). We need to output "YES" if Chef can host the party, and "NO" otherwise.

## Intuition & Mathematical Observation

This problem is a very basic conditional check. The core requirement for Chef to host the party is explicitly stated: the number of guests must not exceed the hall's capacity.

Therefore, the intuition is straightforward:
- If `N <= X` (number of guests is less than or equal to capacity), Chef can host the party.
- If `N > X` (number of guests exceeds capacity), Chef cannot host the party.

There are no complex algorithms, data structures, or mathematical observations required beyond this simple comparison.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    -   The program reads the number of test cases `T` once.
    -   Inside the `while (T--)` loop, for each test case, it performs a constant number of operations: reading two integers (`N` and `X`), performing a single comparison (`N <= X`), and printing a string ("YES" or "NO").
    -   Since these operations take constant time per test case, the total time complexity is directly proportional to the number of test cases, `T`.

-   **Space Complexity**: $O(1)$
    -   The program uses a few integer variables (`T`, `N`, `X`) to store input values.
    -   The memory used by these variables is constant and does not depend on the input size (e.g., the values of `N` or `X`).
    -   Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries

// Using the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from C's stdio and prevents flushing cout before cin.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare variable for the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int N, X; // Declare variables for the total number of people (N) and hall capacity (X)
        cin >> N >> X; // Read N and X for the current test case

        // Chef can host the party if the number of people N is less than or equal to the hall's capacity X.
        if (N <= X) {
            cout << "YES\n"; // If N is less than or equal to X, output YES
        } else {
            cout << "NO\n"; // Otherwise (if N is greater than X), output NO
        }
    }

    return 0; // Indicate successful execution
}
```