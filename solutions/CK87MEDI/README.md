# [Chef and Employment Test (CK87MEDI)](https://www.codechef.com/problems/CK87MEDI)
- **Difficulty Rating**: 1142
- **Solved in**: 2 attempt(s)

## Problem Summary

The problem asks us to find the maximum possible median of an array after adding `K` non-negative integers to an initial array `A` of `N` integers. We can choose any `K` non-negative integers to add. The median of an array of size `M` is defined as the element at index `(M-1)/2` (0-indexed) after sorting the array in non-decreasing order. The values in the initial array `A` are between 0 and 1000, inclusive.

## Intuition & Mathematical Observation

1.  **Median Definition**: For an array of `M` elements, sorted as `a_0, a_1, ..., a_{M-1}`, the median is `a_{(M-1)/2}`. For an element `X` to be the median `a_p` (where `p = (M-1)/2`), two conditions must be met:
    *   There must be at least `p + 1` elements less than or equal to `X`.
    *   There must be at least `M - p` elements greater than or equal to `X`.
    Substituting `p = (M-1)/2`, both conditions simplify to needing at least `(M+1)/2` elements that are less than or equal to `X`, AND at least `(M+1)/2` elements that are greater than or equal to `X`. Let `required_count = (M+1)/2`.

2.  **Maximizing the Median**: To find the *maximum* possible median, we should try candidate values for the median starting from the largest possible value and working downwards. The maximum possible value for any element in the array is 1000 (given the constraints on `A_i` and the fact that inserting values greater than 1000 won't help achieve a higher median than 1000 if 1000 is already achievable). The smallest possible value is 0.

3.  **Optimal Use of `K` Insertions**: When checking if a candidate value `val` can be the median, we want to use the `K` additional elements in a way that best supports `val` being the median. The most effective strategy is to insert `K` copies of `val` itself. This simultaneously boosts both the count of elements less than or equal to `val` and the count of elements greater than or equal to `val`. If `val` can be the median by inserting `K` copies of `val`, it means `val` is a possible median.

4.  **Efficient Counting**: Since the values in the array `A` are small (0 to 1000), we can use frequency arrays and prefix sums for efficient counting:
    *   `counts[x]`: Stores the frequency of `x` in the original array `A`.
    *   `prefix_counts[x]`: Stores the total number of elements in `A` that are less than or equal to `x`. This can be computed as `prefix_counts[x] = prefix_counts[x-1] + counts[x]`.

5.  **Algorithm Steps**:
    *   Calculate `total_elements = N + K`.
    *   Calculate `required_count_for_median = (total_elements + 1) / 2`.
    *   Populate `counts` array for the initial `N` elements.
    *   Populate `prefix_counts` array based on `counts`.
    *   Iterate `val` from 1000 down to 0:
        *   Calculate `num_le_val_A`: Number of elements in `A` that are `<= val`. This is `prefix_counts[val]`.
        *   Calculate `num_lt_val_A`: Number of elements in `A` that are `< val`. This is `prefix_counts[val-1]` (or 0 if `val=0`).
        *   Calculate `num_ge_val_A`: Number of elements in `A` that are `>= val`. This is `N - num_lt_val_A`.
        *   Check if `val` can be the median:
            *   Condition 1: `num_le_val_A + K >= required_count_for_median`
            *   Condition 2: `num_ge_val_A + K >= required_count_for_median`
        *   If both conditions are true, `val` is the greatest possible median. Print `val` and terminate for this test case.

This approach guarantees finding the maximum possible median because we check values in decreasing order, and the first `val` that satisfies the conditions is our answer.

## Complexity Analysis

*   **Time Complexity**:
    *   Reading `N` and `K`: $O(1)$.
    *   Populating the `counts` array: We iterate `N` times to read `N` elements. Each `scanf` operation is $O(1)$. Total: $O(N)$.
    *   Populating the `prefix_counts` array: We iterate from 0 to 1000 (the maximum possible value). This is a constant number of operations (1001). Total: $O(\text{max_val})$.
    *   Finding the median: We iterate `val` from 1000 down to 0. In each iteration, we perform constant-time lookups and arithmetic operations. Total: $O(\text{max_val})$.
    *   Overall time complexity for one test case: $O(N + \text{max_val})$.
    *   Given `T` test cases, the total time complexity is $O(T \cdot (N + \text{max_val}))$. With `N` up to $10^5$ and `max_val` being 1000, this simplifies to $O(T \cdot N)$, which is efficient enough.

*   **Space Complexity**:
    *   `counts` vector: Stores frequencies for values from 0 to 1000. Size is `max_val + 1`. Total: $O(\text{max_val})$.
    *   `prefix_counts` vector: Stores prefix sums for values from 0 to 1000. Size is `max_val + 1`. Total: $O(\text{max_val})$.
    *   Overall space complexity: $O(\text{max_val})$. This is very small (1001 integers).

## Solution Code

```cpp
#include <iostream> // For std::ios_base, std::cin, std::cout (though not used directly after change)
#include <vector>
#include <algorithm> // For std::max (not strictly needed for this solution, but often useful)
#include <cstdio>    // For scanf/printf

void solve() {
    int N, K;
    // Use scanf for faster input of N and K
    scanf("%d %d", &N, &K);

    // counts[val] stores the frequency of 'val' in the original array A.
    // Max A_i is 1000, so array size 1001 (for indices 0 to 1000).
    std::vector<int> counts(1001, 0);
    for (int i = 0; i < N; ++i) {
        int val;
        // Use scanf for faster input of array elements
        scanf("%d", &val);
        counts[val]++;
    }

    // prefix_counts[v] stores the total number of elements in A that are <= v.
    std::vector<int> prefix_counts(1001, 0);
    // Initialize prefix_counts[0] with counts[0].
    // The loop for i=1 to 1000 will correctly sum up counts even if N=0 (all counts are 0).
    prefix_counts[0] = counts[0];
    for (int i = 1; i <= 1000; ++i) {
        prefix_counts[i] = prefix_counts[i-1] + counts[i];
    }

    int total_elements = N + K;
    // The median is at index (total_elements - 1) / 2 (0-indexed).
    // To be the median, an element 'val' must satisfy:
    // 1. At least (total_elements - 1) / 2 + 1 elements are <= val.
    // 2. At least total_elements - (total_elements - 1) / 2 elements are >= val.
    // Both conditions simplify to needing at least (total_elements + 1) / 2 elements.
    int required_count_for_median = (total_elements + 1) / 2;

    // Iterate from the largest possible median value (1000) down to 0.
    // The first 'val' that satisfies the conditions will be the greatest median.
    for (int val = 1000; val >= 0; --val) {
        // num_le_val_A: Number of elements in original array A that are <= val.
        int num_le_val_A = prefix_counts[val];
        
        // num_lt_val_A: Number of elements in original array A that are < val.
        // If val is 0, there are no elements < 0, so this is 0.
        int num_lt_val_A = (val == 0) ? 0 : prefix_counts[val-1];
        
        // num_ge_val_A: Number of elements in original array A that are >= val.
        // This is N - (count of elements < val).
        int num_ge_val_A = N - num_lt_val_A;

        // Check if 'val' can be the median.
        // We can insert K elements. To maximize the median, we assume we insert K elements
        // that are equal to 'val'. These K elements contribute to both counts.
        bool condition_le_met = (num_le_val_A + K >= required_count_for_median);
        bool condition_ge_met = (num_ge_val_A + K >= required_count_for_median);

        if (condition_le_met && condition_ge_met) {
            // Use printf for faster output
            printf("%d\n", val);
            return; // Found the greatest possible median, so we can stop.
        }
    }
}

int main() {
    // When using scanf/printf, std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    // are not needed and can sometimes cause minor issues if mixed with C-style I/O.
    // So, they are removed.
    
    int t;
    scanf("%d", &t); // Read the number of test cases.
    while (t--) {
        solve(); // Solve each test case.
    }
    return 0;
}
```