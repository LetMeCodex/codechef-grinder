# [Farmer And His Plot (RECTSQ)](https://www.codechef.com/problems/RECTSQ)
- **Difficulty Rating**: 936
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to take a rectangular plot of land with given dimensions, `N` (length) and `M` (breadth), and divide it into the minimum possible number of identical square plots. We need to output this minimum count of square plots.

## Intuition & Mathematical Observation

To divide a rectangle of dimensions `N x M` into identical square plots, each square must have a side length, let's call it `S`, that perfectly divides both `N` and `M`. If `S` does not divide `N` (or `M`), then we cannot perfectly tile the length `N` (or breadth `M`) with squares of side `S` without any leftover space or cutting squares.

The problem asks for the *minimum* number of square plots. This implies that each individual square plot should be as *large* as possible.

Combining these two observations:
1.  The side length `S` of the square plots must be a common divisor of `N` and `M`.
2.  To minimize the number of plots (by maximizing the size of each plot), `S` must be the *greatest* possible common divisor of `N` and `M`.

Therefore, the optimal side length `S` for the square plots is the Greatest Common Divisor (GCD) of `N` and `M`, i.e., `S = gcd(N, M)`.

Once we determine `S = gcd(N, M)`:
*   The number of squares that fit along the length `N` will be `N / S`.
*   The number of squares that fit along the breadth `M` will be `M / S`.

The total minimum number of square plots will be the product of these two quantities: `(N / S) * (M / S)`.

For example, if `N=6` and `M=9`:
*   `gcd(6, 9) = 3`. So, `S=3`.
*   Number of squares along length `N`: `6 / 3 = 2`.
*   Number of squares along breadth `M`: `9 / 3 = 3`.
*   Total minimum squares: `2 * 3 = 6`.

## Complexity Analysis

*   **Time Complexity**: For each test case, the dominant operation is calculating the Greatest Common Divisor (GCD) of `N` and `M`. The `std::gcd` function (available in C++17 and later, typically included via `<numeric>` or `<bits/stdc++.h>`) implements the Euclidean algorithm. The time complexity of the Euclidean algorithm is $O(\log(\min(N, M)))$. Since there are `T` test cases, the total time complexity will be $O(T \cdot \log(\min(N, M)))$.

*   **Space Complexity**: The solution uses a fixed number of integer variables (`T`, `N`, `M`, `common_side_length`, `num_plots`) per test case. The memory usage does not grow with the input size `N` or `M`. Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, numeric (for std::gcd), etc. for convenience
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming to reduce execution time.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times for each test case
        int N, M;
        cin >> N >> M; // Read the length N and breadth M of the land

        // Calculate the greatest common divisor (GCD) of N and M.
        // As per our intuition, this GCD will be the side length of the largest possible square plots
        // that can perfectly tile the rectangle.
        int common_side_length = std::gcd(N, M);

        // The number of squares along the length N will be N / common_side_length.
        // The number of squares along the breadth M will be M / common_side_length.
        // The total minimum number of square plots is the product of these two quantities.
        // Using long long for num_plots to prevent potential overflow, though for the given constraints
        // (N, M <= 10000), int would also suffice as (10000/1)*(10000/1) = 10^8 fits in int.
        long long num_plots = (long long)(N / common_side_length) * (M / common_side_length);
        
        // Print the calculated minimum number of plots, followed by a newline.
        cout << num_plots << "\n";
    }

    return 0; // Indicate successful execution
}
```