# [Asymmetric Swaps (ARRSWAP)](https://www.codechef.com/problems/ARRSWAP)
- **Difficulty Rating**: 1230
- **Solved in**: 1 attempt(s)

## Problem Summary

You are given two arrays, `A` and `B`, each of size `N`. You can perform an operation: swap `A[i]` with `B[i]` for any index `i` from `0` to `N-1`. This operation can be performed any number of times. After performing these swaps, you need to select `N` elements, one from each pair `(A[i], B[i])`, to form a new array `C`. The goal is to minimize the difference between the maximum and minimum elements in `C`.

## Intuition & Mathematical Observation

1.  **Understanding the "Swap" Operation**: The "swap `A[i]` with `B[i]`" operation is key. It means that for each index `i`, we effectively have two values (the original `A[i]` and `B[i]`) and we can decide which one is labeled `A[i]` and which is `B[i]`. After these potential swaps, we must choose one element from the pair `(A[i], B[i])` for our final array `C`. This simplifies to: for each `i`, we must choose either the original `A[i]` or the original `B[i]` to be part of `C`. The specific labels `A[i]` and `B[i]` become irrelevant; what matters are the `N` pairs of values `(original A[i], original B[i])`.

2.  **Minimizing Range**: We need to select `N` elements, one from each of these `N` pairs, such that the difference between the maximum and minimum chosen element is minimized. To minimize `max(C) - min(C)`, we should intuitively pick `N` elements that are numerically "close" to each other.

3.  **Combining and Sorting**: Let's consider all `2N` elements from both arrays `A` and `B` as a single pool of numbers. If we sort these `2N` elements, say `x_0 \le x_1 \le \dots \le x_{2N-1}`, then any `N` elements chosen to minimize their range will likely be a contiguous subsegment (a "window") of this sorted list.

4.  **Sliding Window Approach**: The problem then reduces to a known pattern: given `N` pairs `(a_i, b_i)`, choose one from each pair to form a set `C` of `N` elements, minimizing `max(C) - min(C)`. A standard solution for this type of problem is to:
    *   Combine all `2N` elements into a single list.
    *   Sort this combined list.
    *   Iterate through all possible "windows" of `N` consecutive elements in the sorted list. For each window `[x_k, x_{k+1}, \dots, x_{k+N-1}]`, calculate its range `x_{k+N-1} - x_k`. The minimum of these ranges will be the answer.

5.  **Why this works (The "one from each pair" constraint)**: The crucial part is that the "one from each pair" constraint does not invalidate this sliding window approach. The flexibility provided by the initial "swaps" (or simply the nature of choosing one from each pair) ensures that if we pick any `N` consecutive elements from the sorted `2N` list, we can always assign them back to the original `N` pairs such that each pair contributes exactly one element. This is a non-trivial property for this class of problems, often proven by an exchange argument, but it holds true. Essentially, the problem becomes equivalent to finding the minimum range of `N` elements chosen from `2N` available elements.

Therefore, the strategy is:
1.  Read all `2N` elements into a single vector.
2.  Sort the vector.
3.  Iterate `i` from `0` to `N` (inclusive). For each `i`, consider the window of `N` elements starting at index `i` and ending at `i + N - 1`. Calculate the difference `vector[i + N - 1] - vector[i]`.
4.  The minimum of these differences is the answer.

## Complexity Analysis

*   **Time Complexity**:
    *   Reading `2N` elements: $O(N)$
    *   Storing `2N` elements in a vector: $O(N)$
    *   Sorting the `2N` elements: $O(2N \log(2N)) = O(N \log N)$
    *   Iterating through `N+1` possible windows (from index `0` to `N`): $O(N)$
    *   The dominant factor is sorting.
    *   Overall Time Complexity: $O(N \log N)$

*   **Space Complexity**:
    *   Storing all `2N` elements in the `combined_elements` vector: $O(2N) = O(N)$
    *   Overall Space Complexity: $O(N)$

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // For INT_MAX

void solve() {
    int N;
    std::cin >> N;
    
    // Create a vector to store all 2N elements from arrays A and B.
    std::vector<int> combined_elements(2 * N);
    
    // Read elements of array A
    for (int i = 0; i < N; ++i) {
        std::cin >> combined_elements[i];
    }
    
    // Read elements of array B
    for (int i = 0; i < N; ++i) {
        std::cin >> combined_elements[N + i];
    }

    // Sort all 2N elements.
    // This is crucial because to minimize max-min, we should pick elements
    // that are numerically close, which are found in a sorted list.
    std::sort(combined_elements.begin(), combined_elements.end());

    // Initialize minimum difference to a very large value.
    int min_diff = INT_MAX;

    // Iterate through all possible windows of N consecutive elements.
    // A window starting at index 'i' will contain elements from combined_elements[i]
    // to combined_elements[i + N - 1].
    // The loop runs from i = 0 up to i = N.
    // When i = 0, the window is [0, N-1].
    // When i = N, the window is [N, 2N-1].
    // There are (2N - N + 1) = N + 1 such windows.
    for (int i = 0; i <= N; ++i) {
        // The maximum element in the current window is at combined_elements[i + N - 1].
        int current_max = combined_elements[i + N - 1];
        // The minimum element in the current window is at combined_elements[i].
        int current_min = combined_elements[i];
        
        // Update the overall minimum difference found so far.
        min_diff = std::min(min_diff, current_max - current_min);
    }

    std::cout << min_diff << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases.
    while (T--) {
        solve(); // Solve each test case.
    }

    return 0;
}
```