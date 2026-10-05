# [Magical World (P2149)](https://www.codechef.com/problems/P2149)
- **Difficulty Rating**: 1005
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a rectangle with dimensions $A$ and $B$, and a square with side length $X$. We want to make the area of the rectangle less than or equal to the area of the square. We can perform an operation that costs 1 unit: change either dimension ($A$ or $B$) of the rectangle to any positive integer. We need to find the minimum number of operations required.

## Intuition & Mathematical Observation

The goal is to achieve $A_{new} \times B_{new} \le X \times X$, where $A_{new}$ and $B_{new}$ are the dimensions of the rectangle after some operations. We want to minimize the number of operations.

Let the initial rectangle area be $A \times B$ and the target square area be $S = X \times X$.

**Case 0: Cost is 0**
If the initial area of the rectangle is already less than or equal to the area of the square, i.e., $A \times B \le S$, then no operations are needed. The cost is 0.

**Case 1: Cost is 1**
If $A \times B > S$, we check if we can achieve the goal with just one operation. An operation allows us to change either $A$ or $B$ to any positive integer. To minimize the cost, we want to make the largest possible reduction in area with a single change. The smallest possible positive integer for a dimension is 1.

*   **Option 1: Change dimension A.**
    We can change $A$ to a new value $A_{new}$. To satisfy the condition $A_{new} \times B \le S$, the smallest possible value for $A_{new}$ is 1. If we set $A_{new} = 1$, the condition becomes $1 \times B \le S$, or simply $B \le S$. If this condition holds, we can change $A$ to 1, and the cost is 1 (assuming $A$ was not already 1, which is implicitly handled because we are in the case where $A \times B > S$).

*   **Option 2: Change dimension B.**
    Similarly, we can change $B$ to a new value $B_{new}$. To satisfy the condition $A \times B_{new} \le S$, the smallest possible value for $B_{new}$ is 1. If we set $B_{new} = 1$, the condition becomes $A \times 1 \le S$, or simply $A \le S$. If this condition holds, we can change $B$ to 1, and the cost is 1.

Therefore, if $A \times B > S$, and either $A \le S$ or $B \le S$, we can achieve the goal with one operation. For example, if $A \le S$, we can change $B$ to 1, making the new area $A \times 1 = A$, which is $\le S$.

**Case 2: Cost is 2**
If $A \times B > S$, and neither $A \le S$ nor $B \le S$ is true, it means that changing one dimension to 1 is not sufficient. Specifically, if $A > S$ and $B > S$, then setting $A_{new}=1$ results in $1 \times B = B > S$, and setting $B_{new}=1$ results in $A \times 1 = A > S$.

In this scenario, we need at least two operations. We can always achieve the goal with two operations by changing both $A$ and $B$ to 1. The new dimensions would be $A_{new}=1$ and $B_{new}=1$. The new area would be $1 \times 1 = 1$. Since $X \ge 1$, $S = X \times X \ge 1$. Thus, $1 \le S$ is always true. This strategy costs 2 operations.

**Summary of Logic:**
1.  If $A \times B \le X \times X$, the cost is 0.
2.  Else if $A \le X \times X$ or $B \le X \times X$, the cost is 1.
3.  Else (if $A \times B > X \times X$ and $A > X \times X$ and $B > X \times X$), the cost is 2.

The constraints $A, B, X \le 10$ ensure that $A \times B$ and $X \times X$ will not overflow standard integer types, but using `long long` is a safe practice.

## Complexity Analysis

*   **Time Complexity**: $O(1)$ per test case. The solution involves a few arithmetic operations and comparisons, which take constant time. Since there are $T$ test cases, the total time complexity is $O(T)$.

*   **Space Complexity**: $O(1)$. The solution uses a fixed amount of memory for variables, regardless of the input size.

## Solution Code

```cpp
#include <iostream>
#include <algorithm>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        long long a, b, x; // Dimensions of rectangle (a, b) and side of square (x)
        std::cin >> a >> b >> x;

        long long rect_area = a * b;
        long long square_area = x * x;

        // Case 0: Rectangle area is already less than or equal to square area
        if (square_area >= rect_area) {
            std::cout << 0 << "\n";
        }
        // Case 1: Rectangle area is greater than square area, check if 1 operation is sufficient
        // We can achieve the goal with 1 operation if we can make one dimension 1
        // and the resulting area is <= square_area.
        // This is possible if changing A to 1 makes area <= square_area (i.e., b <= square_area)
        // OR if changing B to 1 makes area <= square_area (i.e., a <= square_area).
        else if (a <= square_area || b <= square_area) {
            std::cout << 1 << "\n";
        }
        // Case 2: If 0 or 1 operation is not enough, then 2 operations are always sufficient.
        // We can change both A and B to 1, resulting in an area of 1*1=1.
        // Since X >= 1, square_area = X*X >= 1, so 1 <= square_area is always true.
        else {
            std::cout << 2 << "\n";
        }
    }
    return 0;
}
```