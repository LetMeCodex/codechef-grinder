# [False Number (FALSNUM)](https://www.codechef.com/problems/FALSNUM)
- **Difficulty Rating**: 1286
- **Solved in**: 2 attempt(s)

## Problem Summary

You are given a string `A` representing a positive integer. Your task is to find the lexicographically smallest string `W` such that `A` can be obtained by deleting exactly one digit from `W`. The deletion rule is specific:
1.  If `W` is non-increasing (e.g., "987", "553"), the last digit of `W` is deleted.
2.  Otherwise, the deleted digit `W[k]` is the *first* digit (from the left) such that `W[k] < W[k+1]`.

`W` must not have leading zeros, unless `W` itself is "0" (which is not possible here as `A` has at least one digit).

## Intuition & Mathematical Observation

Let `N` be the length of the given string `A`. Since `A` is formed by deleting exactly one digit from `W`, `W` must have length `N+1`. Let `W = w_0 w_1 ... w_N`. If `w_k` is the deleted digit, then `A` is `w_0 ... w_{k-1} w_{k+1} ... w_N`. This implies that `W` is formed by inserting a digit `d` into `A` at some position `k` (0-indexed, `0 <= k <= N`). So, `W = A[0...k-1] + d + A[k...N-1]`.

Our goal is to find the lexicographically smallest `W`. This means we should prioritize making the leading digits of `W` as small as possible. The smallest possible digits are '0' and '1'.

Let's analyze the two cases for deletion based on the problem statement to determine valid insertions:

**Case 1: `W` is non-increasing.**
If `W` is non-increasing (e.g., "987", "553"), the last digit `W[N]` is deleted.
This implies `A = W[0...N-1]`. So, `W` must be `A + W[N]`.
For `W` to be non-increasing, we need `A[0] >= A[1] >= ... >= A[N-1] >= W[N]`.
To make `W` lexicographically smallest, we should insert the smallest possible digit `W[N]` at the end, which is '0'.
Thus, if `A` itself is non-increasing, then `W = A + '0'` is a valid candidate. The '0' at the end would be deleted, yielding `A`.
*Example:* If `A = "321"`, then `W = "3210"`. `W` is non-increasing, so '0' is deleted, resulting in "321". This is a valid `W`.

**Case 2: `W` has a digit `W[j]` such that `W[j] < W[j+1]`. The *first* such digit `W[j]` is deleted.**
Let the inserted digit be `d` at position `k`. So `W = A[0...k-1] + d + A[k...N-1]`.
For `d` (which is `W[k]`) to be the deleted digit, two conditions must hold:
1.  All digits *before* `d` must form a non-increasing sequence: `W[0] >= W[1] >= ... >= W[k-1]`. This translates to `A[0] >= A[1] >= ... >= A[k-1]`. This ensures no digit before the inserted `d` is deleted.
2.  `d` must be strictly less than the digit immediately following it: `W[k] < W[k+1]`.
    *   If `k < N` (inserting `d` in the middle), this means `d < A[k]`.
    *   If `k = N` (inserting `d` at the end), this condition doesn't apply directly. This scenario is covered by Case 1, where `W` is non-increasing and `d` is the last digit.

Additionally, `W` cannot have a leading zero unless `W` itself is "0". Since `A` has at least one digit, `W` will have at least two digits, so `W[0]` cannot be '0'.

Considering these observations, we can identify two primary strategies to construct the lexicographically smallest `W`:

**Strategy A: Insert '1' at the beginning of `A`.**
Let `W = "1" + A`. Here, `k=0` and `d='1'`.
For `W[0]` ('1') to be the deleted digit, it must be the first digit `W[j]` such that `W[j] < W[j+1]`.
Since `j=0`, we need `W[0] < W[1]`, which means `'1' < A[0]`.
If `A[0] > '1'`, then `W = "1" + A` is a valid candidate. This `W` starts with '1', which is the smallest possible leading digit for `W` (as `W[0]` cannot be '0'). This makes it a very strong candidate for the lexicographically smallest `W`.
*Example:* If `A = "234"`, then `W = "1234"`. `W[0] = '1'`, `W[1] = '2'`. Since `'1' < '2'`, '1' is deleted, yielding "234". This is valid.

**Strategy B: Insert '0' at some position `k` (where `k > 0`).**
We want to insert '0' to make `W` lexicographically smallest. Since `W[0]` cannot be '0', we must insert '0' at `k >= 1`.
We iterate through possible insertion positions `k` from `1` to `N`. For each `k`, we form `W = A[0...k-1] + '0' + A[k...N-1]`.
For this '0' to be the deleted digit, the following must hold:
1.  The prefix `A[0...k-1]` must be non-increasing: `A[0] >= A[1] >= ... >= A[k-1]`. This ensures no digit before the inserted '0' is deleted.
2.  If `k < N` (inserting '0' in the middle): The digit `A[k]` must be greater than '0' (`A[k] > '0'`). This ensures `W[k] < W[k+1]` (i.e., `'0' < A[k]`) holds, making '0' the deleted digit.
3.  If `k = N` (inserting '0' at the end): This falls under Case 1. The entire `W` must be non-increasing. This means `A[0] >= ... >= A[N-1] >= '0'`. The '0' at the end is deleted.

