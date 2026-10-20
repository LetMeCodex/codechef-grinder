# [Profits (PROFIT)](https://www.codechef.com/problems/PROFIT)
- **Difficulty Rating**: 607
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem states that there are $N$ customers. The $i$-th customer is willing to pay $i$ rupees. The cost for the chef to make one lemonade is $X$ rupees. The chef wants to maximize their total profit.

## Intuition & Mathematical Observation
The chef can only make a profit from a customer if the amount the customer is willing to pay is greater than or equal to the cost of making the lemonade.

Let's consider the $i$-th customer. This customer is willing to pay $i$ rupees. The cost to make a lemonade is $X$ rupees.
- If $i < X$, the customer is willing to pay less than the cost. The chef cannot make a profit from this customer. In fact, if the chef were to sell to this customer, they would incur a loss of $X - i$. To maximize profit, the chef should not sell to such customers.
- If $i \ge X$, the customer is willing to pay at least the cost. The chef can make a profit from this customer. The profit from the $i$-th customer would be $i - X$.

To maximize the total profit, the chef should sell to every customer who is willing to pay at least $X$ rupees. These are the customers from index $X$ up to $N$.

The total profit will be the sum of profits from each of these customers:
Total Profit = $\sum_{i=X}^{N} (i - X)$

This sum can be expanded as:
Total Profit = $(X - X) + ((X+1) - X) + ((X+2) - X) + \dots + (N - X)$
Total Profit = $0 + 1 + 2 + \dots + (N - X)$

This is the sum of an arithmetic progression. The terms are $0, 1, 2, \dots, (N-X)$.
The number of terms in this series is $(N - X) - 0 + 1 = N - X + 1$.
The sum of an arithmetic series is given by: $\frac{\text{number of terms}}{2} \times (\text{first term} + \text{last term})$.

In this case:
First term = $0$
Last term = $N - X$
Number of terms = $N - X + 1$

So, the sum is:
Total Profit = $\frac{(N - X + 1)}{2} \times (0 + (N - X))$
Total Profit = $\frac{(N - X + 1)(N - X)}{2}$

However, this formula is only valid if $N \ge X$. If $N < X$, it means no customer is willing to pay at least $X$ rupees. In this scenario, the chef cannot make any profit, and the total profit is $0$.

The loop in the provided code directly implements the summation $\sum_{i=X}^{N} (i - X)$. This is a straightforward and correct approach. The loop will only execute if $X \le N$. If $X > N$, the loop condition `i <= n` will be false from the start, and `max_profit` will remain $0$, which is the correct behavior.

Let's consider the constraints. $N$ and $X$ can be up to $10^9$. The sum of profits can also be large, so `long long` is necessary for `n`, `x`, and `max_profit`. The summation approach using a loop is efficient enough because the number of iterations is at most $N - X + 1$. If $N$ is very large and $X$ is small, this could still be too slow.

Let's re-evaluate the summation:
$\sum_{i=X}^{N} (i - X)$
Let $j = i - X$. When $i = X$, $j = 0$. When $i = N$, $j = N - X$.
The sum becomes $\sum_{j=0}^{N-X} j$.
This is the sum of the first $N-X$ non-negative integers.
The formula for the sum of the first $k$ non-negative integers (i.e., $0 + 1 + \dots + k$) is $\frac{k(k+1)}{2}$.
Here, $k = N - X$.
So, the sum is $\frac{(N - X)(N - X + 1)}{2}$.

This formula is much more efficient than a loop, especially when $N$ is large and $X$ is small. The provided solution uses a loop, which might be too slow if $N-X$ is large. However, given the problem constraints and typical competitive programming platform time limits, it's possible that the test cases are designed such that $N-X$ is not excessively large, or the formulaic approach is indeed expected.

Let's check the problem constraints again. $N$ and $X$ can be up to $10^9$. A loop iterating up to $10^9$ times will definitely TLE (Time Limit Exceeded). Therefore, the mathematical formula is the intended solution.

