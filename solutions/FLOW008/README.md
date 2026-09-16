# [Helping Chef (FLOW008)](https://www.codechef.com/problems/FLOW008)
- **Difficulty Rating**: 776
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine Chef's availability based on a given number `N`. We are provided with `T` test cases. For each test case, we need to read an integer `N`.
- If `N` is less than 10, Chef is free, and we should print "Thanks for helping Chef!".
- Otherwise (if `N` is 10 or greater), Chef is busy, and we should print "-1".
Each output should be followed by a newline character.

## Intuition & Mathematical Observation

This is a very basic conditional problem. The core logic revolves around a single comparison: checking if the input number `N` satisfies the condition `N < 10`.

- **Direct Application of Rule**: The problem statement directly provides the condition and the corresponding output. There's no hidden trick or complex mathematical concept involved. We simply need to implement an `if-else` statement based on the given inequality.
- **Input/Output Handling**: The standard competitive programming setup requires reading the number of test cases `T`, then looping `T` times, and inside the loop, reading `N` and printing the appropriate string followed by a newline.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    -   The program iterates `T` times, once for each test case.
    -   Inside each test case, it performs a constant number of operations: reading an integer `N`, a single comparison (`N < 10`), and printing a fixed-length string.
    -   Therefore, the total time complexity is directly proportional to the number of test cases, $O(T)$.

-   **Space Complexity**: $O(1)$
    -   The program uses a few integer variables (`t`, `n`) to store the number of test cases and the current input number. These variables occupy a constant amount of memory regardless of the input values or the number of test cases.
    -   No dynamic data structures or arrays are used that would scale with input size.
    -   Hence, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Include all standard libraries

using namespace std; // Use standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // `ios_base::sync_with_stdio(false)` unties C++ streams from C standard streams.
    // `cin.tie(NULL)` prevents `cout` from flushing before `cin` reads input.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Declare an integer variable 't' to store the number of test cases.
    cin >> t; // Read the number of test cases from standard input.

    // Loop 't' times, once for each test case.
    // The `while (t--)` idiom is common for iterating 't' times,
    // decrementing 't' in each iteration until it becomes 0.
    while (t--) {
        int n; // Declare an integer variable 'n' to store the input number for the current test case.
        cin >> n; // Read the integer 'n' from standard input.

        // Check the condition specified in the problem statement:
        // If 'n' is less than 10.
        if (n < 10) {
            // If the condition is true, print the specified message.
            // `"\n"` is used for a newline character, as required for each output.
            cout << "Thanks for helping Chef!\n";
        } else {
            // If the condition is false (i.e., 'n' is 10 or greater), print "-1".
            cout << "-1\n";
        }
    }

    return 0; // Indicate successful program execution.
}
```