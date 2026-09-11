# [Bull or Bear (BULLBEAR)](https://www.codechef.com/problems/BULLBEAR)

- **Difficulty Rating**: 300
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine the outcome of a stock trade given a buying price $X$ and a selling price $Y$. We need to output:
- `"PROFIT"` if $Y > X$
- `"LOSS"` if $Y < X$
- `"NEUTRAL"` if $Y = X$

## Intuition & Mathematical Observation
This is a straightforward conditional logic problem. By comparing the two integers $X$ and $Y$, we can categorize the financial outcome:
1. If the selling price is strictly greater than the buying price, the difference is positive (Profit).
2. If the selling price is strictly less than the buying price, the difference is negative (Loss).
3. If the prices are identical, the net change is zero (Neutral).

We can implement this using a simple `if-else if-else` control structure.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of comparisons, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input values regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries

// Use the standard namespace to avoid prefixing std::
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // potentially speeding up I/O operations.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // which can further speed up I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int X, Y; // Declare two integer variables X and Y for buying and selling prices.
        cin >> X >> Y; // Read X and Y for the current test case.

        // Compare X and Y to determine profit, loss, or neutral deal.
        if (Y > X) {
            // If selling price (Y) is greater than buying price (X), it's a profit.
            cout << "PROFIT\n";
        } else if (Y < X) {
            // If selling price (Y) is less than buying price (X), it's a loss.
            cout << "LOSS\n";
        } else {
            // If selling price (Y) is equal to buying price (X), it's a neutral deal.
            cout << "NEUTRAL\n";
        }
    }

    return 0; // Indicate successful execution of the program.
}
```