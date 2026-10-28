# [Bear and Ladder (BRLADDER)](https://www.codechef.com/problems/BRLADDER)
- **Difficulty Rating**: 999
- **Solved in**: 2 attempt(s)

## Problem Summary

The problem describes a network of `N` cities, numbered from 1 to `N`. Roads exist between cities `a` and `b` based on specific conditions. We are given `Q` queries, and for each query, we need to determine if a road exists between two distinct cities `a` and `b`.

The conditions for a road to exist between cities `a` and `b` are:
1.  The absolute difference between `a` and `b` is 1 (`|a - b| = 1`), AND the minimum of `a` and `b` is an odd number (`min(a, b) % 2 == 1`).
    *Examples*: (1,2), (3,4), (5,6)
2.  The absolute difference between `a` and `b` is 2 (`|a - b| = 2`).
    *Examples*: (1,3), (2,4), (3,5), (4,6)

If neither of these conditions is met, no road exists. City numbers `a` and `b` can be up to $10^9$.

## Intuition & Mathematical Observation

The problem statement directly provides the rules for road existence, making the solution straightforward. The core idea is to translate these rules into conditional logic.

Let `diff = |a - b|`.

1.  **Case 1: `diff == 1`**
    If the cities are consecutive (e.g., 1 and 2, or 2 and 3), a road exists only if the smaller city is odd.
    *   If `min(a, b)` is odd (e.g., `a=1, b=2` or `a=2, b=1`), then `1 % 2 == 1`, so a road exists.
    *   If `min(a, b)` is even (e.g., `a=2, b=3` or `a=3, b=2`), then `2 % 2 == 0`, so no road exists.

2.  **Case 2: `diff == 2`**
    If the cities differ by exactly 2 (e.g., 1 and 3, or 2 and 4), a road *always* exists, regardless of their parity.
    *   If `a` and `b` are both odd (e.g., `a=1, b=3`), `diff` is 2.
    *   If `a` and `b` are both even (e.g., `a=2, b=4`), `diff` is 2.
    In both scenarios, a road exists.

3.  **Case 3: `diff > 2`**
    If the absolute difference between `a` and `b` is anything other than 1 or 2, no road exists according to the problem rules.

The solution simply implements these three conditions using `if-else if-else` statements. The use of `long long` for city numbers `a` and `b` is crucial because they can be as large as $10^9$. The input/output is handled using `scanf` and `printf` for efficiency in C++.

## Complexity Analysis

*   **Time Complexity**: $O(Q)$
    For each query, we perform a constant number of arithmetic operations (absolute difference, minimum, modulo, comparisons). These operations take $O(1)$ time. Since there are `Q` queries, the total time complexity is $O(Q)$. Given $Q \le 10^5$, this is highly efficient and well within typical time limits.

*   **Space Complexity**: $O(1)$
    The solution uses a fixed amount of memory to store variables like `Q`, `a`, `b`, and `diff`. This memory usage does not scale with the input size (other than `Q` itself, which is a single integer). Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <cstdio>   // For scanf, printf
#include <cmath>    // For std::abs
#include <algorithm> // For std::min

int main() {
    // For scanf/printf, no need for ios_base::sync_with_stdio(false) or cin.tie(NULL).
    // These optimizations are specific to C++ iostreams (cin/cout).

    int Q;
    scanf("%d", &Q); // Read the number of queries using scanf

    while (Q--) { // Loop Q times for each query
        long long a, b;
        scanf("%lld %lld", &a, &b); // Read the two distinct cities using scanf with %lld for long long

        // Calculate the absolute difference between a and b.
        // std::abs() is overloaded for long long in <cmath> and works independently of I/O method.
        long long diff = std::abs(a - b);

        if (diff == 1) {
            // Case 1: Cities are consecutive (e.g., 1-2, 3-4).
            // A road exists if the smaller city is odd.
            // This corresponds to roads of type (2*i+1, 2*i+2), where 2*i+1 is always odd.
            // std::min() is overloaded for long long in <algorithm> and works independently of I/O method.
            if (std::min(a, b) % 2 == 1) {
                printf("YES\n"); // Print "YES" using printf
            } else {
                // If the smaller city is even (e.g., 2-3, 4-5), no road of this type.
                printf("NO\n"); // Print "NO" using printf
            }
        } else if (diff == 2) {
            // Case 2: Cities differ by 2 (e.g., 1-3, 2-4, 3-5, 4-6).
            // If two numbers differ by 2, they must have the same parity.
            // - If both are odd (e.g., 1-3), it matches the "consecutive odd numbers" rule.
            // - If both are even (e.g., 2-4), it matches the "consecutive even numbers" rule.
            // In both scenarios, a road exists.
            printf("YES\n"); // Print "YES" using printf
        } else {
            // Case 3: Cities differ by more than 2.
            // Based on the problem description, no roads exist for differences greater than 2.
            printf("NO\n"); // Print "NO" using printf
        }
    }

    return 0; // Indicate successful execution
}
```