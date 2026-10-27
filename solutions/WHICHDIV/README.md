# [Which Division (WHICHDIV)](https://www.codechef.com/problems/WHICHDIV)
- **Difficulty Rating**: 867
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine which division a person belongs to on CodeChef based on their rating `R`. The rules for division assignment are as follows:
- If `R >= 2000`, the person is in Division 1.
- If `1600 <= R < 2000`, the person is in Division 2.
- If `R < 1600`, the person is in Division 3.

We need to read an integer `R` for each test case and output `1`, `2`, or `3` corresponding to the determined division.

## Intuition & Mathematical Observation

This problem is a direct application of conditional logic. The rules for assigning divisions are clearly defined with specific rating ranges. There are no complex mathematical observations or algorithms required. The core idea is to use `if-else if-else` statements to check the given conditions sequentially.

A common approach for such range-based conditions is to check the highest range first, then the next highest, and so on. This ensures that once a condition is met, the correct division is assigned, and subsequent (lower) range checks are skipped. For example:
1. Check if `R >= 2000`. If true, it's Division 1.
2. Else (meaning `R < 2000`), check if `R >= 1600`. If true, it's Division 2.
3. Else (meaning `R < 1600`), it must be Division 3.

This sequential checking correctly covers all possible rating values and assigns the unique division as per the problem statement.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    The program processes `T` test cases. For each test case, it reads an integer `R` and performs a constant number of comparisons (`if-else if-else`) and an output operation. All these operations take constant time, $O(1)$. Therefore, the total time complexity is directly proportional to the number of test cases, $T$.

-   **Space Complexity**: $O(1)$
    The program uses a few integer variables (`t`, `R`) to store the number of test cases and the current rating. These variables occupy a constant amount of memory, regardless of the input values or the number of test cases. No dynamic data structures or arrays that scale with input size are used.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries

// Use the standard namespace to avoid typing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Declare an integer variable 't' to store the number of test cases.
    cin >> t; // Read the number of test cases from standard input.

    // Loop 't' times, once for each test case.
    // The 't--' decrements 't' after each iteration until it becomes 0.
    while (t--) {
        int R; // Declare an integer variable 'R' to store the person's rating.
        cin >> R; // Read the rating for the current test case.

        // Apply the division rules using if-else if-else statements.
        // Check for Division 1 first (highest rating range).
        if (R >= 2000) {
            cout << 1 << "\n"; // If R is 2000 or more, output 1 for Division 1.
        } 
        // If not Division 1, check for Division 2.
        // This 'else if' implicitly means R < 2000.
        else if (R >= 1600) { 
            cout << 2 << "\n"; // If R is between 1600 and 1999 (inclusive), output 2 for Division 2.
        } 
        // If neither of the above conditions is met, it must be Division 3.
        // This 'else' implicitly means R < 1600.
        else {
            cout << 3 << "\n"; // If R is less than 1600, output 3 for Division 3.
        }
    }

    return 0; // Indicate successful program execution.
}
```