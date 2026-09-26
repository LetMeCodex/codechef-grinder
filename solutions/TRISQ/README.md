# Fit Squares in Triangle (TRISQ)

## Problem Statement

You are given a right-angled isosceles triangle with base $B$. You need to find the maximum number of $2 \times 2$ squares that can be fitted inside this triangle. One side of each square must be parallel to the base of the triangle.

The problem statement mentions "Base is the shortest side of the triangle". In a right-angled isosceles triangle, if the base is the shortest side, it implies that the two equal sides are longer. This means the right angle is opposite the base. However, the standard interpretation of "right-angled isosceles triangle of base B" usually implies that the two equal sides have length B, and the right angle is between them. The hypotenuse would then be $B\sqrt{2}$.

Given the sample cases and the constraint that one side of the square must be parallel to the base, the most consistent interpretation is that the triangle has two legs of length $B$, meeting at a right angle. The vertices can be considered as $(0,0)$, $(B,0)$, and $(0,B)$. The hypotenuse lies on the line $x+y=B$.

We are fitting $2 \times 2$ squares. Let the bottom-left corner of a square be at coordinates $(x, y)$. For the square to be entirely within the triangle, the following conditions must hold:
1. $x \ge 0$ (square is to the right of the y-axis)
2. $y \ge 0$ (square is above the x-axis)
3. $x+2 \le B$ (square does not extend beyond the leg along the x-axis)
4. $y+2 \le B$ (square does not extend beyond the leg along the y-axis)
5. The top-right corner of the square, $(x+2, y+2)$, must lie on or below the hypotenuse $x+y=B$. This translates to $(x+2) + (y+2) \le B$, which simplifies to $x+y \le B-4$.

The problem then reduces to finding the maximum number of $2 \times 2$ squares whose bottom-left corners $(x,y)$ satisfy $x \ge 0$, $y \ge 0$, and $x+y \le B-4$. The coordinates $x$ and $y$ for the bottom-left corner of each $2 \times 2$ square must be multiples of 2 if we consider a grid of $2 \times 2$ cells.

Let's analyze the number of squares that can fit in layers.
Consider the base of the triangle along the x-axis. We can place squares with their bottom edge on the x-axis ($y=0$). The bottom-left corners can be at $(0,0), (2,0), (4,0), \dots, (2k,0)$.
For a square at $(2k, 0)$, its top-right corner is $(2k+2, 2)$. This point must satisfy $(2k+2) + 2 \le B$, which means $2k+4 \le B$, or $2k \le B-4$. Thus, $k \le \lfloor \frac{B-4}{2} \rfloor$. The number of possible values for $k$ (starting from 0) is $\lfloor \frac{B-4}{2} \rfloor + 1$. This is the number of squares in the first row.

