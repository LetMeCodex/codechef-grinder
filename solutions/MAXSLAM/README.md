# Maximum Slams (MAXSLAM)
- **Difficulty Rating**: 224
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to calculate the minimum number of years a chef needs to win at least 25 Grand Slams, given that they currently have $X$ Grand Slams. The chef wins 4 Grand Slams per year.

## Intuition & Mathematical Observation
The chef needs to reach a total of at least 25 Grand Slams.
Let $X$ be the current number of Grand Slams the chef has.
Let $Y$ be the number of years the chef plays.
In $Y$ years, the chef wins $4 \times Y$ Grand Slams.
The total number of Grand Slams after $Y$ years will be $X + 4 \times Y$.

We want to find the minimum integer $Y$ such that:
$X + 4 \times Y \ge 25$

Rearranging the inequality to solve for $Y$:
$4 \times Y \ge 25 - X$
$Y \ge \frac{25 - X}{4}$

Since $Y$ must be an integer (number of years), we need to find the smallest integer $Y$ that satisfies this condition. This is equivalent to taking the ceiling of the right-hand side.

The number of additional slams needed is $25 - X$.
Let $S = 25 - X$.
We need $4 \times Y \ge S$.
So, $Y \ge \frac{S}{4}$.

The minimum integer $Y$ is $\lceil \frac{S}{4} \rceil$.

In integer arithmetic, the ceiling of $a/b$ (where $b > 0$) can be calculated as $(a + b - 1) / b$.
In our case, $a = S = 25 - X$ and $b = 4$.
So, the minimum number of years $Y$ is $\frac{(25 - X) + 4 - 1}{4} = \frac{25 - X + 3}{4}$.

The problem constraints state $0 \le X \le 24$. This guarantees that $25 - X$ will always be at least $25 - 24 = 1$, so the number of slams to win will always be positive. Thus, we don't need to handle the case where $25 - X \le 0$ separately, as the formula will correctly yield 0 years if $X \ge 25$ (though this is not possible given the constraints).

## Complexity Analysis
- **Time Complexity**: $O(1)$
The solution involves a few arithmetic operations and a single input/output operation. These operations take constant time, regardless of the input value $X$.

- **Space Complexity**: $O(1)$
The solution uses a fixed amount of memory to store variables like `x`, `needed_slams`, `slams_to_win`, and `years`. This amount of memory does not depend on the input size.

## Solution Code
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x;
    cin >> x;

    // Chef needs at least 25 Grand Slams to break the record.
    // Let 'y' be the number of years.
    // In 'y' years, Chef wins 4 * y Grand Slams.
    // Total slams after 'y' years will be x + 4 * y.
    // We need x + 4 * y >= 25.
    // This means 4 * y >= 25 - x.
    // So, y >= (25 - x) / 4.

    // Since 'y' must be an integer, we need to find the smallest integer 'y'
    // that satisfies the inequality.
    // This can be calculated using the ceiling division: ceil((25 - x) / 4.0).
    // In integer arithmetic, ceil(a/b) for positive b is (a + b - 1) / b.
    // Here, a = 25 - x and b = 4.

    int needed_slams = 25;
    int slams_to_win = needed_slams - x;

    // Calculate minimum years using ceiling division.
    // (slams_to_win + 4 - 1) / 4
    int years = (slams_to_win + 3) / 4;

    cout << years << "\n";

    return 0;
}
```