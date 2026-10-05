# [Online or Offline (FOODPLAN)](https://www.codechef.com/problems/FOODPLAN)
- **Difficulty Rating**: 713
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to compare the cost of ordering food online versus dining at a restaurant. We are given two integer values: `N`, the original cost of ordering food online, and `M`, the cost of dining at the restaurant. When ordering online, a 10% discount is applied to the original online cost `N`. We need to determine which option is cheaper or if they cost the same. The output should be "ONLINE", "DINING", or "EITHER" accordingly.

## Intuition & Mathematical Observation

1.  **Calculate Online Cost with Discount**:
    *   The original online cost is `N`.
    *   A 10% discount means the discount amount is `10% of N`, which is `(10/100) * N = N/10`.
    *   The final online cost after the discount is `N - N/10`.
    *   To simplify this expression: `N - N/10 = (10N - N) / 10 = 9N / 10`.

2.  **Compare Costs**:
    *   We need to compare the final online cost (`9N / 10`) with the restaurant cost (`M`).

3.  **Avoiding Floating-Point Issues**:
    *   Directly calculating `9N / 10` using floating-point numbers (like `double` or `float`) can introduce precision errors, especially when checking for exact equality. For competitive programming, it's generally best to stick to integer arithmetic whenever possible.
    *   To compare `9N / 10` and `M` using only integers, we can multiply both sides of the comparison by 10. This transforms the comparison without changing its outcome:
        *   `9N / 10 < M` becomes `9N < 10M`
        *   `9N / 10 > M` becomes `9N > 10M`
        *   `9N / 10 == M` becomes `9N == 10M`

4.  **Data Type Considerations**:
    *   Given the constraints `1 <= N, M <= 1000`:
        *   The maximum value for `9 * N` would be `9 * 1000 = 9000`.
        *   The maximum value for `10 * M` would be `10 * 1000 = 10000`.
    *   Both these values fit comfortably within a standard `int` type (which typically handles values up to `2 * 10^9`). Therefore, `long long` is not necessary for this problem.

Based on this, the strategy is to calculate `9 * N` and `10 * M` and then compare these two integer values to determine the output.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    *   The solution processes `T` test cases.
    *   For each test case, it performs a fixed number of operations: reading two integers, two multiplications, one comparison, and printing a string. These operations take constant time, $O(1)$.
    *   Therefore, the total time complexity is $T \times O(1) = O(T)$.

*   **Space Complexity**: $O(1)$
    *   The solution uses a few integer variables (`T`, `N`, `M`, `online_cost_...`, `restaurant_cost_...`) to store input and intermediate calculations.
    *   The amount of memory used does not depend on the input values `N` or `M`, but rather on a fixed number of variables.
    *   Thus, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Required include as per instructions

// Required using namespace std; as per instructions
using namespace std;

int main() {
    // Fast I/O as per instructions
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times for each test case
        int N, M;
        cin >> N >> M; // Read online cost N and restaurant cost M

        // Calculate the final online cost after 10% discount.
        // The discount is 10% of N, so the final cost is N - (N * 10 / 100) = N - N/10.
        // This simplifies to (10N - N) / 10 = 9N / 10.
        //
        // To avoid potential floating-point arithmetic issues and ensure exact comparison,
        // we compare the costs by multiplying both sides of the inequality by 10.
        //
        // Original comparison: (9 * N) / 10 vs M
        // Equivalent integer comparison: 9 * N vs 10 * M
        //
        // Constraints: 1 <= N, M <= 1000.
        // Maximum value for 9 * N is 9 * 1000 = 9000.
        // Maximum value for 10 * M is 10 * 1000 = 10000.
        // Both these values fit comfortably within a standard 'int' type,
        // so 'long long' is not strictly necessary for this problem.

        int online_cost_after_discount_multiplied_by_10 = 9 * N;
        int restaurant_cost_multiplied_by_10 = 10 * M;

        if (online_cost_after_discount_multiplied_by_10 < restaurant_cost_multiplied_by_10) {
            cout << "ONLINE\n"; // Online option is cheaper
        } else if (online_cost_after_discount_multiplied_by_10 > restaurant_cost_multiplied_by_10) {
            cout << "DINING\n"; // Restaurant option is cheaper
        } else { // online_cost_after_discount_multiplied_by_10 == restaurant_cost_multiplied_by_10
            cout << "EITHER\n"; // Both options cost the same
        }
    }

    return 0;
}
```