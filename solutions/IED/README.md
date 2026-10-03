# [International Education Day! (IED)](https://www.codechef.com/problems/IED)
- **Difficulty Rating**: 271
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the maximum total sales achieved by either Chef or Chefina. We are given three integer inputs:
1.  `A`: The cost per item for Chef.
2.  `B`: The cost per item for Chefina.
3.  `C`: The total number of items sold by both Chef and Chefina.

We need to calculate Chef's total sales, Chefina's total sales, and then output the larger of these two values.

## Intuition & Mathematical Observation

The problem is a straightforward application of basic arithmetic.
To find Chef's total sales, we multiply their cost per item (`A`) by the number of items sold (`C`).
Chef's Total Sales = `A * C`

Similarly, to find Chefina's total sales, we multiply their cost per item (`B`) by the number of items sold (`C`).
Chefina's Total Sales = `B * C`

Once we have both total sales figures, the problem requires us to find the maximum of these two values. This can be done using a simple comparison or a `max()` function.

There are no complex algorithms, data structures, or deep mathematical insights required. It's a direct computation based on the given inputs.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The solution involves a fixed number of operations regardless of the input values (within integer limits):
    *   Reading three integers.
    *   Two multiplication operations.
    *   One comparison (or `max` function call).
    *   Printing one integer.
    All these operations take constant time. Therefore, the overall time complexity is $O(1)$.

-   **Space Complexity**: $O(1)$
    The solution uses a fixed number of integer variables (`A`, `B`, `C`, `chef_total_sales`, `chefina_total_sales`, `maximum_sales`) to store input and intermediate results. The memory used by these variables does not grow with the input values. Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common headers like iostream and algorithm

// Use the standard namespace to avoid repeatedly writing std::
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from C's stdio and prevents synchronization,
    // which is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare three integer variables to store the input values:
    // A: cost per item for Chef
    // B: cost per item for Chefina
    // C: number of items sold by both
    int A, B, C;

    // Read the three space-separated integers from standard input.
    cin >> A >> B >> C;

    // Calculate Chef's total sales: cost per item * number of items.
    int chef_total_sales = A * C;

    // Calculate Chefina's total sales: cost per item * number of items.
    int chefina_total_sales = B * C;

    // Find the maximum of the two total sales values.
    // std::max is part of the <algorithm> header, which is included by <bits/stdc++.h>.
    int maximum_sales = max(chef_total_sales, chefina_total_sales);

    // Print the calculated maximum sales value to standard output,
    // followed by a newline character as required.
    cout << maximum_sales << "\n";

    // Indicate successful execution of the program.
    return 0;
}
```