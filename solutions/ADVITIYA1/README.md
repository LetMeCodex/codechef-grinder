# [Advitiya (ADVITIYA1)](https://www.codechef.com/problems/ADVITIYA1)
- **Difficulty Rating**: 243
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a given date `N` (representing a day in February) falls within the dates of the Advitiya fest. The Advitiya fest is held on the 16th, 17th, and 18th of February. If the given date `N` is one of these days, we should print "ADVITIYA". Otherwise, if `N` is any other day, we should print "WAITING FOR ADVITIYA". The input `N` is guaranteed to be between 1 and 18, inclusive.

## Intuition & Mathematical Observation

This problem is a very basic conditional check. We are given a specific range of dates (16, 17, 18) that signify the Advitiya fest. Our task is simply to check if the input date `N` falls within this predefined range.

The core intuition is:
1. Read the input date `N`.
2. Check if `N` is greater than or equal to 16 AND less than or equal to 18.
3. If both conditions are true, it means `N` is 16, 17, or 18, so print "ADVITIYA".
4. Otherwise, `N` must be a date from 1 to 15 (given the constraints), so print "WAITING FOR ADVITIYA".

There are no complex mathematical observations or algorithms required; it's a direct application of an `if-else` statement with a range check.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The program performs a constant number of operations: reading one integer, a single comparison, and printing a string. These operations take a fixed amount of time regardless of the input value `N` (within its given constraints).

-   **Space Complexity**: $O(1)$
    The program uses a fixed amount of memory for storing variables (like `N`) and for standard input/output buffers. The memory usage does not scale with the input value `N`.

## Solution Code

```cpp
#include <bits/stdc++.h> // Include all standard libraries as requested

using namespace std; // Use the standard namespace as requested

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; // Declare an integer variable N to store the date.
    cin >> N; // Read the date N from standard input.

    // The Advitiya fest runs on the 16th, 17th, and 18th of February.
    // We need to check if the date N falls within this range.
    // The constraints state 1 <= N <= 18, so N will always be a valid date within February up to the 18th.
    if (N >= 16 && N <= 18) {
        // If N is 16, 17, or 18, Mehul will be able to enjoy the fest.
        cout << "ADVITIYA\n"; // Print "ADVITIYA" followed by a newline.
    } else {
        // If N is any other date (1 through 15), Mehul will have to wait.
        cout << "WAITING FOR ADVITIYA\n"; // Print "WAITING FOR ADVITIYA" followed by a newline.
    }

    return 0; // Indicate successful program execution.
}
```