# [Profit Increment (PROINC)](https://www.codechef.com/problems/PROINC)
- **Difficulty Rating**: 414
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the new profit of an item after its selling price increases by 10%. We are given the initial selling price `X` and the initial profit `Y`. The buying price of the item remains constant. We are also told that `X` is always a multiple of 100.

## Intuition & Mathematical Observation

Let's break down the problem into its components:

1.  **Initial State**:
    *   Initial Selling Price (SP_initial) = `X`
    *   Initial Profit (P_initial) = `Y`
    *   The relationship between selling price, buying price, and profit is: `Profit = Selling Price - Buying Price`.
    *   From this, we can deduce the Buying Price (BP): `BP = SP_initial - P_initial = X - Y`.
    *   Crucially, the problem states that the buying price remains constant.

2.  **New State**:
    *   The selling price increases by 10%.
    *   New Selling Price (SP_new) = `SP_initial + 10% of SP_initial`.
    *   Since `X` is a multiple of 100, `10% of X` can be calculated simply as `X / 10`.
    *   So, `SP_new = X + (X / 10)`.

3.  **Calculating New Profit**:
    *   New Profit (P_new) = `SP_new - BP`.
    *   Substitute the expressions we found:
        `P_new = (X + X / 10) - (X - Y)`
    *   Now, simplify the expression:
        `P_new = X + X / 10 - X + Y`
        `P_new = (X - X) + X / 10 + Y`
        `P_new = X / 10 + Y`

This simplified formula `X / 10 + Y` directly gives us the new profit. We just need to perform one division and one addition.

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    The `solve()` function performs a fixed number of arithmetic operations (division, addition) and input/output operations, which take constant time. Since the `solve()` function is called `T` times, the total time complexity is $O(T \cdot 1) = O(T)$.

*   **Space Complexity**: $O(1)$
    The solution uses a few integer variables (`X`, `Y`, `new_profit`, `T`) to store input and intermediate results. The memory usage for these variables is constant and does not depend on the magnitude of the input values (within typical integer limits).

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common standard libraries like iostream

using namespace std; // Allows using cin, cout, etc. without std:: prefix

void solve() {
    int X, Y;
    // Read the initial selling price X and initial profit Y
    cin >> X >> Y;
    
    // Calculate the new profit.
    // The buying price remains constant: BP = X - Y.
    // The new selling price is X + 10% of X.
    // Since X is a multiple of 100, 10% of X is simply X / 10.
    // New selling price = X + (X / 10).
    // New profit = (New selling price) - (Buying price)
    // New profit = (X + X / 10) - (X - Y)
    // Simplifying the expression:
    // New profit = X + X / 10 - X + Y
    // New profit = X / 10 + Y
    
    int new_profit = (X / 10) + Y;
    
    // Output the calculated new profit, followed by a newline
    cout << new_profit << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    // Read the number of test cases
    cin >> T;
    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for each test case
    }
    
    return 0; // Indicate successful execution
}
```