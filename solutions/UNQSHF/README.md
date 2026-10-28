# [Unequal Shuffle (UNQSHF)](https://www.codechef.com/problems/UNQSHF)
- **Difficulty Rating**: 726
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if it's possible to rearrange the characters of two given binary strings, `A` and `B`, of length `N`, such that for every index `i` (from `0` to `N-1`), the character `A[i]` is not equal to `B[i]`. The strings `A` and `B` consist only of 'a's and 'b's. We are allowed to rearrange the characters within string `A` independently, and similarly for string `B`.

## Intuition & Mathematical Observation

The core condition is `A[i] != B[i]` for all `i`. Since the strings only contain 'a' and 'b', this means that for every position `i`, the pair `(A[i], B[i])` must be either `('a', 'b')` or `('b', 'a')`. It cannot be `('a', 'a')` or `('b', 'b')`.

Let's consider the counts of characters. Since we can rearrange the characters within `A` and `B` independently, the *order* of characters in the original strings doesn't matter; only the *total count* of 'a's and 'b's in each string matters.

Suppose we successfully rearrange `A` and `B` to satisfy the condition.
Let `k` be the number of positions where `(A[i], B[i]) = ('a', 'b')`.
Then, the remaining `N - k` positions must have `(A[i], B[i]) = ('b', 'a')`.

Now, let's analyze the character counts required for `A` and `B` based on this arrangement:
1.  **For string `A`**:
    *   It must contain `k` 'a's (from the `('a', 'b')` pairs).
    *   It must contain `N - k` 'b's (from the `('b', 'a')` pairs).
    *   Therefore, the total number of 'a's in `A` must be `k`.
    *   The total number of 'b's in `A` must be `N - k`.
2.  **For string `B`**:
    *   It must contain `k` 'b's (from the `('a', 'b')` pairs).
    *   It must contain `N - k` 'a's (from the `('b', 'a')` pairs).
    *   Therefore, the total number of 'b's in `B` must be `k`.
    *   The total number of 'a's in `B` must be `N - k`.

Let `countA_a` be the number of 'a's in the original string `A`, and `countB_b` be the number of 'b's in the original string `B`.
From our analysis, for a valid rearrangement to exist, we must have:
*   `countA_a = k`
*   `countB_b = k`

This implies that `countA_a` must be equal to `countB_b`.

**Is this condition sufficient?**
Yes. If `countA_a == countB_b`, let this common count be `k`.
Then:
*   String `A` has `k` 'a's and `N - k` 'b's.
*   String `B` has `k` 'b's and `N - k` 'a's (since `countB_a = N - countB_b = N - k`).

We can construct the rearranged strings as follows:
*   For `A`: Place all `k` 'a's first, followed by all `N-k` 'b's.
    (e.g., `A = "aaa...a" (k times) + "bbb...b" (N-k times)`)
*   For `B`: Place all `k` 'b's first, followed by all `N-k` 'a's.
    (e.g., `B = "bbb...b" (k times) + "aaa...a" (N-k times)`)

Let's check the condition `A[i] != B[i]` for this construction:
*   For `i` from `0` to `k-1`: `A[i]` will be 'a' and `B[i]` will be 'b'. So `A[i] != B[i]`.
*   For `i` from `k` to `N-1`: `A[i]` will be 'b' and `B[i]` will be 'a'. So `A[i] != B[i]`.

Since the condition holds for all `i`, this construction proves sufficiency.

Therefore, the problem reduces to simply counting the number of 'a's in string `A` and the number of 'b's in string `B`, and checking if these two counts are equal.

## Complexity Analysis

*   **Time Complexity**:
    *   Reading `N`, `A`, and `B` takes $O(N)$ time.
    *   Counting 'a's in string `A` involves iterating through `A` once, which takes $O(N)$ time.
    *   Counting 'b's in string `B` involves iterating through `B` once, which takes $O(N)$ time.
    *   The comparison and printing take $O(1)$ time.
    *   Thus, for a single test case, the time complexity is $O(N)$.
    *   Given that the sum of `N` over all test cases does not exceed $2 \cdot 10^5$, the total time complexity across all test cases will be $O(\sum N)$, which is efficient enough.

*   **Space Complexity**:
    *   Storing strings `A` and `B` requires $O(N)$ space.
    *   A few integer variables (`N`, `countA_a`, `countB_b`) require $O(1)$ space.
    *   Therefore, the total space complexity for a single test case is $O(N)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries, as requested

// Use the standard namespace to avoid prefixing std::
using namespace std;

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the length of the strings
    string A, B;
    cin >> A >> B; // Read strings A and B

    // Count the number of 'a's in string A
    int countA_a = 0;
    for (char c : A) {
        if (c == 'a') {
            countA_a++;
        }
    }
    // An alternative way to count using std::count from <algorithm>:
    // int countA_a = count(A.begin(), A.end(), 'a');

    // Count the number of 'b's in string B
    int countB_b = 0;
    for (char c : B) {
        if (c == 'b') {
            countB_b++;
        }
    }
    // An alternative way to count using std::count from <algorithm>:
    // int countB_b = count(B.begin(), B.end(), 'b');

    // The condition for a solution to exist is that the number of 'a's in A
    // must be equal to the number of 'b's in B.
    // This is derived from the fact that if we want A_i != B_i for all i,
    // then for each position i, the pair (A_i, B_i) must be either ('a', 'b') or ('b', 'a').
    // Let 'k' be the number of ('a', 'b') pairs.
    // Then 'N-k' must be the number of ('b', 'a') pairs.
    // String A must contain 'k' 'a's and 'N-k' 'b's. So, countA_a = k.
    // String B must contain 'N-k' 'a's and 'k' 'b's. So, countB_b = k.
    // Therefore, countA_a must be equal to countB_b.
    if (countA_a == countB_b) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cout from flushing before cin reads input.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful execution
}
```