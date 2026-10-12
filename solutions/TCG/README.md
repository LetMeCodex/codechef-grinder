# [Capital Gain Tax (TCG)](https://www.codechef.com/problems/TCG)
- **Difficulty Rating**: 311
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine the change in capital gain tax based on two given integer values. We are provided with `X`, representing the previous capital gain tax percentage, and `Y`, representing the new capital gain tax percentage. Our task is to output one of three strings: "INCREASED" if `Y` is strictly greater than `X`, "DECREASED" if `Y` is strictly less than `X`, and "SAME" if `Y` is equal to `X`.

## Intuition & Mathematical Observation
This problem is a direct application of basic comparison logic. We simply need to compare the two given integers, `X` and `Y`, and print the corresponding string based on their relationship.

There are three mutually exclusive scenarios:
1.  **`Y > X`**: The new tax percentage (`Y`) is higher than the previous one (`X`), indicating an "INCREASED" tax.
2.  **`Y < X`**: The new tax percentage (`Y`) is lower than the previous one (`X`), indicating a "DECREASED" tax.
3.  **`Y == X`**: The new tax percentage (`Y`) is the same as the previous one (`X`), indicating "SAME" tax.

The constraints on `X` and `Y` (10 <= X, Y <= 30) are very small, so standard integer types are perfectly adequate, and there's no risk of overflow or underflow. No complex mathematical operations or data structures are required. An `if-else if-else` construct is ideal for handling these three conditions.

## Complexity Analysis
-   **Time Complexity**: $O(1)$
    The program performs a fixed number of operations regardless of the input values: reading two integers, a single comparison (or a sequence of comparisons in an `if-else if-else` chain), and printing a string. These operations take constant time.
-   **Space Complexity**: $O(1)$
    The program uses a constant amount of memory to store the two input integers (`X` and `Y`) and for standard I/O buffers. The memory usage does not scale with any input parameter.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes all standard libraries

using namespace std; // Allows using standard library elements without std:: prefix

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from C's stdio and prevents flushing cout before cin.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem statement's "Input Format" section specifies:
    // "The first and only line of input consists of two space-separated integers X and Y"
    // This indicates that there is a single test case, not multiple test cases
    // introduced by a 't' variable.

    int X, Y; // Declare two integer variables for the previous and new tax values
    cin >> X >> Y; // Read the two integers from standard input

    // Compare X and Y to determine the change in capital gain tax.
    // The constraints 10 <= X, Y <= 30 mean that 'int' is sufficient
    // to store these values without any risk of overflow.

    if (Y > X) {
        // If the new tax value (Y) is strictly greater than the previous tax value (X),
        // the capital gain tax has increased.
        cout << "INCREASED\n";
    } else if (Y < X) {
        // If the new tax value (Y) is strictly less than the previous tax value (X),
        // the capital gain tax has decreased.
        cout << "DECREASED\n";
    } else {
        // If the new tax value (Y) is equal to the previous tax value (X),
        // the capital gain tax has remained the same.
        cout << "SAME\n";
    }

    return 0; // Indicate successful execution of the program
}
```