The provided C++ code uses a loop. Let's analyze its complexity assuming the loop is the intended solution for some reason (e.g., smaller test cases).

If $N$ and $X$ are up to $10^9$, the loop `for (long long i = x; i <= n; ++i)` will iterate $N - X + 1$ times. In the worst case, $X=1$, $N=10^9$, leading to $10^9$ iterations. This will TLE.

The correct approach should use the formula:
If $N < X$, profit is $0$.
If $N \ge X$, profit is $\frac{(N - X)(N - X + 1)}{2}$.

Let's rewrite the solution using the formula.

```cpp
#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        long long n, x;
        std::cin >> n >> x;
        
        long long max_profit = 0;
        
        // If N is less than X, no customer is willing to pay at least X.
        // So, no profit can be made.
        if (n < x) {
            max_profit = 0;
        } else {
            // Customers from index X to N are willing to pay at least X.
            // The profit from customer i is i - X.
            // Total profit = sum from i=X to N of (i - X)
            // Let k = i - X. When i=X, k=0. When i=N, k=N-X.
            // The sum becomes sum from k=0 to N-X of k.
            // This is the sum of an arithmetic series: 0 + 1 + 2 + ... + (N-X)
            // The formula for sum of first m non-negative integers (0 to m) is m*(m+1)/2.
            // Here, m = N - X.
            long long m = n - x;
            max_profit = m * (m + 1) / 2;
        }
        
        std::cout << max_profit << "\n";
    }
    return 0;
}
```

The provided solution code in the prompt uses a loop. If this solution was accepted in 1 attempt, it implies that either the test cases were weak (e.g., $N-X$ was always small) or the problem setter intended for the loop solution to pass within limits for some reason. However, based on standard competitive programming practices and the given constraints ($N, X \le 10^9$), the formulaic approach is the robust and correct one.

Let's analyze the complexity of the provided loop-based solution.

## Complexity Analysis
- **Time Complexity**: $O(N - X)$ in the worst case.
    The loop iterates from $i = X$ to $N$. The number of iterations is $N - X + 1$. If $X$ is small (e.g., $1$) and $N$ is large (e.g., $10^9$), this complexity is effectively $O(N)$, which would lead to a Time Limit Exceeded (TLE) verdict on typical competitive programming platforms. However, if $N-X$ is guaranteed to be small in the test data, this might pass.
- **Space Complexity**: $O(1)$.
    The solution uses a fixed amount of extra space for variables like `t`, `n`, `x`, and `max_profit`, regardless of the input size.

If the formulaic approach were used:
- **Time Complexity**: $O(1)$.
    The calculation involves a few arithmetic operations, which take constant time.
- **Space Complexity**: $O(1)$.
    The solution uses a fixed amount of extra space for variables.

Given that the provided solution code uses a loop, I will describe the analysis for that code.

## Solution Code
```cpp
#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        long long n, x;
        std::cin >> n >> x;
        
        // The i-th customer is willing to pay Rs. i.
        // Chef's cost to make one lemonade is Rs. X.
        // Chef can only make a profit if the customer pays more than or equal to the cost.
        // So, Chef will only consider customers willing to pay at least X.
        // These are customers from index X to N (inclusive).
        // The i-th customer pays Rs. i.
        // If Chef accepts customer i, the profit from this customer is i - X.
        // To maximize profit, Chef should accept all customers from X to N,
        // as long as X <= N. If X > N, no customer is willing to pay at least X.
        
        long long max_profit = 0;
        
        // Iterate through customers who are willing to pay at least X.
        // These are customers with willingness to pay from X up to N.
        // The customer index is 1-based, and willingness to pay is equal to the index.
        // So, customers from index X to N are relevant.
        for (long long i = x; i <= n; ++i) {
            // If the customer is willing to pay at least X, Chef can make a profit.
            // The profit from this customer is i - X.
            // We sum up the profits from all such customers.
            max_profit += (i - x);
        }
        
        std::cout << max_profit << "\n";
    }
    return 0;
}
```