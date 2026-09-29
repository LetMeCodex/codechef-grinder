# [Zero Ones Equal One Zeros (ZOOZ)](https://www.codechef.com/problems/ZOOZ)
- **Difficulty Rating**: 1009
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to construct a binary string of a given length `N` (where `3 <= N <= 1000`) such that two conditions are met:
1.  The count of "01" subsequences is equal to the count of "10" subsequences.
2.  The string must contain at least one '0' and at least one '1'.

We are guaranteed that a solution always exists.

## Intuition & Mathematical Observation

Let's denote the count of "01" subsequences as `C_01` and "10" subsequences as `C_10`. We need to find a string where `C_01 = C_10`.

First, let's consider some simple string structures:

1.  **Monotonic strings (e.g., "000111" or "111000"):**
    *   If the string is `k` zeros followed by `N-k` ones (e.g., "00111"), then `C_01 = k * (N-k)` and `C_10 = 0`. These are only equal if `k=0` or `k=N` (all zeros or all ones), which violates the "at least one '0' and one '1'" condition.
    *   Similarly, if the string is `k` ones followed by `N-k` zeros (e.g., "11100"), then `C_10 = k * (N-k)` and `C_01 = 0`. This also doesn't work.
    This means we need a mix of '0's and '1's that are not simply separated into two blocks.

2.  **Alternating strings (e.g., "010101..."):**
    *   Let's test `N=3`: "010"
        *   `C_01`: (0 at index 0, 1 at index 1) -> 1
        *   `C_10`: (1 at index 1, 0 at index 2) -> 1
        *   Here, `C_01 = C_10 = 1`. This works! It also contains at least one '0' and one '1'.
    *   Let's test `N=4`: "0101"
        *   `C_01`: (0@0, 1@1), (0@0, 1@3), (0@2, 1@3) -> 3
        *   `C_10`: (1@1, 0@2) -> 1
        *   Here, `C_01 != C_10`. This pattern doesn't work for even `N`.

The sample cases provided in the problem statement are:
*   For `N=3`: "010"
*   For `N=4`: "1001"

Let's analyze these sample outputs:

*   **For `N=3`, string "010":**
    *   This string has one '1' in the middle, surrounded by `(3-1)/2 = 1` zero on each side.
    *   Structure: `0` `1` `0`.
    *   `C_01`: The only '1' is at index 1. The '0' at index 0 is before it. So, 1 "01" subsequence.
    *   `C_10`: The only '1' is at index 1. The '0' at index 2 is after it. So, 1 "10" subsequence.
    *   `C_01 = C_10 = 1`. This matches our observation for `N=3`.

*   **For `N=4`, string "1001":**
    *   This string has two '1's, one at each end, and `4-2 = 2` zeros in the middle.
    *   Structure: `1` `00` `1`.
    *   `C_01`:
        *   The '1' at index 0 cannot form a "01" subsequence (no '0's before it).
        *   The '1' at index 3 can form a "01" subsequence with any '0' before it. The '0's are at index 1 and 2. So, 2 "01" subsequences.
        *   Total `C_01 = 2`.
    *   `C_10`:
        *   The '1' at index 0 can form a "10" subsequence with any '0' after it. The '0's are at index 1 and 2. So, 2 "10" subsequences.
        *   The '1' at index 3 cannot form a "10" subsequence (no '0's after it).
        *   Total `C_10 = 2`.
    *   `C_01 = C_10 = 2`. This works! It also contains at least one '0' and one '1'.

These two sample cases suggest two distinct patterns based on whether `N` is odd or even. Let's generalize and prove them.

### Pattern for Odd `N`

**Construction:** A string with `(N-1)/2` zeros, followed by a single '1', followed by `(N-1)/2` zeros.
Let `k = (N-1)/2`. The string is `0...0` (k times) `1` `0...0` (k times).

**Proof:**
*   **Characters:** The string contains `2k` zeros and `1` one. Since `N >= 3`, `k = (N-1)/2 >= 1`. Thus, there is at least one '1' and at least two '0's, satisfying the second condition.
*   **`C_01` count:** The only '1' is at index `k`. Any '0' at an index `i < k` can form a "01" subsequence with this '1'. There are `k` such '0's (at indices `0` to `k-1`). So, `C_01 = k`.
*   **`C_10` count:** The only '1' is at index `k`. Any '0' at an index `j > k` can form a "10" subsequence with this '1'. There are `k` such '0's (at indices `k+1` to `2k`). So, `C_10 = k`.
*   **Conclusion:** `C_01 = C_10 = k`. This pattern works for all odd `N >= 3`.

**Example `N=5`:** `k=(5-1)/2=2`. String: "00100".
*   `C_01`: (0@0, 1@2), (0@1, 1@2) -> 2
*   `C_10`: (1@2, 0@3), (1@2, 0@4) -> 2
*   Counts are equal.

