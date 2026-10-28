# [Double Discount (DBDISC)](https://www.codechef.com/problems/DBDISC)
- **Difficulty Rating**: 994
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to help Chef select exactly two distinct food items from a list of `N` available items. Each item `i` has a cost `A_i` and a tastiness `B_i`. Chef has a budget `K`.

There's a special discount rule:
1.  Identify the more expensive and the less expensive item among the two chosen.
2.  The less expensive item is purchased at its full price.
3.  The more expensive item receives a discount. The discount amount is the minimum of:
    *   50% of its original cost.
    *   100 rupees.
    (Note: `A_i` are guaranteed to be even, so 50% of cost will always be an integer).
4.  Chef wants to maximize the total tastiness of the two items he buys, while staying within his budget `K`. If no pair of items can be bought within the budget, the maximum tastiness is 0.

## Intuition & Mathematical Observation

The core of this problem lies in correctly calculating the total cost for any pair of items, applying the specific discount rule, and then checking if this total cost is within Chef's budget `K`. Since we need to find the *maximum* tastiness, we must explore all possible valid pairs of items.

Here's the breakdown of the intuition and observations:

1.  **Iterating through Pairs**: We need to select *exactly two distinct* items. This immediately suggests using nested loops. The outer loop can pick the first item (let's say at index `i`), and the inner loop can pick the second item (at index `j`). To ensure we pick distinct items and avoid processing the same pair twice (e.g., (item 0, item 1) is the same as (item 1, item 0)), the inner loop should always start from `i + 1`. This way, `j` is always greater than `i`, guaranteeing distinct items and unique pairs.

2.  **Applying the Discount**: For any chosen pair `(item_i, item_j)`:
    *   Let `cost1 = A[i]` and `cost2 = A[j]`.
    *   We need to determine which one is more expensive and which is less expensive. We can use `std::max` and `std::min` for this:
        *   `C_max = std::max(cost1, cost2)`
        *   `C_min = std::min(cost1, cost2)`
    *   The discount applies *only* to `C_max`.
    *   The discount amount is calculated as `std::min(C_max / 2, 100)`. Since `A_i` values are even, `C_max / 2` will always be an integer, simplifying calculations.
    *   The effective cost of the more expensive item after discount is `effective_C_max = C_max - discount`.
    *   The total cost for the pair is `total_cost = C_min + effective_C_max`.

3.  **Calculating Total Tastiness**: The total tastiness for a pair `(item_i, item_j)` is simply the sum of their individual tastiness values: `total_tastiness = B[i] + B[j]`.

4.  **Maximization and Budget Check**:
    *   We'll maintain a variable, `max_tastiness`, initialized to `0` (as tastiness values are non-negative, and 0 is the required output if no pair fits the budget).
    *   For each pair `(item_i, item_j)`:
        *   Calculate its `total_cost` and `total_tastiness` as described above.
        *   If `total_cost <= K` (i.e., the pair is affordable), we update `max_tastiness = std::max(max_tastiness, total_tastiness)`.

By following these steps, we systematically check every possible distinct pair, correctly apply the discount, and find the maximum tastiness achievable within the budget.

## Complexity Analysis

*   **Time Complexity**:
    *   Reading `N`, `K`, and the two arrays `A` and `B` (each of size `N`) takes $O(N)$ time.
    *   The core logic involves two nested loops to iterate through all unique pairs of items.
        *   The outer loop runs `N` times (from `i = 0` to `N-1`).
        *   The inner loop runs `N-1` times for `i=0`, `N-2` times for `i=1`, and so on, down to `1` time for `i=N-2`.
        *   The total number of pairs considered is approximately $N \times (N-1) / 2$, which simplifies to $O(N^2)$.
    *   Inside the inner loop, all operations (like `std::max`, `std::min`, arithmetic calculations, and comparisons) take constant time, $O(1)$.
    *   Therefore, the dominant part of the algorithm is the nested loop, resulting in a time complexity of $O(N^2)$ per test case.
    *   Given `T` test cases, the total time complexity is $O(T \cdot N^2)$. With `N` up to 1000, $N^2 = 10^6$, which is efficient enough for typical time limits (usually around $10^8$ operations per second).

*   **Space Complexity**:
    *   We use two `std::vector`s, `A` and `B`, each storing `N` integers. This requires $O(N)$ space.
    *   All other variables (e.g., `N`, `K`, `max_tastiness`, `cost1`, `cost2`, `discount`, etc.) use a constant amount of memory, $O(1)$.
    *   Thus, the total space complexity is $O(N)$. With `N` up to 1000, this is a very small memory footprint (e.g., 2 * 1000 * 4 bytes = 8KB for integers), well within typical memory limits.

## Solution Code

```cpp
#include <iostream> // Required for cin, cout
#include <vector>   // Required for std::vector
#include <algorithm> // Required for std::max, std::min

// Function to solve a single test case
void solve() {
    int N, K;
    std::cin >> N >> K; // Read N (number of food items) and K (Chef's budget)

    // Read item costs A_i into a vector
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    // Read item tastiness values B_i into a vector
    std::vector<int> B(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> B[i];
    }

    int max_tastiness = 0; // Initialize maximum tastiness found to 0.
                            // This handles the case where no pair fits the budget.

    // Iterate through all unique pairs of items (i, j)
    // The outer loop picks the first item (index i).
    for (int i = 0; i < N; ++i) {
        // The inner loop picks the second item (index j), ensuring j is always greater than i
        // to avoid duplicate pairs (e.g., (0,1) and (1,0) are the same) and self-pairing.
        for (int j = i + 1; j < N; ++j) {
            int cost1 = A[i];
            int tastiness1 = B[i];
            int cost2 = A[j];
            int tastiness2 = B[j];

            // Determine the more expensive and less expensive item costs
            int C_max = std::max(cost1, cost2);
            int C_min = std::min(cost1, cost2);

            // Calculate the discount for the more expensive item.
            // Discount is min(50% of C_max, 100 rupees).
            // Since A_i is guaranteed to be an even integer, C_max / 2 will be an integer.
            int discount = std::min(C_max / 2, 100);

            // Calculate the effective cost of the more expensive item after applying the discount
            int effective_C_max = C_max - discount;

            // Calculate the total cost for this pair of items
            int total_cost = C_min + effective_C_max;

            // Calculate the total tastiness for this pair of items
            int total_tastiness = tastiness1 + tastiness2;

            // Check if the total cost is within Chef's budget K
            if (total_cost <= K) {
                // If it is, update max_tastiness if this pair offers higher total tastiness
                max_tastiness = std::max(max_tastiness, total_tastiness);
            }
        }
    }

    // Print the maximum tastiness found for this test case.
    // If no pair was found within budget, max_tastiness remains 0, which is the required output.
    std::cout << max_tastiness << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from being flushed before each std::cin operation.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful program execution
}
```