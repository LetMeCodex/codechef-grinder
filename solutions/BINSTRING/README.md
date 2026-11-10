# [Distinct Binary Strings (BINSTRING)](https://www.codechef.com/problems/BINSTRING)
- **Difficulty Rating**: 1262
- **Solved in**: 1 attempt(s)

## Problem Summary

You are given a binary string $S$ of length $N$. You can perform exactly one operation: choose an index $i$ ($0 \le i < N$) and delete the character $S_i$ from the string. After deletion, the remaining parts are concatenated. For example, if $S = \text{"10110"}$ and you delete $S_2$ ('1'), the string becomes $\text{"1010"}$.

Your task is to find the total number of *distinct* binary strings that can be obtained by performing exactly one such operation. The length of the string $N$ is at least 2.

## Intuition & Mathematical Observation

Let's denote the string obtained by deleting $S_i$ as $S^{(i)}$. We want to count the number of unique strings in the set $\{S^{(0)}, S^{(1)}, \dots, S^{(N-1)}\}$.

Consider two adjacent indices, $i$ and $i+1$.
- If we delete $S_i$, the resulting string is $S_0 S_1 \dots S_{i-1} S_{i+1} S_{i+2} \dots S_{N-1}$.
- If we delete $S_{i+1}$, the resulting string is $S_0 S_1 \dots S_{i-1} S_i S_{i+2} \dots S_{N-1}$.

When are these two strings, $S^{(i)}$ and $S^{(i+1)}$, identical?
Comparing them character by character:
The prefix $S_0 \dots S_{i-1}$ is identical in both.
The suffix $S_{i+2} \dots S_{N-1}$ is identical in both.
The only difference can be at the $i$-th position (0-indexed) after deletion. In $S^{(i)}$, this character is $S_{i+1}$. In $S^{(i+1)}$, this character is $S_i$.

Therefore, $S^{(i)}$ is identical to $S^{(i+1)}$ if and only if $S_i = S_{i+1}$.
If $S_i \ne S_{i+1}$, then $S^{(i)}$ and $S^{(i+1)}$ will be distinct.

This observation is key. It implies that if we have a block of identical characters, say $S_k S_{k+1} \dots S_m$ where all characters are the same (e.g., "111" or "00"), then deleting any character within this block will produce the same resulting string.
For example, if $S = \text{"00011"}$:
- Deleting $S_0$ ('0') gives "0011".
- Deleting $S_1$ ('0') gives "0011".
- Deleting $S_2$ ('0') gives "0011".
All these operations produce the same string.

However, if $S_i \ne S_{i+1}$, then deleting $S_i$ and deleting $S_{i+1}$ will yield distinct strings. This means that each time we encounter a change in character ($S_i \ne S_{i+1}$), it effectively "starts a new group" of deletions that produce a distinct string.

Let's count the number of distinct strings:
1. Start with `distinct_strings_count = 1`. This accounts for the string obtained by deleting $S_0$.
2. Iterate from $i=0$ to $N-2$.
3. If $S_i \ne S_{i+1}$, it means that deleting $S_{i+1}$ will produce a string distinct from deleting $S_i$. We increment `distinct_strings_count`.

This approach essentially counts the number of "blocks" of consecutive identical characters in the string. For example, in "10110":
- "1" (first block)
- "0" (second block, because $S_0 \ne S_1$)
- "11" (third block, because $S_1 \ne S_2$)
- "0" (fourth block, because $S_3 \ne S_4$)
The number of distinct strings is 4.

Let's trace with $S = \text{"10110"}$, $N=5$:
- Initialize `distinct_strings_count = 1` (for the first block '1').
- `i = 0`: $S_0 = \text{'1'}$, $S_1 = \text{'0'}$. $S_0 \ne S_1$. Increment count. `distinct_strings_count = 2`.
- `i = 1`: $S_1 = \text{'0'}$, $S_2 = \text{'1'}$. $S_1 \ne S_2$. Increment count. `distinct_strings_count = 3`.
- `i = 2`: $S_2 = \text{'1'}$, $S_3 = \text{'1'}$. $S_2 = S_3$. Count remains 3.
- `i = 3`: $S_3 = \text{'1'}$, $S_4 = \text{'0'}$. $S_3 \ne S_4$. Increment count. `distinct_strings_count = 4`.
The loop finishes. Output `4`. This matches the example.

This logic correctly counts the number of maximal contiguous blocks of identical characters, which is equivalent to the number of distinct strings that can be formed.

## Complexity Analysis

-   **Time Complexity**: $O(N)$
    The solution involves reading the input string of length $N$ and then iterating through it once from $i=0$ to $N-2$. Each comparison and increment operation takes constant time. Thus, for each test case, the time complexity is linear with respect to the length of the string. Given $T$ test cases, the total time complexity is $O(T \cdot N_{max})$, where $N_{max}$ is the maximum string length.

-   **Space Complexity**: $O(N)$
    The solution stores the input string $S$ of length $N$. All other variables (like `n`, `distinct_strings_count`, loop counter `i`) use a constant amount of space. Therefore, the space complexity is dominated by storing the input string.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, string, etc.

// Using namespace std; as requested
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // The problem states N >= 2, so we don't need to handle N=0 or N=1 explicitly.
    // The number of distinct strings is 1 + (number of times S[i] != S[i+1]).
    // This is equivalent to counting the number of "blocks" of identical characters.
    // For example, if S = "10110":
    // Blocks are "1", "0", "11", "0". Total 4 blocks.
    //
    // Let's trace the logic:
    // Initial distinct_strings_count = 1 (for the first character/block).
    // This accounts for the string obtained by deleting S[0].
    //
    // For i = 0: S[0] ('1') vs S[1] ('0') -> different, increment count.
    // For i = 1: S[1] ('0') vs S[2] ('1') -> different, increment count.
    // For i = 2: S[2] ('1') vs S[3] ('1') -> same, count remains unchanged.
    // For i = 3: S[3] ('1') vs S[4] ('0') -> different, increment count.
    //
    // The loop iterates from i=0 to n-2.
    // Each time s[i] != s[i+1], it signifies that deleting s[i+1] will produce
    // a string distinct from deleting s[i]. This is because the character at
    // the (i)-th position (after deletion) would be s[i+1] for deleting s[i],
    // and s[i] for deleting s[i+1]. Since s[i] != s[i+1], these strings differ.
    // Thus, we increment our count of distinct strings.

    int distinct_strings_count = 1; // Start with 1 for the first block/character
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] != s[i+1]) {
            distinct_strings_count++;
        }
    }
    cout << distinct_strings_count << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }

    return 0;
}
```