# [Make Permutation (MAKEPERM)](https://www.codechef.com/problems/MAKEPERM)
- **Difficulty Rating**: 1200
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a given array `A` of `N` positive integers can be transformed into a permutation `C` of numbers from `1` to `N`. The transformation rule is that for each element `A[i]`, we must find a corresponding `C[i]` such that `C[i] >= A[i]`. If such a permutation `C` can be formed, we output "YES"; otherwise, "NO".

## Intuition & Mathematical Observation

The core idea behind solving this problem efficiently is a greedy strategy combined with sorting.

**Greedy Strategy:**
To maximize our chances of successfully forming a permutation `C`, we should try to satisfy the constraints for the "most restrictive" elements first. An element `A[i]` is more restrictive if it's smaller, as it can potentially take up a smaller value from `1` to `N` that a larger `A[j]` might also need. Conversely, if `A[i]` is large, it *must* take a large `C[i]`.

The optimal greedy approach is as follows:

1.  **Sort the input array `A`**: Sort `A` in non-decreasing order. This ensures that when we iterate through `A`, we are always considering the smallest available `A[i]` that hasn't been assigned a `C[i]` yet. By processing smaller `A[i]` values first, we leave larger target values (from `1` to `N`) available for larger `A[i]` values, which might require them due to the `C[i] >= A[i]` constraint.

2.  **Iterate and Assign Greedily**: For each `A[i]` (in sorted order):
    *   We need to find the smallest possible `C[i]` such that:
        *   `C[i] >= A[i]` (as per problem statement, `B[i] = C[i] - A[i]` must be non-negative).
        *   `C[i]` is in the range `[1, N]` (definition of a permutation of size `N`).
        *   `C[i]` has not been used yet by any previous `A[j]` (where `j < i`).
    *   We can maintain a boolean array `used` (of size `N+1`) to keep track of which numbers from `1` to `N` have already been assigned. `used[k]` will be `true` if `k` has been assigned.
    *   For the current `A[i]`, we search for the smallest integer `k` starting from `A[i]` up to `N`.
    *   If we find such a `k` that is not `used`, we assign `k` to `C[i]`, mark `used[k]` as `true`, and move to the next `A[i]`.
    *   If we iterate from `A[i]` up to `N` and find that all numbers in this range are already `used`, then it's impossible to find a suitable `C[i]` for the current `A[i]`. In this case, we immediately know that a permutation cannot be formed, and we can output "NO".

**Why this greedy approach works:**
By always picking the *smallest possible* available `C[i]` for the *smallest current* `A[i]`, we are making the "safest" choice. This strategy preserves larger target values for larger `A[i]`s that might *require* them (because their `A[i]` value is high). If this greedy approach fails to find a permutation, no other assignment strategy could succeed, because any other choice would either use a larger target value for a smaller `A[i]` (which is suboptimal as it reduces options for larger `A[j]`s) or fail to satisfy `C[i] >= A[i]`.

## Complexity Analysis

*   **Time Complexity**:
    *   Reading input `N` and array `A`: $O(N)$.
    *   Sorting array `A`: $O(N \log N)$.
    *   Initializing the `used` boolean vector: $O(N)$.
    *   The main loop iterates `N` times (for each `A[i]`). Inside this loop, the inner loop searches for the smallest available `k` from `A[i]` to `N`. In the worst case (e.g., `A = [1, 1, ..., 1]`), for each `A[i]`, the inner loop might iterate up to `N` times to find an unused `k`.
        *   For `A[0]=1`, `k` checks `1`.
        *   For `A[1]=1`, `k` checks `1` (used), then `2`.
        *   For `A[i]=1`, `k` checks `1, 2, ..., i`, then `i+1`.
        *   The total number of checks across all `N` iterations of the outer loop would be $1 + 2 + \dots + N = \frac{N(N+1)}{2}$, which is $O(N^2)$.
    *   Therefore, the dominant factor is the nested loop structure, resulting in an overall time complexity of $O(N \log N + N^2) = O(N^2)$.

    **Note on Constraints:** The problem states that the sum of `N` over all test cases is $\le 10^5$. While an $O(N^2)$ solution for a single test case with $N=10^5$ would be too slow ($10^{10}$ operations), this constraint implies that if `N` is large for one test case, `T` must be small. The effective maximum `N` for which $N^2$ operations are performed is limited. For example, if the maximum `N` for any test case is around $1000$, then $T$ could be up to $100$ (since $100 \times 1000 = 10^5$), leading to $100 \times (1000)^2 = 10^8$ operations, which is often acceptable within typical time limits (1-2 seconds) for C++ solutions.

*   **Space Complexity**:
    *   `std::vector<int> A(N)`: $O(N)$ space to store the input array.
    *   `std::vector<bool> used(N + 1)`: $O(N)$ space to keep track of used numbers.
    *   Overall space complexity: $O(N)$.

## Solution Code

```cpp
#include <iostream> // Required for standard input/output operations (cin, cout)
#include <vector>   // Required for std::vector
#include <algorithm> // Required for std::sort

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N; // Read the size of the array A
    std::vector<int> A(N); // Declare a vector A of size N
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i]; // Read elements of array A
    }

    // Sort array A in non-decreasing order.
    // This is a critical step for the greedy strategy to work correctly.
    // By processing smaller A_i values first, we leave larger target values
    // available for larger A_i values, maximizing the chances of success.
    std::sort(A.begin(), A.end());

    // `used` array to keep track of numbers from 1 to N that have been assigned to C_i.
    // `used[0]` is intentionally unused (to allow 1-based indexing for values 1 to N).
    // `used[k]` will be true if the value `k` has already been assigned.
    std::vector<bool> used(N + 1, false);

    bool possible = true; // Flag to track if a permutation can be formed
    for (int i = 0; i < N; ++i) {
        // For the current A[i] (which is the smallest unassigned A_j due to sorting),
        // we need to find the smallest possible C_i such that:
        // 1. C_i >= A[i] (because B_i must be non-negative)
        // 2. C_i is in the range [1, N] (definition of a permutation of size N)
        // 3. C_i has not been used yet by a previous A_j (j < i)
        
        bool found_target = false; // Flag to check if a suitable C_i was found for A[i]
        // Iterate from A[i] up to N to find the smallest available target value
        for (int k = A[i]; k <= N; ++k) {
            if (!used[k]) {
                // Found the smallest available target value k for A[i]
                used[k] = true; // Mark k as used
                found_target = true;
                break; // Move to the next A[i] as we've assigned a value for the current one
            }
        }

        if (!found_target) {
            // If no suitable k was found for A[i] (meaning all numbers from A[i] to N
            // are already used), then it's impossible to form a permutation.
            possible = false;
            break; // No need to check further elements, the answer is NO
        }
    }

    // Output the result for the current test case
    if (possible) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful execution
}
```