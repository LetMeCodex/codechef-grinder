# [Average of Three (AVGOF3)](https://www.codechef.com/problems/AVGOF3)
- **Difficulty Rating**: 1141
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find three distinct integers, $A_1, A_2, A_3$, such that their arithmetic mean (average) is equal to a given integer $X$.
Additionally, these three integers must satisfy the following constraints:
1. $1 \le A_1, A_2, A_3 \le 1000$
2. $A_1, A_2, A_3$ must be distinct.

The input $X$ is guaranteed to be between $2$ and $100$ ($2 \le X \le 100$). There are $T$ test cases.

## Intuition & Mathematical Observation

The core condition is that the average of $A_1, A_2, A_3$ must be $X$. Mathematically, this means:
$$ \frac{A_1 + A_2 + A_3}{3} = X $$
Multiplying both sides by 3, we get:
$$ A_1 + A_2 + A_3 = 3X $$
We need to find three *distinct* integers that sum up to $3X$ and fall within the range $[1, 1000]$.

A common strategy when dealing with averages or sums of numbers is to pick values symmetrically around the target average. The simplest set of three distinct integers centered around $X$ would be:
$A_1 = X - 1$
$A_2 = X$
$A_3 = X + 1$

Let's verify if this choice satisfies all the problem conditions:

1.  **Sum and Average**:
    $(X - 1) + X + (X + 1) = 3X$.
    The average is $(3X) / 3 = X$. This condition is perfectly met.

2.  **Distinctness**:
    Since $X-1$, $X$, and $X+1$ are consecutive integers, they are inherently distinct. This condition is also met.

3.  **Range ($1 \le A_i \le 1000$)**:
    The problem states that $X$ is between $2$ and $100$ ($2 \le X \le 100$).
    *   **Smallest possible $X$**: If $X = 2$, the chosen integers would be $A_1 = 2-1=1$, $A_2 = 2$, $A_3 = 2+1=3$. All these values ($1, 2, 3$) are within the required range $[1, 1000]$.
    *   **Largest possible $X$**: If $X = 100$, the chosen integers would be $A_1 = 100-1=99$, $A_2 = 100$, $A_3 = 100+1=101$. All these values ($99, 100, 101$) are also well within the required range $[1, 1000]$.
    Since $X$ is always between $2$ and $100$, the values $X-1$, $X$, and $X+1$ will always fall within the range $[1, 101]$, which is a subset of $[1, 1000]$. This condition is also met.

Since all conditions are satisfied by choosing $A_1 = X-1$, $A_2 = X$, and $A_3 = X+1$, this is a valid and straightforward solution.

## Complexity Analysis

*   **Time Complexity**: For each test case, we read one integer $X$ and perform a constant number of arithmetic operations (subtraction, addition) and print three integers. This takes $O(1)$ time per test case. Since there are $T$ test cases, the total time complexity is $O(T)$.

*   **Space Complexity**: We only need to store a few integer variables ($X$, $T$, and loop counters). This requires a constant amount of memory, regardless of the input values or the number of test cases. Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries, as requested.

// Using the standard namespace for convenience, as requested.
using namespace std;

// Function to solve a single test case.
void solve() {
    int X; // Chef's favourite number.
    cin >> X; // Read X from input.

    // We need to find three distinct integers A1, A2, A3 such that:
    // 1. (A1 + A2 + A3) / 3 = X  =>  A1 + A2 + A3 = 3 * X
    // 2. 1 <= A1, A2, A3 <= 1000
    // 3. A1, A2, A3 are distinct.

    // A simple and effective strategy is to pick numbers symmetrically
    // around the target average X.
    // Let's choose A1 = X - 1, A2 = X, A3 = X + 1.

    // Verification of conditions:
    // 1. Sum: (X - 1) + X + (X + 1) = 3X. The mean is (3X) / 3 = X. (Satisfied)
    // 2. Distinctness: X - 1, X, and X + 1 are consecutive integers,
    //    thus they are always distinct. (Satisfied)
    // 3. Range (1 <= A_i <= 1000):
    //    The problem constraints state 2 <= X <= 100.
    //    - Smallest possible X is 2:
    //      A1 = 2 - 1 = 1
    //      A2 = 2
    //      A3 = 2 + 1 = 3
    //      All values (1, 2, 3) are within [1, 1000].
    //    - Largest possible X is 100:
    //      A1 = 100 - 1 = 99
    //      A2 = 100
    //      A3 = 100 + 1 = 101
    //      All values (99, 100, 101) are within [1, 1000].
    //    Since X is always between 2 and 100, the generated A_i values
    //    will always be between 1 and 101, which perfectly fits the [1, 1000] range. (Satisfied)

    // Since all conditions are met, this construction is valid.
    // Output the three integers separated by spaces, followed by a newline.
    cout << X - 1 << " " << X << " " << X + 1 << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases.
    cin >> T; // Read the number of test cases.

    // Loop through each test case.
    while (T--) {
        solve(); // Call the solve function for each test case.
    }

    return 0; // Indicate successful execution.
}
```