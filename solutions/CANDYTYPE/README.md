# [Candy Types (CANDYTYPE)](https://www.codechef.com/problems/CANDYTYPE)
- **Difficulty Rating**: 723
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the most frequent candy color among $N$ given candies. Each candy has a color represented by an integer from $1$ to $N$. If there are multiple colors that appear with the same maximum frequency, we must output the smallest color among them. We need to solve this for $T$ test cases.

## Intuition & Mathematical Observation

The core of this problem is to count the occurrences (frequencies) of each candy color and then identify the color with the highest frequency, applying a specific tie-breaking rule.

1.  **Counting Frequencies**: Since candy colors are integers from $1$ to $N$, a simple and efficient way to store their frequencies is to use an array (or `std::vector` in C++). We can declare a vector `counts` of size `N+1` (to allow 1-based indexing for colors $1$ to $N$) and initialize all its elements to $0$. As we read each candy color, we increment the corresponding count in our `counts` vector. For example, if we read color `C`, we do `counts[C]++`.

2.  **Finding Maximum Frequency with Tie-Breaking**: After counting all frequencies, we need to iterate through our `counts` vector to find the color with the maximum frequency. The tie-breaking rule is crucial: if multiple colors have the same maximum frequency, we must choose the *smallest* color.
    *   We can initialize `max_freq = 0` and `result_color = -1` (or any invalid color).
    *   We then iterate through the possible colors from `1` to `N` (inclusive). This iteration order is key for the tie-breaking rule.
    *   For each `color` from `1` to `N`:
        *   If `counts[color]` is *greater than* `max_freq`, it means we've found a new color that appears more frequently than any we've seen so far. In this case, we update `max_freq = counts[color]` and `result_color = color`.
        *   If `counts[color]` is *equal to* `max_freq`, we do *not* update `result_color`. Why? Because we are iterating `color` in increasing order. If `result_color` already holds a color with `max_freq`, and we encounter a new `color` with the same `max_freq`, this new `color` must be *larger* than the current `result_color` (due to our iteration order). Since the problem asks for the *smallest* color in case of a tie, we stick with the `result_color` we already have.

This approach correctly handles both finding the maximum frequency and applying the smallest-color tie-breaking rule efficiently.

## Complexity Analysis

*   **Time Complexity**:
    *   For each test case:
        *   Reading `N`: $O(1)$.
        *   Initializing the `counts` vector of size `N+1`: $O(N)$.
        *   Reading `N` candy colors and updating their frequencies: This involves $N$ read operations and $N$ increment operations, each taking $O(1)$ time. Total $O(N)$.
        *   Iterating through the `counts` vector from $1$ to $N$ to find the maximum frequency and apply tie-breaking: This involves $N$ comparisons and potential assignments, each taking $O(1)$ time. Total $O(N)$.
    *   Therefore, for a single test case, the total time complexity is $O(N) + O(N) + O(N) = O(N)$.
    *   Given $T$ test cases, the overall time complexity is $O(T \cdot N)$.

*   **Space Complexity**:
    *   For each test case:
        *   The `counts` vector stores $N+1$ integers. This requires $O(N)$ space.
        *   Other variables (`N`, `color`, `max_freq`, `result_color`, `T`) use $O(1)$ space.
    *   Thus, the total space complexity is $O(N)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries, as requested

void solve() {
    int N;
    std::cin >> N; // Read the number of candies

    // Create a vector to store frequencies of candy colours.
    // Size N+1 to use 1-based indexing for colours (from 1 to N).
    // Initialize all counts to 0.
    std::vector<int> counts(N + 1, 0);

    // Read N candy colours and update their frequencies
    for (int i = 0; i < N; ++i) {
        int color;
        std::cin >> color;
        counts[color]++; // Increment count for the current colour
    }

    int max_freq = 0;       // Stores the maximum frequency found so far
    int result_color = -1;  // Stores the colour with the maximum frequency (smallest in case of tie)

    // Iterate through possible colours from 1 to N
    // This iteration order is crucial for correctly handling the tie-breaking rule
    // (smallest colour in case of a tie).
    for (int color = 1; color <= N; ++color) {
        if (counts[color] > max_freq) {
            // If current colour has a higher frequency, update max_freq and result_color
            max_freq = counts[color];
            result_color = color;
        }
        // If counts[color] == max_freq, we do nothing.
        // This is because we want the *smallest* colour in case of a tie.
        // Since we iterate 'color' in increasing order (1, 2, 3, ...),
        // 'result_color' will already hold the smallest colour encountered so far
        // that has 'max_freq'. Any subsequent 'color' with the same 'max_freq'
        // would be larger, so we don't update 'result_color'.
    }

    std::cout << result_color << "\n"; // Output the result
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

    return 0;
}
```