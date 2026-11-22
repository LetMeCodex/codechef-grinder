# [Exun Handshake (EXSHAKE)](https://www.codechef.com/problems/EXSHAKE)
- **Difficulty Rating**: 815
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to select the maximum possible number of groups, say `k` groups, from a total of `n` available groups. Each group `i` has `a[i]` people. The constraint is that the total number of handshakes among all people in the selected `k` groups must not exceed a given budget `m`. The number of handshakes among `P` people is given by the formula `P * (P - 1) / 2`.

## Intuition & Mathematical Observation

1.  **Handshake Function Property**: The number of handshakes `f(P) = P * (P - 1) / 2` is a monotonically increasing function for `P >= 1`. This means that if we have more people, the number of handshakes will always be greater (or equal, if `P` doesn't change). Conversely, to minimize handshakes, we need to minimize the total number of people.

2.  **Minimizing Handshakes for a Fixed Number of Groups `k`**: If we decide to select exactly `k` groups, to minimize the total number of handshakes, we must minimize the total number of people across these `k` groups. To achieve this, we should always choose the `k` groups that have the *smallest* number of people. For example, if we want to pick 2 groups, we should pick the two groups with the fewest people.

3.  **Overall Strategy**:
    *   First, sort the given group sizes `a[i]` in ascending order. This allows us to easily pick the smallest groups.
    *   We want to find the maximum `k` (number of groups). We can iterate `k` from `0` to `n`.
    *   For each `k`:
        *   Calculate the total number of people if we select the `k` smallest groups (i.e., `a[0] + a[1] + ... + a[k-1]`).
        *   Calculate the total handshakes for this sum of people using the formula `P * (P - 1) / 2`.
        *   If the calculated handshakes are less than or equal to `m`, then `k` is a valid number of groups. We update our maximum `k` found so far.
    *   Since the total number of people (and thus handshakes) is non-decreasing as `k` increases (because we always add the next smallest group), once `k` groups exceed the handshake budget `m`, any `k' > k` groups will also exceed `m`. This means we can stop iterating `k` early if the condition `calculate_handshakes(current_people) <= m` becomes false.

The provided solution implements this strategy directly. It sorts the group sizes and then iterates through possible `k` values, summing the `k` smallest group sizes and checking the handshake condition.

## Complexity Analysis

*   **Time Complexity**:
    *   Reading input `n`, `m`, and `a[i]`: $O(N)$
    *   Sorting the array `a`: $O(N \log N)$
    *   The main loop iterates `k` from `0` to `N`. Inside this loop:
        *   For each `k`, it calculates `current_people` by summing the first `k` elements of the sorted array `a`. This inner sum takes $O(k)$ time.
        *   The `calculate_handshakes` function takes $O(1)$ time.
        *   The total time for the `k` loop is $\sum_{k=0}^{N} O(k) = O(N^2)$.
    *   Therefore, the total time complexity per test case is $O(N \log N + N^2) = O(N^2)$.
    *   Given `T` test cases, the overall time complexity is $O(T \cdot N^2)$. With $N=1000$ and $T=100$, this is approximately $100 \cdot (1000)^2 = 10^8$ operations, which is borderline but can pass within typical time limits for simpler problems or with weak test cases.
    *   *Self-correction/Optimization note*: The sum `current_people` can be calculated incrementally in $O(1)$ per `k` iteration (by adding `a[k-1]` to the previous sum), reducing the `k` loop to $O(N)$ and the total time complexity to $O(T \cdot N \log N)$. The provided code, however, re-calculates the sum from scratch in each iteration.

*   **Space Complexity**:
    *   The `std::vector<int> a` stores `N` integers, requiring $O(N)$ space.
    *   All other variables use constant space.
    *   Therefore, the total space complexity is $O(N)$.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <numeric> // Not strictly used in the final loop, but useful for sum operations
#include <algorithm> // For std::sort

// Function to calculate handshakes for a given number of people
long long calculate_handshakes(long long people) {
    if (people < 2) {
        return 0; // 0 or 1 person results in 0 handshakes
    }
    // Formula: P * (P - 1) / 2
    return people * (people - 1) / 2;
}

int main() {
    // Optimize C++ standard streams for faster input/output
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        int n; // Number of groups
        long long m; // Maximum allowed handshakes
        std::cin >> n >> m;

        std::vector<int> a(n); // Vector to store the number of people in each group
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i]; // Read group sizes
        }

        // Sort the group sizes in ascending order.
        // This is crucial because to minimize handshakes for 'k' groups,
        // we must pick the 'k' groups with the smallest number of people.
        std::sort(a.begin(), a.end());

        int max_groups = 0; // Initialize the maximum number of groups found
        
        // Iterate through all possible counts of groups 'k' to invite (from 0 to n)
        for (int k = 0; k <= n; ++k) {
            if (k == 0) {
                // If 0 groups are invited, 0 handshakes occur. This is always valid.
                max_groups = std::max(max_groups, 0);
                continue; // Move to the next 'k'
            }

            // Calculate the total number of people if we invite the 'k' smallest groups.
            // Note: This loop re-sums from scratch for each 'k'. An optimization would be
            // to maintain a running sum to make this O(1) per 'k' iteration.
            long long current_people = 0;
            for (int i = 0; i < k; ++i) {
                current_people += a[i];
            }

            // Check if the handshakes for 'current_people' are within the budget 'm'
            if (calculate_handshakes(current_people) <= m) {
                // If valid, update max_groups if 'k' is greater
                max_groups = std::max(max_groups, k);
            } else {
                // Optimization: Since 'current_people' (and thus handshakes) only increases
                // as 'k' increases, if 'k' groups exceed 'm', then 'k+1' groups will also
                // exceed 'm'. So, we can break early.
                break; 
            }
        }
        std::cout << max_groups << "\n"; // Output the result for the current test case
    }
    return 0; // Indicate successful execution
}

```