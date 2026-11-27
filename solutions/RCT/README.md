# [Rectangular Tiling (RCT)](https://www.codechef.com/problems/RCT)
- **Difficulty Rating**: 1182
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks whether a rectangular floor of dimensions $W \times L$ can be perfectly tiled using smaller rectangular tiles. The crucial constraint for each individual tile $(w_i \times h_i)$ is that its perimeter, $2 \times (w_i + h_i)$, must **not** be divisible by 4. We need to output "YES" if such a tiling is possible, and "NO" otherwise.

## Intuition & Mathematical Observation

Let's break down the condition for a valid tile: $2 \times (w_i + h_i)$ is not divisible by 4.

1.  **Simplifying the Tile Condition:**
    The condition $2 \times (w_i + h_i) \not\equiv 0 \pmod 4$ implies that $(w_i + h_i)$ must be an **odd** number.
    *   If $(w_i + h_i)$ were even (e.g., $2k$), then $2 \times (w_i + h_i)$ would be $2 \times (2k) = 4k$, which *is* divisible by 4. This would make the tile invalid.
    *   Therefore, for the tile to be valid, $(w_i + h_i)$ must be odd.

2.  **Parity of Tile Dimensions:**
    For the sum of two integers $(w_i + h_i)$ to be odd, $w_i$ and $h_i$ must have **different parities**. That is, one must be odd and the other must be even.
    *   `odd + odd = even`
    *   `even + even = even`
    *   `odd + even = odd`
    *   `even + odd = odd`

3.  **Area of a Valid Tile:**
    Now, let's consider the area of a valid tile: $A_i = w_i \times h_i$.
    If $w_i$ and $h_i$ have different parities (one odd, one even), their product $w_i \times h_i$ will always be an **even** number.
    *   `odd * even = even`
    *   `even * odd = even`
    This is a critical insight: **Every valid tile must have an even area.**

4.  **Total Floor Area Constraint:**
    The total area of the floor to be tiled is $A_{total} = W \times L$. If the floor is perfectly tiled by $N$ valid tiles, the sum of their areas must equal the total floor area:
    $A_{total} = \sum_{j=1}^{N} A_j$
    Since each $A_j$ (area of a valid tile) must be even, the sum of any number of even areas must also be even.
    Therefore, for a tiling to be possible, the total area of the floor, $W \times L$, **must be even**.

5.  **When is $W \times L$ even?**
    *   $W \times L$ is even if and only if at least one of $W$ or $L$ is an even number.
    *   $W \times L$ is odd if and only if both $W$ and $L$ are odd numbers.

    Combining this with our previous observation:
    If both $W$ and $L$ are odd, then $W \times L$ is odd. In this scenario, the total floor area is odd, but it must be covered by tiles, each having an even area. This is impossible. Thus, if both $W$ and $L$ are odd, the answer is "NO".

6.  **Constructive Proof (If $W \times L$ is even):**
    If $W \times L$ is even, it means at least one of $W$ or $L$ is even. We need to show that a tiling is always possible in this case.

    *   **Case 1: $W$ is even.** (L can be odd or even)
        *   **Subcase 1.1: $W$ is even, $L$ is odd.**
            We can use a single tile of dimensions $W \times L$. Its width $W$ (even) and height $L$ (odd) have different parities. Therefore, $(W + L)$ is odd, making this $W \times L$ tile a valid tile. This single tile perfectly covers the floor.
        *   **Subcase 1.2: $W$ is even, $L$ is even.**
            A single $W \times L$ tile would have both dimensions even, so $(W+L)$ would be even, making it an invalid tile. However, we can tile the $W \times L$ floor with $W$ tiles, each of dimensions $1 \times L$. For each $1 \times L$ tile: its width is $1$ (odd) and its height is $L$ (even). Since $1$ and $L$ have different parities, $(1 + L)$ is odd, making each $1 \times L$ tile valid. Placing $W$ such tiles side-by-side perfectly covers the $W \times L$ floor.

    *   **Case 2: $L$ is even.** (W can be odd or even)
        This case is symmetric to Case 1. If $L$ is even and $W$ is odd, a single $W \times L$ tile works. If both $W$ and $L$ are even, it's covered by Subcase 1.2 (or we could use $L$ tiles of $W \times 1$).

**Conclusion:**
A tiling is possible if and only if at least one of $W$ or $L$ is even. This is equivalent to checking if $(W \pmod 2 == 0 \text{ or } L \pmod 2 == 0)$.

## Complexity Analysis

*   **Time Complexity**: For each test case, the solution reads two `long long` integers and performs simple modulo operations and a logical OR. These operations take constant time. If there are $T$ test cases, the total time complexity is $O(T)$.
*   **Space Complexity**: The solution only uses a few variables to store $W$, $L$, and the number of test cases $T$. This requires a constant amount of memory, regardless of the input values (within `long long` limits). Thus, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace to avoid prefixing std::
using namespace std;

void solve() {
    long long W, L; // W and L can be up to 10^9. long long is used to safely store these values.
                    // For parity checks, 'int' would also be sufficient as 10^9 fits in int.
    cin >> W >> L;

    // A tile (w_i, h_i) is valid if its perimeter 2*(w_i + h_i) is not divisible by 4.
    // This condition simplifies to (w_i + h_i) being an odd number.
    // For (w_i + h_i) to be odd, w_i and h_i must have different parities (one even, one odd).
    // If w_i and h_i have different parities, then their product w_i * h_i (the area of the tile)
    // is always an even number (e.g., even * odd = even).

    // The total area of the floor W * L must be covered by these tiles.
    // Since each individual tile must have an even area, the sum of their areas (W * L) must also be even.
    // If W * L is odd, it's impossible to tile the floor with such tiles.
    // W * L is odd if and only if both W and L are odd.
    // Therefore, if both W and L are odd, the answer is NO.

    // If W * L is even, then at least one of W or L must be an even number.
    // In this scenario, a tiling is always possible:
    // Case 1: W is even (and L can be either odd or even).
    //   If L is odd: We can use a single tile of dimensions W x L.
    //     Its width W (even) and height L (odd) have different parities, making it a valid tile.
    //     So, a single W x L tile can cover the floor.
    //   If L is even: We can tile the W x L floor with W tiles, each of dimensions 1 x L.
    //     For each 1 x L tile: its width is 1 (odd) and its height is L (even).
    //     Since 1 and L have different parities, each 1 x L tile is valid.
    //     Placing W such tiles side-by-side perfectly covers the W x L floor.
    // Case 2: L is even (and W is odd). This is symmetric to Case 1.
    //   We can use a single W x L tile (W odd, L even) or L tiles of W x 1 dimensions.

    // In summary, if at least one of W or L is even, it's possible to tile the floor.
    // This condition is checked by (W % 2 == 0 || L % 2 == 0).
    if (W % 2 == 0 || L % 2 == 0) {
        cout << "YES\n";
    } else {
        // Both W and L are odd
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times, decrementing T in each iteration
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```