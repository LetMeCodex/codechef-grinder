# [Larger Smaller (LARGSMALL)](https://www.codechef.com/problems/LARGSMALL)
- **Difficulty Rating**: 1035
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the count of "good" integers `X`. An integer `X` is defined as "good" if there exist two elements `A_i` and `A_j` in a given array `A` such that `A_i < X < A_j`. We are given `T` test cases, and for each test case, an array `A` of `N` integers.

## Intuition & Mathematical Observation

1.  **Understanding the "good" integer condition**: The condition `A_i < X < A_j` means that `X` must be strictly greater than some element in the array and strictly less than some other element in the array.

2.  **Finding the tightest bounds for X**: To maximize the range of possible `X` values that satisfy this condition, we should consider the smallest possible `A_i` and the largest possible `A_j` from the entire array.
    *   Let `min_val` be the minimum element in the array `A`.
    *   Let `max_val` be the maximum element in the array `A`.

3.  **Simplified condition**: An integer `X` is "good" if and only if `min_val < X < max_val`. This is because if `X` satisfies `min_val < X < max_val`, then we can simply pick `A_i = min_val` and `A_j = max_val` (assuming `min_val` and `max_val` are indeed present in the array, which they are by definition). If `X` satisfies `A_k < X < A_l` for some `A_k, A_l`, then it must also be true that `min_val <= A_k < X < A_l <= max_val`, implying `min_val < X < max_val`.

4.  **Counting integers in the range**: We need to count the number of integers `X` such that `min_val < X < max_val`. These integers are `min_val + 1, min_val + 2, ..., max_val - 1`.
    The count of integers in an inclusive range `[L, R]` is `R - L + 1`.
    Applying this to our range `[min_val + 1, max_val - 1]`:
    Count = `(max_val - 1) - (min_val + 1) + 1`
    Count = `max_val - 1 - min_val - 1 + 1`
    Count = `max_val - min_val - 1`

5.  **Handling edge cases**:
    *   What if `max_val <= min_val`? This scenario occurs if all elements in the array are identical (e.g., `[5, 5, 5]`, where `min_val = 5, max_val = 5`) or if the array contains only one element (e.g., `[7]`, where `min_val = 7, max_val = 7`). In such cases, there are no integers `X` that can be strictly between `min_val` and `max_val`. The count of "good" integers should be 0.
    *   Our formula `max_val - min_val - 1` would yield `5 - 5 - 1 = -1` for the `[5, 5, 5]` example, which is incorrect.
    *   To correctly handle this, we take the maximum of 0 and the calculated count: `max(0, max_val - min_val - 1)`. This ensures that the result is never negative and is 0 when `max_val <= min_val`.

Therefore, the solution involves iterating through the array once to find its minimum and maximum elements, and then applying the formula `max(0, max_val - min_val - 1)`.

## Complexity Analysis

-   **Time Complexity**: $O(N)$
    For each test case, we iterate through the array of `N` elements exactly once to find the minimum and maximum values. This takes $O(N)$ time. All other operations (reading `N`, initializing variables, calculating the final count, printing) take constant time, $O(1)$. Since there are `T` test cases, the total time complexity will be $O(T \cdot N)$.

-   **Space Complexity**: $O(1)$
    We only store a few integer variables (`N`, `min_val`, `max_val`, `A_i`, `count`, `T`). We do not need to store the entire array `A`. Thus, the space used is constant, regardless of the input size `N`.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, vector, algorithm, limits, etc.

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N; // Read the size of the array
    
    // Initialize min_val to the largest possible integer value
    // and max_val to the smallest possible integer value.
    // This ensures that the first element read will correctly set
    // both min_val and max_val.
    // Given constraints 1 <= A_i <= 100, we could also initialize
    // min_val = 101 and max_val = 0, but using numeric_limits is more general.
    int min_val = std::numeric_limits<int>::max();
    int max_val = std::numeric_limits<int>::min();
    
    // Iterate through the array elements to find the minimum and maximum values
    for (int i = 0; i < N; ++i) {
        int A_i;
        std::cin >> A_i; // Read an element
        min_val = std::min(min_val, A_i); // Update minimum value
        max_val = std::max(max_val, A_i); // Update maximum value
    }
    
    // An integer X is "good" if there exist A_i and A_j such that A_i < X < A_j.
    // This condition is equivalent to min_val < X < max_val.
    // The integers satisfying this condition are min_val + 1, min_val + 2, ..., max_val - 1.
    // The count of such integers is (max_val - 1) - (min_val + 1) + 1,
    // which simplifies to max_val - min_val - 1.
    
    // If max_val <= min_val (e.g., all elements in the array are the same, or N=1),
    // then there are no integers X such that min_val < X < max_val.
    // In this case, the count should be 0.
    // The formula max_val - min_val - 1 would yield a non-positive number (e.g., -1 if max_val == min_val).
    // So, we take the maximum of 0 and the calculated count to handle this case correctly.
    int count = std::max(0, max_val - min_val - 1);
    
    std::cout << count << "\n"; // Output the result for the current test case
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }
    
    return 0; // Indicate successful execution
}
```