# [Yet Another Palindrome Making Problem (MAKEPALAGAIN)](https://www.codechef.com/problems/MAKEPALAGAIN)
- **Difficulty Rating**: 1328
- **Solved in**: 1 attempt(s)

## Problem Summary

You are given a string `A` of even length `N`. You can perform an operation: swap `A[i]` and `A[i+2]` for any valid index `i` (i.e., `0 <= i <= N-3`). The goal is to determine if it's possible to transform the given string `A` into a palindrome using this operation any number of times.

## Intuition & Mathematical Observation

The core of this problem lies in understanding the implications of the allowed operation: swapping `A[i]` and `A[i+2]`.

1.  **Parity of Indices**:
    *   If `i` is an **even** index, then `i+2` is also an **even** index. This means a character initially at an even position can only be moved to other even positions.
    *   If `i` is an **odd** index, then `i+2` is also an **odd** index. This means a character initially at an odd position can only be moved to other odd positions.
    *   **Conclusion**: The set of characters at even indices is completely independent of the set of characters at odd indices. We can rearrange characters among even positions arbitrarily, and similarly for odd positions, but characters cannot move between even and odd positions. This implies that the *multiset* of characters at even positions will always remain the same, and the *multiset* of characters at odd positions will also always remain the same. Only their order can change.

2.  **Palindrome Condition**:
    *   For a string `A` of length `N` to be a palindrome, `A[i]` must be equal to `A[N-1-i]` for all `0 <= i < N`.
    *   Since `N` is even, `N-1` is odd. Let's analyze the parity of `i` and `N-1-i`:
        *   If `i` is **even**: `N-1-i` will be `(odd - even) = odd`. So, `A[even_index]` must match `A[odd_index]`.
        *   If `i` is **odd**: `N-1-i` will be `(odd - odd) = even`. So, `A[odd_index]` must match `A[even_index]`.
    *   **Conclusion**: In a palindrome of even length, every character at an even index must have a matching character at an odd index, and vice-versa.

3.  **Combining the Observations**:
    *   We know that characters at even positions can only be rearranged among themselves, and characters at odd positions can only be rearranged among themselves. The multisets of characters for even and odd positions are invariant.
    *   For the string to become a palindrome, we need to be able to pair up characters such that `A[i]` (from an even position) matches `A[N-1-i]` (from an odd position), and vice-versa.
    *   This means that the collection of characters that *must* occupy even positions in the palindrome must be exactly the same as the collection of characters that *must* occupy odd positions.
    *   Therefore, the multiset of characters initially present at even indices must be identical to the multiset of characters initially present at odd indices. If they are identical, we can always arrange them to form a palindrome. For example, if the even multiset is `{c1, c2, ..., ck}` and the odd multiset is also `{c1, c2, ..., ck}`, we can place `c1` at index 0 and `c1` at index `N-1`, `c2` at index 2 and `c2` at index `N-3`, and so on, forming a palindrome. If they are not identical, it's impossible to satisfy the palindrome condition because characters cannot cross the parity boundary.

**Algorithm:**

1.  Initialize two frequency maps (or arrays for 'a'-'z'): `even_counts` and `odd_counts`.
2.  Iterate through the input string `A` from `i = 0` to `N-1`.
3.  If `i` is even, increment the count for `A[i]` in `even_counts`.
4.  If `i` is odd, increment the count for `A[i]` in `odd_counts`.
5.  After iterating through the entire string, compare `even_counts` and `odd_counts`.
6.  If they are identical, print "YES". Otherwise, print "NO".

## Complexity Analysis

*   **Time Complexity**:
    *   Reading the input string `A` of length `N` takes $O(N)$ time.
    *   Iterating through the string once to populate `even_counts` and `odd_counts`: This involves `N` map operations (insertions/increments). Each `std::map` operation takes $O(\log K)$ time, where `K` is the number of distinct characters (at most 26 for lowercase English letters). Since `K` is a small constant, this part is effectively $O(N)$.
    *   Comparing the two `std::map`s: This takes $O(K)$ time in the worst case, as it iterates through the elements of the maps.
    *   Total time complexity per test case: $O(N + K) = O(N)$ (since `K` is a constant).
    *   For `T` test cases, the total time complexity is $O(T \cdot N)$.

*   **Space Complexity**:
    *   Storing the input string `A`: $O(N)$.
    *   Storing `even_counts` and `odd_counts`: Each map stores at most `K` key-value pairs (where `K` is the number of distinct characters, max 26). So, $O(K)$ for each map.
    *   Total space complexity: $O(N + K) = O(N)$.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map> // Used for frequency counts

int main() {
    // Optimize C++ standard streams for faster input/output
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int n; // Length of the string
        std::cin >> n;
        std::string a; // The input string
        std::cin >> a;

        // We need to count character frequencies for even and odd indices separately.
        // std::map is suitable for this, mapping characters to their counts.
        std::map<char, int> even_counts;
        std::map<char, int> odd_counts;

        // Iterate through the string to populate the frequency maps
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) { // If the index is even
                even_counts[a[i]]++;
            } else { // If the index is odd
                odd_counts[a[i]]++;
            }
        }

        // The condition for forming a palindrome is that the multiset of characters
        // at even positions must be identical to the multiset of characters at odd positions.
        // std::map provides an equality operator that checks if two maps have the same
        // key-value pairs, which is exactly what we need to compare multisets.
        if (even_counts == odd_counts) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}

```