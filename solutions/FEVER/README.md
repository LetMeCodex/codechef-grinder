# [Fever (FEVER)](https://www.codechef.com/problems/FEVER)
- **Difficulty Rating**: 348
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a person has a fever based on their body temperature. We are given an integer `X` representing the body temperature in Fahrenheit. According to the problem statement, a person has a fever if their body temperature is strictly greater than 98 °F. We need to output "YES" if the person has a fever, and "NO" otherwise. This process needs to be repeated for `T` test cases.

## Intuition & Mathematical Observation

This problem is a very basic conditional check. The core requirement is to compare the given temperature `X` with a fixed threshold, 98 °F.

The condition for fever is explicitly stated: "strictly greater than 98 °F". This translates directly to a simple `if` statement:
- If `X > 98`, then the person has a fever.
- Otherwise (if `X <= 98`), the person does not have a fever.

There are no complex algorithms, data structures, or mathematical observations required beyond this direct comparison. For each test case, we simply read the temperature and apply this single comparison.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    For each of the `T` test cases, the program performs a constant number of operations:
    1.  Reading an integer `X`.
    2.  Performing a single comparison (`X > 98`).
    3.  Printing a short string ("YES" or "NO").
    Each of these operations takes constant time. Therefore, the total time complexity is proportional to the number of test cases, `T`.

-   **Space Complexity**: $O(1)$
    The program uses a fixed amount of memory regardless of the input size or the number of test cases. It only stores a few integer variables (`T`, `X`) and does not use any dynamic data structures or arrays that scale with input. Hence, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Using the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can speed up I/O operations.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // further speeding up I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases
    cin >> T; // Read the number of test cases from standard input

    // Loop T times, once for each test case
    while (T--) {
        int X; // Declare an integer variable X for the body temperature in °F
        cin >> X; // Read the body temperature for the current test case

        // Determine if Chef has fever based on the problem's condition:
        // A person has fever if their body temperature is strictly greater than 98 °F.
        if (X > 98) {
            // If X is strictly greater than 98, Chef has fever.
            cout << "YES\n"; // Print "YES" followed by a newline
        } else {
            // Otherwise (if X is 98 or less), Chef does not have fever.
            cout << "NO\n"; // Print "NO" followed by a newline
        }
    }

    return 0; // Indicate successful execution of the program
}
```