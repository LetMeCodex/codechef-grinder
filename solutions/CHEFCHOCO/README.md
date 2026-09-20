# [Chef and Chocolates (CHEFCHOCO)](https://www.codechef.com/problems/CHEFCHOCO)
- **Difficulty Rating**: 492
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the minimum amount of money Chef needs to spend to acquire a total of `C` chocolates. Chef already possesses `X` chocolates, and each additional chocolate costs `Y` rupees. We need to output this minimum cost for several test cases.

## Intuition & Mathematical Observation

The core of this problem is a straightforward arithmetic calculation.

1.  **Determine the deficit**: Chef needs a total of `C` chocolates but already has `X` chocolates. The number of additional chocolates Chef needs to buy is simply the difference between the target amount and the current amount: `C - X`.
2.  **Calculate the total cost**: Each of these additional chocolates costs `Y` rupees. To find the total money Chef needs to spend, we multiply the number of chocolates to buy by the cost per chocolate: `(C - X) * Y`.

Since the problem is rated very low (492), it's expected to be a direct application of basic arithmetic without any complex logic, edge cases (like `C < X`, which would imply Chef needs to sell chocolates, but the problem implies buying), or large numbers that would overflow standard integer types.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    *   The program iterates `T` times, once for each test case.
    *   Inside each test case, it performs a fixed number of operations: reading three integers, one subtraction, one multiplication, and printing one integer. All these operations take constant time, $O(1)$.
    *   Therefore, the total time complexity is directly proportional to the number of test cases, $T$.

-   **Space Complexity**: $O(1)$
    *   The program uses a few integer variables (`T`, `C`, `X`, `Y`, `chocolates_to_buy`, `total_cost`) to store input and intermediate results.
    *   The amount of memory used by these variables is constant and does not depend on the magnitude of the input values or the number of test cases (beyond storing `T` itself).
    *   Hence, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries

// Using the standard namespace to avoid prefixing std::
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from the C standard I/O library and
    // prevents cin from flushing cout before each input operation,
    // leading to faster input/output.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases
    cin >> T; // Read the number of test cases

    // Loop T times, once for each test case
    while (T--) {
        int C, X, Y; // Declare integer variables for C, X, and Y
        cin >> C >> X >> Y; // Read C, X, and Y for the current test case

        // Calculate the number of chocolates Chef needs to buy.
        // Chef needs C chocolates in total, and already has X.
        // So, Chef needs to buy C - X more chocolates.
        int chocolates_to_buy = C - X;

        // Calculate the total cost.
        // Each chocolate costs Y rupees.
        // So, the total cost is (chocolates_to_buy * Y).
        int total_cost = chocolates_to_buy * Y;

        // Output the minimum money Chef needs to spend, followed by a newline.
        cout << total_cost << "\n";
    }

    return 0; // Indicate successful program execution
}
```