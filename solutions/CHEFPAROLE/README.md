# [Chef and Parole (CHEFPAROLE)](https://www.codechef.com/problems/CHEFPAROLE)
- **Difficulty Rating**: 242
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if Chef will be granted parole. The condition for parole is simple: Chef must have served **at least 7 years**. We are given an integer `X`, representing the number of years Chef has served. Our task is to output "Yes" if Chef qualifies for parole, and "No" otherwise.

## Intuition & Mathematical Observation

This problem is a direct application of a given condition. The phrase "at least 7 years" mathematically translates to `X >= 7`. There are no complex algorithms, data structures, or intricate mathematical properties to observe. We simply need to read the input `X` and check if it satisfies this inequality. If `X` is greater than or equal to 7, Chef gets parole ("Yes"); otherwise, Chef does not ("No").

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The program performs a fixed number of operations regardless of the input value `X`. These operations include reading an integer, performing a single comparison, and printing a string. All these operations take constant time.
-   **Space Complexity**: $O(1)$
    The program uses a single integer variable `X` to store the input. This requires a constant amount of memory, irrespective of the value of `X` (within the limits of an `int`).

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common headers like iostream for input/output

using namespace std; // Using the standard namespace to avoid std:: prefix

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X; // Declare an integer variable 'X' to store the number of years Chef has served.
    cin >> X; // Read the value of X from standard input.

    // Check the condition for parole: if X is 7 or more.
    if (X >= 7) {
        cout << "Yes\n"; // If Chef has served at least 7 years, print "Yes" followed by a newline.
    } else {
        cout << "No\n"; // Otherwise (if X is less than 7), print "No" followed by a newline.
    }

    return 0; // Indicate successful program execution.
}
```