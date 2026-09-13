# [404 Not Found (ERROR404)](https://www.codechef.com/problems/ERROR404)
- **Difficulty Rating**: 267
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to read a single integer `X`, which represents an HTTP response code. Based on the value of `X`, we need to print one of two predefined strings:
- If `X` is equal to `404`, we should print "NOT FOUND".
- For any other value of `X` (i.e., `X` is not `404`), we should print "FOUND".

Each output string must be followed by a newline character.

## Intuition & Mathematical Observation

This problem is a very basic introduction to conditional statements. There are no complex algorithms, data structures, or mathematical observations required. The core idea is to perform a direct comparison:

1. Read the given integer `X`.
2. Check if `X` is exactly equal to `404`.
3. If the condition `X == 404` is true, execute the code block for "NOT FOUND".
4. Otherwise (if `X` is anything other than `404`), execute the code block for "FOUND".

This directly translates to an `if-else` construct in most programming languages.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The program performs a fixed number of operations regardless of the input value:
    1. Reading an integer.
    2. Performing a single comparison (`X == 404`).
    3. Printing a constant string.
    All these operations take constant time. Therefore, the overall time complexity is $O(1)$.

-   **Space Complexity**: $O(1)$
    The program uses a constant amount of memory to store the input integer `X`. No additional data structures whose size depends on the input are used. Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common standard library headers

using namespace std; // Uses the standard namespace to avoid prefixing std::

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can speed up I/O operations.
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    // This further optimizes I/O, especially when mixing cin and cout.
    cin.tie(NULL);

    // Declare an integer variable X to store the response code.
    int X;

    // Read the response code from standard input.
    cin >> X;

    // Check if the response code is 404.
    if (X == 404) {
        // If X is 404, print "NOT FOUND" followed by a newline.
        cout << "NOT FOUND\n";
    } else {
        // For any other response code, print "FOUND" followed by a newline.
        cout << "FOUND\n";
    }

    // Return 0 to indicate successful execution of the program.
    return 0;
}
```