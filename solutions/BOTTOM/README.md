# [Guess the bottom face (BOTTOM)](https://www.codechef.com/problems/BOTTOM)
- **Difficulty Rating**: 815
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine the number on the bottom face of a standard six-sided dice, given the number currently visible on its top face. We need to do this for multiple test cases.

## Intuition & Mathematical Observation
The key property of a standard six-sided dice is that the sum of the numbers on any pair of opposite faces is always 7. For example, if 1 is on top, 6 is on the bottom; if 2 is on top, 5 is on the bottom; and if 3 is on top, 4 is on the bottom.

Given the value `x` on the top face, let `y` be the value on the bottom face. According to the property of a standard dice:
`x + y = 7`

To find the value on the bottom face (`y`), we can simply rearrange the equation:
`y = 7 - x`

This direct formula allows us to calculate the bottom face value for any given top face value `x`.

## Complexity Analysis
- **Time Complexity**: $O(T)$
  - The program reads `T` test cases.
  - For each test case, it performs a constant number of operations: reading an integer, a simple subtraction, and printing an integer.
  - Therefore, the total time complexity is directly proportional to the number of test cases, $T$.

- **Space Complexity**: $O(1)$
  - The program uses a few integer variables (`t`, `x`, `bottom_face`) to store input and intermediate results.
  - The memory usage does not depend on the input values or the number of test cases; it remains constant regardless of the input size.

## Solution Code
```cpp
#include <bits/stdc++.h> // Include all standard libraries

using namespace std; // Use the standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Declare an integer variable 't' to store the number of test cases.
    cin >> t; // Read the number of test cases from standard input.

    // Loop 't' times, once for each test case.
    // The 't--' decrements 't' after each iteration until it becomes 0.
    while (t--) {
        int x; // Declare an integer variable 'x' to store the value on the top face.
        cin >> x; // Read the value on the top face for the current test case.

        // According to the problem statement, in a regular dice,
        // the sum of opposite faces is 7.
        // If 'x' is the value on the top face, and 'bottom_face' is the value
        // on the bottom face, then x + bottom_face = 7.
        // Therefore, bottom_face = 7 - x.
        int bottom_face = 7 - x;

        // Print the calculated value of the bottom face, followed by a newline character.
        // Using "\n" is generally faster than endl because endl also flushes the buffer.
        cout << bottom_face << "\n";
    }

    return 0; // Indicate that the program executed successfully.
}
```