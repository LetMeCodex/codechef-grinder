# [Fence Colouring (FENCECOL)](https://www.codechef.com/problems/FENCECOL)
- **Difficulty Rating**: 1131
- **Solved in**: 1 attempt(s)

## Problem Summary

We are given `N` fences, initially all painted with colour 1. We are also given a target configuration `A`, where `A[i]` is the desired colour for fence `i`. We need to find the minimum time (in minutes) to achieve the target configuration using two types of operations:
1.  **Individual Fence Colouring**: Paint a single fence `i` with any colour `C`. This costs 1 minute.
2.  **Global Fence Colouring**: Paint all `N` fences with any colour `C`. This also costs 1 minute.

## Intuition & Mathematical Observation

The problem asks for the minimum number of operations. We start with all fences being colour 1. Let's analyze the possible strategies:

**Strategy 1: Only use individual fence colouring operations.**
*   For each fence `i`, if its target colour `A[i]` is 1, no operation is needed for this fence as it's already colour 1.
*   If its target colour `A[i]` is not 1, we must perform an individual colouring operation on fence `i` to change its colour from 1 to `A[i]`. This costs 1 minute per such fence.
*   The total cost for this strategy is simply the count of fences `i` for which `A[i] != 1`. Let's call this `count_not_1`.

**Strategy 2: Use one global fence colouring operation, then individual operations.**
*   We can perform one global operation to change all `N` fences to some colour `K`. This costs 1 minute.
*   After this global operation, all fences are colour `K`. Now, for each fence `i`, if its target colour `A[i]` is not `K`, we need to perform an individual colouring operation on fence `i`.
*   To minimize the number of *subsequent* individual operations, we should choose `K` to be the colour that appears most frequently in the target array `A`. Let `max_freq` be the maximum frequency of any colour in `A`. If we choose `K` to be this most frequent colour, then `max_freq` fences will already be the correct colour `K` after the global operation. The remaining `N - max_freq` fences will need individual operations.
*   The total cost for this strategy would be `1` (for the global operation) + `(N - max_freq)` (for individual operations).

**Comparing the strategies:**

1.  **Base Case**: If all fences in the target array `A` are already colour 1 (i.e., `count_not_1 == 0`), then no operations are needed. The cost is 0.
2.  **General Case**: If `count_not_1 > 0`, it means at least one fence needs to change from colour 1, so we need at least one operation. In this scenario, the minimum cost will be the minimum of the costs from Strategy 1 and Strategy 2:
    `min(count_not_1, 1 + (N - max_freq))`

The solution involves iterating through the target colours `A[i]` once to:
*   Count `count_not_1` (fences whose target colour is not 1).
*   Calculate `max_freq` (the maximum frequency of any colour in `A`).

Then, apply the logic described above to determine the minimum cost.

**Example:**
`N = 5`, `A = [1, 2, 1, 3, 2]`

1.  **Calculate `count_not_1`**: Fences at index 1 (colour 2), 3 (colour 3), 4 (colour 2) are not colour 1. So, `count_not_1 = 3`.
    *   Cost using Strategy 1: 3 minutes.

2.  **Calculate `max_freq`**:
    *   Frequencies in `A`: Colour 1 appears 2 times, Colour 2 appears 2 times, Colour 3 appears 1 time.
    *   `max_freq = 2` (achieved by colour 1 or colour 2).
    *   Cost using Strategy 2: `1 + (N - max_freq) = 1 + (5 - 2) = 1 + 3 = 4` minutes.

3.  **Minimum Cost**: `min(3, 4) = 3`.

## Complexity Analysis

*   **Time Complexity**: $O(N)$
    *   The dominant part of the solution is a single loop that iterates `N` times to read the target colours `A[i]`. Inside the loop, operations like reading input, incrementing frequency, and comparisons are all $O(1)$.
    *   The calculations outside the loop are $O(1)$.
    *   For `T` test cases, the total time complexity is $O(T \cdot N)$.

*   **Space Complexity**: $O(N)$
    *   A `std::vector<int> freq` of size `N+1` is used to store the frequencies of colours. This requires $O(N)$ space.
    *   All other variables (`n`, `count_not_1`, `max_freq`, `color_ai`, `ans`, `t`) use $O(1)$ space.

## Solution Code

```cpp
#include <iostream> // Required for std::cin, std::cout
#include <vector>   // Required for std::vector
#include <algorithm> // Required for std::min, std::max

// Function to solve a single test case
void solve() {
    int n;
    std::cin >> n; // Read the number of fences

    // freq vector to store the frequency of each colour.
    // Since colours are 1-indexed up to N, size N+1 is appropriate.
    // Initialized to all zeros.
    std::vector<int> freq(n + 1, 0); 
    
    int count_not_1 = 0; // Counts fences that are not colour 1 in the target array A
    int max_freq = 0;    // Stores the maximum frequency of any colour in A

    // Loop through each fence to read its target colour A_i
    for (int i = 0; i < n; ++i) {
        int color_ai;
        std::cin >> color_ai; // Read A_i

        // If the target colour is not 1, we need to change it from the initial state (all 1s).
        if (color_ai != 1) {
            count_not_1++;
        }

        // Increment the frequency for the current colour
        freq[color_ai]++;
        
        // Update max_freq if the current colour's frequency is higher
        if (freq[color_ai] > max_freq) {
            max_freq = freq[color_ai];
        }
    }

    // Case 1: All fences are already colour 1 in the target state.
    // This means count_not_1 will be 0. No operations needed.
    if (count_not_1 == 0) {
        std::cout << 0 << "\n";
    } else {
        // Case 2: At least one fence needs to change from colour 1.
        // We need at least one operation.

        // Option A: Only use individual fence colouring operations.
        // Starting from all fences being colour 1, we change each fence i
        // where A_i is not 1. This costs 1 minute per such fence.
        // Total cost for Option A: count_not_1.
        
        // Option B: Use one global operation first, then individual operations.
        // The global operation changes all N fences to some colour K. This costs 1 minute.
        // To minimize subsequent individual operations, K should be chosen as the
        // most frequent colour in the target array A (which is represented by max_freq).
        // After the global operation to colour K, we need to individually colour
        // all fences whose target colour A_i is not K. The number of such fences is N - max_freq.
        // Total cost for Option B: 1 (for global op) + (N - max_freq) (for individual ops).
        
        int ans = std::min(count_not_1, 1 + (n - max_freq));
        std::cout << ans << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is crucial for competitive programming problems with large I/O.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }

    return 0;
}
```