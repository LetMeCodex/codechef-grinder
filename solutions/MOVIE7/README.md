# Movie (MOVIE7)
- **Difficulty Rating**: 576
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to find the minimum cost to obtain $N$ movie tickets and $M$ popcorns. We have three options for purchasing:
1. Buy a ticket individually at cost $A$.
2. Buy a popcorn individually at cost $B$.
3. Buy a combo pack (one ticket and one popcorn) at cost $C$.

We are given that $max(A, B) < C \le A + B$.

## Intuition & Mathematical Observation

The core of this problem lies in understanding the cost-effectiveness of the combo pack. The condition $max(A, B) < C \le A + B$ provides crucial insights:

1.  **$C > max(A, B)$**: This means a combo pack is always more expensive than buying *either* a ticket or a popcorn individually. This might initially suggest avoiding combo packs.
2.  **$C \le A + B$**: This means a combo pack is *not more expensive* than buying a ticket and a popcorn separately. In fact, if $C < A + B$, it's cheaper to buy a combo than to buy both items individually.

Let's consider how many combo packs we can form. If we decide to buy $k$ combo packs, we will use $k$ tickets and $k$ popcorns. The cost for these $k$ combo packs is $k \times C$.
After buying $k$ combo packs, we will still need to acquire $N - k$ tickets and $M - k$ popcorns. These remaining items must be bought individually. The cost for these remaining items will be $(N - k) \times A + (M - k) \times B$.

The total cost for buying $k$ combo packs and then the remaining items individually is:
$Total Cost(k) = k \times C + (N - k) \times A + (M - k) \times B$

Let's expand this expression:
$Total Cost(k) = k \times C + N \times A - k \times A + M \times B - k \times B$
$Total Cost(k) = (N \times A + M \times B) + k \times (C - A - B)$

We want to minimize $Total Cost(k)$. The term $(N \times A + M \times B)$ is a constant base cost if we were to buy everything individually. The variable part is $k \times (C - A - B)$.

From the problem constraint, we know that $C \le A + B$. This implies that $(C - A - B) \le 0$.

*   If $(C - A - B) < 0$ (i.e., $C < A + B$), then to minimize the total cost, we need to maximize the value of $k$ because we are multiplying a negative number by $k$.
*   If $(C - A - B) = 0$ (i.e., $C = A + B$), then the term $k \times (C - A - B)$ becomes $0$, and the total cost is always $N \times A + M \times B$, regardless of $k$.

In both cases, to minimize the total cost, we should maximize $k$.
The number of combo packs, $k$, cannot exceed the number of tickets $N$ or the number of popcorns $M$. Therefore, the maximum possible value for $k$ is $min(N, M)$.

So, the optimal strategy is to buy as many combo packs as possible, which is $min(N, M)$ combo packs, and then buy any remaining tickets or popcorns individually.

Let $k_{max} = min(N, M)$.
The number of combo packs bought is $k_{max}$.
The number of tickets remaining is $N - k_{max}$.
The number of popcorns remaining is $M - k_{max}$.

The minimum cost will be:
$Min Cost = k_{max} \times C + (N - k_{max}) \times A + (M - k_{max}) \times B$

Let's verify this with an example. Suppose $N=3, M=2, A=10, B=12, C=20$.
Here, $max(A, B) = 12 < C=20 \le A+B=22$.
$min(N, M) = min(3, 2) = 2$.
Optimal strategy: Buy 2 combo packs.
Cost of combo packs = $2 \times C = 2 \times 20 = 40$.
Remaining tickets = $N - 2 = 3 - 2 = 1$. Cost = $1 \times A = 1 \times 10 = 10$.
Remaining popcorns = $M - 2 = 2 - 2 = 0$. Cost = $0 \times B = 0$.
Total cost = $40 + 10 + 0 = 50$.

Using the formula:
$Min Cost = min(3, 2) \times C + (3 - min(3, 2)) \times A + (2 - min(3, 2)) \times B$
$Min Cost = 2 \times 20 + (3 - 2) \times 10 + (2 - 2) \times 12$
$Min Cost = 40 + 1 \times 10 + 0 \times 12$
$Min Cost = 40 + 10 + 0 = 50$.

This confirms our derived strategy.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The solution involves a fixed number of arithmetic operations and comparisons for each test case. The input values $N, M, A, B, C$ do not affect the number of operations performed, only the values of the calculations.

-   **Space Complexity**: $O(1)$
    The solution uses a constant amount of extra space to store variables like $t, n, m, a, b, c$, and the calculated minimum cost. This space requirement does not grow with the input size.

## Solution Code

```cpp
#include <iostream>
#include <algorithm>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        long long n, m, a, b, c;
        // Read input values for tickets, popcorns, individual ticket cost,
        // individual popcorn cost, and combo pack cost.
        std::cin >> n >> m >> a >> b >> c;
        
        // The optimal strategy is to maximize the use of combo packs.
        // A combo pack provides one ticket and one popcorn.
        // We can form at most min(N, M) combo packs, as we are limited by
        // the smaller quantity of either tickets or popcorns needed.
        
        // Calculate the maximum number of combo packs we can form.
        long long num_combos = std::min(n, m);
        
        // Calculate the number of remaining tickets and popcorns after forming combo packs.
        // If N >= M, we use M combo packs, leaving N-M tickets.
        // If M > N, we use N combo packs, leaving M-N popcorns.
        long long remaining_tickets = n - num_combos;
        long long remaining_popcorn = m - num_combos;
        
        // Calculate the total minimum cost:
        // Cost of combo packs + Cost of remaining tickets + Cost of remaining popcorns.
        long long min_cost = num_combos * c + remaining_tickets * a + remaining_popcorn * b;
        
        // Output the calculated minimum cost for the current test case.
        std::cout << min_cost << "\n";
    }
    return 0;
}

```