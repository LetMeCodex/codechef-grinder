# [The Cooler Dilemma 2 (WATERCOOLER2)](https://www.codechef.com/problems/WATERCOOLER2)
- **Difficulty Rating**: 798
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef is faced with a dilemma regarding a water cooler. He has two options:
1.  Rent the cooler for `X` rupees per month.
2.  Buy the cooler outright for `Y` rupees.

Chef wants to rent the cooler for as many months as possible, but with a crucial condition: the total rental cost must be *strictly less than* the purchase cost. We need to find the maximum number of months Chef can rent the cooler while satisfying this condition.

## Intuition & Mathematical Observation

Let `M` be the number of months Chef rents the cooler.
The total rental cost for `M` months would be `M * X`.
The problem states that this total rental cost must be strictly less than the purchase cost `Y`.
So, we need to find the maximum integer `M` such that:
`M * X < Y`

Since `X` is given to be a positive integer (from constraints, `1 <= X`), we can divide both sides of the inequality by `X` without changing the direction of the inequality:
`M < Y / X`

Since `M` must be an integer, the largest integer `M` that is strictly less than `Y / X` can be found by considering `Y - 1`. If `M * X` must be strictly less than `Y`, then `M * X` can be at most `Y - 1`.
So, we are looking for the maximum integer `M` such that:
`M * X <= Y - 1`

Again, dividing by `X` (which is positive):
`M <= (Y - 1) / X`

Since `M` must be an integer, the maximum possible value for `M` is the floor of `(Y - 1) / X`.
In C++ (and many other programming languages), integer division `A / B` automatically computes `floor(A / B)` when `A` and `B` are positive integers.
Given the constraints `1 <= X, Y <= 10^9`, `X` is always positive. `Y - 1` will be non-negative (`Y=1` implies `Y-1=0`). So, `(Y - 1) / X` using integer division will correctly give us the maximum integer `M`.

**Example:**
-   If `X = 3`, `Y = 10`:
    `M * 3 < 10`
    `M < 10 / 3 = 3.33...`
    The maximum integer `M` is `3`.
    Using the formula: `(10 - 1) / 3 = 9 / 3 = 3`. This matches.

-   If `X = 5`, `Y = 5`:
    `M * 5 < 5`
    `M < 5 / 5 = 1`
    The maximum integer `M` is `0`.
    Using the formula: `(5 - 1) / 5 = 4 / 5 = 0` (integer division). This matches.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    The solution processes `T` test cases. For each test case, it performs a constant number of operations: reading two integers, one subtraction, one division, and printing an integer. Each of these operations takes constant time. Therefore, the total time complexity is directly proportional to the number of test cases, `T`.

-   **Space Complexity**: $O(1)$
    The solution uses a fixed number of integer variables (`T`, `X`, `Y`, `result`) to store input and intermediate calculations. The memory usage does not grow with the input values or the number of test cases (beyond the fixed size of these variables). Hence, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common libraries like iostream

using namespace std; // Use the standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases.
    cin >> T; // Read the number of test cases.

    // Loop through each test case.
    while (T--) {
        int X, Y; // Declare integer variables X and Y for rental cost and purchase cost.
        cin >> X >> Y; // Read X and Y for the current test case.

        // Calculate the maximum number of months.
        // We need M * X < Y, which is equivalent to M * X <= Y - 1.
        // Dividing by X (which is >= 1), we get M <= (Y - 1) / X.
        // Since M must be an integer, the maximum M is floor((Y - 1) / X).
        // In C++, integer division `(Y - 1) / X` automatically computes the floor
        // for positive operands.
        int result = (Y - 1) / X;

        // Output the result for the current test case, followed by a newline.
        cout << result << "\n";
    }

    return 0; // Indicate successful execution.
}
```