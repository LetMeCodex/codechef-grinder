# [Is it hot or cold (HOTCOLD)](https://www.codechef.com/problems/HOTCOLD)
- **Difficulty Rating**: 410
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine whether a given temperature `C` indicates a "HOT" or "COLD" climate. According to Chef's definition, the climate is considered "HOT" if the temperature `C` is strictly greater than 20 degrees. Otherwise (i.e., if `C` is 20 degrees or less), the climate is considered "COLD". We need to process `T` independent test cases, printing "HOT" or "COLD" for each given temperature.

## Intuition & Mathematical Observation

This problem is a direct application of a simple conditional statement. There are no complex mathematical observations or algorithms required. The core idea is to:
1. Read the number of test cases, `T`.
2. For each test case, read the temperature `C`.
3. Apply the given rule:
   - If `C > 20`, the climate is "HOT".
   - Otherwise (if `C <= 20`), the climate is "COLD".
4. Print the corresponding string ("HOT" or "COLD") followed by a newline.

The problem statement clearly defines the threshold and the comparison type (strictly greater than), making it a straightforward `if-else` decision.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    -   Reading the number of test cases `T` takes $O(1)$ time.
    -   The program then iterates `T` times, once for each test case.
    -   Inside each iteration:
        -   Reading the temperature `C` takes $O(1)$ time.
        -   The comparison `C > 20` takes $O(1)$ time.
        -   Printing "HOT" or "COLD" takes $O(1)$ time.
    -   Since each test case is processed in constant time, the total time complexity is directly proportional to the number of test cases, $T$.

-   **Space Complexity**: $O(1)$
    -   The program uses a few integer variables (`T`, `C`) to store input and loop counters. These variables occupy a constant amount of memory regardless of the input values or the number of test cases. No data structures that grow with input size are used.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

using namespace std; // Allows using standard library elements without std:: prefix

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // which can speed up programs that mix cin and cout.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    // The T-- decrements T after each iteration, stopping when T becomes 0.
    while (T--) {
        int C; // Declare an integer variable C for the temperature.
        cin >> C; // Read the temperature for the current test case.

        // According to the problem statement, Chef considers the climate HOT
        // if the temperature is *above* 20. This means strictly greater than 20.
        if (C > 20) {
            cout << "HOT\n"; // If C is greater than 20, print "HOT" followed by a newline.
        } else {
            // Otherwise (if C is 20 or less), Chef considers it COLD.
            cout << "COLD\n"; // Print "COLD" followed by a newline.
        }
    }

    return 0; // Indicate successful program execution.
}
```