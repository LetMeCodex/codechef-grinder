# [Subscriptions (SUBSCRIBE_)](https://www.codechef.com/problems/SUBSCRIBE_)

- **Difficulty Rating**: 504
- **Solved in**: 1 attempt(s)

## Problem Summary
A group of $N$ friends wants to watch a show. Each subscription plan allows exactly 6 people to watch. If each subscription costs $X$ rupees, calculate the minimum total cost required to ensure all $N$ friends can watch the show.

## Intuition & Mathematical Observation
The core of the problem is to determine how many subscriptions are needed to cover $N$ people. Since each subscription covers 6 people, we need to calculate the ceiling of $N/6$.

In integer arithmetic, the ceiling division $\lceil N/K \rceil$ can be efficiently calculated using the formula:
$$\text{subscriptions} = \frac{N + K - 1}{K}$$
Substituting $K = 6$, we get:
$$\text{subscriptions} = \frac{N + 5}{6}$$

Once we have the number of subscriptions, the total cost is simply the number of subscriptions multiplied by the cost per subscription ($X$).

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since we perform a constant number of arithmetic operations, the total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N friends and each subscription covers 6 people.
 * To cover N people, we need ceil(N / 6.0) subscriptions.
 * Using integer arithmetic, ceil(N / 6) can be calculated as (N + 5) / 6.
 * The total cost is then (number of subscriptions) * X.
 * 
 * Constraints:
 * N <= 100, X <= 1000.
 * The maximum cost would be roughly (100/6 + 1) * 1000 = 17 * 1000 = 17000.
 * This fits well within a standard 32-bit integer, but using long long is safe practice.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, x;
        cin >> n >> x;

        // Calculate number of subscriptions needed
        // Using integer division: (n + 6 - 1) / 6 is the standard way to perform ceiling division
        long long subscriptions = (n + 5) / 6;

        // Calculate total cost
        long long total_cost = subscriptions * x;

        cout << total_cost << "\n";
    }

    return 0;
}
```