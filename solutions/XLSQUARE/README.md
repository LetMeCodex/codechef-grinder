# [Large Square (XLSQUARE)](https://www.codechef.com/problems/XLSQUARE)

- **Difficulty Rating**: 1160
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $N$ small square tiles, each with a side length of $A$. You need to arrange these tiles to form the largest possible "mega square." The mega square must be composed of $k \times k$ small tiles, where $k$ is an integer. The goal is to find the side length of this mega square, which is $k \times A$.

## Intuition & Mathematical Observation
To form a mega square of size $k \times k$, we need exactly $k^2$ small tiles. Since we have a total of $N$ tiles available, the constraint is:
$$k^2 \le N$$
To maximize the side length of the mega square ($k \times A$), we must maximize $k$. Therefore, we need to find the largest integer $k$ such that $k^2 \le N$. This is equivalent to finding the integer part of the square root of $N$:
$$k = \lfloor \sqrt{N} \rfloor$$
Once we find the maximum $k$, the side length of the resulting mega square is simply $k \times A$.

**Implementation Note:** When using `sqrt()` in C++, floating-point precision can occasionally lead to issues (e.g., `sqrt(9)` returning `2.99999999`). Adding a small epsilon (`1e-9`) before casting to an integer ensures that perfect squares are handled correctly.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, the square root calculation and basic arithmetic operations are performed in $O(1)$ time.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, cmath, etc.

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases

    while (T--) {
        int N, A;
        std::cin >> N >> A; // Read N and A for the current test case

        // Calculate k, the largest integer such that k*k <= N.
        // We add a small epsilon (1e-9) to sqrt(N) to mitigate 
        // potential floating-point precision errors.
        int k = static_cast<int>(sqrt(N) + 1e-9);

        // Ensure k*k does not exceed N.
        if (k * k > N) {
            k--;
        }

        // The side length of the largest mega square is k * A.
        std::cout << k * A << "\n"; 
    }

    return 0; 
}
```