To find the lexicographically smallest `W` of this type, we need to insert '0' at the *earliest possible* position `k` (from `1` to `N`) that satisfies these conditions. The code iterates `k` from `1` to `N`, maintaining a flag `prefix_non_increasing`. As soon as a valid `k` is found, it breaks, because inserting '0' earlier results in a lexicographically smaller `W`.

The final answer `ans_W` is the lexicographically smallest string found between Strategy A and Strategy B.

## Complexity Analysis

*   **Time Complexity**:
    *   Reading the input string `A` takes $O(N)$ time, where $N$ is the length of `A`.
    *   **Strategy A (`"1" + A`):** String concatenation takes $O(N)$ time. The character comparison `A[0] > '1'` is $O(1)$.
    *   **Strategy B (inserting '0'):**
        *   The loop iterates at most `N` times. Inside the loop, character comparisons and updates to `prefix_non_increasing` are $O(1)$.
        *   If a valid `k` is found, constructing the candidate string `W_cand2_str` involves iterating through `N+1` characters, which takes $O(N)$ time. The `reserve` call helps optimize memory allocation but doesn't change the asymptotic complexity of character copying.
        *   Comparing `W_cand2_str` with `ans_W` (if `ans_W` is not empty) takes $O(N)$ time in the worst case (comparing two strings of length $N+1$).
    *   Since these operations are performed sequentially for each test case, the total time complexity per test case is $O(N)$.
    *   Given `T` test cases, the overall time complexity is $O(T \cdot N)$. With $N \le 10^5$ and $T \le 10$, this is approximately $10 \cdot 10^5 = 10^6$ operations, which is well within typical time limits.

*   **Space Complexity**:
    *   Storing the input string `A` requires $O(N)$ space.
    *   Storing `ans_W` and `W_cand2_str` (if generated) each require $O(N)$ space, as they are strings of length `N+1`.
    *   Therefore, the total space complexity is $O(N)$.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void solve() {
    std::string A;
    std::cin >> A;
    int N = A.length();

    std::string ans_W = ""; // Stores the current smallest W found

    // --- Candidate 1: Insert '1' at the beginning of A ---
    // W = "1" + A
    // For '1' to be the deleted digit, it must be the first W[k] such that W[k] < W[k+1].
    // Here, k=0. So W[0] must be < W[1].
    // W[0] is '1', W[1] is A[0].
    // So, '1' < A[0] must hold.
    // Also, W[0] cannot be '0' (satisfied by '1').
    if (A[0] > '1') {
        ans_W = "1" + A; // This is an O(N) operation. Done once.
    }

    // --- Candidate 2: Insert '0' at some position k (from 1 to N) ---
    // We want the smallest W, so we try to insert '0' as early as possible.
    // Iterate k from 1 to N (insertion position).
    // W = A[0...k-1] + '0' + A[k...N-1]
    // Conditions for '0' to be the deleted digit:
    // 1. W[0] >= W[1] >= ... >= W[k-1] (i.e., A[0] >= A[1] >= ... >= A[k-1])
    // 2. W[k-1] >= W[k] (i.e., A[k-1] >= '0', always true)
    // 3. W[k] < W[k+1] (i.e., '0' < A[k], if k < N)
    // 4. If k=N (insert '0' at end), then W must be non-increasing: A[0] >= ... >= A[N-1] >= '0'.
    //    In this case, the last digit '0' is deleted.

    int best_k_for_zero = -1; // Stores the optimal insertion position for '0'
    bool prefix_non_increasing = true; // Tracks if A[0...j] is non-increasing

    for (int k = 1; k <= N; ++k) { // k is the 0-indexed position where '0' is inserted
        // Check prefix A[0...k-1] for non-increasing property
        if (k > 1 && A[k-2] < A[k-1]) { 
            prefix_non_increasing = false;
        }

        if (prefix_non_increasing) {
            bool current_k_is_valid = false;
            if (k < N) { // Insert '0' in the middle, before A[k]
                if (A[k] > '0') { // Condition '0' < A[k]
                    current_k_is_valid = true;
                }
            } else { // k == N, insert '0' at the end of A
                // Condition A[N-1] >= '0' is always true.
                // The prefix_non_increasing check up to A[N-1] covers A[0] >= ... >= A[N-1].
                current_k_is_valid = true;
            }

            if (current_k_is_valid) {
                best_k_for_zero = k;
                break; // Found the earliest valid position for '0', so this gives the smallest W of this type.
            }
        } else {
            break; // Prefix is no longer non-increasing, no further k will work.
        }
    }

    if (best_k_for_zero != -1) {
        // Construct the W string for the best '0' insertion *once*
        std::string W_cand2_str;
        W_cand2_str.reserve(N + 1); // Pre-allocate memory for efficiency
        for (int i = 0; i < best_k_for_zero; ++i) {
            W_cand2_str += A[i];
        }
        W_cand2_str += '0';
        for (int i = best_k_for_zero; i < N; ++i) {
            W_cand2_str += A[i];
        }
        
        // Compare with ans_W and update if W_cand2_str is smaller
        if (ans_W == "" || W_cand2_str < ans_W) {
            ans_W = W_cand2_str;
        }
    }
    
    std::cout << ans_W << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```