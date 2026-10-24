# [Make Money (MAKEMONEY)](https://www.codechef.com/problems/MAKEMONEY)
- **Difficulty Rating**: 1101
- **Solved in**: 1 attempt(s)

## Problem Summary

You are given `N` bags, and each bag `i` initially contains `A_i` coins. You also have two parameters: `X` and `C`.
`X` represents a maximum limit of coins. `C` represents the cost of an operation.

For each bag, you have two choices:
1. Do nothing: The bag retains its `A_i` coins.
2. Perform an operation: Pay `C` coins, and the bag's coin count becomes `X`. This operation can be performed at most once per bag.

Your goal is to maximize the total number of coins you have after making a choice for each of the `N` bags.

## Intuition & Mathematical Observation

The key insight here is that the decision for one bag is completely independent of the decisions for other bags. The operation cost `C` is fixed, and the target value `X` is also fixed. There are no dependencies or global constraints that link the choices for different bags (e.g., a limited number of operations in total, or operations affecting other bags).

Therefore, to maximize the total coins, we should make the locally optimal choice for each individual bag. For any given bag `i` with `A_i` coins, we have two options:

1.  **Do nothing**: The bag contributes `A_i` coins to our total.
2.  **Perform operation**: We pay `C` coins, and the bag's value becomes `X`. So, the net contribution from this bag is `X - C`.

To maximize our total, for each bag `i`, we simply choose the option that yields a higher value. This means the contribution from bag `i` will be `max(A_i, X - C)`.

The total maximum value will then be the sum of these maximum contributions for all `N` bags:
$$ \text{Total Max Coins} = \sum_{i=1}^{N} \max(A_i, X - C) $$

This greedy approach works because of the independence of choices for each bag.

## Complexity Analysis

*   **Time Complexity**: $O(N)$ per test case.
    *   We iterate through `N` bags once. For each bag, we perform a constant number of operations (read `A_i`, calculate `max`, add to sum).
    *   Given `T` test cases, the total time complexity will be $O(T \cdot N)$.
    *   With $T \le 100$ and $N \le 100$, the maximum operations would be around $100 \times 100 = 10^4$, which is very efficient and well within typical time limits.

*   **Space Complexity**: $O(1)$ per test case.
    *   We only use a few variables to store `N`, `X`, `C`, `A_i`, `total_max_value`, and `operation_net_value`. No data structures that scale with `N` are used.

## Solution Code

```cpp
#include <bits/stdc++.h> // Standard header for competitive programming, includes iostream, algorithm, etc.

// Using the standard namespace as per problem instructions.
using namespace std;

// Function to solve a single test case.
void solve() {
    int N; // Number of bags
    int X; // Maximum limit of coins on each bag
    int C; // Cost of performing one operation

    // Read N, X, C for the current test case.
    cin >> N >> X >> C;

    long long total_max_value = 0; // Variable to store the sum of maximum values.
                                   // Using long long to prevent potential overflow,
                                   // though for given constraints (N*X <= 100*100 = 10000),
                                   // int would likely suffice on most systems. It's good practice
                                   // to use long long for sums to be safe.

    // Calculate the threshold value.
    // If we perform an operation on a bag, its coins become X, and we pay C.
    // So, the net value contributed by that bag to the objective function is X - C.
    // If we don't perform an operation, the bag contributes A_i.
    // We choose the option that yields a higher value.
    int operation_net_value = X - C;

    // Iterate through each bag.
    for (int i = 0; i < N; ++i) {
        int A_i; // Coins in the i-th bag
        cin >> A_i; // Read the coins in the current bag.

        // For each bag, we decide whether to perform an operation or not.
        // If we perform an operation, the bag contributes 'operation_net_value' (X - C).
        // If we don't perform an operation, the bag contributes 'A_i'.
        // We pick the maximum of these two options for each bag.
        total_max_value += max(A_i, operation_net_value);
    }

    // Output the total maximum value for the current test case.
    cout << total_max_value << "\n";
}

// Main function to handle multiple test cases.
int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T; // Read the number of test cases.

    // Loop through each test case.
    while (T--) {
        solve(); // Call the solve function for each test case.
    }

    return 0; // Indicate successful execution.
}
```