# [Stick Break (STICKBREAK)](https://www.codechef.com/problems/STICKBREAK)
- **Difficulty Rating**: 1123
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to take a stick of total length `L` and break it into exactly `K` pieces. Each of these `K` pieces must have a positive integer length. We then need to arrange these `K` pieces in some order, say `A_1, A_2, ..., A_K`, such that the sum of absolute differences between adjacent pieces is minimized. That is, we want to minimize `|A_2 - A_1| + |A_3 - A_2| + ... + |A_K - A_{K-1}|`. We need to output this minimum possible sum.

Constraints:
*   `T` test cases.
*   `2 <= K <= L <= 10^9`
*   `A_i` must be positive integers.

## Intuition & Mathematical Observation

The goal is to minimize the sum of absolute differences between adjacent pieces: `sum(|A_{i+1} - A_i|)`. To achieve this, we want the lengths of the `K` pieces to be as close to each other as possible. If all pieces have the same length, the sum of differences would be 0. If they must differ, we want the differences to be as small as possible, ideally 1.

Let the `K` pieces have lengths `A_1, A_2, ..., A_K`. We know that their sum must be `L`: `sum(A_i) = L`. Also, each `A_i` must be a positive integer.

To make the `K` pieces as equal as possible, we can use integer division.
Let `q = L / K` (integer division) and `r = L % K` (remainder).
This means `L = q * K + r`.

We can distribute `L` into `K` parts such that:
*   `r` pieces will have length `q + 1`.
*   `K - r` pieces will have length `q`.

Let's verify the sum of these lengths:
`r * (q + 1) + (K - r) * q = r*q + r + K*q - r*q = K*q + r = L`.
This correctly sums up to `L`.

Also, since `K <= L` (given constraint), `q = L / K` will always be at least 1. Therefore, `q` and `q+1` are always positive integers, satisfying the problem's requirement that `A_i` must be positive.

Now, we have `r` pieces of length `q+1` and `K-r` pieces of length `q`. We need to arrange them to minimize `sum(|A_{i+1} - A_i|)`.

Consider two cases based on the remainder `r`:

1.  **Case 1: `r = 0`**
    If `r = 0`, then `L` is perfectly divisible by `K`. In this scenario, all `K` pieces will have the same length `q = L / K`.
    The sequence of pieces would be `[q, q, ..., q]`.
    The difference between any two adjacent pieces is `|q - q| = 0`.
    Therefore, the total sum of differences is `0`.

2.  **Case 2: `r > 0`**
    If `r > 0`, then `L` is not perfectly divisible by `K`. We have `r` pieces of length `q+1` and `K-r` pieces of length `q`.
    To minimize the sum of absolute differences, we should arrange the pieces such that identical lengths are grouped together. This minimizes the "jumps" in length.
    An optimal arrangement would be to place all `q+1` pieces together, followed by all `q` pieces (or vice-versa).
    For example: `[q+1, q+1, ..., q+1 (r times), q, q, ..., q (K-r times)]`.

    Let's analyze the differences in this arrangement:
    *   Between `q+1` and `q+1`: `|(q+1) - (q+1)| = 0`. This occurs `r-1` times if `r > 1`.
    *   Between `q` and `q`: `|q - q| = 0`. This occurs `K-r-1` times if `K-r > 1`.
    *   The only non-zero difference occurs exactly once, at the boundary between the last `q+1` piece and the first `q` piece: `|q - (q+1)| = |-1| = 1`.

    Any other arrangement would either break up the groups of identical lengths, leading to more `1` differences, or introduce larger differences (which is not possible here as we only have two distinct lengths `q` and `q+1`). Thus, this arrangement yields the minimum sum.
    The total sum of differences is `0 * (r-1) + 1 + 0 * (K-r-1) = 1`.

Combining both cases:
*   If `L % K == 0`, the minimum sum of differences is `0`.
*   If `L % K != 0`, the minimum sum of differences is `1`.

This logic holds because the problem guarantees `K >= 2`, ensuring there's always at least one adjacent pair to consider.

## Complexity Analysis

*   **Time Complexity**: The solution involves reading two `long long` integers (`l` and `k`), performing a single modulo operation (`l % k`), and printing an integer. These are constant time operations. The entire process is repeated `T` times for `T` test cases. Therefore, the total time complexity is $O(T)$.

*   **Space Complexity**: The solution uses a few variables (`t`, `l`, `k`) to store input and loop counters. The memory usage does not depend on the input values `L` or `K`. Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <iostream>
// The following headers are not strictly necessary for this specific problem,
// but are commonly included in competitive programming templates.
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        long long l, k;
        std::cin >> l >> k; // Read the total length L and number of pieces K

        // We want to minimize the sum of absolute differences between adjacent pieces,
        // sum(|A_{i+1} - A_i|), where A_i are positive integers and sum(A_i) = L.
        //
        // To minimize these differences, the lengths A_i should be as close to each other
        // as possible.
        //
        // Let L be divided by K: L = q*K + r, where q = L/K (integer division) and r = L%K.
        // This means we can form K pieces as follows:
        // - 'r' pieces of length (q + 1)
        // - 'K - r' pieces of length q
        //
        // The sum of these lengths is r*(q+1) + (K-r)*q = r*q + r + K*q - r*q = K*q + r = L.
        // All pieces will have positive integer lengths because K <= L implies q = L/K >= 1.
        //
        // To minimize the sum of absolute differences, we should arrange these pieces
        // such that pieces of the same length are grouped together.
        // For example: [ (q+1), ..., (q+1) (r times), q, ..., q (K-r times) ]
        //
        // Consider the differences between adjacent pieces in this arrangement:
        // - Differences between (q+1) and (q+1) are |(q+1) - (q+1)| = 0. (occurs r-1 times)
        // - Differences between q and q are |q - q| = 0. (occurs K-r-1 times)
        // - The only potential non-zero difference occurs at the boundary between the
        //   last (q+1) piece and the first q piece: |q - (q+1)| = |-1| = 1.
        //
        // Case 1: If L is perfectly divisible by K (i.e., r = 0).
        // All K pieces will have length q. The sequence is [q, q, ..., q].
        // All adjacent differences are |q - q| = 0.
        // The total minimum sum of differences is 0.
        //
        // Case 2: If L is not perfectly divisible by K (i.e., r > 0).
        // We have 'r' pieces of length (q+1) and 'K-r' pieces of length q.
        // As analyzed above, arranging them as [..., q+1, q, ...] results in
        // exactly one difference of 1, and all other differences are 0.
        // The total minimum sum of differences is 1.
        //
        // The problem statement guarantees K >= 2, so there's always at least one
        // adjacent pair to consider.

        if (l % k == 0) {
            std::cout << 0 << "\n"; // If L is perfectly divisible by K, min sum is 0
        } else {
            std::cout << 1 << "\n"; // Otherwise, min sum is 1
        }
    }
    return 0;
}

```