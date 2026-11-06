# [Pintu and Fruits (CHPINTU)](https://www.codechef.com/problems/CHPINTU)
- **Difficulty Rating**: 1313
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the minimum total cost among all available fruit types. We are given `N` baskets. For each basket `i`, we know its fruit type `F[i]` and its cost `P[i]`. We need to:
1. Group all baskets by their fruit type.
2. For each unique fruit type, calculate the sum of costs of all baskets containing that fruit type.
3. Find the minimum among these calculated total costs for all fruit types that actually appear in the baskets.

## Intuition & Mathematical Observation

The core idea is to aggregate costs based on fruit types. Since fruit types are integers from 1 to `M`, we can use arrays to efficiently store and retrieve information.

1.  **Aggregation**: We need a way to store the total cost for each fruit type. A `vector<long long> type_costs` of size `M+1` (to accommodate types from 1 to `M`) initialized to zeros is suitable. As we iterate through the `N` baskets, for each basket `i` with fruit type `F[i]` and cost `P[i]`, we simply add `P[i]` to `type_costs[F[i]]`.

2.  **Tracking Appeared Types**: It's important to only consider fruit types that actually appear in at least one basket. If a fruit type `k` doesn't appear, its `type_costs[k]` would remain 0, and this might incorrectly be chosen as the minimum if not handled. We can use a `vector<bool> appeared` of size `M+1` to mark `true` for any fruit type `k` that has at least one basket.

3.  **Finding the Minimum**: After processing all `N` baskets, `type_costs[k]` will hold the total cost for fruit type `k`. We then iterate from `k = 1` to `M`. For each `k`, if `appeared[k]` is `true`, we compare `type_costs[k]` with our current minimum total cost found so far and update it if `type_costs[k]` is smaller. We initialize our minimum with a very large value (e.g., `LLONG_MAX`) to ensure any valid total cost will be smaller.

This approach directly addresses the problem by first accumulating costs per type and then finding the minimum among the relevant types.

## Complexity Analysis

Let `N` be the number of baskets and `M` be the maximum possible fruit type.

*   **Time Complexity**:
    *   Reading `N` and `M`: $O(1)$
    *   Reading `F` array: $O(N)$
    *   Reading `P` array: $O(N)$
    *   Initializing `type_costs` and `appeared` vectors of size `M+1`: $O(M)$
    *   First loop to aggregate costs and mark appeared types (iterates `N` times): $O(N)$
    *   Second loop to find the minimum total cost (iterates `M` times): $O(M)$
    *   Total time complexity: $O(1) + O(N) + O(N) + O(M) + O(N) + O(M) = \mathbf{O(N + M)}$.

*   **Space Complexity**:
    *   `F` vector: $O(N)$
    *   `P` vector: $O(N)$
    *   `type_costs` vector: $O(M)$
    *   `appeared` vector: $O(M)$
    *   Total space complexity: $O(N) + O(N) + O(M) + O(M) = \mathbf{O(N + M)}$.

Given the constraints ($N, M \le 10^5$), an $O(N+M)$ solution is highly efficient and well within typical time limits. The maximum sum for a fruit type ($10^5$ baskets * $100$ cost/basket = $10^7$) fits comfortably within a `long long` (and even an `int` in C++).

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, vector, algorithm, limits, etc.

// Using namespace std as requested by problem statement
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;

    vector<int> F(N);
    for (int i = 0; i < N; ++i) {
        cin >> F[i];
    }

    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }

    // type_costs[k] will store the total cost for fruit type k
    // Using long long just to be safe, though int is sufficient given constraints (max sum 2500 * 100 = 2.5 * 10^5, actually N * max_P = 10^5 * 100 = 10^7)
    // int is sufficient as INT_MAX is ~2*10^9, but long long is safer practice.
    vector<long long> type_costs(M + 1, 0);
    // appeared[k] will be true if at least one basket of type k exists
    vector<bool> appeared(M + 1, false);

    // Aggregate costs and mark appeared fruit types
    for (int i = 0; i < N; ++i) {
        type_costs[F[i]] += P[i];
        appeared[F[i]] = true;
    }

    long long min_total_cost = LLONG_MAX; // Initialize with maximum possible long long value

    // Iterate through all possible fruit types from 1 to M
    for (int k = 1; k <= M; ++k) {
        // Only consider fruit types that actually appear in at least one basket
        if (appeared[k]) {
            min_total_cost = min(min_total_cost, type_costs[k]);
        }
    }

    cout << min_total_cost << "\n";
}

int main() {
    // Fast I/O as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
```