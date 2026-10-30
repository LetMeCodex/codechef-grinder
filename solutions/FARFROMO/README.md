# [Far from origin (FARFROMO)](https://www.codechef.com/problems/FARFROMO)
- **Difficulty Rating**: 750
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to compare the distances of two individuals, Alex and Bob, from the origin (0,0) in a 2D Cartesian plane. We are given Alex's coordinates $(X_1, Y_1)$ and Bob's coordinates $(X_2, Y_2)$. Our task is to determine who is farther from the origin. If Alex is farther, we print "ALEX". If Bob is farther, we print "BOB". If they are at the same distance, we print "EQUAL".

## Intuition & Mathematical Observation

The distance of a point $(x, y)$ from the origin $(0,0)$ is given by the Euclidean distance formula:
$D = \sqrt{(x-0)^2 + (y-0)^2} = \sqrt{x^2 + y^2}$.

To solve this problem, we need to calculate Alex's distance from the origin ($D_{Alex}$) and Bob's distance from the origin ($D_{Bob}$), and then compare them.

A crucial observation in competitive programming when comparing distances is that we can avoid calculating the square root. For any two non-negative numbers $A$ and $B$:
*   If $A > B$, then $A^2 > B^2$.
*   If $A < B$, then $A^2 < B^2$.
*   If $A = B$, then $A^2 = B^2$.

Since distances are always non-negative, we can compare the *squared distances* instead of the actual distances. This has two main benefits:
1.  **Avoids Floating Point Issues**: Calculating square roots often results in floating-point numbers, which can lead to precision errors when comparing very close values. Comparing integers (squared distances) eliminates this risk.
2.  **Computational Efficiency**: Square root operations are generally more computationally expensive than basic arithmetic operations like multiplication and addition.

So, the strategy is:
1.  Calculate Alex's squared distance from the origin: $D_{Alex}^2 = X_1^2 + Y_1^2$.
2.  Calculate Bob's squared distance from the origin: $D_{Bob}^2 = X_2^2 + Y_2^2$.
3.  Compare $D_{Alex}^2$ and $D_{Bob}^2$:
    *   If $D_{Alex}^2 > D_{Bob}^2$, Alex is farther.
    *   If $D_{Bob}^2 > D_{Alex}^2$, Bob is farther.
    *   Otherwise ($D_{Alex}^2 = D_{Bob}^2$), they are at an equal distance.

**Data Type Consideration**:
The problem constraints state that coordinates $X, Y$ are between -1000 and 1000.
*   The maximum value for $X^2$ or $Y^2$ would be $1000^2 = 1,000,000$.
*   The maximum value for $X^2 + Y^2$ would be $1000^2 + 1000^2 = 2,000,000$.
A standard `int` in C++ typically has a maximum value of around $2 \times 10^9$, which is sufficient to store $2 \times 10^6$. However, using `long long` for the squared distances is a good practice to prevent potential overflow issues if the constraints were slightly larger (e.g., coordinates up to $10^5$, where $X^2$ would be $10^{10}$, exceeding `int` capacity). The provided solution correctly uses `long long`.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    For each test case, we perform a fixed number of operations: reading four integers, two multiplications and one addition for each person's squared distance, and then two comparisons. These are all constant-time operations. If there are $T$ test cases, the total time complexity will be proportional to $T$, hence $O(T)$.

-   **Space Complexity**: $O(1)$
    The solution uses a constant amount of extra space regardless of the input values (apart from the number of test cases). We only store a few variables like `T`, `X1`, `Y1`, `X2`, `Y2`, `dist_sq_alex`, and `dist_sq_bob` at any given time. This space requirement does not grow with the magnitude of the coordinates.

## Solution Code

```cpp
#include <bits/stdc++.h> 

// Use the standard namespace to avoid prefixing standard library elements with std::
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times, decrementing T in each iteration
        int X1, Y1, X2, Y2;
        // Read the coordinates for Alex (X1, Y1) and Bob (X2, Y2)
        cin >> X1 >> Y1 >> X2 >> Y2; 

        // Calculate Alex's squared distance from the origin (0,0).
        // Using (long long) for type casting before multiplication to ensure
        // the product is computed as a long long, preventing potential overflow
        // if intermediate squares were larger than int max.
        // For this problem's constraints (-1000 to 1000), int would be sufficient,
        // but long long is a safer general practice.
        long long dist_sq_alex = (long long)X1 * X1 + (long long)Y1 * Y1;

        // Calculate Bob's squared distance from the origin (0,0).
        long long dist_sq_bob = (long long)X2 * X2 + (long long)Y2 * Y2;

        // Compare the squared distances to determine who is farther or if they are equal.
        if (dist_sq_alex > dist_sq_bob) {
            cout << "ALEX\n"; // Alex is farther
        } else if (dist_sq_bob > dist_sq_alex) {
            cout << "BOB\n";  // Bob is farther
        } else {
            cout << "EQUAL\n"; // Both are at the same distance
        }
    }

    return 0; // Indicate successful program execution
}
```