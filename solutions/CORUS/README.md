# Isolation Centers (CORUS)
- **Difficulty Rating**: 1305
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the size of a pending queue for COVID-19 cases. We are given an initial string representing the types of viruses present in the population. Each character in the string represents a person infected with a specific virus type. We are also given a number of queries, `q`. For each query, we are given an integer `c`, representing the number of available isolation centers. An isolation center can only hold one person at a time. The rule is that if there are `k` people infected with a particular virus type, and we have `c` isolation centers, we can place at most `c` of these people into isolation centers (one per center). The remaining `k - min(k, c)` people must be placed in a pending queue. We need to find the total size of the pending queue across all virus types for each query.

## Intuition & Mathematical Observation

The core of the problem lies in understanding how many people of a specific virus type will end up in the pending queue given a certain number of isolation centers.

Let's consider a single virus type. Suppose there are `k` people infected with this virus. We have `c` isolation centers.
Each isolation center can accommodate at most one person. Therefore, we can place at most `c` people infected with this virus type into isolation centers.

The number of people of this virus type that can be placed in isolation centers is `min(k, c)`.
The number of people of this virus type that *cannot* be placed in isolation centers (and thus must go to the pending queue) is `k - min(k, c)`.

Let's analyze `k - min(k, c)`:
1. If `k <= c`: This means the number of infected people of this virus type is less than or equal to the number of available isolation centers. In this case, `min(k, c) = k`. So, `k - min(k, c) = k - k = 0`. No one from this virus type goes to the pending queue.
2. If `k > c`: This means there are more infected people of this virus type than available isolation centers. In this case, `min(k, c) = c`. So, `k - min(k, c) = k - c`. This is the number of people who must go to the pending queue.

Combining these two cases, the number of people of a specific virus type that go to the pending queue is `max(0, k - c)`.

The problem asks for the *total* size of the pending queue. This means we need to sum up the pending queue contributions from *each* distinct virus type.

To efficiently calculate this sum for each query, we first need to know the counts of each distinct virus type in the initial population. A map or a frequency array can be used for this. Since the virus types are represented by lowercase English letters, a map `std::map<char, int>` or an array `int counts[26]` would be suitable.

After counting the occurrences of each virus type, we will have a list of counts (e.g., `[count_A, count_B, count_C, ...]`). For each query `c`, we iterate through these counts. For each `count` in our list, we add `max(0, count - c)` to the total pending queue size.

To optimize the calculation for multiple queries, especially if `q` is large, sorting the virus counts in descending order can be beneficial. However, in this specific problem, the number of distinct virus types is at most 26. So, iterating through the counts for each query is already efficient enough. The provided solution sorts the counts, which is a good practice but not strictly necessary for the given constraints.

Let's re-examine the provided code's logic:
The initial loop iterates through `virus_counts` (which are sorted in descending order).
`pending_queue_size += std::max(0, count - (int)c);`
This line correctly implements the derived formula `max(0, k - c)` for each virus type count. The sorting of `virus_counts` doesn't fundamentally change the correctness of this calculation, as the sum is commutative.

The first attempt at logic in the code comments was slightly confused about how `centers_used` would play a role. The key insight is that each isolation center can be used for *any* virus type, but only one person per center. So, if we have `c` centers, we can accommodate up to `c` people *in total* across all virus types, with the constraint that no more than one person of a *specific* virus type can occupy a center if that center is already taken by someone of the same virus type. However, the problem statement implies that the constraint is per virus type: "if there are `k` people infected with a particular virus type, and we have `c` isolation centers, we can place at most `c` of these people into isolation centers". This means we can use up to `c` centers for virus type A, up to `c` centers for virus type B, and so on, but each center can only hold one person. The interpretation that leads to `max(0, k - c)` is that for a specific virus type with `k` infected individuals, we can use up to `c` distinct isolation centers to house them. If `k > c`, then `k - c` individuals must go to the pending queue. This interpretation is consistent with the problem statement and the provided solution.

## Complexity Analysis

Let `N` be the length of the input string `s` and `Q` be the number of queries.
Let `V` be the number of distinct virus types (at most 26 for lowercase English letters).

*   **Preprocessing (Counting virus types):**
    *   We iterate through the string `s` of length `N` once to populate the `counts` map. This takes $O(N)$ time.
    *   We then extract the counts into a `std::vector`. This takes $O(V)$ time.
    *   Sorting `virus_counts` takes $O(V \log V)$ time. Since `V` is at most 26, this is effectively a constant time operation, $O(1)$.

*   **Query Processing:**
    *   For each of the `Q` queries, we iterate through the `virus_counts` vector. The size of this vector is `V`.
    *   Inside the loop, we perform a constant number of operations (`std::max`, addition).
    *   Therefore, each query takes $O(V)$ time.
    *   The total time for `Q` queries is $O(Q \cdot V)$.

*   **Overall Time Complexity:**
    The dominant part is the query processing. So, the total time complexity is $O(N + Q \cdot V)$. Since `V` is a small constant (26), this can be considered $O(N + Q)$.

*   **Space Complexity:**
    *   The `counts` map stores at most `V` key-value pairs. This takes $O(V)$ space.
    *   The `virus_counts` vector stores at most `V` integers. This takes $O(V)$ space.
    *   Since `V` is a small constant (26), the space complexity is effectively $O(1)$.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int n; // Length of the virus string
        long long q; // Number of queries
        std::cin >> n >> q;
        std::string s; // String representing virus types
        std::cin >> s;

        // Use a map to count the occurrences of each virus type.
        // The keys are characters (virus types), and values are their counts.
        std::map<char, int> counts;
        for (char c : s) {
            counts[c]++;
        }

        // Store the counts of each virus type in a vector.
        // This vector will contain the 'k' values for our formula.
        std::vector<int> virus_counts;
        for (auto const& [key, val] : counts) {
            virus_counts.push_back(val);
        }
        
        // Sorting the virus counts in descending order is not strictly necessary
        // for correctness given V <= 26, but it's a common practice and doesn't
        // hurt performance significantly. It might be useful if V was larger.
        std::sort(virus_counts.rbegin(), virus_counts.rend()); 

        // Process each query
        for (long long i = 0; i < q; ++i) {
            long long c; // Number of available isolation centers for this query
            std::cin >> c;

            long long pending_queue_size = 0; // Initialize pending queue size for this query

            // For each virus type, calculate how many people must go to the pending queue.
            // The formula is max(0, k - c), where k is the count of that virus type.
            for (int count : virus_counts) {
                // If count > c, then count - c people go to the pending queue.
                // Otherwise (count <= c), 0 people go to the pending queue for this type.
                pending_queue_size += std::max(0, count - (int)c);
            }

            // Output the total pending queue size for the current query
            std::cout << pending_queue_size << "\n";
        }
    }
    return 0;
}
```