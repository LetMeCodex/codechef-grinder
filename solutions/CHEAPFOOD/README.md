# [Best Coupon (CHEAPFOOD)](https://www.codechef.com/problems/CHEAPFOOD)
- **Difficulty Rating**: 496
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef has a bill of `X` rupees and two coupons available. He wants to maximize the discount he receives.
The two coupons offer different discounts:
1.  **Coupon 1**: 10 percent off the total bill amount `X`.
2.  **Coupon 2**: A flat discount of Rs. 100.

Chef needs to choose the coupon that gives him the maximum discount and output that maximum discount value. It's guaranteed that `X` will always be a multiple of 100.

## Intuition & Mathematical Observation

The problem asks us to find the maximum of two possible discount values. We simply need to calculate the discount offered by each coupon and then compare them.

1.  **Discount from Coupon 1**: This coupon offers 10 percent off the bill amount `X`. Mathematically, 10 percent of `X` can be calculated as `(10 / 100) * X`, which simplifies to `X / 10`. Since `X` is guaranteed to be a multiple of 100, `X / 10` will always result in an integer, so we don't need to worry about floating-point arithmetic.

2.  **Discount from Coupon 2**: This coupon offers a fixed discount of Rs. 100.

Once we have these two discount values, say `discount1 = X / 10` and `discount2 = 100`, Chef will choose the one that provides a greater benefit. Therefore, the maximum discount Chef can avail is `max(discount1, discount2)`.

**Example:**
*   If `X = 1200`:
    *   `discount1 = 1200 / 10 = 120`
    *   `discount2 = 100`
    *   `max(120, 100) = 120`
*   If `X = 800`:
    *   `discount1 = 800 / 10 = 80`
    *   `discount2 = 100`
    *   `max(80, 100) = 100`

This simple comparison forms the core of the solution.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    *   For each test case, the `solve()` function performs a few constant-time operations: one integer division, one assignment, one comparison (using `max`), and one output operation. These operations take constant time, $O(1)$.
    *   Since there are `T` test cases, and each is processed in $O(1)$ time, the total time complexity is $O(T \times 1) = O(T)$.

*   **Space Complexity**: $O(1)$
    *   In the `solve()` function, we declare a few integer variables (`x`, `discount1`, `discount2`). These variables consume a constant amount of memory, regardless of the input value `X`.
    *   The `main()` function also uses a constant amount of space for `t`.
    *   Therefore, the overall space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries, as requested

using namespace std; // Uses the standard namespace, as requested

void solve() {
    int x; // Declare an integer variable x for the bill amount
    cin >> x; // Read the bill amount x for the current test case

    // Calculate the discount from the first coupon: 10 percent off on the bill amount.
    // Since X is guaranteed to be a multiple of 100, X/10 will always be an integer.
    int discount1 = x / 10;

    // The discount from the second coupon is a flat Rs. 100.
    int discount2 = 100;

    // To find the maximum discount Chef can avail, we compare the two discounts
    // and output the larger one.
    cout << max(discount1, discount2) << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming, as requested.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Declare an integer variable t for the number of test cases
    cin >> t; // Read the number of test cases

    // Loop through each test case
    while (t--) {
        solve(); // Call the solve function to handle the logic for each test case
    }

    return 0; // Indicate successful execution
}
```