### Pattern for Even `N`

**Construction:** A string starting with '1', followed by `N-2` zeros, followed by a '1'.
The string is `1` `0...0` (N-2 times) `1`.

**Proof:**
*   **Characters:** The string contains two '1's (at index 0 and `N-1`) and `N-2` zeros (at indices `1` to `N-2`). Since `N >= 3`, for even `N`, the minimum is `N=4`. Thus, `N-2 >= 2`. There are at least two '1's and at least two '0's, satisfying the second condition.
*   **`C_01` count:**
    *   The '1' at index 0 cannot form any "01" subsequence because there are no '0's before it.
    *   The '1' at index `N-1` can form a "01" subsequence with any '0' before it. All `N-2` zeros (at indices `1` to `N-2`) are before it. So, `N-2` "01" subsequences.
    *   Total `C_01 = N-2`.
*   **`C_10` count:**
    *   The '1' at index 0 can form a "10" subsequence with any '0' after it. All `N-2` zeros (at indices `1` to `N-2`) are after it. So, `N-2` "10" subsequences.
    *   The '1' at index `N-1` cannot form any "10" subsequence because there are no '0's after it.
    *   Total `C_10 = N-2`.
*   **Conclusion:** `C_01 = C_10 = N-2`. This pattern works for all even `N >= 4`.

**Example `N=6`:** String: "100001".
*   `C_01`: (0@1, 1@5), (0@2, 1@5), (0@3, 1@5), (0@4, 1@5) -> 4
*   `C_10`: (1@0, 0@1), (1@0, 0@2), (1@0, 0@3), (1@0, 0@4) -> 4
*   Counts are equal.

These two patterns cover all `N >= 3` and satisfy all problem conditions.

## Complexity Analysis

*   **Time Complexity**: For each test case, we iterate `N` times to print the characters of the string. Since there are `T` test cases, the total time complexity is $O(T \cdot N)$. Given `T <= 100` and `N <= 1000`, the maximum operations would be around $100 \cdot 1000 = 10^5$, which is well within typical time limits.

*   **Space Complexity**: The solution prints characters directly to standard output without storing the entire string in memory. Therefore, the auxiliary space complexity is $O(1)$ per test case.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        int n;
        std::cin >> n; // Read the length of the binary string for the current test case

        // The problem asks for a binary string of length N such that
        // the count of "01" subsequences equals the count of "10" subsequences,
        // and the string contains at least one '0' and one '1'.
        // N is between 3 and 1000.

        // We found two patterns based on N's parity:

        if (n % 2 != 0) { // N is odd
            // Pattern for odd N: (N-1)/2 zeros, then '1', then (N-1)/2 zeros.
            // Example N=3: "010" (1 zero, 1 one, 1 zero)
            // Example N=5: "00100" (2 zeros, 1 one, 2 zeros)
            //
            // Proof for odd N:
            // Let k = (N-1)/2. String is '0'*k + '1' + '0'*k.
            // The single '1' is at index k.
            // Count of "01" subsequences: Any '0' before the '1' can form a "01". There are k such '0's. So, C_01 = k.
            // Count of "10" subsequences: Any '0' after the '1' can form a "10". There are k such '0's. So, C_10 = k.
            // C_01 = C_10 = k.
            // Since N >= 3, k >= 1, so there's at least one '1' and two '0's. Conditions met.

            int num_zeros_each_side = (n - 1) / 2;
            for (int i = 0; i < num_zeros_each_side; ++i) {
                std::cout << '0';
            }
            std::cout << '1';
            for (int i = 0; i < num_zeros_each_side; ++i) {
                std::cout << '0';
            }
            std::cout << "\n"; // Newline after each string
        } else { // N is even
            // Pattern for even N: '1', then N-2 zeros, then '1'.
            // Example N=4: "1001" (1 one, 2 zeros, 1 one)
            // Example N=6: "100001" (1 one, 4 zeros, 1 one)
            //
            // Proof for even N:
            // String is '1' + '0'*(N-2) + '1'.
            // The two '1's are at index 0 and index N-1. The N-2 '0's are in between.
            // Count of "01" subsequences: Only the '1' at index N-1 can form "01" (with any of the N-2 '0's before it). So, C_01 = N-2.
            // Count of "10" subsequences: Only the '1' at index 0 can form "10" (with any of the N-2 '0's after it). So, C_10 = N-2.
            // C_01 = C_10 = N-2.
            // Since N >= 3, for even N, min N=4. N-2 >= 2, so there are at least two '1's and two '0's. Conditions met.

            std::cout << '1';
            for (int i = 0; i < n - 2; ++i) {
                std::cout << '0';
            }
            std::cout << '1';
            std::cout << "\n"; // Newline after each string
        }
    }
    return 0;
}

```