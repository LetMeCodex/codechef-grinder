# [Good Turn (GDTURN)](https://www.codechef.com/problems/GDTURN)
- **Difficulty Rating**: 238
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a "good turn" is possible given the outcomes of two dice rolls. A good turn is defined as the sum of the outcomes of the two dice being strictly greater than 6. We are given `T` test cases. For each test case, we receive two integers, `X` and `Y`, representing the outcomes of the first and second dice, respectively. Our task is to print "YES" if a good turn is possible (i.e., `X + Y > 6`), and "NO" otherwise.

## Intuition & Mathematical Observation

The problem statement directly provides the condition for a "good turn": the sum of the outcomes of the two dice must be strictly greater than 6. This translates to a simple mathematical inequality: `X + Y > 6`.

Our approach will be to:
1. Read the number of test cases, `T`.
2. Loop `T` times for each test case.
3. Inside the loop, read the two dice outcomes, `X` and `Y`.
4. Calculate their sum: `sum = X + Y`.
5. Check if `sum > 6`.
   - If true, print "YES".
   - If false, print "NO".

This is a straightforward conditional check based on the given definition. No complex algorithms or data structures are required.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    -   The `ios_base::sync_with_stdio(false); cin.tie(NULL);` lines take constant time to optimize I/O.
    -   We iterate `T` times, once for each test case.
    -   Inside each test case, we perform the following operations:
        -   Reading two integers (`x`, `y`): This is a constant time operation.
        -   Performing an addition (`x + y`): This is a constant time operation.
        -   Performing a comparison (`x + y > 6`): This is a constant time operation.
        -   Printing "YES" or "NO": This is a constant time operation.
    -   Since each test case takes a constant amount of time, the total time complexity is directly proportional to the number of test cases, `T`.

-   **Space Complexity**: $O(1)$
    -   We use a few integer variables (`t`, `x`, `y`) to store the number of test cases and the dice outcomes. These variables occupy a fixed amount of memory, regardless of the input values or the number of test cases.
    -   No additional data structures are used that would scale with the input size.
    -   Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin/cout from C's stdio and disables synchronization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Declare variable for the number of test cases
    cin >> t; // Read the number of test cases

    // Loop through each test case
    while (t--) {
        int x, y; // Declare variables for the outcomes of the two dice
        cin >> x >> y; // Read the outcomes of the two dice

        // Check if the sum of the outcomes is strictly greater than 6
        if (x + y > 6) {
            cout << "YES\n"; // If true, print "YES"
        } else {
            cout << "NO\n"; // If false, print "NO"
        }
    }

    return 0; // Indicate successful execution
}

```