# [Read Pages (READPAGES)](https://www.codechef.com/problems/READPAGES)
- **Difficulty Rating**: 343
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if Chef can finish reading a book within a given number of days. Chef has a book with `N` pages. He reads `X` pages per day and has `Y` days available to read the book. We need to output "YES" if he can complete the book within `Y` days, and "NO" otherwise. This process needs to be repeated for `T` test cases.

## Intuition & Mathematical Observation

The core idea is to calculate the total number of pages Chef can read within the given `Y` days and then compare it with the total pages in the book, `N`.

1.  **Pages per day**: Chef reads `X` pages each day.
2.  **Total days available**: Chef has `Y` days.
3.  **Maximum pages Chef can read**: In `Y` days, if Chef reads `X` pages every day, the maximum total pages he can read is `X * Y`.
4.  **Condition for completion**: To finish the book, the total number of pages in the book (`N`) must be less than or equal to the maximum number of pages Chef can read (`X * Y`).
    *   If `N <= X * Y`, Chef can finish the book.
    *   If `N > X * Y`, Chef cannot finish the book.

Based on this, we simply need to calculate `X * Y` and compare it with `N`.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    *   The program iterates `T` times, once for each test case.
    *   Inside each test case, it performs a constant number of operations: reading three integers (`N`, `X`, `Y`), one multiplication (`X * Y`), one comparison (`N <= X * Y`), and one print operation. All these operations take constant time, $O(1)$.
    *   Therefore, the total time complexity is proportional to the number of test cases, $O(T)$.

-   **Space Complexity**: $O(1)$
    *   The program uses a fixed number of integer variables (`T`, `N`, `X`, `Y`, `max_pages_chef_can_read`) regardless of the input values or the number of test cases.
    *   No data structures that grow with input size are used.
    *   Hence, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cout from flushing before cin reads input.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases
    cin >> T; // Read the number of test cases from input

    // Loop T times, once for each test case
    while (T--) {
        int N, X, Y; // Declare integer variables for N, X, and Y
        cin >> N >> X >> Y; // Read N, X, and Y for the current test case

        // Calculate the maximum total pages Chef can read in Y days.
        // Chef reads at most X pages per day, so over Y days, the maximum is X * Y.
        int max_pages_chef_can_read = X * Y;

        // Check if the total pages N are less than or equal to
        // the maximum pages Chef can read.
        if (N <= max_pages_chef_can_read) {
            // If N is less than or equal, Chef can complete the book.
            cout << "YES\n"; 
        } else {
            // Otherwise, Chef cannot complete the book.
            cout << "NO\n";
        }
    }

    return 0; // Indicate successful program execution
}
```