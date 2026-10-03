# [Slow Solution (SLOWSOLN)](https://www.codechef.com/problems/SLOWSOLN)
- **Difficulty Rating**: 1003
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to maximize the total number of iterations, defined as $\sum_{i=1}^{T} N_i^2$, subject to several constraints:
1. We must choose $T$ positive integers, $N_1, N_2, \dots, N_T$.
2. The number of chosen integers $T$ must be between $1$ and `maxT` (inclusive): $1 \le T \le \text{maxT}$.
3. Each chosen integer $N_i$ must be between $1$ and `maxN` (inclusive): $1 \le N_i \le \text{maxN}$.
4. The sum of all chosen integers must not exceed `sumN`: $\sum_{i=1}^{T} N_i \le \text{sumN}$.

We are given `maxT`, `maxN`, and `sumN` for each test case.

## Intuition & Mathematical Observation

The core of this problem is to maximize the sum of squares, $\sum N_i^2$, given a fixed total sum $\sum N_i$ and bounds on individual $N_i$ values.

Consider the function $f(x) = x^2$. This is a convex function. A key property of convex functions is that to maximize their sum (or average) given a fixed sum of inputs, the inputs should be made as *unequal* as possible, pushing values towards the extremes.

In our case, the maximum allowed value for any $N_i$ is `maxN`. Therefore, to maximize $\sum N_i^2$, we should try to make as many $N_i$ values as large as possible, specifically `maxN`.

Let's formalize this strategy:
1.  **Prioritize `maxN`**: Assign `maxN` to as many $N_i$ variables as possible. This maximizes the contribution $N_i^2$ for each unit of sum $N_i$ used.
2.  **Constraints on `maxN` assignments**:
    *   We can assign `maxN` at most `maxT` times (due to the $T \le \text{maxT}$ constraint).
    *   The total sum used by these `maxN` assignments cannot exceed `sumN`. If we assign `maxN` to $k$ variables, the sum used is $k \times \text{maxN}$. So, $k \times \text{maxN} \le \text{sumN}$, which implies $k \le \text{sumN} / \text{maxN}$.
    *   Combining these, the maximum number of $N_i$ values we can set to `maxN` is $k = \min(\text{maxT}, \text{sumN} / \text{maxN})$.

3.  **Calculate initial iterations**: After assigning `maxN` to $k$ variables, the total iterations accumulated are $k \times \text{maxN}^2$.

4.  **Update remaining resources**:
    *   The remaining sum budget is $\text{sumN} - (k \times \text{maxN})$.
    *   The remaining available test case slots are $\text{maxT} - k$.

