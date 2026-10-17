# [Subscription Cost (SUBCOST7)](https://www.codechef.com/problems/SUBCOST7)
- **Difficulty Rating**: 459
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the total subscription cost for a given number of months, `N`. The pricing structure is as follows:
*   The first 3 months of the subscription each cost `X` rupees.
*   Any months beyond the initial 3 months each cost `Y` rupees.

We need to calculate and output the total cost for `N` months for several test cases.

## Intuition & Mathematical Observation

The core idea is to divide the total `N` months into two distinct groups based on their pricing:
1.  Months that fall within the "first 3 months" category, which are charged at `X` rupees per month.
2.  Months that fall into the "beyond first 3 months" category, which are charged at `Y` rupees per month.

Let's determine the number of months in each category:

*   **Months at `X` rate**: The number of months that will be charged `X` rupees each is limited to a maximum of 3. If `N` is less than or equal to 3, all `N` months will be charged `X`. If `N` is greater than 3, only the first 3 months will be charged `X`. This can be concisely expressed as `min(N, 3)`.
    *   Let `months_at_X_rate = min(N, 3)`.
    *   The cost for these months will be `months_at_X_rate * X`.

*   **Months at `Y` rate**: After accounting for the `months_at_X_rate`, the remaining months will be charged `Y` rupees each.
    *   The number of remaining months is `N - months_at_X_rate`.
    *   Let `months_at_Y_rate = N - months_at_X_rate`.
    *   The cost for these months will be `months_at_Y_rate * Y`.

*   **Total Cost**: The total subscription cost is the sum of the costs from both categories.
    *   `total_cost = (months_at_X_rate * X) + (months_at_Y_rate * Y)`.

The solution implements this direct calculation. Using `long long` for `total_cost` is a good practice to prevent potential integer overflow, although for the given constraints (`N, X, Y <= 1000`), `int` would typically suffice as the maximum cost would be around `3*1000 + (1000-3)*1000` which is approximately `1000 * 1000 = 1,000,000`, well within `int` limits.

## Complexity Analysis

*   **Time Complexity**: $O(1)$ per test case.
    The `solve()` function performs a fixed number of arithmetic operations (min, subtraction, multiplication, addition) and input/output operations. These operations take constant time, irrespective of the input values `N`, `X`, or `Y`. Since there are `T` test cases, the total time complexity is $O(T)$.

*   **Space Complexity**: $O(1)$ per test case.
    The solution uses a constant number of variables (`N`, `X`, `Y`, `months_at_X_rate`, `months_at_Y_rate`, `total_cost`, `T`) to store input and intermediate results. The memory usage does not grow with the input size.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common libraries like iostream, algorithm, etc.

using namespace std; // Allows direct use of standard library elements like cin, cout, min

void solve() {
    int N, X, Y;
    // Read the number of months (N), cost for first 3 months (X), and cost for following months (Y)
    cin >> N >> X >> Y;

    long long total_cost = 0; // Use long long to prevent potential overflow, though int would suffice for given constraints.

    // Calculate the number of months that fall under the 'X' rate (first 3 months)
    int months_at_X_rate = min(N, 3);
    // Add the cost for these months to the total
    total_cost += (long long)months_at_X_rate * X;

    // Calculate the number of remaining months that fall under the 'Y' rate
    int months_at_Y_rate = N - months_at_X_rate;
    // Add the cost for these months to the total
    total_cost += (long long)months_at_Y_rate * Y;

    // Output the calculated total cost followed by a newline
    cout << total_cost << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
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