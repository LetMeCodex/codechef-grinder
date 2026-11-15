# [Good Quality Bulbs (BULBLIFE)](https://www.codechef.com/problems/BULBLIFE)
- **Difficulty Rating**: 846
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the minimum lifetime required for a single, unmeasured bulb, such that the average lifetime of all bulbs (including the unmeasured one) meets a specified minimum threshold.

We are given:
1. `N`: The total number of bulbs.
2. `X`: The minimum average lifetime required for all `N` bulbs.
3. `N-1` individual lifetimes of the already measured bulbs.

We need to output the minimum possible lifetime `Y` for the `N`-th bulb. A bulb's lifetime cannot be negative.

## Intuition & Mathematical Observation

Let's denote the lifetimes of the `N-1` measured bulbs as $A_1, A_2, \ldots, A_{N-1}$. Let the lifetime of the `N`-th bulb be $Y$.

The total sum of lifetimes for all `N` bulbs will be $S = A_1 + A_2 + \ldots + A_{N-1} + Y$.
Let $S_{N-1} = A_1 + A_2 + \ldots + A_{N-1}$ be the sum of lifetimes of the `N-1` measured bulbs.
So, the total sum is $S = S_{N-1} + Y$.

The average lifetime of all `N` bulbs is $\frac{S}{N}$.
The problem states that this average must be at least `X`.
Therefore, we must satisfy the condition:
$\frac{S_{N-1} + Y}{N} \ge X$

To find the *minimum* possible value for `Y`, we should aim for the equality:
$\frac{S_{N-1} + Y}{N} = X$

Now, we can solve for `Y`:
$S_{N-1} + Y = N \cdot X$
$Y = N \cdot X - S_{N-1}$

This value of `Y` represents the exact lifetime needed for the `N`-th bulb to achieve an average of exactly `X`.

However, there's a practical constraint: a bulb's lifetime cannot be negative. If the calculated `Y` from the formula above turns out to be negative (meaning the sum of the `N-1` bulbs is already high enough to meet or exceed the target average even if the last bulb has zero lifetime), then the minimum valid lifetime for `Y` is `0`.

Thus, the final minimum lifetime for the `N`-th bulb is:
$Y = \max(0, N \cdot X - S_{N-1})$

## Complexity Analysis

-   **Time Complexity**:
    For each test case, we perform the following operations:
    1. Reading `N` and `X`: $O(1)$
    2. Looping `N-1` times to read bulb lifetimes and sum them: $O(N)$
    3. Performing arithmetic calculations and printing the result: $O(1)$
    Since there are `T` test cases, the total time complexity will be $O(T \cdot N)$.
    Given `N <= 100` and `T <= 1000`, the maximum operations would be around $1000 \times 100 = 10^5$, which is very efficient and well within typical time limits.

-   **Space Complexity**:
    For each test case, we only use a few variables to store `N`, `X`, the sum of `N-1` bulbs, and intermediate calculation results. This requires a constant amount of memory.
    Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common libraries like iostream, algorithm, etc.

void solve() {
    int N; // Number of test bulbs
    int X; // Minimum average lifetime claimed
    std::cin >> N >> X;

    long long sum_A = 0; // Use long long for the sum to prevent potential overflow.
                         // For the given constraints (N <= 100, A_i <= 100),
                         // max sum_A = 99 * 100 = 9900, which fits in an int.
                         // However, using long long is a good defensive programming practice.
    for (int i = 0; i < N - 1; ++i) {
        int A_i; // Lifetime of one of the N-1 bulbs
        std::cin >> A_i;
        sum_A += A_i;
    }

    // Calculate the minimum total sum required for all N bulbs to meet the average X.
    // This is N * X.
    // Max N * X = 100 * 100 = 10000, also fits in an int, but cast to long long
    // to match sum_A's type for consistency and safety.
    long long required_total_sum = (long long)N * X; 

    // Calculate the minimum lifetime Y for the remaining bulb.
    // Y must be at least (required_total_sum - sum_A).
    long long min_Y_candidate = required_total_sum - sum_A;
    
    // The lifetime Y must also be non-negative.
    // So, the final minimum non-negative lifetime for Y is max(0, min_Y_candidate).
    // 0LL ensures that 0 is treated as a long long for the comparison.
    std::cout << std::max(0LL, min_Y_candidate) << "\n"; 
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Number of test cases
    std::cin >> T;
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0;
}
```