5.  **Handle the remainder**:
    *   If there are no remaining test case slots (`maxT - k == 0`) or no remaining sum budget (`sumN - (k \times \text{maxN}) == 0`), we are done.
    *   If both `remaining_T_slots > 0` and `remaining_sum_budget > 0`: We have a positive remaining sum to distribute among at least one remaining slot. To maximize the sum of squares, we should assign *all* of this `remaining_sum_budget` to a *single* $N_i$ variable.
        *   Let this remaining sum be $S_{rem}$. We assign $N_{k+1} = S_{rem}$. The contribution to total iterations will be $S_{rem}^2$.
        *   Crucially, the `remaining_sum_budget` will always be less than `maxN`. This is because $k = \text{sumN} / \text{maxN}$ (integer division) means $\text{sumN} = k \times \text{maxN} + \text{remainder}$, where $0 \le \text{remainder} < \text{maxN}$. So, `remaining_sum_budget` is exactly this `remainder`. This ensures that $N_{k+1} = S_{rem}$ satisfies the $N_i \le \text{maxN}$ constraint.
        *   The other `remaining_T_slots - 1` variables can be effectively ignored (or set to $1$ if $N_i \ge 1$ was a strict requirement for *all* $T$ slots, but the problem allows $T \le \text{maxT}$, meaning we don't have to use all `maxT` slots). By assigning the entire remaining sum to one $N_i$, we maximize its square and thus the total sum of squares.

**Example Walkthrough**:
`maxT = 3, maxN = 5, sumN = 12`

1.  Calculate $k$: `num_full_maxN = min(maxT, sumN / maxN) = min(3, 12 / 5) = min(3, 2) = 2`.
    We assign $N_1=5, N_2=5$.
2.  Total iterations so far: $2 \times 5^2 = 2 \times 25 = 50$.
3.  Remaining sum budget: $12 - (2 \times 5) = 12 - 10 = 2$.
4.  Remaining test case slots: $3 - 2 = 1$.
5.  Since `remaining_T_slots` (1) is $>0$ and `remaining_sum_budget` (2) is $>0$:
    Add `remaining_sum_budget^2` to total iterations: $50 + 2^2 = 50 + 4 = 54$.
    The chosen $N_i$ values are $5, 5, 2$.
    *   $T=3 \le \text{maxT}=3$.
    *   $N_i \in \{1, \dots, 5\}$: $5, 5, 2$ all satisfy this.
    *   $\sum N_i = 5+5+2 = 12 \le \text{sumN}=12$.
    *   $\sum N_i^2 = 5^2+5^2+2^2 = 25+25+4 = 54$.

**Data Type Consideration**:
The values `maxN` and `sumN` can be up to $10^5$ and $10^9$ respectively.
`maxN * maxN` can be $(10^5)^2 = 10^{10}$.
`sumN * sumN` (for the remainder part) can be $(10^5)^2 = 10^{10}$ (since remainder is $< \text{maxN}$).
The `total_iterations` can accumulate up to `maxT * maxN * maxN` which is $10^5 \times 10^{10} = 10^{15}$.
All these values exceed the capacity of a standard 32-bit integer (`int`), which typically goes up to $2 \times 10^9$. Therefore, `long long` must be used for all calculations involving squares and the final sum to prevent overflow.

## Complexity Analysis

*   **Time Complexity**: For each test case, the solution performs a fixed number of arithmetic operations (division, multiplication, addition, subtraction, and `std::min`). These operations take constant time. If there are $T_{total}$ test cases (as specified by the input `t`), the total time complexity will be $O(T_{total})$. Given $T_{total}$ can be up to $10^5$, this approach is highly efficient.

*   **Space Complexity**: The solution uses a few variables to store the input values (`maxT`, `maxN`, `sumN`) and intermediate results (`num_full_maxN`, `total_iterations`, etc.). These variables occupy a constant amount of memory regardless of the input values. Therefore, the space complexity is $O(1)$ (constant space) per test case.

## Solution Code

```cpp
#include <iostream>
#include <algorithm> // Required for std::min

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases for the entire problem
    std::cin >> t;
    while (t--) {
        int maxT_int, maxN_int, sumN_int;
        std::cin >> maxT_int >> maxN_int >> sumN_int;

        // Convert input values to long long to prevent potential overflow
        // during intermediate calculations (e.g., maxN * maxN) and for the final sum.
        long long maxT = maxT_int;
        long long maxN = maxN_int;
        long long sumN = sumN_int;

        // Step 1: Determine the number of test cases that can be assigned the maximum N value (maxN).
        // This is limited by the total allowed test cases (maxT) and the total sum budget (sumN).
        // sumN / maxN gives how many times maxN can fit into sumN.
        long long num_full_maxN = std::min(maxT, sumN / maxN);

        // Step 2: Calculate the total iterations from these 'num_full_maxN' test cases.
        // Each contributes maxN * maxN iterations.
        long long total_iterations = num_full_maxN * maxN * maxN;

        // Step 3: Calculate the sum of N values used by these 'num_full_maxN' test cases.
        long long sum_used_for_full_maxN = num_full_maxN * maxN;

        // Step 4: Calculate the remaining sum budget.
        long long remaining_sum_budget = sumN - sum_used_for_full_maxN;

        // Step 5: Calculate the remaining number of test case slots available.
        long long remaining_T_slots = maxT - num_full_maxN;

        // Step 6: If there are remaining test case slots AND a remaining sum budget,
        // assign the entire remaining sum budget to one more test case.
        // This maximizes the square for the remaining sum.
        // As proven in the thought process, if remaining_T_slots > 0, then
        // remaining_sum_budget will be <= maxN, making it a valid N value.
        if (remaining_T_slots > 0 && remaining_sum_budget > 0) {
            total_iterations += remaining_sum_budget * remaining_sum_budget;
        }

        // Output the maximum total iterations for the current test case.
        std::cout << total_iterations << "\n";
    }

    return 0;
}
```