# [Janmansh at Fruit Market (JMARKET)](https://www.codechef.com/problems/JMARKET)
- **Difficulty Rating**: 947
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the minimum cost to buy a total of `X` fruits. We are given three different kinds of fruits with prices `A`, `B`, and `C`. The crucial constraint is that we must buy *at least two different kinds* of fruits.

## Intuition & Mathematical Observation

To minimize the total cost, we should always prioritize buying fruits with the lowest available prices. Let's denote the three given prices as $P_A, P_B, P_C$.

1.  **Sort the Prices**: The first step is to sort the prices `A`, `B`, and `C` in ascending order. Let the sorted prices be $P_1, P_2, P_3$, where $P_1 \le P_2 \le P_3$.
    *   $P_1$ is the minimum price.
    *   $P_2$ is the second minimum price.
    *   $P_3$ is the maximum price.

2.  **Satisfying the "At Least Two Kinds" Constraint**: To meet the requirement of buying at least two different kinds of fruits while minimizing cost, we must select fruits corresponding to the two cheapest prices available. That is, we must buy at least one fruit of the kind with price $P_1$ and at least one fruit of the kind with price $P_2$. Buying any fruit of the kind with price $P_3$ would be suboptimal, as we could always replace it with a fruit of price $P_1$ or $P_2$ (which are cheaper or equal) and still satisfy the distinct kinds constraint.

3.  **Strategy for Minimum Cost**:
    *   We need to buy a total of `X` fruits.
    *   To ensure we have at least two different kinds ($P_1$ and $P_2$) and minimize cost, we can adopt the following strategy:
        *   Buy **one** fruit of the second cheapest kind (price $P_2$). This costs $P_2$. This guarantees one of the two required distinct kinds.
        *   We now have `X - 1` fruits remaining to buy. To minimize the cost for these remaining fruits, we should buy all of them from the cheapest kind (price $P_1$). This costs $(X - 1) \times P_1$.

4.  **Total Minimum Cost**:
    The total minimum cost will be the sum of these two parts:
    $ \text{Total Cost} = (X - 1) \times P_1 + P_2 $

This strategy guarantees:
*   A total of $(X-1) + 1 = X$ fruits are bought.
*   At least two different kinds of fruits are bought (one with price $P_1$, one with price $P_2$). The problem implies that fruits with prices A, B, C are distinct types, even if their numerical prices might be identical.
*   The cost is minimized because we exclusively use the two cheapest prices ($P_1$ and $P_2$), and for the majority of fruits (`X-1`), we use the absolute cheapest price $P_1$.

The problem statement guarantees `X >= 2`, which ensures that `X-1 >= 1`, so we always buy at least one fruit of kind $P_1$ and one fruit of kind $P_2$.

## Complexity Analysis

*   **Time Complexity**:
    *   Reading input `X, A, B, C`: $O(1)$.
    *   Storing prices in a vector of size 3: $O(1)$.
    *   Sorting a vector of 3 elements: `std::sort` on a fixed small number of elements (3 in this case) takes $O(1)$ time.
    *   Calculating the total cost and printing: $O(1)$.
    *   The `solve()` function performs constant time operations. Since `solve()` is called `T` times (for `T` test cases), the overall time complexity is $O(T)$.
    *   Therefore, the **Time Complexity is $O(T)$**.

*   **Space Complexity**:
    *   Storing variables `X, A, B, C`: $O(1)$.
    *   Storing the `prices` vector of size 3: $O(1)$.
    *   No other significant data structures are used.
    *   Therefore, the **Space Complexity is $O(1)$**.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, vector, algorithm, etc.

// Using namespace std; is requested
using namespace std;

void solve() {
    int X, A, B, C;
    cin >> X >> A >> B >> C; // Read X, A, B, C

    // Store prices in a vector to easily sort them
    vector<int> prices = {A, B, C};
    
    // Sort the prices in ascending order.
    // After sorting:
    // prices[0] will be the minimum price (let's call it P1).
    // prices[1] will be the second minimum price (let's call it P2).
    // prices[2] will be the maximum price (let's call it P3).
    sort(prices.begin(), prices.end());

    // The problem requires buying a total of X fruits and having at least 2 different kinds of fruits.
    // To minimize the total cost, we should always prioritize buying fruits with the lowest prices.
    //
    // To satisfy the "at least 2 different kinds" constraint with minimum cost, we must buy
    // at least one fruit of the cheapest kind (price P1) and at least one fruit of the
    // second cheapest kind (price P2).
    //
    // Strategy to achieve minimum cost:
    // 1. Buy one fruit of the second cheapest kind (price `prices[1]`).
    //    This ensures one of the two required distinct kinds is present.
    // 2. Buy the remaining `X-1` fruits of the cheapest kind (price `prices[0]`).
    //    Since `X >= 2`, `X-1 >= 1`, so this ensures at least one fruit of the cheapest kind
    //    is present.
    //
    // This strategy guarantees:
    // - A total of `(X-1) + 1 = X` fruits are bought.
    // - At least two different kinds of fruits are bought (one with price `prices[0]`, one with price `prices[1]`).
    //   The problem states "three different kinds of fruits with prices A, B and C", implying
    //   A, B, C refer to distinct types even if their prices are identical. So, picking
    //   the types corresponding to `prices[0]` and `prices[1]` satisfies the distinct kinds requirement.
    // - The cost is minimized because we are using the two cheapest prices, and for the bulk
    //   of fruits (`X-1`), we use the absolute cheapest price `prices[0]`.
    //
    // Total cost = (cost of X-1 fruits at P1) + (cost of 1 fruit at P2)
    //            = (X - 1) * prices[0] + prices[1]
    
    // Use long long for total_cost to prevent potential integer overflow,
    // although for the given constraints (X <= 1000, prices <= 100),
    // the maximum cost (999 * 100 + 100 = 100000) would fit in a standard int.
    long long total_cost = (long long)(X - 1) * prices[0] + prices[1];
    
    // Output the calculated minimum cost, followed by a newline
    cout << total_cost << "\n"; 
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times, decrementing T each iteration
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful program execution
}
```