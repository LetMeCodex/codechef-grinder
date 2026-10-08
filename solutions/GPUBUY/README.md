# [Buying GPU (GPUBUY)](https://www.codechef.com/problems/GPUBUY)
- **Difficulty Rating**: 728
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef wants to buy a new GPU. The GPU has an initial price of `X` coins. Each month, the price of the GPU increases by `Y` coins. Chef earns `Z` coins each month. Chef decides to buy the GPU at the end of `m` months. The condition for Chef to be able to buy the GPU is that his total accumulated earnings after `m` months must be greater than or equal to the GPU's price at the end of `m` months. We need to find the minimum number of months (`m`) required for Chef to buy the GPU. If it's impossible to buy the GPU, output -1.

## Intuition & Mathematical Observation

Let `m` be the number of months after which Chef attempts to buy the GPU.

1.  **GPU Price after `m` months**:
    *   Initial price: `X`
    *   Price increase per month: `Y`
    *   Total price increase over `m` months: `m * Y`
    *   GPU price at the end of `m` months: `X + m * Y`

2.  **Chef's Total Earnings after `m` months**:
    *   Earnings per month: `Z`
    *   Total earnings over `m` months: `m * Z`

3.  **Condition for buying the GPU**:
    Chef's total earnings must be at least the GPU's price.
    `m * Z >= X + m * Y`

4.  **Rearranging the inequality**:
    To find `m`, let's group terms involving `m`:
    `m * Z - m * Y >= X`
    `m * (Z - Y) >= X`

Now, we need to analyze this inequality based on the value of `(Z - Y)`:

*   **Case 1: `Z > Y` (Chef earns more than the price increases)**
    In this scenario, `(Z - Y)` is a positive value. We can divide both sides of the inequality by `(Z - Y)` without reversing the inequality sign:
    `m >= X / (Z - Y)`
    Since `m` must be an integer and we are looking for the *minimum* `m`, we need to find the smallest integer `m` that satisfies this condition. This is equivalent to `ceil(X / (Z - Y))`.
    For positive integers `A` and `B`, `ceil(A/B)` can be calculated using integer division as `(A + B - 1) / B`.
    So, `m = (X + (Z - Y) - 1) / (Z - Y)`.

*   **Case 2: `Z <= Y` (Chef earns less than or equal to the price increases)**
    *   **Subcase 2a: `Z = Y`**
        The inequality becomes `m * (Y - Y) >= X`, which simplifies to `m * 0 >= X`, or `0 >= X`.
        Since the initial price `X` is always positive (as per problem constraints, `X >= 1`), `0 >= X` is never true. Thus, Chef can never buy the GPU.
    *   **Subcase 2b: `Z < Y`**
        In this case, `(Z - Y)` is a negative value. Let `D = Z - Y` (where `D < 0`).
        The inequality becomes `m * D >= X`.
        When we divide by a negative number (`D`), we must reverse the inequality sign:
        `m <= X / D`
        Since `X` is positive and `D` is negative, `X / D` will be a negative value.
        So, `m` must be less than or equal to a negative value. However, `m` represents the number of months and must be at least 1 (`m >= 1`). This is a contradiction. Chef can never buy the GPU.

    In both subcases where `Z <= Y`, it's impossible for Chef to buy the GPU. Therefore, we output -1.

This covers all possibilities and leads directly to the solution logic.

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    The `solve()` function performs a fixed number of arithmetic operations (addition, subtraction, division) and comparisons. These operations take constant time. The `main()` function calls `solve()` `T` times, so the total time complexity is $O(T)$. Since `T` is up to $10^5$, this is efficient enough.

*   **Space Complexity**: $O(1)$
    The solution uses a few integer variables (`X`, `Y`, `Z`, `diff`, `months`) to store input and intermediate results. The amount of memory used does not depend on the input values or the number of months, making the space complexity constant.

## Solution Code

```cpp
#include <iostream> // Required for standard input/output operations (cin, cout)

// It's common in competitive programming to include <bits/stdc++.h>
// and use 'using namespace std;', but for clarity and minimal includes,
// iostream is sufficient here.
using namespace std;

void solve() {
    int X, Y, Z;
    cin >> X >> Y >> Z; // Read initial price X, price increase Y, and earnings Z

    // The condition for Chef to buy the GPU in 'm' months is:
    // Chef's total coins after 'm' months >= GPU price after 'm' months
    // m * Z >= X + m * Y

    // Rearranging the inequality:
    // m * Z - m * Y >= X
    // m * (Z - Y) >= X

    // Case 1: Chef earns more than the price increases (Z > Y)
    // In this scenario, (Z - Y) is a positive value.
    // We can divide by (Z - Y) to find the minimum 'm':
    // m >= X / (Z - Y)
    // Since 'm' must be an integer, we need the smallest integer 'm' that satisfies this.
    // This is equivalent to ceil(X / (Z - Y)).
    // For positive integers A and B, ceil(A/B) can be calculated as (A + B - 1) / B using integer division.
    if (Z > Y) {
        int diff = Z - Y; // The net gain in buying power per month
        // Calculate ceil(X / diff)
        int months = (X + diff - 1) / diff;
        cout << months << "\n";
    }
    // Case 2: Chef earns less than or equal to the price increase (Z <= Y)
    // If Z = Y, the inequality becomes m * 0 >= X, or 0 >= X. Since X >= 1, this is never true.
    // If Z < Y, then (Z - Y) is negative. The inequality becomes m * (negative_value) >= X.
    // Dividing by a negative value reverses the inequality: m <= X / (negative_value).
    // Since X is positive and (Z - Y) is negative, X / (Z - Y) is a negative value.
    // So, m must be less than or equal to a negative value.
    // However, 'm' must be at least 1 (number of months). This is a contradiction.
    // In both subcases (Z = Y or Z < Y), Chef will never be able to buy the GPU.
    else { // Z <= Y
        cout << -1 << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and disables synchronization with C's stdio library,
    // leading to faster input/output operations.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times, decrementing T each iteration
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```