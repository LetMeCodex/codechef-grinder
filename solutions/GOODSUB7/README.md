Here's a clean, high-quality solution writeup in GitHub-Flavored Markdown for the CodeChef problem GOODSUB7.

---

# [Good Subsequence (GOODSUB7)](https://www.codechef.com/problems/GOODSUB7)
- **Difficulty Rating**: 899
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the maximum possible length of a "good subsequence" from a given array `A` of `N` integers. A subsequence is considered "good" if the parities of any two adjacent elements within the subsequence are different. For example, if a subsequence is `[x1, x2, x3]`, then `x1` and `x2` must have different parities, and `x2` and `x3` must also have different parities.

## Intuition & Mathematical Observation

The core idea is to construct the longest possible subsequence where elements alternate in parity (e.g., odd, even, odd, even...). To maximize the length of such a subsequence, we should employ a greedy strategy.

Consider building the good subsequence element by element:
1.  **Start with the first element:** We must pick at least one element to form a subsequence. The first element of the array, `A[0]`, is always a valid starting point for a good subsequence of length 1. We record its parity.
2.  **Extend greedily:** From this point, we iterate through the rest of the array (`A[1]` to `A[N-1]`). For each element `A[i]`, we check its parity.
    *   If `A[i]` has a *different* parity than the *last element we added to our good subsequence*, then `A[i]` can extend our current good subsequence. We add `A[i]` to our conceptual subsequence, increment its length, and update the "last parity" to `A[i]`'s parity.
    *   If `A[i]` has the *same* parity as the last element we added, we cannot include `A[i]` immediately after the previous element. In this case, we simply skip `A[i]` and continue searching for the next suitable element in the array. We do not reset our subsequence length or last parity, as we are trying to extend the *current* longest one.

This greedy approach works because our goal is solely to maximize the length. By always picking the *next available* element that satisfies the alternating parity condition, we ensure that we are making progress and extending the subsequence whenever possible. The choice of `A[i]` over some `A[j]` (where `j > i`) does not restrict future choices in a way that would lead to a shorter overall subsequence, because we only care about the parity and the relative order, not the specific values or indices beyond what's necessary to maintain the subsequence property.

**Example:** `A = [1, 2, 3, 4, 5]`
*   Initialize `max_length = 1`. `last_parity = A[0] % 2 = 1` (Odd).
*   `i = 1`, `A[1] = 2` (Even). `current_parity = 0`. `0 != 1`.
    *   `max_length` becomes `2`. `last_parity` becomes `0`.
*   `i = 2`, `A[2] = 3` (Odd). `current_parity = 1`. `1 != 0`.
    *   `max_length` becomes `3`. `last_parity` becomes `1`.
*   `i = 3`, `A[3] = 4` (Even). `current_parity = 0`. `0 != 1`.
    *   `max_length` becomes `4`. `last_parity` becomes `0`.
*   `i = 4`, `A[4] = 5` (Odd). `current_parity = 1`. `1 != 0`.
    *   `max_length` becomes `5`. `last_parity` becomes `1`.
*   End of array. Output `max_length = 5`.

## Complexity Analysis

*   **Time Complexity**: $O(N)$
    *   Reading the input array `A` takes $O(N)$ time.
    *   The main loop iterates from `i = 1` to `N-1`, performing constant-time operations (modulo, comparison, increment, assignment) in each iteration. This contributes $O(N)$ time.
    *   Since the `solve()` function is called `T` times, the total time complexity is $O(T \cdot N)$. Given $N \le 100$ and $T \le 100$, this is $100 \cdot 100 = 10^4$ operations in the worst case, which is very efficient.

*   **Space Complexity**: $O(N)$
    *   We use a `std::vector<int> A` to store the input array, which requires $O(N)$ space.
    *   All other variables (`N`, `max_length`, `last_parity`, `current_parity`, loop counter `i`) use a constant amount of space, $O(1)$.
    *   Thus, the dominant factor is the storage of the input array, leading to $O(N)$ space complexity.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, vector, etc.

using namespace std; // As requested

void solve() {
    int N;
    cin >> N; // Read the length of the array
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i]; // Read array elements
    }

    // Constraints state 1 <= N <= 100, so N will never be 0.
    // Thus, a good subsequence of length at least 1 always exists (any single element).
    // Initialize max_length to 1, as we can always pick at least one element.
    int max_length = 1;
    // Store the parity of the first element chosen for our good subsequence.
    // A[0] is always the first element we consider for our subsequence.
    int last_parity = A[0] % 2; 

    // Iterate from the second element to the end of the array
    for (int i = 1; i < N; ++i) {
        int current_parity = A[i] % 2;
        // If the current element's parity is different from the last chosen element's parity,
        // we can extend our good subsequence.
        if (current_parity != last_parity) {
            max_length++; // Increment the length of the good subsequence
            last_parity = current_parity; // Update the last chosen parity
        }
        // If current_parity == last_parity, we cannot include A[i] right after the
        // previous element, so we skip it and look for the next suitable element.
    }
    cout << max_length << "\n"; // Output the maximum length found
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // Unties cin from cout and disables synchronization with C stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times to solve each test case
        solve(); 
    }
    return 0;
}
```