# [Adding Dice (ADDDICE)](https://www.codechef.com/problems/ADDDICE)
- **Difficulty Rating**: -1
- **Solved in**: 2 attempt(s)

## Problem Summary

The problem asks us to determine if it's possible for the sum of two standard dice rolls to be exactly 9, given the result of the first die roll, $X$. A standard die has faces numbered from 1 to 6. We need to output "Yes" if such a second die roll is possible, and "No" otherwise. The input $X$ is guaranteed to be between 1 and 6, inclusive.

## Intuition & Mathematical Observation

Let the first die roll be $X$ and the second die roll be $Y$.
We are given $X$, and we want to find if there exists a valid $Y$ such that their sum is 9.

1.  **Target Sum**: The desired sum is 9. So, $X + Y = 9$.
2.  **Required Second Roll**: From the equation, the value required for the second die roll is $Y = 9 - X$.
3.  **Validity of Second Roll**: For $Y$ to be a valid roll on a standard die, it must satisfy the condition $1 \le Y \le 6$.
4.  **Substituting Y**: We substitute $Y = 9 - X$ into the validity condition:
    $1 \le 9 - X \le 6$

    This inequality can be split into two parts:
    *   $1 \le 9 - X$
        *   $X \le 9 - 1$
        *   $X \le 8$
    *   $9 - X \le 6$
        *   $9 - 6 \le X$
        *   $3 \le X$

    Combining these, for $Y$ to be a valid die roll, $X$ must satisfy $3 \le X \le 8$.

5.  **Considering Problem Constraints**: The problem statement specifies that $X$ will always be between 1 and 6, i.e., $1 \le X \le 6$.

6.  **Intersection of Conditions**: We need to find the values of $X$ that satisfy *both* the derived condition ($3 \le X \le 8$) and the problem constraint ($1 \le X \le 6$).
    The intersection of the range $[3, 8]$ and $[1, 6]$ is $[3, 6]$.

    This means if $X$ is 3, 4, 5, or 6, it is possible to find a valid $Y$ (which would be $6, 5, 4, 3$ respectively).
    If $X$ is 1 or 2 (which are within the problem constraints but outside the $[3, 6]$ range), it is not possible:
    *   If $X=1$, $Y=9-1=8$, which is not a valid die roll.
    *   If $X=2$, $Y=9-2=7$, which is not a valid die roll.

7.  **Simplified Condition**: The condition $3 \le X \le 6$ (given $X$ is already $1 \le X \le 6$) simplifies to just checking if $X \ge 3$.

Therefore, if $X \ge 3$, the answer is "Yes"; otherwise, the answer is "No".

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    The solution involves reading a single integer, performing a constant number of arithmetic operations (subtraction, comparison), and printing a string. All these operations take constant time, regardless of the input value $X$.

*   **Space Complexity**: $O(1)$
    The solution uses a fixed number of variables (e.g., `X`) to store input and intermediate results. The memory usage does not depend on the magnitude of the input $X$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries
using namespace std;     // Uses the standard namespace

// Function to solve a single test case
void solve() {
    int X; // Declare an integer variable X to store the first dice roll
    cin >> X; // Read the value of X from standard input

    // The sum of both dice must be 9.
    // If the first die shows X, the second die must show Y = 9 - X.
    // A standard die has faces numbered from 1 to 6.
    // So, Y must be between 1 and 6 (inclusive).
    //
    // Condition 1: Y >= 1  =>  9 - X >= 1  =>  8 >= X  =>  X <= 8
    // Condition 2: Y <= 6  =>  9 - X <= 6  =>  3 <= X
    //
    // Combining these, for Y to be a valid die roll, X must satisfy 3 <= X <= 8.
    // The problem constraints state that 1 <= X <= 6.
    //
    // The intersection of the range [1, 6] (from problem constraints)
    // and [3, 8] (from our derived conditions) is [3, 6].
    //
    // Therefore, if X is 3, 4, 5, or 6, it is possible. Otherwise (if X is 1 or 2), it is not.
    // This condition simplifies to checking if X is greater than or equal to 3.

    if (X >= 3) {
        cout << "Yes\n"; // If X is 3 or more, it's possible for the second die to make the sum 9.
    } else {
        cout << "No\n"; // If X is 1 or 2, the required second die roll (8 or 7) is not possible.
    }
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from C's stdio and prevents flushing cout before cin.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem statement "The first and only line of each test case contains a single integer X."
    // implies there is only ONE test case, and X is on that line.
    // It does NOT imply reading 't' first for multiple test cases.
    // The previous attempt incorrectly assumed multiple test cases by reading 't'.
    // Removing the 't' variable and the loop.
    solve(); // Call the solve function for the single test case

    return 0; // Indicate successful execution
}
```