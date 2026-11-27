# [Distinct 2 Subarray (DIS2SUB)](https://www.codechef.com/problems/DIS2SUB)
- **Difficulty Rating**: 870
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the length of the shortest "good" subarray within a given array `A` of `N` integers. A subarray is considered "good" if it contains exactly two distinct elements. If no such subarray exists, we should output -1. The array elements $A_i$ are guaranteed to be between 1 and 100, and the array length `N` is up to 100.

## Intuition & Mathematical Observation

The core of the problem is to identify subarrays with exactly two distinct elements and then find the minimum length among them.

1.  **Subarrays**: A subarray is a contiguous part of an array. For an array of length `N`, there are `N * (N + 1) / 2` possible subarrays. Since `N` is small (up to 100), we can afford to iterate through all possible subarrays.

2.  **Counting Distinct Elements**: For each subarray `A[i...j]`, we need to count how many unique values it contains.
    *   A naive approach would be to put all elements of `A[i...j]` into a `std::set` and then check its size. This would be `O((j-i+1) * log(j-i+1))` for each subarray.
    *   A more efficient approach, especially given the small range of element values (1 to 100), is to use a boolean frequency array (or `std::vector<bool>`). For a subarray `A[i...j]`, we can declare `std::vector<bool> seen(101, false)`. As we iterate `k` from `i` to `j`, if `seen[A[k]]` is `false`, we mark it `true` and increment a `distinct_count`.

3.  **Optimization - Early Exit**: When we fix a starting point `i` and extend the ending point `j` from `i` to `N-1`:
    *   We maintain `distinct_count` for the current subarray `A[i...j]`.
    *   If `distinct_count` becomes exactly 2, we have found a "good" subarray `A[i...j]`. We update our `min_len` with `j - i + 1`.
    *   Crucially, if `distinct_count` becomes *greater than* 2 (e.g., 3 or more), then any further extension of this subarray (i.e., `A[i...k]` where `k > j`) will *also* have at least `distinct_count` unique elements. It can never reduce its distinct count back to 2. Therefore, we can stop extending `j` for the current `i` and move to the next starting point `i+1`. This significantly prunes the search space.

4.  **Initialization and Edge Case**:
    *   Initialize `min_len` to a very large value (e.g., `std::numeric_limits<int>::max()`).
    *   If after checking all subarrays, `min_len` remains at its initial large value, it means no "good" subarray was found, and we should output -1. Otherwise, output `min_len`.

This approach systematically checks all relevant subarrays, efficiently counts distinct elements, and uses an early exit optimization to improve performance.

## Complexity Analysis

*   **Time Complexity**:
    *   The outer loop iterates `N` times (for `i` from `0` to `N-1`).
    *   The inner loop iterates `N` times in the worst case (for `j` from `i` to `N-1`).
    *   Inside the inner loop, operations like checking `seen[A[j]]`, incrementing `distinct_count`, and `std::min` are all $O(1)$.
    *   The `break` optimization helps to cut short the inner loop when `distinct_count > 2`. However, in the worst-case scenario (e.g., an array like `[1, 2, 1, 2, 1, 2, ...]`), the inner loop might still run for a significant portion of `N` for many `i`.
    *   Therefore, the overall time complexity remains $O(N^2)$.
    *   Given `N <= 100`, $N^2 = 100^2 = 10000$, which is very efficient and well within typical time limits for competitive programming problems.
    *   For `T` test cases, the total time complexity is $O(T \cdot N^2)$.

*   **Space Complexity**:
    *   `std::vector<int> A(N)`: Stores the input array, requiring $O(N)$ space.
    *   `std::vector<bool> seen(101, false)`: This vector is used to track distinct elements within a subarray. Its size is fixed at 101 because array elements are between 1 and 100. Thus, it contributes $O(1)$ auxiliary space (as 101 is a constant).
    *   Other variables (`N`, `min_len`, `distinct_count`, loop counters) take $O(1)$ space.
    *   Overall, the space complexity is dominated by the input array, resulting in $O(N)$.

## Solution Code

```cpp
#include <iostream> // Required for std::cin, std::cout
#include <vector>   // Required for std::vector
#include <algorithm> // Required for std::min
#include <limits>   // Required for std::numeric_limits<int>::max()

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N; // Read the length of the array
    std::vector<int> A(N); // Declare a vector of size N
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i]; // Read array elements
    }

    // Initialize min_len to a very large value.
    // If it remains this value, no good subarray was found.
    int min_len = std::numeric_limits<int>::max();

    // Iterate over all possible starting points of subarrays
    for (int i = 0; i < N; ++i) {
        // For each starting point i, iterate through all possible ending points j
        // and maintain distinct elements for the current subarray A[i...j]
        
        // `seen` array to keep track of distinct elements in the current subarray A[i...j].
        // A_i values are between 1 and 100, so an array of size 101 is sufficient.
        // Initialize all to false for each new starting point `i`.
        std::vector<bool> seen(101, false); 
        int distinct_count = 0; // Count of distinct elements in A[i...j]

        for (int j = i; j < N; ++j) {
            // If the current element A[j] has not been seen before in A[i...j],
            // mark it as seen and increment the distinct count.
            if (!seen[A[j]]) {
                seen[A[j]] = true;
                distinct_count++;
            }

            // Check if the current subarray A[i...j] is "good".
            // A good subarray has exactly 2 distinct elements.
            if (distinct_count == 2) {
                // If it's good, update min_len with the length of this subarray.
                // The length is (j - i + 1).
                min_len = std::min(min_len, j - i + 1);
            } 
            // Optimization: If distinct_count becomes greater than 2,
            // any further extension of this subarray (A[i...k] where k > j)
            // will also have more than 2 distinct elements (at least the current `distinct_count`).
            // Therefore, it cannot be a "good" subarray. We can stop extending from `i`.
            else if (distinct_count > 2) {
                break; // Move to the next starting point `i`
            }
        }
    }

    // After checking all possible subarrays, print the result.
    if (min_len == std::numeric_limits<int>::max()) {
        // If min_len is still its initial large value, no good subarray was found.
        std::cout << -1 << "\n";
    } else {
        // Otherwise, print the shortest length found.
        std::cout << min_len << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming practice.
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