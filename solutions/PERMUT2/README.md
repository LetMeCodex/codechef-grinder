# [Ambiguous Permutations (PERMUT2)](https://www.codechef.com/problems/PERMUT2)
- **Difficulty Rating**: 853
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a given permutation `P` of numbers from 1 to `N` is "ambiguous". A permutation `P` is considered ambiguous if it is identical to its inverse permutation `P_inv`. We are given multiple test cases. Each test case starts with an integer `N` (the size of the permutation), followed by `N` integers representing the permutation `P`. The input ends when `N` is 0. For each test case, we need to output "ambiguous" or "not ambiguous".

## Intuition & Mathematical Observation

Let's first understand what a permutation and its inverse mean in this context.
*   A permutation `P` of `N` elements can be thought of as a mapping where `P[i]` is the value at position `i`. For example, if `P = [2, 3, 1]` for `N=3`, then `P[1]=2`, `P[2]=3`, `P[3]=1`.
*   The inverse permutation `P_inv` tells us, for each value `j`, at which position `i` it appears in `P`. In other words, if `P[i] = j`, then `P_inv[j] = i`. Using our example `P = [2, 3, 1]`:
    *   `P[1] = 2` implies `P_inv[2] = 1`
    *   `P[2] = 3` implies `P_inv[3] = 2`
    *   `P[3] = 1` implies `P_inv[1] = 3`
    So, `P_inv = [3, 1, 2]`.

The problem defines an "ambiguous" permutation as one where `P` is identical to `P_inv`. This means that for every `i` from 1 to `N`, the condition `P[i] == P_inv[i]` must hold.

The strategy to solve this problem is straightforward:
1.  Read the given permutation `P`. We can store it in a vector (or array).
2.  While reading `P`, simultaneously construct its inverse `P_inv`. If we read `P[i] = val`, then we know that `P_inv[val]` must be `i`.
3.  After both `P` and `P_inv` are fully constructed, iterate from `i = 1` to `N`.
4.  In each iteration, compare `P[i]` with `P_inv[i]`.
5.  If we find even a single `i` where `P[i] != P_inv[i]`, then the permutation is "not ambiguous", and we can stop checking further.
6.  If we complete the loop without finding any mismatches, it means `P[i] == P_inv[i]` for all `i`, and thus the permutation is "ambiguous".

The provided solution implements this exact logic using 1-based indexing for convenience, matching the problem's description of permutations from 1 to `N`.

## Complexity Analysis

*   **Time Complexity**:
    *   The `while` loop continues for `T` test cases.
    *   Inside each test case:
        *   Reading `N`: $O(1)$.
        *   Initializing two vectors of size `N+1`: $O(N)$.
        *   The first `for` loop iterates `N` times to read the permutation `P` and construct `P_inv`. Each operation inside the loop (`cin >> p[i]` and `p_inv[p[i]] = i`) takes $O(1)$ time. So, this loop takes $O(N)$ time.
        *   The second `for` loop iterates up to `N` times to compare `P` and `P_inv`. Each comparison takes $O(1)$ time. In the worst case (when the permutation is ambiguous or the mismatch is found at the very end), this loop also takes $O(N)$ time.
    *   Therefore, for each test case, the total time complexity is $O(N)$.
    *   If `S` is the sum of `N` over all test cases, the overall time complexity is $O(S)$. Given `N` up to $10^5$, this is highly efficient.

*   **Space Complexity**:
    *   We use two vectors, `p` and `p_inv`, both of size `N+1` to store integers.
    *   Each vector requires $O(N)$ space.
    *   Other variables (`n`, `i`, `ambiguous`) use $O(1)$ space.
    *   Thus, the total space complexity for each test case is $O(N)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, vector, etc.

using namespace std; // Allowed by problem instructions

int main() {
    // Optimize C++ standard streams for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // Loop until n is 0, which signals the end of input
    while (cin >> n && n != 0) {
        // Declare vectors for the permutation P and its inverse P_inv
        // Using 1-based indexing for convenience, so size n+1
        vector<int> p(n + 1);
        vector<int> p_inv(n + 1);

        // Read the permutation P and simultaneously construct P_inv
        for (int i = 1; i <= n; ++i) {
            cin >> p[i]; // Read the i-th element of the permutation
            
            // If p[i] is the value at index i in the original permutation,
            // then the position of value p[i] is i.
            // So, in the inverse permutation, the element at index p[i] is i.
            p_inv[p[i]] = i;
        }

        bool ambiguous = true; // Assume ambiguous until a mismatch is found
        
        // Compare P with P_inv
        for (int i = 1; i <= n; ++i) {
            if (p[i] != p_inv[i]) {
                ambiguous = false; // Mismatch found, it's not ambiguous
                break;             // No need to check further, exit loop
            }
        }

        // Output the result based on the 'ambiguous' flag
        if (ambiguous) {
            cout << "ambiguous\n";
        } else {
            cout << "not ambiguous\n";
        }
    }

    return 0;
}
```