# [Sale (FINALSALE)](https://www.codechef.com/problems/FINALSALE)
- **Difficulty Rating**: 1180
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to calculate the maximum possible total sales given a sequence of projected daily sales $A_1, A_2, \dots, A_N$. We have two options for how the sale can end:

1.  **The sale ends on any day $i$ (from 1 to $N$)**: If the sale ends on day $i$, then the sales for days $1, 2, \dots, i-1$ are as projected ($A_1, A_2, \dots, A_{i-1}$), but the sales for day $i$ are doubled ($2 \times A_i$). The sales for all subsequent days ($i+1, \dots, N$) are zero.
2.  **The sale continues indefinitely (or beyond day $N$)**: If the sale continues beyond day $N$, it implies that no day's sales are doubled, and all projected sales $A_1, A_2, \dots, A_N$ are realized.

We need to find the maximum total sales achievable across all these possibilities.

## Intuition & Mathematical Observation

Let the projected daily sales be $A_0, A_1, \dots, A_{N-1}$ (using 0-based indexing for convenience with vectors).

There are $N+1$ possible scenarios to consider:

*   **Scenario 0: The sale continues beyond day $N-1$.**
    In this case, no sales are doubled. The total sales are simply the sum of all projected sales:
    $S_0 = \sum_{i=0}^{N-1} A_i$.

*   **Scenario $i$ (for $i$ from 0 to $N-1$): The sale ends on day $i$.**
    If the sale ends on day $i$, the sales are:
    - $A_0, A_1, \dots, A_{i-1}$ for days $0, 1, \dots, i-1$.
    - $2 \times A_i$ for day $i$.
    - $0$ for days $i+1, \dots, N-1$.
    The total sales for this scenario are:
    $S_i = \left(\sum_{j=0}^{i-1} A_j\right) + 2 \times A_i$.

Our goal is to find $\max(S_0, S_1, S_2, \dots, S_{N-1})$.

Let's analyze the relationship between $S_0$ and $S_i$.
$S_0 = A_0 + A_1 + \dots + A_{i-1} + A_i + A_{i+1} + \dots + A_{N-1}$.
$S_i = A_0 + A_1 + \dots + A_{i-1} + 2 \times A_i$.

We can rewrite $S_i$ in terms of $S_0$:
$S_i = (A_0 + A_1 + \dots + A_{i-1} + A_i) + A_i$.
This doesn't directly relate to $S_0$ in a simple way.

Let's consider the total sum of projected sales as a baseline.
The total sales if the sale continues indefinitely (or beyond day $N-1$) is $\sum_{k=0}^{N-1} A_k$. This is one of our candidate maximums.

Now, consider the case where the sale ends on day $i$. The total sales are $\sum_{j=0}^{i-1} A_j + 2 \times A_i$.
We can calculate this efficiently.
Let `prefix_sum[k]` be the sum of sales from day 0 to day $k-1$. So, `prefix_sum[0] = 0`, `prefix_sum[1] = A_0`, `prefix_sum[2] = A_0 + A_1`, and generally `prefix_sum[i] = \sum_{j=0}^{i-1} A_j$.

Then, the total sales if the sale ends on day $i$ is `prefix_sum[i] + 2 * A_i`.

We can iterate through each day $i$ from $0$ to $N-1$:
1.  Calculate the total sales if the sale ends on day $i$: `prefix_sum[i] + 2 * A_i`.
2.  Keep track of the maximum sales found so far.

The initial maximum sales can be set to the sum of all projected sales (Scenario 0). Then, we update this maximum with the sales calculated for each scenario where the sale ends on a specific day.

Let's trace with an example: $A = [10, 20, 30]$ ($N=3$).

*   **Scenario 0 (Sale continues beyond day 2):**
    Total sales = $10 + 20 + 30 = 60$.
    `max_sales = 60`.

*   **Scenario 0 (Sale ends on day 0):**
    Sales = $2 \times A_0 = 2 \times 10 = 20$.
    `prefix_sum` before day 0 is 0.
    Total sales = $0 + 2 \times 10 = 20$.
    `max_sales = max(60, 20) = 60$.
    Update `prefix_sum` for the next iteration: `prefix_sum` becomes $0 + A_0 = 10$.

