# [Spell Shortening (SHORTSPELL)](https://www.codechef.com/problems/SHORTSPELL)
- **Difficulty Rating**: 1192
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a string $S$ of length $N$, we need to delete exactly one character to obtain a new string of length $N-1$. The goal is to make the resulting string lexicographically as small as possible.

## Intuition & Mathematical Observation

To make a string lexicographically as small as possible, we want to make the earliest possible characters as small as possible. This means we should prioritize making changes at the beginning of the string.

Consider two strings $A$ and $B$. String $A$ is lexicographically smaller than string $B$ if at the first position where they differ, the character in $A$ is smaller than the character in $B$.

Let the given string be $S = s_0s_1s_2...s_{N-1}$. We need to delete one character $s_i$. The resulting string will be $s_0s_1...s_{i-1}s_{i+1}...s_{N-1}$.

We want to find an index $i$ such that deleting $s_i$ results in the lexicographically smallest string.

Let's compare deleting $s_i$ versus deleting $s_j$ where $i < j$.
If we delete $s_i$, the prefix of the string up to index $i-1$ remains the same. The character at index $i$ in the new string will be $s_{i+1}$.
If we delete $s_j$, the prefix of the string up to index $i$ remains the same. The character at index $i$ in the new string will be $s_i$.

Consider the first position $k$ where the string formed by deleting $s_i$ and the string formed by deleting $s_j$ might differ.

If we find an index $i$ such that $s_i > s_{i+1}$, deleting $s_i$ is a strong candidate. Why?
If we delete $s_i$, the character at index $i$ in the new string becomes $s_{i+1}$. Since $s_{i+1} < s_i$, this change at index $i$ makes the string lexicographically smaller than if we had kept $s_i$.
If we were to delete a character $s_k$ where $k > i$, the prefix $s_0s_1...s_i$ would remain unchanged. The character at index $i$ would still be $s_i$. Since $s_{i+1} < s_i$, deleting $s_i$ leads to a smaller character at index $i$ compared to deleting $s_k$ (where $k>i$).

Therefore, the optimal strategy is to find the *first* index $i$ from the left such that $s_i > s_{i+1}$. Deleting this $s_i$ will yield the lexicographically smallest string. This is because we are making the earliest possible character smaller.

What if no such index $i$ exists? This means the string is already sorted in non-decreasing order, i.e., $s_0 \le s_1 \le s_2 \le ... \le s_{N-1}$. Examples: "aab", "abc", "xxyy".
In this scenario, to make the string lexicographically smallest, we should delete the character that has the least impact on the prefix. Deleting the last character $s_{N-1}$ will result in the string $s_0s_1...s_{N-2}$. Any other deletion would remove a character from an earlier position, potentially making the string lexicographically larger if the removed character was smaller than its successor. For example, in "abc", deleting 'a' gives "bc", deleting 'b' gives "ac", deleting 'c' gives "ab". "ab" is the smallest.

So, the algorithm is:
1. Iterate through the string from left to right, checking adjacent characters.
2. Find the first index $i$ where $s_i > s_{i+1}$. If found, delete $s_i$.
3. If no such index is found (the string is sorted non-decreasingly), delete the last character $s_{N-1}$.
4. Print the remaining string.

## Complexity Analysis

- **Time Complexity**: $O(N)$
    - We iterate through the string once to find the character to delete. This takes $O(N)$ time.
    - Printing the resulting string also takes $O(N)$ time.
    - Therefore, the total time complexity is $O(N)$.

- **Space Complexity**: $O(1)$ (excluding input string storage)
    - We only use a few variables to store the index to delete and loop counters.
    - The input string itself takes $O(N)$ space, but this is considered input storage. The auxiliary space used by the algorithm is constant.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <vector> // Not strictly needed, but common in competitive programming

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    int delete_idx = -1;

    // Iterate from the beginning of the string to find the first character S[i]
    // that is greater than the character immediately following it, S[i+1].
    // If such an 'i' is found, deleting S[i] will result in the lexicographically smallest string.
    // This is because replacing S[i] with S[i+1] (which is smaller) at the earliest possible position
    // makes the string lexicographically smaller than any other deletion strategy.
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] > s[i+1]) {
            delete_idx = i;
            break; // Found the optimal character to delete, no need to check further
        }
    }

    // If the loop completes and delete_idx is still -1, it means the string was
    // already sorted in non-decreasing order (e.g., "aab", "xxyy").
    // In this case, to obtain the lexicographically smallest string, we should
    // delete the last character. This preserves the longest possible lexicographically
    // smallest prefix (S[0...N-2]).
    if (delete_idx == -1) {
        delete_idx = n - 1;
    }

    // Print the resulting string by skipping the character at delete_idx.
    for (int i = 0; i < n; ++i) {
        if (i != delete_idx) {
            std::cout << s[i];
        }
    }
    std::cout << "\n"; // Newline after each test case output
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }

    return 0;
}
```