# [Counting Pretty Numbers (NUM239)](https://www.codechef.com/problems/NUM239)
- **Difficulty Rating**: 873
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to count "pretty numbers" within a given range `[L, R]` (inclusive). A number is defined as "pretty" if its last digit is either 2, 3, or 9. We need to perform this counting for `T` independent test cases.

## Intuition & Mathematical Observation

The core of this problem lies in identifying what makes a number "pretty". The definition explicitly states that a number is pretty if its *last digit* is 2, 3, or 9. This is a very direct condition.

1.  **Finding the last digit**: For any positive integer `N`, its last digit can be easily obtained using the modulo operator: `N % 10`. For example, `123 % 10` is 3, `45 % 10` is 5, and `9 % 10` is 9.
2.  **Checking the condition**: Once we have the last digit, we simply need to check if it is equal to 2, 3, or 9.
3.  **Iterating through the range**: Since we need to count pretty numbers within a range `[L, R]`, the most straightforward approach is to iterate through every number `i` from `L` to `R`. For each `i`, we apply the two steps above. If `i` is pretty, we increment a counter.

This approach is efficient enough because the typical constraints for `L` and `R` in problems of this difficulty (around 873) usually allow for a linear scan of the range. For example, if `R - L` is up to `10^5`, iterating through all numbers is perfectly fine.

## Complexity Analysis

*   **Time Complexity**: $O(T \cdot (R - L + 1))$
    *   For each test case, we iterate through all numbers from `L` to `R`. The number of iterations is `R - L + 1`.
    *   Inside the loop, we perform a modulo operation (`i % 10`) and a few comparisons, all of which are constant time operations, $O(1)$.
    *   Therefore, for a single test case, the time complexity is $O(R - L + 1)$.
    *   Since there are `T` test cases, the total time complexity is $O(T \cdot (R - L + 1))$. If we denote the maximum range size as $N_{max} = \max(R-L+1)$, the complexity is $O(T \cdot N_{max})$.

*   **Space Complexity**: $O(1)$
    *   The solution uses a few integer variables (`L`, `R`, `pretty_count`, `i`, `last_digit`, `T`).
    *   The memory used by these variables is constant and does not depend on the input values `L`, `R`, or `T`.

## Solution Code

```cpp
#include <bits/stdc++.h> // Required header as per problem instructions

using namespace std; // Required as per problem instructions

void solve() {
    int L, R;
    cin >> L >> R; // Read L and R for the current test case

    int pretty_count = 0; // Initialize a counter for pretty numbers

    // Iterate through all numbers from L to R (inclusive)
    for (int i = L; i <= R; ++i) {
        // Get the last digit of the current number i
        int last_digit = i % 10;

        // Check if the last digit is 2, 3, or 9
        if (last_digit == 2 || last_digit == 3 || last_digit == 9) {
            pretty_count++; // If it is, increment the counter
        }
    }

    // Print the total count of pretty numbers for this test case
    cout << pretty_count << "\n";
}

int main() {
    // Fast I/O setup as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```