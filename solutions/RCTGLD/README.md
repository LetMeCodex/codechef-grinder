# [Rectangled (RCTGLD)](https://www.codechef.com/problems/RCTGLD)
- **Difficulty Rating**: 751
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the maximum possible area of a rectangle given a certain amount of ink, `N`. The perimeter of the rectangle must be less than or equal to `N`, and its sides (length and width) must be positive integers. We need to output this maximum area for several test cases.

## Intuition & Mathematical Observation

1.  **Perimeter Constraint**: Let the length of the rectangle be `L` and the width be `W`. The perimeter `P` is `2 * (L + W)`. The problem states that `P <= N`.
    Substituting the formula for `P`, we get `2 * (L + W) <= N`.
    Dividing by 2, we find that the sum of the length and width must satisfy `L + W <= N / 2`.

2.  **Integer Sides**: The problem specifies that `L` and `W` must be positive integers. This means `L >= 1` and `W >= 1`. Consequently, their sum `L + W` must be at least `1 + 1 = 2`.

3.  **Maximizing Area for a Fixed Sum**: We want to maximize the area `Area = L * W`. A fundamental geometric principle states that for a fixed sum `S = L + W`, the product `L * W` is maximized when `L` and `W` are as close to each other as possible. This means the rectangle should be as close to a square as possible.

4.  **Combining Observations**:
    *   First, to maximize the area, we should maximize the sum `L + W` as much as possible, up to the limit imposed by `N`. The maximum possible integer sum `L + W` can take is `S_max = floor(N / 2)`. In C++, integer division `N / 2` automatically computes `floor(N / 2)` for positive `N`.
    *   Once we have `S_max`, we need to find `L` and `W` such that `L + W = S_max` and `L * W` is maximized. As discussed, this occurs when `L` and `W` are as close as possible.
    *   We can achieve this by setting `L = S_max / 2` (integer division) and `W = S_max - L`.
        *   If `S_max` is even (e.g., `S_max = 8`), then `L = 8 / 2 = 4` and `W = 8 - 4 = 4`. `L` and `W` are equal.
        *   If `S_max` is odd (e.g., `S_max = 7`), then `L = 7 / 2 = 3` and `W = 7 - 3 = 4`. `L` and `W` differ by 1.
    *   This approach correctly handles the positive integer side constraint:
        *   If `N` is 0 or 1, `S_max = 0`. Then `L = 0`, `W = 0`. Area = 0. This is correct, as a rectangle with positive integral sides cannot be formed.
        *   If `N` is 2 or 3, `S_max = 1`. Then `L = 0`, `W = 1`. Area = 0. This is also correct, as `L+W=1` cannot be formed by two positive integers. The smallest sum for two positive integers is `1+1=2`.
        *   For `N >= 4`, `S_max >= 2`, ensuring `L` and `W` will be at least 1 (e.g., if `S_max = 2`, `L=1, W=1`).

Therefore, the strategy is:
1. Calculate `S_max = N / 2`.
2. Calculate `L = S_max / 2`.
3. Calculate `W = S_max - L`.
4. The maximum area is `L * W`.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    For each test case, the solution performs a few constant-time arithmetic operations (integer division, subtraction, multiplication) and input/output operations. Since there are `T` test cases, the total time complexity is directly proportional to `T`.

-   **Space Complexity**: $O(1)$
    The solution uses a fixed number of variables (`T`, `N`, `S_max`, `L`, `W`, `area`) to store data for each test case. The memory usage does not depend on the input value `N`. Hence, the space complexity is constant.

## Solution Code

```cpp
#include <iostream> // Required for standard input/output operations (cin, cout)

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases

    while (T--) { // Loop T times for each test case
        int N;
        std::cin >> N; // Read the amount of ink left for the current test case

        // The perimeter of a rectangle is 2 * (length + width).
        // Chef has N units of ink, so the perimeter must be less than or equal to N.
        // 2 * (L + W) <= N
        // This implies L + W <= N / 2.
        // Since L and W must be integral (positive integers), their sum (L + W) must also be an integer.
        // So, the maximum possible sum of length and width is floor(N / 2).
        // Integer division in C++ automatically computes floor(N / 2) for positive N.
        int S_max = N / 2;

        // To maximize the area (L * W) for a fixed sum (L + W = S_max),
        // L and W should be as close to each other as possible.
        // We can achieve this by setting L to S_max / 2 (integer division)
        // and W to the remaining part, S_max - L.
        // For example, if S_max = 7, L = 7/2 = 3, W = 7 - 3 = 4. Area = 3*4 = 12.
        // If S_max = 8, L = 8/2 = 4, W = 8 - 4 = 4. Area = 4*4 = 16.

        // Also, a rectangle with integral sides must have L >= 1 and W >= 1.
        // This means L + W must be at least 2.
        // If S_max is 0 (e.g., N=0 or N=1), L=0, W=0, Area=0.
        // If S_max is 1 (e.g., N=2 or N=3), L=0, W=1, Area=0.
        // In these cases, the calculated L or W would be 0, resulting in an area of 0,
        // which correctly reflects that a valid rectangle (with positive integral sides) cannot be formed.
        
        int L = S_max / 2;
        int W = S_max - L;

        // Calculate the area.
        // The maximum N is 1000, so S_max is 500. L and W are at most 250.
        // The maximum area is 250 * 250 = 62500, which fits within an 'int'.
        // Using 'long long' for area is a safe practice in competitive programming,
        // though not strictly necessary here.
        long long area = (long long)L * W;

        std::cout << area << "\n"; // Output the maximum area followed by a newline
    }

    return 0; // Indicate successful execution
}
```