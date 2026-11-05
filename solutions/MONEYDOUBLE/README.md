# [Money Double (MONEYDOUBLE)](https://www.codechef.com/problems/MONEYDOUBLE)
- **Difficulty Rating**: 784
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to maximize the final amount of money after performing exactly `Y` operations. We start with an initial amount `X`. In each operation, we have two choices:
1. Add 1000 to the current money.
2. Double the current money.

We need to find the maximum possible money we can have after `Y` operations.

## Intuition & Mathematical Observation

Let's consider the effect of the two operations. Suppose we have `M` money.
- If we perform an "add 1000" operation followed by a "double" operation:
  The money becomes `(M + 1000) * 2 = 2M + 2000`.
- If we perform a "double" operation followed by an "add 1000" operation:
  The money becomes `(M * 2) + 1000 = 2M + 1000`.

Comparing these two sequences, `2M + 2000` is always greater than `2M + 1000`. This crucial observation tells us that it is always optimal to perform an "add 1000" operation *before* a "double" operation if both are to be performed. This is because the added 1000 also gets doubled, contributing more to the final sum.

Therefore, to maximize the final amount, all "add 1000" operations should be performed consecutively at the beginning, followed by all "double" operations.

Based on this, our strategy becomes:
1. Choose a number `k` (where `0 <= k <= Y`) representing the count of "add 1000" operations.
2. Perform these `k` "add 1000" operations first. The money becomes `X + k * 1000`.
3. Perform the remaining `Y - k` "double" operations. The money becomes `(X + k * 1000) * 2^(Y-k)`.

Since `Y` is a small number (up to 10), we can iterate through all possible values of `k` from `0` to `Y`. For each `k`, we calculate the final amount using the formula above and keep track of the maximum amount found.

Let's trace an example: `X = 100, Y = 2`
- **k = 0** (0 additions, 2 doublings):
  Amount = `(100 + 0 * 1000) * 2^(2-0) = 100 * 2^2 = 100 * 4 = 400`
- **k = 1** (1 addition, 1 doubling):
  Amount = `(100 + 1 * 1000) * 2^(2-1) = 1100 * 2^1 = 1100 * 2 = 2200`
- **k = 2** (2 additions, 0 doublings):
  Amount = `(100 + 2 * 1000) * 2^(2-2) = 2100 * 2^0 = 2100 * 1 = 2100`

The maximum amount is 2200.

The maximum possible value for `X` is 1000 and `Y` is 10.
The maximum intermediate sum before doubling would be `X + Y * 1000 = 1000 + 10 * 1000 = 11000`.
The maximum doubling factor would be `2^Y = 2^10 = 1024`.
The maximum final amount would be around `11000 * 1024 = 11,264,000`. This value fits comfortably within a `long long` data type, and even within a standard 32-bit `int` (which typically goes up to `2 * 10^9`). However, using `long long` for all calculations is a safer practice in competitive programming to prevent potential overflows, especially when dealing with powers or large multiplications.

## Complexity Analysis

-   **Time Complexity**: The solution involves a single loop that iterates `Y+1` times (for `k` from `0` to `Y`). Inside the loop, we perform a few constant-time arithmetic operations (addition, multiplication, and bit shift for power of 2). Since `Y` is at most 10, the number of iterations is very small (at most 11). Therefore, the time complexity per test case is $O(Y)$. Given `T` test cases, the total time complexity is $O(T \cdot Y)$.
-   **Space Complexity**: We only use a few variables to store `X`, `Y`, `k`, `max_amount`, and intermediate calculations. This requires a constant amount of memory, so the space complexity is $O(1)$ per test case.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common headers like iostream, algorithm, etc.

// Using namespace std; is common practice in competitive programming for brevity.
using namespace std; 

void solve() {
    long long X, Y; // Use long long for X and Y to be safe, though int would suffice for input values based on constraints.
    cin >> X >> Y;

    long long max_amount = 0; // Initialize max_amount to 0.

    // Iterate through all possible counts of 'add 1000' operations (k).
    // The number of additions k can range from 0 to Y.
    // The remaining (Y - k) operations will be 'double' operations.
    for (long long k = 0; k <= Y; ++k) {
        // Calculate amount after k additions of 1000.
        // Use 1000LL to ensure the multiplication k * 1000 is done using long long arithmetic
        // before adding to X, preventing potential intermediate overflow.
        long long current_amount_after_additions = X + k * 1000LL; 
        
        // Calculate the number of doubling operations remaining.
        long long num_doublings = Y - k;
        
        // Calculate the doubling factor (2 raised to the power of num_doublings).
        // Use 1LL to ensure the bit shift operates on a long long, preventing overflow
        // if num_doublings was large (e.g., > 30 for int).
        long long doubling_factor = 1LL << num_doublings; 
        
        // Calculate the total amount for this specific strategy (k additions, Y-k doublings).
        long long total_amount = current_amount_after_additions * doubling_factor;
        
        // Update the maximum amount found so far.
        max_amount = max(max_amount, total_amount);
    }

    cout << max_amount << "\n"; // Output the maximum amount for the current test case.
}

int main() {
    // Fast I/O setup. Unties cin/cout from C standard streams and disables synchronization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Number of test cases
    cin >> t;
    while (t--) {
        solve(); // Call the solve function for each test case.
    }

    return 0; // Indicate successful execution.
}
```