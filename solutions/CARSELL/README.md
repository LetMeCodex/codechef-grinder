# [Sell All the Cars (CARSELL)](https://www.codechef.com/problems/CARSELL)
- **Difficulty Rating**: 1380
- **Solved in**: 3 attempt(s)

## Problem Summary
We are given $N$ cars, each with an initial price. We can sell at most one car per year. If we decide to sell a car in year $k$ (where year 1 is the first year, year 2 is the second, and so on), its price will be its initial price minus $(k-1)$. We want to maximize the total profit we can make by selling all $N$ cars over $N$ years. The profit must be non-negative. The total profit should be modulo $10^9 + 7$.

## Intuition & Mathematical Observation

The core of this problem lies in deciding which car to sell in which year to maximize profit. Since we can sell at most one car per year and we have $N$ cars to sell over $N$ years, we will sell exactly one car each year.

Let the initial prices of the $N$ cars be $p_1, p_2, \dots, p_N$.
If we sell a car with initial price $p_i$ in year $k$, its selling price will be $\max(0, p_i - (k-1))$.
The total profit is the sum of selling prices of all cars, modulo $10^9 + 7$.

Consider two cars, A and B, with initial prices $p_A$ and $p_B$, and two years, $k_1$ and $k_2$, where $k_1 < k_2$.
Suppose we sell car A in year $k_1$ and car B in year $k_2$. The profit is $\max(0, p_A - (k_1-1)) + \max(0, p_B - (k_2-1))$.
If we swap them, selling car B in year $k_1$ and car A in year $k_2$, the profit is $\max(0, p_B - (k_1-1)) + \max(0, p_A - (k_2-1))$.

Let's think about the depreciation. The later a car is sold, the more it depreciates. To maximize profit, we should try to sell cars with higher initial prices when the depreciation is lower (i.e., in earlier years). This suggests a greedy approach.

