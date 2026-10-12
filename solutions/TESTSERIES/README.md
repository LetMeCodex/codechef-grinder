# [Test Match Series (TESTSERIES)](https://www.codechef.com/problems/TESTSERIES)
- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a 5-match test series between India and England. For each of the 5 matches, a result `R_i` is provided:
*   `R_i = 1`: India won the match.
*   `R_i = 2`: England won the match.
*   `R_i = 0`: The match was a draw.

The task is to determine the winner of the entire series.
*   If India wins strictly more matches than England, output "INDIA".
*   If England wins strictly more matches than India, output "ENGLAND".
*   If both teams win the same number of matches (this includes the case where both win 0 matches), output "DRAW".

This process needs to be repeated for `T` independent test cases.

## Intuition & Mathematical Observation

The problem is a straightforward counting and comparison task. There are no complex mathematical observations required. The core idea is to:

1.  **Initialize Counters**: Maintain two separate counters, one for the total matches won by India and another for the total matches won by England. Both should start at zero for each test case.
2.  **Process Match Results**: Iterate through the results of the 5 matches. For each match result `R_i`:
    *   If `R_i` is `1`, increment India's win counter.
    *   If `R_i` is `2`, increment England's win counter.
    *   If `R_i` is `0`, the match was a draw, so neither team's win counter is incremented.
3.  **Determine Series Winner**: After processing all 5 match results, compare the final win counts:
    *   If `india_wins > england_wins`, India is the series winner.
    *   If `england_wins > india_wins`, England is the series winner.
    *   Otherwise (if `india_wins == england_wins`), the series is a draw.

This logic directly translates to conditional statements and simple arithmetic operations.

## Complexity Analysis

*   **Time Complexity**: For each test case, the program performs a fixed number of operations:
    *   It initializes two integer variables (constant time).
    *   It loops exactly 5 times to read 5 match results. Inside the loop, it performs a constant number of operations (reading an integer, two comparisons, and at most one increment).
    *   After the loop, it performs a few comparisons and prints a string (constant time).
    Since the number of operations per test case is constant (independent of any input size, as the number of matches is fixed at 5), the time complexity per test case is $O(1)$.
    Given `T` test cases, the total time complexity will be $O(T \times 1) = \mathbf{O(T)}$.

*   **Space Complexity**: The program uses a fixed number of integer variables to store the win counts (`india_wins`, `england_wins`), the current match result (`R_i`), the loop counter (`i`), and the number of test cases (`T`). The amount of memory used does not depend on the input values or `T`. Therefore, the space complexity is $\mathbf{O(1)}$ (constant space).

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

// Function to solve a single test case
void solve() {
    int india_wins = 0;    // Counter for matches won by India
    int england_wins = 0;  // Counter for matches won by England

    // Loop 5 times to read the results of all 5 matches
    for (int i = 0; i < 5; ++i) {
        int R_i; // Variable to store the result of the current match
        cin >> R_i; // Read the match result

        // Check the result and update the respective win counter
        if (R_i == 1) {
            // India won this match
            india_wins++;
        } else if (R_i == 2) {
            // England won this match
            england_wins++;
        }
        // If R_i == 0, it's a draw, so neither counter is incremented.
    }

    // Determine the winner of the series based on the total wins
    if (india_wins > england_wins) {
        // India won strictly more matches
        cout << "INDIA\n";
    } else if (england_wins > india_wins) {
        // England won strictly more matches
        cout << "ENGLAND\n";
    } else {
        // Both teams won the same number of matches, or neither won any
        cout << "DRAW\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases

    // Loop T times, calling the solve function for each test case
    while (T--) {
        solve();
    }

    return 0; // Indicate successful execution
}
```