# [Gotta Catch Em All (GCEA)](https://www.codechef.com/problems/GCEA)
- **Difficulty Rating**: 898
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the minimum total cost to catch `N` Pekómons. For each Pekómon `i`, we are given a value `A_i`, which represents the number of Normal Pekóballs required to catch it. We have two options for catching each Pekómon:

1.  **Normal Pekóballs**: Each Normal Pekóball costs `X` coins. To catch Pekómon `i`, we would need `A_i` Normal Pekóballs, incurring a cost of `A_i * X`.
2.  **Master Pekóballs**: Each Master Pekóball costs `Y` coins. A single Master Pekóball can catch any Pekómon, regardless of its `A_i` value. So, using a Master Pekóball for Pekómon `i` incurs a cost of `Y`.

We need to make an independent decision for each of the `N` Pekómons (either use Normal Pekóballs or a Master Pekóball) such that the total cost to catch all of them is minimized.

## Intuition & Mathematical Observation

The key insight here is that the decision for one Pekómon does not affect the options or costs for any other Pekómon. The costs `X` and `Y` are constant for all Pekómons. This means we can make the optimal choice for each Pekómon independently.

For any given Pekómon `i`:
*   The cost of catching it using Normal Pekóballs is `A_i * X`.
*   The cost of catching it using a Master Pekóball is `Y`.

To minimize the cost for Pekómon `i`, we should simply choose the cheaper of these two options. Therefore, the minimum cost to catch Pekómon `i` is `min(A_i * X, Y)`.

The total minimum cost to catch all `N` Pekómons will be the sum of these individual minimum costs for each Pekómon.
Mathematically, the total cost `C` can be expressed as:
$$ C = \sum_{i=1}^{N} \min(A_i \cdot X, Y) $$

This greedy approach works because there are no interdependencies or global constraints that would make choosing a more expensive option for one Pekómon beneficial for another.

Regarding data types:
The maximum values for `N`, `A_i`, `X`, `Y` are 100.
*   `A_i * X` can be at most `100 * 100 = 10,000`.
*   `Y` can be at most `100`.
*   The `min` of these two will be at most `10,000`.
*   The `total_cost` (sum over `N` Pekómons) can be at most `100 * 10,000 = 1,000,000`.
All these values fit comfortably within a standard 32-bit integer (`int`). However, it's a common and good practice in competitive programming to use `long long` for sums and products to prevent potential overflow issues, especially if constraints were slightly larger (e.g., `A_i` or `X` up to `10^5`). The provided solution follows this safe practice.

## Complexity Analysis

*   **Time Complexity**: $O(N)$
    *   For each test case, we iterate through `N` Pekómons. Inside the loop, we perform a constant number of operations (reading `A_i`, two multiplications, one comparison, one addition).
    *   Therefore, the time complexity for a single test case is $O(N)$.
    *   Given `T` test cases, the total time complexity is $O(T \cdot N)$.
    *   With `T` up to 100 and `N` up to 100, the maximum operations would be around `100 * 100 = 10,000`, which is very efficient and well within typical time limits.

*   **Space Complexity**: $O(1)$
    *   We only use a few variables to store `N`, `X`, `Y`, `A_i`, and `total_cost`. These variables consume a constant amount of memory regardless of the input size `N`.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, algorithm, etc.

// Using namespace std; as requested by problem instructions.
using namespace std;

void solve() {
    int N;
    // X and Y can be int based on constraints (max 100), but using long long for consistency with total_cost
    // and general competitive programming practice to avoid potential overflow issues, especially with products.
    long long X, Y; 
    cin >> N >> X >> Y;

    long long total_cost = 0; // Use long long for total_cost to prevent overflow.
                              // Max total_cost is 100 * 100 = 10000, which fits in int.
                              // But following the general instruction "use long long in C++" for sums.

    for (int i = 0; i < N; ++i) {
        int A_i; // A_i is max 100, fits in int.
        cin >> A_i;

        // Calculate cost using Normal Pekóballs.
        // Cast A_i to long long before multiplication to ensure the product is long long,
        // even though A_i * X (100 * 100 = 10000) fits in int. This is a safe practice.
        long long cost_normal = (long long)A_i * X; 
        
        // Cost using a Master Pekóball is simply Y.
        long long cost_master = Y;

        // Add the minimum of the two options to the total cost.
        total_cost += min(cost_normal, cost_master);
    }

    cout << total_cost << "\n";
}

int main() {
    // Fast I/O setup as requested.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases.
    while (T--) { // Loop through each test case.
        solve();
    }

    return 0;
}
```