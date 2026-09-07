# Saving Taxes (TAXSAVING)
- **Difficulty Rating**: 252
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to calculate the minimum amount of money a person needs to invest to avoid paying taxes. We are given two values: `X`, the total amount earned, and `Y`, the tax threshold. Taxes are levied if the earned amount is strictly greater than `Y`.

## Intuition & Mathematical Observation
The core of the problem lies in understanding the condition for paying taxes and how to circumvent it with minimal investment.

We are given that the current earned amount is `X`.
The tax threshold is `Y`.
Taxes are paid if `X > Y`.

We want to find the minimum investment, let's call it `I`, such that after investing this amount, the remaining income is no longer strictly greater than `Y`. The remaining income after investment will be `X - I`.

So, we need to find the minimum `I` that satisfies the condition:
`X - I <= Y`

To find the minimum `I`, we can rearrange the inequality:
`X - Y <= I`

This inequality tells us that the investment `I` must be greater than or equal to the difference between the earned amount `X` and the tax threshold `Y`. The smallest integer value that satisfies this condition is exactly `X - Y`.

If we invest `I = X - Y`, our effective income becomes `X - (X - Y) = Y`. Since `Y` is not strictly greater than `Y` (it's equal), we will not have to pay taxes. Any investment less than `X - Y` would result in an effective income that is still strictly greater than `Y`, meaning taxes would still be applicable.

Therefore, the minimum amount that needs to be invested is `X - Y`.

## Complexity Analysis
- **Time Complexity**: $O(1)$
The solution involves reading a few integers and performing a single subtraction for each test case. The number of test cases is read once, and then a loop runs for that many iterations. Inside the loop, the operations are constant time. Thus, for each test case, the time complexity is $O(1)$. If `T` is the number of test cases, the total time complexity is $O(T)$. However, since the problem constraints usually imply `T` is relatively small and the operations per test case are constant, it's often simplified to $O(1)$ per test case.

- **Space Complexity**: $O(1)$
The solution uses a fixed number of variables (`T`, `X`, `Y`, `investment_needed`) regardless of the input size. Therefore, the space complexity is constant, $O(1)$.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes most standard libraries

// Use the standard namespace to avoid prefixing std::
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times, decrementing T in each iteration
        int X, Y;
        cin >> X >> Y; // Read the amount earned (X) and the tax threshold (Y)

        // The minimum investment needed is the difference between the earned amount
        // and the tax threshold, because investing this amount will reduce the
        // taxable income down to the threshold Y, thus avoiding taxes.
        int investment_needed = X - Y;

        // Output the calculated minimum investment for the current test case,
        // followed by a newline character.
        cout << investment_needed << "\n";
    }

    return 0; // Indicate successful execution
}
```