*   **Scenario 1 (Sale ends on day 1):**
    Sales = $A_0 + 2 \times A_1 = 10 + 2 \times 20 = 10 + 40 = 50$.
    Using `prefix_sum`: `prefix_sum` (sum up to day 0) is 10.
    Total sales = $10 + 2 \times 20 = 50$.
    `max_sales = max(60, 50) = 60$.
    Update `prefix_sum`: `prefix_sum` becomes $10 + A_1 = 10 + 20 = 30$.

*   **Scenario 2 (Sale ends on day 2):**
    Sales = $A_0 + A_1 + 2 \times A_2 = 10 + 20 + 2 \times 30 = 30 + 60 = 90$.
    Using `prefix_sum`: `prefix_sum` (sum up to day 1) is 30.
    Total sales = $30 + 2 \times 30 = 90$.
    `max_sales = max(60, 90) = 90$.
    Update `prefix_sum`: `prefix_sum` becomes $30 + A_2 = 30 + 30 = 60$.

After iterating through all days, the maximum sales is 90.

The logic in the provided solution code implements this correctly.
It first calculates the sum of all elements as the initial `max_sales` (representing the case where the sale continues indefinitely).
Then, it iterates through the array, maintaining a `prefix_sum`. In each iteration `i`, it calculates the potential total sales if the sale ends on day `i` as `prefix_sum + 2 * a[i]` and updates `max_sales`. After calculating the potential sales for day `i`, it updates `prefix_sum` by adding `a[i]` for the next iteration.

## Complexity Analysis

-   **Time Complexity**: $O(N)$
    The code iterates through the input array `a` twice.
    The first loop (implicit in the initial calculation of `max_sales` as the sum of all elements) takes $O(N)$ time.
    The second loop iterates through the array once to calculate `prefix_sum` and potential sales for each day, taking $O(N)$ time.
    Therefore, the total time complexity is $O(N) + O(N) = O(N)$.

-   **Space Complexity**: $O(N)$
    A `std::vector<long long> a` of size $N$ is used to store the projected daily sales.
    The `prefix_sum` and `max_sales` variables use constant extra space.
    Therefore, the space complexity is dominated by the input array storage, which is $O(N)$. If we consider the input array as part of the input and not extra space, then the extra space complexity is $O(1)$. However, typically, the space used to store the input is included.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int n; // Number of days
        std::cin >> n;
        std::vector<long long> a(n); // Projected sales for each day
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        long long max_sales = 0;

        // Option 1: The sale continues beyond day N-1.
        // In this case, no sales are doubled. The total sales are the sum of all projected sales.
        // This also serves as an initial candidate for max_sales.
        long long current_sum_all_days = 0;
        for (long long sales : a) {
            current_sum_all_days += sales;
        }
        max_sales = current_sum_all_days;

        // Option 2: The sale ends on day i (for i from 0 to N-1).
        // If the sale ends on day i, sales for days 0 to i-1 are as projected,
        // sales for day i are doubled (2 * a[i]), and sales for days i+1 to N-1 are zero.
        // Total sales = sum(a[0]...a[i-1]) + 2 * a[i].
        // We can efficiently calculate sum(a[0]...a[i-1]) using a running prefix sum.
        long long prefix_sum = 0; // Stores sum of sales from day 0 up to the previous day (i-1)
        for (int i = 0; i < n; ++i) {
            // Calculate total sales if the sale ends on day 'i':
            // prefix_sum holds sum(a[0]...a[i-1])
            // 2 * a[i] is the doubled sales for day 'i'
            long long sales_if_ends_today = prefix_sum + 2 * a[i];

            // Update the maximum sales found so far
            max_sales = std::max(max_sales, sales_if_ends_today);

            // Update prefix_sum for the next iteration: add sales of the current day 'i'
            prefix_sum += a[i];
        }

        std::cout << max_sales << "\n";
    }
    return 0;
}
```