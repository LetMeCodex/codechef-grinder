# [Election Hopes (ELHP)](https://www.codechef.com/problems/ELHP)
- **Difficulty Rating**: 245
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if Chef wins an election based on the votes he and his rival, Chefu, received. Chef received $X$ votes and Chefu received $Y$ votes. Chef wins the election if he received **at least double** the number of votes Chefu received. We need to output "Yes" if Chef wins, and "No" otherwise.

## Intuition & Mathematical Observation

The core of this problem lies in understanding the condition "at least double".
Let Chef's votes be $X$ and Chefu's votes be $Y$.

1.  **"Double the number of votes Chefu received"**: This can be mathematically expressed as $2 \times Y$.
2.  **"At least double"**: This means Chef's votes ($X$) must be greater than or equal to ($ \ge $) double Chefu's votes ($2 \times Y$).

Combining these, the condition for Chef to win is $X \ge 2 \times Y$.

Our approach will be straightforward:
1. Read the two integer inputs, $X$ and $Y$.
2. Evaluate the condition $X \ge 2 \times Y$.
3. If the condition is true, print "Yes".
4. Otherwise (if the condition is false), print "No".

This is a simple conditional check, requiring no complex algorithms or data structures.

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    The program performs a fixed number of operations regardless of the input values $X$ and $Y$ (within their given constraints). It involves reading two integers, one multiplication, one comparison, and printing a string. All these operations take constant time.

*   **Space Complexity**: $O(1)$
    The program uses a constant amount of memory to store a few integer variables ($X$ and $Y$). No data structures that grow with the input size are used.

## Solution Code

```cpp
#include <bits/stdc++.h> // Include all standard libraries

// Use the standard namespace
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin/cout from the C standard streams and prevents flushing
    // of cout before cin operations, which can speed up I/O significantly.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare two integer variables to store the votes received by Chef (X)
    // and his rival Chefu (Y).
    // The constraints (1 <= X, Y <= 100) ensure that 'int' is sufficient
    // to store these values and any intermediate calculations (like 2*Y, which
    // would be at most 200).
    int X, Y;

    // Read the two space-separated integers from the standard input.
    cin >> X >> Y;

    // Chef dominates the election if he received "at least double" the number
    // of votes Chefu received. This condition can be expressed as X >= 2 * Y.
    if (X >= 2 * Y) {
        // If the condition is true, Chef dominated the election.
        // Print "Yes" followed by a newline character.
        cout << "Yes\n";
    } else {
        // If the condition is false, Chef did not dominate the election.
        // Print "No" followed by a newline character.
        cout << "No\n";
    }

    // Return 0 to indicate successful execution of the program.
    return 0;
}
```