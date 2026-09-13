# [Chef and Wire Frames (CWIREFRAME)](https://www.codechef.com/problems/CWIREFRAME)

- **Difficulty Rating**: 383
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef needs to build a rectangular frame with dimensions $N$ cm and $M$ cm. The cost of the wire used for the frame is $X$ per cm. We need to calculate the total cost required to purchase the wire for the entire perimeter of the rectangle.

## Intuition & Mathematical Observation
The perimeter of a rectangle with length $N$ and width $M$ is given by the formula:
$$\text{Perimeter} = 2 \times (N + M)$$

Since the cost of the wire is $X$ per unit length, the total cost is simply the product of the perimeter and the cost per unit:
$$\text{Total Cost} = \text{Perimeter} \times X = 2 \times (N + M) \times X$$

Given the constraints $N, M, X \le 1000$, the maximum possible cost is $2 \times (1000 + 1000) \times 1000 = 4,000,000$. This value fits comfortably within a standard 32-bit integer, though `long long` is used in the implementation to ensure robustness against potential overflow in similar problems.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves only basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The perimeter of a rectangle with length N and width M is 2 * (N + M).
 * The cost per cm is X.
 * Total cost = Perimeter * X = 2 * (N + M) * X.
 * 
 * Constraints:
 * N, M, X <= 1000.
 * Max perimeter = 2 * (1000 + 1000) = 4000.
 * Max cost = 4000 * 1000 = 4,000,000.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, m, x;
        cin >> n >> m >> x;
        
        // Calculate perimeter: 2 * (N + M)
        // Calculate total cost: Perimeter * X
        long long perimeter = 2 * (n + m);
        long long total_cost = perimeter * x;
        
        cout << total_cost << "\n";
    }

    return 0;
}
```