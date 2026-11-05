# [Bakery Problem (BAKERY7)](https://www.codechef.com/problems/BAKERY7)
- **Difficulty Rating**: 284
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to calculate the minimum cost to buy `N` cakes. There are two pricing options available:
1.  **Without Bribe**: Each cake costs 100 rupees.
2.  **With Bribe**: Pay a one-time bribe of `K` rupees, and then each cake costs 60 rupees.

We need to determine which option results in a lower total cost and output that minimum cost.

## Intuition & Mathematical Observation
The problem presents a straightforward choice between two distinct cost structures. To find the minimum total cost, we simply need to calculate the total cost for each option and then pick the smaller of the two.

Let's define the costs mathematically:

1.  **Cost without bribe**: If we choose not to bribe, we pay 100 rupees for each of the `N` cakes.
    Total Cost (No Bribe) = `N * 100`

2.  **Cost with bribe**: If we choose to bribe, we first pay a fixed amount `K` for the bribe, and then 60 rupees for each of the `N` cakes.
    Total Cost (With Bribe) = `K + (N * 60)`

The minimum total cost will be the minimum of these two values:
`Minimum Total Cost = min(Total Cost (No Bribe), Total Cost (With Bribe))`
`Minimum Total Cost = min(N * 100, K + N * 60)`

This approach directly translates into a simple comparison and selection, requiring no complex algorithms or data structures.

## Complexity Analysis
-   **Time Complexity**: $O(1)$
    The program performs a fixed number of operations regardless of the input values `N` and `K`. These operations include reading two integers, two multiplications, one addition, one comparison (`min`), and one output operation. All these operations take constant time. Therefore, the overall time complexity is constant.

-   **Space Complexity**: $O(1)$
    The program uses a few integer variables (`N`, `K`, `cost_no_bribe`, `cost_with_bribe`, `min_total_cost`) to store input and intermediate results. The amount of memory used by these variables is constant and does not depend on the size or values of the input `N` and `K`. Thus, the space complexity is constant.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes common headers like iostream, algorithm, etc.

using namespace std; // Allows using standard library components without std:: prefix

int main() {
    // Optimize C++ standard streams for competitive programming.
    // Unties cin/cout from C's stdio, and unties cin from cout.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare variables to store input N (number of cakes) and K (bribe amount).
    // Given constraints (N <= 10, K <= 1000), int is sufficient for all calculations.
    int N, K;

    // Read N and K from standard input.
    cin >> N >> K;

    // Calculate the total cost if we choose NOT to bribe Chef's son.
    // In this scenario, each cake costs 100 rupees.
    int cost_no_bribe = N * 100;

    // Calculate the total cost if we choose to bribe Chef's son.
    // We pay K rupees once for the bribe, and then each cake costs 60 rupees.
    int cost_with_bribe = K + (N * 60);

    // The minimum cost is the smaller of the two calculated options.
    int min_total_cost = min(cost_no_bribe, cost_with_bribe);

    // Output the minimum total cost followed by a newline character.
    cout << min_total_cost << "\n";

    return 0; // Indicate successful program execution.
}
```