If we sort the initial prices in descending order, say $p'_1 \ge p'_2 \ge \dots \ge p'_N$, it seems intuitive to sell the car with the highest initial price ($p'_1$) in the first year (year 1, depreciation $0$), the car with the second highest initial price ($p'_2$) in the second year (year 2, depreciation $1$), and so on.
In general, we would sell the car with the $k$-th highest initial price ($p'_k$) in the $k$-th year (year $k$, depreciation $k-1$).

Let's verify this. Suppose we have sorted prices $p'_1 \ge p'_2 \ge \dots \ge p'_N$.
If we sell $p'_i$ in year $y_i$, the total profit is $\sum_{i=1}^N \max(0, p'_i - (y_i-1))$, where $\{y_1, y_2, \dots, y_N\}$ is a permutation of $\{1, 2, \dots, N\}$.

Consider the strategy: sell $p'_k$ in year $k$. The profit for this car is $\max(0, p'_k - (k-1))$.
The total profit would be $\sum_{k=1}^N \max(0, p'_k - (k-1))$.

Let's assume there's an optimal solution where this is not the case. This means there exist two cars, say with initial prices $p'_i$ and $p'_j$ where $i < j$ (so $p'_i \ge p'_j$), and they are sold in years $y_a$ and $y_b$ respectively, such that $y_a > y_b$.
So, car $p'_i$ is sold in year $y_a$ and car $p'_j$ is sold in year $y_b$.
The profit contribution from these two cars is $\max(0, p'_i - (y_a-1)) + \max(0, p'_j - (y_b-1))$.

Now, let's swap their selling years. Sell $p'_i$ in year $y_b$ and $p'_j$ in year $y_a$.
The new profit contribution is $\max(0, p'_i - (y_b-1)) + \max(0, p'_j - (y_a-1))$.

Since $i < j$, we have $p'_i \ge p'_j$.
Since $y_a > y_b$, we have $y_a-1 > y_b-1$.

Let $P_1 = \max(0, p'_i - (y_a-1)) + \max(0, p'_j - (y_b-1))$
Let $P_2 = \max(0, p'_i - (y_b-1)) + \max(0, p'_j - (y_a-1))$

We want to show that $P_2 \ge P_1$.
Consider the function $f(p, y) = \max(0, p - y)$. This function is submodular.
The sum $\sum f(p_i, y_i)$ is maximized when $p_i$ are sorted in descending order and $y_i$ are sorted in ascending order. This is a standard result from rearrangement inequality or by considering pairwise swaps.

Specifically, if we have $p_1 \ge p_2$ and $y_1 < y_2$, then:
$\max(0, p_1 - (y_1-1)) + \max(0, p_2 - (y_2-1)) \le \max(0, p_1 - (y_2-1)) + \max(0, p_2 - (y_1-1))$
This inequality might not hold directly due to the $\max(0, \cdot)$ function. However, the principle of pairing larger values with smaller subtractions (earlier years) generally holds.

Let's re-examine the greedy strategy:
Sort the initial prices in descending order: $p'_1 \ge p'_2 \ge \dots \ge p'_N$.
Sell the car with price $p'_k$ in year $k$. The depreciation is $(k-1)$.
The selling price is $\max(0, p'_k - (k-1))$.
The total profit is $\sum_{k=1}^N \max(0, p'_k - (k-1))$.

The problem states "sell at most one car per year" and we have $N$ cars and $N$ years. This implies we sell exactly one car each year for $N$ years.
The years are implicitly $1, 2, \dots, N$.
The depreciation for year $k$ is $k-1$.

So, if we sort prices in descending order $p'_1 \ge p'_2 \ge \dots \ge p'_N$, the greedy strategy is to sell $p'_1$ in year 1 (depreciation 0), $p'_2$ in year 2 (depreciation 1), ..., $p'_N$ in year $N$ (depreciation $N-1$).
The profit for the $k$-th car in this sorted list (which is $p'_k$) sold in year $k$ is $\max(0, p'_k - (k-1))$.

The total profit is $\sum_{k=1}^N \max(0, p'_k - (k-1))$.
We need to compute this sum modulo $10^9 + 7$.

The crucial observation is that if the current car's price after depreciation becomes non-positive, any subsequent car (with an even lower initial price) sold in a later year (with even more depreciation) will also yield a non-positive profit. Therefore, we can stop the summation as soon as we encounter a non-positive selling price.

Example:
Prices: [10, 8, 12]
$N=3$.
Sorted prices (descending): [12, 10, 8]

Year 1 (depreciation 0): Sell car with price 12. Profit = $\max(0, 12 - 0) = 12$.
Year 2 (depreciation 1): Sell car with price 10. Profit = $\max(0, 10 - 1) = 9$.
Year 3 (depreciation 2): Sell car with price 8. Profit = $\max(0, 8 - 2) = 6$.

Total profit = $12 + 9 + 6 = 27$.

Let's consider another order:
Year 1 (depreciation 0): Sell car with price 10. Profit = $\max(0, 10 - 0) = 10$.
Year 2 (depreciation 1): Sell car with price 12. Profit = $\max(0, 12 - 1) = 11$.
Year 3 (depreciation 2): Sell car with price 8. Profit = $\max(0, 8 - 2) = 6$.
Total profit = $10 + 11 + 6 = 27$.

Wait, the example above shows that swapping might not change the total profit if all prices are positive. The key is the $\max(0, \cdot)$ part.

Let's consider a case where depreciation makes profit zero.
Prices: [5, 3, 1]
$N=3$.
Sorted prices (descending): [5, 3, 1]

Greedy strategy:
Year 1 (depreciation 0): Sell 5. Profit = $\max(0, 5 - 0) = 5$.
Year 2 (depreciation 1): Sell 3. Profit = $\max(0, 3 - 1) = 2$.
Year 3 (depreciation 2): Sell 1. Profit = $\max(0, 1 - 2) = 0$.
Total profit = $5 + 2 + 0 = 7$.

What if we sell 3 in year 1, 5 in year 2, 1 in year 3?
Year 1 (depreciation 0): Sell 3. Profit = $\max(0, 3 - 0) = 3$.
Year 2 (depreciation 1): Sell 5. Profit = $\max(0, 5 - 1) = 4$.
Year 3 (depreciation 2): Sell 1. Profit = $\max(0, 1 - 2) = 0$.
Total profit = $3 + 4 + 0 = 7$.

What if we sell 1 in year 1, 3 in year 2, 5 in year 3?
Year 1 (depreciation 0): Sell 1. Profit = $\max(0, 1 - 0) = 1$.
Year 2 (depreciation 1): Sell 3. Profit = $\max(0, 3 - 1) = 2$.
Year 3 (depreciation 2): Sell 5. Profit = $\max(0, 5 - 2) = 3$.
Total profit = $1 + 2 + 3 = 6$. This is less.

The greedy strategy of sorting prices in descending order and selling the $k$-th car in the $k$-th year (with $k-1$ depreciation) seems correct. The reason is that we want to pair the largest prices with the smallest subtractions. The years $1, 2, \dots, N$ provide subtractions $0, 1, \dots, N-1$. To maximize the sum $\sum \max(0, p - \text{depreciation})$, we should pair the largest $p$ with the smallest depreciation, the second largest $p$ with the second smallest depreciation, and so on.

The modulo operation $10^9 + 7$ needs to be applied at each addition to prevent overflow.

The code implements this strategy:
1. Read the number of test cases $t$.
2. For each test case:
   a. Read the number of cars $n$.
   b. Read the $n$ initial prices into a vector `p_values`.
   c. Sort `p_values` in descending order using `std::sort(p_values.rbegin(), p_values.rend())`.
   d. Initialize `total_profit = 0` and `MOD = 1000000007`.
   e. Iterate from `year = 0` to `n-1`. This `year` variable represents the depreciation amount (0-indexed).
      i. The current initial price is `p_values[year]`.
      ii. The selling price is `current_initial_price - year`.
      iii. If `current_price > 0`, add it to `total_profit` modulo `MOD`.
      iv. If `current_price <= 0`, break the loop because all subsequent cars will also yield non-positive profit.
   f. Print `total_profit`.

The use of `std::ios_base::sync_with_stdio(false);` and `std::cin.tie(NULL);` is for optimizing I/O speed, which is common in competitive programming.

The logic seems sound. The key is the greedy choice: pair the highest initial prices with the lowest depreciation values.

## Complexity Analysis

- **Time Complexity**:
  - Reading $N$ prices: $O(N)$
  - Sorting the prices: $O(N \log N)$
  - Iterating through the sorted prices: In the worst case, we iterate through all $N$ cars, performing constant time operations for each. This is $O(N)$.
  - The dominant factor is sorting.
  - Therefore, the time complexity per test case is $O(N \log N)$.
  - For $T$ test cases, the total time complexity is $O(T \cdot N \log N)$.

- **Space Complexity**:
  - We use a vector `p_values` to store the $N$ initial prices. This requires $O(N)$ space.
  - Other variables use constant space.
  - Therefore, the space complexity per test case is $O(N)$.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // For std::sort

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        int n;
        std::cin >> n; // Read the number of cars

        // Use a vector to store initial prices
        std::vector<long long> p_values(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> p_values[i];
        }

        // Sort prices in descending order.
        // std::sort with reverse iterators (rbegin(), rend()) sorts in descending order.
        std::sort(p_values.rbegin(), p_values.rend()); 

        long long total_profit = 0;
        const long long MOD = 1000000007; // Modulo constant

        // Iterate through the sorted prices, selling one car per year.
        // 'year' represents the number of years passed since the start (0-indexed).
        // The car sold in 'year' k (0-indexed) depreciates by k units.
        // Year 1 corresponds to year=0, depreciation=0.
        // Year 2 corresponds to year=1, depreciation=1.
        // ...
        // Year N corresponds to year=N-1, depreciation=N-1.
        for (int year = 0; year < n; ++year) {
            // The current car to sell is the one with the highest remaining initial price
            // among the cars not yet sold. After sorting, this is p_values[year].
            long long current_initial_price = p_values[year];

            // Calculate the selling price after depreciation.
            // The depreciation for the car sold in the (year+1)-th year is 'year'.
            long long current_price = current_initial_price - year;

            if (current_price > 0) {
                // Add positive profit to total_profit, applying modulo.
                total_profit = (total_profit + current_price) % MOD;
            } else {
                // Optimization: If the current car (which has the highest remaining initial price)
                // yields 0 or negative profit, all subsequent cars will also yield 0 or negative profit
                // because their initial prices are less than or equal, and the 'year' (depreciation)
                // value only increases. So, we can stop.
                break;
            }
        }
        std::cout << total_profit << "\n"; // Print the maximum profit for the test case
    }
    return 0;
}
```