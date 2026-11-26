# [Distinct Substring (DISTSUB)](https://www.codechef.com/problems/DISTSUB)
- **Difficulty Rating**: 1251
- **Solved in**: 2 attempt(s)

## Problem Summary

The problem asks us to determine if it's possible to construct a binary string (containing only '0's and '1's) of a given length `N` such that it contains exactly `K` distinct substrings consisting only of '0's. These substrings are often referred to as "islands of 0s".

For example, if `K=3`, we need to have three distinct lengths of consecutive '0's present in the string. The substrings "0", "00", and "000" are distinct because they have different lengths. If a string contains "0" and "00", it has 2 distinct '0'-only substrings.

## Intuition & Mathematical Observation

The core of this problem lies in understanding what "distinct substrings that consist only of '0's" means and how to minimize the total string length `N` to achieve `K` such distinct substrings.

1.  **What are "distinct substrings that consist only of '0's"?**
    These are sequences like "0", "00", "000", etc. If we need `K` distinct such substrings, it implies we need `K` different lengths of consecutive '0's to appear in our string. For instance, if `K=3`, we need to have '0's of length 1, length 2, and length 3 present in the string.

2.  **Minimizing '0's for `K` distinct lengths:**
    To minimize the total number of '0's used, we should choose the smallest possible distinct positive integer lengths for these `K` islands. These lengths are `1, 2, 3, ..., K`.
    The sum of these lengths gives us the minimum total count of '0's required:
    `min_zeros_sum = 1 + 2 + ... + K = K * (K + 1) / 2`.

3.  **Separating the '0' islands:**
    To ensure that these `K` distinct '0' islands are indeed distinct and form separate "islands", they must be separated by at least one '1'. For example, to have "0", "00", and "000" as distinct islands, we could arrange them as `01001000`.
    If we have `K` islands, we need at least `K-1` separators ('1's) to place between them.
    `min_separators = K - 1`.
    (Note: If `K=1`, `min_separators = 0`, which is correct as a single island like "0" doesn't need separators).

4.  **Minimum total length `N` required:**
    The minimum total length of the string `N` is the sum of the minimum '0's required and the minimum '1's required:
    `required_length = min_zeros_sum + min_separators`
    `required_length = (K * (K + 1) / 2) + (K - 1)`

5.  **Constructibility:**
    If the given `N` is greater than or equal to this `required_length`, it is always possible to construct such a string. Any "extra" length (`N - required_length`) can be filled with additional '1's. Adding more '1's (e.g., `011001000` instead of `01001000`) does not change the set of distinct '0' islands, but it increases the total string length. Therefore, if `N >= required_length`, the answer is "YES"; otherwise, it's "NO".

6.  **Data Types:**
    `K` can be up to 500.
    For `K=500`:
    `min_zeros_sum = 500 * 501 / 2 = 125250`
    `min_separators = 500 - 1 = 499`
    `required_length = 125250 + 499 = 125749`
    These values fit within a standard `int`. However, `N` can be up to `10^9`. To avoid potential overflow during intermediate calculations (e.g., `K * (K + 1)` before division) and to ensure correct comparison with `N`, it's safer and good practice to use `long long` for `required_length` and its components.

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    For each test case, the solution performs a fixed number of arithmetic operations (multiplication, addition, division, subtraction) and a comparison. These operations take constant time, regardless of the values of `N` or `K`. The overall time complexity is dominated by reading `T` test cases, making it $O(T)$.

*   **Space Complexity**: $O(1)$
    The solution uses a few integer variables (`t`, `n`, `k`, `min_zeros_sum`, `min_separators`, `required_length`) to store input and calculated values. The memory usage for these variables is constant and does not depend on the input size `N` or `K`.

## Solution Code

```cpp
#include <iostream>
// The headers <vector>, <numeric>, <algorithm> are not used in this solution
// and can be removed for a cleaner build.

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int n; // Length of the binary string
        int k; // Number of distinct '0' islands required
        std::cin >> n >> k;

        // To have K distinct islands, we need K blocks of 0s.
        // The smallest possible distinct lengths for these K islands are 1, 2, ..., K.
        // The sum of these lengths is S = 1 + 2 + ... + K = K * (K + 1) / 2.
        // This is the minimum number of '0's required.
        long long min_zeros_sum = (long long)k * (k + 1) / 2;

        // To separate K islands, we need at least K-1 separators (the character '1').
        // For K=1, we need 0 separators. For K > 1, we need K-1 separators.
        // Since K >= 1, (k - 1) correctly handles both cases.
        long long min_separators = k - 1;

        // Therefore, the minimum total length of the string required is the sum of minimum zeros
        // plus the minimum number of ones.
        long long required_length = min_zeros_sum + min_separators;

        // If the given length N is less than the minimum required length, it's impossible.
        // Otherwise, it's possible to construct such a string by adding extra '1's.
        if (n >= required_length) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}

```