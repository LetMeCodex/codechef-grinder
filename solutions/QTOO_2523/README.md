# [Bi_lindrome! (QTOO_2523)](https://www.codechef.com/problems/QTOO_2523)
- **Difficulty Rating**: 1095
- **Solved in**: 1 attempt(s)

## Problem Summary

Given a string $S$ of length $N$, we need to find the maximum possible length of a subsequence that can be deleted such that the remaining characters form a palindrome. If it's impossible to form a palindrome of length greater than 1, we should output -1.

## Intuition & Mathematical Observation

The problem asks us to maximize the length of the deleted subsequence, which is equivalent to minimizing the length of the remaining palindrome. The remaining palindrome must have a length greater than 1.

Let the original string be $S$ of length $N$. We want to find a subsequence of $S$ that forms a palindrome, say $P$, such that $P$ has length $L > 1$, and $N - L$ is maximized. This means we want to minimize $L$.

Consider the properties of a palindrome of length greater than 1.
- A palindrome of length 2 must be of the form "aa", "bb", etc. This means it must consist of two identical characters.
- A palindrome of length 3 could be "aba", "bbb", etc. This means at least one character must appear twice.
- In general, any palindrome of length $L > 1$ must contain at least one character that appears at least twice within the palindrome itself. For example, "racecar" has 'r' twice, 'a' twice, 'c' twice.

Now, let's think about forming such a palindrome as a subsequence from the original string $S$.

**Case 1: The string $S$ contains at least one character that appears two or more times.**
If there is a character, say 'x', that appears at least twice in $S$, we can always pick two occurrences of 'x' from $S$ to form a palindrome of length 2 (e.g., "xx"). Since we want to minimize the length of the remaining palindrome (to maximize the deleted subsequence), a palindrome of length 2 is the smallest possible palindrome greater than 1.
If we can form a palindrome of length 2, the length of the deleted subsequence will be $N - 2$. This is the maximum possible length for the deleted subsequence because we've achieved the minimum possible length for the remaining palindrome ($L=2$).

**Case 2: All characters in the string $S$ are unique.**
If every character in $S$ appears only once, then it's impossible to pick two identical characters from $S$ to form a palindrome of length 2. More generally, any subsequence we pick will also consist of unique characters. A palindrome of length greater than 1 *must* have at least one character appearing more than once. Since $S$ does not have any character appearing more than once, we cannot form any palindrome of length $L > 1$. In this scenario, the problem states we should output -1.

Therefore, the core of the problem boils down to checking if the string $S$ contains any duplicate characters.

- If $S$ has duplicate characters, the minimum length of a palindrome we can form is 2. The maximum length of the deleted subsequence is $N - 2$.
- If $S$ has no duplicate characters (all characters are unique), it's impossible to form a palindrome of length greater than 1. The answer is -1.

To efficiently check for duplicate characters, we can use a frequency map or a boolean array (since the characters are lowercase English letters).

## Complexity Analysis

- **Time Complexity**: $O(N)$
    The solution iterates through the input string $S$ once to check for duplicate characters. The length of the string is $N$. The operations inside the loop (character to index conversion, array access, assignment) take constant time. Therefore, the time complexity is linear with respect to the length of the string.

- **Space Complexity**: $O(1)$
    We use a boolean vector `seen` of size 26 to keep track of the characters encountered. Since the alphabet size is fixed (26 lowercase English letters), the space used by this vector is constant, regardless of the input string length $N$.

## Solution Code

```cpp
#include <iostream> // Required for std::cin, std::cout
#include <string>   // Required for std::string
#include <vector>   // Required for std::vector

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N; // Read the length of the string
    std::string S;
    std::cin >> S; // Read the string S

    // A boolean vector to keep track of characters encountered so far.
    // 'a' corresponds to index 0, 'b' to index 1, ..., 'z' to index 25.
    // Initialize all elements to false, meaning no character has been seen yet.
    std::vector<bool> seen(26, false); 
    bool found_duplicate = false; // Flag to indicate if any character appears at least twice

    // Iterate through each character in the string S
    for (char c : S) {
        // Calculate the index for the current character 'c' in the 'seen' array.
        // For example, 'a' - 'a' = 0, 'b' - 'a' = 1, etc.
        int char_idx = c - 'a';

        // Check if the current character 'c' has been seen before
        if (seen[char_idx]) {
            found_duplicate = true; // If yes, we found a character that appears at least twice
            break; // No need to check further, we've found what we need to determine the answer
        }
        // Mark the current character 'c' as seen
        seen[char_idx] = true;
    }

    // After checking all characters (or breaking early if a duplicate was found):
    if (found_duplicate) {
        // If a character appears at least twice, we can form a palindrome of length 2 (e.g., "cc").
        // This is the shortest possible palindrome of length greater than 1.
        // To maximize the length of the deleted subsequence, we must minimize the length
        // of the remaining palindrome. The minimum possible length for a palindrome > 1 is 2.
        // So, the length of the deleted subsequence will be N - 2.
        std::cout << N - 2 << "\n";
    } else {
        // If no duplicate character was found, it means all characters in S are unique.
        // A palindrome of length greater than 1 must contain at least one character that appears twice within itself.
        // For example, "aa", "aba", "racecar" all have characters appearing multiple times.
        // If all characters in S are unique, it's impossible to form such a palindrome as a subsequence,
        // because S itself does not contain any character twice.
        // Therefore, it's impossible to satisfy the conditions.
        std::cout << -1 << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can speed up I/O operations.
    // std::cin.tie(NULL) prevents std::cout from being flushed before each std::cin operation,
    // further improving I/O performance.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful execution
}
```