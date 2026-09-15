# [Sum OR Difference (DIFFSUM)](https://www.codechef.com/problems/DIFFSUM)
- **Difficulty Rating**: 749
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to read two integer numbers, let's call them `N1` and `N2`. Based on their comparison, we need to perform one of two operations and print the result:
1. If `N1` is strictly greater than `N2` (`N1 > N2`), we should print their difference (`N1 - N2`).
2. Otherwise (if `N1` is less than or equal to `N2`, i.e., `N1 <= N2`), we should print their sum (`N1 + N2`).

## Intuition & Mathematical Observation

The problem statement directly provides the conditional logic required. There isn't a complex mathematical observation or a hidden trick; it's a straightforward implementation of an `if-else` statement.

The core idea is:
1. Read the two input numbers.
2. Use an `if` condition to check if the first number (`N1`) is greater than the second number (`N2`).
3. If the condition is true, calculate `N1 - N2` and print it.
4. If the condition is false (meaning `N1` is less than or equal to `N2`), calculate `N1 + N2` and print it.

This problem tests basic conditional logic and input/output operations.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The program performs a fixed number of operations regardless of the magnitude of the input numbers (within standard integer limits). These operations include reading two integers, a single comparison, a single arithmetic operation (addition or subtraction), and printing the result. All these steps take constant time.

-   **Space Complexity**: $O(1)$
    The program uses a constant amount of memory to store the two input integers (`n1`, `n2`) and any temporary variables required for calculations. No data structures that grow with input size are used.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common headers like iostream

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare two variables of type long long to store the input numbers.
    // long long is chosen to handle potentially large integer inputs,
    // though for this problem's constraints, int might also suffice.
    long long n1, n2;

    // Read the two numbers from standard input.
    cin >> n1 >> n2;

    // Implement the conditional logic as per the problem statement.
    if (n1 > n2) {
        // If n1 is greater than n2, print their difference.
        cout << n1 - n2 << "\n";
    } else {
        // Otherwise (if n1 is less than or equal to n2), print their sum.
        cout << n1 + n2 << "\n";
    }

    // Indicate successful program execution.
    return 0;
}
```