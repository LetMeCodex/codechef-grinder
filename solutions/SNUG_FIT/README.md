# [School of Geometry (SNUG_FIT)](https://www.codechef.com/problems/SNUG_FIT)
- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to form `N` rectangles using `N` given lengths (sequence `A`) and `N` given widths (sequence `B`). Each length from `A` must be paired with a unique width from `B`, and vice-versa. For each rectangle with dimensions `L x W`, the diameter of its inscribed circle is `min(L, W)`. Our goal is to find the maximum possible total sum of these `N` diameters.

## Intuition & Mathematical Observation

To maximize the sum of `min(L_i, W_i)` for `N` pairs, we need to find an optimal pairing strategy. Let's consider two pairs `(A_i, B_x)` and `(A_j, B_y)`. Suppose we have sorted sequence `A` such that `A_i <= A_j`. If `B_x > B_y`, this means we are pairing a smaller `A` with a larger `B`, and a larger `A` with a smaller `B`. Let's investigate if swapping the `B` values to form pairs `(A_i, B_y)` and `(A_j, B_x)` would improve or maintain the sum.

We need to compare the sum from the original pairing `S_orig = min(A_i, B_x) + min(A_j, B_y)` with the sum from the swapped pairing `S_swap = min(A_i, B_y) + min(A_j, B_x)`.

It's a known mathematical property that for any four numbers `a, b, c, d` such that `a <= b` and `c <= d`, the following inequality holds:
`min(a, c) + min(b, d) >= min(a, d) + min(b, c)`

In our context, let `a = A_i`, `b = A_j`, `c = B_y`, and `d = B_x`.
Since we assumed `A_i <= A_j` and `B_y < B_x` (which implies `B_y <= B_x`), these conditions are met.
Applying the inequality:
`min(A_i, B_y) + min(A_j, B_x) >= min(A_i, B_x) + min(A_j, B_y)`
This means `S_swap >= S_orig`.

This inequality demonstrates that if we have an "unsorted" pairing (where `A_i` is paired with `B_x` and `A_j` with `B_y`, but `A_i < A_j` and `B_x > B_y`), we can always swap the `B` values to pair `A_i` with `B_y` and `A_j` with `B_x`. This swap will either increase the total sum or keep it the same. By repeatedly applying this swapping logic, any arbitrary pairing can be transformed into a sorted pairing (where `A_i` is paired with `B_i` after both sequences are sorted) without decreasing the total sum.

Therefore, the optimal strategy is to sort both sequences `A` and `B` in non-decreasing order. After sorting, we pair `A[i]` with `B[i]` for all `i` from `0` to `N-1`, and sum up `min(A[i], B[i])`. This strategy ensures that smaller lengths are paired with smaller widths, and larger lengths with larger widths, which maximizes the sum of minimums.

## Complexity Analysis

*   **Time Complexity**:
    *   Reading `N` elements into `A`: $O(N)$
    *   Reading `N` elements into `B`: $O(N)$
    *   Sorting `A` using `std::sort`: `std::sort` typically uses IntroSort, which has an average and worst-case time complexity of $O(N \log N)$.
    *   Sorting `B` using `std::sort`: Similarly, $O(N \log N)$.
    *   Iterating `N` times to calculate the sum: $O(N)$
    *   The dominant operations are sorting. Thus, the total time complexity is $O(N \log N)$.

*   **Space Complexity**:
    *   `std::vector<long long> A(N)`: $O(N)$ space to store sequence A.
    *   `std::vector<long long> B(N)`: $O(N)$ space to store sequence B.
    *   Other variables (like `N`, `total_sum_of_diameters`, loop counters): $O(1)$ space.
    *   The total space complexity is $O(N)$.

## Solution Code

```cpp
#include <iostream> // Required for input/output operations (cin, cout)
#include <vector>   // Required for using std::vector
#include <algorithm> // Required for std::sort and std::min

void solve() {
    int N;
    std::cin >> N; // Read the number of rectangles

    // Declare vectors to store sequences A and B.
    // Using long long for elements to be safe, though int would suffice for A_i, B_i values.
    std::vector<long long> A(N); 
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i]; // Read elements of sequence A
    }

    std::vector<long long> B(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> B[i]; // Read elements of sequence B
    }

    // Sort both sequences A and B in non-decreasing order.
    // This is the crucial step to maximize the sum of minimums.
    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());

    long long total_sum_of_diameters = 0; // Use long long for the sum to prevent overflow
    
    // Iterate through the sorted arrays and pair A[i] with B[i].
    // The diameter of the inscribed circle for a rectangle of dimensions L x W is min(L, W).
    // Sum these minimums to get the maximum possible total sum of diameters.
    for (int i = 0; i < N; ++i) {
        total_sum_of_diameters += std::min(A[i], B[i]);
    }

    std::cout << total_sum_of_diameters << "\n"; // Print the calculated maximum sum
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
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