# [Candy Distribution (CANDYDIST)](https://www.codechef.com/problems/CANDYDIST)
- **Difficulty Rating**: 668
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef has `N` candies and `M` friends. He wants to distribute the candies among his `M` friends according to three specific conditions:
1.  **Equal Distribution**: Each friend must receive an equal number of candies.
2.  **All Candies Used**: All `N` candies must be distributed; none should be left over.
3.  **Even Count Per Friend**: The number of candies each friend receives must be an even number.

The task is to determine if it's possible to distribute the candies satisfying all three conditions. Output "Yes" if possible, and "No" otherwise.

## Intuition & Mathematical Observation

Let's denote the total number of candies as `N` and the number of friends as `M`.
Let `C` be the number of candies each friend receives.

We need to satisfy three conditions:

1.  **Equal Distribution & All Candies Used**:
    If each friend receives `C` candies, and there are `M` friends, then the total candies distributed would be `M * C`. For all `N` candies to be distributed equally, `M * C` must be exactly equal to `N`. This implies that `N` must be perfectly divisible by `M`. If `N` is not divisible by `M`, it's impossible to distribute them equally and use all of them.
    Mathematically, this means `N % M == 0`.
    If this condition holds, then `C = N / M`.

2.  **Even Count Per Friend**:
    The problem states that each friend must receive an *even* number of candies.
    This means `C` must be an even number.
    Mathematically, this means `C % 2 == 0`.

Combining these observations:
For a "Yes" output, both of the following must be true:
*   `N` must be perfectly divisible by `M` (i.e., `N % M == 0`).
*   The result of `N / M` (which is `C`, the candies per friend) must be an even number (i.e., `(N / M) % 2 == 0`).

If both of these conditions are met, then it's possible to distribute the candies as required. Otherwise, it's not possible.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    The program processes `T` test cases. For each test case, it performs a few constant-time operations: two integer reads, one modulo operation, one division operation, another modulo operation, and one print operation. Since the number of operations per test case is constant and does not depend on the input values `N` or `M` (beyond their size as integers), the total time complexity is directly proportional to the number of test cases, `T`.

*   **Space Complexity**: $O(1)$
    The program uses a fixed number of integer variables (`T`, `N`, `M`, `candies_per_friend`) to store input and intermediate results. The memory usage for these variables remains constant regardless of the input values or the number of test cases. Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream and other standard libraries

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases

    while (T--) { // Loop T times for each test case
        int N, M;
        std::cin >> N >> M; // Read N (number of candies) and M (number of friends)

        // Condition 1: Check if N candies can be distributed equally among M friends
        // and all candies are used. This means N must be perfectly divisible by M.
        if (N % M == 0) {
            // If N is divisible by M, calculate how many candies each friend gets.
            int candies_per_friend = N / M;
            
            // Condition 2: Check if the number of candies each friend gets is an even number.
            if (candies_per_friend % 2 == 0) {
                // Both conditions are met: equal distribution and an even number of candies per friend.
                std::cout << "Yes\n";
            } else {
                // Condition 1 is met, but Condition 2 is not (candies_per_friend is odd).
                std::cout << "No\n";
            }
        } else {
            // Condition 1 is not met: N is not perfectly divisible by M.
            // It's impossible to distribute candies equally and use all of them.
            std::cout << "No\n";
        }
    }

    return 0; // Indicate successful execution
}
```