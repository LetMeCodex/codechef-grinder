# [Minimise LCS (MINLCS)](https://www.codechef.com/problems/MINLCS)
- **Difficulty Rating**: 1367
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum possible length of the Longest Common Subsequence (LCS) of two strings, $A$ and $B$, both of length $N$. We are allowed to reorder the characters within string $A$ in any way we want, and similarly, we can reorder the characters within string $B$ in any way we want, independently.

## Intuition & Mathematical Observation

The key to this problem lies in the ability to reorder characters within both strings. This means that the original positions of characters do not matter; only their frequencies (counts) are relevant.

Let's denote the frequency of a character `c` in string $A$ as `countA[c]` and in string $B$ as `countB[c]`.

1.  **Contribution of a single character to LCS**: For any character `c`, if a common subsequence contains `k` occurrences of `c`, then both string $A$ and string $B$ must contain at least `k` occurrences of `c`. Therefore, the maximum number of times a character `c` can appear in *any* common subsequence is `min(countA[c], countB[c])`.

2.  **Minimizing LCS**: We want to arrange the characters in $A$ and $B$ such that their LCS is as short as possible.
    *   Consider the value `min(countA[c], countB[c])` for each character `c`. This value represents the maximum number of `c`'s that *must* be able to form a common subsequence of `c`'s. For example, if `countA['a'] = 5` and `countB['a'] = 3`, we can always form "aaa" as a common subsequence of 'a's.
    *   Since the LCS must be at least as long as any common subsequence, the LCS length must be at least `min(countA[c], countB[c])` for *every* character `c`.
    *   Therefore, the LCS length must be at least `max_c(min(countA[c], countB[c]))` over all possible characters `c`. This establishes a lower bound for the minimum LCS length.

3.  **Achieving the lower bound (Constructive Proof)**: Can we always arrange strings $A$ and $B$ such that their LCS length is exactly `max_c(min(countA[c], countB[c]))`?
    Let $M = \max_c(\min(countA[c], countB[c]))$.
    Consider the following arrangement strategy:
    *   Reorder string $A$ such that all its characters are sorted alphabetically (e.g., all 'a's, then all 'b's, etc.). Let this be $A'$.
    *   Reorder string $B$ such that all its characters are sorted in reverse-alphabetical order (e.g., all 'z's, then all 'y's, etc.). Let this be $B'$.

    Now, let's analyze the LCS of $A'$ and $B'$.
    Suppose a common subsequence $S = s_1 s_2 \dots s_L$ exists.
    *   Since $S$ is a subsequence of $A'$, and $A'$ is sorted alphabetically, it must be that $s_1 \le s_2 \le \dots \le s_L$.
    *   Since $S$ is a subsequence of $B'$, and $B'$ is sorted reverse-alphabetically, it must be that $s_1 \ge s_2 \ge \dots \ge s_L$.
    *   For both conditions to hold simultaneously, it must be that $s_1 = s_2 = \dots = s_L$.
    This implies that any common subsequence formed by this arrangement must consist of repetitions of a *single* character.

    For example, if $A' = \text{"aaabbc"}$ and $B' = \text{"ccbaaa"}$:
    *   A common subsequence of only 'a's can have length `min(countA['a'], countB['a'])`.
    *   A common subsequence of only 'b's can have length `min(countA['b'], countB['b'])`.
    *   A common subsequence of only 'c's can have length `min(countA['c'], countB['c'])`.
    The longest among these single-character common subsequences will be the overall LCS. This is precisely `max_c(min(countA[c], countB[c]))`.

    Since we have shown that the LCS length must be *at least* $M$ and we can construct strings $A'$ and $B'$ such that their LCS length is *exactly* $M$, the minimum possible LCS length is indeed $M$.

**Algorithm:**
1.  Count the frequency of each character ('a' through 'z') in string $A$. Store these in `countA`.
2.  Count the frequency of each character ('a' through 'z') in string $B$. Store these in `countB`.
3.  Initialize `min_lcs_length = 0`.
4.  For each character `c` from 'a' to 'z':
    Calculate `current_common_count = min(countA[c], countB[c])`.
    Update `min_lcs_length = max(min_lcs_length, current_common_count)`.
5.  The final `min_lcs_length` is the answer.

## Complexity Analysis

*   **Time Complexity**:
    *   Reading input $N$, $A$, and $B$: $O(N)$
    *   Counting character frequencies for string $A$: We iterate through string $A$ once, which takes $O(N)$ time.
    *   Counting character frequencies for string $B$: We iterate through string $B$ once, which takes $O(N)$ time.
    *   Calculating `max_c(min(countA[c], countB[c]))`: We iterate through all 26 possible lowercase English letters. This is a constant number of operations, $O(26)$, which simplifies to $O(1)$.
    *   Total time complexity per test case: $O(N) + O(N) + O(1) = O(N)$.
    *   For $T$ test cases, the total time complexity is $O(T \cdot N)$.

*   **Space Complexity**:
    *   Storing strings $A$ and $B$: $O(N)$
    *   Storing character frequency arrays `countA` and `countB`: Each array has 26 elements (for 'a' through 'z'). This is $O(26)$, which simplifies to $O(1)$ as 26 is a constant.
    *   Total space complexity: $O(N) + O(1) = O(N)$.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // For std::max and std::min

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N;
    std::string A, B;
    std::cin >> A >> B;

    // Use vectors for character counts as the alphabet size is fixed (26 lowercase English letters).
    // 'a' corresponds to index 0, 'b' to index 1, ..., 'z' to index 25.
    std::vector<int> countA(26, 0);
    std::vector<int> countB(26, 0);

    // Count character frequencies for string A
    for (char c : A) {
        countA[c - 'a']++;
    }
    // Count character frequencies for string B
    for (char c : B) {
        countB[c - 'a']++;
    }

    // The minimum LCS length is the maximum of min(countA[c], countB[c]) for all characters c.
    int min_lcs_length = 0;
    for (int i = 0; i < 26; ++i) {
        min_lcs_length = std::max(min_lcs_length, std::min(countA[i], countB[i]));
    }

    std::cout << min_lcs_length << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from being flushed before each std::cin operation.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}

```