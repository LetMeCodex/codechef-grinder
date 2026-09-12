# [Scalene Triangle (SCALENE)](https://www.codechef.com/problems/SCALENE)
- **Difficulty Rating**: 430
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a given triangle is a scalene triangle. We are provided with the lengths of the three sides, $A, B, C$, which are guaranteed to be in non-decreasing order, i.e., $A \le B \le C$. A triangle is defined as scalene if all its sides have different lengths. For each test case, we need to output "YES" if the triangle is scalene, and "NO" otherwise.

## Intuition & Mathematical Observation

The definition of a scalene triangle is that all three of its sides must have distinct lengths. This means if the side lengths are $A, B, C$, then we must have $A \ne B$, $B \ne C$, and $A \ne C$.

We are given a crucial piece of information: the side lengths are provided in non-decreasing order, $A \le B \le C$.

Let's analyze the conditions for a scalene triangle under this constraint:
1.  **$A \ne B$**: Since $A \le B$, if $A \ne B$, it implies $A < B$.
2.  **$B \ne C$**: Since $B \le C$, if $B \ne C$, it implies $B < C$.

If both $A < B$ and $B < C$ are true, then it automatically follows that $A < B < C$. In this scenario, all three sides are distinct: $A$ is different from $B$, $B$ is different from $C$, and consequently, $A$ is also different from $C$. Therefore, the triangle is scalene.

Conversely, if the triangle is *not* scalene, it means at least two sides are equal. Given $A \le B \le C$:
*   If $A = B$, then the first two sides are equal. (e.g., `5 5 7`)
*   If $B = C$, then the last two sides are equal. (e.g., `5 7 7`)
*   If $A = B = C$, then all three sides are equal (an equilateral triangle), which is also not scalene. This case is covered by both $A=B$ and $B=C$.

So, for a triangle to be scalene, we simply need to check if $A \ne B$ AND $B \ne C$. If both these conditions are true, then $A < B < C$, and all sides are distinct. Otherwise, if $A=B$ or $B=C$ (or both), at least two sides are equal, and it's not a scalene triangle.

## Complexity Analysis

*   **Time Complexity**: For each test case, we perform a constant number of operations: reading three integers, two comparisons, and one output operation. This takes $O(1)$ time per test case. If there are $T$ test cases, the total time complexity will be $O(T)$. Given typical constraints for $T$ (e.g., $T \le 100$), this is extremely efficient.
*   **Space Complexity**: We only use a few integer variables to store the side lengths ($A, B, C$) and the number of test cases ($T$). This is a constant amount of memory, independent of the input values or the number of test cases. Thus, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <iostream> // Required for standard input/output operations

// Function to solve a single test case
void solve() {
    int A, B, C;
    // Read the three side lengths for the current test case
    std::cin >> A >> B >> C;

    // A triangle is scalene if all three sides are distinct.
    // The problem guarantees that the sides are given in non-decreasing order: A <= B <= C.
    //
    // If A, B, and C are distinct, it means A < B < C.
    // This implies two conditions must hold:
    // 1. A is not equal to B (A != B)
    // 2. B is not equal to C (B != C)
    //
    // If both A != B AND B != C are true, then A < B and B < C, which means A < B < C.
    // In this case, all three sides are distinct, and the triangle is scalene.
    //
    // If either A == B or B == C (or both), then at least two sides are equal,
    // and the triangle is not scalene.
    if (A != B && B != C) {
        std::cout << "YES\n"; // Output YES if scalene
    } else {
        std::cout << "NO\n";  // Output NO otherwise
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming to prevent TLE (Time Limit Exceeded)
    // on problems with large inputs, though for T=100 and small integers, it's not strictly
    // necessary but good practice.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    // Read the number of test cases
    std::cin >> T;
    // Loop T times, calling the solve function for each test case
    while (T--) {
        solve();
    }

    return 0; // Indicate successful execution
}
```