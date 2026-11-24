# [Skip one (SKIPONE)](https://www.codechef.com/problems/SKIPONE)
- **Difficulty Rating**: 1182
- **Solved in**: 3 attempt(s)

## Problem Summary

The problem asks us to find the maximum number of items we can buy from a given list of `N` items, `A[0], A[1], ..., A[N-1]`, with a total budget `K`. The items must be bought in their given order, meaning we can only choose a prefix `A[0], ..., A[i]` for some `i`. The special rule is that when we buy a set of items, the most expensive item among them is free. We need to maximize the count of items purchased.

## Intuition & Mathematical Observation

1.  **Prefix-based Selection**: The problem explicitly states that items must be bought in their given order. This means we are always considering a prefix of the array `A`, i.e., `A[0], A[1], ..., A[i]` for some `i`.

2.  **Effective Cost Calculation**: For any given prefix `A[0], ..., A[i]`, the total cost of these `i+1` items would normally be `sum(A[0]...A[i])`. However, the most expensive item in this prefix is free. So, the actual cost we pay (the "effective cost") is `sum(A[0]...A[i]) - max(A[0]...A[i])`.

3.  **Monotonicity**: Let's observe how the effective cost changes as we extend the prefix.
    When we move from considering `A[0]...A[i]` to `A[0]...A[i+1]`:
    *   The `current_sum` (sum of all items in the prefix) will always increase by `A[i+1]` (since `A[i+1] >= 1`).
    *   The `max_val_in_prefix` (maximum item cost in the prefix) will either increase (if `A[i+1]` is greater than the previous maximum) or stay the same.
    
    Consider the effective cost: `effective_cost = current_sum - max_val_in_prefix`.
    Since `current_sum` is non-decreasing and `max_val_in_prefix` is also non-decreasing, it can be shown that the `effective_cost` is also non-decreasing as we extend the prefix.
    
    *Proof Sketch*:
    Let `S_i = sum(A[0]...A[i])` and `M_i = max(A[0]...A[i])`.
    `Effective_cost(i) = S_i - M_i`.
    `Effective_cost(i+1) = S_{i+1} - M_{i+1} = (S_i + A[i+1]) - max(M_i, A[i+1])`.
    
    Case 1: `A[i+1] <= M_i`. Then `max(M_i, A[i+1]) = M_i`.
    `Effective_cost(i+1) = (S_i + A[i+1]) - M_i = (S_i - M_i) + A[i+1] = Effective_cost(i) + A[i+1]`.
    Since `A[i+1] >= 1`, `Effective_cost(i+1) > Effective_cost(i)`.
    
    Case 2: `A[i+1] > M_i`. Then `max(M_i, A[i+1]) = A[i+1]`.
    `Effective_cost(i+1) = (S_i + A[i+1]) - A[i+1] = S_i`.
    Since `M_i >= 1`, `S_i = (S_i - M_i) + M_i = Effective_cost(i) + M_i`.
    So, `Effective_cost(i+1) = Effective_cost(i) + M_i`.
    Since `M_i >= 1`, `Effective_cost(i+1) > Effective_cost(i)`.
    
    In both cases, `Effective_cost(i+1) >= Effective_cost(i)`. This confirms the non-decreasing property.

4.  **Greedy Strategy**: Because the effective cost is non-decreasing, if we can afford `i+1` items, we might be able to afford `i+2` items. However, if we *cannot* afford `i+1` items (i.e., `effective_cost > K`), then we definitely cannot afford `i+2` or more items, as their effective cost would be even higher. This allows for a simple linear scan:
    *   Iterate through the array `A` from left to right, extending the prefix one item at a time.
    *   Maintain `current_sum` and `max_val_in_prefix` for the current prefix.
    *   Calculate the `effective_cost`.
    *   If `effective_cost <= K`, we can afford these items, so we update our answer to the current count of items (`i+1`).
    *   If `effective_cost > K`, we cannot afford these items, and due to the monotonicity, we cannot afford any longer prefixes either. So, we break the loop.

This greedy approach correctly finds the maximum number of items.

## Complexity Analysis

*   **Time Complexity**: $O(N)$ per test case. We iterate through the input array `A` once. Inside the loop, all operations (addition, `std::max`, comparison) take constant time. Given `T` test cases, the total time complexity is $O(T \cdot N)$.
    With $N \le 2 \cdot 10^5$ and $T \le 10$, $T \cdot N \approx 2 \cdot 10^6$, which is well within typical time limits.

*   **Space Complexity**: $O(N)$ per test case. We use a `std::vector<int> A` to store the input item costs. All other variables (`current_sum`, `ans`, `max_val_in_prefix`, `K`, `N`, `t`) use constant additional space.

## Solution Code

```cpp
#include <iostream> // For standard input/output operations
#include <vector>   // For std::vector
#include <algorithm> // For std::max

// Function to solve a single test case
void solve() {
    int N;
    long long K; // K can be up to 10^9, so long long is appropriate
    std::cin >> N >> K;
    std::vector<int> A(N); // Item costs
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    long long current_sum = 0; // Sum of costs of items A[0]...A[i], can be up to 2*10^9 (N * max_A_i)
    int ans = 0; // Maximum number of items that can be bought
    int max_val_in_prefix = 0; // Stores the maximum cost among A[0]...A[i]

    for (int i = 0; i < N; ++i) {
        current_sum += A[i]; // Add current item's cost to the running sum

        // Update the maximum value seen so far in the prefix A[0]...A[i]
        // Since A_i >= 1, initializing max_val_in_prefix to 0 is safe.
        max_val_in_prefix = std::max(max_val_in_prefix, A[i]);
        
        // Calculate the effective cost: total sum minus the cost of the most expensive item (which is made free)
        long long effective_cost = current_sum - max_val_in_prefix;

        if (effective_cost <= K) {
            // If we can afford these i+1 items, update the answer.
            // i is 0-indexed, so i+1 gives the count of items.
            ans = i + 1;
        } else {
            // If we cannot afford these i+1 items, we cannot afford any more items
            // because the effective cost is non-decreasing. So, we break the loop.
            break;
        }
    }
    std::cout << ans << "\n"; // Output the maximum number of items
}

int main() {
    // Fast I/O setup
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        solve(); // Solve each test case
    }
    return 0;
}

```