Now consider the second row of squares, where the bottom edge is at $y=2$. The bottom-left corners can be at $(0,2), (2,2), (4,2), \dots, (2k',2)$. The top-right corner is $(2k'+2, 4)$. This point must satisfy $(2k'+2) + 4 \le B$, which means $2k'+6 \le B$, or $2k' \le B-6$. Thus, $k' \le \lfloor \frac{B-6}{2} \rfloor$. The number of squares in the second row is $\lfloor \frac{B-6}{2} \rfloor + 1$.

Generalizing, for the $i$-th row (0-indexed from the bottom, so $y=2i$), the number of squares is $\lfloor \frac{B - 2i - 4}{2} \rfloor + 1$, provided $B - 2i - 4 \ge 0$.

The total number of squares is the sum of squares in each row:
$$ \sum_{i=0}^{\lfloor (B-2)/2 \rfloor} \max(0, \lfloor \frac{B - 2i - 4}{2} \rfloor + 1) $$

Let's test this with sample cases:
- $B=4$: $\lfloor (4-2)/2 \rfloor = 1$. $i$ goes from 0 to 1.
  - $i=0$: $\lfloor \frac{4-0-4}{2} \rfloor + 1 = \lfloor 0 \rfloor + 1 = 1$.
  - $i=1$: $\lfloor \frac{4-2-4}{2} \rfloor + 1 = \lfloor -1 \rfloor + 1 = 0$.
  Total = 1. Correct.

- $B=6$: $\lfloor (6-2)/2 \rfloor = 2$. $i$ goes from 0 to 2.
  - $i=0$: $\lfloor \frac{6-0-4}{2} \rfloor + 1 = \lfloor 1 \rfloor + 1 = 2$.
  - $i=1$: $\lfloor \frac{6-2-4}{2} \rfloor + 1 = \lfloor 0 \rfloor + 1 = 1$.
  - $i=2$: $\lfloor \frac{6-4-4}{2} \rfloor + 1 = \lfloor -1 \rfloor + 1 = 0$.
  Total = 2 + 1 = 3. Correct.

- $B=8$: $\lfloor (8-2)/2 \rfloor = 3$. $i$ goes from 0 to 3.
  - $i=0$: $\lfloor \frac{8-0-4}{2} \rfloor + 1 = \lfloor 2 \rfloor + 1 = 3$.
  - $i=1$: $\lfloor \frac{8-2-4}{2} \rfloor + 1 = \lfloor 1 \rfloor + 1 = 2$.
  - $i=2$: $\lfloor \frac{8-4-4}{2} \rfloor + 1 = \lfloor 0 \rfloor + 1 = 1$.
  - $i=3$: $\lfloor \frac{8-6-4}{2} \rfloor + 1 = \lfloor -1 \rfloor + 1 = 0$.
  Total = 3 + 2 + 1 = 6. Correct.

This summation can be simplified. Let $m = \lfloor \frac{B-2}{2} \rfloor$. The number of squares in row $i$ is $m-i$.
The total number of squares is $\sum_{i=0}^{m} (m-i) = m + (m-1) + \dots + 1 + 0$.
This is the $m$-th triangular number, which is given by $T_m = \frac{m(m+1)}{2}$.

The formula $m = \lfloor \frac{B-2}{2} \rfloor$ works for $B \ge 2$.
- If $B=1$, $m = \lfloor -0.5 \rfloor = -1$. The answer should be 0.
- If $B=2$, $m = \lfloor 0/2 \rfloor = 0$. $T_0 = 0$. Correct.
- If $B=3$, $m = \lfloor 1/2 \rfloor = 0$. $T_0 = 0$. Correct.
- If $B=4$, $m = \lfloor 2/2 \rfloor = 1$. $T_1 = \frac{1(2)}{2} = 1$. Correct.

So, if $B < 4$, the answer is 0. Otherwise, we calculate $m = \lfloor \frac{B-2}{2} \rfloor$ and the answer is $\frac{m(m+1)}{2}$.

In C++, integer division `(B - 2) / 2` for positive `B-2` correctly computes $\lfloor \frac{B-2}{2} \rfloor$.

## Complexity Analysis

- **Time Complexity**: $O(1)$
  The solution involves a few arithmetic operations and a conditional check, all of which take constant time.

- **Space Complexity**: $O(1)$
  The solution uses a fixed amount of memory for variables, regardless of the input size.

## Solution Code

```cpp
#include <iostream>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        int b;
        std::cin >> b; // Read the base of the triangle

        // If the base is less than 4, no 2x2 square can fit.
        if (b < 4) {
            std::cout << 0 << "\n";
        } else {
            // Calculate m = floor((B-2)/2)
            // This represents the maximum number of 'layers' of squares we can fit,
            // where each layer is 2 units high.
            // For B=4, m=1. For B=5, m=1. For B=6, m=2. For B=7, m=2.
            long long m = (b - 2) / 2;

            // The total number of squares is the m-th triangular number: m * (m + 1) / 2
            // This formula arises from summing the number of squares that can fit
            // in each horizontal 'slice' of the triangle.
            long long ans = m * (m + 1) / 2;
            std::cout << ans << "\n";
        }
    }
    return 0;
}

```