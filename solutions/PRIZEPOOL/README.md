# [Total Prize Money (PRIZEPOOL)](https://www.codechef.com/problems/PRIZEPOOL)
- **Difficulty Rating**: 296
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the total prize money distributed in a contest based on specific rules. The rules are:
1.  The top 10 participants each receive `X` rupees.
2.  Participants ranked from 11 to 100 (inclusive) each receive `Y` rupees.

We need to find the sum of the prize money given to all these participants for a given `X` and `Y`. The calculation needs to be performed for `T` test cases.

## Intuition & Mathematical Observation

This problem is a straightforward application of basic arithmetic. We need to determine the number of participants in each prize category and multiply it by their respective prize amounts, then sum these totals.

1.  **For the top 10 participants**:
    *   There are exactly `10` participants in this category (ranks 1 through 10).
    *   Each of them receives `X` rupees.
    *   So, the total prize money for this group is `10 * X`.

2.  **For participants ranked 11 to 100**:
    *   To find the number of participants in this range, we can use the formula: `last_rank - first_rank + 1`.
    *   Number of participants = `100 - 11 + 1 = 90`.
    *   Each of these `90` participants receives `Y` rupees.
    *   So, the total prize money for this group is `90 * Y`.

3.  **Total Prize Money**:
    *   The total prize money is the sum of the prize money from both groups.
    *   `Total Prize Money = (10 * X) + (90 * Y)`.

The maximum values for `X` and `Y` are 1000. So, the maximum total prize money would be `(10 * 1000) + (90 * 1000) = 10000 + 90000 = 100000`. This value fits comfortably within a standard `int` data type, so no special handling for large numbers is required.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    *   The program iterates `T` times, once for each test case.
    *   Inside the loop, for each test case, it performs a constant number of operations: two integer reads, two multiplications, one addition, and one integer print.
    *   Since these operations take constant time, the total time complexity is directly proportional to the number of test cases, `T`.

-   **Space Complexity**: $O(1)$
    *   The program uses a fixed number of variables (`T`, `X`, `Y`, `total_prize_money`) regardless of the input values or the number of test cases.
    *   The memory usage does not grow with the input size, hence it's constant space complexity.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Using the standard namespace to avoid writing std::
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int X, Y; // Declare integer variables X and Y to store the prize amounts.
        cin >> X >> Y; // Read X and Y for the current test case.

        // Calculate the total prize money.
        // Top 10 participants receive X rupees each. Total for this group: 10 * X.
        // Participants with rank 11 to 100 (which are 100 - 11 + 1 = 90 participants)
        // receive Y rupees each. Total for this group: 90 * Y.
        // The total prize money is the sum of these two amounts.
        // Since X and Y are at most 1000, the maximum total prize money is
        // (10 * 1000) + (90 * 1000) = 10000 + 90000 = 100000.
        // This value fits comfortably within a standard 'int' type.
        int total_prize_money = (10 * X) + (90 * Y);

        // Output the calculated total prize money for the current test case,
        // followed by a newline character as required.
        cout << total_prize_money << "\n";
    }

    return 0; // Indicate successful program execution.
}
```