# [Sums in a Triangle (SUMTRIAN)](https://www.codechef.com/problems/SUMTRIAN)
- **Difficulty Rating**: 869
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the maximum total sum from top to bottom in a given triangle of numbers. We start at the top of the triangle and can move to an adjacent number on the row below. Specifically, from a number `triangle[i][j]`, we can move to either `triangle[i+1][j]` (directly below) or `triangle[i+1][j+1]` (below and to the right). We need to find the path that yields the largest sum.

## Intuition & Mathematical Observation

This is a classic dynamic programming problem. The key idea is to work from the bottom of the triangle upwards.

Consider an element `triangle[i][j]`. If we want to find the maximum path sum starting from this element and going down to the base of the triangle, we know that the next step must be either `triangle[i+1][j]` or `triangle[i+1][j+1]`. To maximize the sum, we should choose the path that yields a larger sum from those two options.

This leads to the following recurrence relation for the maximum path sum `DP[i][j]` starting from `triangle[i][j]` down to the base:
`DP[i][j] = triangle[i][j] + max(DP[i+1][j], DP[i+1][j+1])`

The base cases for this recurrence are the elements in the last row (`n-1`). For these elements, `DP[n-1][j] = triangle[n-1][j]`, as there are no further rows to move to.

We can implement this by iterating from the second-to-last row (`n-2`) up to the top row (`0`). For each element `triangle[i][j]`, we update its value to `triangle[i][j] + max(triangle[i+1][j], triangle[i+1][j+1])`. By doing this, `triangle[i][j]` will store the maximum path sum starting from that position down to the base.

After iterating through all rows up to the top, the element `triangle[0][0]` will contain the maximum total sum from the top of the triangle to its base. This approach modifies the input triangle in-place, effectively using it as our DP table.

## Complexity Analysis

-   **Time Complexity**: $O(N^2)$
    -   Reading the input triangle: The triangle has `N * (N + 1) / 2` elements, which is $O(N^2)$.
    -   Dynamic programming calculation: The outer loop runs from `N-2` down to `0` (N-1 iterations). The inner loop runs `i+1` times for each `i`. The total number of operations for the DP part is approximately `(N-1) + (N-2) + ... + 1 = N * (N-1) / 2`, which is $O(N^2)$.
    -   Overall, the dominant factor is $O(N^2)$.

-   **Space Complexity**: $O(N^2)$
    -   We store the entire triangle in a `std::vector<std::vector<int>>`. This requires space proportional to the number of elements in the triangle, which is `N * (N + 1) / 2`, hence $O(N^2)$.
    -   The dynamic programming approach modifies this structure in-place, so no significant additional space is required.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // Required for std::max

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int n; // Number of rows in the triangle
        std::cin >> n;

        // Declare a 2D vector to store the triangle.
        // triangle[i] will store the elements of the i-th row.
        std::vector<std::vector<int>> triangle(n);

        // Read the triangle elements
        for (int i = 0; i < n; ++i) {
            // Each row i has i+1 elements (0-indexed)
            triangle[i].resize(i + 1);
            for (int j = 0; j <= i; ++j) {
                std::cin >> triangle[i][j];
            }
        }

        // Dynamic programming approach: Bottom-up
        // We iterate from the second-to-last row up to the first row.
        // For each element, we update its value to be its current value
        // plus the maximum of the two elements directly below it in the next row.
        for (int i = n - 2; i >= 0; --i) { // Iterate from row n-2 up to row 0
            for (int j = 0; j <= i; ++j) { // Iterate through elements in the current row i
                // Update triangle[i][j] with the maximum path sum starting from it
                // down to the base.
                triangle[i][j] += std::max(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }

        // After the loops complete, triangle[0][0] will contain the maximum
        // path sum from the top of the triangle to its base.
        std::cout << triangle[0][0] << "\n";
    }
    return 0;
}

```