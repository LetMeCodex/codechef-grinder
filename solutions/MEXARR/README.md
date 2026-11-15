# [MEXimize the Array (MEXARR)](https://www.codechef.com/problems/MEXARR)
- **Difficulty Rating**: 1289
- **Solved in**: 1 attempt(s)

## Problem Summary

You are given an array `A` of `N` integers. You can perform an operation: choose an index `i` and an integer `X`, then change `A[i]` to `X`. The cost of this operation is `|A[i] - X|`. Your goal is to minimize the total cost such that the MEX (Minimum Excluded value) of the array becomes as large as possible.

The MEX of a set of non-negative integers is the smallest non-negative integer not present in the set. For example, MEX({0, 1, 3}) = 2, MEX({1, 2, 3}) = 0, MEX({0, 1, 2}) = 3.

## Intuition & Mathematical Observation

1.  **Maximizing MEX**:
    For an array of `N` elements, what is the maximum possible MEX we can achieve?
    To achieve a MEX of `K`, the array must contain all integers `0, 1, ..., K-1`.
    If an array has `N` elements, the largest possible MEX it can have is `N`. This occurs if and only if the array contains all integers from `0` to `N-1` (i.e., it is a permutation of `[0, 1, ..., N-1]`). If it contains these `N` distinct elements, then `N` is the smallest non-negative integer not present, making the MEX equal to `N`. Any other configuration of `N` elements would result in a MEX less than `N`.
    Therefore, our primary goal is to transform the given array `A` into a permutation of `[0, 1, ..., N-1]`.

2.  **Minimum Cost Transformation**:
    We have an initial array `A` (of `N` elements) and a target array `B = [0, 1, ..., N-1]` (also of `N` elements). We want to transform `A` into `B` by changing `A[i]` to some `B[j]` such that the sum of absolute differences `|A[i] - B[j]|` is minimized.
    This is a classic problem: given two sets of numbers, `A` and `B`, find a one-to-one mapping (a permutation `P`) such that `sum(|A[i] - B[P[i]]|)` is minimized. The well-known result is that this sum is minimized if both arrays `A` and `B` are sorted, and then elements are paired element-wise. That is, the `i`-th smallest element of `A` is mapped to the `i`-th smallest element of `B`.

3.  **Applying the Observation**:
    *   Our target array `B = [0, 1, ..., N-1]` is already sorted.
    *   We should sort the given array `A`. Let the sorted array be `A'`.
    *   Then, for each index `i` from `0` to `N-1`, we pair `A'[i]` with `B[i]` (which is simply `i`).
    *   The cost for this specific pairing at index `i` will be `|A'[i] - i|`.
    *   The total minimum cost will be the sum of these individual costs: `sum(|A'[i] - i|)` for `i` from `0` to `N-1`.

This strategy guarantees the maximum possible MEX (`N`) with the minimum possible operations.

## Complexity Analysis

*   **Time Complexity**:
    *   Reading `N` elements into the vector `A`: $O(N)$.
    *   Sorting the array `A`: $O(N \log N)$. This is the dominant factor.
    *   Iterating through the sorted array to calculate the sum of absolute differences: $O(N)$.
    *   For each test case, the total time complexity is $O(N \log N)$.
    *   Given `T` test cases, the overall time complexity is $O(T \cdot N \log N)$.

*   **Space Complexity**:
    *   Storing the input array `A` in a `std::vector`: $O(N)$.
    *   Other variables (like `N`, `total_operations`, loop counters) use $O(1)$ space.
    *   The total space complexity is $O(N)$.

## Solution Code

```cpp
#include <iostream> // Required for std::cin, std::cout
#include <vector>   // Required for std::vector
#include <algorithm> // Required for std::sort, std::abs

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N; // Read the number of elements

    // Declare a vector to store the array elements.
    // A_i values are between 0 and N, so 'int' is sufficient for individual elements.
    std::vector<int> A(N); 
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i]; // Read each element
    }

    // Step 1: Sort the array A.
    // This is crucial because to minimize the sum of absolute differences
    // between two sets of numbers, both sets must be sorted and then paired element-wise.
    std::sort(A.begin(), A.end());

    // Step 2: Calculate the minimum operations.
    // The goal is to achieve the maximum possible MEX.
    // For an array of length N, the maximum possible MEX is N.
    // This requires the array to contain all integers from 0 to N-1.
    // So, our target array is effectively [0, 1, ..., N-1].
    // We pair the i-th smallest element of A (which is A[i] after sorting)
    // with the i-th smallest target value (which is i).
    // The cost for this pairing is |A[i] - i|.
    // The total sum of operations can be large, so 'long long' is necessary.
    long long total_operations = 0;
    for (int i = 0; i < N; ++i) {
        total_operations += std::abs(A[i] - i);
    }

    // Output the minimum number of operations for the current test case.
    std::cout << total_operations << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
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